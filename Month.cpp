/*************************************************************************
【文件名】 Month.cpp
【功能模块和目的】 维护Month类，集中编写Month类成员函数的定义。
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/

#include "Month.hpp"
#include <string>
using std::string;

const string Month::m_Names[2][12]{
    "JAN", "FEB", "MAR", "APR", "MAY", "JUN"
    , "JUL" , "AUG", "SEP", "OCT", "NOV", "DEC",
    "January", "February", "Mar", "April", "May", "June"
    , "July", "August", "September", "October", "November", "December"
};

const unsigned int Month::MaxDaysOfMonths[13] = {
    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

/*************************************************************************
【函数名称】 ExecptionWrongValue【函数功能】 抛出月份异常
【参数】 无
【返回值】 无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
Month::ExecptionWrongValue::ExecptionWrongValue() 
    : invalid_argument("月份错误，应为 1~12(JAN to DEC)。") {
}

/*************************************************************************
【函数名称】 Month【函数功能】 构造函数
【参数】 输入参数Value
【返回值】 构造函数，无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
Month::Month(const ValueType& Value) {
    Set(Value);
}

/*************************************************************************
【函数名称】 Month【函数功能】 构造函数
【参数】 输入参数Value
【返回值】 构造函数，无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
Month::Month(const unsigned int& uValue) {
    Set(uValue);
}

/*************************************************************************
【函数名称】 operator=【函数功能】 赋值运算符
【参数】 输入参数Value
【返回值】 *this
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
Month& Month::operator= (const ValueType& Value) {
    Set(Value);
    return *this;
}

/*************************************************************************
【函数名称】 operator=【函数功能】 赋值运算符
【参数】 输入参数Value
【返回值】 *this
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
Month& Month::operator= (const unsigned int& uValue) {
    Set(uValue);
    return *this;
}

/*************************************************************************
【函数名称】 Set【函数功能】 设置月份
【参数】 输入参数Value
【返回值】 无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
void Month::Set(const ValueType& Value) {
    this->m_Value = Value;
}

/*************************************************************************
【函数名称】 Set【函数功能】 设置月份
【参数】 输入参数uValue
【返回值】 无
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
void Month::Set(const unsigned int& uValue) {
    switch (uValue) {
    case 1 : m_Value = ValueType::JAN;  break;
    case 2 : m_Value = ValueType::FEB;  break;
    case 3 : m_Value = ValueType::MAR;  break;
    case 4 : m_Value = ValueType::APR;  break;
    case 5 : m_Value = ValueType::MAY;  break;
    case 6 : m_Value = ValueType::JUN;  break;
    case 7 : m_Value = ValueType::JUL;  break;
    case 8 : m_Value = ValueType::AUG;  break;
    case 9 : m_Value = ValueType::SEP;  break;
    case 10: m_Value = ValueType::OCT;  break;
    case 11: m_Value = ValueType::NOV;  break;
    case 12: m_Value = ValueType::DEC;  break;

    default: throw ExecptionWrongValue();
    }
}

/*************************************************************************
【函数名称】 GetValue【函数功能】 获得月份值
【参数】 无
【返回值】 static_cast<unsigned int>(m_Value)月份值
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
unsigned int Month::GetValue() const {
    return static_cast<unsigned int>(m_Value);
}

/*************************************************************************
【函数名称】 operator==【函数功能】 ==运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool Month::operator==(const Month& Source) const {
    return m_Value == Source.m_Value;
}

/*************************************************************************
【函数名称】 operator==【函数功能】 ==运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool Month::operator==(const ValueType& Source) const {
    return  m_Value == Source;
}

/*************************************************************************
【函数名称】 operator==【函数功能】 ==运算符，友元
【参数】 输入参数Value，输入参数Month
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator==(const Month::ValueType& Value, const Month& Month) {
    return Value == Month.m_Value;
}

/*************************************************************************
【函数名称】 operator!=【函数功能】 !=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool Month::operator!=(const Month& Source) const {
    return m_Value != Source.m_Value;
}

/*************************************************************************
【函数名称】 operator!=【函数功能】 !=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool Month::operator!=(const ValueType& Source) const {
    return  m_Value != Source;
}

/*************************************************************************
【函数名称】 operator!=【函数功能】 !=运算符，友元
【参数】 输入参数Value，输入参数Month
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator!=(const Month::ValueType& Value, const Month& Month) {
    return Value != Month.m_Value;
}

/*************************************************************************
【函数名称】 operator>【函数功能】 >运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool Month::operator> (const Month& Source) const {
    return  m_Value > Source.m_Value;
}

/*************************************************************************
【函数名称】 operator>【函数功能】 >运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool Month::operator> (const ValueType& Source) const {
    return  m_Value > Source;
}

/*************************************************************************
【函数名称】 operator>【函数功能】 >运算符，友元
【参数】 输入参数Value，输入参数Month
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator> (const Month::ValueType& Value, const Month& Month) {
    return Value > Month.m_Value;
}

/*************************************************************************
【函数名称】 operator>=【函数功能】 >=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool Month::operator>=(const Month& Source) const {
    return m_Value >= Source.m_Value;
}

/*************************************************************************
【函数名称】 operator>=【函数功能】 >=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool Month::operator>=(const ValueType& Source) const {
    return m_Value >= Source;
}

/*************************************************************************
【函数名称】 operator>=【函数功能】 >=运算符，友元
【参数】 输入参数Value，输入参数Month
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator>=(const Month::ValueType& Value, const Month& Month) {
    return Value >= Month.m_Value;
}

/*************************************************************************
【函数名称】 operator<【函数功能】 <运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool Month::operator< (const Month& Source) const {
    return m_Value < Source.m_Value;
}

/*************************************************************************
【函数名称】 operator<【函数功能】 <运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool Month::operator< (const ValueType& Source) const {
    return m_Value < Source;
}

/*************************************************************************
【函数名称】 operator<【函数功能】 <运算符，友元
【参数】 输入参数Value，输入参数Month
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator< (const Month::ValueType& Value, const Month& Month) {
    return Value < Month.m_Value;
}

/*************************************************************************
【函数名称】 operator<=【函数功能】 <=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool Month::operator<=(const Month& Source) const {
    return m_Value <= Source.m_Value;
}

/*************************************************************************
【函数名称】 operator<=【函数功能】 <=运算符
【参数】 输入参数Source
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool Month::operator<=(const ValueType& Source) const {
    return m_Value <= Source;
}

/*************************************************************************
【函数名称】 operator<=【函数功能】 <=运算符，友元
【参数】 输入参数Value，输入参数Month
【返回值】 bool，符合条件返回true
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
bool operator<=(const Month::ValueType& Value, const Month& Month) {
    return Value <= Month.m_Value;
}

/*************************************************************************
【函数名称】 operator++【函数功能】 前置++运算符
【参数】 无
【返回值】 *this
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
Month& Month::operator++() {
    switch (m_Value) {
    case ValueType::JAN: m_Value = ValueType::FEB; break;
    case ValueType::FEB: m_Value = ValueType::MAR; break;
    case ValueType::MAR: m_Value = ValueType::APR; break;
    case ValueType::APR: m_Value = ValueType::MAY; break;
    case ValueType::MAY: m_Value = ValueType::JUN; break;
    case ValueType::JUN: m_Value = ValueType::JUL; break;
    case ValueType::JUL: m_Value = ValueType::AUG; break;
    case ValueType::AUG: m_Value = ValueType::SEP; break;
    case ValueType::SEP: m_Value = ValueType::OCT; break;
    case ValueType::OCT: m_Value = ValueType::NOV; break;
    case ValueType::NOV: m_Value = ValueType::DEC; break;
    case ValueType::DEC: m_Value = ValueType::JAN; break;
    default: throw ExecptionWrongValue();
    }
    return *this;
}

/*************************************************************************
【函数名称】 operator++【函数功能】 后置++运算符
【参数】 无
【返回值】 Temp
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
Month Month::operator++(int) {
    //call prefix operator++
    Month Temp{ *this };
    ++(*this);
    return Temp;
}

/*************************************************************************
【函数名称】 operator--【函数功能】 前置--运算符
【参数】 无
【返回值】 *this
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
Month& Month::operator--() {
    switch (m_Value) {
    case ValueType::JAN: m_Value = ValueType::DEC; break;
    case ValueType::FEB: m_Value = ValueType::JAN; break;
    case ValueType::MAR: m_Value = ValueType::FEB; break;
    case ValueType::APR: m_Value = ValueType::MAR; break;
    case ValueType::MAY: m_Value = ValueType::APR; break;
    case ValueType::JUN: m_Value = ValueType::MAY; break;
    case ValueType::JUL: m_Value = ValueType::JUN; break;
    case ValueType::AUG: m_Value = ValueType::JUL; break;
    case ValueType::SEP: m_Value = ValueType::AUG; break;
    case ValueType::OCT: m_Value = ValueType::SEP; break;
    case ValueType::NOV: m_Value = ValueType::OCT; break;
    case ValueType::DEC: m_Value = ValueType::NOV; break;
    default: throw ExecptionWrongValue();
    }
    return *this;
}

/*************************************************************************
【函数名称】 operator--【函数功能】 后置--运算符
【参数】 无
【返回值】 Temp
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
Month Month::operator--(int) {
    //call prefix operator--
    Month Temp{ *this };
    --(*this);
    return Temp;
}

/*************************************************************************
【函数名称】 ToName【函数功能】 转换为字符串
【参数】 输入参数Source，输入参数Type
【返回值】 月份名称
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
string Month::ToName(const Month& Source, const NameType& Type) {
    return m_Names[static_cast<unsigned int>(Type)]
        [static_cast<unsigned int>(Source.m_Value) - 1];
}

/*************************************************************************
【函数名称】 ToName【函数功能】 转换为字符串
【参数】 输入参数Source，输入参数Type
【返回值】 月份名称
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
string Month::ToName(const ValueType& Source, const NameType& Type) {
    return m_Names[static_cast<unsigned int>(Type)]
        [static_cast<unsigned int>(Source) - 1];
}

/*************************************************************************
【函数名称】 ToName【函数功能】 转换为字符串
【参数】 输入参数Type
【返回值】 月份名称
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
string Month::ToName(const NameType& Type) const {
    return ToName(m_Value, Type);
}

/*************************************************************************
【函数名称】 operator()【函数功能】 （）运算符
【参数】 无
【返回值】 得到月份对象的值
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
unsigned int Month::operator()() const {
    return static_cast<unsigned int>(m_Value);
}

/*************************************************************************
【函数名称】 GetMaxDaysOfMonths【函数功能】 得到月份最大日
【参数】 无
【返回值】 unsigned int最大日
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
unsigned int Month::GetMaxDaysOfMonths() const {
    return MaxDaysOfMonths[static_cast<unsigned int>(m_Value)];
}

/*************************************************************************
【函数名称】 GetMaxDaysOfMonths【函数功能】 得到月份最大日
【参数】 输入参数Month
【返回值】 unsigned int最大日
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
unsigned int Month::GetMaxDaysOfMonths(const unsigned int& Month) {
    return MaxDaysOfMonths[Month];
}

/*************************************************************************
【函数名称】 GetMaxDaysOfMonths【函数功能】 得到月份最大日
【参数】 输入参数Month
【返回值】 unsigned int最大日
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
unsigned int Month::GetMaxDaysOfMonths(const Month& Month) {
    return MaxDaysOfMonths[Month.GetValue()];
}
