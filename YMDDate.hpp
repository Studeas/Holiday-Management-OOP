/*************************************************************************
���ļ����� YMDDate.hpp
������ģ���Ŀ�ġ� ά��YMDDate�࣬���б�дYMDDate���Ա������������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/

#ifndef YMDDate_hpp
#define YMDDate_hpp

#include "MDDate.hpp"
#include "WeekDay.hpp"
#include "MOWeekDay.hpp"
#include <ctime>

/*************************************************************************
�������� YMDDate
�����ܡ� ĳ��ĳ��ĳ�����͵����ڣ�����������
���ӿ�˵���� 1��getter������ȡ���ݣ�3��setter�����޸ĳ�Ա���ݣ�IsLeapYear�ж�
			ƽ���꣬IsValidYMDDate�ж����ںϷ��ԣ�DaysPassedInThisYear�����
			�ڼ��죬DaysPassedInTotal�ܹ��ǵڼ��죬ToWeekDay�����ڼ���
			ToMOWeekDay���ĸ��µ�ĳ�����ڼ���YMOWeekDayToYMDDate YMOWת����
			�����գ�Today�������죬�������������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
class YMDDate : public MDDate {
public:
	//�������Ĺ��캯��
	YMDDate(const unsigned int& uYear
			, const unsigned int& uMonth
			, const unsigned int& uDay);
	YMDDate(const unsigned int& uYear
			, const Month& Month
			, const unsigned int& uDay);
	YMDDate(const unsigned int& uYear, const MDDate& MDDate);
	//Ĭ�Ͽ������캯�������캯������������
	YMDDate(const YMDDate&) = default;
	YMDDate() = default;
	~YMDDate() = default;
	//��ֵ�����
	YMDDate& operator=(const YMDDate& Source);
	//==�����
	bool operator==(const YMDDate& Source) const;
	friend bool operator==(const YMDDate& YMDDate1, const YMDDate& YMDDate2);
	//!=�����
	bool operator!=(const YMDDate& Source) const;
	friend bool operator!=(const YMDDate& YMDDate1, const YMDDate& YMDDate2);
	//>�����
	bool operator>(const YMDDate& Source) const;
	friend bool operator>(const YMDDate& YMDDate1, const YMDDate& YMDDate2);
	//<�����
	bool operator<(const YMDDate& Source) const;
	friend bool operator<(const YMDDate& YMDDate1, const YMDDate& YMDDate2);
	//>=�����
	bool operator>=(const YMDDate& Source) const;
	friend bool operator>=(const YMDDate& YMDDate1, const YMDDate& YMDDate2);
	//<=�����
	bool operator<=(const YMDDate& Source) const;
	friend bool operator<=(const YMDDate& YMDDate1, const YMDDate& YMDDate2);
	//++�����
	YMDDate& operator++();
	YMDDate  operator++(int);
	//--�����
	YMDDate& operator--();
	YMDDate  operator--(int);
	//����������
	void Set(const unsigned int& uYear, const MDDate& MDDate);
	void Set(const unsigned int& uYear
			, const Month& Month
			, const unsigned int& uDay);
	void Set(const unsigned int& uYear
			, const unsigned int& uMonth
			, const unsigned int& uDay);
	//������
	void SetYear(const unsigned int& uYear);
	//�����
	unsigned int GetYear() const;
	//�ж��Ƿ�������
	bool IsLeapYear() const;
	static bool IsLeapYear(const unsigned int& uYear);
	//�ж������Ƿ�Ϸ�
	bool IsValidYMDDate() const;
	static bool IsValidYMDDate(const unsigned int& uYear
							, const Month& Month
							, const unsigned int uDay);
	static bool IsValidYMDDate(const unsigned int& uYear
							, const unsigned int& uMonth
							, const unsigned int& uDay);
	//�ǵ���ĵڼ���
	unsigned int DaysPassedInThisYear() const;
	static unsigned int DaysPassedInThisYear(const YMDDate& YMDDate);
	//��19000101�����ǵڼ���
	unsigned int DaysPassedInTotal() const;//since 1900.1.1
	static unsigned int DaysPassedInTotal(const YMDDate& YMDDate);
	//ת�������ڼ�
	WeekDay ToWeekDay() const;
	static WeekDay ToWeekDay(const YMDDate& YMDDate);
	static WeekDay ToWeekDay(const unsigned int& uYear
							, const unsigned int& uMonth
							, const unsigned int& uDay);
	static WeekDay ToWeekDay(const unsigned int& uYear
							, const Month& Month
							, const unsigned int& uDay);
	//ת���ɣ�ĳ�µ�ĳ�����ڼ�
	MOWeekDay ToMOWeekDay() const;
	static MOWeekDay ToMOWeekDay(const YMDDate& YMDDate);
	static MOWeekDay ToMOWeekDay(const unsigned int& uYear
								, const unsigned int& uMonth
								, const unsigned int& uDay);
	static MOWeekDay ToMOWeekDay(const unsigned int& uYear
								, const Month& Month
								, const unsigned int& uDay);
	//YMOWת����������
	static YMDDate YMOWeekDayToYMDDate(const unsigned int& uYear
									, const unsigned int& uMonth
									, const unsigned int& uOrdial
									, const unsigned int& uWeekDay);
	//����
	static YMDDate Today();

private:
	unsigned int m_Year;

	static unsigned int s_MaxYear;
	static unsigned int s_MinYear;
};


#endif // !YMDDate_hpp
