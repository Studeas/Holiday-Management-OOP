/*************************************************************************
【文件名】 Month.hpp
【功能模块和目的】 维护Month类，集中编写Month类成员函数的声明。
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/

#ifndef Month_hpp
#define Month_hpp

#include <string>
#include <stdexcept>
using std::string;
using std::exception;
using std::invalid_argument;

/*************************************************************************
【类名】 Month
【功能】 月份管理，包含值、长短名称。
【接口说明】 6个getter用来获取数据，5个setter用来修改成员数据，4个IsValid判断合法性。
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
class Month {
public:
    //抛出月份异常类
    class ExecptionWrongValue : public invalid_argument {
    public:
        ExecptionWrongValue();
    };
    //月份值类型
    enum class ValueType : unsigned int {
        JAN = 1, FEB = 2, MAR = 3, APR = 4, MAY = 5, JUN = 6
        , JUL = 7, AUG = 8, SEP = 9, OCT = 10, NOV = 11, DEC = 12
    };
    //月份名称类型
    enum class NameType : unsigned int {
        SHORT = 0, FULL = 1
    };
    //带参数的构造函数
    Month(const ValueType& Value);
    Month(const unsigned int& uValue);
    //默认构造函数
    Month() = default;
    //拷贝构造函数
    Month(const Month&) = default;
    //默认赋值运算符
    Month& operator=(const Month&) = default;
    //析构函数
    ~Month() = default;

    //赋值运算符
    Month& operator= (const ValueType& Value);
    Month& operator= (const unsigned int& uValue);

    //设置月份
    void Set(const ValueType& Value);
    void Set(const unsigned int& Value);
    //获得月份的值
    unsigned int GetValue() const;

    //==运算符
    bool        operator==(const Month& Source) const;
    bool        operator==(const ValueType& Source) const;
    friend bool operator==(const Month::ValueType& Value, const Month& Month);
    //!=运算符
    bool        operator!=(const Month& Source) const;
    bool        operator!=(const ValueType& Source) const;
    friend bool operator!=(const Month::ValueType& Value, const Month& Month);
    //>运算符
    bool        operator> (const Month& Source) const;
    bool        operator> (const ValueType& Source) const;
    friend bool operator> (const Month::ValueType& Value, const Month& Month);
    //>=运算符
    bool        operator>=(const Month& Source) const;
    bool        operator>=(const ValueType& Source) const;
    friend bool operator>=(const Month::ValueType& Value, const Month& Month);
    //<运算符
    bool        operator< (const Month& Source) const;
    bool        operator< (const ValueType& Source) const;
    friend bool operator< (const Month::ValueType& Value, const Month& Month);
    //<=运算符
    bool        operator<=(const Month& Source) const;
    bool        operator<=(const ValueType& Source) const;
    friend bool operator<=(const Month::ValueType& Value, const Month& Month);
    //++运算符
    Month& operator++();
    Month  operator++(int);
    //--运算符
    Month& operator--();
    Month  operator--(int);

    //转换成字符串
    static string ToName(const Month& Source
        , const NameType& Type = NameType::SHORT);
    //转换成字符串
    static string ToName(const ValueType& Source
        , const NameType& Type = NameType::SHORT);
    //转换成字符串
    string ToName(const NameType& Type = NameType::SHORT) const;
    unsigned int operator()() const;

    //得到月份最大日
    unsigned int GetMaxDaysOfMonths() const;
    static unsigned int GetMaxDaysOfMonths(const unsigned int& Month);
    static unsigned int GetMaxDaysOfMonths(const Month& Month);

private:
    ValueType m_Value;
    static const string m_Names[2][12];
    static const unsigned int MaxDaysOfMonths[13];
};

#endif /* WeekDay_hpp */


