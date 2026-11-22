/******************************************************************************
@file levelselect.c
@author Lu Yong Wei
@email L.yongwei@digipen.edu.sg
@course CSD1401 Software Engineering Project
@game Low Light
@brief Level select screen: loads its music and image, draws the buttons and detects which level is clicked.
@copyright Copyright (C) 2026 DigiPen Institute of Technology Singapore. All rights reserved.
******************************************************************************/

#include "cprocessing.h"
#include <stdio.h>
#include "utils.h"
#include "mainmenu.h"

//Calling on width and height
float width;												//LevelSelect Loads music and image, draws text, buttons and detects if circle clicked. Relies on function from my utils.c/h.
float height;

float exit_center_x, exit_center_y, exit_width, exit_height;

//Declaring colors
CP_Font myfont;
CP_Color grey;
CP_Color black;
CP_Color red;
CP_Color dred;
CP_Color blue;
CP_Color green;
CP_Color blank;
CP_Color white;
CP_Color gold;

//Declaring music and image
CP_Sound MainMenuMusic; //Music
CP_Image MainMenu; //Main menu image

//Calling on arrays for relevant info
float window_settings[2]; //Contains width and heigh
float exit_dimensions[4]; //Contains centre in x and y and width and height

float click_x;
float click_y;

void LevelSelect_Init(void)
{
	//Load stuff and colors
	MainMenu = CP_Image_Load("Assets/JapanImageNight1.jpg"); //Load background image
	myfont = CP_Font_Load("Assets/Atma-Medium.ttf"); //Load font
	MainMenuMusic = CP_Sound_LoadMusic("Assets/MainMenuMusic.mp3"); // Music
	grey = CP_Color_Create(128, 128, 128, 255);
	black = CP_Color_Create(0, 0, 0, 255);
	red = CP_Color_Create(230, 0, 10, 255);
	dred = CP_Color_Create(200, 50, 50, 255);
	blue = CP_Color_Create(0, 0, 255, 255);
	green = CP_Color_Create(0, 255, 0, 255);
	white = CP_Color_Create(255, 255, 255, 255);
	blank = CP_Color_Create(0, 255, 0, 0);
	gold = CP_Color_Create(255, 215, 0, 255);
	//Window size
	width = CP_System_GetWindowWidth();
	height = CP_System_GetWindowHeight();
	//Window size array setting
	window_settings[0] = width; //Declaring here cus cprocessing is only called in the init.
	window_settings[1] = height;//Didn't check but should work

	//Main menu button size reuses exit button array
	exit_center_x = width / 1.65;
	exit_center_y = (height /4) *3;
	exit_width = width / 8;
	exit_height = height / 8;
	//Exit button array
	exit_dimensions[0] = exit_center_x;
	exit_dimensions[1] = exit_center_y;
	exit_dimensions[2] = exit_width;
	exit_dimensions[3] = exit_height;

}

void LevelSelect_Update(void)
{
	//Audio stuff
	float songLength = 500;
	static float timer;
	timer += CP_System_GetDt();
	if (timer >= .5f * songLength)
	{
		CP_Sound_PauseGroup(CP_SOUND_GROUP_0); //Pause
	}
	if (timer >= songLength)
	{
		CP_Sound_ResumeGroup(CP_SOUND_GROUP_0); //Resume player
	}
	
	//Background and font
	CP_Graphics_ClearBackground(CP_Color_Create(128, 128, 128, 255));
	CP_Font_Set(myfont);

	//Background
	CP_Image_Draw(MainMenu, width/2, height/2, width, height, 255);
	
	//Level Select text
	Draw_Text(white, 200, "Level Select", width/3 + 10, height/7.5);

	//Level buttons
	for (int i = 0; i < 5; i++) //Loop to draw 5 buttons at once
	{
		Draw_Circle(white,white, width / 3.2 + 150 * i, height / 2, 100);
		Draw_Text(black, 80, (const char[2]) { '0' + (i + 1), '\0' }, width / 2.98 + 151 * i, height / 2 + 10);
		if (CP_Input_MouseClicked())
		{
			click_x = CP_Input_GetMouseX();
			click_y = CP_Input_GetMouseY();
			//Check if button is clicked
			if (IsCircleClicked(width / 3.2 + 150 * i, height / 2, 90, click_x, click_y) == 3)
			{
				CP_Sound_PauseGroup(CP_SOUND_GROUP_0);
				printf("clicked");
				//if (i = 1)
				//{
				//CP_Engine_SetNextGameState(LevelSelect_Init, LevelSelect_Update, LevelSelect_Exit); This might need some tweaking  yet to test
				//}
			}

		}
		//Watashi wa star

		if (IsMouseHovering(width / 3.2 + 150 * i, height / 2, 90, CP_Input_GetMouseX(), CP_Input_GetMouseY()) == 4)
		{
			//Star
			Draw_Star(gold, 400, 250);
			Draw_Star(gold, 600, 250);
			Draw_Star(gold, 800, 250);
			Draw_Star(gold, 1000, 250);
			Draw_Star(gold, 1200, 250);
			//Timer
			Draw_Text(white, 150, "00:00:00", width / 2 - 150, 210);
		}
	}
	//Main menu button
	Draw_Rect(white, width/2, height - 100, exit_dimensions[2], exit_dimensions[3], 0, 0);
	Draw_Text(black, 60, "Back", width / 2 + 15, height - 90);
	
	//Main menu button detection
	if (CP_Input_MouseClicked())
	{
		click_x = CP_Input_GetMouseX();
		click_y = CP_Input_GetMouseY();

		if (IsAreaClicked(width / 2, height / 1.2, exit_dimensions[2], exit_dimensions[3], click_x, click_y) == 1)
		{
			printf("Main Menu\n");
			CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
		}

	}
}

void LevelSelect_Exit(void)
{
	
}