// Pr1Gen.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

#define MAX_COUNT 10050000

int _tmain(int argc, _TCHAR* argv[])
{
	bool Setted = false;
	HANDLE hEvent;
	if (!wcscmp(GetCommandLine(), L"Mutex"))
	{
		hEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"GL.Task8.Event.Percentage70.SVR");
 		if ( GetLastError() != 0  ) 
		{
			cout << "Last error: " << GetLastError() << endl;
			cout << "Generator can't open Event\nWill exit\n";
			return -1;
		}
		else
			cout << "Generator open Event\n";
	}
	else
	{
		Setted = true;
	}
	char *ptr = NULL;
	srand(NULL);
	try
	{
		ptr = new char[MAX_COUNT];
		if (ptr)
		{
			for(int i = 0; i < MAX_COUNT; i++)
			{
				if (MAX_COUNT/(i+1) >= 70 && !Setted)
				{
					SetEvent(hEvent);
					cout << "Gen: Set Event\n";
					Setted = true;
				}
				*(ptr + i) = ((rand() % 255) | 1) + 1;
			}
			delete ptr;
		}
	}
	catch (bad_alloc& ba)
	{
		cout << "bad_alloc caught: " << ba.what() << endl;
		return 1;
	}
	cout << "Generated succesfully!\n";
	system("pause");
	return 0;
}

