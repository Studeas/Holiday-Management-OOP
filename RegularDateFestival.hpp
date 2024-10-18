/*************************************************************************
【文件名】 RegularDateFestival.hpp
【功能模块和目的】 维护RegularDateFestival类，集中编写RegularDateFestival
				类成员函数的声明。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/

#ifndef RegularDateFestival_hpp
#define RegularDateFestival_hpp
#include "Festival.hpp"
#include "MDDate.hpp"
#include "MOWeekDay.hpp" 

/*************************************************************************
【类名】 RegularDateFestival
【功能】 某月某日的日期形式，每年一次
【接口说明】 4个getter用来获取数据，3个Modify用来修改成员数据。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
class RegularDateFestival : public Festival {
public:
	//静态，添加节日函数
	static Festival* Add(const string& Name, const MDDate& MDDate);
	//删除默认构造函数、拷贝构造函数、赋值运算符等
	RegularDateFestival() = delete;
	RegularDateFestival(const RegularDateFestival&) = delete;
	RegularDateFestival(const char*, const MDDate&) = delete;
	RegularDateFestival& operator=(const RegularDateFestival& Source) = delete;

	//修改MOW，纯虚函数的实现，此处不予实现
	bool ModifyMOWeekDay(const unsigned int& Month, const unsigned int& Ordial
						, const unsigned int& WeekDay);
	//修改年月日，纯虚函数的实现，只实现这一种函数
	bool ModifyMDDate(const unsigned int& Month, const unsigned int& Day);
	//修改月日，纯虚函数的实现，此处不予实现
	bool ModifyYMDDate(const unsigned int& Year, const unsigned int& Month
					, const unsigned int& Day);

	//获得年月日，纯虚函数的实现，此处不予实现
	YMDDate GetYMDDate() const;
	//获得月日，纯虚函数的实现，实现这一种函数
	MDDate GetMDDate() const;
	//获得MOW，纯虚函数的实现，此处不予实现
	MOWeekDay GetMOWeekDay() const;
	//获得节日种类，纯虚函数的实现，实现这一种函数
	FestivalType GetType() const;

protected:

private:
	//带参数的构造函数
	RegularDateFestival(const string& Name, const MDDate& MDDate);
	MDDate m_MDDate;
};


#endif
