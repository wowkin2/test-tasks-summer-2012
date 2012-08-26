// Pr2Sort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

#define MAX_COUNT 1005000
int _tmain(int argc, _TCHAR* argv[])
{
	bool Setted = false;
	HANDLE hEvent;
	if (!wcscmp(GetCommandLine(), L"Mutex"))
	{
		hEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"GL.Task8.Event.Percentage70.SVR");
 		if ( GetLastError() != 0 ) 
		{
			cout << "Last error: " << GetLastError() << endl;
			cout << "Sorter can't open Event\nWill exit\n";
			return -1;
		}
		else
			cout << "Sorter open Event\n";
	}
	else
	{
		Setted = true;
	}
	unsigned int *ptr = NULL;
	srand(NULL);
	try
	{
		ptr = new unsigned int[MAX_COUNT];
		if (ptr)
		{
			for(int i = 0; i < MAX_COUNT; i++)
			{
				*(ptr + i) = rand() % 1000;
			}
			cout << "Sorting\n";
			/*bool done = false;
			unsigned int j = MAX_COUNT;
			while ( !done )
			{
				done = true;
				for (unsigned int i = 0; i < MAX_COUNT-1; i++)
				{
					if (ptr[i] > ptr[i+1])
					{
						done = false;
						std::swap(ptr[i], ptr[i+1]);
					}
				}
				j--;
			}*/
			

			int j, i, m, mid;
			for(m = MAX_COUNT/2; m > 0; m /= 2)
			{
				for(j = m; j< MAX_COUNT; j++)
				{
					if (MAX_COUNT/(j+1) == 70 && !Setted)
					{
						SetEvent(hEvent);
						cout << "Sort: Set Event\n";
						Setted = true;
					}
					for(i = j - m; i >= 0; i -= m)
					{
						if(ptr[i+m]>=ptr[i])
							break;
						else
						{
							mid = ptr[i];
							ptr[i] = ptr[i+m];
							ptr[i+m] = mid;
						}
					}
				}
			}

			delete ptr; ///!!!!!!!!!!!
		}
	}
	catch (bad_alloc& ba)
	{
		cerr << "bad_alloc caught: " << ba.what() << endl;
	}
	cout << "Sort succesfully!\n";
	return 0;
}

