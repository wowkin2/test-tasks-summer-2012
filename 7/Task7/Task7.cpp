/**
* @file         Task7.cpp
* @brief        Task7
* @task         All tasks in Task7 see ReadmeTask7.txt
*
* @author       Volodymyr Spodaryk
* @email        spodaryk.volodymyr@i.ua
* ----------------------------------------------------------------------*/
#include "stdafx.h"
#include <iostream>
using namespace std;
typedef unsigned int UI;
//------------------------- prototype functions -----------------------//

/**
* @class	List
* @brief	one-way linear list
* basic methods:  add to front, add to Last, show all, check if empty
*
* @author       Volodymyr Spodaryk
* @email        spodaryk.volodymyr@i.ua
*/
#ifndef NULL
#define NULL 0 
#endif

template <class T> class List
{
	struct Node {		// element of list
		T data;				// element data
		Node *next;		// ptr to next element
		Node()
		{
			data = 0;
			next = NULL;
		}
	};
	Node *pHead;			// ptr to first element
	Node *pLast;			// ptr to last element
	UI cntNode;			// count of elements
public :
    List();
    ~List();
/**
* @brief        Push element in front of list (stack)
* @param[in]    element to push
* @return       true if push, false if smth wrong
*/
    bool addHead(T data);
/**
* @brief        Push element in Last of list (deque)
* @param[in]    element to push
* @return       true if push, false if smth wrong
*/
    bool addLast(T data);
/**
* @brief        return element from front of list (stack)
* @return       value if OK, else NULL
*/
    inline T getHead();
/**
* @brief        return element from Last of list (deque)
* @return       value if OK, else NULL
*/
    inline T getLast();
/**
* @brief        return element
* @param[in]    element to return
* @return       value if OK, else NULL
*/
    inline T getNode(Node *p);
/**
* @brief        insert element in after other element
* @param[in]    prev element
* @param[in]    element to insert
* @return       true if push, false if smth wrong
*/
    bool insAfter(T prev,T data);
/**
* @brief        show all elements in list
* notify if list is empty 
* @return       void
*/
    void print();
/**
* @brief        show one elements in list
* @param[in]    element to show
* @return       void
*/
	void print(Node *p);
/**
* @brief        find element by value
* @param[in]	value to search
* @return       ptr to first acceptable element if exist, else 0
*/
	typename Node* findNode(T x);
/**
* @brief        delete element from Head
* @return       true if ok
*/
    bool delHead();
/**
* @brief        delete element Last (Stack)
* @return       true if ok
*/
    bool delLast();
/**
* @brief        delete element by value
* @param[in]	value to delete
* @return       true if ok
*/
    bool delNode(T x);
/**
* @brief        delete element by pointer
* @param[in]	pointer to element
* @return       true if ok
*/
    bool delNode(Node *x);
/**
* @brief        delete all elements from list
* @return       void
*/
    void delAllList();
/**
* @brief        check if list is empty
* @return       empty state
*/
    inline bool IsEmpty();
/**
* @brief        find max element
* @return       ptr to max element, on error return 0
*/
	typename Node* getMax();
/**
* @brief        find min element
* @return       ptr to min element, on error return 0
*/
	typename Node* getMin();
/**
* @brief        sort all elements in list
* @return       void
*/
	void Sort();
/**
* @brief        check if list is sorted
* @return       true if sorted, false if not
*/
	bool IsSorted();
/**
* @brief        print list items in back order
* param[in]		element to start
* param[in]		element to finish
* @return       void
*/
	void printBack(Node *from, Node *to);
/**
* @brief        count elements with equal neighbours
* @return       UI count of neighbours
*/
	UI countEqNbrs();
/**
* @brief        delete elements with equal neighbours
* @return       void
*/
	void delEqNbrs();
/**
* @brief        delete element if data already exist
* @return       void
*/
	void delTwice();
/**
* @brief        doubles all elements
* @return       void
*/
	void genTwice();
};
//--------------------------- main function ---------------------------//
int main(void)
{
	List <UI> list;
	UI tmp;
	UI tmp2;
	while (true)
	{
		cout << "Input numbers (0 - to finish input):\n";
		cin.clear();
		cin >> tmp;
		if (cin.good())
		{
			if (tmp == 0)
			{
				cout << "--------------\n";
				break;
			}
			else
				list.addLast(tmp);
		}
	}
	UI choice = 0;
	while (choice != 27)
	{
		system("cls");
		cout << "Choice the method to proceed this list:\n"
			"1  - Add element in deque\n"	// and must be add random!!!
			"2  - Insert element after other\n"
			"3  - Check for empty\n"
			"4  - Clear List\n"
			"5  - Check for sorted\n"
			"6  - Sort list\n"
			"7  - Print list\n"
			"8  - Print list from min to max\n"
			"9  - Print Max\n"
			"10 - Print Min\n"
			"11 - Remove repeating numbers\n"
			"12 - Add double numbers\n"
			"13 - Count numbers with equal neighbours\n"
			"14 - Delete numbers with equal neighbours\n";
		cin.clear();
		cin >> choice;
		switch(choice)
		{
		case 1:
			tmp = NULL;
			cin.clear();
			cout << "Input element to add to list: ";
			cin >> tmp;
			if (cin.good())
				if (tmp != 0)
					if (list.addLast(tmp) == true)
					{
						cout << "Successfully added: " << tmp << "\n";
						break;
					}
			cout << "Can't add this element\n";
			break;
		case 2:
			tmp = tmp2 = NULL;
			cin.clear();
			cout << "Input element to add to list, and number that must be before it: ";
			cin >> tmp >> tmp2;
			if (cin.good())
				if (tmp != 0 && tmp2 != 0)
					if (list.insAfter(tmp2, tmp) == true)
					{
						cout << "Successfully added: " << tmp << "\n";
						break;
					}
			cout << "Can't add this element\n";
			break;
		case 3:
			if (list.IsEmpty())
				cout << "List is empty\n";
			else
				cout << "List is not empty\n";
			break;
		case 4:
			if (list.IsEmpty())
				cout << "List is empty\n";
			else
			{
				list.delAllList();
				if (list.IsEmpty())
					cout << "List is empty\n";
				else
					cout << "Can't clear List\n";
			}
			break;
		case 5:
			if (list.IsSorted())
				cout << "List is sorted\n";
			else
				cout << "List is not sorted\n";
			break;
		case 6:
			if (list.IsSorted())
				cout << "List is sorted\n";
			else
			{
				list.Sort();
				if (list.IsSorted())
					cout << "List is sorted\n";
				else
					cout << "Can't sort List\n";
			}
			break;
		case 7:
			list.print();
			break;
		case 8:
			cout << "List from min to max:\n";
			list.printBack(list.getMin(), list.getMax());
			break;
		case 9:
			tmp = NULL;
			if ((tmp = list.getNode(list.getMax())) != NULL)
				cout << "Max element is: " << tmp << endl;
			else
				cout << "Can't get max element\n";
			break;
		case 10:
			tmp = NULL;
			if ((tmp = list.getNode(list.getMin())) != NULL)
				cout << "Min element is: " << tmp << endl;
			else
				cout << "Can't get min element\n";
			break;
			break;
		case 11:
			list.delTwice();
			cout << "Deleted elements with repeating numbers\n";
			break;
		case 12:
			list.genTwice();
			cout << "Added double numbers\n";
			break;
		case 13:
			cout << "There are '" << list.countEqNbrs() << "' with equal neighbours\n";
			break;
		case 14:
			list.delEqNbrs();
			cout << "Deleted elements with equal neighbours\n";
			break;
		case 27:
			break;
		default:
			break;
		}
		system("@pause");
	}
	
	//catch(...){ cout << "Error\n"; }
	/* // Without huge menu
	// (16)
	if ( !list.IsEmpty() )
	{
		// (1)
		list.insAfter(2, 5);
		list.insAfter(1, 7);
		// (2)
		cout << "Max. element is: " << list.getMax()->data << "\n";
		// (11)
		cout << "From min to max:\n";
		list.printBack(list.getMin(), list.getMax());
		list.print();
		// (3), (5)
		if (list.IsSorted() == false)
		{
			cout << "Need to sort list...\n";
			list.Sort();
			list.print();
		}
		list.delAllList();
	}
	else
	{
		cout << "List is empty...\n";
	}*/
	list.delAllList();
	system ("@pause");
	return 0;
}

