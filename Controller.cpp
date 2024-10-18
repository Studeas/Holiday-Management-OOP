/*************************************************************************
���ļ����� Controller.cpp
������ģ���Ŀ�ġ� ά��Controller�࣬���б�дController���Ա�����Ķ��塣
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/

#include "Controller.hpp"
#include <iomanip>

/*************************************************************************
���������ơ� Controller���������ܡ� ���캯��
�������� const string& FestivalsFileName������������ļ�������������ctr����
������ֵ�� ���캯��
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
Controller::Controller(const string& sFestivalsFileName) {
	m_sFestivalsFileName = sFestivalsFileName;
	Festival::LoadFromFile(m_sFestivalsFileName);
}

/*************************************************************************
���������ơ� ~Controller���������ܡ� ��������
�������� ��
������ֵ�� ��������
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
Controller::~Controller() {
	Festival::SaveToFile(m_sFestivalsFileName);
}

/*************************************************************************
���������ơ� AddFestival���������ܡ� ��������ͨ�õĽ�����Ӻ���
�������� �������UsersChoice���������sFestivalName���������uTimeNum1
		���������uTimeNum1���������uTimeNum3
������ֵ�� RES::ADDFESTIVAL_OK����ʾ��ӳɹ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
RES Controller::AddFestival(const FestivalType& UsersChoice, 
	                        const string& sFestivalName,
	                        const unsigned int& uTimeNum1,
	                        const unsigned int& uTimeNum2, 
	                        const unsigned int& uTimeNum3) const {
	try {
		//���REGULAR_DATE���͵Ľ���
		if (UsersChoice == FestivalType::REGULAR_DATE) {
			RegularDateFestival::Add(sFestivalName
				, MDDate(uTimeNum1, uTimeNum2));
			return RES::ADDFESTIVAL_OK;
			cout << "��ӳɹ���" << endl;
		}
		//���REGULAR_WEEKDAY���͵Ľ���
		if (UsersChoice == FestivalType::REGULAR_WEEKDAY) {
			RegularWeekDayFestival::Add(sFestivalName
				, MOWeekDay(uTimeNum1, uTimeNum2, uTimeNum3));
			return RES::ADDFESTIVAL_OK;
			cout << "��ӳɹ���" << endl;
		}
		//���SPECIAL_DATE���͵Ľ���
		if (UsersChoice == FestivalType::SPECIAL_DATE) {
			SpecialDateFestival::Add(sFestivalName
				, YMDDate(uTimeNum1, uTimeNum2, uTimeNum3));
			return RES::ADDFESTIVAL_OK;
			cout << "��ӳɹ���" << endl;
		}
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
		return RES::ADDFESTIVAL_FAIL;
	}
}

/*************************************************************************
���������ơ� DelFestival���������ܡ� ɾ������
�������� �������sFestivalName
������ֵ�� RES::DELETE_OK����ӳɹ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
RES Controller::DelFestival(const string& sFestivalName) const{
	try {
		Festival::Del(sFestivalName);
		cout << "ɾ���ɹ���" << endl;
		return RES::DELETE_OK;
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
		return RES::DELETE_FAIL;
	}
}

/*************************************************************************
���������ơ� ModifyFestivalName���������ܡ� �޸Ľ�������
�������� �������sFestivalName���������sNewName
������ֵ�� RES::MODIFYNAME_OK�������޸ĳɹ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
RES Controller::ModifyFestivalName(const string& sFestivalName, 
	                               const string& sNewName) const {
	try {
		Festival::SearchFestivalByName(sFestivalName)->ModifyName(sFestivalName, sNewName);
		cout << "�޸ĳɹ���" << endl;
		return RES::MODIFYNAME_OK;
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
		return RES::MODIFYNAME_FAIL;
	}

}

/*************************************************************************
���������ơ� ModifyFestivalTime���������ܡ� �޸Ľ���ʱ��
�������� �������ResFestivalType���������sFestivalName���������uTimeNum1
		���������uTimeNum1���������uTimeNum3
������ֵ�� RES::MODIFYTIME_OK���޸�ʱ��ɹ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
RES Controller::ModifyFestivalTime(const FestivalType& ResFestivalType, 
	                               const string& sFestivalName,
	                               const unsigned int& uTimeNum1, 
	                               const unsigned int& uTimeNum2, 
	                               const unsigned int& uTimeNum3) const {
	try {
		//�õ���ѯ�����ָ��
		Festival* pMyFestival = Festival::SearchFestivalByName(sFestivalName);
		//�޸�REGULAR_DATE���͵Ľ���
		if (ResFestivalType == FestivalType::REGULAR_DATE) {
			pMyFestival->ModifyMDDate(uTimeNum1, uTimeNum2);
			cout << "�޸ĳɹ���" << endl;
			return RES::MODIFYTIME_OK;
		}
		//�޸�REGULAR_WEEKDAY���͵Ľ���
		if (ResFestivalType == FestivalType::REGULAR_WEEKDAY) {
			pMyFestival->ModifyMOWeekDay(uTimeNum1, uTimeNum2, uTimeNum3);
			cout << "�޸ĳɹ���" << endl;
			return RES::MODIFYTIME_OK;
		}
		//�޸�SPECIAL_DATE���͵Ľ���
		if (ResFestivalType == FestivalType::SPECIAL_DATE) {
			pMyFestival->ModifyYMDDate(uTimeNum1, uTimeNum2, uTimeNum3);
			cout << "�޸ĳɹ���" << endl;
			return RES::MODIFYTIME_OK;
		}
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
		return RES::MODIFYTIME_FAIL;
	}
}

/*************************************************************************
���������ơ� MonthCalendar���������ܡ� ָ����ĳ��ĳ�¡�����ӡ���������ͽ��յĺ���
�������� �������uYear���������uMonth
������ֵ�� RES::MONCALPRINT_OK���������ɳɹ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
RES Controller::MonthCalendar(const unsigned int& uYear, 
	                          const unsigned int& uMonth) const {
	try {
		MonthCalendarPrinter MCP(uYear, uMonth);
		//��ӡ����
		MCP.PrintCalendar(uYear, uMonth);

		//��ӡ����
		MCP.PrintFestivals(uYear, uMonth);

		cout << "��ӡ�ɹ���" << endl;
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
���������ơ� SearchAndSortFestival���������ܡ� ָ���������ա���Χ
			�������Զ��������ʽ��ӡ��ʱ�䷶Χ�ڵĽ���
�������� �������YMDDate1���������YMDDate2���������SortType
������ֵ�� RES::SEARCHSORT_OK����������list�ɹ�
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
RES Controller::SearchAndSortFestival(const YMDDate& YMDDate1, 
	                                  const YMDDate& YMDDate2, 
	                                  const SortType& SortType) const {
	try {
		SearchYMDRange SYMDR(YMDDate1, YMDDate2, SortType);

		//��ѯ����ӡ���������ڵĽ��գ�����SortType������ʽ
		SYMDR.PrintFestivals();
		return RES::SEARCHSORT_OK;
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
		return RES::SEARCHSORT_FAIL;
	}
}

/*************************************************************************
���������ơ� CountDownFestival���������ܡ� �����Ʋ��Ҳ���ӡ��Ӧ���յĵ�����
�������� �������sTargetName
������ֵ�� RES::PAST_FESTIVAL�����ѹ���RES::COUNTDOWN_OK���������ɳɹ�
			��RES::INEXISTENT_NAME�����ڵĽ������ƣ�����ʧ��;
�������߼����ڡ� ��С����2023.08.02
�����ļ�¼�� ��
*************************************************************************/
RES Controller::CountDownFestival(const string& sTargetName) const{
	try{ 
		//�����Ʋ��ҽ��պͽ�������
		Festival* SearchRes = Festival::SearchFestivalByName(sTargetName); 
		FestivalType TypeRes = SearchRes->GetType();

		//��ӡSPECIAL_DATE���͵Ľ��յ�����
		if (TypeRes == FestivalType::SPECIAL_DATE) {
			//�ý��յ�������
			unsigned int uSrchResDaysInTotal 
				= SearchRes->GetYMDDate().DaysPassedInTotal();
			//�����������
			unsigned int uTodayDaysInTotal 
				= YMDDate::Today().DaysPassedInTotal();

			//����ý��ջ�û������ӡ������
			if (uSrchResDaysInTotal >= uTodayDaysInTotal) {
				cout << SearchRes->GetFestivalName() << "�ھ���ջ���"
					<< uSrchResDaysInTotal - uTodayDaysInTotal 
					<< "�졣" << endl;
				return RES::COUNTDOWN_OK;
			}
			//����ý����ѹ�����ӡ��ʾ�����
			else {
				cout << SearchRes->GetFestivalName() << "���ѹ���" << endl;
				return RES::PAST_FESTIVAL;
			}
		}

		//��ӡREGULAR_DATE���͵Ľ��յ�����
		if (TypeRes == FestivalType::REGULAR_DATE) {
			//����ĸý��յ�������
			unsigned int uSrchResThisYDaysTtl
				= YMDDate(YMDDate::Today().GetYear()
				, SearchRes->GetMDDate()).DaysPassedInTotal();
			//�����������
			unsigned int uTodayDaysInTotal
				= YMDDate::Today().DaysPassedInTotal();

			//�������ĸý��ջ�û����ֱ�Ӵ�ӡ������
			if (uSrchResThisYDaysTtl >= uTodayDaysInTotal) {
				cout << "���һ��" << SearchRes->GetFestivalName() 
					 << "�ھ���ջ���"
					 << uSrchResThisYDaysTtl - uTodayDaysInTotal << "�졣";
				return RES::COUNTDOWN_OK;
			}
			//�������Ľ����ѹ���ʹ������ĸý��ռ��㵹����
			else {
				unsigned int uSrchResNxtYDaysTtl 
					= YMDDate(YMDDate::Today().GetYear() + 1
						, SearchRes->GetMDDate()).DaysPassedInTotal();
				cout << "���һ��" << SearchRes->GetFestivalName() 
					 << "�ھ���ջ���"
					 << uSrchResNxtYDaysTtl - uTodayDaysInTotal << "�졣";
				return RES::COUNTDOWN_OK;
			}
		}

		//��ӡREGULAR_WEEKDAY���͵Ľ��յ�����
		if (TypeRes == FestivalType::REGULAR_WEEKDAY) {
			//����ĸý��յ�������
			unsigned int uSrchResThisYDaysTtl 
				= YMDDate::YMOWeekDayToYMDDate(YMDDate::Today().GetYear()
					, SearchRes->GetMOWeekDay().GetMonthValue()
					, SearchRes->GetMOWeekDay().GetOrdial()
					, SearchRes->GetMOWeekDay().GetWeekDayActualValue()).DaysPassedInTotal();
			//�����������
			unsigned int uTodayDaysInTotal = YMDDate::Today().DaysPassedInTotal();

			//�������ĸý��ջ�û����ֱ�Ӵ�ӡ������
			if (uSrchResThisYDaysTtl >= uTodayDaysInTotal) {
				cout << "���һ��" << SearchRes->GetFestivalName() << "�ھ���ջ���"
					 << uSrchResThisYDaysTtl - uTodayDaysInTotal << "�졣";
				cout << endl;
				return RES::COUNTDOWN_OK;
			}
			//�������Ľ����ѹ���ʹ������ĸý��ռ��㵹����
			else {
				unsigned int SearchResNextYearDaysInTotal
					= YMDDate::YMOWeekDayToYMDDate(YMDDate::Today().GetYear() + 1
						, SearchRes->GetMOWeekDay().GetMonthValue()
						, SearchRes->GetMOWeekDay().GetOrdial()
						, SearchRes->GetMOWeekDay().GetWeekDayActualValue()).DaysPassedInTotal();

				cout << "���һ��" << SearchRes->GetFestivalName() << "�ھ���ջ���"
					 << SearchResNextYearDaysInTotal - uTodayDaysInTotal << "�졣";
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