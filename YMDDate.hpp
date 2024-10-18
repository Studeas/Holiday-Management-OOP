/*************************************************************************
【文件名】 YMDDate.hpp
【功能模块和目的】 维护YMDDate类，集中编写YMDDate类成员函数的声明。
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/

#ifndef YMDDate_hpp
#define YMDDate_hpp

#include "MDDate.hpp"
#include "WeekDay.hpp"
#include "MOWeekDay.hpp"
#include <ctime>

/*************************************************************************
【类名】 YMDDate
【功能】 某年某月某日类型的日期，年月日类型
【接口说明】 1个getter用来获取数据，3个setter用来修改成员数据，IsLeapYear判断
			平闰年，IsValidYMDDate判断日期合法性，DaysPassedInThisYear今年的
			第几天，DaysPassedInTotal总共是第几天，ToWeekDay是星期几，
			ToMOWeekDay是哪个月第某个星期几，YMOWeekDayToYMDDate YMOW转换成
			年月日，Today给出今天，若干运算符重载
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
class YMDDate : public MDDate {
public:
	//带参数的构造函数
	YMDDate(const unsigned int& uYear
			, const unsigned int& uMonth
			, const unsigned int& uDay);
	YMDDate(const unsigned int& uYear
			, const Month& Month
			, const unsigned int& uDay);
	YMDDate(const unsigned int& uYear, const MDDate& MDDate);
	//默认拷贝构造函数、构造函数、析构函数
	YMDDate(const YMDDate&) = default;
	YMDDate() = default;
	~YMDDate() = default;
	//赋值运算符
	YMDDate& operator=(const YMDDate& Source);
	//==运算符
	bool operator==(const YMDDate& Source) const;
	friend bool operator==(const YMDDate& YMDDate1, const YMDDate& YMDDate2);
	//!=运算符
	bool operator!=(const YMDDate& Source) const;
	friend bool operator!=(const YMDDate& YMDDate1, const YMDDate& YMDDate2);
	//>运算符
	bool operator>(const YMDDate& Source) const;
	friend bool operator>(const YMDDate& YMDDate1, const YMDDate& YMDDate2);
	//<运算符
	bool operator<(const YMDDate& Source) const;
	friend bool operator<(const YMDDate& YMDDate1, const YMDDate& YMDDate2);
	//>=运算符
	bool operator>=(const YMDDate& Source) const;
	friend bool operator>=(const YMDDate& YMDDate1, const YMDDate& YMDDate2);
	//<=运算符
	bool operator<=(const YMDDate& Source) const;
	friend bool operator<=(const YMDDate& YMDDate1, const YMDDate& YMDDate2);
	//++运算符
	YMDDate& operator++();
	YMDDate  operator++(int);
	//--运算符
	YMDDate& operator--();
	YMDDate  operator--(int);
	//设置年月日
	void Set(const unsigned int& uYear, const MDDate& MDDate);
	void Set(const unsigned int& uYear
			, const Month& Month
			, const unsigned int& uDay);
	void Set(const unsigned int& uYear
			, const unsigned int& uMonth
			, const unsigned int& uDay);
	//设置年
	void SetYear(const unsigned int& uYear);
	//获得年
	unsigned int GetYear() const;
	//判断是否是闰年
	bool IsLeapYear() const;
	static bool IsLeapYear(const unsigned int& uYear);
	//判断日期是否合法
	bool IsValidYMDDate() const;
	static bool IsValidYMDDate(const unsigned int& uYear
							, const Month& Month
							, const unsigned int uDay);
	static bool IsValidYMDDate(const unsigned int& uYear
							, const unsigned int& uMonth
							, const unsigned int& uDay);
	//是当年的第几天
	unsigned int DaysPassedInThisYear() const;
	static unsigned int DaysPassedInThisYear(const YMDDate& YMDDate);
	//从19000101算起，是第几天
	unsigned int DaysPassedInTotal() const;//since 1900.1.1
	static unsigned int DaysPassedInTotal(const YMDDate& YMDDate);
	//转换成星期几
	WeekDay ToWeekDay() const;
	static WeekDay ToWeekDay(const YMDDate& YMDDate);
	static WeekDay ToWeekDay(const unsigned int& uYear
							, const unsigned int& uMonth
							, const unsigned int& uDay);
	static WeekDay ToWeekDay(const unsigned int& uYear
							, const Month& Month
							, const unsigned int& uDay);
	//转换成，某月第某个星期几
	MOWeekDay ToMOWeekDay() const;
	static MOWeekDay ToMOWeekDay(const YMDDate& YMDDate);
	static MOWeekDay ToMOWeekDay(const unsigned int& uYear
								, const unsigned int& uMonth
								, const unsigned int& uDay);
	static MOWeekDay ToMOWeekDay(const unsigned int& uYear
								, const Month& Month
								, const unsigned int& uDay);
	//YMOW转换成年月日
	static YMDDate YMOWeekDayToYMDDate(const unsigned int& uYear
									, const unsigned int& uMonth
									, const unsigned int& uOrdial
									, const unsigned int& uWeekDay);
	//今天
	static YMDDate Today();

private:
	unsigned int m_Year;

	static unsigned int s_MaxYear;
	static unsigned int s_MinYear;
};


#endif // !YMDDate_hpp
