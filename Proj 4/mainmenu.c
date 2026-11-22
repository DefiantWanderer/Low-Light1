/******************************************************************************
@file mainmenu.c
@author Lu Yong Wei
@email L.yongwei@digipen.edu.sg
@course CSD1401 Software Engineering Project
@game Low Light
@brief Main menu screen: draws the title, the bouncing lamp light and the start/exit buttons, and plays the menu music.
@copyright Copyright (C) 2026 DigiPen Institute of Technology Singapore. All rights reserved.
******************************************************************************/

#include "cprocessing.h"
#include <stdio.h>
#include "utils.h"
#include "levelselect.h"
#include "level1.h"
#include "mainmenu.h"
#include "loadingscreen.h"
#include "story.h"
#include "sound.h"

// MainMenu edits
// Alpha works, now just try to implement different colors to make the words more obvious. I think just need to increase the alpha of the orange or change to white.
// Yet to create pulsating light.

float windowWidth;
float windowHeight;
float textoffset;

int mainlightlevel = 5;
CP_Vector playerposition;
float lanternoffset;
float lanternwidth;
float lanternheight;
float mainlightradiusarray[5] = { 10.f, 50.f, 100.f, 175.f, 275.f };
float MMlamppickup = 0;
float MMlampclicked = 0;

float bouncetimer = 0;
float bouncestate = 0;
float dt;

int alpha = 5;

int level =1;
int princessdown = 0;
int lampbreak = 0;
int storymode = 1;

float play_center_x, play_center_y, play_width, play_height;
float exit_center_x, exit_center_y, exit_width, exit_height;

CP_Font myfont; //cpfont is a pointer to a struct
CP_Image LanternImage;
CP_Color grey;
CP_Color black;
CP_Color red;
CP_Color dred;
CP_Color blue;
CP_Color green;
CP_Color blank;
CP_Color white;
CP_Color blackalpha;
CP_Color whitealpha;
CP_Color grey1;
CP_Color grey2;
CP_Color grey3;
CP_Color grey4;
CP_Color orangealpha;

//Illumination colors
CP_Color orange;
CP_Color amber;
CP_Color goldenyellow;
CP_Color strokeorange;
CP_Color strokeamber;
CP_Color strokegoldenyellow;
CP_Color gold;
CP_Color transparent;

CP_Sound MainMenuMusic = NULL; //Music
CP_Image MainMenu = NULL;


struct platformdata playbutton;
struct platformdata exitbutton;
struct platformdata lowlight;

float window_settings[2]; //Contains width and height
float play_dimensions[4]; //Contains centre in x and y and width and height
float exit_dimensions[4];

int soundplay = 0;
int lampstart = 0;

float click_x;
float click_y;

void Main_Menu_Init(void)
{
	//Load stuff and colors
	myfont = CP_Font_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/Atma-Medium.ttf"); //Load font
	//myfont = CP_Font_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/Alike-Regular.ttf");
	LanternImage = CP_Image_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/Lantern.png");
	grey = CP_Color_Create(128, 128, 128, 255);
	black = CP_Color_Create(0, 0, 0, 255);
	red = CP_Color_Create(230, 0, 10, 255);
	dred = CP_Color_Create(200, 50, 50, 255);
	blue = CP_Color_Create(0, 0, 255, 255);
	green = CP_Color_Create(0, 255, 0, 255);
	


	//Play with this alpha to reveal
	white = CP_Color_Create(255, 255, 255, 255); 
	
	blank = CP_Color_Create(0, 255, 0, 0);
	orange = CP_Color_Create(255, 165, 0, 100);
	strokeorange = CP_Color_Create(255, 165, 0, 30);
	amber = CP_Color_Create(255, 191, 0, 100);
	strokeamber = CP_Color_Create(255, 191, 0, 30);
	goldenyellow = CP_Color_Create(255, 192, 0, 50);
	strokegoldenyellow = CP_Color_Create(255, 192, 0, 15);
	gold = CP_Color_Create(255, 215, 0, 255);
	transparent = CP_Color_Create(0, 0, 0, 0);
	
	//Window size
	windowWidth = (float)CP_System_GetWindowWidth();
	windowHeight = (float)CP_System_GetWindowHeight();

	textoffset = windowWidth / 40; //40 


	//Play button size
	play_center_x = windowWidth / 2 - 120;
	play_center_y = (windowHeight / 4) * 3;
	play_width = windowWidth / 8;
	play_height = windowHeight / 8;

	//Play button array
	playbutton.x = play_center_x;
	playbutton.y = play_center_y;
	playbutton.width = play_width;
	playbutton.height = play_height;
	playbutton.alpha = 0;

	//Exit button size
	exit_center_x = windowWidth / 2 + 165;
	exit_center_y = (windowHeight /4) *3;
	exit_width = windowWidth / 8;
	exit_height = windowHeight / 8;

	//Exit button array
	exitbutton.x = exit_center_x;
	exitbutton.y = exit_center_y;
	exitbutton.width = exit_width;
	exitbutton.height = exit_height;
	exitbutton.alpha = 0;

	//LowLight
	lowlight.x = windowWidth / 2 - 4 * textoffset;
	lowlight.y = windowHeight / 3;
	lowlight.width = 200;
	lowlight.height = 100;
	lowlight.alpha = 0;

	//Player (lamp)
	playerposition.x = windowWidth / 2;
	playerposition.y = windowHeight / 3;


	//Lantern
	lanternwidth = windowWidth / 20;
	lanternheight = windowHeight / 11;
	lanternoffset = windowHeight / 20;
	dt = CP_System_GetDt();
	LoadSounds();
	
}

