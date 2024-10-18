/*************************************************************************
���ļ����� Month.cpp
������ģ���Ŀ�ġ� ά��Month�࣬���б�дMonth���Ա�����Ķ��塣
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
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
���������ơ� ExecptionWrongValue���������ܡ� �׳��·��쳣
�������� ��
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
Month::ExecptionWrongValue::ExecptionWrongValue() 
    : invalid_argument("�·ݴ���ӦΪ 1~12(JAN to DEC)��") {
}

/*************************************************************************
���������ơ� Month���������ܡ� ���캯��
�������� �������Value
������ֵ�� ���캯������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
Month::Month(const ValueType& Value) {
    Set(Value);
}

/*************************************************************************
���������ơ� Month���������ܡ� ���캯��
�������� �������Value
������ֵ�� ���캯������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
Month::Month(const unsigned int& uValue) {
    Set(uValue);
}

/*************************************************************************
���������ơ� operator=���������ܡ� ��ֵ�����
�������� �������Value
������ֵ�� *this
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
Month& Month::operator= (const ValueType& Value) {
    Set(Value);
    return *this;
}

/*************************************************************************
���������ơ� operator=���������ܡ� ��ֵ�����
�������� �������Value
������ֵ�� *this
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
Month& Month::operator= (const unsigned int& uValue) {
    Set(uValue);
    return *this;
}

/*************************************************************************
���������ơ� Set���������ܡ� �����·�
�������� �������Value
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void Month::Set(const ValueType& Value) {
    this->m_Value = Value;
}

/*************************************************************************
���������ơ� Set���������ܡ� �����·�
�������� �������uValue
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
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
���������ơ� GetValue���������ܡ� ����·�ֵ
�������� ��
������ֵ�� static_cast<unsigned int>(m_Value)�·�ֵ
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
unsigned int Month::GetValue() const {
    return static_cast<unsigned int>(m_Value);
}

/*************************************************************************
���������ơ� operator==���������ܡ� ==�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool Month::operator==(const Month& Source) const {
    return m_Value == Source.m_Value;
}

/*************************************************************************
���������ơ� operator==���������ܡ� ==�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool Month::operator==(const ValueType& Source) const {
    return  m_Value == Source;
}

/*************************************************************************
���������ơ� operator==���������ܡ� ==���������Ԫ
�������� �������Value���������Month
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool operator==(const Month::ValueType& Value, const Month& Month) {
    return Value == Month.m_Value;
}

/*************************************************************************
���������ơ� operator!=���������ܡ� !=�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool Month::operator!=(const Month& Source) const {
    return m_Value != Source.m_Value;
}

/*************************************************************************
���������ơ� operator!=���������ܡ� !=�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool Month::operator!=(const ValueType& Source) const {
    return  m_Value != Source;
}

/*************************************************************************
���������ơ� operator!=���������ܡ� !=���������Ԫ
�������� �������Value���������Month
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool operator!=(const Month::ValueType& Value, const Month& Month) {
    return Value != Month.m_Value;
}

/*************************************************************************
���������ơ� operator>���������ܡ� >�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool Month::operator> (const Month& Source) const {
    return  m_Value > Source.m_Value;
}

/*************************************************************************
���������ơ� operator>���������ܡ� >�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool Month::operator> (const ValueType& Source) const {
    return  m_Value > Source;
}

/*************************************************************************
���������ơ� operator>���������ܡ� >���������Ԫ
�������� �������Value���������Month
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool operator> (const Month::ValueType& Value, const Month& Month) {
    return Value > Month.m_Value;
}

/*************************************************************************
���������ơ� operator>=���������ܡ� >=�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool Month::operator>=(const Month& Source) const {
    return m_Value >= Source.m_Value;
}

/*************************************************************************
���������ơ� operator>=���������ܡ� >=�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool Month::operator>=(const ValueType& Source) const {
    return m_Value >= Source;
}

/*************************************************************************
���������ơ� operator>=���������ܡ� >=���������Ԫ
�������� �������Value���������Month
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool operator>=(const Month::ValueType& Value, const Month& Month) {
    return Value >= Month.m_Value;
}

/*************************************************************************
���������ơ� operator<���������ܡ� <�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool Month::operator< (const Month& Source) const {
    return m_Value < Source.m_Value;
}

/*************************************************************************
���������ơ� operator<���������ܡ� <�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool Month::operator< (const ValueType& Source) const {
    return m_Value < Source;
}

/*************************************************************************
���������ơ� operator<���������ܡ� <���������Ԫ
�������� �������Value���������Month
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool operator< (const Month::ValueType& Value, const Month& Month) {
    return Value < Month.m_Value;
}

/*************************************************************************
���������ơ� operator<=���������ܡ� <=�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool Month::operator<=(const Month& Source) const {
    return m_Value <= Source.m_Value;
}

/*************************************************************************
���������ơ� operator<=���������ܡ� <=�����
�������� �������Source
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool Month::operator<=(const ValueType& Source) const {
    return m_Value <= Source;
}

/*************************************************************************
���������ơ� operator<=���������ܡ� <=���������Ԫ
�������� �������Value���������Month
������ֵ�� bool��������������true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool operator<=(const Month::ValueType& Value, const Month& Month) {
    return Value <= Month.m_Value;
}

/*************************************************************************
���������ơ� operator++���������ܡ� ǰ��++�����
�������� ��
������ֵ�� *this
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
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
���������ơ� operator++���������ܡ� ����++�����
�������� ��
������ֵ�� Temp
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
Month Month::operator++(int) {
    //call prefix operator++
    Month Temp{ *this };
    ++(*this);
    return Temp;
}

/*************************************************************************
���������ơ� operator--���������ܡ� ǰ��--�����
�������� ��
������ֵ�� *this
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
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
���������ơ� operator--���������ܡ� ����--�����
�������� ��
������ֵ�� Temp
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
Month Month::operator--(int) {
    //call prefix operator--
    Month Temp{ *this };
    --(*this);
    return Temp;
}

/*************************************************************************
���������ơ� ToName���������ܡ� ת��Ϊ�ַ���
�������� �������Source���������Type
������ֵ�� �·�����
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
string Month::ToName(const Month& Source, const NameType& Type) {
    return m_Names[static_cast<unsigned int>(Type)]
        [static_cast<unsigned int>(Source.m_Value) - 1];
}

/*************************************************************************
���������ơ� ToName���������ܡ� ת��Ϊ�ַ���
�������� �������Source���������Type
������ֵ�� �·�����
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
string Month::ToName(const ValueType& Source, const NameType& Type) {
    return m_Names[static_cast<unsigned int>(Type)]
        [static_cast<unsigned int>(Source) - 1];
}

/*************************************************************************
���������ơ� ToName���������ܡ� ת��Ϊ�ַ���
�������� �������Type
������ֵ�� �·�����
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
string Month::ToName(const NameType& Type) const {
    return ToName(m_Value, Type);
}

/*************************************************************************
���������ơ� operator()���������ܡ� ���������
�������� ��
������ֵ�� �õ��·ݶ����ֵ
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
unsigned int Month::operator()() const {
    return static_cast<unsigned int>(m_Value);
}

/*************************************************************************
���������ơ� GetMaxDaysOfMonths���������ܡ� �õ��·������
�������� ��
������ֵ�� unsigned int�����
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
unsigned int Month::GetMaxDaysOfMonths() const {
    return MaxDaysOfMonths[static_cast<unsigned int>(m_Value)];
}

/*************************************************************************
���������ơ� GetMaxDaysOfMonths���������ܡ� �õ��·������
�������� �������Month
������ֵ�� unsigned int�����
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
unsigned int Month::GetMaxDaysOfMonths(const unsigned int& Month) {
    return MaxDaysOfMonths[Month];
}

/*************************************************************************
���������ơ� GetMaxDaysOfMonths���������ܡ� �õ��·������
�������� �������Month
������ֵ�� unsigned int�����
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
unsigned int Month::GetMaxDaysOfMonths(const Month& Month) {
    return MaxDaysOfMonths[Month.GetValue()];
}
