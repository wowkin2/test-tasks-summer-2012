/**
* @file         pr7.cpp
* @brief        Task2
* @task         7. З клавіатури ввести набір даних про книги у формі:
<Автор>, <Найменування>, <Видавництво>, <Рік видання>.
Надрукувати введений список книг у вигляді таблиці,
згрупувавши їх за роками видань у спадному порядку.
Роздрукувати дані про книги з програмування мовою C/C++.

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
        char *Publisher;
        char *Year;
};
enum
{
        AUTHOR, BOOK_NAME, PUBLISHER, YEAR
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
/**
* @brief        Find Substring 'f' in 's'
* @param[in]    pointer to string for searching
* @param[in]    string should be found
* @return       int, number of position if found, else 0
*/
int sFnd(char *s, char *f);
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
        SortBy(x, YEAR);
        cout << endl;
        Show(x, "Sorted data:\n");
        Find(x, BOOK_NAME, "C++");

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
                p[i]->Publisher = (char*)malloc(sizeof(char) * sLen(tmpT));
                sCpy(p[i]->Publisher,tmpT);
        }
}
void Show(Book **p,const char *c)
{
        cout << c;
        for(int i=0; i<NUMBER; i++)
        {
                cout << p[i]->Author << "\t"
                        << p[i]->BookName << "\t"
                        << p[i]->Publisher << "\t"
                        << p[i]->Year << endl;
        }
}
void Show(Book **p,const int i)
{
        cout << "[" << i << "]: "
                << p[i]->Author << "\t"
                << p[i]->BookName << "\t"
                << p[i]->Publisher << "\t"
                << p[i]->Year << endl;
}
void Remove(Book **p)
{
        for(int i=0; i<NUMBER; i++)
        {
                delete p[i]->Author;
                delete p[i]->BookName;
                delete p[i]->Publisher;
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
                        if(sCmp(((p[i]->Year)),((p[j]->Year))) == -1)
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
                        case PUBLISHER:    s = p[i]->Publisher; break;
                }
                if (sFnd(s, f) >= 0)
                {
                        Show(p,i);
                        found = true;
                }
        }
        if (!found) cout << "0";
}
int sFnd(char *s, char *f)
{
        int k = StrLen(f);
        int i, j = 0;
        while (*(s + j + k - 1))
        {
                for(i=0; i<k; i++)
                {
                        if (*(s + i + j) != *(f+i)) break;
                }
                if (i == k) return j;
                ++s;
        }
        return -1;
}
