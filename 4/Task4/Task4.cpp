// !!!
// DOESN'T WORK PROPERLY
// !!!
/**
* @file         Task4.cpp
* @brief        Task4
* @task         "Is it a Tree?" Check inputed tree by rules
* 1) there is only only one root vertex
* 2) each vertex has only one parent
* 3) there is only one way from root to each vertex
*
* @author       Volodymyr Spodaryk
* @email        spodaryk.volodymyr@i.ua
* ----------------------------------------------------------------------*/

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Vertex {	
	int Info;
	int Parent;		// if (root) = 0
	int CCount;		//count of children
	int * Children; // pointer to children numbers
} **p = nullptr;	// massive of vertex

int NSize = 0;		//Count of vertex

//------------------------- prototype functions -----------------------//

/**
* @brief        add new vertex
* @param[in]    first parameter parent
* @param[in]    second parameter child
* @return       int - 0 if ok, else error
*/
int Add(unsigned int a, unsigned int b);
/**
* @brief        find vertex in massive
* @param[in]    index of vertex
* @return       Vertex* or NULL if not find
*/
Vertex * Exist(int a, bool newIfNotExist = false);
void Check()
{
/*	int s = 0;
	for (int i = 0; i < NSize; i++)
	{
		if ((*(p+i))->Parent == 0)
		{
			s++;
		}
		//cout << (*(p) + sizeof(Vertex *)*i) << endl;
		cout << "addrC: " << (*(p+i)) << endl;
	}*/
	//cout << c;
    for(int i=0; i<NSize; i++)
    {
            cout << "Show: " << p[i]->Info << "\t" << p[i]->Parent << p[i]->CCount << "\t" << p[i]->Children << "\t" << endl;
    }
}
//--------------------------- main function ---------------------------//

int main(void)
{
	int a, b;
	cout << "PROGRAM DOESN'T WORK PROPERLY!\n\n";
	cout << "Input numeric pair of vertex like 'parent child' \n(0 0 to end of input):\n" << endl;
	while (true)
	{
		while (true)	// while error in input repeat	
		{
				cin >> a >> b;	
				if (cin.good()) break;
				cin.clear();
				cin.sync();
				cout << "Error in input, try once more...\n(0 0 to end of input):\n";
		}
		if (a < 1 || b < 1)
		{
			break;			//exit from inputing
		}
		else
		{
			if (a == b)
			{
				cout << "Can't assign equal vertex!\n";
			}
			else
			{
				if ( !Add (a, b) )		// try to add pair
				{
					cout << "Successfully. (0 0) to end of input \n";
				}
				else
				{
					cout << "Error in adding new vertex";
				}
			}
		}
	}
	/*if (s > 1) 
	{
		cout << "Isn't a tree. Because has " << s << " roots or not connected to each other.";
	}
	else
	{
		cout << "It is a tree. There is a one root and all connected to it.";
	}*/
	/*for (int i = 0; i < NSize; i++)
	{
		cout << (*(p))->Children << endl;
	}*/

    system ("@pause");
    return 0;
}

//------------------------ realization of prototype ------------------//

inline void addChild(Vertex *p, int x)
{
	if (p->CCount > 0)
	{
		p->CCount++;
		p->Children = (int *) realloc (p->Children, p->CCount * sizeof(int));
	}
	else
	{
		p->CCount = 1;
		p->Children = (int *) malloc (sizeof(int));
	}
	*(p->Children + p->CCount - 1) = x;
}
int Add(unsigned int a, unsigned int b)
{
	Vertex *z;
	if (p == NULL) 
	{
		//allocate a
		NSize = 2;
		p = (Vertex **) malloc(sizeof(Vertex*));
		(*p) = (Vertex *) malloc (sizeof(Vertex));
		(*p)->Info = a;
		(*p)->Parent = 0;
		(*p)->CCount = 0;
		(*p)->Children = 0;
		addChild((*p), b);
		//allocate b
		z = Exist(b, true);
		z->Parent = a;
		cout << "addrI: " << (p) << endl;
		cout << "addrI: " << (z) << endl;
	}
	else
	{
		/*if( Exist(b) )
		{
			cout << "Can't add two parents to one vertex. See rules!\n";
		}
		else
		{*/
			z = Exist(a, true);
			addChild(z, b);
			
			//allocate b
			z = Exist(b, true);
			if (z->Parent)
			{
				cout << "Can't add two parents to one vertex. See rules!\n";
				
			}
			else
			{
				z->Parent = a;
			}
		//}
	}
	Check();
	return 0;
}
Vertex * Exist(int a, bool b)
{
	for (int i = 0; i < NSize; i++)
	{
		int e = p[i]->Info;
		//cout << "(*(p) + sizeof(Vertex *)*i)->Info: " << e << endl;
		if (e == a)
		{
			return p[i];
		}
	}
	if (b == true)
	{
		++NSize;
		p = (Vertex **) realloc(p, sizeof(Vertex*) * NSize);	//new address of element in massive
		p[NSize] = (Vertex *) malloc (sizeof(Vertex));		//new vertex 
		p[NSize]->Info = a;
		p[NSize]->Parent = 0;
		p[NSize]->Children = 0;
		p[NSize]->CCount = 0;
		
		cout << "addr: " << p[NSize] << endl;
		return p[NSize];
	}
	else
	{
		return 0;	
	}
}