/*************************************************************************
【文件名】 Festival.cpp
【功能模块和目的】 维护Festival类，集中编写Festival类成员函数的定义。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 Festival【函数功能】 带参数的构造函数，按照名称构造节日
【参数】 输入参数sName
【返回值】 构造函数，无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
Festival::Festival(const string& sName) :Name(m_Name) {
    m_Name = sName;
}

/*************************************************************************
【函数名称】 Del【函数功能】 删除节日
【参数】 输入参数sName
【返回值】 bool，删除成功返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool Festival::Del(const string& sName) {
    //迭代器
    vector<Festival*>::iterator n = m_All.begin();
    //遍历查找，找到删除
    for (n; n != m_All.end();n++) {
        if ((*n)->Name == sName) {
            delete* n;
            (*n) = nullptr;
            n = m_All.erase(n);
            return true;
        }
    }
    throw invalid_argument("不存在该节日，删除失败。");
    return false;
}

/*************************************************************************
【函数名称】 Clear【函数功能】 清除动态内存
【参数】 无
【返回值】 无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
void Festival::Clear() {
    for (auto& n : m_All) {
        delete n;
        n = nullptr;
    }
    m_All.clear();
}

/*************************************************************************
【函数名称】 GetFestivalName【函数功能】 获取节日名称
【参数】 无
【返回值】 string m_Name，节日名称
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
string Festival::GetFestivalName() const {
    return m_Name;
}

/*************************************************************************
【函数名称】 ModifyName【函数功能】 修改名称
【参数】 输入参数sOldName, 输入参数sNewName
【返回值】 bool，修改成功返回true
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
bool Festival::ModifyName(const string& sOldName, const string& sNewName) {
    SearchFestivalByName(sOldName)->m_Name = sNewName;
    return true;
}

/*************************************************************************
【函数名称】 SearchFestivalByName【函数功能】 按名称查找节日
【参数】 输入参数sTargetName
【返回值】 Festival*指针，可以访问到目标节日
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
Festival* Festival::SearchFestivalByName(const string& sTargetName) {
    for (auto& n : m_All) {
        if (n->Name == sTargetName) {
            return n;
        }
    }
    throw invalid_argument("不存在该节日。");
}

/*************************************************************************
【函数名称】 FestivalInThisYear::FestivalInThisYear【函数功能】 内嵌类构造函数
【参数】 输入参数sName，YMDDate，uDaysInTotal
【返回值】 构造函数，无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
Festival::FestivalInThisYear::FestivalInThisYear(const string& sName
                , const YMDDate& YMDDate, const unsigned int& uDaysInTotal) :
    m_Name(sName), m_YMDDate(YMDDate), m_DaysInTotal(uDaysInTotal) {
}


/*************************************************************************
【函数名称】 GetFestivalInThisYearList【函数功能】 得到某年的全部节日信息
【参数】 输入参数uYear
【返回值】 vector<Festival::FestivalInThisYear*> FestivalInThisYearList查找结果
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
vector<Festival::FestivalInThisYear*> 
    Festival::GetFestivalInThisYearList(const unsigned int& uYear) {
    //局部变量，存储查找结果
    vector<FestivalInThisYear*> FestivalInThisYearList;

    //遍历m_All，查找节日，分类别处理
    for (auto& n : m_All) {
        //节日为SPECIAL_DATE
        if (n->GetType() == FestivalType::SPECIAL_DATE) {
            //如果该节日在当年
            if (n->GetYMDDate().GetYear() == uYear) {
                FestivalInThisYear* Temp = new FestivalInThisYear(n->Name
                    , n->GetYMDDate(), n->GetYMDDate().DaysPassedInTotal());
                FestivalInThisYearList.push_back(Temp);
            }
        }
        //节日为REGULAR_DATE
        if (n->GetType() == FestivalType::REGULAR_DATE) {
            FestivalInThisYear* Temp = new FestivalInThisYear(n->Name
                , YMDDate(uYear, n->GetMDDate())
                , YMDDate(uYear, n->GetMDDate()).DaysPassedInTotal());
            FestivalInThisYearList.push_back(Temp);
        }
        //节日为REGULAR_WEEKDAY
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
【函数名称】 SaveToFile【函数功能】 存储信息到指定文件
【参数】 输入参数FileName
【返回值】 无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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
【函数名称】 LoadFromFile【函数功能】 读取指定文件内容
【参数】 输入参数FileName
【返回值】 无
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
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


