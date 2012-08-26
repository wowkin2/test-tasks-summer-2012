// Pr4FindInFile.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

char *FilePath = "1.txt";
char *FindString = "123";
unsigned const char SZ = 230;

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *InputF;
	if( (InputF = fopen(FilePath, "rb")) == 0)
	{
		cout << "Can't open file...\n";
	}
	else
	{
		char *Buff = new char [SZ];
		char *Pos = 0;
		int cnt = 0;

		while( fgets(Buff, SZ, InputF) )
		{
			Pos = strstr(Buff, FindString);
			if (Pos)
			{
				cout << "Found in: " << (int(Pos - Buff) + cnt*SZ) << endl;
			}
			cnt++;
			memset(Buff, 0, SZ);
		}

		fclose(InputF);
	}
	return 0;
}

