/*************************************************************************
���ļ����� MOWeekDay.hpp
������ģ���Ŀ�ġ� ά��MOWeekDay�࣬���б�дMOWeekDay���Ա������������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
#ifndef MOWeekDay_hpp
#define MOWeekDay_hpp

#include "Month.hpp"
#include "WeekDay.hpp"

/*************************************************************************
�������� MOWeekDay
�����ܡ� ĳ�µ�ĳ�����ڼ����������ʽ�������ڹ���
���ӿ�˵���� 5��getter������ȡ���ݣ�8��setter�����޸ĳ�Ա���ݣ�4��IsValid�жϺϷ��ԡ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
class MOWeekDay {
public:
	//ɾ��Ĭ�Ϲ��캯��
	MOWeekDay() = delete;
	//�������캯��
	MOWeekDay(const Month& Month
			, const unsigned int& uOrdial
			, const WeekDay& WeekDay);
	MOWeekDay(const unsigned int& uMonth
			, const unsigned int& uOrdial
			, const unsigned int& uActualWeekDayValue);
	MOWeekDay(const Month& Month
			, const unsigned int& uOrdial
			, const unsigned int& uActualWeekDayValue);
	MOWeekDay(const MOWeekDay& Source);
	//Ĭ����������
	~MOWeekDay() = default;
	//��ֵ�����
	MOWeekDay& operator=(const MOWeekDay& Source);

	//����MOW
	void Set(const Month& Month
		   , const unsigned int& uOrdial
		   , const WeekDay& WeekDay);
	void Set(const unsigned int& uMonth
		   , const unsigned int& uOrdial
		   , const unsigned int& uActualWeekDayValue);
	void Set(const Month& Month
		   , const unsigned int& uOrdial
		   , const unsigned int& uctualWeekDayValue);
	//������
	void SetMonth(const unsigned int& uMonth);
	void SetMonth(const Month& Month);
	//���õ�ĳ��
	void SetOrdial(const unsigned int& uOrdial);
	//�������ڼ�
	void SetWeekDay(const WeekDay& WeekDay);
	void SetWeekDay(const unsigned int& uActualWeekDayValue);

	//�ж������Ƿ�Ϸ�
	static bool IsValidMOWeekDay(const Month& Month
								, const unsigned int& uOrdial
								, const WeekDay& WeekDay);
	static bool IsValidMOWeekDay(const unsigned int& uMonth
								, const unsigned int& uOrdial
								, const unsigned int& uActualWeekDayValue);
	static bool IsValidMOWeekDay(const Month& uMonth
								, const unsigned int& uOrdial
								, const unsigned int& uActualWeekDayValue);
	bool IsValidMOWeekDay() const;

	//��ȡ��
	Month GetMonth() const;
	//��ȡ�µ�ֵ
	unsigned int GetMonthValue() const;
	//��ȡ��ĳ��
	unsigned int GetOrdial() const;
	//��ȡ���ڼ�
	WeekDay GetWeekDay() const;
	//��ȡ���ڼ���ֵ
	unsigned int GetWeekDayActualValue() const;

	 
private:
	Month m_Month;
	unsigned int m_Ordial;
	WeekDay m_WeekDay;
};


#endif // !MOWeekDay_hpp

