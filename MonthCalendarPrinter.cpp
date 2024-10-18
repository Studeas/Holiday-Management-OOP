/*************************************************************************
【文件名】 MonthCalendarPrinter.cpp
【功能模块和目的】 维护MonthCalendarPrinter类，集中编写MonthCalendarPrinter类
			     成员函数的定义。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
#include "MonthCalendarPrinter.hpp"
using namespace std;

/*************************************************************************
【函数名称】 MonthCalendarPrinter【函数功能】 构造函数
【参数】 输入参数uYear，输入参数uMonth
【返回值】 构造函数，无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
MonthCalendarPrinter::MonthCalendarPrinter(const unsigned int& uYear
											, const unsigned int& uMonth) {
	if (uYear < 1900 || uYear>9999) {
		throw invalid_argument("年份超限");
	}
	Month::Month(uMonth);
	m_Year = uYear;
	m_Month = uMonth;
}

/*************************************************************************
【函数名称】 PrintCalendar【函数功能】 打印月历
【参数】 输入参数uYear，输入参数uMonth
【返回值】 无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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

	//打印表头
	cout << "Calendar of " << Month::Month(uMonth).ToName(Month::NameType::FULL) 
		 << ", " << uYear << "." << endl << endl;
	cout << "=========================================================" << endl;
	cout << "|  Mon  |" << "  Tue  |" << "  Wed  |" << "  Thu  |" << "  Fri  |" 
		 << "  Sat  |" << "  Sun  |" << endl;
	cout << "=========================================================" << endl;

	//逐行打印
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
【函数名称】 CmpByDate【函数功能】 排序节日
【参数】 输入参数a，输入参数b
【返回值】 bool，a日期小于b则为true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool MonthCalendarPrinter::CmpByDate(Festival::FestivalInThisYear* a
									, Festival::FestivalInThisYear* b) {
	return a->m_DaysInTotal < b->m_DaysInTotal;
}

/*************************************************************************
【函数名称】 PrintFestivals【函数功能】 打印节日
【参数】 输入参数uYear，输入参数uMonth
【返回值】 无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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

	//打印提示语
	cout << "Festivals in " 
		 << Month::Month(uMonth).ToName(Month::NameType::FULL) 
		 << ", " << uYear << "." << endl << endl;

	//打印节日
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