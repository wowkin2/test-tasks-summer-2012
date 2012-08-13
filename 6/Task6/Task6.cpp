/**
* @file         Task6.cpp
* @brief        Task6
* @task         1.	Ќапишите программу, котора€ определит, 
* правильно ли расставлены скобки в выражении, 
* если оно состоит из скобок типа: ()[]{}.
*
* @author       Volodymyr Spodaryk
* @email        spodaryk.volodymyr@i.ua
* ----------------------------------------------------------------------*/

#include "stdafx.h"
#include <iostream>
using namespace std;
typedef struct StrStack {
	char data;
    StrStack *next;
} Stk;
//------------------------- prototype functions -----------------------//

/**
* @brief        Push char in stack
* @param[in]    char to push
* @return       true if push, false if smth wrong
*/
bool Push (char a);
/**
* @brief        Get char from stack
* @return       char from stack
*/
char Pop (void);
//--------------------------- main function ---------------------------//
Stk *MyESP = NULL;	//Stack pointer

int main(void)
{
	const int SZ = 256;
	char tmp[SZ];
	cout << "Input the arithmetic expression:\n";
	cin >> tmp;
	cout << endl;
	try {
		if (cin.good())
		{
			for (int i = 0; i < SZ; i++)
			{
				if (tmp [i] == '(' || tmp [i] == '[' || tmp [i] == '{')
				{	// Open brackets
					Push(tmp[i]);
				}
				else
				{
					if (tmp [i] == ')' || tmp [i] == ']' || tmp [i] == '}')
					{	// Closed brackets
						char s = Pop();
						//cout << s << (char)(tmp [i] - 1);
						if (s != tmp [i] - 1)
						{
							throw "Wrong position of brackets in expression!\n";
						}
					}
				}
			
			}
			if (Pop() != 0)
			{
				throw "Wrong count of brackets!\n";
			}
			else
			{
				cout << "Expression is OK. =)\n";
			}
		}
		else
		{
			throw "Error in input...\n";
		}
	}
	catch (char *a)
	{
		cout << a;
	}
    system ("@pause");
    return 0;
}

//------------------------ realization of prototype ------------------//

bool Push (char a)
{
	Stk *pNew;
	pNew = (Stk *) malloc (sizeof (Stk) );
	if ( pNew )
	{
		pNew->data = a;
		pNew->next = MyESP;
		MyESP = pNew;
		return true;
	}
	else
	{
		return false;
	}
}
char Pop (void)
{
	Stk *ptr = MyESP;
	if (ptr == NULL) 
		return NULL;
    char tmp = ptr->data;
	MyESP = MyESP->next;
	free (ptr);
	return tmp;
}