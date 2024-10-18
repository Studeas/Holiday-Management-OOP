/*************************************************************************
���ļ����� Controller.hpp
������ģ���Ŀ�ġ� ά��Controller�࣬���б�дController���Ա������������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
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
�������� ControllerRet
�����ܡ� ö�����ͣ��ṩController��Ա�����ķ���ֵ��
���ӿ�˵���� ���ṩ�ӿڣ�ֻά����Ա��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
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

//��RES��ΪControllerRet�ļ򻯱��
using RES = ControllerRet;

/*************************************************************************
�������� Controller
�����ܡ� ��װ�����չ������6����Ҫ���ܣ��ṩ�ɱ�������õĽӿڡ�
���ӿ�˵���� �����������⣬�ṩ7�������ӿڣ���main.cpp�е�ctr������ã�ʵ����Ҫ���ܡ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
class Controller {
public:
    Controller() = delete;
    //���������ļ������Ĺ��캯��
    Controller(const string& sFestivalsFileName);

    //��������
    ~Controller();

    //�������ͽ���ͨ�õġ����ӽ��ա�����
    RES AddFestival(const FestivalType& UsersChoice, 
                    const string& sFestivalName, 
                    const unsigned int& uTimeNum1, 
                    const unsigned int& uTimeNum2, 
                    const unsigned int& uTimeNum3 = 1) const;

    //�������ͽ���ͨ�õġ�ɾ�����ա�����
    RES DelFestival(const string& sFestivalName) const;

    //�������ͽ���ͨ�õġ��޸Ľ������ơ�����
    RES ModifyFestivalName(const string& sFestivalName
                        , const string& sNewName) const;

    //�������ͽ���ͨ�õġ��޸Ľ���ʱ�䡱����
    RES ModifyFestivalTime(const FestivalType& UsersChoice, 
                           const string& sFestivalName,
                           const unsigned int& uTimeNum1, 
                           const unsigned int& uTimeNum2, 
                           const unsigned int& uTimeNum3 = 1) const;
   
    //ָ����ĳ��ĳ�¡�����ӡ���������ͽ��յĺ���
    RES MonthCalendar(const unsigned int& uYear
                    , const unsigned int& uMonth) const;
    
    //ָ���������ա���Χ�������Զ��������ʽ��ӡ��ʱ�䷶Χ�ڵĽ���
    RES SearchAndSortFestival(const YMDDate& YMDDate1, 
                              const YMDDate& YMDDate2, 
                              const SortType& SortType) const;
    
    //�����Ʋ��Ҳ���ӡ��Ӧ���յĵ�����
    RES CountDownFestival(const string& sTargetName) const;

private:
    string m_sFestivalsFileName;
};

#endif // !Controller_hpp

