/**
* @file         pr5.cpp
* @brief        Task5
* @task         5.	Створити бібліотеку для реалізації гри у 
*	«хрестики-нолики» на полі розміром 3x3. У модулі реалізувати дії:
*	1)	зробити хід гравця;
*	2)	зробити хід комп’ ютера;
*	3)	показати ігрове поле.

*
* @author       Volodymyr Spodaryk
* @email        spodaryk.volodymyr@i.ua
* ----------------------------------------------------------------------*/
#include "stdafx.h"
#include "f1.h"
using namespace std;

//------------------------ realization of prototype ------------------//
Pole* CreatePole(UNC playerCount, UNC poleSize)
{
	Pole *p = (Pole *) malloc (sizeof( Pole ));
	p->plCount = playerCount;
	p->size = poleSize;	// classic tic-tac is 3x3
	p->data = (UNC *) malloc (sizeof (UNC) * (p->size) * (p->size) );//+1
	memset(p->data, 0, (p->size) * (p->size) );	//set all field to '0'
	return p;
}
void DestroyPole(Pole *ptr)
{
	free (ptr->data);
	free (ptr);
}
UNC GetState(Pole *ptr)
{
	// @brief
	// 0 empty
	// 11	still playing
	// N<10 except 0 - player N win
	// 12	draw (all fields are filled but nobody win)
	// 13	smth is wrong 
	bool chkEmpty = false, chkFull = false;
	UNC tmpField;
	for (UNC x=0; x < ptr->size * ptr->size; x++)
	{
		tmpField = *(ptr->data + x);
		if (tmpField == 0) 
		{
			chkEmpty = true;
		}
		else
		{
			chkFull = true;
		}
	}
	
	if (chkEmpty && !chkFull)
	{
		return 0;
	}
	else
	{
		if (chkEmpty && chkFull)	
		{
			UNC a = RuleLogic(ptr);
			if (a != 12) 
			{
				return a;
			}
			else
			{
				return 11;
			}
		}
		else
		{
			if (!chkEmpty && chkFull)	
			{
				return RuleLogic(ptr);
			}
			else
			{
				return 13;
			}
		}
	}
}
void ClearPole(Pole *ptr)
{
	memset(ptr->data, 0, (ptr->size) * (ptr->size) );	//set all field to 0
	return;
}
UNC MakeStep(Pole *ptr, UNC x, UNC player)
{
	// @brief
	// 0	field in x;y is free everything is OK
	// 1	there's already sign of this player
	// 2	there's already sign of another player
	UNC *tmpField = ptr->data + x;
	if (*tmpField == 0)
	{
		*tmpField = player ;//+ 48; 
		return 0;
	}
	else
	{	//if 1 or 2
		return 2;
	}
}
void ShowPole(Pole *ptr)
{
	cout << endl << "---|---|---" << endl;
	for (UNC y=0; y < ptr->size; y++)
	{
		cout << " ";
		for (UNC x=0; x < ptr->size; x++)
		{
			if (*(ptr->data + ptr->size * y + x) == 0)
			{
				cout << " ";
			}
			else
			{
				cout << (char)(*(ptr->data + ptr->size * y + x) + 48);
			}
			if (x != ptr->size - 1) cout << " | ";
		}
		cout << endl << "---|---|---" << endl;
	}
	cout << endl;
	return;
}
UNC RuleLogic(Pole *ptr)
{	// checkers for vertical, horizontal and both diagonal lines to end game
	bool checkerX, checkerY, checkerZ1, checkerZ2;
	for (UNC pl = 1; pl <= ptr->plCount; pl++)
	{
		checkerZ1 = true;
		checkerZ2 = true;
		for (UNC y=0; y < ptr->size; y++)
		{
			checkerX = true;
			checkerY = true;			
			for (UNC x=0; x < ptr->size; x++)
			{
				if (*(ptr->data + ptr->size * y + x) != pl) 
				{
					checkerX = false;
				}
				if (*(ptr->data + ptr->size * x + y) != pl) 
				{
					checkerY = false;
				}
			}
			if (checkerX || checkerY) return pl;
			if (*(ptr->data + ptr->size * y + y) != pl) 
			{
				checkerZ1 = false;
			}
			if (*(ptr->data + ptr->size * y + (ptr->size - y - 1)) != pl) 
			{
				checkerZ2 = false;
			}
		}
		if (checkerZ1 || checkerZ2) return pl;
	}
	return 12;
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
char LogicCPU(Pole *ptr)
{
	//D**
	if(*(ptr->data + 8) == *(ptr->data + 4) && *(ptr->data + 4) != 0  && *(ptr->data + 0) == 0) return 0;
	if(*(ptr->data + 6) == *(ptr->data + 4) && *(ptr->data + 4) != 0  && *(ptr->data + 2) == 0) return 2;

	if(*(ptr->data + 0) == *(ptr->data + 8) && *(ptr->data + 8) != 0  && *(ptr->data + 4) == 0) return 4;
	if(*(ptr->data + 2) == *(ptr->data + 6) && *(ptr->data + 6) != 0  && *(ptr->data + 4) == 0) return 4;
	
	if(*(ptr->data + 2) == *(ptr->data + 4) && *(ptr->data + 4) != 0  && *(ptr->data + 6) == 0) return 6;
	if(*(ptr->data + 0) == *(ptr->data + 4) && *(ptr->data + 4) != 0  && *(ptr->data + 8) == 0) return 8;

	//H**
	if(*(ptr->data + 2) == *(ptr->data + 1) && *(ptr->data + 1) != 0 && *(ptr->data + 0) == 0) return 0;
	if(*(ptr->data + 5) == *(ptr->data + 4) && *(ptr->data + 4) != 0  && *(ptr->data + 3) == 0) return 3;
	if(*(ptr->data + 8) == *(ptr->data + 7) && *(ptr->data + 7) != 0  && *(ptr->data + 6) == 0) return 6;

	if(*(ptr->data + 0) == *(ptr->data + 2) && *(ptr->data + 2) != 0  && *(ptr->data + 1) == 0) return 1;
	if(*(ptr->data + 3) == *(ptr->data + 5) && *(ptr->data + 5) != 0  && *(ptr->data + 4) == 0) return 4;
	if(*(ptr->data + 6) == *(ptr->data + 8) && *(ptr->data + 8) != 0  && *(ptr->data + 7) == 0) return 7;

	if(*(ptr->data + 0) == *(ptr->data + 1) && *(ptr->data + 1) != 0  && *(ptr->data + 2) == 0) return 2;
	if(*(ptr->data + 3) == *(ptr->data + 4) && *(ptr->data + 4) != 0  && *(ptr->data + 5) == 0) return 5;
	if(*(ptr->data + 6) == *(ptr->data + 7) && *(ptr->data + 7) != 0  && *(ptr->data + 8) == 0) return 8;

	//V**
	if(*(ptr->data + 6) == *(ptr->data + 3) && *(ptr->data + 3) != 0  && *(ptr->data + 0) == 0) return 0;
	if(*(ptr->data + 7) == *(ptr->data + 4) && *(ptr->data + 4) != 0  && *(ptr->data + 1) == 0) return 1;
	if(*(ptr->data + 8) == *(ptr->data + 5) && *(ptr->data + 5) != 0  && *(ptr->data + 2) == 0) return 2;

	if(*(ptr->data + 0) == *(ptr->data + 6) && *(ptr->data + 6) != 0  && *(ptr->data + 3) == 0) return 3;
	if(*(ptr->data + 1) == *(ptr->data + 7) && *(ptr->data + 7) != 0  && *(ptr->data + 4) == 0) return 4;
	if(*(ptr->data + 2) == *(ptr->data + 8) && *(ptr->data + 8) != 0  && *(ptr->data + 5) == 0) return 5;

	if(*(ptr->data + 0) == *(ptr->data + 3) && *(ptr->data + 3) != 0  && *(ptr->data + 6) == 0) return 6;
	if(*(ptr->data + 1) == *(ptr->data + 4) && *(ptr->data + 4) != 0  && *(ptr->data + 7) == 0) return 7;
	if(*(ptr->data + 2) == *(ptr->data + 5) && *(ptr->data + 5) != 0  && *(ptr->data + 8) == 0) return 8;

	srand((unsigned) time(NULL));
	UNC x = rand() % (ptr->size*ptr->size);
	while ( *(ptr->data + x) != 0 )
	{
		x = rand() % (ptr->size*ptr->size);
	}
	return x;
}
bool ChoicePlayer(UNC GameType, UNC Current)
{
	if (GameType == 2 || (GameType == 1 && Current == 2))
	{	//CPU vs. CPU		or Player vs. CPU
		return true;
	}
	else
	{	// Player vs. Player
		//if (GameType == 0)
		//{
		return false;
		//}
	}
}