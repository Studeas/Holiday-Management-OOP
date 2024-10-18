/*************************************************************************
���ļ����� MonthCalendarPrinter.cpp
������ģ���Ŀ�ġ� ά��MonthCalendarPrinter�࣬���б�дMonthCalendarPrinter��
			     ��Ա�����Ķ��塣
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
#include "MonthCalendarPrinter.hpp"
using namespace std;

/*************************************************************************
���������ơ� MonthCalendarPrinter���������ܡ� ���캯��
�������� �������uYear���������uMonth
������ֵ�� ���캯������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
MonthCalendarPrinter::MonthCalendarPrinter(const unsigned int& uYear
											, const unsigned int& uMonth) {
	if (uYear < 1900 || uYear>9999) {
		throw invalid_argument("��ݳ���");
	}
	Month::Month(uMonth);
	m_Year = uYear;
	m_Month = uMonth;
}

/*************************************************************************
���������ơ� PrintCalendar���������ܡ� ��ӡ����
�������� �������uYear���������uMonth
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void MonthCalendarPrinter::PrintCalendar(const unsigned int& uYear
										, const unsigned int& uMonth) const{
	unsigned int FirstDayWeekDay;
	unsigned int DaysInTotal;
	FirstDayWeekDay = YMDDate(uYear, uMonth, 1).ToWeekDay().GetActualValue();
	DaysInTotal = Month::Month(uMonth).GetMaxDaysOfMonths();
	if (!YMDDate::IsLeapYear(uYear) && uMonth == 2) {
		DaysInTotal -= 1;
	}

	//��ӡ��ͷ
	cout << "Calendar of " << Month::Month(uMonth).ToName(Month::NameType::FULL) 
		 << ", " << uYear << "." << endl << endl;
	cout << "=========================================================" << endl;
	cout << "|  Mon  |" << "  Tue  |" << "  Wed  |" << "  Thu  |" << "  Fri  |" 
		 << "  Sat  |" << "  Sun  |" << endl;
	cout << "=========================================================" << endl;

	//���д�ӡ
	unsigned int MonthDaysPrint[42]{ 0 };
	unsigned int DayValue = 1;
	for (unsigned int DayPosi = FirstDayWeekDay - 1
			; DayPosi < DaysInTotal + FirstDayWeekDay - 1; DayPosi++) {
		MonthDaysPrint[DayPosi] = DayValue;
		DayValue++;
	}
	for (unsigned int RowNum = 0; RowNum < 6; RowNum++) {
		if (MonthDaysPrint[RowNum * 7 + 0] == 0 && RowNum != 0) {
			break;
		}
		cout << "|";
		for (unsigned int ColNum = 0; ColNum < 7; ColNum++) {
			if (MonthDaysPrint[RowNum * 7 + ColNum] == 0) {
				cout << "       |";
			}
			else {
				cout << "  ";
				cout << setw(2) << MonthDaysPrint[RowNum * 7 + ColNum] << "   |";
			}
		}
		cout << endl;
		cout << "---------------------------------------------------------" 
			 << endl;
	}
	cout << endl ;
}

/*************************************************************************
���������ơ� CmpByDate���������ܡ� �������
�������� �������a���������b
������ֵ�� bool��a����С��b��Ϊtrue
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool MonthCalendarPrinter::CmpByDate(Festival::FestivalInThisYear* a
									, Festival::FestivalInThisYear* b) {
	return a->m_DaysInTotal < b->m_DaysInTotal;
}

/*************************************************************************
���������ơ� PrintFestivals���������ܡ� ��ӡ����
�������� �������uYear���������uMonth
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void MonthCalendarPrinter::PrintFestivals(const unsigned int& uYear
										, const unsigned int& uMonth) const{
	unsigned int DaysInTotal;
	DaysInTotal = Month::Month(uMonth).GetMaxDaysOfMonths();
	if (!YMDDate::IsLeapYear(uYear) && uMonth == 2) {
		DaysInTotal -= 1;
	}

	vector<Festival::FestivalInThisYear*> ThisYearFestivals 
		= Festival::GetFestivalInThisYearList(uYear);
	
	sort(ThisYearFestivals.begin(), ThisYearFestivals.end(), CmpByDate);

	//��ӡ��ʾ��
	cout << "Festivals in " 
		 << Month::Month(uMonth).ToName(Month::NameType::FULL) 
		 << ", " << uYear << "." << endl << endl;

	//��ӡ����
	for (auto& n : ThisYearFestivals) {
		if (n->m_DaysInTotal >= YMDDate(uYear, uMonth, 1).DaysPassedInTotal()
			&& n->m_DaysInTotal 
			<= YMDDate(uYear, uMonth, DaysInTotal).DaysPassedInTotal()) {

			cout << YMDDate(uYear, uMonth, n->m_DaysInTotal 
				- YMDDate(uYear, uMonth, 1).DaysPassedInTotal() + 1).GetMonth() << ".";
			cout << setw(2)<<setfill('0') << YMDDate(uYear, uMonth, n->m_DaysInTotal 
				- YMDDate(uYear, uMonth, 1).DaysPassedInTotal() + 1).GetDay();
			cout << "     " << n->m_Name << "   " << endl;
		}
	}
	cout << endl;
}