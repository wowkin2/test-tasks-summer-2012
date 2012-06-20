/**
* @file         pr1.cpp
* @brief        Task3
* @task         7.	Розробити функцію, яка вилучає з речення слово, задане 
* своїм порядковим номером (якщо таке слово є в реченні).  
* На основі розробленої функції вилучити друге та п’яте слово 
* з введеного речення. Роздрукувати результат вилучення.

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
* @param[in]    number of characters
* @comment		use function sLen
* @post         Src and Dst points to equal strings
* @return       pointer to dest
*/
char* sCpy(const char *src, int n);
/**
* @brief        Check for forbidden combination
* @param[in]    char Pointer source
* @param[in]    char Pointer destination
* @param[in]    forbidden combination
* @comment		use function sLen
* @return       bool true if OK
*/
bool CheckWord(const char *src, int n, const char *forbChar);
//--------------------------- main function ---------------------------//

int main(void)
{
	char *a = nullptr, *b = nullptr, tmp[250];
	int start = 0, len = 0, c = 0;

	cout << "Input any text (maxLength is 250 characters): " << endl;
	cin.getline	(tmp, 250);
	a = (char*) malloc (sizeof(char) * sLen(tmp) );
	sCpy(a, tmp);
	cout << endl;

	cout << "Checked text: " << endl;
	FindNextWord(a, start, len);
	while( len > 0 )
	{	
		c++;
		if (c != 2 && c != 5)
		{
			cout << sCpy (a + start, len) << " ";
		}
		FindNextWord(a, start, len);
	}
	cout << endl;
	

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
bool CheckWord(const char *src, int n, const char *forbChar)
{
	for(int i = 0; i < n; i++)
	{
		while(*(src + i) == *forbChar)
		{
			src++;
			forbChar++;
			if (*forbChar == '\0') return false;
		}
	}
	return true;
}