/**
* @file         pr20.cpp
* @brief        Task1
* @task         20. Використовуючи тільки бітові та арифметичні операції,
написати функцію, яка виконує циклічний зсув заданого беззнакового довгого
цілого числа на r бітів уліво.
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
* @brief        Left rotate number
* @param[in]    Number input by user
* @param[in]    Number of bits
* @return       ULI
*/
ULI Foo(ULI a, int r);
//--------------------------- main function ---------------------------//

int main(void)
{
        ULI a;
        int r;
        cout<<"Input number: ";
        cin>>a;
        cout<<"Input count: ";
        cin>>r;
        cout<<"Binary: "<<endl;
        Show(a);
        cout<<endl<<"Output: "<<Foo(a,r)<<endl;
        cout<<"Binary: "<<endl;
        Show(Foo(a,r));
        getch();
        return 0;
}

//------------------------ realization of prototype ------------------//

ULI Foo(ULI a,int r)
{
        return (a<<r)|(a>>(32-r));
}
void Show(ULI temp)
{
        ULI x[32];
        int i;
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

