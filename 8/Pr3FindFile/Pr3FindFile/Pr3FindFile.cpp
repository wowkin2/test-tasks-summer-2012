// Pr3FindFile.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
#include <vector>
#include <iostream>
using namespace std;

vector<WCHAR[260]> SearchData;

unsigned int SearchFiles(WCHAR* tmpPath, WCHAR *findPath)
{
	WIN32_FIND_DATA FindFileData;
    HANDLE hf;
    hf=FindFirstFile(tmpPath, &FindFileData);
    if (hf != INVALID_HANDLE_VALUE)
    {
        do
        {
			if(!(wcscmp(FindFileData.cFileName,L".") == 0 || wcscmp(FindFileData.cFileName,L"..") == 0))
			{
				if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{

					WCHAR *b = new WCHAR [1024];
					memset(b, 0, sizeof(WCHAR) * 1024);
					b = wcscat(b, tmpPath);
					b = wcstok(b, L"*");
					b = wcscat(b, FindFileData.cFileName);
					b = wcscat(b, L"\\*");
					SearchFiles(b, findPath);
				}
				else
				{
					if (wcscmp(FindFileData.cFileName, findPath) == 0)
					{
						wcout << FindFileData.cFileName << endl;
						// SHOW (tmpPath, "\\", FindFileData.cFileName)
					}
				}
			}
        }
        while (FindNextFile(hf, &FindFileData)!=0);
        FindClose(hf);
    }
	return SearchData.size();
}
int main()
{
	SearchFiles(L"D:\\Проекти і чтиво\\GL Base Camp\\- MyPresentation\\*", L"RTTI.pptx");
	/*while (SearchData.size())
	{
		wcout << SearchData.back() << endl;
		SearchData.pop_back();
	}*/
	//system("@pause");
	return 0;
}