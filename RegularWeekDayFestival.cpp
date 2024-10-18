/*************************************************************************
���ļ����� RegularWeekDayFestival.cpp
������ģ���Ŀ�ġ� ά��RegularWeekDayFestival�࣬���б�дRegularWeekDayFestival���Ա�����Ķ��塣
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/

#include "RegularWeekDayFestival.hpp"
#include <stdexcept>

/*************************************************************************
���������ơ� RegularWeekDayFestival���������ܡ� ���캯��
�������� �������Name���������MOWeekDay
������ֵ�� ���캯������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
RegularWeekDayFestival::RegularWeekDayFestival(const string& Name
	, const MOWeekDay& MOWeekDay) : Festival(Name), m_MOWeekDay(MOWeekDay) {

}

/*************************************************************************
���������ơ� RegularWeekDayFestival���������ܡ� ���캯��
�������� �������Name���������Month���������uOrdial���������WeekDay
������ֵ�� ���캯������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
RegularWeekDayFestival::RegularWeekDayFestival(const string& Name
											, const Month& Month
											, const unsigned int& uOrdial
											, const WeekDay& WeekDay) 
									: Festival(Name)
									, m_MOWeekDay(Month, uOrdial, WeekDay) {
}

/*************************************************************************
���������ơ� Add���������ܡ� ��ӽ���
�������� �������Name���������MOWeekDay
������ֵ�� Temp������ӽ��յ�ָ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
Festival* RegularWeekDayFestival::Add(const string& Name
									, const MOWeekDay& MOWeekDay) {
	for (auto& n : m_All) {
		if (n->Name == Name) {
			n = nullptr;
			throw invalid_argument("�����ظ��Ľ�������");
		}
	}
	Festival* pTemp = new RegularWeekDayFestival(Name, MOWeekDay);
	m_All.push_back(pTemp);
	return pTemp;
}

/*************************************************************************
���������ơ� ModifyMOWeekDay���������ܡ� �޸�MOW
�������� �������uMonth���������uOrdial���������uWeekDay
������ֵ�� bool true �޸ĳɹ�����������Ļ�Set���쳣
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool RegularWeekDayFestival::ModifyMOWeekDay(const unsigned int& uMonth
											, const unsigned int& uOrdial
											, const unsigned int& uWeekDay) {
	m_MOWeekDay.Set(uMonth, uOrdial, uWeekDay);
	return true;
}

/*************************************************************************
���������ơ� ModifyMDDate���������ܡ� �޸�����
�������� �������uMonth���������uDay
������ֵ�� bool false ���Ͳ�һ�£�����ʵ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool RegularWeekDayFestival::ModifyMDDate(const unsigned int& uMonth
										, const unsigned int& uDay) {
	return false;
}

/*************************************************************************
���������ơ� ModifyYMDDate���������ܡ� �޸�������
�������� �������uYear���������uMonth���������uDay
������ֵ�� bool false ���Ͳ�һ�£�����ʵ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool RegularWeekDayFestival::ModifyYMDDate(const unsigned int& uYear
										, const unsigned int& uMonth
										, const unsigned int& uDay) {
	return false;
}


/*************************************************************************
���������ơ� GetYMDDate���������ܡ� ���������
�������� ��
������ֵ�� ���쳣�����Ͳ�һ�£�����ʵ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
YMDDate RegularWeekDayFestival::GetYMDDate() const {
	throw invalid_argument("�޷�����YMD���ڡ�");
}

/*************************************************************************
���������ơ� GetMDDate���������ܡ� �������
�������� ��
������ֵ�� ���쳣�����Ͳ�һ�£�����ʵ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
MDDate RegularWeekDayFestival::GetMDDate() const {
	throw invalid_argument("�޷�����MD���ڡ�");
}

/*************************************************************************
���������ơ� GetMOWeekDay���������ܡ� ���MOW
�������� ��
������ֵ�� m_MOWeekDay
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
MOWeekDay RegularWeekDayFestival::GetMOWeekDay() const {
	return m_MOWeekDay;
}

/*************************************************************************
���������ơ� GetType���������ܡ� �������
�������� ��
������ֵ�� FestivalType::REGULAR_WEEKDAY
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
FestivalType RegularWeekDayFestival::GetType() const {
	return FestivalType::REGULAR_WEEKDAY;
}
