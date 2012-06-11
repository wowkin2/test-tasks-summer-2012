/**
* @file         pr12.cpp
* @brief        Task1
* @task         12. Використовуючи тільки бітові операції, написати функцію,
яка міняє місцями усі сусідні групи з 2-х бітів у заданому беззнаковому
довгому цілому числі.
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
* @brief        Change all 2-neighbors bites in ULI
* @param[in]    ULI number to change
* @return       ULI changed number
*/
ULI Foo(ULI a);

//--------------------------- main function ---------------------------//

int main(void)
{
        ULI a;
        int pos1, pos2;
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

ULI Foo(ULI x)
{
		int a1, int a2;
        a1 = (x & 0xCCCCCCCC)>>2;
        a2 = (x & 0x33333333)<<2;
        x=a1 | a2;
        return x;//(x ^ 1) ;
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
                if((i)%4==0)
                {
                        cout<<" ";
                }
        }
        cout<<endl;
}

