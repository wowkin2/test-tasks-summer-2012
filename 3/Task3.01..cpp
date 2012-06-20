/**
* @file         pr1.cpp
* @brief        Task3
* @task         1. Розробити функцію, яка визначає найдовше слово у заданому 
* символьному рядку і повертає довжину цього слова. На основі розробленої функції 
* визначити і надрукувати найдовше слово серед усіх слів групи введених речень. 
* @author       Volodymyr Spodaryk
* @email        spodaryk.volodymyr@i.ua
* ----------------------------------------------------------------------*/

#include "stdafx.h"
#include <iostream>
using namespace std;
//------------------------- prototype functions -----------------------//

/**
* @brief        Find next word
* @param[in]    string should be proceed
* @param[in/out]    number of character
* @param[in/out]    len of word, null if not found
* @return       pointer to text
*/
void FindNextWord(char *a, int &start, int &len);
/**
* @brief        Count size of string
* @param[in]    Pointer to a string
* @return       int size of string
*/
int sLen(const char *s);
/**
* @brief        Copy memory from Src to Dst
* @param[in]    char Pointer source
* @param[in]    char Pointer destination
* @post         Src and Dst points to equal strings
* @comment		use function sLen
* @return       pointer to dest
*/
char* sCpy(char *dst,const char *src);
/**
* @brief        Copy N bytes from Src to Dst
* @param[in]    char Pointer source
* @param[in]    char Pointer destination
* @param[in]    number of bytes
* @comment		use function sLen
* @post         Src and Dst points to equal strings
* @return       pointer to dest
*/
char* sCpy(const char *src, int n);
//--------------------------- main function ---------------------------//

int main(void)
{
	char *a = nullptr, tmp[250];
	int Max = 0, MaxS = 0;
	int start = 0, len = 0;

	cout << "Input any text (maxLength is 250 characters): " << endl;
	cin.getline	(tmp, 250);
	a = (char*) malloc (sizeof(char) * sLen(tmp) );
	sCpy(a, tmp);
	cout << endl;

	FindNextWord(a, start, len);
	while(len > 0)
	{	
		if(Max < len) 
		{
			MaxS = start;
			Max = len;
		}
		cout << "[" << len << "]: " << sCpy (a + start, len) << endl;
		FindNextWord(a, start, len);
	}

	cout << endl << "The longest inputed word is: " << "[" << Max << "]: " << sCpy (a + MaxS, Max) << endl;

	fflush(stdin);
	cin.get();
	return 0;
}

//------------------------ realization of prototype ------------------//

void FindNextWord(char* b, int &start, int &len)
{
	if (!b) return; //if null then exit
	start +=len;
	b += start;
	len = 0;
	if (!*b) return; //if end of string then doNothing

	while((*b < 65 || *b > 90) && (*b < 97 || *b > 122) && *b != '\0' && *b != '-') 
	{				// skip signs except A..Z, a..z
		b++;	
		start++;
	}
	while( (*b > 65 && *b < 90 || *b > 97 && *b < 122 ) && *b != '\0' && *b != 32 && *b != '-')
	{					// count 'good' signs
		b++;	
		len++;
	}
    return;
}
int sLen(const char *s)
{
	if(!*s && !s) return 0;	// null pointer or length = 0
    int c=0;
    while(*s++)
    {
            ++c;
    }
    return c;
}
char *sCpy(char *dst, const char *src) 
{ 
	int len = sLen(src);
    if(len == 0)
    {
            cout << "INPUT ERROR!!!";
            return 0;
    }
	while (*dst++=*src++) 
		; 
	return dst; 
}
char* sCpy(const char *src, int n)
{
    int len = sLen(src);
	char *dst;
    if(len == 0 || len < n)
    {
            cout << "INPUT ERROR!!!";
            return 0;
    }
	char *tmp = dst = (char*) malloc (sizeof(char) * (n+1));
	while (n--) 
	{
		*tmp = *src; 
		tmp++;
		src++;
	}
	*tmp = '\0';
	return dst; 
}