
#ifndef funHH
#define funHH

#define DllExport __declspec( dllexport)

//------------------------- typedefs and structs -----------------------//
typedef unsigned char UNC;
extern "C" struct DllExport Pole 
{	//count of players, size and 9 (3x3) fields
	UNC plCount;
	UNC size;
	UNC *data; 
};	//11 bytes ???
//------------------------- prototype functions -----------------------//

/**
* @brief        create new field in memory
* @param[in]    UNC players Count
* @param[in]    UNC size of pole to create
* @return       pointer to the new field
*/
extern "C" DllExport Pole* CreatePole(UNC playerCount, UNC poleSize); 
/**
* @brief        destroy existing field in memory
* @param[in]    pointer to field
* @return       void
*/
extern "C" DllExport void DestroyPole(Pole *ptr);
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
extern "C" DllExport UNC GetState(Pole *ptr);
/**
* @brief        clear all fields of pole
* @param[in]    pointer to field
* @return       void
*/
extern "C" DllExport void ClearPole(Pole *ptr);
/**
* @brief        make step of player
* @param[in]    pointer to field
* @param[in]    number of field 
* @param[in]    player
* @tag			coord numerate from 0 to N-1
* @return       UNC state
*/
extern "C" DllExport UNC MakeStep(Pole *ptr, UNC x, UNC player);
/**
* @brief		show 'pole' on the screen
* @param[in]	field pointer to show
* @return		void
*/
extern "C" DllExport void ShowPole(Pole *ptr);
/**
* @brief		contain logic: who can win or it is draw
* @param[in]	field pointer to show
* @return		UNC state
*/
extern "C" DllExport UNC RuleLogic(Pole *ptr);
/**
* @brief		contain logic of CPU
* @param[in]	field pointer
* @return		UNC cell
*/
extern "C" DllExport char LogicCPU(Pole *ptr);
/**
* @brief		check if Pole is empty, if not notify to clear (can clear)
* @param[in]	field pointer to show
* @return		UNC (0 if clear or creared, 1 if not empty)
*/
extern "C" DllExport UNC EmptyNotify(Pole *ptr);
/**
* @brief		control of game proccess
* @param[in]	field pointer to show
* @return		UNC result of game (win, draw, etc.)
*/
extern "C" DllExport UNC StartGame(Pole *ptr);
/**
* @brief		choice the type of game
* @param[in]	GameType	0 - Pl vs. Pl, 1 - Pl vs. CPU, 2 - CPU vs. CPU
* @param[in]	current player number
* @return		bool opportunity to make move of CPU
*/
extern "C" DllExport bool ChoicePlayer(UNC GameType, UNC Current);

#endif
