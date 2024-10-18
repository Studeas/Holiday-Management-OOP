/*************************************************************************
【文件名】 SearchYMDRange.cpp
【功能模块和目的】 维护SearchYMDRange类，集中编写SearchYMDRange类成员函数的定义。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/

#include "SearchYMDRange.hpp"

/*************************************************************************
【函数名称】 SearchYMDRange【函数功能】 构造函数
【参数】 输入参数YMDDate1，输入参数YMDDate2，输入参数SortType
【返回值】 构造函数，无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
SearchYMDRange::SearchYMDRange(const YMDDate& YMDDate1
							, const YMDDate& YMDDate2
							, const SortType& SortType) 
							: m_YMDDate1(YMDDate1)
							, m_YMDDate2(YMDDate2)
							, m_SortType(SortType) {

}

/*************************************************************************
【函数名称】 CmpDate【函数功能】 按照日期升序排序
【参数】 输入参数a，输入参数b
【返回值】 a的日期小于b则返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool CmpDate(Festival::FestivalInThisYear* a, Festival::FestivalInThisYear* b) {
	return a->m_DaysInTotal < b->m_DaysInTotal;
}

/*************************************************************************
【函数名称】 CmpName【函数功能】 按照首字母升序排序
【参数】 输入参数a，输入参数b
【返回值】 a的首字母再b之前则返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool CmpName(Festival::FestivalInThisYear* a, Festival::FestivalInThisYear* b) {
	char Initial_a = a->m_Name[0];
	char Initial_b = b->m_Name[0];
	if (static_cast<int>(Initial_a) >= 97) {
		Initial_a = static_cast<char>(static_cast<int>(Initial_a) - 32);
	}
	if (static_cast<int>(Initial_b) >= 97) {
		Initial_b = static_cast<char>(static_cast<int>(Initial_b) - 32);
	}
	return static_cast<int>(Initial_a) < static_cast<int>(Initial_b);
}

/*************************************************************************
【函数名称】 PrintFestivals【函数功能】 查找、排序并且打印
【参数】 无
【返回值】 TheseYearsFestivals 查找结果的list
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
vector<Festival::FestivalInThisYear*> SearchYMDRange::PrintFestivals() const {
	unsigned int MaxDaysInTotal = m_YMDDate2.DaysPassedInTotal();
	unsigned int MinDaysInTotal = m_YMDDate1.DaysPassedInTotal();
	
	vector<Festival::FestivalInThisYear*> TheseYearsFestivals 
		= Festival::GetFestivalInThisYearList(m_YMDDate1.GetYear());

	//首先将所搜索的年份的节日都存进来
	for (unsigned int Year = m_YMDDate1.GetYear() + 1
		; Year <= m_YMDDate2.GetYear(); Year++) {
		vector<Festival::FestivalInThisYear*> Temp 
			= Festival::GetFestivalInThisYearList(Year);
		TheseYearsFestivals.insert(TheseYearsFestivals.end()
			, Temp.begin(), Temp.end());
	}
	cout << "try";
	//然后遍历，删除日期之外的节日
	vector<Festival::FestivalInThisYear*>::iterator n 
		= TheseYearsFestivals.begin();
	for (n; n != TheseYearsFestivals.end(); n++) {
		if ((*n)->m_DaysInTotal > MaxDaysInTotal 
			|| (*n)->m_DaysInTotal < MinDaysInTotal) {
			delete (*n);
			(*n) = nullptr;
			n = TheseYearsFestivals.erase(n);
		}
	}
	//按照选择进行排序
	if (m_SortType == SortType::BY_DATE) {
		sort(TheseYearsFestivals.begin(), TheseYearsFestivals.end(), CmpName);
		sort(TheseYearsFestivals.begin(), TheseYearsFestivals.end(), CmpDate);
	}
	if (m_SortType == SortType::BY_NAME) {
		sort(TheseYearsFestivals.begin(), TheseYearsFestivals.end(), CmpDate);
		sort(TheseYearsFestivals.begin(), TheseYearsFestivals.end(), CmpName);
	}
	//打印提示语
	cout << "Festivals in this period (" 
		<< m_YMDDate1.GetMonth(Month::NameType::FULL) << "." 
		<< m_YMDDate1.GetDay() << ", " << m_YMDDate1.GetYear()
		<< " ~ " << m_YMDDate2.GetMonth(Month::NameType::FULL) << "." 
		<< m_YMDDate2.GetDay() << ", " << m_YMDDate2.GetYear() << "):" << endl;
	for (auto& n : TheseYearsFestivals) {
		cout << flush << n->m_YMDDate.GetMonth() << "." 
			<< setw(2) << setfill('0') << n->m_YMDDate.GetDay() << ", " 
			<< n->m_YMDDate.GetYear() << "   " << n->m_Name << endl;
	}
	//返回结果
	return TheseYearsFestivals;
}