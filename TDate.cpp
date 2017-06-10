/*
Author:Lizhaotailang
Date:2015-07-25
Visual Studio 2013
*/

#include<iostream>
#include<string>
#include<sstream>
#include<cstring>
#include<stdlib.h>
#include<windows.h>

#define MaxYearValue 9999
#define MinYearValue 1
#define MaxDayValue31 31
#define MaxDayValue30 30
#define MaxDayValue29 29
#define MaxDayValue28 28
#define MinDayValue 1
#define MaxMonthValue 12
#define MinMonthValue 1

using namespace std;

static bool IsYearValid(int year)
{
	return ((year >= MinYearValue) && (year <= MaxYearValue));
}

static bool IsMonthValid(int month)
{
	return  ((month >= MinMonthValue) && (month <= MaxMonthValue));
}

static bool IsDayInScope(int day)
{
	return ((day >= MinDayValue) && (day <= MaxDayValue31));
}

class TDate
{
protected:
	int year, month, day;
	string errorInfo;
public:
	TDate();
	TDate(int year, int month, int day);
	TDate(string dateStr);
	int GetYear();
	int GetMonth();
	int GetDay();
	string GetErrorInfo();
	string virtual ToString();
	string virtual ToString(char ch);
	bool virtual IsValid();
	bool IsThisLeapYear();
	bool static IsLeapYear(int year);
	int static GetDaysInMonth(int year, int month);
	void AddDays(int days);
	void AddMonths(int months);
	void AddYears(int years);
	void AddOneDay();
	void SubstractOneDay();
	void SetLastDayOfMonth();
	void Initialize(int year,int month,int day);
	string & trim(string &s);
	int GetMinusCount(string dataStr);
	string::size_type GetMinusPositions(string dateStr,string::size_type index);
};

void TDate::Initialize(int year,int month,int day)
{
	if ((IsYearValid(year) == false) || (IsMonthValid(month) == false) || (IsDayInScope(day) == false))
	{
		errorInfo = "wrong date";
		return;
	}

	if (day > GetDaysInMonth(year, month))
	{
		errorInfo = "wrong date";
		return;
	}

	this->year = year;
	this->month = month;
	this->day = day;
}
bool TDate::IsLeapYear(int year)
{
	if (IsYearValid(year) == false)
	{
		return false;
	}


	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		return true;
	}

	return false;
}
int TDate::GetDaysInMonth(int year, int month)
{
	if ((IsYearValid(year) == false) || ((IsMonthValid(month)) == false))
	{
		return 0;
	}

	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		return MaxDayValue30;
	}

	if (month == 2)
	{
		if (IsLeapYear(year) == true)
		{
			return MaxDayValue29;
		}

		return MaxDayValue28;
	}

	return MaxDayValue31;
}

TDate::TDate()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	year = sys.wYear;
	month = sys.wMonth;
	day = sys.wDay;
}

TDate::TDate(int year, int month, int day)
{
	Initialize(year, month, day);
}

TDate::TDate(string dateStr)
{
	if (dateStr.empty() == true)
	{
		errorInfo = "wrong date";
		return;
	}

	int minusIndex[16];
	string s[3];
	int year_s, month_s, day_s;
	string::size_type position = 0;
	int minusCount = 0;

	minusCount = GetMinusCount(dateStr);

	int i = 0;
	while ((position = dateStr.find_first_of("-", position)) != string::npos)
	{
		minusIndex[i] = position;
		position++;
		i++;
	}

	if (minusCount != 2)
	{
		errorInfo = "wrong date";
		return;
	}


	s[0] = dateStr.substr(0, minusIndex[0]);
	s[1] = dateStr.substr(minusIndex[0]+1,minusIndex[1]-minusIndex[0]-1);
	s[2] = dateStr.substr(minusIndex[1]+1, dateStr.length());

	if ((s[0].empty() == true) || (s[1].empty() == true) || (s[2].empty() == true))
	{
		errorInfo = "wrong date";
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		bool flag=true;
		s[i] = trim(s[i]);
		for (int j = 0; j < s[i].length(); j++)
		{
			if ((s[i].at(j) < '0') || (s[i].at(j) > '9'))
			{
				errorInfo = "wrong date";
				flag = false;
				return;
			}
		}
		if (flag==false)
		{
			cout << "falsefalsefalse";
			return;
		}
	}

	year_s = atoi(s[0].c_str());
	month_s = atoi(s[1].c_str());
	day_s = atoi(s[2].c_str());

	Initialize(year_s, month_s, day_s);

}

int TDate::GetYear()
{
	return year;
}
int TDate::GetMonth()
{
	return month;
}
int TDate::GetDay()
{
	return day;
}
string TDate::GetErrorInfo()
{
	return errorInfo;
}

string TDate::ToString()
{
	return ToString('-');
}

