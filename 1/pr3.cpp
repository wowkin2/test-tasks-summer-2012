/**
* @file         pr3.cpp
* @brief        Task1
* @task         3. Використовуючи тільки бітові операції, написати функцію,
яка повертає одиницю, якщо біти у 2-х заданих позиціях
беззнакового довгого цілого числа відрізняються.
* @author       Volodymyr Spodaryk
* @email        spodaryk.volodymyr@i.ua
* ----------------------------------------------------------------------*/

#include <vcl.h>
//#include "stdafx.h"
#include <iostream>
#include <conio>
using namespace std;
typedef unsigned long int ULI;
typedef   signed long int SLI;
//------------------------- prototype functions -----------------------//

/**
* @brief        Show binary code of number
* @param[in]    Number should be converted
* @return       void
*/
void Show(ULI temp);

/**
* @brief        Compare 2 bites in ULI
* @param[in]    ULI number to change
* @param[in]    int first bit position
* @param[in]    int second bit position
* @return       int 1 if numbers are different, 0 - equals
*/
int Foo(ULI a, int pos1, int pos2);

//--------------------------- main function ---------------------------//

int main(void)
{
        ULI a;
        int pos1, pos2;
        cout<<"Input number: ";
        cin>>a;
        cout<<"Input first bit position: ";
        cin>>pos1;
        cout<<"Input second bit position: ";
        cin>>pos2;
        cout<<"Binary: "<<endl;
        Show(a);
        cout<<endl<<"Output: "<<Foo(a, pos1, pos2)<<endl;
//        cout<<"Binary: "<<Foo(a, pos1, pos2);
        getch();
        return 0;
}

//------------------------ realization of prototype ------------------//

int Foo(ULI x, int a1, int a2)
{
        return ( ( (1 << a1-1) & x) >> a1-1 ) ^ ( ( (1 << a2-1) & x) >> a2-1 );
}

void Show(ULI temp)
{
        ULI x[32];
        int i;
        cout<<temp<<"\t";
        for(i=0;i<32;i++)
        {
                x[i]=temp%2;
		temp=temp/2;
	}
        for(i=31;i>=0;i--)
        {
	        cout<<x[i];
			if((i+1)%4==0)
			{
					cout<<" ";
			}			
        }
        cout<<endl;
}

