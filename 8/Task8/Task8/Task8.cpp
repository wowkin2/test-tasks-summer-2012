// Task8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;

HANDLE RunProcess(LPCWSTR ProcName, bool WaitEvent, char *Comment = NULL);

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE pG, pS, pF, pT;
	HANDLE hEvent = CreateEvent( NULL, FALSE, FALSE, L"GL.Task8.Event.Percentage70.SVR");
	if ( GetLastError() == ERROR_ALREADY_EXISTS )
	{
		cout << "Main. Can't create Event\nWill exit\n";
		system("pause");
		return -1;
	}
	/***************  FIRST PART  *********************/
	/*cout << "Run without waiting:\n";
	pG = RunProcess(TEXT("..\\..\\Pr1Gen\\Debug\\Pr1Gen.exe"), false, "Generate");
	WaitForSingleObject( pG, INFINITE );
	CloseHandle( pG );
	pS = RunProcess(TEXT("..\\..\\Pr2Sort\\Debug\\Pr2Sort.exe"), false, "Sorting");
	WaitForSingleObject( pS, INFINITE );
	CloseHandle( pS );
	pF = RunProcess(TEXT("..\\..\\Pr3FindFile\\Debug\\Pr3FindFile.exe"), false, "Search file");
	WaitForSingleObject( pF, INFINITE );
	CloseHandle( pF );
	pT = RunProcess(TEXT("..\\..\\Pr4FindInFile\\Debug\\Pr4FindInFile.exe"), false, "Search in file");
	WaitForSingleObject( pT, INFINITE );
	CloseHandle( pT );
	cout << "First Part COMPLETE\n\n";
	system("pause");
	system("cls");*/
	
	/***************  SECOND PART  *********************/
	cout << "Run with waiting for 70% progress:\n";
	pG = RunProcess(TEXT("..\\..\\Pr1Gen\\Debug\\Pr1Gen.exe"), true, "Generate");
	//pF = RunProcess(TEXT("..\\..\\Pr3FindFile\\Debug\\Pr3FindFile.exe"), true, "Search file");
	CloseHandle( pG);
	/*CloseHandle( pF);
	WaitForSingleObject(hEvent, INFINITE);
	pS = RunProcess(TEXT("..\\..\\Pr2Sort\\Debug\\Pr2Sort.exe"), true, "Sorting");
	CloseHandle( pS );
	WaitForSingleObject(hEvent, INFINITE);
	pT = RunProcess(TEXT("..\\..\\Pr4FindInFile\\Debug\\Pr4FindInFile.exe"), true, "Search in file");
	CloseHandle( pT );
	*/CloseHandle(hEvent);
	system("@pause");

	return 0;
}
HANDLE RunProcess(LPCWSTR ProcName, bool WaitEvent, char *Comment)
{
	STARTUPINFO si;
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	PROCESS_INFORMATION pi;
	ZeroMemory( &pi, sizeof(pi) );

	if (CreateProcess(ProcName, (WaitEvent ? L"Mutex" : NULL), 
		NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi ))
	{
		if (Comment) cout << "\t" << Comment << ": Created...\n";
		CloseHandle( pi.hThread );
	}
	else
	{
		cout << "Can't create process!\n";
		return 0;
	}
	return pi.hProcess;
}