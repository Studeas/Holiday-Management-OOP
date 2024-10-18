/*************************************************************************
���ļ����� Festival.cpp
������ģ���Ŀ�ġ� ά��Festival�࣬���б�дFestival���Ա�����Ķ��塣
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/

#include "Festival.hpp"
#include<iostream>
#include <stdexcept>
#include <fstream>
#include "RegularDateFestival.hpp"
#include "RegularWeekDayFestival.hpp"
#include "SpecialDateFestival.hpp"

vector<Festival*> Festival::m_All{};
Festival::Garbo Festival::m_Garbo{};

/*************************************************************************
���������ơ� Festival���������ܡ� �������Ĺ��캯�����������ƹ������
�������� �������sName
������ֵ�� ���캯������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
Festival::Festival(const string& sName) :Name(m_Name) {
    m_Name = sName;
}

/*************************************************************************
���������ơ� Del���������ܡ� ɾ������
�������� �������sName
������ֵ�� bool��ɾ���ɹ�����true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool Festival::Del(const string& sName) {
    //������
    vector<Festival*>::iterator n = m_All.begin();
    //�������ң��ҵ�ɾ��
    for (n; n != m_All.end();n++) {
        if ((*n)->Name == sName) {
            delete* n;
            (*n) = nullptr;
            n = m_All.erase(n);
            return true;
        }
    }
    throw invalid_argument("�����ڸý��գ�ɾ��ʧ�ܡ�");
    return false;
}

/*************************************************************************
���������ơ� Clear���������ܡ� �����̬�ڴ�
�������� ��
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void Festival::Clear() {
    for (auto& n : m_All) {
        delete n;
        n = nullptr;
    }
    m_All.clear();
}

/*************************************************************************
���������ơ� GetFestivalName���������ܡ� ��ȡ��������
�������� ��
������ֵ�� string m_Name����������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
string Festival::GetFestivalName() const {
    return m_Name;
}

/*************************************************************************
���������ơ� ModifyName���������ܡ� �޸�����
�������� �������sOldName, �������sNewName
������ֵ�� bool���޸ĳɹ�����true
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
bool Festival::ModifyName(const string& sOldName, const string& sNewName) {
    SearchFestivalByName(sOldName)->m_Name = sNewName;
    return true;
}

/*************************************************************************
���������ơ� SearchFestivalByName���������ܡ� �����Ʋ��ҽ���
�������� �������sTargetName
������ֵ�� Festival*ָ�룬���Է��ʵ�Ŀ�����
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
Festival* Festival::SearchFestivalByName(const string& sTargetName) {
    for (auto& n : m_All) {
        if (n->Name == sTargetName) {
            return n;
        }
    }
    throw invalid_argument("�����ڸý��ա�");
}

/*************************************************************************
���������ơ� FestivalInThisYear::FestivalInThisYear���������ܡ� ��Ƕ�๹�캯��
�������� �������sName��YMDDate��uDaysInTotal
������ֵ�� ���캯������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
Festival::FestivalInThisYear::FestivalInThisYear(const string& sName
                , const YMDDate& YMDDate, const unsigned int& uDaysInTotal) :
    m_Name(sName), m_YMDDate(YMDDate), m_DaysInTotal(uDaysInTotal) {
}


/*************************************************************************
���������ơ� GetFestivalInThisYearList���������ܡ� �õ�ĳ���ȫ��������Ϣ
�������� �������uYear
������ֵ�� vector<Festival::FestivalInThisYear*> FestivalInThisYearList���ҽ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
vector<Festival::FestivalInThisYear*> 
    Festival::GetFestivalInThisYearList(const unsigned int& uYear) {
    //�ֲ��������洢���ҽ��
    vector<FestivalInThisYear*> FestivalInThisYearList;

    //����m_All�����ҽ��գ��������
    for (auto& n : m_All) {
        //����ΪSPECIAL_DATE
        if (n->GetType() == FestivalType::SPECIAL_DATE) {
            //����ý����ڵ���
            if (n->GetYMDDate().GetYear() == uYear) {
                FestivalInThisYear* Temp = new FestivalInThisYear(n->Name
                    , n->GetYMDDate(), n->GetYMDDate().DaysPassedInTotal());
                FestivalInThisYearList.push_back(Temp);
            }
        }
        //����ΪREGULAR_DATE
        if (n->GetType() == FestivalType::REGULAR_DATE) {
            FestivalInThisYear* Temp = new FestivalInThisYear(n->Name
                , YMDDate(uYear, n->GetMDDate())
                , YMDDate(uYear, n->GetMDDate()).DaysPassedInTotal());
            FestivalInThisYearList.push_back(Temp);
        }
        //����ΪREGULAR_WEEKDAY
        if (n->GetType() == FestivalType::REGULAR_WEEKDAY) {
            YMDDate ThisYearYMD = YMDDate::YMOWeekDayToYMDDate(uYear
                , n->GetMOWeekDay().GetMonthValue()
                , n->GetMOWeekDay().GetOrdial()
                , n->GetMOWeekDay().GetWeekDayActualValue());
            FestivalInThisYear* Temp = new FestivalInThisYear(n->Name
                , ThisYearYMD, ThisYearYMD.DaysPassedInTotal());
            FestivalInThisYearList.push_back(Temp);
        }
    }
    return FestivalInThisYearList;
}

/*************************************************************************
���������ơ� SaveToFile���������ܡ� �洢��Ϣ��ָ���ļ�
�������� �������FileName
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void Festival::SaveToFile(const string& FileName) {
    ofstream File(FileName);
    if (!File.is_open()) {
        throw invalid_argument("Can't open/Create for saving, File : " 
            + FileName);
    }
    File << m_All.size() << endl;
    for (auto& n : m_All) {
        if (n->GetType() == FestivalType::REGULAR_DATE) {
            File << "REGULAR_DATE" << " ";
            File << n->Name << " ";
            File << n->GetMDDate().GetMonthValue() 
                 << " " << n->GetMDDate().GetDay() << endl;
        }
        if (n->GetType() == FestivalType::REGULAR_WEEKDAY) {
            File << "REGULAR_WEEKDAY" << " ";
            File << n->Name << " ";
            File << n->GetMOWeekDay().GetMonthValue() << " " 
                 << n->GetMOWeekDay().GetOrdial() << " " 
                 << n->GetMOWeekDay().GetWeekDayActualValue() << endl;
        }
        if (n->GetType() == FestivalType::SPECIAL_DATE) {
            File << "SPECIAL_DATE" << " ";
            File << n->Name << " ";
            File << n->GetYMDDate().GetYear() << " " 
                 << n->GetYMDDate().GetMonthValue() << " " 
                 << n->GetYMDDate().GetDay() << endl;
        }
    }
    File.close();
}

/*************************************************************************
���������ơ� LoadFromFile���������ܡ� ��ȡָ���ļ�����
�������� �������FileName
������ֵ�� ��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
void Festival::LoadFromFile(const string& FileName) {
    ifstream File(FileName);
    if (!File.is_open()) {
        ofstream NewFile(FileName);
        if (!NewFile.is_open()) {
            throw invalid_argument("Can't open/create for loading, file: " 
                + FileName);
        }
        NewFile << 0 << endl;
        NewFile.close();

        File.open(FileName);
    }
    unsigned int FestivalCount;
    File >> FestivalCount;
    File.get();
    m_All.clear();
    string FestivalTypeName;
    string FestivalName;

    if (FestivalCount > 0) {
        for (unsigned int i = 0; i < FestivalCount; i++) {
            File >> FestivalTypeName >> FestivalName;
            if (FestivalTypeName == "REGULAR_DATE") {
                unsigned int MonthTemp;
                unsigned int DayTemp;
                File >> MonthTemp >> DayTemp;
                RegularDateFestival::Add(FestivalName
                    , MDDate(MonthTemp, DayTemp));
            }
            if (FestivalTypeName == "REGULAR_WEEKDAY") {
                unsigned int MonthTemp;
                unsigned int OrdialTemp;
                unsigned int WeekDayTemp;
                File >> MonthTemp >> OrdialTemp >> WeekDayTemp;
                RegularWeekDayFestival::Add(FestivalName
                    , MOWeekDay(MonthTemp, OrdialTemp, WeekDayTemp));
            }
            if (FestivalTypeName == "SPECIAL_DATE") {
                unsigned int YearTemp;
                unsigned int MonthTemp;
                unsigned int DayTemp;
                File >> YearTemp >> MonthTemp >> DayTemp;
                SpecialDateFestival::Add(FestivalName
                    , YMDDate(YearTemp, MonthTemp, DayTemp));
            }
        }
    }
    File.close();
}


