/******************************************************************************
@file mainmenu.h
@author Lu Yong Wei
@email L.yongwei@digipen.edu.sg
@course CSD1401 Software Engineering Project
@game Low Light
@brief Declarations for the main menu game state and its lamp light helper functions.
@copyright Copyright (C) 2026 DigiPen Institute of Technology Singapore. All rights reserved.
******************************************************************************/

#pragma once

void Main_Menu_Init(void);
void Main_Menu_Update(void);
void Main_Menu_Exit(void);
int DrawMainMenuLight();
void MainMenuLightBounce(void);
int  MainMenulampclicked(void);
void lampintersectalpha(struct platformdata *arr, int numberof, int maxalpha);