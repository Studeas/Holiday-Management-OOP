/*************************************************************************
【文件名】 Festival.hpp
【功能模块和目的】 维护Festival类，集中编写Festival类成员函数的声明。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/

#ifndef Festival_hpp
#define Festival_hpp

#include <string>
#include <vector>
#include "MDDate.hpp"
#include "YMDDate.hpp"
#include "MOWeekDay.hpp"


using namespace std;

/*************************************************************************
【类名】 FestivalType
【功能】 枚举类型，提供FestivalType成员函数的返回值。
【接口说明】 不提供接口，只维护成员。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
enum class FestivalType {
	REGULAR_DATE,
	REGULAR_WEEKDAY,
	SPECIAL_DATE
};

/*************************************************************************
【类名】 Festival
【功能】 抽象类，存储节日名；读取、存储文件；提供修改、查找等功能的函数实现。
【接口说明】 Del删除节日，5个getter用来获取数据，4个Modify用来修改成员数据
			，SearchFestivalByName用来查找。
【开发者及日期】 孙小康，2023.08.02
【更改记录】 无
*************************************************************************/
class Festival {
public:
	//删除指定名称的节日
	static bool Del(const string& sName);

	//删除默认构造函数、拷贝构造函数和赋值运算符
	Festival(const char*) = delete;
	Festival() = delete;
	Festival(const Festival& Source) = delete;
	Festival& operator=(const Festival& Source) = delete;

	//获得节日名称
	string GetFestivalName() const;

	//修改节日名称
	bool ModifyName(const string& sOldName, const string& sNewName);

	//修改节日时间，纯虚函数
	virtual bool ModifyMOWeekDay(const unsigned int& uMonth
								, const unsigned int& uOrdial
								, const unsigned int& uWeekDay) = 0;
	virtual bool ModifyMDDate(const unsigned int& uMonth
							, const unsigned int& uDay) = 0;
	virtual bool ModifyYMDDate(const unsigned int& uYear
							, const unsigned int& uMonth
							, const unsigned int& uDay) = 0;
		
	//获得节日时间信息，纯虚函数
	virtual YMDDate GetYMDDate() const = 0;
	virtual MDDate GetMDDate() const = 0;
	virtual MOWeekDay GetMOWeekDay() const = 0;
	virtual FestivalType GetType() const = 0;

	//按照名称搜索节日
	static Festival* SearchFestivalByName(const string& sTargetName);
	
	//内嵌类，存储某年的节日信息（包含名称、时间信息），便于实现查找打印功能
	class FestivalInThisYear {
	public:
		//带参数的构造函数
		FestivalInThisYear(const string& sName
						, const YMDDate& YMDDate
						, const unsigned int& uDaysInTotal);
		string m_Name;
		YMDDate m_YMDDate;
		unsigned int m_DaysInTotal;
	};

	//静态成员函数，查找某年中的所有节日
	static vector<FestivalInThisYear*> 
		GetFestivalInThisYearList(const unsigned int& uYear);

	//保存至指定文件
	static void SaveToFile(const string& FileName);
	//读取指定文件
	static void LoadFromFile(const string& FileName);

	//节日名称的常引用
	const string& Name;

protected:
	//带参数的构造函数
	Festival(const string& sName);

	//受保护的数据成员，存储所有节日的指针
	static vector<Festival*> m_All;
	
private:
	//程序结束的时候Garbo类会调用这个函数
	static void Clear();
	
	//私有数据成员，节日名称
	string m_Name;

	//内嵌类，程序结束的时候用以销毁动态内存，防止内存泄漏
	class Garbo {
	public:
		~Garbo() {
			Festival::Clear();
		}
	};
	static Garbo m_Garbo;
};


#endif