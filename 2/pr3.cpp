/**
* @file         pr3.cpp
* @brief        Task2
* @task         3. З клавіатури ввести послідовність даних про  місячні
результати роботи цеху: <Номер місяця>, <План>, <Фактичний випуск>.
Роздрукувати введені дані у вигляді таблиці, відсортувавши їх у порядку зменшення
відсотку виконання плану. В таблиці замінити номери місяців їх найменуваннями.

* @author       Volodymyr Spodaryk
* @email        spodaryk.volodymyr@i.ua
* ----------------------------------------------------------------------*/

#include <vcl.h>
//#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

#define NUMBER 3             //Number of Results
struct Result{
        int Month;
        int Plan;
        int Fact;
};
//------------------------- prototype functions -----------------------//

/**
* @brief        Fill fields in struct
* @param[in]    Array to fill
* @return       void
*/
void Fill(Result **p);
/**
* @brief        Show data in array
* @param[in]    Array to show
* @param[in]    Message before array
* @return       void
*/
void Show(Result **p,const char *c);
/**
* @brief        Sort Results by Field
* @param[in]    Pointer source
* @param[in]    field follow which should be sorting
* @post         array of Results is sorted
* @return       void
*/
void Sorting(Result **p);
/**
* @brief        Print full name of month by number
* @param[in]    Number of month
* @return       void
*/
void GetMonth(int a);
//--------------------------- main function ---------------------------//

int main(void)
{
        Result *x[NUMBER];
        cout << "Hello, this is a Result-manager.\n"
                << "Input integer coords of " << NUMBER
                << " Result (month number, plan, factically production): \n";
        Fill(x);
        clrscr();
        Show(x, "Inputed data:\n");
        Sorting(x);
        cout << endl;
        Show(x, "Sorted data:\n");

        delete []x;
//        cin.get();
        getch();
        return 0;
}

//------------------------ realization of prototype ------------------//
void Fill(Result **p)
{
        for(int i=0;i<NUMBER;i++)
        {
                cout << "[" << i+1 << "]: ";
                p[i] = (Result*) malloc (sizeof(Result));
                cin >> p[i]->Month >> p[i]->Plan >> p[i]->Fact;
        }
}
void Show(Result **p,const char *c)
{
        cout << c;
        for(int i=0; i<NUMBER; i++)
        {
                GetMonth(p[i]->Month);
                cout << p[i]->Plan << "\t" << p[i]->Fact << endl;
        }
}
void Sorting(Result **p)
{
        Result *tmp;
        for(int i=0; i < NUMBER; i++)
                for(int j=i+1; j < NUMBER; j++)
                {
                        if(p[i]->Fact - p[i]->Plan > p[j]->Fact - p[j]->Plan)
                        {
                                tmp = p[i];
                                p[i] = p[j];
                                p[j] = tmp;
                        }

                }
        return;
}
void GetMonth(int a)
{
        switch(a)
        {
                case 1: cout << "January  \t"; break;
                case 2: cout << "February \t"; break;
                case 3: cout << "March    \t"; break;
                case 4: cout << "April    \t"; break;
                case 5: cout << "May      \t"; break;
                case 6: cout << "June     \t"; break;
                case 7: cout << "July     \t"; break;
                case 8: cout << "August   \t"; break;
                case 9: cout << "September\t"; break;
                case 10: cout << "October \t"; break;
                case 11: cout << "November\t"; break;
                case 12: cout << "December\t"; break;
                default: cout << "No month\t";
        }
}
