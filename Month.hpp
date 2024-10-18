/*************************************************************************
���ļ����� Month.hpp
������ģ���Ŀ�ġ� ά��Month�࣬���б�дMonth���Ա������������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/

#ifndef Month_hpp
#define Month_hpp

#include <string>
#include <stdexcept>
using std::string;
using std::exception;
using std::invalid_argument;

/*************************************************************************
�������� Month
�����ܡ� �·ݹ�������ֵ���������ơ�
���ӿ�˵���� 6��getter������ȡ���ݣ�5��setter�����޸ĳ�Ա���ݣ�4��IsValid�жϺϷ��ԡ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
class Month {
public:
    //�׳��·��쳣��
    class ExecptionWrongValue : public invalid_argument {
    public:
        ExecptionWrongValue();
    };
    //�·�ֵ����
    enum class ValueType : unsigned int {
        JAN = 1, FEB = 2, MAR = 3, APR = 4, MAY = 5, JUN = 6
        , JUL = 7, AUG = 8, SEP = 9, OCT = 10, NOV = 11, DEC = 12
    };
    //�·���������
    enum class NameType : unsigned int {
        SHORT = 0, FULL = 1
    };
    //�������Ĺ��캯��
    Month(const ValueType& Value);
    Month(const unsigned int& uValue);
    //Ĭ�Ϲ��캯��
    Month() = default;
    //�������캯��
    Month(const Month&) = default;
    //Ĭ�ϸ�ֵ�����
    Month& operator=(const Month&) = default;
    //��������
    ~Month() = default;

    //��ֵ�����
    Month& operator= (const ValueType& Value);
    Month& operator= (const unsigned int& uValue);

    //�����·�
    void Set(const ValueType& Value);
    void Set(const unsigned int& Value);
    //����·ݵ�ֵ
    unsigned int GetValue() const;

    //==�����
    bool        operator==(const Month& Source) const;
    bool        operator==(const ValueType& Source) const;
    friend bool operator==(const Month::ValueType& Value, const Month& Month);
    //!=�����
    bool        operator!=(const Month& Source) const;
    bool        operator!=(const ValueType& Source) const;
    friend bool operator!=(const Month::ValueType& Value, const Month& Month);
    //>�����
    bool        operator> (const Month& Source) const;
    bool        operator> (const ValueType& Source) const;
    friend bool operator> (const Month::ValueType& Value, const Month& Month);
    //>=�����
    bool        operator>=(const Month& Source) const;
    bool        operator>=(const ValueType& Source) const;
    friend bool operator>=(const Month::ValueType& Value, const Month& Month);
    //<�����
    bool        operator< (const Month& Source) const;
    bool        operator< (const ValueType& Source) const;
    friend bool operator< (const Month::ValueType& Value, const Month& Month);
    //<=�����
    bool        operator<=(const Month& Source) const;
    bool        operator<=(const ValueType& Source) const;
    friend bool operator<=(const Month::ValueType& Value, const Month& Month);
    //++�����
    Month& operator++();
    Month  operator++(int);
    //--�����
    Month& operator--();
    Month  operator--(int);

    //ת�����ַ���
    static string ToName(const Month& Source
        , const NameType& Type = NameType::SHORT);
    //ת�����ַ���
    static string ToName(const ValueType& Source
        , const NameType& Type = NameType::SHORT);
    //ת�����ַ���
    string ToName(const NameType& Type = NameType::SHORT) const;
    unsigned int operator()() const;

    //�õ��·������
    unsigned int GetMaxDaysOfMonths() const;
    static unsigned int GetMaxDaysOfMonths(const unsigned int& Month);
    static unsigned int GetMaxDaysOfMonths(const Month& Month);

private:
    ValueType m_Value;
    static const string m_Names[2][12];
    static const unsigned int MaxDaysOfMonths[13];
};

#endif /* WeekDay_hpp */


