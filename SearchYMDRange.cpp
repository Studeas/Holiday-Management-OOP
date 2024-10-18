/*************************************************************************
���ļ����� SearchYMDRange.cpp
������ģ���Ŀ�ġ� ά��SearchYMDRange�࣬���б�дSearchYMDRange���Ա�����Ķ��塣
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/

#include "SearchYMDRange.hpp"

/*************************************************************************
���������ơ� SearchYMDRange���������ܡ� ���캯��
�������� �������YMDDate1���������YMDDate2���������SortType
������ֵ�� ���캯������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
SearchYMDRange::SearchYMDRange(const YMDDate& YMDDate1
							, const YMDDate& YMDDate2
							, const SortType& SortType) 
							: m_YMDDate1(YMDDate1)
							, m_YMDDate2(YMDDate2)
							, m_SortType(SortType) {

}

/*************************************************************************
���������ơ� CmpDate���������ܡ� ����������������
�������� �������a���������b
������ֵ�� a������С��b�򷵻�true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool CmpDate(Festival::FestivalInThisYear* a, Festival::FestivalInThisYear* b) {
	return a->m_DaysInTotal < b->m_DaysInTotal;
}

/*************************************************************************
���������ơ� CmpName���������ܡ� ��������ĸ��������
�������� �������a���������b
������ֵ�� a������ĸ��b֮ǰ�򷵻�true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
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
���������ơ� PrintFestivals���������ܡ� ���ҡ������Ҵ�ӡ
�������� ��
������ֵ�� TheseYearsFestivals ���ҽ����list
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
vector<Festival::FestivalInThisYear*> SearchYMDRange::PrintFestivals() const {
	unsigned int MaxDaysInTotal = m_YMDDate2.DaysPassedInTotal();
	unsigned int MinDaysInTotal = m_YMDDate1.DaysPassedInTotal();
	
	vector<Festival::FestivalInThisYear*> TheseYearsFestivals 
		= Festival::GetFestivalInThisYearList(m_YMDDate1.GetYear());

	//���Ƚ�����������ݵĽ��ն������
	for (unsigned int Year = m_YMDDate1.GetYear() + 1
		; Year <= m_YMDDate2.GetYear(); Year++) {
		vector<Festival::FestivalInThisYear*> Temp 
			= Festival::GetFestivalInThisYearList(Year);
		TheseYearsFestivals.insert(TheseYearsFestivals.end()
			, Temp.begin(), Temp.end());
	}
	cout << "try";
	//Ȼ�������ɾ������֮��Ľ���
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
	//����ѡ���������
	if (m_SortType == SortType::BY_DATE) {
		sort(TheseYearsFestivals.begin(), TheseYearsFestivals.end(), CmpName);
		sort(TheseYearsFestivals.begin(), TheseYearsFestivals.end(), CmpDate);
	}
	if (m_SortType == SortType::BY_NAME) {
		sort(TheseYearsFestivals.begin(), TheseYearsFestivals.end(), CmpDate);
		sort(TheseYearsFestivals.begin(), TheseYearsFestivals.end(), CmpName);
	}
	//��ӡ��ʾ��
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
	//���ؽ��
	return TheseYearsFestivals;
}