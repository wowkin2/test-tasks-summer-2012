#ifndef __USEDLL_H__
#define __USEDLL_H__

#include "stdafx.h"
#include <iostream>
#include <windows.h> 

#define DllImport __declspec( dllimport)

typedef unsigned char UNC;
struct Pole 
{	//count of players, size and 9 (3x3) fields
	UNC plCount;
	UNC size;
	UNC *data; 
};	//11 bytes ???

typedef void  (*FFFIN) (Pole *);
typedef Pole* (*FFOUT) (void);
typedef UNC   (*FFUNC) (Pole *);
typedef UNC   (*FFSTP) (Pole *, UNC, UNC);
typedef Pole* (*FFCRP) (UNC, UNC);
typedef bool  (*FFCHO) (UNC, UNC);

/************** dll function pointers (project prototypes =) )***************/

/**
* @brief        create new field in memory
* @param[in]    UNC players Count
* @param[in]    UNC size of pole to create
* @return       pointer to the new field
*/
Pole* (*CreatePole)(UNC playerCount, UNC poleSize); 
/**
* @brief        destroy existing field in memory
* @param[in]    pointer to field
* @return       void
*/
void (*DestroyPole)(Pole *ptr);
/**
* @brief        check state of field (win, draw, etc.)
* @param[in]    pointer to field
* @return       UNC state
*	// 0 empty
*	// N<10 except 0 - player N win
*	// 11	still playing
*	// 12	draw (all fields are filled but nobody win)
*	// 13	smth is wrong 
*/
UNC (*GetState)(Pole *ptr);
/**
* @brief        clear all fields of pole
* @param[in]    pointer to field
* @return       void
*/
void (*ClearPole)(Pole *ptr);
/**
* @brief        make step of player
* @param[in]    pointer to field
* @param[in]    number of field 
* @param[in]    player
* @tag			coord numerate from 0 to N-1
* @return       UNC state
*/
UNC (*MakeStep)(Pole *ptr, UNC x, UNC player);
/**
* @brief		show 'pole' on the screen
* @param[in]	field pointer to show
* @return		void
*/
void (*ShowPole)(Pole *ptr);
/**
* @brief		contain logic: who can win or it is draw
* @param[in]	field pointer to show
* @return		UNC state
*/
UNC (*RuleLogic)(Pole *ptr);
/**
* @brief		contain logic of CPU
* @param[in]	field pointer
* @return		UNC cell
*/
UNC (*LogicCPU)(Pole *ptr);
/**
* @brief		choice the type of game
* @param[in]	GameType	0 - Pl vs. Pl, 1 - Pl vs. CPU, 2 - CPU vs. CPU
* @param[in]	current player number
* @return		bool opportunity to make move of CPU
*/
bool (*ChoicePlayer)(UNC GameType, UNC Current);

/*********************************-------------------******************************/
/********************************| program functions |*****************************/
/*********************************-------------------******************************/
/**
* @brief		check if Pole is empty, if not notify to clear (can clear)
* @param[in]	field pointer to show
* @return		UNC (0 if clear or creared, 1 if not empty)
*/
UNC EmptyNotify(Pole *ptr);
/**
* @brief		control of game proccess
* @param[in]	field pointer to show
* @return		UNC result of game (win, draw, etc.)
*/
UNC StartGame(Pole *ptr);

#endif __USEDLL_H__