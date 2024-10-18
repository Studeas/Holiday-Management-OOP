/*************************************************************************
���ļ����� main.cpp
������ģ���Ŀ�ġ� ����Controller�Ķ���ʵ��������ܣ��ṩ��������������档
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
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

	//��ʼ��ʾ��
	Controller ctr = Controller("Festivals.txt");

	cout << "��ӭ��ʹ�ý��չ�����������롰1����ʼʹ�ã����롰0���˳�����" << endl ;
	cout << "---------------------------------------------------------" 
		 << endl;

	//�������ֽ���ָ������ȴ�������ҳ
	int iExitCommand = 1;
	do {
		cin >> iExitCommand;
		if (iExitCommand != 0 && iExitCommand != 1) {
			cout << "�������볬����Χ�����롰1����ʼʹ�ã����롰0���˳�����" << endl;
		}
	} while (iExitCommand != 0 && iExitCommand != 1);

	while (iExitCommand != 0) {

		unsigned int uChoiceNum = 0;

		//��ҳ������ʾ
		cout << "---------------------------------------------------------" 
			 << endl;
		cout << "**��ҳ" << endl;
		cout << "������Ļ��������ǽ��н��չ���" << endl 
			 << "���������ڸ�ʽ�����տ��Է�Ϊ�������ͣ�" << endl;
		cout << "1. ��һ�ֽ��յ�����Ϊ��ĳ�ꡢĳ�¡�ĳ�ա����ض����ڣ�" 
			 << endl << "2. �ڶ��ֽ��յ�����Ϊ��ĳ�¡�ĳ�ա���һ��һ�Σ�" << endl 
			 << "3. �����ֽ��յ�����Ϊ��ĳ�¡���ĳ�������ڼ�����һ��һ�Ρ�"
			 << endl << endl;
		cout << "����Ϊ������Ļ������ܣ�" << endl;
		cout << "1. ��ӽ���" << endl;
		cout << "2. ɾ������" << endl;
		cout << "3. �޸Ľ�����Ϣ�����ơ����ڣ�" << endl;
		cout << "4. ���ݡ��ꡢ�¡�����ӡ��������������" << endl;
		cout << "5. ��ѯָ�����ꡢ�¡��ա���Χ�ڵĽ��գ��������ӡ" << endl;
		cout << "6. ��ѯĳδ�����յĵ�����" << endl;
		cout << "---------------------------------------------------------" 
			 << endl;

		//���룬ѡ��ϣ��ʹ�õĹ���
		bool IsValidInput = true;
		do {
			cout << "�����롰1~6����������ѡ����ϣ��ʹ�õĹ��ܡ�"
				 << "���롰0�������˳�����" << endl;
			cin >> uChoiceNum;
			if (uChoiceNum < 0 || uChoiceNum > 6) {
				IsValidInput = false;
				cout << "�������볬����Χ��";
			}
			else {
				IsValidInput = true;
			}
		} while (!IsValidInput);
		cout << "---------------------------------------------------------"
			<< endl;

		//����1�����ӽ���
		if (uChoiceNum == 1) {
			string sNameInput;
			cout << "������������ƣ�Ӣ�ģ�: ";
			cin >> sNameInput;
			int iTypeChoice = 1;
			do {
				cout << "�����롰1~3��������,ѡ���������" << endl;
				cin >> iTypeChoice;
				if (iTypeChoice != 1 && iTypeChoice != 2 && iTypeChoice != 3) {
					cout << "�������볬����Χ��";
				}
			} while (iTypeChoice != 1 && iTypeChoice != 2 && iTypeChoice != 3);

			//����SpecialDateFestival
			if (iTypeChoice == 1) {
				unsigned int uYearInput;
				unsigned int uMonthInput;
				unsigned int uDayInput;
				cout << "�����롰ĳ�ꡢĳ�¡�ĳ�ա���ʽ�����ڡ�" << endl;
				cout << "�꣺";
				cin >> uYearInput;
				cout << "�£�";
				cin >> uMonthInput;
				cout << "�գ�";
				cin >> uDayInput;
				ctr.AddFestival(FestivalType::SPECIAL_DATE
					, sNameInput, uYearInput, uMonthInput, uDayInput);				
			}
			//����RegularDateFestival
			if (iTypeChoice == 2) {
				unsigned int uMonthInput;
				unsigned int uDayInput;
				cout << "�����롰ĳ�¡�ĳ�ա���ʽ�����ڡ�" << endl;
				cout << "�£�";
				cin >> uMonthInput;
				cout << "�գ�";
				cin >> uDayInput;
				ctr.AddFestival(FestivalType::REGULAR_DATE
					, sNameInput, uMonthInput, uDayInput);
				cout << "��ӳɹ���";
			}
			//����RegularWeekDayFestival
			if (iTypeChoice == 3) {
				unsigned int uMonthInput;
				unsigned int uOrdialInput;
				unsigned int uWeekDayInput;
				cout << "�����롰ĳ�¡���ĳ�������ڼ�����ʽ�����ڡ�" << endl;
				cout << "�£�";
				cin >> uMonthInput;
				cout << "�ڼ�����";
				cin >> uOrdialInput;
				cout << "���ڼ���";
				cin >> uWeekDayInput;
				ctr.AddFestival(FestivalType::REGULAR_WEEKDAY
					, sNameInput, uMonthInput, uOrdialInput, uWeekDayInput);
				cout << "��ӳɹ���";
			}
		}

		//����2��ɾ������
		if (uChoiceNum == 2) {
			cout << "�������ƣ����Ҳ�ɾ��ָ�����ƵĽ��ա�" << endl;
			cout << "���ƣ�";
			string sTargetName;
			cin >> sTargetName;
			ctr.DelFestival(sTargetName);
		}

		//����3���޸Ľ�����Ϣ�����ơ����ڣ�
		if (uChoiceNum == 3) {
			cout << "��ѡ���޸����ͣ�1. �޸����ơ� 2.�޸����ڡ� " << endl;
			int iModifyType = 1;
			do {
				cin >> iModifyType;
				if (iModifyType != 1 && iModifyType != 2) {
					cout << "�������볬����Χ����ѡ�����򷽷���" 
						 <<  "�޸����ͣ�1. �޸����ơ� 2.�޸����ڡ�" << endl;
				}
			} while (iModifyType != 1 && iModifyType != 2);
			//�޸�����
			if (iModifyType == 1) {
				cout << "������ԭ���ƣ�";
				string sOldName;
				cin >> sOldName;
				cout << "�����������ƣ�";
				string sNewName;
				cin >> sNewName;
				ctr.ModifyFestivalName(sOldName, sNewName);
			}
			//�޸�����
			if (iModifyType == 2) {
				cout << "���������޸����ڵĽ������ƣ�";
				string sName;
				cin >> sName;
				Festival* pSearchRes = Festival::SearchFestivalByName(sName);
				//�޸�RegularDateFestival����
				if (pSearchRes->GetType() == FestivalType::REGULAR_DATE) {
					unsigned int uMonthInput;
					unsigned int uDayInput;
					cout << "�����롰ĳ�¡�ĳ�ա���ʽ�������ڡ�" << endl;
					cout << "�£�";
					cin >> uMonthInput;
					cout << "�գ�";
					cin >> uDayInput;
					ctr.ModifyFestivalTime(FestivalType::REGULAR_DATE
						, sName, uMonthInput, uDayInput);
				}
				//�޸�RegularWeekDateFestival����
				if (pSearchRes->GetType() == FestivalType::REGULAR_WEEKDAY) {
					unsigned int uMonthInput;
					unsigned int uOrdialInput;
					unsigned int uWeekDayInput;
					cout << "�����롰ĳ�¡���ĳ�������ڼ�����ʽ�������ڡ�" << endl;
					cout << "�£�";
					cin >> uMonthInput;
					cout << "�ڼ�����";
					cin >> uOrdialInput;
					cout << "���ڼ���";
					cin >> uWeekDayInput;
					ctr.ModifyFestivalTime(FestivalType::REGULAR_WEEKDAY
						, sName, uMonthInput, uOrdialInput, uWeekDayInput);
				}
				//�޸�SpecialDateFestival����
				if (pSearchRes->GetType() == FestivalType::SPECIAL_DATE) {
					unsigned int uYearInput;
					unsigned int uMonthInput;
					unsigned int uDayInput;
					cout << "�����롰ĳ�ꡢĳ�¡�ĳ�ա���ʽ�������ڡ�" << endl;
					cout << "�꣺";
					cin >> uYearInput;
					cout << "�£�";
					cin >> uMonthInput;
					cout << "�գ�";
					cin >> uDayInput;
					ctr.ModifyFestivalTime(FestivalType::SPECIAL_DATE
						, sName, uYearInput, uMonthInput, uDayInput);
				}
			}
		}

		//����4�����ݡ��ꡢ�¡�����ӡ��������������
		if (uChoiceNum == 4) {
			cout << "�����롰�ꡢ�¡����ڣ���ӡ�������������½��ա�" << endl;
			unsigned int uYearInput;
			unsigned int uMonthInput;
			cout << "�꣺";
			cin >> uYearInput;
			cout << "�£�";
			cin >> uMonthInput;
			ctr.MonthCalendar(uYearInput, uMonthInput);
		}

		//����5����ѯָ�����ꡢ�¡��ա���Χ�ڵĽ��գ��������ӡ
		if (uChoiceNum == 5) {
			cout << "�������������ꡢ�¡��ա����ڣ�����ѡ���򷽷�����ӡ���ڼ�����н��ա�"
				 << endl;
			unsigned int uYearInput1;
			unsigned int uMonthInput1;
			unsigned int uDayInput1;
			cout << "��1��";
			cin >> uYearInput1;
			cout << "��1��";
			cin >> uMonthInput1;
			cout << "��1��";
			cin >> uDayInput1;
			unsigned int uYearInput2;
			unsigned int uMonthInput2;
			unsigned int uDayInput2;
			cout << "��2��";
			cin >> uYearInput2;
			cout << "��2��";
			cin >> uMonthInput2;
			cout << "��2��";
			cin >> uDayInput2;
			YMDDate YMDDate1(uYearInput1, uMonthInput1, uDayInput1);
			YMDDate YMDDate2(uYearInput2, uMonthInput2, uDayInput2);

			int iSortType = 1;
			cout << "��ѡ�����򷽷���1. ������������ 2. ������������ĸ����" 
				 << endl;
			do {
				cin >> iSortType;
				if (iSortType != 1 && iSortType != 2) {
					cout << "�������볬����Χ����ѡ�����򷽷���1. ������������"
						 <<" 2. ������������ĸ����" << endl;
				}
			} while (iSortType != 1 && iSortType != 2);

			if (iSortType == 1) {
				ctr.SearchAndSortFestival(YMDDate1, YMDDate2, SortType::BY_DATE);
			}
			if (iSortType == 2) {
				ctr.SearchAndSortFestival(YMDDate1, YMDDate2, SortType::BY_NAME);
			}
		}
		//����6����ѯĳδ�����յĵ�����
		if (uChoiceNum == 6) {
			cout << "������ĳδ���Ľ������ƣ��鿴�ý��յĵ���ʱ��" << endl;
			cout << "���ƣ�";
			string sNameInput;
			cin >> sNameInput;
			ctr.CountDownFestival(sNameInput);
			cout << endl;
		}

		//ѭ�����ڣ�����0��ֱ���˳�����
		if (uChoiceNum == 0) {
			break;
		}


		cout << "���롰0���˳��������������ּ���..." << endl;
		cin >> iExitCommand;
	}
	return 0;
}
	
