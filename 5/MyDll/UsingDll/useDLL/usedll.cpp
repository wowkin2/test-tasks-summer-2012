
#include "stdafx.h"
#include "usedll.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	HINSTANCE mydll = LoadLibrary(TEXT("mydll.dll")); 
	if (mydll) 
    { 
		cout << "Loading Dynamic library...\n";
		CreatePole	= (FFCRP) GetProcAddress(mydll, LPCSTR("CreatePole"));   
        ShowPole	= (FFFIN) GetProcAddress(mydll, LPCSTR("ShowPole"));
		DestroyPole = (FFFIN) GetProcAddress(mydll, LPCSTR("DestroyPole"));
		ClearPole	= (FFFIN) GetProcAddress(mydll, LPCSTR("ClearPole"));   
        GetState	= (FFUNC) GetProcAddress(mydll, LPCSTR("GetState"));
		RuleLogic	= (FFUNC) GetProcAddress(mydll, LPCSTR("RuleLogic"));
		MakeStep	= (FFSTP) GetProcAddress(mydll, LPCSTR("MakeStep"));
		ChoicePlayer= (FFCHO) GetProcAddress(mydll, LPCSTR("ChoicePlayer"));
		LogicCPU	= (FFUNC) GetProcAddress(mydll, LPCSTR("LogicCPU"));
		if ( !( CreatePole && ShowPole && DestroyPole && ClearPole && GetState && RuleLogic && MakeStep ) )
		{
			cout << "Can't load some function(-s) from the library... \n";
		}
		else
		{
			cout << "Successfully... \n\n";
			
			Pole *ptr1;
			char choice = 'y';

			cout << "This is a program of Tic-Tac-Toe... \n\n";
			ptr1 = CreatePole(2, 3);
			while (choice == 'y')
			{
				if ( EmptyNotify(ptr1) == 0) 
				{
					UNC result = StartGame(ptr1);
					if (result > 12)
					{
						cout << "Ups... Smth is wrong.. \nError code #" << result;
					}
					else
					{
						if (result == 12)
						{
							cout << "It's a Draw... \n";
							ShowPole(ptr1);
						}
						else
						{
							if (result < 11)
							{
								cout << "\nPlayer" << (char) (result + 48) << " win. Congratulation!\n";
								ShowPole(ptr1);
							}
						}
					}
				}
				cout << "\nWant to play again (y/n)? ";
				cin >> choice;
				while ( !( cin.good() && ( choice =='y' || choice =='n' ) ) )
				{
					cout << "\nWant to play again (y/n)? ";
					cin >> choice;
				}
				if (choice == 'y') 
				{
					ClearPole(ptr1);
					cout << endl << endl;
				}
			}
			DestroyPole( ptr1 );
		}
		FreeLibrary(mydll); 
    } 
	else
	{
		cout<<"Can't load of DLL\n";
	}
	system("@pause");
	return 0;
}

UNC EmptyNotify(Pole *ptr)
{
	char tmpChar = 0;
	while( GetState(ptr) != 0 )
	{
		cout << "Error. Field is not empty cann't to continue... \nClear this field to play (y/n) ?? ";
		cin >> tmpChar;
		while ( !( cin.good() && ( tmpChar!='y' || tmpChar!='n' ) ) )
		{
			cout << "Error. Field is not empty cann't to continue... \nClear this field to play (y/n) ?? ";
			cin >> tmpChar;
		}
		if (tmpChar == 'y')
		{
			ClearPole(ptr);
			return 0;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
UNC StartGame(Pole *ptr)
{
	UNC uCount = ptr->plCount; //Count of User 2 
	UNC tmpCnt = 1;		// First player is 1
	UNC tmpX;			// temporary coord for one step
	UNC tmpStep;		// tmp for state of players step
	UNC GameType;	// 0 - Pl vs. Pl, 1 - Pl vs. CPU, 2 - CPU vs. CPU

	cout << "Input type of Game:\n0\tPlayer vs. Player\n1\tPlayer vs. CPU\n2\tCPU vs. CPU\nInput number: ";
	cin >> GameType;
	while ( !( cin.good() && ( GameType > 48 || GameType < 50 ) ) )
	{
		cout << "Input type of Game:\n0\tPlayer vs. Player\n1\tPlayer vs. CPU\n2\tCPU vs. CPU\nInput number: ";
		cin >> GameType;
	}
	while( GetState(ptr) == 11 || GetState(ptr) == 0 )
	{
		if (ChoicePlayer(GameType - '0', tmpCnt) == true)
		{
			cout << "Thinking";
			for (int k = 0; k < 5; k++)
			{
				cout << ".";
				Sleep(200);			//Delay to nice game
			}
			MakeStep(ptr, LogicCPU(ptr), tmpCnt);
			cout << "PC step is maked... \n";
			Sleep(200);				//Delay to nice game
			tmpCnt++;
			if (tmpCnt > uCount)
			{
				tmpCnt = 1;
			}
		}
		else
		{
			while (true)	// while error in input repeat	
			{
				cout << "List of free cells:\n----------\n";
				for (int i = 0; i < ptr->size * ptr->size; i++)
				{
					if (*(ptr->data+i) == 0) 
					{
						cout << " " << i << " ";
					}
					else
					{
						cout << "   ";
					}
					if ((i+1) % ptr->size == 0) cout << endl;
				}
				cout << "----------\nInput a cell number from list: ";
				cin >> tmpX;
				if (cin.good() && tmpX >= 48 && tmpX < (48 + ptr->size * ptr->size)) break;
				cin.clear();
				cin.sync();
				cout << "Player" << tmpCnt+1 << ", error in input...\n";
			}
			tmpStep = MakeStep(ptr, tmpX - 48, tmpCnt);
			if ( tmpStep == 0 )
			{
				cout << "Your step is maked... \n";
				tmpCnt++;
				if (tmpCnt > uCount)
				{
					tmpCnt = 1;
				}
			}
			else
			{
				if (tmpStep == 1 || tmpStep == 2)
				{
					cout << "This field is not empty try once more...\n";
				}
				else
				{
					cout << "An unknown error... \n";
				}
			}
		}
		ShowPole(ptr);
		Sleep(200);				//Delay to nice game
	}
	return GetState(ptr);
}