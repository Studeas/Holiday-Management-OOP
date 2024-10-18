/*************************************************************************
【文件名】 MDDate.hpp
【功能模块和目的】 维护MDDate类，集中编写MDDate类成员函数的声明。
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/

#ifndef MDDate_hpp
#define MDDate_hpp

#include "Month.hpp"

/*************************************************************************
【类名】 MDDate
【功能】 月日日期，包含所有可能的日期（含2.29），不考虑平闰年。
【接口说明】 6个getter用来获取数据，5个setter用来修改成员数据，4个IsValid判断合法性。
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
class MDDate {
public:
	//删除默认构造函数
	MDDate() = delete;

	//带参数的构造函数
	MDDate(const unsigned int& uMonth, const unsigned int& uDay);
	MDDate(const Month& Month, const unsigned int& uDay);

	//默认拷贝构造函数和默认析构函数
	MDDate(const MDDate& MDDate) = default;
	~MDDate() = default;

	//赋值运算符
	MDDate& operator=(const MDDate& MDDate);

	//设置月、日日期
	void Set(const unsigned int& uMonth, const unsigned int& uDay);
	void Set(const Month& Month, const unsigned int& uDay);
	void SetMonth(const unsigned int& uMonth);
	void SetMonth(const Month& Month);
	void SetDay(const unsigned int& uDay);

	//判断月日日期是否合法
	static bool IsValidMDDate(const unsigned int& uMonth
							, const unsigned int& uDay);
	static bool IsValidMDDate(const Month::ValueType& Month
							, const unsigned int& uDay);
	static bool IsValidMDDate(const Month& Month
							, const unsigned int& uDay);
	bool IsValidMDDate() const;

	//==运算符
	bool operator==(const MDDate& Source) const;
	friend bool operator==(const MDDate& MDDate1, const MDDate& MDDate2);
	//!=运算符
	bool operator!=(const MDDate& Source) const;
	friend bool operator!=(const MDDate& MDDate1, const MDDate& MDDate2);
	//>运算符
	bool operator>(const MDDate& Source) const;
	friend bool operator>(const MDDate& MDDate1, const MDDate& MDDate2);
	//<运算符
	bool operator<(const MDDate& Source) const;
	friend bool operator<(const MDDate& MDDate1, const MDDate& MDDate2);
	//>=运算符
	bool operator>=(const MDDate& Source) const;
	friend bool operator>=(const MDDate& MDDate1, const MDDate& MDDate2);
	//<=运算符
	bool operator<=(const MDDate& Source) const;
	friend bool operator<=(const MDDate& MDDate1, const MDDate& MDDate2);
	//++运算符
	MDDate& operator++();
	MDDate  operator++(int);
	//--运算符
	MDDate& operator--();
	MDDate  operator--(int);

	//获得月
	string GetMonth(const Month::NameType& Type = Month::NameType::SHORT) const;
	//获得月的数值
	unsigned int GetMonthValue() const;
	//获得日
	unsigned int GetDay() const;
	//获得月的最大日（此处不考虑平闰，2月为29日）
	static unsigned int GetDaysOfMonthMax(const Month& Month);
	static unsigned int GetDaysOfMonthMax(const unsigned int& uMonth);
	unsigned int GetDaysOfMonthMax() const;
	
	//常引用
	const Month& TheMonth;
	const unsigned int& Day;

private:
	Month m_Month;
	unsigned int m_Day;
	static unsigned int MinDay;
	static unsigned int MaxDay;

protected:	
	static const unsigned int DaysOfMonthMax[13];

};


#endif // !MDDate_hpp

