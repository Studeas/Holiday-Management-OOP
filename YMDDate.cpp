/*************************************************************************
���ļ����� YMDDate.cpp
������ģ���Ŀ�ġ� ά��YMDDate�࣬���б�дYMDDate���Ա�����Ķ��塣
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "YMDDate.hpp"
#include <chrono>
#include <ctime>
#include <iostream>

unsigned int YMDDate::s_MaxYear = 9999;
unsigned int YMDDate::s_MinYear = 1900;

/*************************************************************************
���������ơ� YMDDate���������ܡ� ���캯��
�������� �������uYear���������uMonth���������uDay
������ֵ�� ���캯������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
YMDDate::YMDDate(const unsigned int& uYear
				, const unsigned int& uMonth
				, const unsigned int& uDay): MDDate(uMonth, uDay) {
	if (!IsValidYMDDate(uYear, uMonth, uDay)) {
		throw invalid_argument("�������ա����ڳ��޻򲻴��ڡ�");
	}
	Set(uYear, uMonth, uDay);
}

/*************************************************************************
���������ơ� YMDDate���������ܡ� ���캯��
�������� �������uYear���������uMonth���������uDay
������ֵ�� ���캯������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
YMDDate::YMDDate(const unsigned int& uYear
				, const Month& Month
				, const unsigned int& uDay): MDDate(Month, uDay) {
	if (!IsValidYMDDate(uYear, Month, uDay)) {
		throw invalid_argument("�������ա����ڳ��޻򲻴��ڡ�");
	}
	Set(uYear, Month, uDay);
}

/*************************************************************************
���������ơ� YMDDate���������ܡ� ���캯��
�������� �������uYear���������MDDate
������ֵ�� ���캯������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
YMDDate::YMDDate(const unsigned int& uYear
				, const MDDate& MDDate): MDDate(MDDate) {
	if (!IsValidYMDDate(uYear, MDDate.GetMonthValue(), MDDate.GetDay())) {
		throw invalid_argument("�������ա����ڳ��޻򲻴��ڡ�");
	}
	Set(uYear, MDDate);
}

/*************************************************************************
���������ơ� operator=���������ܡ� ��ֵ�����
�������� �������Source
������ֵ�� *this
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
YMDDate& YMDDate::operator=(const YMDDate& Source) {
	if (this == &Source) {
		return *this;
	}
	MDDate::operator=(Source);
	m_Year = Source.m_Year;
}

/*************************************************************************
���������ơ� operator==���������ܡ� ==�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool YMDDate::operator==(const YMDDate& Source) const {
	return (Source.m_Year == m_Year) 
		&& (Source.GetMonth() == this->GetMonth()) 
		&& (Source.GetDay() == this->GetDay());
}

/*************************************************************************
���������ơ� operator==���������ܡ� ==�����
�������� �������YMDDate1���������YMDDate2
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool operator==(const YMDDate& YMDDate1, const YMDDate& YMDDate2) {
	return (YMDDate1.m_Year == YMDDate2.m_Year) 
		&& (YMDDate1.GetMonth() == YMDDate2.GetMonth()) 
		&& (YMDDate1.GetDay() == YMDDate2.GetDay());
}

/*************************************************************************
���������ơ� operator!=���������ܡ� !=�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool YMDDate::operator!=(const YMDDate& Source) const {
	return (Source.m_Year != m_Year) 
		|| (Source.GetMonth() != this->GetMonth())
		|| (Source.GetDay() != this->GetDay());
}

/*************************************************************************
���������ơ� operator!=���������ܡ� !=�����
�������� �������YMDDate1���������YMDDate2
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool operator!=(const YMDDate& YMDDate1, const YMDDate& YMDDate2) {
	return (YMDDate1.m_Year != YMDDate2.m_Year) || (YMDDate1.GetMonth() != YMDDate2.GetMonth()) || (YMDDate1.GetDay() != YMDDate2.GetDay());
}

/*************************************************************************
���������ơ� operator>���������ܡ� >�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool YMDDate::operator>(const YMDDate& Source) const {
	if (m_Year > Source.m_Year) {
		return true;
	}
	if ((m_Year == Source.m_Year) 
		&& (this->GetMonthValue() > Source.GetMonthValue())) {
		return true;
	}
	if ((m_Year == Source.m_Year) 
		&& (this->GetMonthValue() == Source.GetMonthValue()) 
		&& (this->GetDay()>this->GetDay())) {
		return true;
	}
	return false;
}

/*************************************************************************
���������ơ� operator>���������ܡ� >�����
�������� �������YMDDate1���������YMDDate2
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool operator>(const YMDDate& YMDDate1, const YMDDate& YMDDate2) {
	if (YMDDate1.m_Year > YMDDate2.m_Year) {
		return true;
	}
	if ((YMDDate1.m_Year == YMDDate2.m_Year) 
		&& (YMDDate1.GetMonthValue() > YMDDate2.GetMonthValue())) {
		return true;
	}
	if ((YMDDate1.m_Year == YMDDate2.m_Year) 
		&& (YMDDate1.GetMonthValue() == YMDDate2.GetMonthValue()) 
		&& (YMDDate1.GetDay() > YMDDate2.GetDay())) {
		return true;
	}
	return false;
}

/*************************************************************************
���������ơ� operator<���������ܡ� <�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool YMDDate::operator<(const YMDDate& Source) const {
	if (m_Year < Source.m_Year) {
		return true;
	}
	if ((m_Year == Source.m_Year)
		&& (this->GetMonthValue() < Source.GetMonthValue())) {
		return true;
	}
	if ((m_Year == Source.m_Year)
		&& (this->GetMonthValue() == Source.GetMonthValue()) 
		&& (this->GetDay() < this->GetDay())) {
		return true;
	}
	return false;
}

/*************************************************************************
���������ơ� operator<���������ܡ� <�����
�������� �������YMDDate1���������YMDDate2
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool operator<(const YMDDate& YMDDate1, const YMDDate& YMDDate2) {
	if (YMDDate1.m_Year < YMDDate2.m_Year) {
		return true;
	}
	if ((YMDDate1.m_Year == YMDDate2.m_Year)
		&& (YMDDate1.GetMonthValue() < YMDDate2.GetMonthValue())) {
		return true;
	}
	if ((YMDDate1.m_Year == YMDDate2.m_Year) 
		&& (YMDDate1.GetMonthValue() == YMDDate2.GetMonthValue())
		&& (YMDDate1.GetDay() < YMDDate2.GetDay())) {
		return true;
	}
	return false;
}

/*************************************************************************
���������ơ� operator>=���������ܡ� >=�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool YMDDate::operator>=(const YMDDate& Source) const {
	if (m_Year > Source.m_Year) {
		return true;
	}
	if ((m_Year == Source.m_Year)
		&& (this->GetMonthValue() > Source.GetMonthValue())) {
		return true;
	}
	if ((m_Year == Source.m_Year) 
		&& (this->GetMonthValue() == Source.GetMonthValue()) 
		&& (this->GetDay() >= this->GetDay())) {
		return true;
	}
	return false;
}

/*************************************************************************
���������ơ� operator>=���������ܡ� >=�����
�������� �������YMDDate1���������YMDDate2
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool operator>=(const YMDDate& YMDDate1, const YMDDate& YMDDate2) {
	if (YMDDate1.m_Year > YMDDate2.m_Year) {
		return true;
	}
	if ((YMDDate1.m_Year == YMDDate2.m_Year) 
		&& (YMDDate1.GetMonthValue() > YMDDate2.GetMonthValue())) {
		return true;
	}
	if ((YMDDate1.m_Year == YMDDate2.m_Year) 
		&& (YMDDate1.GetMonthValue() == YMDDate2.GetMonthValue())
		&& (YMDDate1.GetDay() >= YMDDate2.GetDay())) {
		return true;
	}
	return false;
}

/*************************************************************************
���������ơ� operator<=���������ܡ� <=�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool YMDDate::operator<=(const YMDDate& Source) const {
	if (m_Year < Source.m_Year) {
		return true;
	}
	if ((m_Year == Source.m_Year) 
		&& (this->GetMonthValue() < Source.GetMonthValue())) {
		return true;
	}
	if ((m_Year == Source.m_Year) 
		&& (this->GetMonthValue() == Source.GetMonthValue()) 
		&& (this->GetDay() <= this->GetDay())) {
		return true;
	}
	return false;
}

/*************************************************************************
���������ơ� operator<=���������ܡ� <=�����
�������� �������YMDDate1���������YMDDate2
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool operator<=(const YMDDate& YMDDate1, const YMDDate& YMDDate2) {
	if (YMDDate1.m_Year < YMDDate2.m_Year) {
		return true;
	}
	if ((YMDDate1.m_Year == YMDDate2.m_Year) 
		&& (YMDDate1.GetMonthValue() < YMDDate2.GetMonthValue())) {
		return true;
	}
	if ((YMDDate1.m_Year == YMDDate2.m_Year) 
		&& (YMDDate1.GetMonthValue() == YMDDate2.GetMonthValue())
		&& (YMDDate1.GetDay() <= YMDDate2.GetDay())) {
		return true;
	}
	return false;
}

/*************************************************************************
���������ơ� operator++���������ܡ� ǰ��++�����
�������� ��
������ֵ�� *this
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
YMDDate& YMDDate::operator++() {
	if ((this->GetMonthValue() == 12) && (this->GetDay() == 31)) {
		if (m_Year + 1 > s_MaxYear) {
			throw invalid_argument("���ڳ���");
		}
		++m_Year;
		this->SetMonth(1);
		this->SetDay(1);
		return *this;
	}
	else {
		if ((this->GetMonthValue() == 2) && (this->GetDay() == 28)) {
			if (IsLeapYear(m_Year)) {
				this->SetMonth(2);
				this->SetDay(29);
				return *this;
			}
			else {
				this->SetMonth(3);
				this->SetDay(1);
				return *this;
			}
		}
		else {
			MDDate::operator++();
			return *this;
		}
	}
}

/*************************************************************************
���������ơ� operator++���������ܡ� ����++�����
�������� ��
������ֵ�� Temp
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
YMDDate YMDDate::operator++(int) {
	YMDDate Temp{ *this };
	++(*this);
	return Temp;
}

/*************************************************************************
���������ơ� operator--���������ܡ� ǰ��--�����
�������� ��
������ֵ�� *this
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
YMDDate& YMDDate::operator--() {
	if ((this->GetMonthValue() == 1) && (this->GetDay() == 1)) {
		if (m_Year - 1 < s_MinYear) {
			throw invalid_argument("���ڳ���");
		}
		--m_Year;
		this->SetMonth(12);
		this->SetDay(31);
		return *this;
	}
	else {
		if ((this->GetMonthValue() == 3) && (this->GetDay() == 1)) {
			if (IsLeapYear(m_Year)) {
				this->SetMonth(2);
				this->SetDay(29);
				return *this;
			}
			else {
				this->SetMonth(2);
				this->SetDay(28);
				return *this;
			}
		}
		else {
			MDDate::operator--();
			return *this;
		}
	}
}

/*************************************************************************
���������ơ� operator--���������ܡ� ����--�����
�������� ��
������ֵ�� Temp
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
YMDDate YMDDate::operator--(int) {
	YMDDate Temp{ *this };
	--(*this);
	return Temp;
}

/*************************************************************************
���������ơ� Set���������ܡ� ����������
�������� �������uYear���������MDDate
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void YMDDate::Set(const unsigned int& uYear, const MDDate& MDDate) {
	if (IsValidYMDDate(uYear, MDDate.GetMonthValue(), MDDate.GetDay())) {
		m_Year = uYear;
		MDDate::operator=(MDDate);
	}	
}

/*************************************************************************
���������ơ� Set���������ܡ� ����������
�������� �������uYear���������Month���������uDay
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void YMDDate::Set(const unsigned int& uYear
				, const Month& Month
				, const unsigned int& uDay) {
	if (IsValidYMDDate(uYear, Month, uDay)) {
		m_Year = uYear;
		MDDate::Set(Month, uDay);
	}
}

/*************************************************************************
���������ơ� Set���������ܡ� ����������
�������� �������uYear���������uMonth���������uDay
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void YMDDate::Set(const unsigned int& uYear
				, const unsigned int& uMonth
				, const unsigned int& uDay) {
	if (IsValidYMDDate(uYear, uMonth, uDay)) {
		m_Year = uYear;
		MDDate::Set(uMonth, uDay);
	}
}

/*************************************************************************
���������ơ� SetYear���������ܡ� ������
�������� �������uYear
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void YMDDate::SetYear(const unsigned int& uYear) {
	if (IsValidYMDDate(uYear, MDDate::GetMonthValue(), MDDate::GetDay())) {
		m_Year = uYear;
	}
}

/*************************************************************************
���������ơ� GetYear���������ܡ� ��ȡ��
�������� ��
������ֵ�� m_Year
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
unsigned int YMDDate::GetYear() const {
	return m_Year;
}

/*************************************************************************
���������ơ� IsLeapYear���������ܡ� �ж�����
�������� ��
������ֵ�� bool true ������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool YMDDate::IsLeapYear() const {
	if ((m_Year % 4 == 0 && m_Year % 100 != 0) || (m_Year % 400 == 0)) {
		return true;
	}
	return false;
}

/*************************************************************************
���������ơ� IsLeapYear���������ܡ� �ж�����
�������� �������uYear
������ֵ�� bool true ������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool YMDDate::IsLeapYear(const unsigned int& uYear) {
	if ((uYear % 4 == 0 && uYear % 100 != 0) || (uYear % 400 == 0)) {
		return true;
	}
	return false;
}

/*************************************************************************
���������ơ� IsLeapYear���������ܡ� �ж����ںϷ���
�������� ��
������ֵ�� bool true �Ϸ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool YMDDate::IsValidYMDDate() const {
	if (IsValidYMDDate(m_Year, this->GetMonthValue(), this->GetDay())) {
		return true;
	}
	throw invalid_argument("���ڳ��޻򲻴���");
}

/*************************************************************************
���������ơ� IsLeapYear���������ܡ� �ж����ںϷ���
�������� �������uYear���������Month���������uDay
������ֵ�� bool true �Ϸ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool YMDDate::IsValidYMDDate(const unsigned int& uYear
							, const Month& Month
							, const unsigned int uDay) {
	if (uYear < s_MinYear || uYear > s_MaxYear) {
		throw invalid_argument("���ڳ��޻򲻴���");
	}
	else {
		if (IsLeapYear(uYear)) {
			if (IsValidMDDate(Month, uDay)) {
				return true;
			}
			throw invalid_argument("���ڳ��޻򲻴���");
		}
		else {
			if (IsValidMDDate(Month, uDay) 
				&& !(Month.GetValue() == 2 && uDay == 29)) {
				return true;
			}
			throw invalid_argument("���ڳ��޻򲻴���");
		}
	}
}

/*************************************************************************
���������ơ� IsValidYMDDate���������ܡ� �ж����ںϷ���
�������� �������uYear���������Month���������uDay
������ֵ�� bool true �Ϸ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool YMDDate::IsValidYMDDate(const unsigned int& uYear
							, const unsigned int& uMonth
							, const unsigned int& uDay) {
	if (uYear < s_MinYear || uYear > s_MaxYear) {
		throw invalid_argument("���ڳ��޻򲻴���");
	}
	else {
		if (IsLeapYear(uYear)) {
			if (IsValidMDDate(uMonth, uDay)) {
				return true;
			}
			throw invalid_argument("���ڳ��޻򲻴���");
		}
		else {
			if (IsValidMDDate(uMonth, uDay) && !(uMonth == 2 && uDay == 29)) {
				return true;
			}
			throw invalid_argument("���ڳ��޻򲻴���");
		}
	}
}

/*************************************************************************
���������ơ� DaysPassedInThisYear���������ܡ� ����ĵڼ���
�������� ��
������ֵ�� Days �ڼ���
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
unsigned int YMDDate::DaysPassedInThisYear() const {
	if (IsLeapYear(m_Year)) {
		unsigned int uDays = 0;
		for (int i = 1; i < this->GetMonthValue(); i++) {
			uDays += DaysOfMonthMax[i];
		}
		uDays += this->GetDay();
		return uDays;
	}
	else {
		unsigned int uDays = 0;
		for (int i = 1; i < this->GetMonthValue(); i++) {
			uDays += DaysOfMonthMax[i];
		}
		uDays += this->GetDay();
		if (this->GetMonthValue() > 2) {
			uDays -= 1;
		}
		return uDays;
	}
}

/*************************************************************************
���������ơ� DaysPassedInThisYear���������ܡ� ����ĵڼ���
�������� �������YMDDate
������ֵ�� Days �ڼ���
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
unsigned int YMDDate::DaysPassedInThisYear(const YMDDate& YMDDate) {
	if (IsLeapYear(YMDDate.m_Year)) {
		unsigned int uDays = 0;
		for (int i = 1; i < YMDDate.GetMonthValue(); i++) {
			uDays += DaysOfMonthMax[i];
		}
		uDays += YMDDate.GetDay();
		return uDays;
	}
	else {
		unsigned int uDays = 0;
		for (int i = 1; i < YMDDate.GetMonthValue(); i++) {
			uDays += DaysOfMonthMax[i];
		}
		uDays += YMDDate.GetDay();
		if (YMDDate.GetMonthValue() > 2) {
			uDays -= 1;
		}
		return uDays;
	}
}

/*************************************************************************
���������ơ� DaysPassedInTotal���������ܡ� ��19000101�ڼ���
�������� ��
������ֵ�� Days �ڼ���
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
unsigned int YMDDate::DaysPassedInTotal() const {
	unsigned int uDaysInTotal = 0;
	for (int PassedYear = 1900; PassedYear < m_Year; PassedYear++) {
		if (IsLeapYear(PassedYear)) {
			uDaysInTotal += 366;
			continue;
		}
		else {
			uDaysInTotal += 365;
		}
	}
	return uDaysInTotal + DaysPassedInThisYear();
}

/*************************************************************************
���������ơ� DaysPassedInTotal���������ܡ� ��19000101�ڼ���
�������� �������YMDDate
������ֵ�� Days �ڼ���
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
unsigned int YMDDate::DaysPassedInTotal(const YMDDate& YMDDate) {
	unsigned int uDaysInTotal = 0;
	for (int PassedYear = 1900; PassedYear < YMDDate.m_Year; PassedYear++) {
		if (IsLeapYear(PassedYear)) {
			uDaysInTotal += 366;
			continue;
		}
		else {
			uDaysInTotal += 365;
		}
	}
	return uDaysInTotal;
}

/*************************************************************************
���������ơ� ToWeekDay���������ܡ� ת��Ϊ���ڼ�
�������� ��
������ֵ�� WeekDay Temp�����ڼ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
WeekDay YMDDate::ToWeekDay() const {
	unsigned int uWeekDayValue = (this->DaysPassedInTotal()) % 7;
	if (uWeekDayValue == 0) {
		uWeekDayValue = 7;
	}
	WeekDay Temp(uWeekDayValue);
	return Temp;
}

/*************************************************************************
���������ơ� ToWeekDay���������ܡ� ת��Ϊ���ڼ�
�������� �������YMDDate
������ֵ�� WeekDay Temp�����ڼ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
WeekDay YMDDate::ToWeekDay(const YMDDate& YMDDate){
	unsigned int uWeekDayValue = (YMDDate.DaysPassedInTotal()) % 7;
	if (uWeekDayValue == 0) {
		uWeekDayValue = 7;
	}
	WeekDay Temp(uWeekDayValue);
	return Temp;
}

/*************************************************************************
���������ơ� ToWeekDay���������ܡ� ת��Ϊ���ڼ�
�������� �������uYear���������uMonth���������uDay
������ֵ�� WeekDay Temp�����ڼ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
WeekDay YMDDate::ToWeekDay(const unsigned int& uYear
						, const unsigned int& uMonth
						, const unsigned int& uDay) {
	unsigned int uWeekDayValue 
		= (YMDDate(uYear,uMonth,uDay).DaysPassedInTotal()) % 7;
	if (uWeekDayValue == 0) {
		uWeekDayValue = 7;
	}
	WeekDay Temp(uWeekDayValue);
	return Temp;
}

/*************************************************************************
���������ơ� ToWeekDay���������ܡ� ת��Ϊ���ڼ�
�������� �������uYear���������uMonth���������uDay
������ֵ�� WeekDay Temp�����ڼ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
WeekDay YMDDate::ToWeekDay(const unsigned int& uYear
						, const Month& Month
						, const unsigned int& uDay) {
	unsigned int uWeekDayValue 
		= (YMDDate(uYear, Month, uDay).DaysPassedInTotal()) % 7;
	if (uWeekDayValue == 0) {
		uWeekDayValue = 7;
	}
	WeekDay Temp(uWeekDayValue);
	return Temp;
}

/*************************************************************************
���������ơ� ToWeekDay���������ܡ� ת��Ϊ���ڼ�
�������� ��
������ֵ�� WeekDay Temp�����ڼ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
MOWeekDay YMDDate::ToMOWeekDay() const {
	unsigned int uTempOrdial = MDDate::GetDay() / 7 + 1;
	return MOWeekDay(MDDate::GetMonthValue(), uTempOrdial, ToWeekDay());
}

/*************************************************************************
���������ơ� ToWeekDay���������ܡ� ת��Ϊ���ڼ�
�������� �������YMDDate
������ֵ�� WeekDay Temp�����ڼ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
MOWeekDay YMDDate::ToMOWeekDay(const YMDDate& YMDDate) {
	unsigned int uTempOrdial = YMDDate.GetDay() / 7 + 1;
	return MOWeekDay(YMDDate.GetMonthValue(), uTempOrdial, YMDDate.ToWeekDay());
}

/*************************************************************************
���������ơ� ToWeekDay���������ܡ� ת��Ϊ���ڼ�
�������� �������uYear���������uMonth���������uDay
������ֵ�� WeekDay Temp�����ڼ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
MOWeekDay YMDDate::ToMOWeekDay(const unsigned int& uYear
							, const unsigned int& uMonth
							, const unsigned int& uDay) {
	unsigned int uTempOrdial = uDay / 7 + 1;
	return MOWeekDay(uMonth, uTempOrdial, ToWeekDay(uYear, uMonth, uDay));
}

/*************************************************************************
���������ơ� ToWeekDay���������ܡ� ת��Ϊ���ڼ�
�������� �������uYear���������Month���������uDay
������ֵ�� WeekDay Temp�����ڼ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
MOWeekDay YMDDate::ToMOWeekDay(const unsigned int& uYear
							, const Month& Month
							, const unsigned int& uDay) {
	unsigned int uTempOrdial = uDay / 7 + 1;
	return MOWeekDay(Month, uTempOrdial, ToWeekDay(uYear, Month, uDay));
}


/*************************************************************************
���������ơ� YMOWeekDayToYMDDate���������ܡ� YMOWת��Ϊ������
�������� �������uYear���������uMonth���������uOrdial���������uActualWeekDay
������ֵ�� WeekDay Temp�����ڼ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
YMDDate YMDDate::YMOWeekDayToYMDDate(const unsigned int& uYear
									, const unsigned int& uMonth
									, const unsigned int& uOrdial
									, const unsigned int& uActualWeekDay) {
	if (uActualWeekDay > 7 || uActualWeekDay < 1) {
		throw invalid_argument("������1~7֮�ڵ�������");
	}
	else {
		if (uActualWeekDay
			>= YMDDate(uYear, uMonth, 1).ToWeekDay().GetActualValue()) {
			unsigned int uDaysPassedInThisMonth
				= (uOrdial - 1) * 7 + ((uActualWeekDay
					- YMDDate(uYear, uMonth, 1).ToWeekDay().GetActualValue()) % 7) + 1;
			return YMDDate(uYear, uMonth, uDaysPassedInThisMonth);
		}
		else {
			unsigned int uDaysPassedInThisMonth
				= (uOrdial - 1) * 7 + ((uActualWeekDay + 7
					- YMDDate(uYear, uMonth, 1).ToWeekDay().GetActualValue()) % 7) + 1;
			return YMDDate(uYear, uMonth, uDaysPassedInThisMonth);
		}
	}
}

/*************************************************************************
���������ơ� Today���������ܡ� �õ����������
�������� ��
������ֵ�� YMDDate ����
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
YMDDate YMDDate::Today() {
	auto tp = std::chrono::system_clock::now();
	time_t cur_time = std::chrono::system_clock::to_time_t(tp);
	struct tm* pTimeInfo = localtime(&cur_time);
	return YMDDate(pTimeInfo->tm_year + 1900
		, pTimeInfo->tm_mon + 1, pTimeInfo->tm_mday);
}


