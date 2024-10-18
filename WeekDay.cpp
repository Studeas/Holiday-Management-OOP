/*************************************************************************
【文件名】 WeekDay.cpp
【功能模块和目的】 维护WeekDay类，集中编写WeekDay成员函数的定义。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/

#include "WeekDay.hpp"
#include <string>
using std::string;

const string WeekDay::m_Names[2][7]{
    "SUN", "MON", "TUES", "WED", "THUR", "FRI", "SAT" ,
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

/*************************************************************************
【函数名称】 ExecptionWrongValue【函数功能】 抛出星期异常
【参数】 无
【返回值】 无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
WeekDay::ExecptionWrongValue::ExecptionWrongValue() 
    : invalid_argument("星期错误,应为1~7(MON to SUN)。") {
}

/*************************************************************************
【函数名称】 WeekDay【函数功能】 构造函数
【参数】 输入参数Value
【返回值】 构造函数，无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
WeekDay::WeekDay(const ValueType& Value) {
    Set(Value);
}


/*************************************************************************
【函数名称】 WeekDay【函数功能】 构造函数
【参数】 输入参数Value
【返回值】 构造函数，无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
WeekDay::WeekDay(const unsigned int& Value) {
    Set(Value);
}

/*************************************************************************
【函数名称】 operator=【函数功能】 赋值运算符
【参数】 输入参数Value
【返回值】 *this
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
WeekDay& WeekDay::operator= (const ValueType& Value) {
    Set(Value);
    return *this;
}

/*************************************************************************
【函数名称】 Set【函数功能】 设置星期
【参数】 输入参数Value
【返回值】 无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
void WeekDay::Set(const ValueType& Value) {
    this->m_Value = Value;
}

/*************************************************************************
【函数名称】 Set【函数功能】 设置月份
【参数】 输入参数uValue
【返回值】 无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
void WeekDay::Set(const unsigned int& uValue) {
    switch (uValue) {
    case 1: m_Value = ValueType::MON;  break;
    case 2: m_Value = ValueType::TUES; break;
    case 3: m_Value = ValueType::WED;  break;
    case 4: m_Value = ValueType::THUR; break;
    case 5: m_Value = ValueType::FRI;  break;
    case 6: m_Value = ValueType::SAT;  break;
    case 7: m_Value = ValueType::SUN;  break;
    default: throw ExecptionWrongValue();
    }
}

/*************************************************************************
【函数名称】 operator==【函数功能】 ==运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool WeekDay::operator==(const WeekDay& Source) const {
    return m_Value == Source.m_Value;
}

/*************************************************************************
【函数名称】 operator==【函数功能】 ==运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool WeekDay::operator==(const ValueType& Source) const {
    return  m_Value == Source;
}

/*************************************************************************
【函数名称】 operator==【函数功能】 ==运算符，友元
【参数】 输入参数Value，输入参数Month
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator==(const WeekDay::ValueType& Value, const WeekDay& WeekDay) {
    return Value == WeekDay.m_Value;
}

/*************************************************************************
【函数名称】 operator!=【函数功能】 !=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool WeekDay::operator!=(const WeekDay& Source) const {
    return m_Value != Source.m_Value;
}

/*************************************************************************
【函数名称】 operator!=【函数功能】 !=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool WeekDay::operator!=(const ValueType& Source) const {
    return  m_Value != Source;
}

/*************************************************************************
【函数名称】 operator!=【函数功能】 !=运算符，友元
【参数】 输入参数Value，输入参数Month
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator!=(const WeekDay::ValueType& Value, const WeekDay& WeekDay) {
    return Value != WeekDay.m_Value;
}

/*************************************************************************
【函数名称】 operator>【函数功能】 >运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool WeekDay::operator> (const WeekDay& Source) const {
    return  m_Value > Source.m_Value;
}

/*************************************************************************
【函数名称】 operator>【函数功能】 >运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool WeekDay::operator> (const ValueType& Source) const {
    return  m_Value > Source;
}

/*************************************************************************
【函数名称】 operator>【函数功能】 >运算符，友元
【参数】 输入参数Value，输入参数Month
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator> (const WeekDay::ValueType& Value, const WeekDay& WeekDay) {
    return Value > WeekDay.m_Value;
}

/*************************************************************************
【函数名称】 operator>=【函数功能】 >=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool WeekDay::operator>=(const WeekDay& Source) const {
    return m_Value >= Source.m_Value;
}

/*************************************************************************
【函数名称】 operator>=【函数功能】 >=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool WeekDay::operator>=(const ValueType& Source) const {
    return m_Value >= Source;
}

/*************************************************************************
【函数名称】 operator>=【函数功能】 >=运算符，友元
【参数】 输入参数Value，输入参数Month
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator>=(const WeekDay::ValueType& Value, const WeekDay& WeekDay) {
    return Value >= WeekDay.m_Value;
}

/*************************************************************************
【函数名称】 operator<【函数功能】 <运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool WeekDay::operator< (const WeekDay& Source) const {
    return m_Value < Source.m_Value;
}

/*************************************************************************
【函数名称】 operator<【函数功能】 <运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool WeekDay::operator< (const ValueType& Source) const {
    return m_Value < Source;
}

/*************************************************************************
【函数名称】 operator<【函数功能】 <运算符，友元
【参数】 输入参数Value，输入参数Month
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator< (const WeekDay::ValueType& Value, const WeekDay& WeekDay) {
    return Value < WeekDay.m_Value;
}

/*************************************************************************
【函数名称】 operator<=【函数功能】 <=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool WeekDay::operator<=(const WeekDay& Source) const {
    return m_Value <= Source.m_Value;
}

/*************************************************************************
【函数名称】 operator<=【函数功能】 <=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool WeekDay::operator<=(const ValueType& Source) const {
    return m_Value <= Source;
}

/*************************************************************************
【函数名称】 operator<=【函数功能】 <=运算符，友元
【参数】 输入参数Value，输入参数Month
【返回值】 bool，符合条件返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator<=(const WeekDay::ValueType& Value, const WeekDay& WeekDay) {
    return Value <= WeekDay.m_Value;
}

/*************************************************************************
【函数名称】 operator++【函数功能】 前置++运算符
【参数】 无
【返回值】 *this
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
WeekDay& WeekDay::operator++() {
    switch (m_Value) {
    case ValueType::MON: m_Value = ValueType::TUES; break;
    case ValueType::TUES: m_Value = ValueType::WED; break;
    case ValueType::WED: m_Value = ValueType::THUR; break;
    case ValueType::THUR: m_Value = ValueType::FRI; break;
    case ValueType::FRI: m_Value = ValueType::SAT; break;
    case ValueType::SAT: m_Value = ValueType::SUN; break;
    case ValueType::SUN: m_Value = ValueType::MON; break;
    default: throw ExecptionWrongValue();
    }
    return *this;
}

/*************************************************************************
【函数名称】 operator++【函数功能】 后置++运算符
【参数】 无
【返回值】 Temp
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
WeekDay WeekDay::operator++(int) {
    //call prefix operator++
    WeekDay Res{ *this };
    ++(*this);
    return Res;
}

/*************************************************************************
【函数名称】 operator--【函数功能】 前置--运算符
【参数】 无
【返回值】 *this
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
WeekDay& WeekDay::operator--() {
    switch (m_Value) {
    case ValueType::TUES: m_Value = ValueType::MON; break;
    case ValueType::WED: m_Value = ValueType::TUES; break;
    case ValueType::THUR: m_Value = ValueType::WED; break;
    case ValueType::FRI: m_Value = ValueType::THUR; break;
    case ValueType::SAT: m_Value = ValueType::FRI; break;
    case ValueType::SUN: m_Value = ValueType::SAT; break;
    case ValueType::MON: m_Value = ValueType::SUN; break;
    default: throw ExecptionWrongValue();
    }
    return *this;
}

/*************************************************************************
【函数名称】 operator--【函数功能】 后置--运算符
【参数】 无
【返回值】 Temp
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
WeekDay WeekDay::operator--(int) {
    //call prefix operator--
    WeekDay Res{ *this };
    --(*this);
    return Res;
}

/*************************************************************************
【函数名称】 ToName【函数功能】 转换为字符串
【参数】 输入参数Source，输入参数Type
【返回值】 星期名称
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
string WeekDay::ToName(const WeekDay& Source, const NameType& Type) {
    return m_Names[static_cast<unsigned int>(Type)][static_cast<unsigned int>(Source.m_Value) % 7];
}

/*************************************************************************
【函数名称】 ToName【函数功能】 转换为字符串
【参数】 输入参数Source，输入参数Type
【返回值】 星期名称
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
string WeekDay::ToName(const ValueType& Source, const NameType& Type) {
    return m_Names[static_cast<unsigned int>(Type)][static_cast<unsigned int>(Source) % 7];
}

/*************************************************************************
【函数名称】 ToName【函数功能】 转换为字符串
【参数】 输入参数Type
【返回值】 星期名称
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
string WeekDay::ToName(const NameType& Type) const {
    return ToName(m_Value, Type);
}

/*************************************************************************
【函数名称】 operator()【函数功能】 （）运算符
【参数】 无
【返回值】 得到星期对象的值
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
unsigned int WeekDay::operator()() const {
    return static_cast<unsigned int>(m_Value);
}

/*************************************************************************
【函数名称】 GetActualValue【函数功能】 得到星期的值
【参数】 无
【返回值】 ActualValue
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
unsigned int WeekDay::GetActualValue() const {
    unsigned int ActualValue = static_cast<unsigned int>(m_Value);
    return (ActualValue == 0) ? 7 : ActualValue;
}

/*************************************************************************
【函数名称】 GetActualValue【函数功能】 得到星期的值
【参数】 输入参数WeekDay
【返回值】 ActualValue
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
unsigned int WeekDay::GetActualValue(const WeekDay& WeekDay) {
    unsigned int ActualValue = static_cast<unsigned int>(WeekDay.m_Value);
    return (ActualValue == 0) ? 7 : ActualValue;
}

