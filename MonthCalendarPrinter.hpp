/*************************************************************************
【文件名】 MonthCalendarPrinter.hpp
【功能模块和目的】 维护MonthCalendarPrinter类，集中编写MonthCalendarPrinter
				  类成员函数的声明。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
#ifndef MonthCalendarPrinter_hpp
#define MonthCalendarPrinter_hpp

#include "Month.hpp"
#include "MDDate.hpp"
#include "YMDDate.hpp"
#include "WeekDay.hpp"
#include "SpecialDateFestival.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

/*************************************************************************
【类名】 MonthCalendarPrinter
【功能】 负责打印月历和当月节日的功能
【接口说明】 1个PrintCalendar打印月历，1个PrintFestivals打印节日list
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
class MonthCalendarPrinter {
public:
	//删除默认构造函数、拷贝构造函数
	MonthCalendarPrinter() = delete;
	MonthCalendarPrinter(const MonthCalendarPrinter&) = delete;

	//带参数的构造函数
	MonthCalendarPrinter(const unsigned int& uYear
						, const unsigned int& uMonth);
	//默认析构函数
	~MonthCalendarPrinter() = default;

	//排序当日节日
	static bool CmpByDate(Festival::FestivalInThisYear* a
						, Festival::FestivalInThisYear* b);
	//打印月历
	void PrintCalendar(const unsigned int& uYear
					, const unsigned int& uMonth) const;

	//打印当月节日
	void PrintFestivals(const unsigned int& uYear
					, const unsigned int& uMonth) const;
private:
	unsigned int m_Year;
	unsigned int m_Month;

};

#endif // !MonthCalendarPrinter_hpp

