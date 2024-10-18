/*************************************************************************
���ļ����� RegularWeekDayFestival.hpp
������ģ���Ŀ�ġ� ά��RegularWeekDayFestival�࣬���б�дRegularWeekDayFestival
				���Ա������������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/

#ifndef RegularWeekDayFestival_hpp
#define RegularWeekDayFestival_hpp

#include "Festival.hpp"
#include "WeekDay.hpp"
#include "MOWeekDay.hpp"

/*************************************************************************
�������� RegularWeekDayFestival
�����ܡ� ĳ�µ�ĳ�����ڼ���������ʽ��ÿ��һ��
���ӿ�˵���� 4��getter������ȡ���ݣ�3��Modify�����޸ĳ�Ա���ݡ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
class RegularWeekDayFestival : public Festival {
public:
	//��ӽ���
	static Festival* Add(const string& Name, const MOWeekDay& MOWeekDay);

	//ɾ��Ĭ�Ϲ��캯�����������캯������ֵ�������
	RegularWeekDayFestival() = delete;
	RegularWeekDayFestival(const RegularWeekDayFestival&) = delete;
	RegularWeekDayFestival(const char*, const MDDate&) = delete;
	RegularWeekDayFestival& operator=(const RegularWeekDayFestival& Source)
		= delete;

	//�޸�MOW�����麯����ʵ�֣�ʵ���������
	bool ModifyMOWeekDay(const unsigned int& uMonth
						, const unsigned int& uOrdial
						, const unsigned int& uWeekDay);
	//�޸����գ����麯����ʵ�֣��˴�����ʵ��
	bool ModifyMDDate(const unsigned int& uMonth, const unsigned int& uDay);
	//�޸������գ����麯����ʵ�֣��˴�����ʵ��
	bool ModifyYMDDate(const unsigned int& uYear
					, const unsigned int& uMonth
					, const unsigned int& uDay);

	//��������գ����麯����ʵ�֣��˴�����ʵ��
	YMDDate GetYMDDate() const;
	//������գ����麯����ʵ�֣��˴�����ʵ��
	MDDate GetMDDate() const;
	//���MOW�����麯����ʵ�֣�ʵ����һ�ֺ���
	MOWeekDay GetMOWeekDay() const;
	//��ý������࣬���麯����ʵ�֣�ʵ����һ�ֺ���
	FestivalType GetType() const;

private:
	//�������Ĺ��캯��
	RegularWeekDayFestival(const string& Name, const MOWeekDay& MOWeekDay);
	RegularWeekDayFestival(const string& Name
						, const Month& Month
						, const unsigned int& Ordial
						, const WeekDay& WeekDay);
	MOWeekDay m_MOWeekDay;
};




#endif // !RegularWeekDayFestival_hpp
