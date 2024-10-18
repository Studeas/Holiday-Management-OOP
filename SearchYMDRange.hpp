/*************************************************************************
【文件名】 SearchYMDRange.hpp
【功能模块和目的】 维护SearchYMDRange类，集中编写SearchYMDRange类成员函数的声明。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/

#ifndef SearchYMDRange_hpp
#define SearchYMDRange_hpp

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
【类名】 SortType
【功能】 枚举类，管理排序类型名
【接口说明】 无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
enum class SortType {
	BY_NAME, BY_DATE
};

/*************************************************************************
【类名】 SearchYMDRange
【功能】 实现年月日范围内的节日查找和排序打印
【接口说明】 PrintFestivals可被调用，用来实现功能
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
class SearchYMDRange {
public:
	//删除默认构造函数，拷贝构造函数
	SearchYMDRange() = delete;
	SearchYMDRange(const SearchYMDRange&) = delete;

	//带参数的构造函数
	SearchYMDRange(const YMDDate& YMDDate1
				, const YMDDate& YMDDate2
				, const SortType& SortType);
	//默认析构函数
	~SearchYMDRange() = default;

	//实现查找、排序和打印的主要功能函数
	vector<Festival::FestivalInThisYear*> PrintFestivals() const;

private:
	YMDDate m_YMDDate1;
	YMDDate m_YMDDate2;
	SortType m_SortType;
};



#endif // !SearchYMDRange_hpp

