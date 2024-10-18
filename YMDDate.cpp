/*************************************************************************
【文件名】 YMDDate.cpp
【功能模块和目的】 维护YMDDate类，集中编写YMDDate类成员函数的定义。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "YMDDate.hpp"
#include <chrono>
#include <ctime>
#include <iostream>

unsigned int YMDDate::s_MaxYear = 9999;
unsigned int YMDDate::s_MinYear = 1900;

/*************************************************************************
【函数名称】 YMDDate【函数功能】 构造函数
【参数】 输入参数uYear，输入参数uMonth，输入参数uDay
【返回值】 构造函数，无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
YMDDate::YMDDate(const unsigned int& uYear
				, const unsigned int& uMonth
				, const unsigned int& uDay): MDDate(uMonth, uDay) {
	if (!IsValidYMDDate(uYear, uMonth, uDay)) {
		throw invalid_argument("‘年月日’日期超限或不存在。");
	}
	Set(uYear, uMonth, uDay);
}

/*************************************************************************
【函数名称】 YMDDate【函数功能】 构造函数
【参数】 输入参数uYear，输入参数uMonth，输入参数uDay
【返回值】 构造函数，无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
YMDDate::YMDDate(const unsigned int& uYear
				, const Month& Month
				, const unsigned int& uDay): MDDate(Month, uDay) {
	if (!IsValidYMDDate(uYear, Month, uDay)) {
		throw invalid_argument("‘年月日’日期超限或不存在。");
	}
	Set(uYear, Month, uDay);
}

/*************************************************************************
【函数名称】 YMDDate【函数功能】 构造函数
【参数】 输入参数uYear，输入参数MDDate
【返回值】 构造函数，无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
YMDDate::YMDDate(const unsigned int& uYear
				, const MDDate& MDDate): MDDate(MDDate) {
	if (!IsValidYMDDate(uYear, MDDate.GetMonthValue(), MDDate.GetDay())) {
		throw invalid_argument("‘年月日’日期超限或不存在。");
	}
	Set(uYear, MDDate);
}

/*************************************************************************
【函数名称】 operator=【函数功能】 赋值运算符
【参数】 输入参数Source
【返回值】 *this
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
YMDDate& YMDDate::operator=(const YMDDate& Source) {
	if (this == &Source) {
		return *this;
	}
	MDDate::operator=(Source);
	m_Year = Source.m_Year;
}

/*************************************************************************
【函数名称】 operator==【函数功能】 ==运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool YMDDate::operator==(const YMDDate& Source) const {
	return (Source.m_Year == m_Year) 
		&& (Source.GetMonth() == this->GetMonth()) 
		&& (Source.GetDay() == this->GetDay());
}

/*************************************************************************
【函数名称】 operator==【函数功能】 ==运算符
【参数】 输入参数YMDDate1，输入参数YMDDate2
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator==(const YMDDate& YMDDate1, const YMDDate& YMDDate2) {
	return (YMDDate1.m_Year == YMDDate2.m_Year) 
		&& (YMDDate1.GetMonth() == YMDDate2.GetMonth()) 
		&& (YMDDate1.GetDay() == YMDDate2.GetDay());
}

/*************************************************************************
【函数名称】 operator!=【函数功能】 !=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool YMDDate::operator!=(const YMDDate& Source) const {
	return (Source.m_Year != m_Year) 
		|| (Source.GetMonth() != this->GetMonth())
		|| (Source.GetDay() != this->GetDay());
}

/*************************************************************************
【函数名称】 operator!=【函数功能】 !=运算符
【参数】 输入参数YMDDate1，输入参数YMDDate2
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator!=(const YMDDate& YMDDate1, const YMDDate& YMDDate2) {
	return (YMDDate1.m_Year != YMDDate2.m_Year) || (YMDDate1.GetMonth() != YMDDate2.GetMonth()) || (YMDDate1.GetDay() != YMDDate2.GetDay());
}

/*************************************************************************
【函数名称】 operator>【函数功能】 >运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 operator>【函数功能】 >运算符
【参数】 输入参数YMDDate1，输入参数YMDDate2
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 operator<【函数功能】 <运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 operator<【函数功能】 <运算符
【参数】 输入参数YMDDate1，输入参数YMDDate2
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 operator>=【函数功能】 >=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 operator>=【函数功能】 >=运算符
【参数】 输入参数YMDDate1，输入参数YMDDate2
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 operator<=【函数功能】 <=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 operator<=【函数功能】 <=运算符
【参数】 输入参数YMDDate1，输入参数YMDDate2
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 operator++【函数功能】 前置++运算符
【参数】 无
【返回值】 *this
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
YMDDate& YMDDate::operator++() {
	if ((this->GetMonthValue() == 12) && (this->GetDay() == 31)) {
		if (m_Year + 1 > s_MaxYear) {
			throw invalid_argument("日期超限");
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
【函数名称】 operator++【函数功能】 后置++运算符
【参数】 无
【返回值】 Temp
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
YMDDate YMDDate::operator++(int) {
	YMDDate Temp{ *this };
	++(*this);
	return Temp;
}

/*************************************************************************
【函数名称】 operator--【函数功能】 前置--运算符
【参数】 无
【返回值】 *this
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
YMDDate& YMDDate::operator--() {
	if ((this->GetMonthValue() == 1) && (this->GetDay() == 1)) {
		if (m_Year - 1 < s_MinYear) {
			throw invalid_argument("日期超限");
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
【函数名称】 operator--【函数功能】 后置--运算符
【参数】 无
【返回值】 Temp
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
YMDDate YMDDate::operator--(int) {
	YMDDate Temp{ *this };
	--(*this);
	return Temp;
}

/*************************************************************************
【函数名称】 Set【函数功能】 设置年月日
【参数】 输入参数uYear，输入参数MDDate
【返回值】 无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
void YMDDate::Set(const unsigned int& uYear, const MDDate& MDDate) {
	if (IsValidYMDDate(uYear, MDDate.GetMonthValue(), MDDate.GetDay())) {
		m_Year = uYear;
		MDDate::operator=(MDDate);
	}	
}

/*************************************************************************
【函数名称】 Set【函数功能】 设置年月日
【参数】 输入参数uYear，输入参数Month，输入参数uDay
【返回值】 无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 Set【函数功能】 设置年月日
【参数】 输入参数uYear，输入参数uMonth，输入参数uDay
【返回值】 无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 SetYear【函数功能】 设置年
【参数】 输入参数uYear
【返回值】 无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
void YMDDate::SetYear(const unsigned int& uYear) {
	if (IsValidYMDDate(uYear, MDDate::GetMonthValue(), MDDate::GetDay())) {
		m_Year = uYear;
	}
}

/*************************************************************************
【函数名称】 GetYear【函数功能】 获取年
【参数】 无
【返回值】 m_Year
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
unsigned int YMDDate::GetYear() const {
	return m_Year;
}

/*************************************************************************
【函数名称】 IsLeapYear【函数功能】 判断闰年
【参数】 无
【返回值】 bool true 是闰年
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool YMDDate::IsLeapYear() const {
	if ((m_Year % 4 == 0 && m_Year % 100 != 0) || (m_Year % 400 == 0)) {
		return true;
	}
	return false;
}

/*************************************************************************
【函数名称】 IsLeapYear【函数功能】 判断闰年
【参数】 输入参数uYear
【返回值】 bool true 是闰年
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool YMDDate::IsLeapYear(const unsigned int& uYear) {
	if ((uYear % 4 == 0 && uYear % 100 != 0) || (uYear % 400 == 0)) {
		return true;
	}
	return false;
}

/*************************************************************************
【函数名称】 IsLeapYear【函数功能】 判断日期合法性
【参数】 无
【返回值】 bool true 合法
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool YMDDate::IsValidYMDDate() const {
	if (IsValidYMDDate(m_Year, this->GetMonthValue(), this->GetDay())) {
		return true;
	}
	throw invalid_argument("日期超限或不存在");
}

/*************************************************************************
【函数名称】 IsLeapYear【函数功能】 判断日期合法性
【参数】 输入参数uYear，输入参数Month，输入参数uDay
【返回值】 bool true 合法
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool YMDDate::IsValidYMDDate(const unsigned int& uYear
							, const Month& Month
							, const unsigned int uDay) {
	if (uYear < s_MinYear || uYear > s_MaxYear) {
		throw invalid_argument("日期超限或不存在");
	}
	else {
		if (IsLeapYear(uYear)) {
			if (IsValidMDDate(Month, uDay)) {
				return true;
			}
			throw invalid_argument("日期超限或不存在");
		}
		else {
			if (IsValidMDDate(Month, uDay) 
				&& !(Month.GetValue() == 2 && uDay == 29)) {
				return true;
			}
			throw invalid_argument("日期超限或不存在");
		}
	}
}

/*************************************************************************
【函数名称】 IsValidYMDDate【函数功能】 判断日期合法性
【参数】 输入参数uYear，输入参数Month，输入参数uDay
【返回值】 bool true 合法
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool YMDDate::IsValidYMDDate(const unsigned int& uYear
							, const unsigned int& uMonth
							, const unsigned int& uDay) {
	if (uYear < s_MinYear || uYear > s_MaxYear) {
		throw invalid_argument("日期超限或不存在");
	}
	else {
		if (IsLeapYear(uYear)) {
			if (IsValidMDDate(uMonth, uDay)) {
				return true;
			}
			throw invalid_argument("日期超限或不存在");
		}
		else {
			if (IsValidMDDate(uMonth, uDay) && !(uMonth == 2 && uDay == 29)) {
				return true;
			}
			throw invalid_argument("日期超限或不存在");
		}
	}
}

/*************************************************************************
【函数名称】 DaysPassedInThisYear【函数功能】 今年的第几天
【参数】 无
【返回值】 Days 第几天
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 DaysPassedInThisYear【函数功能】 今年的第几天
【参数】 输入参数YMDDate
【返回值】 Days 第几天
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 DaysPassedInTotal【函数功能】 从19000101第几天
【参数】 无
【返回值】 Days 第几天
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 DaysPassedInTotal【函数功能】 从19000101第几天
【参数】 输入参数YMDDate
【返回值】 Days 第几天
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 ToWeekDay【函数功能】 转换为星期几
【参数】 无
【返回值】 WeekDay Temp，星期几
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 ToWeekDay【函数功能】 转换为星期几
【参数】 输入参数YMDDate
【返回值】 WeekDay Temp，星期几
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 ToWeekDay【函数功能】 转换为星期几
【参数】 输入参数uYear，输入参数uMonth，输入参数uDay
【返回值】 WeekDay Temp，星期几
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 ToWeekDay【函数功能】 转换为星期几
【参数】 输入参数uYear，输入参数uMonth，输入参数uDay
【返回值】 WeekDay Temp，星期几
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 ToWeekDay【函数功能】 转换为星期几
【参数】 无
【返回值】 WeekDay Temp，星期几
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
MOWeekDay YMDDate::ToMOWeekDay() const {
	unsigned int uTempOrdial = MDDate::GetDay() / 7 + 1;
	return MOWeekDay(MDDate::GetMonthValue(), uTempOrdial, ToWeekDay());
}

/*************************************************************************
【函数名称】 ToWeekDay【函数功能】 转换为星期几
【参数】 输入参数YMDDate
【返回值】 WeekDay Temp，星期几
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
MOWeekDay YMDDate::ToMOWeekDay(const YMDDate& YMDDate) {
	unsigned int uTempOrdial = YMDDate.GetDay() / 7 + 1;
	return MOWeekDay(YMDDate.GetMonthValue(), uTempOrdial, YMDDate.ToWeekDay());
}

/*************************************************************************
【函数名称】 ToWeekDay【函数功能】 转换为星期几
【参数】 输入参数uYear，输入参数uMonth，输入参数uDay
【返回值】 WeekDay Temp，星期几
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
MOWeekDay YMDDate::ToMOWeekDay(const unsigned int& uYear
							, const unsigned int& uMonth
							, const unsigned int& uDay) {
	unsigned int uTempOrdial = uDay / 7 + 1;
	return MOWeekDay(uMonth, uTempOrdial, ToWeekDay(uYear, uMonth, uDay));
}

/*************************************************************************
【函数名称】 ToWeekDay【函数功能】 转换为星期几
【参数】 输入参数uYear，输入参数Month，输入参数uDay
【返回值】 WeekDay Temp，星期几
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
MOWeekDay YMDDate::ToMOWeekDay(const unsigned int& uYear
							, const Month& Month
							, const unsigned int& uDay) {
	unsigned int uTempOrdial = uDay / 7 + 1;
	return MOWeekDay(Month, uTempOrdial, ToWeekDay(uYear, Month, uDay));
}


/*************************************************************************
【函数名称】 YMOWeekDayToYMDDate【函数功能】 YMOW转换为年月日
【参数】 输入参数uYear，输入参数uMonth，输入参数uOrdial，输入参数uActualWeekDay
【返回值】 WeekDay Temp，星期几
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
YMDDate YMDDate::YMOWeekDayToYMDDate(const unsigned int& uYear
									, const unsigned int& uMonth
									, const unsigned int& uOrdial
									, const unsigned int& uActualWeekDay) {
	if (uActualWeekDay > 7 || uActualWeekDay < 1) {
		throw invalid_argument("请输入1~7之内的整数。");
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
【函数名称】 Today【函数功能】 得到今天的日期
【参数】 无
【返回值】 YMDDate 今天
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
YMDDate YMDDate::Today() {
	auto tp = std::chrono::system_clock::now();
	time_t cur_time = std::chrono::system_clock::to_time_t(tp);
	struct tm* pTimeInfo = localtime(&cur_time);
	return YMDDate(pTimeInfo->tm_year + 1900
		, pTimeInfo->tm_mon + 1, pTimeInfo->tm_mday);
}


