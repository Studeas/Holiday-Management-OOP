/*************************************************************************
【文件名】 Controller.hpp
【功能模块和目的】 维护Controller类，集中编写Controller类成员函数的声明。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/

#ifndef Controller_hpp
#define Controller_hpp

#include "Month.hpp"
#include "MDDate.hpp"
#include "YMDDate.hpp"
#include "WeekDay.hpp"
#include "MOWeekDay.hpp"
#include "Festival.hpp"
#include "RegularDateFestival.hpp"
#include "RegularWeekDayFestival.hpp"
#include "SpecialDateFestival.hpp"
#include "MonthCalendarPrinter.hpp"
#include "SearchYMDRange.hpp"
#include <iostream>

using namespace std;

/*************************************************************************
【类名】 ControllerRet
【功能】 枚举类型，提供Controller成员函数的返回值。
【接口说明】 不提供接口，只维护成员。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
enum class ControllerRet {
    INEXISTENT_NAME,
    PAST_FESTIVAL,
    COUNTDOWN_OK,
    ADDFESTIVAL_OK,
    ADDFESTIVAL_FAIL,
    DELETE_OK,
    DELETE_FAIL,
    MODIFYNAME_OK,
    MODIFYNAME_FAIL,
    MODIFYTIME_OK,
    MODIFYTIME_FAIL,
    MONCALPRINT_OK,
    MONCALPRINT_FAIL,
    SEARCHSORT_OK,
    SEARCHSORT_FAIL
};

//将RES作为ControllerRet的简化别称
using RES = ControllerRet;

/*************************************************************************
【类名】 Controller
【功能】 封装本节日管理软件6个主要功能，提供可被界面调用的接口。
【接口说明】 除构造析构外，提供7个函数接口，供main.cpp中的ctr对象调用，实现主要功能。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
class Controller {
public:
    Controller() = delete;
    //带参数（文件名）的构造函数
    Controller(const string& sFestivalsFileName);

    //析构函数
    ~Controller();

    //三种类型节日通用的“增加节日”函数
    RES AddFestival(const FestivalType& UsersChoice, 
                    const string& sFestivalName, 
                    const unsigned int& uTimeNum1, 
                    const unsigned int& uTimeNum2, 
                    const unsigned int& uTimeNum3 = 1) const;

    //三种类型节日通用的“删除节日”函数
    RES DelFestival(const string& sFestivalName) const;

    //三种类型节日通用的“修改节日名称”函数
    RES ModifyFestivalName(const string& sFestivalName
                        , const string& sNewName) const;

    //三种类型节日通用的“修改节日时间”函数
    RES ModifyFestivalTime(const FestivalType& UsersChoice, 
                           const string& sFestivalName,
                           const unsigned int& uTimeNum1, 
                           const unsigned int& uTimeNum2, 
                           const unsigned int& uTimeNum3 = 1) const;
   
    //指定“某年某月”，打印当月月历和节日的函数
    RES MonthCalendar(const unsigned int& uYear
                    , const unsigned int& uMonth) const;
    
    //指定“年月日”范围，按照自定义的排序方式打印此时间范围内的节日
    RES SearchAndSortFestival(const YMDDate& YMDDate1, 
                              const YMDDate& YMDDate2, 
                              const SortType& SortType) const;
    
    //按名称查找并打印对应节日的倒数日
    RES CountDownFestival(const string& sTargetName) const;

private:
    string m_sFestivalsFileName;
};

#endif // !Controller_hpp

