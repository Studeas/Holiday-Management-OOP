/*************************************************************************
���ļ����� SpecialDateFestival.hpp
������ģ���Ŀ�ġ� ά��SpecialDateFestival�࣬���б�дSpecialDateFestival���Ա������������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
#ifndef SpecialDateFestival_hpp
#define SpecialDateFestival_hpp

#include "Festival.hpp"
#include "YMDDate.hpp"

/*************************************************************************
�������� SpecialDateFestival
�����ܡ� ĳ��ĳ��ĳ�յ�������ʽ����Ψһ������
���ӿ�˵���� 4��getter������ȡ���ݣ�3��Modify�����޸ĳ�Ա���ݡ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
class SpecialDateFestival : public Festival {
public:
	//��ӽ���
	static Festival* Add(const string& Name, const YMDDate& YMDDate);
	//ɾ��Ĭ�Ϲ��캯�����������캯������ֵ�������
	SpecialDateFestival() = delete;
	SpecialDateFestival(const SpecialDateFestival&) = delete;
	SpecialDateFestival(const char*, const MDDate&) = delete;
	SpecialDateFestival& operator=(const SpecialDateFestival& Source) = delete;

	//�޸�MOW�����麯����ʵ�֣��˴�����ʵ��
	bool ModifyMOWeekDay(const unsigned int& uMonth, const unsigned int& uOrdial
						, const unsigned int& uWeekDay);
	//�޸����գ����麯����ʵ�֣�����ʵ��
	bool ModifyMDDate(const unsigned int& uMonth, const unsigned int& uDay);
	//�޸������գ����麯����ʵ�֣�����ʵ��
	bool ModifyYMDDate(const unsigned int& uYear, const unsigned int& uMonth
						, const unsigned int& uDay);

	//��������գ����麯����ʵ�֣�ʵ���������
	YMDDate GetYMDDate() const;
	//������գ����麯����ʵ�֣�ʵ���������
	MDDate GetMDDate() const;
	//���MOW�����麯����ʵ�֣�ʵ���������
	MOWeekDay GetMOWeekDay() const;
	//������࣬���麯����ʵ�֣�ʵ���������
	FestivalType GetType() const;

private:
	//�������Ĺ��캯��
	SpecialDateFestival(const string& Name, const YMDDate& YMDDate);
	YMDDate m_YMDDate;
};




#endif // !SpecialDateFestival_hpp

