/*************************************************************************
���ļ����� MOWeekDay.cpp
������ģ���Ŀ�ġ� ά��MOWeekDay�࣬���б�дMOWeekDay���Ա�����Ķ��塣
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/

#include "MOWeekDay.hpp"

/*************************************************************************
���������ơ� MOWeekDay���������ܡ� ���캯��
�������� �������Month���������uOrdial���������WeekDay
������ֵ�� ���캯������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
MOWeekDay::MOWeekDay(const Month& Month, const unsigned int& uOrdial
					, const WeekDay& WeekDay): m_Month(Month), m_Ordial(uOrdial)
					, m_WeekDay(WeekDay) {
	Set(Month, uOrdial, WeekDay);
}

/*************************************************************************
���������ơ� MOWeekDay���������ܡ� ���캯��
�������� �������uMonth���������uOrdial���������uActualWeekDayValue
������ֵ�� ���캯������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
MOWeekDay::MOWeekDay(const unsigned int& uMonth, const unsigned int& uOrdial
					, const unsigned int& uActualWeekDayValue) : m_Month(uMonth)
					, m_Ordial(uOrdial), m_WeekDay(uActualWeekDayValue) {
	Set(uMonth, uOrdial, uActualWeekDayValue);
}

/*************************************************************************
���������ơ� MOWeekDay���������ܡ� ���캯��
�������� �������uMonth���������uOrdial���������uActualWeekDayValue
������ֵ�� ���캯������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
MOWeekDay::MOWeekDay(const Month& Month, const unsigned int& uOrdial
					, const unsigned int& uActualWeekDayValue) : m_Month(Month)
					, m_Ordial(uOrdial), m_WeekDay(uActualWeekDayValue) {
	Set(Month, uOrdial, uActualWeekDayValue);
}

/*************************************************************************
���������ơ� MOWeekDay���������ܡ� ���캯��
�������� �������Source
������ֵ�� ���캯������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
MOWeekDay::MOWeekDay(const MOWeekDay& Source) : m_Month(Source.m_Month)
					, m_Ordial(Source.m_Ordial), m_WeekDay(Source.m_WeekDay) {

}

/*************************************************************************
���������ơ� operator=���������ܡ� ��ֵ�����
�������� �������Source
������ֵ�� *this
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
MOWeekDay& MOWeekDay::operator=(const MOWeekDay& Source) {
	if (this == &Source) {
		return *this;
	}
	m_Month = Source.m_Month;
	m_Ordial = Source.m_Ordial;
	m_WeekDay = Source.m_WeekDay;
}

/*************************************************************************
���������ơ� Set���������ܡ� ��������
�������� �������Month���������uOrdial���������WeekDay
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void MOWeekDay::Set(const Month& Month, const unsigned int& uOrdial
					, const WeekDay& WeekDay) {
	if (MOWeekDay::IsValidMOWeekDay(Month, uOrdial, WeekDay)) {
		m_Month = Month;
		m_Ordial = uOrdial;
		m_WeekDay = WeekDay;
	}
	else {
		throw invalid_argument("MOWeekDay����");
	}
}

/*************************************************************************
���������ơ� Set���������ܡ� ��������
�������� �������uMonth���������uOrdial���������uActualWeekDayValue
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void MOWeekDay::Set(const unsigned int& uMonth, const unsigned int& uOrdial
					, const unsigned int& uActualWeekDayValue) {
	if (MOWeekDay::IsValidMOWeekDay(uMonth, uOrdial, uActualWeekDayValue)) {
		m_Month = uMonth;
		m_Ordial = uOrdial;
		m_WeekDay = uActualWeekDayValue;
	}
	else {
		throw invalid_argument("MOWeekDay����");
	}
}

/*************************************************************************
���������ơ� Set���������ܡ� ��������
�������� �������Month���������uOrdial���������uActualWeekDayValue
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void MOWeekDay::Set(const Month& Month, const unsigned int& uOrdial
	, const unsigned int& uActualWeekDayValue) {
	if (MOWeekDay::IsValidMOWeekDay(Month, uOrdial, uActualWeekDayValue)) {
		m_Month = Month;
		m_Ordial = uOrdial;
		m_WeekDay = uActualWeekDayValue;
	}
	else {
		throw invalid_argument("MOWeekDay����");
	}
}

/*************************************************************************
���������ơ� SetMonth���������ܡ� ������
�������� �������uMonth
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void MOWeekDay::SetMonth(const unsigned int& uMonth) {
	if (MOWeekDay::IsValidMOWeekDay(uMonth, m_Ordial, m_WeekDay)) {
		m_Month = uMonth;
	}
	else {
		throw invalid_argument("MOWeekDay����");
	}
}

/*************************************************************************
���������ơ� SetMonth���������ܡ� ������
�������� �������Month
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void MOWeekDay::SetMonth(const Month& Month) {
	if (MOWeekDay::IsValidMOWeekDay(Month, m_Ordial, m_WeekDay)) {
		m_Month = Month;
	}
	else {
		throw invalid_argument("MOWeekDay����");
	}
}

/*************************************************************************
���������ơ� SetOrdial���������ܡ� ���õ�ĳ��
�������� �������uOrdial
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void MOWeekDay::SetOrdial(const unsigned int& uOrdial) {
	if (MOWeekDay::IsValidMOWeekDay(m_Month, uOrdial, m_WeekDay)) {
		m_Ordial = uOrdial;
	}
	else {
		throw invalid_argument("MOWeekDay����");
	}
}

/*************************************************************************
���������ơ� SetWeekDay���������ܡ� �������ڼ�
�������� �������WeekDay
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void MOWeekDay::SetWeekDay(const WeekDay& WeekDay) {
	if (MOWeekDay::IsValidMOWeekDay(m_Month, m_Ordial, WeekDay)) {
		m_WeekDay = WeekDay;
	}
	else {
		throw invalid_argument("MOWeekDay����");
	}
}

/*************************************************************************
���������ơ� SetWeekDay���������ܡ� �������ڼ�
�������� �������uActualWeekDayValue
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void MOWeekDay::SetWeekDay(const unsigned int& uActualWeekDayValue) {
	if (MOWeekDay::IsValidMOWeekDay(m_Month, m_Ordial, uActualWeekDayValue)) {
		m_WeekDay = uActualWeekDayValue;
	}
	else {
		throw invalid_argument("MOWeekDay����");
	}
}

/*************************************************************************
���������ơ� IsValidMOWeekDay���������ܡ� �ж����ںϷ���
�������� �������Month���������uOrdial���������WeekDay
������ֵ�� bool���Ϸ���Ϊtrue
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool MOWeekDay::IsValidMOWeekDay(const Month& Month
								, const unsigned int& uOrdial
								, const WeekDay& WeekDay) {
	if (uOrdial >= 1 && uOrdial <= 5) {
		return true;
	}
	return false;
}

/*************************************************************************
���������ơ� IsValidMOWeekDay���������ܡ� �ж����ںϷ���
�������� �������Month���������uOrdial���������uActualWeekDayValue
������ֵ�� bool���Ϸ���Ϊtrue
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool MOWeekDay::IsValidMOWeekDay(const unsigned int& uMonth
								, const unsigned int& uOrdial
								, const unsigned int& uActualWeekDayValue) {
	class Month TempMonth(uMonth);
	WeekDay TempWeekDay(uActualWeekDayValue);
	return IsValidMOWeekDay(TempMonth, uOrdial, TempWeekDay);
}

/*************************************************************************
���������ơ� IsValidMOWeekDay���������ܡ� �ж����ںϷ���
�������� �������Month���������uOrdial���������uActualWeekDayValue
������ֵ�� bool���Ϸ���Ϊtrue
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool MOWeekDay::IsValidMOWeekDay(const Month& Month
								, const unsigned int& uOrdial
								, const unsigned int& uActualWeekDayValue) {
	WeekDay TempWeekDay(uActualWeekDayValue);
	return IsValidMOWeekDay(Month, uOrdial, TempWeekDay);
}

/*************************************************************************
���������ơ� IsValidMOWeekDay���������ܡ� �ж����ںϷ���
�������� ��
������ֵ�� bool���Ϸ���Ϊtrue
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool MOWeekDay::IsValidMOWeekDay() const {
	return IsValidMOWeekDay(m_Month, m_Ordial, m_WeekDay);
}

/*************************************************************************
���������ơ� GetMonth���������ܡ� �����
�������� ��
������ֵ�� m_Month ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
Month MOWeekDay::GetMonth() const {
	return m_Month;
}

/*************************************************************************
���������ơ� GetMonthValue���������ܡ� ����µ�ֵ
�������� ��
������ֵ�� m_Month.GetValue() ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
unsigned int MOWeekDay::GetMonthValue() const {
	return m_Month.GetValue();
}

/*************************************************************************
���������ơ� GetOrdial���������ܡ� ��õ�ĳ��
�������� ��
������ֵ�� m_Ordial ��ĳ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
unsigned int MOWeekDay::GetOrdial() const {
	return m_Ordial;
}

/*************************************************************************
���������ơ� GetWeekDay���������ܡ� ������ڼ�
�������� ��
������ֵ�� m_WeekDay ���ڼ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
WeekDay MOWeekDay::GetWeekDay() const {
	return m_WeekDay;
}

/*************************************************************************
���������ơ� GetWeekDay���������ܡ� ������ڼ�
�������� ��
������ֵ�� m_WeekDay.GetActualValue() ���ڼ���ֵ
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
unsigned int MOWeekDay::GetWeekDayActualValue() const {
	return m_WeekDay.GetActualValue();
}