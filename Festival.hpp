/*************************************************************************
���ļ����� Festival.hpp
������ģ���Ŀ�ġ� ά��Festival�࣬���б�дFestival���Ա������������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/

#ifndef Festival_hpp
#define Festival_hpp

#include <string>
#include <vector>
#include "MDDate.hpp"
#include "YMDDate.hpp"
#include "MOWeekDay.hpp"


using namespace std;

/*************************************************************************
�������� FestivalType
�����ܡ� ö�����ͣ��ṩFestivalType��Ա�����ķ���ֵ��
���ӿ�˵���� ���ṩ�ӿڣ�ֻά����Ա��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
enum class FestivalType {
	REGULAR_DATE,
	REGULAR_WEEKDAY,
	SPECIAL_DATE
};

/*************************************************************************
�������� Festival
�����ܡ� �����࣬�洢����������ȡ���洢�ļ����ṩ�޸ġ����ҵȹ��ܵĺ���ʵ�֡�
���ӿ�˵���� Delɾ�����գ�5��getter������ȡ���ݣ�4��Modify�����޸ĳ�Ա����
			��SearchFestivalByName�������ҡ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
class Festival {
public:
	//ɾ��ָ�����ƵĽ���
	static bool Del(const string& sName);

	//ɾ��Ĭ�Ϲ��캯�����������캯���͸�ֵ�����
	Festival(const char*) = delete;
	Festival() = delete;
	Festival(const Festival& Source) = delete;
	Festival& operator=(const Festival& Source) = delete;

	//��ý�������
	string GetFestivalName() const;

	//�޸Ľ�������
	bool ModifyName(const string& sOldName, const string& sNewName);

	//�޸Ľ���ʱ�䣬���麯��
	virtual bool ModifyMOWeekDay(const unsigned int& uMonth
								, const unsigned int& uOrdial
								, const unsigned int& uWeekDay) = 0;
	virtual bool ModifyMDDate(const unsigned int& uMonth
							, const unsigned int& uDay) = 0;
	virtual bool ModifyYMDDate(const unsigned int& uYear
							, const unsigned int& uMonth
							, const unsigned int& uDay) = 0;
		
	//��ý���ʱ����Ϣ�����麯��
	virtual YMDDate GetYMDDate() const = 0;
	virtual MDDate GetMDDate() const = 0;
	virtual MOWeekDay GetMOWeekDay() const = 0;
	virtual FestivalType GetType() const = 0;

	//����������������
	static Festival* SearchFestivalByName(const string& sTargetName);
	
	//��Ƕ�࣬�洢ĳ��Ľ�����Ϣ���������ơ�ʱ����Ϣ��������ʵ�ֲ��Ҵ�ӡ����
	class FestivalInThisYear {
	public:
		//�������Ĺ��캯��
		FestivalInThisYear(const string& sName
						, const YMDDate& YMDDate
						, const unsigned int& uDaysInTotal);
		string m_Name;
		YMDDate m_YMDDate;
		unsigned int m_DaysInTotal;
	};

	//��̬��Ա����������ĳ���е����н���
	static vector<FestivalInThisYear*> 
		GetFestivalInThisYearList(const unsigned int& uYear);

	//������ָ���ļ�
	static void SaveToFile(const string& FileName);
	//��ȡָ���ļ�
	static void LoadFromFile(const string& FileName);

	//�������Ƶĳ�����
	const string& Name;

protected:
	//�������Ĺ��캯��
	Festival(const string& sName);

	//�ܱ��������ݳ�Ա���洢���н��յ�ָ��
	static vector<Festival*> m_All;
	
private:
	//���������ʱ��Garbo�������������
	static void Clear();
	
	//˽�����ݳ�Ա����������
	string m_Name;

	//��Ƕ�࣬���������ʱ���������ٶ�̬�ڴ棬��ֹ�ڴ�й©
	class Garbo {
	public:
		~Garbo() {
			Festival::Clear();
		}
	};
	static Garbo m_Garbo;
};


#endif