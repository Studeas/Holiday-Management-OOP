/*************************************************************************
���ļ����� MDDate.hpp
������ģ���Ŀ�ġ� ά��MDDate�࣬���б�дMDDate���Ա������������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/

#ifndef MDDate_hpp
#define MDDate_hpp

#include "Month.hpp"

/*************************************************************************
�������� MDDate
�����ܡ� �������ڣ��������п��ܵ����ڣ���2.29����������ƽ���ꡣ
���ӿ�˵���� 6��getter������ȡ���ݣ�5��setter�����޸ĳ�Ա���ݣ�4��IsValid�жϺϷ��ԡ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
class MDDate {
public:
	//ɾ��Ĭ�Ϲ��캯��
	MDDate() = delete;

	//�������Ĺ��캯��
	MDDate(const unsigned int& uMonth, const unsigned int& uDay);
	MDDate(const Month& Month, const unsigned int& uDay);

	//Ĭ�Ͽ������캯����Ĭ����������
	MDDate(const MDDate& MDDate) = default;
	~MDDate() = default;

	//��ֵ�����
	MDDate& operator=(const MDDate& MDDate);

	//�����¡�������
	void Set(const unsigned int& uMonth, const unsigned int& uDay);
	void Set(const Month& Month, const unsigned int& uDay);
	void SetMonth(const unsigned int& uMonth);
	void SetMonth(const Month& Month);
	void SetDay(const unsigned int& uDay);

	//�ж����������Ƿ�Ϸ�
	static bool IsValidMDDate(const unsigned int& uMonth
							, const unsigned int& uDay);
	static bool IsValidMDDate(const Month::ValueType& Month
							, const unsigned int& uDay);
	static bool IsValidMDDate(const Month& Month
							, const unsigned int& uDay);
	bool IsValidMDDate() const;

	//==�����
	bool operator==(const MDDate& Source) const;
	friend bool operator==(const MDDate& MDDate1, const MDDate& MDDate2);
	//!=�����
	bool operator!=(const MDDate& Source) const;
	friend bool operator!=(const MDDate& MDDate1, const MDDate& MDDate2);
	//>�����
	bool operator>(const MDDate& Source) const;
	friend bool operator>(const MDDate& MDDate1, const MDDate& MDDate2);
	//<�����
	bool operator<(const MDDate& Source) const;
	friend bool operator<(const MDDate& MDDate1, const MDDate& MDDate2);
	//>=�����
	bool operator>=(const MDDate& Source) const;
	friend bool operator>=(const MDDate& MDDate1, const MDDate& MDDate2);
	//<=�����
	bool operator<=(const MDDate& Source) const;
	friend bool operator<=(const MDDate& MDDate1, const MDDate& MDDate2);
	//++�����
	MDDate& operator++();
	MDDate  operator++(int);
	//--�����
	MDDate& operator--();
	MDDate  operator--(int);

	//�����
	string GetMonth(const Month::NameType& Type = Month::NameType::SHORT) const;
	//����µ���ֵ
	unsigned int GetMonthValue() const;
	//�����
	unsigned int GetDay() const;
	//����µ�����գ��˴�������ƽ��2��Ϊ29�գ�
	static unsigned int GetDaysOfMonthMax(const Month& Month);
	static unsigned int GetDaysOfMonthMax(const unsigned int& uMonth);
	unsigned int GetDaysOfMonthMax() const;
	
	//������
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

