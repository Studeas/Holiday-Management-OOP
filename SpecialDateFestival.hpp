/*************************************************************************
【文件名】 SpecialDateFestival.hpp
【功能模块和目的】 维护SpecialDateFestival类，集中编写SpecialDateFestival类成员函数的声明。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
#ifndef SpecialDateFestival_hpp
#define SpecialDateFestival_hpp

#include "Festival.hpp"
#include "YMDDate.hpp"

/*************************************************************************
【类名】 SpecialDateFestival
【功能】 某年某月某日的日期形式，是唯一的日期
【接口说明】 4个getter用来获取数据，3个Modify用来修改成员数据。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
class SpecialDateFestival : public Festival {
public:
	//添加节日
	static Festival* Add(const string& Name, const YMDDate& YMDDate);
	//删除默认构造函数、拷贝构造函数、赋值运算符等
	SpecialDateFestival() = delete;
	SpecialDateFestival(const SpecialDateFestival&) = delete;
	SpecialDateFestival(const char*, const MDDate&) = delete;
	SpecialDateFestival& operator=(const SpecialDateFestival& Source) = delete;

	//修改MOW，纯虚函数的实现，此处不予实现
	bool ModifyMOWeekDay(const unsigned int& uMonth, const unsigned int& uOrdial
						, const unsigned int& uWeekDay);
	//修改月日，纯虚函数的实现，可以实现
	bool ModifyMDDate(const unsigned int& uMonth, const unsigned int& uDay);
	//修改年月日，纯虚函数的实现，可以实现
	bool ModifyYMDDate(const unsigned int& uYear, const unsigned int& uMonth
						, const unsigned int& uDay);

	//获得年月日，纯虚函数的实现，实现这个函数
	YMDDate GetYMDDate() const;
	//获得月日，纯虚函数的实现，实现这个函数
	MDDate GetMDDate() const;
	//获得MOW，纯虚函数的实现，实现这个函数
	MOWeekDay GetMOWeekDay() const;
	//获得种类，纯虚函数的实现，实现这个函数
	FestivalType GetType() const;

private:
	//带参数的构造函数
	SpecialDateFestival(const string& Name, const YMDDate& YMDDate);
	YMDDate m_YMDDate;
};




#endif // !SpecialDateFestival_hpp

