/**
* @file         pr1.cpp
* @brief        Task2
* @task         1. З клавіатури ввести набір даних про книги у формі
<Автор>, <Найменування>, <Рік видання>, <Примітки>.
Роздрукувати введені дані у вигляді таблиці, відсортувавши їх в абетковому
порядку за прізвищами авторів.  Надрукувати список книг, виданих до 1970 року.

* @author       Volodymyr Spodaryk
* @email        spodaryk.volodymyr@i.ua
* ----------------------------------------------------------------------*/

#include <vcl.h>
//#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

#define NUMBER 2             //Number of books
#define SIZE 20         //Length of inputed string
struct Book{
        char *Author;
        char *BookName;
        char *Year;
        char *Tag;
};
enum
{
        AUTHOR, BOOK_NAME, YEAR, TAG
};
//------------------------- prototype functions -----------------------//

/**
* @brief        Fill fields in struct Book
* @param[in]    Array to fill
* @return       void
*/
void Fill(Book **p);
/**
* @brief        Show data in array
* @param[in]    Array to show
* @param[in]    Message before array
* @return       void
*/
void Show(Book **p,const char *c);
/**
* @brief        Show item from array
* @param[in]    Array to show
* @param[in]    index of item
* @return       void
*/
void Show(Book **p,const int i);
/**
* @brief        Free memory of Book
* @param[in]    Array to free
* @return       void
*/
void Remove(Book **p);
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
* @return       void
*/
void sCpy(char *dst,const char *src);
/**
* @brief        Compare 2 strings
* @param[in]    pointer to first string
* @param[in]    pointer to second string
* @return       0 if equal, -1 if upper
*/
int sCmp(char *str1,char *str2);
/**
* @brief        Sort Books by Field
* @param[in]    char Pointer source
* @param[in]    field follow which should be sorting
* @post         array of Book is sorted
* @return       void
*/
void SortBy(Book **p, char c);
/**
* @brief        Find Books by Field
* @param[in]    char Pointer source
* @param[in]    field follow which should be sorting
* @param[in]    param. for searching
* @return       void
*/
void Find(Book **p, char c, char *f);
//--------------------------- main function ---------------------------//

int main(void)
{
        Book *x[NUMBER];//tmp;
        cout << "Hello, this is a book-manager.\n"
                << "Input data about " << NUMBER
                << " books (Author, Book name, Year, Smth else about book): \n";
        Fill(x);
        clrscr();
        Show(x, "Inputed data:\n");
        SortBy(x, BOOK_NAME);
        cout << endl;
        Show(x, "Sorted data:\n");
        Find(x, YEAR, "1970");

        Remove(x);
//        cin.get();
        getch();
        return 0;
}

//------------------------ realization of prototype ------------------//
void Fill(Book **p)
{
        char tmpA[SIZE], tmpB[SIZE], tmpY[SIZE], tmpT[SIZE];
        for(int i=0;i<NUMBER;i++)
        {
                cout << "[" << i+1 << "]: ";
                cin >> tmpA >> tmpB >> tmpY >> tmpT;
                p[i] = (Book*) malloc (sizeof(Book));
                //memcpy(x[i],&tmp,sizeof(Book));

                p[i]->Author = (char*)malloc(sizeof(char) * sLen(tmpA));
                sCpy(p[i]->Author,tmpA);
                p[i]->BookName = (char*)malloc(sizeof(char) * sLen(tmpB));
                sCpy(p[i]->BookName,tmpB);
                p[i]->Year = (char*)malloc(sizeof(char) * sLen(tmpY));
                sCpy(p[i]->Year,tmpY);
                p[i]->Tag = (char*)malloc(sizeof(char) * sLen(tmpT));
                sCpy(p[i]->Tag,tmpT);
        }
}
void Show(Book **p,const char *c)
{
        cout << c;
        for(int i=0; i<NUMBER; i++)
        {
                cout << p[i]->Author << "\t"
                        << p[i]->BookName << "\t"
                        << p[i]->Year << "\t"
                        << p[i]->Tag << endl;
        }
}
void Show(Book **p,const int i)
{
        cout << p[i]->Author << "\t"
                << p[i]->BookName << "\t"
                << p[i]->Year << "\t"
                << p[i]->Tag << endl;
}
void Remove(Book **p)
{
        for(int i=0; i<NUMBER; i++)
        {
                delete p[i]->Author;
                delete p[i]->BookName;
                delete p[i]->Tag;
                delete p[i]->Year;
                delete p[i];
        }
}
int sLen(const char *s)
{
        int c=0;
        while(*s)
        {
                ++c;
                ++s;
        }
        return c;
}
void sCpy(char *dst,const char *src)
{
        int len = sLen(src);
        if(len==0)
        {
                cout<<"INPUT ERROR!!!";
                return;
        }
        char *p = (char*)malloc((len + 1) * sizeof(char));
        memcpy(p, src, len);
        *(p + len + 1)='\0';
        memcpy (dst, p, len + 1);
        return;
}
void SortBy(Book **p, char c)
{
        Book *tmp;
        for(int i=0; i < NUMBER; i++)
                for(int j=i+1; j < NUMBER; j++)
                {
                        if(sCmp(((p[i]->Author)),((p[j]->Author))) == 1)
                        {                        // need to compare like:
                                                 // &(p[j]->Author)+c*sizeof(char*)
                                tmp = p[i];
                                p[i] = p[j];
                                p[j] = tmp;
                        }

                }
        return;
}
int sCmp(char *str1, char *str2)
{
        while (*str1 == *str2)
        {
                if( *(str1) == '\0' && *(str2) == '\0')return 0;
                ++str1;
                ++str2;
        }
        return *str1>*str2?1:-1;
}
void Find(Book **p, char c, char *f)
{
        char *s;
        bool found;
        cout << endl << endl << "Found ('" << f << "'): ";
        for(int i=0; i < NUMBER; i++)
        {
                switch(c)
                {
                        case AUTHOR: s = p[i]->Author; break;
                        case BOOK_NAME:   s = p[i]->BookName; break;
                        case YEAR: s = p[i]->Year; break;
                        case TAG:    s = p[i]->Tag; break;
                }
                if (sCmp(s, f) == 0)
                {
                        Show(p,i);
                        found = true;
                }
        }
        if (!found) cout << "0";
}
