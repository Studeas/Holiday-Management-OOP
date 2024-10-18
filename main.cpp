/*************************************************************************
【文件名】 main.cpp
【功能模块和目的】 调用Controller的对象，实现软件功能，提供输入输出交互界面。
【开发者及日期】 Studeas，2023.08.02
【更改记录】 无
*************************************************************************/

#include <iostream>
#include "WeekDay.hpp"
#include "Month.hpp"
#include "MDDate.hpp"
#include "YMDDate.hpp"
#include "Festival.hpp"
#include "RegularDateFestival.hpp"
#include "SpecialDateFestival.hpp"
#include "RegularWeekDayFestival.hpp"
#include "SearchYMDRange.hpp"
#include "Controller.hpp"


using namespace std;

int main() {

	//开始提示语
	Controller ctr = Controller("Festivals.txt");

	cout << "欢迎您使用节日管理软件！输入“1”开始使用，输入“0”退出程序。" << endl ;
	cout << "---------------------------------------------------------" 
		 << endl;

	//采用数字进行指令交互，等待进入主页
	int iExitCommand = 1;
	do {
		cin >> iExitCommand;
		if (iExitCommand != 0 && iExitCommand != 1) {
			cout << "您的输入超出范围。输入“1”开始使用，输入“0”退出程序。" << endl;
		}
	} while (iExitCommand != 0 && iExitCommand != 1);

	while (iExitCommand != 0) {

		unsigned int uChoiceNum = 0;

		//首页内容提示
		cout << "---------------------------------------------------------" 
			 << endl;
		cout << "**首页" << endl;
		cout << "本程序的基础功能是进行节日管理。" << endl 
			 << "根据其日期格式，节日可以分为三种类型：" << endl;
		cout << "1. 第一种节日的日期为“某年、某月、某日”的特定日期；" 
			 << endl << "2. 第二种节日的日期为“某月、某日”，一年一次；" << endl 
			 << "3. 第三种节日的日期为“某月、第某个、星期几”，一年一次。"
			 << endl << endl;
		cout << "以下为本程序的基本功能：" << endl;
		cout << "1. 添加节日" << endl;
		cout << "2. 删除节日" << endl;
		cout << "3. 修改节日信息（名称、日期）" << endl;
		cout << "4. 根据“年、月”，打印当月日历及节日" << endl;
		cout << "5. 查询指定“年、月、日”范围内的节日，并排序打印" << endl;
		cout << "6. 查询某未来节日的倒数日" << endl;
		cout << "---------------------------------------------------------" 
			 << endl;

		//输入，选择希望使用的功能
		bool IsValidInput = true;
		do {
			cout << "请输入“1~6”的整数，选择您希望使用的功能。"
				 << "输入“0”即可退出程序。" << endl;
			cin >> uChoiceNum;
			if (uChoiceNum < 0 || uChoiceNum > 6) {
				IsValidInput = false;
				cout << "您的输入超出范围。";
			}
			else {
				IsValidInput = true;
			}
		} while (!IsValidInput);
		cout << "---------------------------------------------------------"
			<< endl;

		//功能1：增加节日
		if (uChoiceNum == 1) {
			string sNameInput;
			cout << "请输入节日名称（英文）: ";
			cin >> sNameInput;
			int iTypeChoice = 1;
			do {
				cout << "请输入“1~3”的整数,选择节日类型" << endl;
				cin >> iTypeChoice;
				if (iTypeChoice != 1 && iTypeChoice != 2 && iTypeChoice != 3) {
					cout << "您的输入超出范围。";
				}
			} while (iTypeChoice != 1 && iTypeChoice != 2 && iTypeChoice != 3);

			//增加SpecialDateFestival
			if (iTypeChoice == 1) {
				unsigned int uYearInput;
				unsigned int uMonthInput;
				unsigned int uDayInput;
				cout << "请输入“某年、某月、某日”格式的日期。" << endl;
				cout << "年：";
				cin >> uYearInput;
				cout << "月：";
				cin >> uMonthInput;
				cout << "日：";
				cin >> uDayInput;
				ctr.AddFestival(FestivalType::SPECIAL_DATE
					, sNameInput, uYearInput, uMonthInput, uDayInput);				
			}
			//增加RegularDateFestival
			if (iTypeChoice == 2) {
				unsigned int uMonthInput;
				unsigned int uDayInput;
				cout << "请输入“某月、某日”格式的日期。" << endl;
				cout << "月：";
				cin >> uMonthInput;
				cout << "日：";
				cin >> uDayInput;
				ctr.AddFestival(FestivalType::REGULAR_DATE
					, sNameInput, uMonthInput, uDayInput);
				cout << "添加成功！";
			}
			//增加RegularWeekDayFestival
			if (iTypeChoice == 3) {
				unsigned int uMonthInput;
				unsigned int uOrdialInput;
				unsigned int uWeekDayInput;
				cout << "请输入“某月、第某个、星期几”格式的日期。" << endl;
				cout << "月：";
				cin >> uMonthInput;
				cout << "第几个：";
				cin >> uOrdialInput;
				cout << "星期几：";
				cin >> uWeekDayInput;
				ctr.AddFestival(FestivalType::REGULAR_WEEKDAY
					, sNameInput, uMonthInput, uOrdialInput, uWeekDayInput);
				cout << "添加成功！";
			}
		}

		//功能2：删除节日
		if (uChoiceNum == 2) {
			cout << "输入名称，查找并删除指定名称的节日。" << endl;
			cout << "名称：";
			string sTargetName;
			cin >> sTargetName;
			ctr.DelFestival(sTargetName);
		}

		//功能3：修改节日信息（名称、日期）
		if (uChoiceNum == 3) {
			cout << "请选择修改类型：1. 修改名称。 2.修改日期。 " << endl;
			int iModifyType = 1;
			do {
				cin >> iModifyType;
				if (iModifyType != 1 && iModifyType != 2) {
					cout << "您的输入超出范围。请选择排序方法：" 
						 <<  "修改类型：1. 修改名称。 2.修改日期。" << endl;
				}
			} while (iModifyType != 1 && iModifyType != 2);
			//修改名称
			if (iModifyType == 1) {
				cout << "请输入原名称：";
				string sOldName;
				cin >> sOldName;
				cout << "请输入新名称：";
				string sNewName;
				cin >> sNewName;
				ctr.ModifyFestivalName(sOldName, sNewName);
			}
			//修改日期
			if (iModifyType == 2) {
				cout << "请输入欲修改日期的节日名称：";
				string sName;
				cin >> sName;
				Festival* pSearchRes = Festival::SearchFestivalByName(sName);
				//修改RegularDateFestival节日
				if (pSearchRes->GetType() == FestivalType::REGULAR_DATE) {
					unsigned int uMonthInput;
					unsigned int uDayInput;
					cout << "请输入“某月、某日”格式的新日期。" << endl;
					cout << "月：";
					cin >> uMonthInput;
					cout << "日：";
					cin >> uDayInput;
					ctr.ModifyFestivalTime(FestivalType::REGULAR_DATE
						, sName, uMonthInput, uDayInput);
				}
				//修改RegularWeekDateFestival节日
				if (pSearchRes->GetType() == FestivalType::REGULAR_WEEKDAY) {
					unsigned int uMonthInput;
					unsigned int uOrdialInput;
					unsigned int uWeekDayInput;
					cout << "请输入“某月、第某个、星期几”格式的新日期。" << endl;
					cout << "月：";
					cin >> uMonthInput;
					cout << "第几个：";
					cin >> uOrdialInput;
					cout << "星期几：";
					cin >> uWeekDayInput;
					ctr.ModifyFestivalTime(FestivalType::REGULAR_WEEKDAY
						, sName, uMonthInput, uOrdialInput, uWeekDayInput);
				}
				//修改SpecialDateFestival节日
				if (pSearchRes->GetType() == FestivalType::SPECIAL_DATE) {
					unsigned int uYearInput;
					unsigned int uMonthInput;
					unsigned int uDayInput;
					cout << "请输入“某年、某月、某日”格式的新日期。" << endl;
					cout << "年：";
					cin >> uYearInput;
					cout << "月：";
					cin >> uMonthInput;
					cout << "日：";
					cin >> uDayInput;
					ctr.ModifyFestivalTime(FestivalType::SPECIAL_DATE
						, sName, uYearInput, uMonthInput, uDayInput);
				}
			}
		}

		//功能4：根据“年、月”，打印当月日历及节日
		if (uChoiceNum == 4) {
			cout << "请输入“年、月”日期，打印当月月历、当月节日。" << endl;
			unsigned int uYearInput;
			unsigned int uMonthInput;
			cout << "年：";
			cin >> uYearInput;
			cout << "月：";
			cin >> uMonthInput;
			ctr.MonthCalendar(uYearInput, uMonthInput);
		}

		//功能5：查询指定“年、月、日”范围内的节日，并排序打印
		if (uChoiceNum == 5) {
			cout << "请输入两个“年、月、日”日期，并自选排序方法，打印此期间的所有节日。"
				 << endl;
			unsigned int uYearInput1;
			unsigned int uMonthInput1;
			unsigned int uDayInput1;
			cout << "年1：";
			cin >> uYearInput1;
			cout << "月1：";
			cin >> uMonthInput1;
			cout << "日1：";
			cin >> uDayInput1;
			unsigned int uYearInput2;
			unsigned int uMonthInput2;
			unsigned int uDayInput2;
			cout << "年2：";
			cin >> uYearInput2;
			cout << "月2：";
			cin >> uMonthInput2;
			cout << "日2：";
			cin >> uDayInput2;
			YMDDate YMDDate1(uYearInput1, uMonthInput1, uDayInput1);
			YMDDate YMDDate2(uYearInput2, uMonthInput2, uDayInput2);

			int iSortType = 1;
			cout << "请选择排序方法：1. 按照日期升序。 2. 按照名称首字母升序。" 
				 << endl;
			do {
				cin >> iSortType;
				if (iSortType != 1 && iSortType != 2) {
					cout << "您的输入超出范围。请选择排序方法：1. 按照日期升序。"
						 <<" 2. 按照名称首字母升序。" << endl;
				}
			} while (iSortType != 1 && iSortType != 2);

			if (iSortType == 1) {
				ctr.SearchAndSortFestival(YMDDate1, YMDDate2, SortType::BY_DATE);
			}
			if (iSortType == 2) {
				ctr.SearchAndSortFestival(YMDDate1, YMDDate2, SortType::BY_NAME);
			}
		}
		//功能6：查询某未来节日的倒数日
		if (uChoiceNum == 6) {
			cout << "请输入某未来的节日名称，查看该节日的倒计时。" << endl;
			cout << "名称：";
			string sNameInput;
			cin >> sNameInput;
			ctr.CountDownFestival(sNameInput);
			cout << endl;
		}

		//循环出口：输入0，直接退出程序
		if (uChoiceNum == 0) {
			break;
		}


		cout << "输入“0”退出，输入其他数字继续..." << endl;
		cin >> iExitCommand;
	}
	return 0;
}
	
