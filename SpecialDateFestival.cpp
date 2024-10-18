/*************************************************************************
���ļ����� SpecialDateFestival.cpp
������ģ���Ŀ�ġ� ά��SpecialDateFestival�࣬���б�дSpecialDateFestival���Ա�����Ķ��塣
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/

#include "SpecialDateFestival.hpp"
#include <stdexcept>

/*************************************************************************
���������ơ� SpecialDateFestival���������ܡ� ���캯��
�������� �������Name���������YMDDate
������ֵ�� ���캯������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
SpecialDateFestival::SpecialDateFestival(const string& Name
										, const YMDDate& YMDDate) 
										: Festival(Name)
										, m_YMDDate(YMDDate) {
}

/*************************************************************************
���������ơ� Add���������ܡ� ��ӽ���
�������� �������Name���������YMDDate
������ֵ�� Temp������ӽ��յ�ָ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
Festival* SpecialDateFestival::Add(const string& Name, const YMDDate& YMDDate) {
	for (auto& n : m_All) {
		if (n->Name == Name) {
			n = nullptr;
			throw invalid_argument("�����ظ��Ľ�������");
		}
	}
	Festival* Temp = new SpecialDateFestival(Name, YMDDate);
	m_All.push_back(Temp);
	return Temp;
}

/*************************************************************************
���������ơ� ModifyMOWeekDay���������ܡ� �޸�MOW
�������� �������uMonth���������uOrdial���������uWeekDay
������ֵ�� bool false ���Ͳ�һ�£�����ʵ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool SpecialDateFestival::ModifyMOWeekDay(const unsigned int& uMonth
										, const unsigned int& uOrdial
										, const unsigned int& uWeekDay) {
	return false;
}

/*************************************************************************
���������ơ� ModifyMDDate���������ܡ� �޸�����
�������� �������uMonth���������uDay
������ֵ�� bool true �޸ĳɹ�����������Ļ�Set���쳣
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool SpecialDateFestival::ModifyMDDate(const unsigned int& uMonth
									, const unsigned int& uDay) {
	YMDDate Temp(m_YMDDate.GetYear(), uMonth, uDay);//�Ѱ������ںϸ��Լ��
	m_YMDDate = Temp;
	return true;
}

/*************************************************************************
���������ơ� ModifyYMDDate���������ܡ� �޸�������
�������� �������uYear���������uMonth���������uDay
������ֵ�� bool false ���Ͳ�һ�£�����ʵ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool SpecialDateFestival::ModifyYMDDate(const unsigned int& uYear
									, const unsigned int& uMonth
									, const unsigned int& uDay) {
	YMDDate Temp(uYear, uMonth, uDay);//�Ѱ������ںϸ��Լ��
	m_YMDDate = Temp;
	return true;
}

/*************************************************************************
���������ơ� GetYMDDate���������ܡ� ���������
�������� ��
������ֵ�� m_YMDDate
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
YMDDate SpecialDateFestival::GetYMDDate() const {
	return m_YMDDate;
}

/*************************************************************************
���������ơ� GetMDDate���������ܡ� �������
�������� ��
������ֵ�� �����յ����ղ���
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
MDDate SpecialDateFestival::GetMDDate() const {
	return MDDate(m_YMDDate.GetMonthValue(), m_YMDDate.GetDay());
}

/*************************************************************************
���������ơ� GetMOWeekDay���������ܡ� ���MOW
�������� ��
������ֵ�� m_MOWeekDay
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
MOWeekDay SpecialDateFestival::GetMOWeekDay() const {
	return m_YMDDate.ToMOWeekDay();
}

/*************************************************************************
���������ơ� GetType���������ܡ� �������
�������� ��
������ֵ�� FestivalType::REGULAR_WEEKDAY
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
FestivalType SpecialDateFestival::GetType() const {
	return FestivalType::SPECIAL_DATE;
}