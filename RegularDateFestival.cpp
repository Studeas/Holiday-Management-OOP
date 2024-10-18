/*************************************************************************
【文件名】 RegularDateFestival.cpp
【功能模块和目的】 维护RegularDateFestival类，集中编写RegularDateFestival类成员函数的定义。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
#include "RegularDateFestival.hpp"
#include <stdexcept>

/*************************************************************************
【函数名称】 RegularDateFestival【函数功能】 构造函数
【参数】 输入参数Name，输入参数MDDate
【返回值】 构造函数，无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
RegularDateFestival::RegularDateFestival(const string& Name, const MDDate& MDDate)
	: Festival(Name), m_MDDate(MDDate) {
}

/*************************************************************************
【函数名称】 Add【函数功能】 添加节日
【参数】 输入参数Name，输入参数MDDate
【返回值】 Temp，新添加节日的指针
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
Festival* RegularDateFestival::Add(const string& Name, const MDDate& MDDate) {
	for (auto& n : m_All) {
		if (n->Name == Name) {
			n = nullptr;
			throw invalid_argument("存在重复的节日名称");
		}
	}
	Festival* Temp = new RegularDateFestival(Name, MDDate);
	m_All.push_back(Temp);
	return Temp;
}

/*************************************************************************
【函数名称】 ModifyMOWeekDay【函数功能】 修改MOW
【参数】 输入参数uMonth，输入参数uOrdial，输入参数uWeekDay
【返回值】 false，不予实现这种操作，日期类型不一致
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool RegularDateFestival::ModifyMOWeekDay(const unsigned int& uMonth
										, const unsigned int& uOrdial
										, const unsigned int& uWeekDay) {
	return false;
}

/*************************************************************************
【函数名称】 ModifyMOWeekDay【函数功能】 修改月日
【参数】 输入参数uMonth，输入参数uDay
【返回值】 bool true，操作成功
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool RegularDateFestival::ModifyMDDate(const unsigned int& uMonth
										, const unsigned int& uDay) {
	MDDate Temp(uMonth, uDay);//已包含日期合格性检查
	m_MDDate = Temp;
	return true;
}

/*************************************************************************
【函数名称】 ModifyMOWeekDay【函数功能】 修改年月日
【参数】 输入参数uYear，输入参数uMonth，输入参数uDay
【返回值】 false，不予实现这种操作，日期类型不一致
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool RegularDateFestival::ModifyYMDDate(const unsigned int& uYear
										, const unsigned int& uMonth
										, const unsigned int& uDay) {
	return false;
}

/*************************************************************************
【函数名称】 GetYMDDate【函数功能】 获得年月日
【参数】 无
【返回值】 抛出异常，不予实现这种操作，日期类型不一致
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
YMDDate RegularDateFestival::GetYMDDate() const {
	throw invalid_argument("无法返回YMD日期。");
}

/*************************************************************************
【函数名称】 GetMDDate【函数功能】 获得月日
【参数】 无
【返回值】 m_MDDate
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
MDDate RegularDateFestival::GetMDDate() const {
	return m_MDDate;
}

/*************************************************************************
【函数名称】 GetMOWeekDay【函数功能】 获得MOW
【参数】 无
【返回值】 抛出异常，不予实现这种操作，日期类型不一致
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
MOWeekDay RegularDateFestival::GetMOWeekDay() const {
	throw invalid_argument("无法返回MOW日期。");
}

/*************************************************************************
【函数名称】 GetType【函数功能】 获得节日类型
【参数】 无
【返回值】 FestivalType::REGULAR_DATE
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
FestivalType RegularDateFestival::GetType() const {
	return FestivalType::REGULAR_DATE;
}
