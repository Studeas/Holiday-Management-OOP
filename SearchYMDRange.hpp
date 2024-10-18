/*************************************************************************
���ļ����� SearchYMDRange.hpp
������ģ���Ŀ�ġ� ά��SearchYMDRange�࣬���б�дSearchYMDRange���Ա������������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/

#ifndef SearchYMDRange_hpp
#define SearchYMDRange_hpp

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
�������� SortType
�����ܡ� ö���࣬��������������
���ӿ�˵���� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
enum class SortType {
	BY_NAME, BY_DATE
};

/*************************************************************************
�������� SearchYMDRange
�����ܡ� ʵ�������շ�Χ�ڵĽ��ղ��Һ������ӡ
���ӿ�˵���� PrintFestivals�ɱ����ã�����ʵ�ֹ���
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
class SearchYMDRange {
public:
	//ɾ��Ĭ�Ϲ��캯�����������캯��
	SearchYMDRange() = delete;
	SearchYMDRange(const SearchYMDRange&) = delete;

	//�������Ĺ��캯��
	SearchYMDRange(const YMDDate& YMDDate1
				, const YMDDate& YMDDate2
				, const SortType& SortType);
	//Ĭ����������
	~SearchYMDRange() = default;

	//ʵ�ֲ��ҡ�����ʹ�ӡ����Ҫ���ܺ���
	vector<Festival::FestivalInThisYear*> PrintFestivals() const;

private:
	YMDDate m_YMDDate1;
	YMDDate m_YMDDate2;
	SortType m_SortType;
};



#endif // !SearchYMDRange_hpp