void Main_Menu_Update(void)
{
	char buffer[256] = { "Low Light" };
	CP_System_SetWindowTitle(buffer);
	if (soundplay == 0)
	{
		CP_Sound_PlayAdvanced(mainmenu1, 100, 1, 0, CP_SOUND_GROUP_0);
		soundplay = 1;
	}
	
	orangealpha = CP_Color_Create(255, 165, 0, alpha);
	blackalpha = CP_Color_Create(0, 0, 0, alpha);
	whitealpha = CP_Color_Create(255, 255, 255, alpha);
	grey1 = CP_Color_Create(129, 133, 137, alpha);
	grey2 = CP_Color_Create(211, 211, 211, alpha);
	grey3 = CP_Color_Create(137, 148, 153, alpha);
	grey4 = CP_Color_Create(133, 121, 126, alpha);
	//Background and font
	CP_Graphics_ClearBackground(black);
	CP_Font_Set(myfont);
	
	//Gamename
	Draw_Text(CP_Color_Create(255, 165, 0, lowlight.alpha), 200, "Low Light", windowWidth/2 - 4*textoffset, windowHeight/3);

	//Play button
	Draw_Rect(blackalpha, playbutton.x, playbutton.y, playbutton.width, playbutton.height, 0, 0);
	Draw_Text((CP_Color_Create(255,255,255,playbutton.alpha)), 60, "Play", playbutton.x + 10, playbutton.y +10);

	//Exit button
	Draw_Rect(blackalpha, exitbutton.x, exitbutton.y, exitbutton.width, exitbutton.height, 0, 0);
	Draw_Text((CP_Color_Create(255, 255, 255, exitbutton.alpha)), 60, "Exit", exitbutton.x + 10, exitbutton.y +10);

	DrawMainMenuLight();

	if (lampstart == 0)
	{
		Draw_Text(white, 60, "Click on the lamp", playerposition.x -70, playerposition.y + 20);
	}
	MainMenuLightBounce();


	//Button detection
	if (CP_Input_MouseClicked())
	{
		click_x = CP_Input_GetMouseX();
		click_y = CP_Input_GetMouseY();


		//Possible to make it so that the play and exit buttons can only be clicked if alpha is a certain value.
		if (IsAreaClicked(playbutton.x, playbutton.y, playbutton.width, playbutton.height, click_x, click_y) == 1) //work on this only as it is the only thing that links to utils.c
		{
			printf("Play\n");
			//CP_Sound_PauseGroup(CP_SOUND_GROUP_0); //Pause music
			//CP_Engine_SetNextGameState(StoryScreen_Init, StoryScreen_Update, StoryScreen_Exit);
			lampstart = 0;
			CP_Engine_SetNextGameState(LoadingScreen_Init, LoadingScreen_Update, LoadingScreen_Exit);
			//CP_Engine_SetNextGameState(Level1_Init, Level1_Update, Level1_Exit); //CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
		}
		if (IsAreaClicked(exitbutton.x, exitbutton.y, exitbutton.width, exitbutton.height, click_x, click_y) == 1)
		{
			printf("Exit\n");
			//CP_Sound_PauseGroup(CP_SOUND_GROUP_0);
			CP_Engine_Terminate();
		}

	}
	lampintersectalpha(&playbutton, 1, 255);
	lampintersectalpha(&exitbutton, 1, 255);
	lampintersectalpha(&lowlight, 1, 255);
	MainMenulampclicked();
}