string TDate::ToString(char ch)
{
	stringstream ss;
	ss << year;
	ss << ch;

	if (month < 10)
	{
		ss << '0';
	}

	ss << month;
	ss << ch;

	if (day < 10)
	{
		ss << '0';
	}

	ss << day;

	return ss.str();
}

bool TDate::IsValid()
{
	return errorInfo.empty();
}

bool TDate::IsThisLeapYear()
{
	return IsLeapYear(year);
}

bool operator ==(TDate t1, TDate t2)
{
	if ((t1.IsValid() == false) || (t2.IsValid() == false))
	{
		return false;
	}

	if ((t1.GetYear() == t2.GetYear()) && (t1.GetMonth() == t2.GetMonth()) && (t1.GetDay() == t2.GetDay()))
	{
		return true;
	}

	return false;
}

bool operator !=(TDate t1, TDate t2)
{
	if ((t1.IsValid() == false) || (t2.IsValid() == false))
	{
		return false;
	}

	if (t1 == t2)
	{
		return false;
	}

	return true;
}

bool operator >(TDate t1, TDate t2)
{
	if (t1.IsValid() == false || t2.IsValid() == false)
	{
		return false;
	}

	if (t1.GetYear() > t2.GetYear())
	{
		return true;
	}
	if (t1.GetYear() < t2.GetYear())
	{
		return false;
	}
	if (t1.GetMonth() > t2.GetMonth())
	{
		return true;
	}
	if (t1.GetMonth() < t2.GetMonth())
	{
		return false;
	}
	if (t1.GetDay() > t2.GetDay())
	{
		return true;
	}

	return false;
}

bool operator <(TDate t1, TDate t2)
{
	if ((t1.IsValid() == false) || (t2.IsValid() == false))
	{
		return false;
	}

	if ((t1 > t2) || (t1 == t2))
	{
		return false;
	}

	return true;
}

bool operator >=(TDate t1, TDate t2)
{
	if (t1.IsValid() == false || t2.IsValid() == false)
	{
		return false;
	}

	if (t1 < t2)
	{
		return false;
	}

	return true;
}

bool operator <=(TDate t1, TDate t2)
{
	if ((t1.IsValid() == false) || (t2.IsValid() == false))
	{
		return false;
	}

	if (t1 > t2)
	{
		return false;
	}

	return true;
}

void TDate::AddOneDay()
{
	day += 1;
	if (day > GetDaysInMonth(year, month))
	{
		month += 1;
		day = 1;
	}

	if (month > MaxMonthValue)
	{
		month = 1;
		year += 1;
	}

	if (year > MaxYearValue)
	{
		errorInfo = "over range";
	}
}
void TDate::SubstractOneDay()
{
	day -= 1;
	if (day <= 0)
	{
		month = month - 1;
	}

	if (month <= 0)
	{
		month = 12;
		year = year - 1;
		day = MaxDayValue31;
	}

	if (year <= 0)
	{
		errorInfo = "over range";
	}

	if(day <= 0)
	{
		day = GetDaysInMonth(year, month);
	}
}

void TDate::SetLastDayOfMonth()
{
	if (day > GetDaysInMonth(year, month))
	{
		day = GetDaysInMonth(year, month);
	}
}

void TDate::AddDays(int days)
{
	if (IsValid() == false)
	{
		return;
	}

	if (days >= 0)
	{
		for (int i = 1; i <= days; i++)
		{
			AddOneDay();
		}
	}
	else
	{
		for (int i = 1; i <= -days; i++)
		{
			SubstractOneDay();
		}
	}
}
void TDate::AddMonths(int months)
{
	if (IsValid() == false)
	{
		return;
	}
		if (months >= 0)
		{
			month += months;
			cout << month << endl;
			while (month > 12)
			{
				month -= 12;
				year += 1;
				if (year > MaxYearValue)
				{
					errorInfo = "over range";
					return;
				}
			}
			SetLastDayOfMonth();
		}
		else
		{
			month -= -months;
			while (month <= 0)
			{
				month += 12;
				year -= 1;
				if (year < MinYearValue)
				{
					errorInfo = "over range";
					return;
				}
			}
		}
		SetLastDayOfMonth();
}
void TDate::AddYears(int years)
{
	if (IsValid() == false)
	{
		return;
	}

	if (years >= 0)
	{
		year += years;
		if (year > MaxYearValue)
		{
			errorInfo = "over range";
			return;
		}
	}
	else
	{
		year -= (-years);
		if (year < MinYearValue)
		{
			errorInfo = "over range";
			return;
		}
	}
	SetLastDayOfMonth();
}

string & TDate::trim(string &s)
{
	if (s.empty())
	{
		return s;
	}
	s.erase(0, s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
	return s;
}

int TDate::GetMinusCount(string dateStr)
{
	int amountOfMinus = 0;
	string::size_type position = 0;
	while ((position = dateStr.find_first_of("-", position)) != string::npos)
	{
		position++;
		amountOfMinus++;
	}
	return amountOfMinus;
}

int main()
{
	getchar();
	return 0;
}
