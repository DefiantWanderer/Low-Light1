/******************************************************************************
@file loadingscreen.h
@author Lu Yong Wei
@email L.yongwei@digipen.edu.sg
@course CSD1401 Software Engineering Project
@game Low Light
@brief Declarations for the loading screen game state and the per-level story text.
@copyright Copyright (C) 2026 DigiPen Institute of Technology Singapore. All rights reserved.
******************************************************************************/

#pragma once

#include "cprocessing.h"

char* level1story[10];
char* level2story[10];
char* level3story[10];

void LoadingScreen_Init(void);
void LoadingScreen_Update(void);
void LoadingScreen_Exit(void);