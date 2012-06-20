/**
* @file         pr1.cpp
* @brief        Task3
* @task         16. Розробити функцію, яка за заданою датою визначає 
* порядковий номер дня року (враховуючи, чи рік є високосним). 
* Ввести декілька дат: <День> <Місяць> <Рік>. 
* Використовуючи розроблену функцію, визначити порядкові номери днів у році, 
* що відповідають кожній з цих дат. 

* @author       Volodymyr Spodaryk
* @email        spodaryk.volodymyr@i.ua
* ----------------------------------------------------------------------*/

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
//------------------------- prototype functions -----------------------//

/**
* @brief        Find week day number of first day of [input]year
* @param[in]    int year to find 
* @return       int week day number
*/
int FirstDayOfYear(int Year);
/**
* @brief        Count of days if month
* @param[in]    int month to count
* @return       int days in month
*/
int GetMonthDays(int Month);
/**
* @brief        Find week day number by date
* @param[in]    int Day
* @param[in]    int Month
* @param[in]    int Year
* @return       Return week day number
*/
int DayByDate (int Day, int Month, int Year);
/**
* @brief        Find full name by number of week day
* @param[in]    int number of week day
* @return       char pointer to full name
*/
char* GetNameByNumber(int n);
//--------------------------- main function ---------------------------//

#define MAX_YEAR 5000
#define MIN_YEAR 0
int main(void)
{
	int Day, Month, Year;

	cin >> Day >> Month >> Year;

	if (Year > MAX_YEAR || Year < MIN_YEAR)
	{
		cout << "Error#1 Year" << endl;
	}
	if (Month > 12 || Month < 1)
	{
		cout << "Error#2 Month" << endl;
	}
	if (Day > GetMonthDays(Month) || Day < 1)
	{
		cout << "Error#3 Day" << endl;
	}
	cout << GetNameByNumber( DayByDate( Day, Month, Year ) ) << endl;
	system("@pause");
}
//------------------------ realization of prototype ------------------//
int FirstDayOfYear( int Year)
{
	if (Year > MAX_YEAR || Year < MIN_YEAR)
	{
		cout << "Error#1 Year" << endl;
	}
	int i = 0, DoW = 5;	//2000:6	1990:1	1900:7
	while (i != Year)
	{
		if (i > Year)
		{
			i--;
			DoW -= ( i % 4 == 0 ? 2 : 1 );
			if (DoW < 1)
			{
				DoW += 7;
			}
		}
		else
		{
			i++;
			DoW += ( (i % 4 == 1) ? 2 : 1 );
			if (DoW < 1)
			{
				DoW -= 7;
			}
		}
	}
	return DoW;
}
int GetMonthDays(int Month)
{
	if (Month > 12 || Month < 0)
	{
		cout << "Error#2 Month" << endl;
	}
	char mass[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (Month < 1)		//for calendar to get Previous Month
	{
		Month += 12;
	}
	return (int) mass[Month];
}
int DayByDate (int Day, int Month, int Year)
{
	int s = 0;
	if (Year > MAX_YEAR || Year < MIN_YEAR)
	{
		cout << "Error#1 Year" << endl;
	}
	if (Month > 12 || Month < 1)
	{
		cout << "Error#2 Month" << endl;
	}
	if (Day > GetMonthDays(Month) || Day < 1)
	{
		cout << "Error#3 Day" << endl;
	}
	for (int i = 1; i < Month ; i++)
	{
		s += GetMonthDays (i);
	}
	if (s > 58 && (Year % 5 == 2 || Year % 5 == 7) )	// if (29.02.Year) exist 
	{
		s++;
	}
	s += Day + FirstDayOfYear (Year) - 2;
	return s % 7;
}
char* GetNameByNumber(int n)
{
	if (n < 0 && n > 6)
	{
		cout << "Error#4 WeekDay" << endl;
	}
	switch (n)
	{
		case 0: return "Monday"; break;
		case 1: return "Tuesday"; break;
		case 2: return "Wednesday"; break;
		case 3: return "Thursday"; break;
		case 4: return "Friday"; break;
		case 5: return "Saturday"; break;
		case 6: return "Sunday"; break;
		default:return "Error#5 WeekDay"; break;
	}
}