//------------------------ realization of prototype ------------------//
// class List 
template <class T> List<T>::List()
{
    pHead = pLast = NULL;
    cntNode = 0;
}
template <class T> List<T>::~List()
{
    delAllList();
}
template <class T>bool List<T>::addHead(T data) //void(*)(const int&).
{
    Node *temp = new Node;
	if (temp)
	{
		temp->next = pHead;
		pHead = temp;
		if(pLast == NULL)
		{
			pLast = pHead;
		}
		pHead->data = data;
		++cntNode;
		return true;
	}
	else
		return false;
}
template <class T>bool List<T>::addLast(T data)
{
    Node *temp = new Node;
	if (temp)
	{
		if(pHead == NULL)
			pHead = temp;
		else
			pLast->next = temp;

		temp->data = data;
		temp->next = NULL;
		pLast = temp;
		++cntNode;
		return true;
	}
	else
		return false;
}
template <class T>T List<T>::getHead()
{
	if (pHead)
		return pHead->data;
	else
		return NULL;
}
template <class T>T List<T>::getLast()
{
	if (pLast)
		return pLast-data;
	else
		return NULL;
}
template <class T>T List<T>::getNode(Node *p)
{
	if (p)
		return p->data;
	else
		return NULL;
}
template <class T>bool List<T>::insAfter(T prev,T data)
{
	Node *prevPtr = NULL;
	if ( (prevPtr = findNode(prev)) == 0 ) return false;
    Node *temp = new Node;
	if (temp)
	{
		if (prevPtr == pLast)
			pLast = temp;
		temp->next = prevPtr->next;
		prevPtr->next = temp;
		temp->data = data;
		++cntNode;
		return true;
	}
	else
		return false;
}
template <class T>void List<T>::print()
{
	Node *pTemp = pHead;
	if (!IsEmpty()) {
		cout << "List items:\n";
		while(pTemp != NULL)
		{
			cout << pTemp->data << endl;
			pTemp = pTemp->next;
		}
	}
	else
	{
		cout << "List is empty\n";
	}
}
template <class T>void List<T>::print(Node *p)
{
	if (p != NULL)
			cout << p->data << endl;
}
template <class T>typename List<T>::Node* List<T>::findNode(T x)
{
	Node *pTemp = pHead;
	if (pHead == NULL) return NULL;
	while( !(pTemp->data == x) )
    {
        if ((pTemp = pTemp->next) == NULL) return NULL;	// if end of list and not found
    }
	if (pTemp->data == x)
		return pTemp;
	//else
		return NULL;
}
template <class T>bool List<T>::delHead()
{
	if (pHead != NULL)
		return delNode(pHead);
	else
		return false;
}
template <class T>bool List<T>::delLast()
{
	if (pLast != NULL)
		return delNode(pLast);
	else 
		return false;
}
template <class T>bool List<T>::delNode(Node *tmp)
{
	if (tmp != NULL)
	{
		if(tmp == pHead)	// if need to delete first element
		{
			pHead = tmp->next;
		}
		else				// if need to delete other
		{
			Node *tmpPr = NULL;
			for(Node *tmpPr = pHead; tmpPr->next != tmp; tmpPr = tmpPr->next);
			tmpPr->next=tmpPr->next->next;
			pLast = tmpPr;
		}
		memset(tmp, 0, sizeof(T));
        delete tmp;
		cntNode--;
		return true;
	}
	else
	{
		return false;
	}
}
template <class T>bool List<T>::delNode(T x)
{
	return delNode(findNode(x));
}
template <class T>void List<T>::delAllList()
{
    while(pHead != NULL)
    {
        Node *pTemp = pHead;
        pHead = pHead->next;
		memset(pTemp,0,sizeof(T));
        delete pTemp;
		cntNode--;
    }
}
template <class T>bool List<T>::IsEmpty()
{
	return (cntNode == 0 && pHead == 0);
}
template <class T>typename List<T>::Node* List<T>::getMax()
{
	if ( IsEmpty() ) return NULL;
	Node *pTemp = pHead;
	T max = pTemp->data;
	Node *maxPtr = pTemp;
	while(pTemp != NULL)
    {
		if (max < pTemp->data) 
		{
			maxPtr =  pTemp;
			max =  pTemp->data;
		}
        pTemp = pTemp->next;
	}
	return maxPtr;
}
template <class T>typename List<T>::Node* List<T>::getMin()
{
	if ( IsEmpty() ) return NULL;
	Node *pTemp = pHead;
	T min = pTemp->data;
	Node *minPtr = pTemp;
	while(pTemp != NULL)
    {
		if (min > pTemp->data) 
		{
			minPtr =  pTemp;
			min =  pTemp->data;
		}
        pTemp = pTemp->next;
	}
	return minPtr;
}
template <class T>void List<T>::Sort()
{	// Insertion Sort
	Node *pStart = pHead, *tmpCurr, *tmpNext;
	for (UI i = 1; i < cntNode; i++)
	{
		tmpCurr = pStart, 
		tmpNext = tmpCurr->next;
		while (tmpNext != NULL && tmpCurr->data > tmpNext->data)
		{
			swap(tmpCurr->data, tmpNext->data);
			
			tmpCurr = tmpNext;
			tmpNext = tmpNext->next;
		}
		pStart = pStart->next;
	}
}
template <class T>bool List<T>::IsSorted()
{
	Node *tmpCurr = pHead, *tmpNext = NULL;
	if (tmpCurr) tmpNext = tmpCurr->next;
	while (tmpNext != NULL && tmpCurr->data < tmpNext->data)
	{		
		tmpCurr = tmpNext;
		tmpNext = tmpNext->next;
	}
	return (tmpNext == NULL);
}
template <class T>void List<T>::printBack(Node *from, Node *to)
{
	while (from != NULL && from != to)
	{
		print(from);
		from = from->next;
	}
	print(from);
}
template <class T>UI List<T>::countEqNbrs()
{
	Node *pPrev = pHead, *pCurr = NULL;
	if (pPrev) pCurr = pPrev->next;

	UI cnt = 0;
	if (!IsEmpty()) {
		while(pCurr->next != NULL)
		{
			if (pPrev->data == pCurr->next->data) ++cnt;
			pPrev = pPrev->next;
			pCurr = pPrev->next;
		}
	}
	return cnt;
}
template <class T>void List<T>::delEqNbrs()
{
	Node *pPrev = pHead, *pCurr = NULL;
	if (pPrev) pCurr = pPrev->next;

	if (!IsEmpty()) {
		while(pCurr->next != NULL)
		{
			if (pPrev->data == pCurr->next->data)
				delNode(pCurr);
			pPrev = pPrev->next;
			pCurr = pPrev->next;
		}
	}
}
template <class T>void List<T>::delTwice()
{
	Node *pCurr = pHead, *toDel = NULL;
	if (!IsEmpty()) {
		while(pCurr != NULL)
		{
			while (toDel = findNode(pCurr->data))
			{	// while found equal data, delete it (must be = not ==)
				delNode(toDel);
			}
			if (pCurr->next)
				pCurr = pCurr->next;
		}
	}
}
template <class T>void List<T>::genTwice()
{
	Node *pEnd = pLast, *pCurr = pHead;
	if (!IsEmpty()) {
		if (pLast == pHead)
		{
			addLast(pCurr->data);
		}
		else
		{
			while(pCurr != pEnd)
			{
				addLast(pCurr->data);
				pCurr = pCurr->next;
			}
		}
	}
}
/**
+1)	+<<
	+>>
	insertAfter(what, prev)
	+delElem(T x)

+2)	getMax

+3)	sortUp

-4)	*genPercent
	+getMax

+5)	bool IsSorted
	-sortUp

6)	divBySign

7)	combUp

8)

9)	delTwice
	setTwice

10)

+11)	printBack
	+<
	+>
	+getMin
	+getMax

13)	==
	countEqNbrs
	delEqNbrs

+14)	delLast
	+addLast
	+isEmpty

+15)	delHead
	+addHead

+16)	+delAllList
	+isEmpty
*/