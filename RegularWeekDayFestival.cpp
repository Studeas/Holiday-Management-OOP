/*************************************************************************
【文件名】 RegularWeekDayFestival.cpp
【功能模块和目的】 维护RegularWeekDayFestival类，集中编写RegularWeekDayFestival类成员函数的定义。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/

#include "RegularWeekDayFestival.hpp"
#include <stdexcept>

/*************************************************************************
【函数名称】 RegularWeekDayFestival【函数功能】 构造函数
【参数】 输入参数Name，输入参数MOWeekDay
【返回值】 构造函数，无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
RegularWeekDayFestival::RegularWeekDayFestival(const string& Name
	, const MOWeekDay& MOWeekDay) : Festival(Name), m_MOWeekDay(MOWeekDay) {

}

/*************************************************************************
【函数名称】 RegularWeekDayFestival【函数功能】 构造函数
【参数】 输入参数Name，输入参数Month，输入参数uOrdial，输入参数WeekDay
【返回值】 构造函数，无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
RegularWeekDayFestival::RegularWeekDayFestival(const string& Name
											, const Month& Month
											, const unsigned int& uOrdial
											, const WeekDay& WeekDay) 
									: Festival(Name)
									, m_MOWeekDay(Month, uOrdial, WeekDay) {
}

/*************************************************************************
【函数名称】 Add【函数功能】 添加节日
【参数】 输入参数Name，输入参数MOWeekDay
【返回值】 Temp，新添加节日的指针
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
Festival* RegularWeekDayFestival::Add(const string& Name
									, const MOWeekDay& MOWeekDay) {
	for (auto& n : m_All) {
		if (n->Name == Name) {
			n = nullptr;
			throw invalid_argument("存在重复的节日名称");
		}
	}
	Festival* pTemp = new RegularWeekDayFestival(Name, MOWeekDay);
	m_All.push_back(pTemp);
	return pTemp;
}

/*************************************************************************
【函数名称】 ModifyMOWeekDay【函数功能】 修改MOW
【参数】 输入参数uMonth，输入参数uOrdial，输入参数uWeekDay
【返回值】 bool true 修改成功，出现问题的话Set抛异常
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool RegularWeekDayFestival::ModifyMOWeekDay(const unsigned int& uMonth
											, const unsigned int& uOrdial
											, const unsigned int& uWeekDay) {
	m_MOWeekDay.Set(uMonth, uOrdial, uWeekDay);
	return true;
}

/*************************************************************************
【函数名称】 ModifyMDDate【函数功能】 修改月日
【参数】 输入参数uMonth，输入参数uDay
【返回值】 bool false 类型不一致，不予实现
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool RegularWeekDayFestival::ModifyMDDate(const unsigned int& uMonth
										, const unsigned int& uDay) {
	return false;
}

/*************************************************************************
【函数名称】 ModifyYMDDate【函数功能】 修改年月日
【参数】 输入参数uYear，输入参数uMonth，输入参数uDay
【返回值】 bool false 类型不一致，不予实现
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool RegularWeekDayFestival::ModifyYMDDate(const unsigned int& uYear
										, const unsigned int& uMonth
										, const unsigned int& uDay) {
	return false;
}


/*************************************************************************
【函数名称】 GetYMDDate【函数功能】 获得年月日
【参数】 无
【返回值】 抛异常，类型不一致，不予实现
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
YMDDate RegularWeekDayFestival::GetYMDDate() const {
	throw invalid_argument("无法返回YMD日期。");
}

/*************************************************************************
【函数名称】 GetMDDate【函数功能】 获得月日
【参数】 无
【返回值】 抛异常，类型不一致，不予实现
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
MDDate RegularWeekDayFestival::GetMDDate() const {
	throw invalid_argument("无法返回MD日期。");
}

/*************************************************************************
【函数名称】 GetMOWeekDay【函数功能】 获得MOW
【参数】 无
【返回值】 m_MOWeekDay
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
MOWeekDay RegularWeekDayFestival::GetMOWeekDay() const {
	return m_MOWeekDay;
}

/*************************************************************************
【函数名称】 GetType【函数功能】 获得类型
【参数】 无
【返回值】 FestivalType::REGULAR_WEEKDAY
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
FestivalType RegularWeekDayFestival::GetType() const {
	return FestivalType::REGULAR_WEEKDAY;
}
