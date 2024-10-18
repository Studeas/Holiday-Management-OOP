/*************************************************************************
【文件名】 WeekDay.hpp
【功能模块和目的】 维护WeekDay类，集中编写WeekDay类成员函数的声明。
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/

#ifndef WeekDay_hpp
#define WeekDay_hpp

#include <string>
#include <stdexcept>
using std::string;
using std::exception;
using std::invalid_argument;

/*************************************************************************
【类名】 WeekDay
【功能】 星期管理
【接口说明】 2个getter用来获取数据，2个setter用来修改成员数据，3个toname获得名称
            字符串，若干运算符重载
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
class WeekDay {
public:
    //抛出异常类型
    class ExecptionWrongValue : public invalid_argument {
    public:
        ExecptionWrongValue();
    };
    //星期的值
    enum class ValueType : unsigned int {
        MON = 1, TUES = 2, WED = 3, THUR = 4, FRI = 5, SAT = 6, SUN = 7
    };
    //名称类型
    enum class NameType : unsigned int {
        SHORT = 0, FULL = 1
    };
    //构造函数
    WeekDay(const ValueType& Value);
    WeekDay(const unsigned int& Value);
    //删除默认构造函数
    WeekDay() = delete;
    //默认拷贝构造、析构函数和默认赋值运算符
    WeekDay(const WeekDay&) = default;
    WeekDay& operator=(const WeekDay&) = default;
    ~WeekDay() = default;
    //赋值运算符
    WeekDay& operator= (const ValueType& Value);

    //设置星期
    void Set(const ValueType& Value);
    void Set(const unsigned int& Value);

    //==运算符
    bool        operator==(const WeekDay& Source) const;
    bool        operator==(const ValueType& Source) const;
    friend bool operator==(const WeekDay::ValueType& Value
                         , const WeekDay& WeekDay);
    //!=运算符
    bool        operator!=(const WeekDay& Source) const;
    bool        operator!=(const ValueType& Source) const;
    friend bool operator!=(const WeekDay::ValueType& Value
                         , const WeekDay& WeekDay);
    //>运算符
    bool        operator> (const WeekDay& Source) const;
    bool        operator> (const ValueType& Source) const;
    friend bool operator> (const WeekDay::ValueType& Value
                         , const WeekDay& WeekDay);
    //>=运算符
    bool        operator>=(const WeekDay& Source) const;
    bool        operator>=(const ValueType& Source) const;
    friend bool operator>=(const WeekDay::ValueType& Value
                         , const WeekDay& WeekDay);
    //<运算符
    bool        operator< (const WeekDay& Source) const;
    bool        operator< (const ValueType& Source) const;
    friend bool operator< (const WeekDay::ValueType& Value
                         , const WeekDay& WeekDay);
    //<=运算符
    bool        operator<=(const WeekDay& Source) const;
    bool        operator<=(const ValueType& Source) const;
    friend bool operator<=(const WeekDay::ValueType& Value
                         , const WeekDay& WeekDay);
    //前置++运算符
    WeekDay& operator++();
    WeekDay  operator++(int);
    //后置++运算符
    WeekDay& operator--();
    WeekDay  operator--(int);

    //转换成字符串名称
    static string ToName(const WeekDay& Source
                        , const NameType& Type = NameType::SHORT);
    static string ToName(const ValueType& Source
                        , const NameType& Type = NameType::SHORT);
    string ToName(const NameType& Type = NameType::SHORT) const;

    //()运算符
    unsigned int operator()() const;

    //获得星期的值
    unsigned int GetActualValue() const;
    static unsigned int GetActualValue(const WeekDay& WeekDay);

private:
    ValueType m_Value;
    static const string m_Names[2][7];
};

#endif /* WeekDay_hpp */

