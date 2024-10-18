/*************************************************************************
【文件名】 MOWeekDay.hpp
【功能模块和目的】 维护MOWeekDay类，集中编写MOWeekDay类成员函数的声明。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
#ifndef MOWeekDay_hpp
#define MOWeekDay_hpp

#include "Month.hpp"
#include "WeekDay.hpp"

/*************************************************************************
【类名】 MOWeekDay
【功能】 某月第某个星期几，以这个格式进行日期管理
【接口说明】 5个getter用来获取数据，8个setter用来修改成员数据，4个IsValid判断合法性。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
class MOWeekDay {
public:
	//删除默认构造函数
	MOWeekDay() = delete;
	//其他构造函数
	MOWeekDay(const Month& Month
			, const unsigned int& uOrdial
			, const WeekDay& WeekDay);
	MOWeekDay(const unsigned int& uMonth
			, const unsigned int& uOrdial
			, const unsigned int& uActualWeekDayValue);
	MOWeekDay(const Month& Month
			, const unsigned int& uOrdial
			, const unsigned int& uActualWeekDayValue);
	MOWeekDay(const MOWeekDay& Source);
	//默认析构函数
	~MOWeekDay() = default;
	//赋值运算符
	MOWeekDay& operator=(const MOWeekDay& Source);

	//设置MOW
	void Set(const Month& Month
		   , const unsigned int& uOrdial
		   , const WeekDay& WeekDay);
	void Set(const unsigned int& uMonth
		   , const unsigned int& uOrdial
		   , const unsigned int& uActualWeekDayValue);
	void Set(const Month& Month
		   , const unsigned int& uOrdial
		   , const unsigned int& uctualWeekDayValue);
	//设置月
	void SetMonth(const unsigned int& uMonth);
	void SetMonth(const Month& Month);
	//设置第某个
	void SetOrdial(const unsigned int& uOrdial);
	//设置星期几
	void SetWeekDay(const WeekDay& WeekDay);
	void SetWeekDay(const unsigned int& uActualWeekDayValue);

	//判断日期是否合法
	static bool IsValidMOWeekDay(const Month& Month
								, const unsigned int& uOrdial
								, const WeekDay& WeekDay);
	static bool IsValidMOWeekDay(const unsigned int& uMonth
								, const unsigned int& uOrdial
								, const unsigned int& uActualWeekDayValue);
	static bool IsValidMOWeekDay(const Month& uMonth
								, const unsigned int& uOrdial
								, const unsigned int& uActualWeekDayValue);
	bool IsValidMOWeekDay() const;

	//获取月
	Month GetMonth() const;
	//获取月的值
	unsigned int GetMonthValue() const;
	//获取第某个
	unsigned int GetOrdial() const;
	//获取星期几
	WeekDay GetWeekDay() const;
	//获取星期几的值
	unsigned int GetWeekDayActualValue() const;

	 
private:
	Month m_Month;
	unsigned int m_Ordial;
	WeekDay m_WeekDay;
};


#endif // !MOWeekDay_hpp

