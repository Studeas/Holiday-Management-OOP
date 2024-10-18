/*************************************************************************
【文件名】 MOWeekDay.cpp
【功能模块和目的】 维护MOWeekDay类，集中编写MOWeekDay类成员函数的定义。
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/

#include "MOWeekDay.hpp"

/*************************************************************************
【函数名称】 MOWeekDay【函数功能】 构造函数
【参数】 输入参数Month，输入参数uOrdial，输入参数WeekDay
【返回值】 构造函数，无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
MOWeekDay::MOWeekDay(const Month& Month, const unsigned int& uOrdial
					, const WeekDay& WeekDay): m_Month(Month), m_Ordial(uOrdial)
					, m_WeekDay(WeekDay) {
	Set(Month, uOrdial, WeekDay);
}

/*************************************************************************
【函数名称】 MOWeekDay【函数功能】 构造函数
【参数】 输入参数uMonth，输入参数uOrdial，输入参数uActualWeekDayValue
【返回值】 构造函数，无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
MOWeekDay::MOWeekDay(const unsigned int& uMonth, const unsigned int& uOrdial
					, const unsigned int& uActualWeekDayValue) : m_Month(uMonth)
					, m_Ordial(uOrdial), m_WeekDay(uActualWeekDayValue) {
	Set(uMonth, uOrdial, uActualWeekDayValue);
}

/*************************************************************************
【函数名称】 MOWeekDay【函数功能】 构造函数
【参数】 输入参数uMonth，输入参数uOrdial，输入参数uActualWeekDayValue
【返回值】 构造函数，无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
MOWeekDay::MOWeekDay(const Month& Month, const unsigned int& uOrdial
					, const unsigned int& uActualWeekDayValue) : m_Month(Month)
					, m_Ordial(uOrdial), m_WeekDay(uActualWeekDayValue) {
	Set(Month, uOrdial, uActualWeekDayValue);
}

/*************************************************************************
【函数名称】 MOWeekDay【函数功能】 构造函数
【参数】 输入参数Source
【返回值】 构造函数，无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
MOWeekDay::MOWeekDay(const MOWeekDay& Source) : m_Month(Source.m_Month)
					, m_Ordial(Source.m_Ordial), m_WeekDay(Source.m_WeekDay) {

}

/*************************************************************************
【函数名称】 operator=【函数功能】 赋值运算符
【参数】 输入参数Source
【返回值】 *this
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
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
【函数名称】 Set【函数功能】 设置日期
【参数】 输入参数Month，输入参数uOrdial，输入参数WeekDay
【返回值】 无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
void MOWeekDay::Set(const Month& Month, const unsigned int& uOrdial
					, const WeekDay& WeekDay) {
	if (MOWeekDay::IsValidMOWeekDay(Month, uOrdial, WeekDay)) {
		m_Month = Month;
		m_Ordial = uOrdial;
		m_WeekDay = WeekDay;
	}
	else {
		throw invalid_argument("MOWeekDay超限");
	}
}

/*************************************************************************
【函数名称】 Set【函数功能】 设置日期
【参数】 输入参数uMonth，输入参数uOrdial，输入参数uActualWeekDayValue
【返回值】 无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
void MOWeekDay::Set(const unsigned int& uMonth, const unsigned int& uOrdial
					, const unsigned int& uActualWeekDayValue) {
	if (MOWeekDay::IsValidMOWeekDay(uMonth, uOrdial, uActualWeekDayValue)) {
		m_Month = uMonth;
		m_Ordial = uOrdial;
		m_WeekDay = uActualWeekDayValue;
	}
	else {
		throw invalid_argument("MOWeekDay超限");
	}
}

/*************************************************************************
【函数名称】 Set【函数功能】 设置日期
【参数】 输入参数Month，输入参数uOrdial，输入参数uActualWeekDayValue
【返回值】 无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
void MOWeekDay::Set(const Month& Month, const unsigned int& uOrdial
	, const unsigned int& uActualWeekDayValue) {
	if (MOWeekDay::IsValidMOWeekDay(Month, uOrdial, uActualWeekDayValue)) {
		m_Month = Month;
		m_Ordial = uOrdial;
		m_WeekDay = uActualWeekDayValue;
	}
	else {
		throw invalid_argument("MOWeekDay超限");
	}
}

/*************************************************************************
【函数名称】 SetMonth【函数功能】 设置月
【参数】 输入参数uMonth
【返回值】 无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
void MOWeekDay::SetMonth(const unsigned int& uMonth) {
	if (MOWeekDay::IsValidMOWeekDay(uMonth, m_Ordial, m_WeekDay)) {
		m_Month = uMonth;
	}
	else {
		throw invalid_argument("MOWeekDay超限");
	}
}

/*************************************************************************
【函数名称】 SetMonth【函数功能】 设置月
【参数】 输入参数Month
【返回值】 无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
void MOWeekDay::SetMonth(const Month& Month) {
	if (MOWeekDay::IsValidMOWeekDay(Month, m_Ordial, m_WeekDay)) {
		m_Month = Month;
	}
	else {
		throw invalid_argument("MOWeekDay超限");
	}
}

/*************************************************************************
【函数名称】 SetOrdial【函数功能】 设置第某个
【参数】 输入参数uOrdial
【返回值】 无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
void MOWeekDay::SetOrdial(const unsigned int& uOrdial) {
	if (MOWeekDay::IsValidMOWeekDay(m_Month, uOrdial, m_WeekDay)) {
		m_Ordial = uOrdial;
	}
	else {
		throw invalid_argument("MOWeekDay超限");
	}
}

/*************************************************************************
【函数名称】 SetWeekDay【函数功能】 设置星期几
【参数】 输入参数WeekDay
【返回值】 无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
void MOWeekDay::SetWeekDay(const WeekDay& WeekDay) {
	if (MOWeekDay::IsValidMOWeekDay(m_Month, m_Ordial, WeekDay)) {
		m_WeekDay = WeekDay;
	}
	else {
		throw invalid_argument("MOWeekDay超限");
	}
}

/*************************************************************************
【函数名称】 SetWeekDay【函数功能】 设置星期几
【参数】 输入参数uActualWeekDayValue
【返回值】 无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
void MOWeekDay::SetWeekDay(const unsigned int& uActualWeekDayValue) {
	if (MOWeekDay::IsValidMOWeekDay(m_Month, m_Ordial, uActualWeekDayValue)) {
		m_WeekDay = uActualWeekDayValue;
	}
	else {
		throw invalid_argument("MOWeekDay超限");
	}
}

/*************************************************************************
【函数名称】 IsValidMOWeekDay【函数功能】 判断日期合法性
【参数】 输入参数Month，输入参数uOrdial，输入参数WeekDay
【返回值】 bool，合法则为true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
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
【函数名称】 IsValidMOWeekDay【函数功能】 判断日期合法性
【参数】 输入参数Month，输入参数uOrdial，输入参数uActualWeekDayValue
【返回值】 bool，合法则为true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool MOWeekDay::IsValidMOWeekDay(const unsigned int& uMonth
								, const unsigned int& uOrdial
								, const unsigned int& uActualWeekDayValue) {
	class Month TempMonth(uMonth);
	WeekDay TempWeekDay(uActualWeekDayValue);
	return IsValidMOWeekDay(TempMonth, uOrdial, TempWeekDay);
}

/*************************************************************************
【函数名称】 IsValidMOWeekDay【函数功能】 判断日期合法性
【参数】 输入参数Month，输入参数uOrdial，输入参数uActualWeekDayValue
【返回值】 bool，合法则为true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool MOWeekDay::IsValidMOWeekDay(const Month& Month
								, const unsigned int& uOrdial
								, const unsigned int& uActualWeekDayValue) {
	WeekDay TempWeekDay(uActualWeekDayValue);
	return IsValidMOWeekDay(Month, uOrdial, TempWeekDay);
}

/*************************************************************************
【函数名称】 IsValidMOWeekDay【函数功能】 判断日期合法性
【参数】 无
【返回值】 bool，合法则为true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool MOWeekDay::IsValidMOWeekDay() const {
	return IsValidMOWeekDay(m_Month, m_Ordial, m_WeekDay);
}

/*************************************************************************
【函数名称】 GetMonth【函数功能】 获得月
【参数】 无
【返回值】 m_Month 月
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
Month MOWeekDay::GetMonth() const {
	return m_Month;
}

/*************************************************************************
【函数名称】 GetMonthValue【函数功能】 获得月的值
【参数】 无
【返回值】 m_Month.GetValue() 月
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
unsigned int MOWeekDay::GetMonthValue() const {
	return m_Month.GetValue();
}

/*************************************************************************
【函数名称】 GetOrdial【函数功能】 获得第某个
【参数】 无
【返回值】 m_Ordial 第某个
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
unsigned int MOWeekDay::GetOrdial() const {
	return m_Ordial;
}

/*************************************************************************
【函数名称】 GetWeekDay【函数功能】 获得星期几
【参数】 无
【返回值】 m_WeekDay 星期几
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
WeekDay MOWeekDay::GetWeekDay() const {
	return m_WeekDay;
}

/*************************************************************************
【函数名称】 GetWeekDay【函数功能】 获得星期几
【参数】 无
【返回值】 m_WeekDay.GetActualValue() 星期几的值
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
unsigned int MOWeekDay::GetWeekDayActualValue() const {
	return m_WeekDay.GetActualValue();
}
