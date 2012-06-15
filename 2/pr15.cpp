/**
* @file         pr15.cpp
* @brief        Task2
* @task         15. З клавіатури ввести послідовність даних, які містять
координати вершин трикутників.  Роздрукувати введені дані у вигляді таблиці,
відсортувавши їх у порядку спадання величин периметрів цих трикутників.
Визначити відсоток трикутників, периметр яких перевищує мінімальний периметр
більше, ніж у 2 рази.

* @author       Volodymyr Spodaryk
* @email        spodaryk.volodymyr@i.ua
* ----------------------------------------------------------------------*/

#include <vcl.h>
//#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

#define NUMBER 2             //Number of triangles
#define SIZE 20         //Length of inputed string
struct Pnt{
        int x;
        int y;
};
struct Trian{
        Pnt A;
        Pnt B;
        Pnt C;
};
//------------------------- prototype functions -----------------------//

/**
* @brief        Fill fields in struct
* @param[in]    Array to fill
* @return       void
*/
void Fill(Trian **p);
/**
* @brief        Show data in array
* @param[in]    Array to show
* @param[in]    Message before array
* @return       void
*/
void Show(Trian **p,const char *c);
/**
* @brief        Show item from array
* @param[in]    Array to show
* @param[in]    index of item
* @return       void
*/
void Show(Trian **p,const int i);
/**
* @brief        Sort triangles by perimetr
* @param[in]    char Pointer source
* @param[in]    field follow which should be sorting
* @post         array of triangles is sorted
* @return       void
*/
void Sorting(Trian **p);
/**
* @brief        Find minimal perimeter of triangle
* @param[in]    Pointer source
* @return       void
*/
void Find(Trian **p);
/**
* @brief        Count perimetr of triangle
* @param[in]    pointer to struct triangle
* @return       int perimetr
*/
int GetPer(Trian *p);
/**
* @brief        Find minimal perimetr of triangle
* @param[in]    pointer to triangle
* @return       int perimetr
*/
int GetMinPer(Trian **p);
//--------------------------- main function ---------------------------//

int main(void)
{
        Trian *x[NUMBER];
        cout << "Input coord 'x' and 'y' of " << NUMBER
                << " triangle 3 points A, B, C: \n";
        Fill(x);
        clrscr();
        Show(x, "Inputed data:\n");
        Sorting(x);
        cout << endl;
        Show(x, "Sorted data:\n");
        Find(x);

        delete []x;
//        cin.get();
        getch();
        return 0;
}

//------------------------ realization of prototype ------------------//
void Fill(Trian **p)
{
        for(int i=0;i<NUMBER;i++)
        {
                cout << "[" << i+1 << "]: ";
                p[i] = (Trian*) malloc (sizeof(Trian));
                cin >> p[i]->A.x >> p[i]->A.y
                        >> p[i]->B.x >> p[i]->B.y
                        >> p[i]->C.x >> p[i]->C.y;
        }
}
void Show(Trian **p,const char *c)
{
        cout << c;
        for(int i=0; i<NUMBER; i++)
        {
                cout << p[i]->A.x << ";" << p[i]->A.y << "\t"
                        << p[i]->B.x << ";" << p[i]->B.y << "\t"
                        << p[i]->C.x << ";" << p[i]->C.y << endl;
        }
}
void Show(Trian **p,const int i)
{
        cout << p[i]->A.x << ";" << p[i]->A.y << "\t"
                << p[i]->B.x << ";" << p[i]->B.y << "\t"
                << p[i]->C.x << ";" << p[i]->C.y << endl;
}
void Sorting(Trian **p)
{
        Trian *tmp;
        for(int i=0; i < NUMBER; i++)
                for(int j=i+1; j < NUMBER; j++)
                {
                        if(GetPer(p[i])>GetPer(p[j]))
                        {
                                tmp = p[i];
                                p[i] = p[j];
                                p[j] = tmp;
                        }

                }
        return;
}
void Find(Trian **p)
{
        int minPer = GetMinPer(p);
        int s = 0;
        bool found;
        cout << endl << endl << "Found (with perimetr twice less than minimal): ";
        for(int i=0; i < NUMBER; i++)
        {

                if (minPer * 2 < GetPer(p[i]))
                {
                        cout << endl;
                        Show(p,i);
                        found = true;
                        ++s;
                }
        }
        if (!found)
        {
                cout << "0%";
        }
        else
        {
                cout << "\n Percentage: " << ((float)s) / NUMBER * 100 << "%";
        }
}
int GetPer(Trian *p)
{
        return sqrt(pow((p->A.x - p->B.x), 2) * pow((p->A.x - p->B.x), 2)) +
                sqrt(pow((p->B.x - p->C.x), 2) * pow((p->B.x - p->C.x), 2)) +
                sqrt(pow((p->C.x - p->A.x), 2) * pow((p->C.x - p->A.x), 2));
}
int GetMinPer(Trian **p)
{
        int minPer = GetPer(p[0]);
        for(int i=1; i < NUMBER; i++)
                if (minPer > GetPer(p[i]))
                        minPer = GetPer(p[i]);
        return minPer;
}
