/**
* @file         pr1.cpp
* @brief        Task1
* @task         1. Використовуючи тільки бітові та арифметичні операції, написати функцію,
яка повертає наступне парне число за заданим беззнаковим довгим цілим числом.
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
* @brief        Change number according to the task
* @param[in]    Number input by user
* @return       ULI
*/
ULI Foo(ULI a);
//--------------------------- main function ---------------------------//

int main(void)
{
        ULI a;
        cout<<"Input number: ";
        cin>>a;
        cout<<"Binary: "<<endl;
        Show(a);
        cout<<endl<<"Output: "<<Foo(a)<<endl;
        cout<<"Binary: "<<endl;
        Show(Foo(a));
        getch();
        return 0;
}

//------------------------ realization of prototype ------------------//

ULI Foo(ULI a)
{
        return (a&0xFFFFFFFE)|2;
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

