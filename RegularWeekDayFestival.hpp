/*************************************************************************
【文件名】 RegularWeekDayFestival.hpp
【功能模块和目的】 维护RegularWeekDayFestival类，集中编写RegularWeekDayFestival
				类成员函数的声明。
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/

#ifndef RegularWeekDayFestival_hpp
#define RegularWeekDayFestival_hpp

#include "Festival.hpp"
#include "WeekDay.hpp"
#include "MOWeekDay.hpp"

/*************************************************************************
【类名】 RegularWeekDayFestival
【功能】 某月第某个星期几的日期形式，每年一次
【接口说明】 4个getter用来获取数据，3个Modify用来修改成员数据。
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
class RegularWeekDayFestival : public Festival {
public:
	//添加节日
	static Festival* Add(const string& Name, const MOWeekDay& MOWeekDay);

	//删除默认构造函数、拷贝构造函数、赋值运算符等
	RegularWeekDayFestival() = delete;
	RegularWeekDayFestival(const RegularWeekDayFestival&) = delete;
	RegularWeekDayFestival(const char*, const MDDate&) = delete;
	RegularWeekDayFestival& operator=(const RegularWeekDayFestival& Source)
		= delete;

	//修改MOW，纯虚函数的实现，实现这个函数
	bool ModifyMOWeekDay(const unsigned int& uMonth
						, const unsigned int& uOrdial
						, const unsigned int& uWeekDay);
	//修改月日，纯虚函数的实现，此处不予实现
	bool ModifyMDDate(const unsigned int& uMonth, const unsigned int& uDay);
	//修改年月日，纯虚函数的实现，此处不予实现
	bool ModifyYMDDate(const unsigned int& uYear
					, const unsigned int& uMonth
					, const unsigned int& uDay);

	//获得年月日，纯虚函数的实现，此处不予实现
	YMDDate GetYMDDate() const;
	//获得月日，纯虚函数的实现，此处不予实现
	MDDate GetMDDate() const;
	//获得MOW，纯虚函数的实现，实现这一种函数
	MOWeekDay GetMOWeekDay() const;
	//获得节日种类，纯虚函数的实现，实现这一种函数
	FestivalType GetType() const;

private:
	//带参数的构造函数
	RegularWeekDayFestival(const string& Name, const MOWeekDay& MOWeekDay);
	RegularWeekDayFestival(const string& Name
						, const Month& Month
						, const unsigned int& Ordial
						, const WeekDay& WeekDay);
	MOWeekDay m_MOWeekDay;
};




#endif // !RegularWeekDayFestival_hpp
