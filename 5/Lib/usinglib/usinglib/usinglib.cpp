// usinglib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "f1.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
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

    system ("@pause");
    return 0;
}