void Main_Menu_Exit(void)
{
	CP_Sound_PauseGroup(CP_SOUND_GROUP_0);
}

int DrawMainMenuLight()
{
	if (mainlightlevel >= 0)
	{
		Draw_Circle(orange, strokeorange, playerposition.x, playerposition.y + lanternoffset, mainlightradiusarray[0]);
	}
	if (mainlightlevel >= 1)
	{
		Draw_Circle(amber, strokeamber, playerposition.x, playerposition.y + lanternoffset, mainlightradiusarray[1]);
	}
	if (mainlightlevel >= 2)
	{
		Draw_Circle(goldenyellow, strokegoldenyellow, playerposition.x, playerposition.y + lanternoffset, mainlightradiusarray[2]);
	}
	if (mainlightlevel >= 3)
	{
		Draw_Circle(goldenyellow, strokegoldenyellow, playerposition.x, playerposition.y + lanternoffset, mainlightradiusarray[3]);
	}
	if (mainlightlevel >= 4)
	{
		Draw_Circle(goldenyellow, strokegoldenyellow, playerposition.x, playerposition.y + lanternoffset, mainlightradiusarray[4]);
	}
	CP_Image_DrawSubImage(LanternImage, playerposition.x + 3, playerposition.y + lanternoffset, lanternwidth, lanternheight, 0, 0, 256, 256, 255);
	return 1;
}
void MainMenuLightBounce(void)
{
	if (bouncestate == 0)
	{
		bouncetimer += 1 * dt;

		if (bouncetimer < 2)
		{
			playerposition.y += 50 * dt;
		}
		if (bouncetimer > 2)
		{
			playerposition.y -= 50 * dt;
		}
		if (bouncetimer > 4)
		{
			bouncetimer = 0;
		}
	}
}
int  MainMenulampclicked(void)
{
	if ((CP_Input_MouseDown(MOUSE_BUTTON_LEFT) && (MMlamppickup == 0)))
	{
		if ((IsAreaClicked(playerposition.x, playerposition.y, lanternwidth, lanternheight, CP_Input_GetMouseX(), CP_Input_GetMouseY()) == 1))
		{
			playerposition.x = CP_Input_GetMouseX();
			playerposition.y = CP_Input_GetMouseY();
			MMlamppickup = 1;
			bouncestate = 1;
			if (alpha < 255) { alpha += 10; }
			printf("%d", alpha);
		}
	}
		if ((CP_Input_MouseDown(MOUSE_BUTTON_LEFT) && (MMlamppickup == 1)))
		{
			if ((IsAreaClicked(playerposition.x, playerposition.y, lanternwidth, lanternheight, CP_Input_GetMouseX(), CP_Input_GetMouseY()) == 1))
			{
				if (alpha < 255) { alpha += 10; }
				printf("%d", alpha);
			}
		}

	if (MMlamppickup == 1)
	{
		lampstart = 1;
		playerposition.x = CP_Input_GetMouseX();
		playerposition.y = CP_Input_GetMouseY();
	}
	return 0;
}

void lampintersectalpha(struct platformdata *arr, int numberof, int maxalpha)
{
	for (int i = 0; i < numberof; i++)
	{
		if ((AreCirclesIntersecting(playerposition.x, playerposition.y + lanternoffset, lightradius * 2 + 30, arr->x, arr->y, arr->width) == 1) && playerposition.y + lanternoffset <= arr->y)
		{
			if(arr->alpha < 253)
			arr->alpha += 2;
		}
		/*else
		{
			arr[i].alpha = 0;
		}*/
	}
}