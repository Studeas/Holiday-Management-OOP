/*************************************************************************
【文件名】 Controller.cpp
【功能模块和目的】 维护Controller类，集中编写Controller类成员函数的定义。
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/

#include "Controller.hpp"
#include <iomanip>

/*************************************************************************
【函数名称】 Controller【函数功能】 构造函数
【参数】 const string& FestivalsFileName，输入参数，文件名，用来构造ctr对象。
【返回值】 构造函数
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
Controller::Controller(const string& sFestivalsFileName) {
	m_sFestivalsFileName = sFestivalsFileName;
	Festival::LoadFromFile(m_sFestivalsFileName);
}

/*************************************************************************
【函数名称】 ~Controller【函数功能】 析构函数
【参数】 无
【返回值】 析构函数
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
Controller::~Controller() {
	Festival::SaveToFile(m_sFestivalsFileName);
}

/*************************************************************************
【函数名称】 AddFestival【函数功能】 三种类型通用的节日添加函数
【参数】 输入参数UsersChoice，输入参数sFestivalName，输入参数uTimeNum1
		，输入参数uTimeNum1，输入参数uTimeNum3
【返回值】 RES::ADDFESTIVAL_OK，表示添加成功
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
RES Controller::AddFestival(const FestivalType& UsersChoice, 
	                        const string& sFestivalName,
	                        const unsigned int& uTimeNum1,
	                        const unsigned int& uTimeNum2, 
	                        const unsigned int& uTimeNum3) const {
	try {
		//添加REGULAR_DATE类型的节日
		if (UsersChoice == FestivalType::REGULAR_DATE) {
			RegularDateFestival::Add(sFestivalName
				, MDDate(uTimeNum1, uTimeNum2));
			return RES::ADDFESTIVAL_OK;
			cout << "添加成功！" << endl;
		}
		//添加REGULAR_WEEKDAY类型的节日
		if (UsersChoice == FestivalType::REGULAR_WEEKDAY) {
			RegularWeekDayFestival::Add(sFestivalName
				, MOWeekDay(uTimeNum1, uTimeNum2, uTimeNum3));
			return RES::ADDFESTIVAL_OK;
			cout << "添加成功！" << endl;
		}
		//添加SPECIAL_DATE类型的节日
		if (UsersChoice == FestivalType::SPECIAL_DATE) {
			SpecialDateFestival::Add(sFestivalName
				, YMDDate(uTimeNum1, uTimeNum2, uTimeNum3));
			return RES::ADDFESTIVAL_OK;
			cout << "添加成功！" << endl;
		}
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
		return RES::ADDFESTIVAL_FAIL;
	}
}

/*************************************************************************
【函数名称】 DelFestival【函数功能】 删除节日
【参数】 输入参数sFestivalName
【返回值】 RES::DELETE_OK，添加成功
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
RES Controller::DelFestival(const string& sFestivalName) const{
	try {
		Festival::Del(sFestivalName);
		cout << "删除成功！" << endl;
		return RES::DELETE_OK;
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
		return RES::DELETE_FAIL;
	}
}

/*************************************************************************
【函数名称】 ModifyFestivalName【函数功能】 修改节日名称
【参数】 输入参数sFestivalName，输入参数sNewName
【返回值】 RES::MODIFYNAME_OK，名称修改成功
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
RES Controller::ModifyFestivalName(const string& sFestivalName, 
	                               const string& sNewName) const {
	try {
		Festival::SearchFestivalByName(sFestivalName)->ModifyName(sFestivalName, sNewName);
		cout << "修改成功！" << endl;
		return RES::MODIFYNAME_OK;
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
		return RES::MODIFYNAME_FAIL;
	}

}

/*************************************************************************
【函数名称】 ModifyFestivalTime【函数功能】 修改节日时间
【参数】 输入参数ResFestivalType，输入参数sFestivalName，输入参数uTimeNum1
		，输入参数uTimeNum1，输入参数uTimeNum3
【返回值】 RES::MODIFYTIME_OK，修改时间成功
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
RES Controller::ModifyFestivalTime(const FestivalType& ResFestivalType, 
	                               const string& sFestivalName,
	                               const unsigned int& uTimeNum1, 
	                               const unsigned int& uTimeNum2, 
	                               const unsigned int& uTimeNum3) const {
	try {
		//得到查询结果的指针
		Festival* pMyFestival = Festival::SearchFestivalByName(sFestivalName);
		//修改REGULAR_DATE类型的节日
		if (ResFestivalType == FestivalType::REGULAR_DATE) {
			pMyFestival->ModifyMDDate(uTimeNum1, uTimeNum2);
			cout << "修改成功！" << endl;
			return RES::MODIFYTIME_OK;
		}
		//修改REGULAR_WEEKDAY类型的节日
		if (ResFestivalType == FestivalType::REGULAR_WEEKDAY) {
			pMyFestival->ModifyMOWeekDay(uTimeNum1, uTimeNum2, uTimeNum3);
			cout << "修改成功！" << endl;
			return RES::MODIFYTIME_OK;
		}
		//修改SPECIAL_DATE类型的节日
		if (ResFestivalType == FestivalType::SPECIAL_DATE) {
			pMyFestival->ModifyYMDDate(uTimeNum1, uTimeNum2, uTimeNum3);
			cout << "修改成功！" << endl;
			return RES::MODIFYTIME_OK;
		}
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
		return RES::MODIFYTIME_FAIL;
	}
}

/*************************************************************************
【函数名称】 MonthCalendar【函数功能】 指定“某年某月”，打印当月月历和节日的函数
【参数】 输入参数uYear，输入参数uMonth
【返回值】 RES::MONCALPRINT_OK，日历生成成功
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
RES Controller::MonthCalendar(const unsigned int& uYear, 
	                          const unsigned int& uMonth) const {
	try {
		MonthCalendarPrinter MCP(uYear, uMonth);
		//打印月历
		MCP.PrintCalendar(uYear, uMonth);

		//打印节日
		MCP.PrintFestivals(uYear, uMonth);

		cout << "打印成功！" << endl;
		cout << "********************************************************* "
			<< endl << endl;
		return RES::MONCALPRINT_OK;
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
		return RES::MONCALPRINT_FAIL;
	}
}

/*************************************************************************
【函数名称】 SearchAndSortFestival【函数功能】 指定“年月日”范围
			，按照自定义的排序方式打印此时间范围内的节日
【参数】 输入参数YMDDate1，输入参数YMDDate2，输入参数SortType
【返回值】 RES::SEARCHSORT_OK，查找生成list成功
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
RES Controller::SearchAndSortFestival(const YMDDate& YMDDate1, 
	                                  const YMDDate& YMDDate2, 
	                                  const SortType& SortType) const {
	try {
		SearchYMDRange SYMDR(YMDDate1, YMDDate2, SortType);

		//查询并打印日期区间内的节日，按照SortType的排序方式
		SYMDR.PrintFestivals();
		return RES::SEARCHSORT_OK;
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
		return RES::SEARCHSORT_FAIL;
	}
}

/*************************************************************************
【函数名称】 CountDownFestival【函数功能】 按名称查找并打印对应节日的倒数日
【参数】 输入参数sTargetName
【返回值】 RES::PAST_FESTIVAL节日已过，RES::COUNTDOWN_OK倒数日生成成功
			，RES::INEXISTENT_NAME不存在的节日名称，查找失败;
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/
RES Controller::CountDownFestival(const string& sTargetName) const{
	try{ 
		//按名称查找节日和节日类型
		Festival* SearchRes = Festival::SearchFestivalByName(sTargetName); 
		FestivalType TypeRes = SearchRes->GetType();

		//打印SPECIAL_DATE类型的节日倒数日
		if (TypeRes == FestivalType::SPECIAL_DATE) {
			//该节日的总天数
			unsigned int uSrchResDaysInTotal 
				= SearchRes->GetYMDDate().DaysPassedInTotal();
			//今天的总天数
			unsigned int uTodayDaysInTotal 
				= YMDDate::Today().DaysPassedInTotal();

			//如果该节日还没过，打印倒数日
			if (uSrchResDaysInTotal >= uTodayDaysInTotal) {
				cout << SearchRes->GetFestivalName() << "节距今日还有"
					<< uSrchResDaysInTotal - uTodayDaysInTotal 
					<< "天。" << endl;
				return RES::COUNTDOWN_OK;
			}
			//如果该节日已过，打印提示语，结束
			else {
				cout << SearchRes->GetFestivalName() << "节已过。" << endl;
				return RES::PAST_FESTIVAL;
			}
		}

		//打印REGULAR_DATE类型的节日倒数日
		if (TypeRes == FestivalType::REGULAR_DATE) {
			//今年的该节日的总天数
			unsigned int uSrchResThisYDaysTtl
				= YMDDate(YMDDate::Today().GetYear()
				, SearchRes->GetMDDate()).DaysPassedInTotal();
			//今天的总天数
			unsigned int uTodayDaysInTotal
				= YMDDate::Today().DaysPassedInTotal();

			//如果今年的该节日还没过，直接打印倒数日
			if (uSrchResThisYDaysTtl >= uTodayDaysInTotal) {
				cout << "最近一次" << SearchRes->GetFestivalName() 
					 << "节距今日还有"
					 << uSrchResThisYDaysTtl - uTodayDaysInTotal << "天。";
				return RES::COUNTDOWN_OK;
			}
			//如果今年的节日已过，使用明年的该节日计算倒数日
			else {
				unsigned int uSrchResNxtYDaysTtl 
					= YMDDate(YMDDate::Today().GetYear() + 1
						, SearchRes->GetMDDate()).DaysPassedInTotal();
				cout << "最近一次" << SearchRes->GetFestivalName() 
					 << "节距今日还有"
					 << uSrchResNxtYDaysTtl - uTodayDaysInTotal << "天。";
				return RES::COUNTDOWN_OK;
			}
		}

		//打印REGULAR_WEEKDAY类型的节日倒数日
		if (TypeRes == FestivalType::REGULAR_WEEKDAY) {
			//今年的该节日的总天数
			unsigned int uSrchResThisYDaysTtl 
				= YMDDate::YMOWeekDayToYMDDate(YMDDate::Today().GetYear()
					, SearchRes->GetMOWeekDay().GetMonthValue()
					, SearchRes->GetMOWeekDay().GetOrdial()
					, SearchRes->GetMOWeekDay().GetWeekDayActualValue()).DaysPassedInTotal();
			//今天的总天数
			unsigned int uTodayDaysInTotal = YMDDate::Today().DaysPassedInTotal();

			//如果今年的该节日还没过，直接打印倒数日
			if (uSrchResThisYDaysTtl >= uTodayDaysInTotal) {
				cout << "最近一次" << SearchRes->GetFestivalName() << "节距今日还有"
					 << uSrchResThisYDaysTtl - uTodayDaysInTotal << "天。";
				cout << endl;
				return RES::COUNTDOWN_OK;
			}
			//如果今年的节日已过，使用明年的该节日计算倒数日
			else {
				unsigned int SearchResNextYearDaysInTotal
					= YMDDate::YMOWeekDayToYMDDate(YMDDate::Today().GetYear() + 1
						, SearchRes->GetMOWeekDay().GetMonthValue()
						, SearchRes->GetMOWeekDay().GetOrdial()
						, SearchRes->GetMOWeekDay().GetWeekDayActualValue()).DaysPassedInTotal();

				cout << "最近一次" << SearchRes->GetFestivalName() << "节距今日还有"
					 << SearchResNextYearDaysInTotal - uTodayDaysInTotal << "天。";
				cout << endl;
				return RES::COUNTDOWN_OK;
			}
		}
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
		return RES::INEXISTENT_NAME;
	}
}
