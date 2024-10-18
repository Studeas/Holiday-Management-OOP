/*************************************************************************
【文件名】 MDDate.cpp
【功能模块和目的】 维护MDDate类，集中编写MDDate类成员函数的定义。
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/

#include "MDDate.hpp"

unsigned int MDDate::MinDay = 1;
unsigned int MDDate::MaxDay = 31;

const unsigned int MDDate::DaysOfMonthMax[13] = {
    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

/*************************************************************************
【函数名称】 MDDate【函数功能】 构造函数
【参数】 输入参数uMonth，输入参数uDay
【返回值】 构造函数，无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
MDDate::MDDate(const unsigned int& uMonth, const unsigned int& uDay) 
		: TheMonth(m_Month), Day(m_Day)  {
	Set(uMonth, uDay);
}

/*************************************************************************
【函数名称】 MDDate【函数功能】 构造函数
【参数】 输入参数Month，输入参数uDay
【返回值】 构造函数，无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
MDDate::MDDate(const Month& Month, const unsigned int& uDay) 
		: TheMonth(m_Month), Day(m_Day) {
	Set(Month, uDay);
}

/*************************************************************************
【函数名称】 operator=【函数功能】 赋值运算符
【参数】 输入参数MDDate
【返回值】 this*指针
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
MDDate& MDDate::operator=(const MDDate& MDDate) {
	if (this == &MDDate) {
		return *this;
	}
	this->m_Month = MDDate.m_Month;
	this->m_Day = MDDate.m_Day;
	return *this;
}

/*************************************************************************
【函数名称】 Set【函数功能】 设置月日
【参数】 输入参数uMonth，uDay
【返回值】 无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
void MDDate::Set(const unsigned int& uMonth, const unsigned int& uDay) {
	if (!IsValidMDDate(uMonth, uDay)) {
		throw invalid_argument("‘月日’日期超限。");
	}
	this->m_Month = uMonth;
	this->m_Day = uDay;
}

/*************************************************************************
【函数名称】 Set【函数功能】 设置月日
【参数】 输入参数Month，uDay
【返回值】 无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
void MDDate::Set(const Month& Month, const unsigned int& uDay) {
	if (!IsValidMDDate(Month, uDay)) {
		throw invalid_argument("‘月日’日期超限。");
	}
	this->m_Month = Month;
	this->m_Day = uDay;
}

/*************************************************************************
【函数名称】 SetMonth【函数功能】 设置月
【参数】 输入参数uMonth
【返回值】 无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
void MDDate::SetMonth(const unsigned int& uMonth) {
	this->m_Month = uMonth;
}

/*************************************************************************
【函数名称】 SetMonth【函数功能】 设置月
【参数】 输入参数Month
【返回值】 无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
void MDDate::SetMonth(const Month& Month) {
	this->m_Month = Month;
}

/*************************************************************************
【函数名称】 SetDay【函数功能】 设置日
【参数】 输入参数uDay
【返回值】 无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
void MDDate::SetDay(const unsigned int& uDay) {
	if (!IsValidMDDate(m_Month, uDay)) {
		throw invalid_argument("‘月日’日期超限。");
	}
	this->m_Day = uDay;
}

/*************************************************************************
【函数名称】 IsValidMDDate【函数功能】 月日合法性检查
【参数】 输入参数uMonth，输入参数uDay
【返回值】 bool，合法则返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool MDDate::IsValidMDDate(const unsigned int& uMonth, const unsigned int& uDay) {
	if ((uDay > 0) && (uDay <= DaysOfMonthMax[uMonth])) {
		return true;
	}
	return false;
}

/*************************************************************************
【函数名称】 IsValidMDDate【函数功能】 月日合法性检查
【参数】 输入参数Month，输入参数uDay
【返回值】 bool，合法则返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool MDDate::IsValidMDDate(const Month::ValueType& Month, const unsigned int& uDay) {
	if ((uDay > 0) && (uDay <= DaysOfMonthMax[static_cast<unsigned int>(Month)])) {
		return true;
	}
	return false;
}
/*************************************************************************
【函数名称】 IsValidMDDate【函数功能】 月日合法性检查
【参数】 输入参数Month，输入参数uDay
【返回值】 bool，合法则返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool MDDate::IsValidMDDate(const Month& Month, const unsigned int& uDay) {
	if ((uDay > 0) && (uDay <= DaysOfMonthMax[Month.GetValue()])) {
		return true;
	}
	return false;
}

/*************************************************************************
【函数名称】 IsValidMDDate【函数功能】 月日合法性检查
【参数】 无
【返回值】 bool，合法则返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool MDDate::IsValidMDDate() const {
	if ((m_Day > 0) && (m_Day <= DaysOfMonthMax[m_Month.GetValue()])) {
		return true;
	}
	return false;
}

/*************************************************************************
【函数名称】 operator==【函数功能】 ==运算符
【参数】 输入参数Source
【返回值】 bool，符合条件为true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool MDDate::operator==(const MDDate& Source) const {
	return (Source.m_Month == m_Month) && (Source.m_Day == m_Day);
}
/*************************************************************************
【函数名称】 operator==【函数功能】 ==运算符
【参数】 输入参数Source
【返回值】 bool，符合条件为true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator==(const MDDate& MDDate1, const MDDate& MDDate2) {
	return (MDDate1.m_Month == MDDate2.m_Month) && (MDDate1.m_Day == MDDate2.m_Day);
}
/*************************************************************************
【函数名称】 operator!=【函数功能】 !=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件为true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool MDDate::operator!=(const MDDate& Source) const {
	return (Source.m_Month != m_Month) || (Source.m_Day != m_Day);
}
/*************************************************************************
【函数名称】 operator!=【函数功能】 !=运算符
【参数】 输入参数MDDate1, MDDate2
【返回值】 bool，符合条件为true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator!=(const MDDate& MDDate1, const MDDate& MDDate2) {
	return (MDDate1.m_Month != MDDate2.m_Month) || (MDDate1.m_Day != MDDate2.m_Day);
}
/*************************************************************************
【函数名称】 operator>【函数功能】 >运算符
【参数】 输入参数Source
【返回值】 bool，符合条件为true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool MDDate::operator>(const MDDate& Source) const {
	if (m_Month > Source.m_Month) {
		return true;
	}
	if ((m_Month == Source.m_Month) && (m_Day > Source.m_Day)) {
		return true;
	}
	return false;
}
/*************************************************************************
【函数名称】 operator>【函数功能】 >运算符
【参数】 输入参数MDDate1, MDDate2
【返回值】 bool，符合条件为true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator>(const MDDate& MDDate1, const MDDate& MDDate2) {
	if (MDDate1.m_Month > MDDate2.m_Month) {
		return true;
	}
	if ((MDDate1.m_Month == MDDate2.m_Month) && (MDDate1.m_Day > MDDate2.m_Day)) {
		return true;
	}
	return false;
}
/*************************************************************************
【函数名称】 operator<【函数功能】 <运算符
【参数】 输入参数Source
【返回值】 bool，符合条件为true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool MDDate::operator<(const MDDate& Source) const {
	if (m_Month < Source.m_Month) {
		return true;
	}
	if ((m_Month == Source.m_Month) && (m_Day < Source.m_Day)) {
		return true;
	}
	return false;
}
/*************************************************************************
【函数名称】 operator<【函数功能】 <运算符
【参数】 输入参数MDDate1, MDDate2
【返回值】 bool，符合条件为true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator<(const MDDate& MDDate1, const MDDate& MDDate2) {
	if (MDDate1.m_Month < MDDate2.m_Month) {
		return true;
	}
	if ((MDDate1.m_Month == MDDate2.m_Month) && (MDDate1.m_Day < MDDate2.m_Day)) {
		return true;
	}
	return false;
}
/*************************************************************************
【函数名称】 operator>=【函数功能】 >=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件为true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool MDDate::operator>=(const MDDate& Source) const {
	if (m_Month > Source.m_Month) {
		return true;
	}
	if ((m_Month == Source.m_Month) && (m_Day >= Source.m_Day)) {
		return true;
	}
	return false;
}
/*************************************************************************
【函数名称】 operator>=【函数功能】 >=运算符
【参数】 输入参数MDDate1, MDDate2
【返回值】 bool，符合条件为true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator>=(const MDDate& MDDate1, const MDDate& MDDate2) {
	if (MDDate1.m_Month > MDDate2.m_Month) {
		return true;
	}
	if ((MDDate1.m_Month == MDDate2.m_Month) && (MDDate1.m_Day >= MDDate2.m_Day)) {
		return true;
	}
	return false;
}
/*************************************************************************
【函数名称】 operator<=【函数功能】 <=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件为true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool MDDate::operator<=(const MDDate& Source) const {
	if (m_Month < Source.m_Month) {
		return true;
	}
	if ((m_Month == Source.m_Month) && (m_Day <= Source.m_Day)) {
		return true;
	}
	return false;
}
/*************************************************************************
【函数名称】 operator<=【函数功能】 <=运算符
【参数】 输入参数MDDate1, MDDate2
【返回值】 bool，符合条件为true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator<=(const MDDate& MDDate1, const MDDate& MDDate2) {
	if (MDDate1.m_Month < MDDate2.m_Month) {
		return true;
	}
	if ((MDDate1.m_Month == MDDate2.m_Month) && (MDDate1.m_Day <= MDDate2.m_Day)) {
		return true;
	}
	return false;
}

/*************************************************************************
【函数名称】 operator++【函数功能】 ++运算符
【参数】 无
【返回值】 *this
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
MDDate& MDDate::operator++() {
	if (m_Day < DaysOfMonthMax[m_Month.GetValue()]) {
		++m_Day;
		return *this;
	}
	else {
		++m_Month;
		m_Day = 1;
		return *this;
	}
}
/*************************************************************************
【函数名称】 operator++【函数功能】 ++运算符
【参数】 int，无实际意义
【返回值】 Temp
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
MDDate MDDate::operator++(int) {
	MDDate Temp{ *this };
	++(*this);
	return Temp;
}
/*************************************************************************
【函数名称】 operator--【函数功能】 --运算符
【参数】 无
【返回值】 *this
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
MDDate& MDDate::operator--() {
	if (m_Day > 1) {
		--m_Day;
		return *this;
	}
	else {
		--m_Month;
		m_Day = DaysOfMonthMax[m_Month.GetValue()];
		return *this;
	}
}
/*************************************************************************
【函数名称】 operator--【函数功能】 --运算符
【参数】 int，无实际意义
【返回值】 Temp
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
MDDate MDDate::operator--(int) {
	MDDate Temp{ *this };
	--(*this);
	return Temp;
}

/*************************************************************************
【函数名称】 GetMonth【函数功能】 获得月
【参数】 输入参数Type
【返回值】 string 月的名称
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
string MDDate::GetMonth(const Month::NameType& Type) const {
	return m_Month.ToName(Type);
}

/*************************************************************************
【函数名称】 GetMonthValue【函数功能】 获得月的值
【参数】 无
【返回值】 unsigned int m_Month.GetValue()月的值
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
unsigned int MDDate::GetMonthValue() const {
	return m_Month.GetValue();
}

/*************************************************************************
【函数名称】 GetDay【函数功能】 获得日
【参数】 无
【返回值】 unsigned int m_Day日
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
unsigned int MDDate::GetDay() const {
	return m_Day;
}

/*************************************************************************
【函数名称】 GetDaysOfMonthMax【函数功能】 得到月份的最大日
【参数】 输入参数Month
【返回值】 unsigned int最大日
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
unsigned int MDDate::GetDaysOfMonthMax(const Month& Month) {
	return MDDate(Month,1).GetDaysOfMonthMax();
}

/*************************************************************************
【函数名称】 GetDaysOfMonthMax【函数功能】 得到月份的最大日
【参数】 输入参数uMonth
【返回值】 unsigned int最大日
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
unsigned int MDDate::GetDaysOfMonthMax(const unsigned int& uMonth) {
	return MDDate(uMonth, 1).GetDaysOfMonthMax();
}

/*************************************************************************
【函数名称】 GetDaysOfMonthMax【函数功能】 得到月份的最大日
【参数】 无
【返回值】 unsigned int最大日
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
unsigned int MDDate::GetDaysOfMonthMax() const {
	return DaysOfMonthMax[m_Month.GetValue()];
}
