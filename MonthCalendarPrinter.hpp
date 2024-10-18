/*************************************************************************
���ļ����� MonthCalendarPrinter.hpp
������ģ���Ŀ�ġ� ά��MonthCalendarPrinter�࣬���б�дMonthCalendarPrinter
				  ���Ա������������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
#ifndef MonthCalendarPrinter_hpp
#define MonthCalendarPrinter_hpp

#include "Month.hpp"
#include "MDDate.hpp"
#include "YMDDate.hpp"
#include "WeekDay.hpp"
#include "SpecialDateFestival.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

/*************************************************************************
�������� MonthCalendarPrinter
�����ܡ� �����ӡ�����͵��½��յĹ���
���ӿ�˵���� 1��PrintCalendar��ӡ������1��PrintFestivals��ӡ����list
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
class MonthCalendarPrinter {
public:
	//ɾ��Ĭ�Ϲ��캯�����������캯��
	MonthCalendarPrinter() = delete;
	MonthCalendarPrinter(const MonthCalendarPrinter&) = delete;

	//�������Ĺ��캯��
	MonthCalendarPrinter(const unsigned int& uYear
						, const unsigned int& uMonth);
	//Ĭ����������
	~MonthCalendarPrinter() = default;

	//�����ս���
	static bool CmpByDate(Festival::FestivalInThisYear* a
						, Festival::FestivalInThisYear* b);
	//��ӡ����
	void PrintCalendar(const unsigned int& uYear
					, const unsigned int& uMonth) const;

	//��ӡ���½���
	void PrintFestivals(const unsigned int& uYear
					, const unsigned int& uMonth) const;
private:
	unsigned int m_Year;
	unsigned int m_Month;

};

#endif // !MonthCalendarPrinter_hpp

