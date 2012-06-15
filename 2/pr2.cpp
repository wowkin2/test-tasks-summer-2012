/**
* @file         pr2.cpp
* @brief        Task2
* @task         2. З клавіатури ввести послідовність даних, які є координатами
протилежних вершин прямокутників.  Роздрукувати введені дані у вигляді таблиці,
відсортувавши їх за зростанням лівої координати x прямокутника. Визначити два
прямокутники з найбільшою і найменшою площею.

* @author       Volodymyr Spodaryk
* @email        spodaryk.volodymyr@i.ua
* ----------------------------------------------------------------------*/

#include <vcl.h>
//#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

#define NUMBER 3             //Number of rectangles
struct StRect{
        int x1;
        int y1;
        int x2;
        int y2;
};
//------------------------- prototype functions -----------------------//

/**
* @brief        Fill fields in struct Rect
* @param[in]    Array to fill
* @return       void
*/
void Fill(StRect **p);
/**
* @brief        Show data in array
* @param[in]    Array to show
* @param[in]    Message before array
* @return       void
*/
void Show(StRect **p,const char *c);
/**
* @brief        Show item from array
* @param[in]    Array to show
* @param[in]    index of item
* @return       void
*/
void Show(StRect **p,const int i);
/**
* @brief        Sort Rectangls by Field
* @param[in]    Pointer source
* @param[in]    field follow which should be sorting
* @post         array of Rectangle is sorted
* @return       void
*/
void Sorting(StRect **p);
/**
* @brief        find max rectangle square
* @param[in]    Pointer source
* @return       int max square
*/
int GetMax(StRect **p);
/**
* @brief        find max rectangle square
* @param[in]    Pointer source
* @return       int max square
*/
int GetMin(StRect **p);
/**
* @brief        count rectangle square
* @param[in]    Pointer source
* @return       int square
*/
int GetSq(StRect *p);
//--------------------------- main function ---------------------------//

int main(void)
{
        StRect *x[NUMBER];
        cout << "Hello, this is a Rectangle-manager.\n"
                << "Input integer coords of " << NUMBER
                << " Rectangle (x1, y1, x2, y2): \n";
        Fill(x);
        clrscr();
        Show(x, "Inputed data:\n");
        Sorting(x);
        cout << endl;
        Show(x, "Sorted data:\n");
        cout<<endl<<"Max: "<<GetMax(x);
        cout<<endl<<"Min: "<<GetMin(x);

        delete []x;
//        cin.get();
        getch();
        return 0;
}

//------------------------ realization of prototype ------------------//
void Fill(StRect **p)
{
        for(int i=0;i<NUMBER;i++)
        {
                cout << "[" << i+1 << "]: ";
                p[i] = (StRect*) malloc (sizeof(StRect));
                cin >> p[i]->x1 >> p[i]->y1 >> p[i]->x2 >> p[i]->y2;
        }
}
void Show(StRect **p,const char *c)
{
        cout << c;
        for(int i=0; i<NUMBER; i++)
        {
                cout << p[i]->x1 << "\t"
                     << p[i]->y1 << "\t"
                     << p[i]->x2 << "\t"
                     << p[i]->y2 << endl;
        }
}
void Show(StRect **p,const int i)
{
        cout << p[i]->x1 << "\t"
                << p[i]->y1 << "\t"
                << p[i]->x2 << "\t"
                << p[i]->y2 << endl;
}
void Sorting(StRect **p)
{
        StRect *tmp;
        for(int i=0; i < NUMBER; i++)
                for(int j=i+1; j < NUMBER; j++)
                {
                        if(p[i]->x1 > p[j]->x1)
                        {
                                tmp = p[i];
                                p[i] = p[j];
                                p[j] = tmp;
                        }

                }
        return;
}
int GetMax(StRect **p)
{
        int max = GetSq(p[0]);
        for(int i=1; i<NUMBER; i++)
        {
                if(max < GetSq(p[i]))
                        max = GetSq(p[i]);
        }
        return max;
}
int GetMin(StRect **p)
{
        int min = GetSq(p[0]);
        for(int i=1; i<NUMBER; i++)
        {
                if(min > GetSq(p[i]))
                        min = GetSq(p[i]);
        }
        return min;
}
int GetSq(StRect *p)
{
        return abs((p->x2 - p->x1) * (p->y2 - p->y1));
}
