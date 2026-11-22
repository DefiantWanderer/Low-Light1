/******************************************************************************
@file main.c
@author Lu Yong Wei
@email L.yongwei@digipen.edu.sg
@course CSD1401 Software Engineering Project
@game Low Light
@brief Program entry point. Sets the window size and starts the CProcessing engine at the main menu.
@copyright Copyright (C) 2026 DigiPen Institute of Technology Singapore. All rights reserved.
******************************************************************************/

#include "cprocessing.h"
#include "mainmenu.h"
#include "level1.h"
#include "utils.h"
#include "story.h"
#include "loadingscreen.h"


// main() the starting point for the program
// CP_Engine_SetNextGameState() tells CProcessing which functions to use for init, update and exit
// CP_Engine_Run() is the core function that starts the simulation
int main(void)
{
	//CP_Engine_SetNextGameState(StoryScreen_Init, StoryScreen_Update, StoryScreen_Exit);
	//CP_Engine_SetNextGameState(LoadingScreen_Init, LoadingScreen_Update, LoadingScreen_Exit);
	//CP_Engine_SetNextGameState(Level1_Init, Level1_Update, Level1_Exit);
	CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	CP_System_SetWindowSize(1600, 900);
	CP_Engine_Run(0);
	return 0;
}
