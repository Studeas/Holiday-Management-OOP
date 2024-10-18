/*************************************************************************
【文件名】 SpecialDateFestival.cpp
【功能模块和目的】 维护SpecialDateFestival类，集中编写SpecialDateFestival类成员函数的定义。
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/

#include "SpecialDateFestival.hpp"
#include <stdexcept>

/*************************************************************************
【函数名称】 SpecialDateFestival【函数功能】 构造函数
【参数】 输入参数Name，输入参数YMDDate
【返回值】 构造函数，无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
SpecialDateFestival::SpecialDateFestival(const string& Name
										, const YMDDate& YMDDate) 
										: Festival(Name)
										, m_YMDDate(YMDDate) {
}

/*************************************************************************
【函数名称】 Add【函数功能】 添加节日
【参数】 输入参数Name，输入参数YMDDate
【返回值】 Temp，新添加节日的指针
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
Festival* SpecialDateFestival::Add(const string& Name, const YMDDate& YMDDate) {
	for (auto& n : m_All) {
		if (n->Name == Name) {
			n = nullptr;
			throw invalid_argument("存在重复的节日名称");
		}
	}
	Festival* Temp = new SpecialDateFestival(Name, YMDDate);
	m_All.push_back(Temp);
	return Temp;
}

/*************************************************************************
【函数名称】 ModifyMOWeekDay【函数功能】 修改MOW
【参数】 输入参数uMonth，输入参数uOrdial，输入参数uWeekDay
【返回值】 bool false 类型不一致，不予实现
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool SpecialDateFestival::ModifyMOWeekDay(const unsigned int& uMonth
										, const unsigned int& uOrdial
										, const unsigned int& uWeekDay) {
	return false;
}

/*************************************************************************
【函数名称】 ModifyMDDate【函数功能】 修改月日
【参数】 输入参数uMonth，输入参数uDay
【返回值】 bool true 修改成功，出现问题的话Set抛异常
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool SpecialDateFestival::ModifyMDDate(const unsigned int& uMonth
									, const unsigned int& uDay) {
	YMDDate Temp(m_YMDDate.GetYear(), uMonth, uDay);//已包含日期合格性检查
	m_YMDDate = Temp;
	return true;
}

/*************************************************************************
【函数名称】 ModifyYMDDate【函数功能】 修改年月日
【参数】 输入参数uYear，输入参数uMonth，输入参数uDay
【返回值】 bool false 类型不一致，不予实现
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool SpecialDateFestival::ModifyYMDDate(const unsigned int& uYear
									, const unsigned int& uMonth
									, const unsigned int& uDay) {
	YMDDate Temp(uYear, uMonth, uDay);//已包含日期合格性检查
	m_YMDDate = Temp;
	return true;
}

/*************************************************************************
【函数名称】 GetYMDDate【函数功能】 获得年月日
【参数】 无
【返回值】 m_YMDDate
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
YMDDate SpecialDateFestival::GetYMDDate() const {
	return m_YMDDate;
}

/*************************************************************************
【函数名称】 GetMDDate【函数功能】 获得月日
【参数】 无
【返回值】 年月日的月日部分
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
MDDate SpecialDateFestival::GetMDDate() const {
	return MDDate(m_YMDDate.GetMonthValue(), m_YMDDate.GetDay());
}

/*************************************************************************
【函数名称】 GetMOWeekDay【函数功能】 获得MOW
【参数】 无
【返回值】 m_MOWeekDay
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
MOWeekDay SpecialDateFestival::GetMOWeekDay() const {
	return m_YMDDate.ToMOWeekDay();
}

/*************************************************************************
【函数名称】 GetType【函数功能】 获得类型
【参数】 无
【返回值】 FestivalType::REGULAR_WEEKDAY
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
FestivalType SpecialDateFestival::GetType() const {
	return FestivalType::SPECIAL_DATE;
}
