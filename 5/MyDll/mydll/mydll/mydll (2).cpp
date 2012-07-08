// mydll.cpp : Defines the entry point for the DLL application.
//


#include "fun.h"
#include "windows.h"


int z;

BOOL WINAPI DllMain(
   DWORD dwReason,
   LPVOID /*lpReserved*/
) 
{
    z = f1(55);
	return TRUE;
}
