/*************************************************************************
���ļ����� RegularDateFestival.hpp
������ģ���Ŀ�ġ� ά��RegularDateFestival�࣬���б�дRegularDateFestival
				���Ա������������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/

#ifndef RegularDateFestival_hpp
#define RegularDateFestival_hpp
#include "Festival.hpp"
#include "MDDate.hpp"
#include "MOWeekDay.hpp" 

/*************************************************************************
�������� RegularDateFestival
�����ܡ� ĳ��ĳ�յ�������ʽ��ÿ��һ��
���ӿ�˵���� 4��getter������ȡ���ݣ�3��Modify�����޸ĳ�Ա���ݡ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
class RegularDateFestival : public Festival {
public:
	//��̬����ӽ��պ���
	static Festival* Add(const string& Name, const MDDate& MDDate);
	//ɾ��Ĭ�Ϲ��캯�����������캯������ֵ�������
	RegularDateFestival() = delete;
	RegularDateFestival(const RegularDateFestival&) = delete;
	RegularDateFestival(const char*, const MDDate&) = delete;
	RegularDateFestival& operator=(const RegularDateFestival& Source) = delete;

	//�޸�MOW�����麯����ʵ�֣��˴�����ʵ��
	bool ModifyMOWeekDay(const unsigned int& Month, const unsigned int& Ordial
						, const unsigned int& WeekDay);
	//�޸������գ����麯����ʵ�֣�ֻʵ����һ�ֺ���
	bool ModifyMDDate(const unsigned int& Month, const unsigned int& Day);
	//�޸����գ����麯����ʵ�֣��˴�����ʵ��
	bool ModifyYMDDate(const unsigned int& Year, const unsigned int& Month
					, const unsigned int& Day);

	//��������գ����麯����ʵ�֣��˴�����ʵ��
	YMDDate GetYMDDate() const;
	//������գ����麯����ʵ�֣�ʵ����һ�ֺ���
	MDDate GetMDDate() const;
	//���MOW�����麯����ʵ�֣��˴�����ʵ��
	MOWeekDay GetMOWeekDay() const;
	//��ý������࣬���麯����ʵ�֣�ʵ����һ�ֺ���
	FestivalType GetType() const;

protected:

private:
	//�������Ĺ��캯��
	RegularDateFestival(const string& Name, const MDDate& MDDate);
	MDDate m_MDDate;
};


#endif
