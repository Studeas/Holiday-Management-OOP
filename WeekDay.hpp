/*************************************************************************
���ļ����� WeekDay.hpp
������ģ���Ŀ�ġ� ά��WeekDay�࣬���б�дWeekDay���Ա������������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/

#ifndef WeekDay_hpp
#define WeekDay_hpp

#include <string>
#include <stdexcept>
using std::string;
using std::exception;
using std::invalid_argument;

/*************************************************************************
�������� WeekDay
�����ܡ� ���ڹ���
���ӿ�˵���� 2��getter������ȡ���ݣ�2��setter�����޸ĳ�Ա���ݣ�3��toname�������
            �ַ������������������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
class WeekDay {
public:
    //�׳��쳣����
    class ExecptionWrongValue : public invalid_argument {
    public:
        ExecptionWrongValue();
    };
    //���ڵ�ֵ
    enum class ValueType : unsigned int {
        MON = 1, TUES = 2, WED = 3, THUR = 4, FRI = 5, SAT = 6, SUN = 7
    };
    //��������
    enum class NameType : unsigned int {
        SHORT = 0, FULL = 1
    };
    //���캯��
    WeekDay(const ValueType& Value);
    WeekDay(const unsigned int& Value);
    //ɾ��Ĭ�Ϲ��캯��
    WeekDay() = delete;
    //Ĭ�Ͽ������졢����������Ĭ�ϸ�ֵ�����
    WeekDay(const WeekDay&) = default;
    WeekDay& operator=(const WeekDay&) = default;
    ~WeekDay() = default;
    //��ֵ�����
    WeekDay& operator= (const ValueType& Value);

    //��������
    void Set(const ValueType& Value);
    void Set(const unsigned int& Value);

    //==�����
    bool        operator==(const WeekDay& Source) const;
    bool        operator==(const ValueType& Source) const;
    friend bool operator==(const WeekDay::ValueType& Value
                         , const WeekDay& WeekDay);
    //!=�����
    bool        operator!=(const WeekDay& Source) const;
    bool        operator!=(const ValueType& Source) const;
    friend bool operator!=(const WeekDay::ValueType& Value
                         , const WeekDay& WeekDay);
    //>�����
    bool        operator> (const WeekDay& Source) const;
    bool        operator> (const ValueType& Source) const;
    friend bool operator> (const WeekDay::ValueType& Value
                         , const WeekDay& WeekDay);
    //>=�����
    bool        operator>=(const WeekDay& Source) const;
    bool        operator>=(const ValueType& Source) const;
    friend bool operator>=(const WeekDay::ValueType& Value
                         , const WeekDay& WeekDay);
    //<�����
    bool        operator< (const WeekDay& Source) const;
    bool        operator< (const ValueType& Source) const;
    friend bool operator< (const WeekDay::ValueType& Value
                         , const WeekDay& WeekDay);
    //<=�����
    bool        operator<=(const WeekDay& Source) const;
    bool        operator<=(const ValueType& Source) const;
    friend bool operator<=(const WeekDay::ValueType& Value
                         , const WeekDay& WeekDay);
    //ǰ��++�����
    WeekDay& operator++();
    WeekDay  operator++(int);
    //����++�����
    WeekDay& operator--();
    WeekDay  operator--(int);

    //ת�����ַ�������
    static string ToName(const WeekDay& Source
                        , const NameType& Type = NameType::SHORT);
    static string ToName(const ValueType& Source
                        , const NameType& Type = NameType::SHORT);
    string ToName(const NameType& Type = NameType::SHORT) const;

    //()�����
    unsigned int operator()() const;

    //������ڵ�ֵ
    unsigned int GetActualValue() const;
    static unsigned int GetActualValue(const WeekDay& WeekDay);

private:
    ValueType m_Value;
    static const string m_Names[2][7];
};

#endif /* WeekDay_hpp */

