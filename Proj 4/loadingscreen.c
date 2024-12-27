#pragma once

#include "loadingscreen.h"
#include "level1.h"
#include "mainmenu.h"
#include "utils.h"

CP_Color black;
CP_Color whitewithalpha;

float LoadingTimer =0;
float alphachange = 0;
float windowWidth;
float windowHeight;
float dt;
//Might need to double check if the value stored in level is transferred.
//Need to test and check the position of the words.
int level;
float textsize;

CP_Font myfont;

void LoadingScreen_Init(void)
{
	LoadingTimer = 0;
	alphachange = 0;
	black = CP_Color_Create(0, 0, 0, 255);
	textsize = windowWidth / 16; //100
	myfont = CP_Font_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/Atma-Medium.ttf"); //Load font
	
}

void LoadingScreen_Update(void)
{
	CP_Font_Set(myfont);
	CP_Graphics_ClearBackground(black);

	whitewithalpha = CP_Color_Create(255, 255, 255, alphachange);

	stopgenerate = 0;

	if (level == 1)
	{
		
		Draw_Text(whitewithalpha, textsize, "The light in the darkness", windowWidth / 3, windowHeight / 2);
	}
	if (level == 2)
	{
		Draw_Text(whitewithalpha, textsize, "The Cliff", windowWidth / 2, windowHeight / 2);
	}
	if (level == 3)
	{
		Draw_Text(whitewithalpha, textsize, "Catastrophy", windowWidth / 2, windowHeight / 2);
	}
	LoadingTimer += dt * 1;
	if (LoadingTimer > 0.5 && LoadingTimer < 1)
	{
		alphachange = 200;
	}
	if (LoadingTimer > 1.0 && LoadingTimer < 2.5)
	{
		alphachange = 255;
	}
	/*if (LoadingTimer > 1.5&& LoadingTimer < 2.0)
	{
		alphachange = 200;
	}*/
	if (LoadingTimer > 2.5 && LoadingTimer < 2.6)
	{
		CP_Engine_SetNextGameState(Level1_Init, Level1_Update, Level1_Exit);
	}
}

void LoadingScreen_Exit(void)
{

}