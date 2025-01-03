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
char level1story[200] = { "The Princess born in darkness. She knew nothing, and saw nothing. Then a light appeared. She was drawn towards the light." };
char level2story[200] = { "The Princess followed the light. Though it was dim she found brightness. The Princess realized she could affect the light. The light was a lamp unto her feet" };
char level3story[200] = { "The light revealed a catatrophe." };
float textstartpointx;
float textstartpointy;
float textintervalx;
float textintervaly;
//Might need to double check if the value stored in level is transferred.
//Need to test and check the position of the words.
int level;
int princessdown;
int lampbreak;
int storymode;
float textsize;

CP_Font myfont;

void LoadingScreen_Init(void)
{
	LoadingTimer = 0;
	alphachange = 0;
	black = CP_Color_Create(0, 0, 0, 255);
	textsize = windowWidth / 16; //100
	myfont = CP_Font_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/Atma-Medium.ttf"); //Load font

	lamppickup = 0;
	textstartpointx = windowWidth / 16;
	textstartpointy = windowHeight / 9;
	textintervalx = windowWidth / 60;
	textintervaly = windowHeight / 9;
}

void LoadingScreen_Update(void)
{
	CP_Font_Set(myfont);
	CP_Graphics_ClearBackground(black);

	whitewithalpha = CP_Color_Create(255, 255, 255, alphachange);

	stopgenerate = 0;

	if (princessdown == 1)
	{
		Draw_Text(whitewithalpha, textsize, "The Princess has fallen", windowWidth / 2.2, windowHeight / 2);
		LoadingTimer += dt * 1;
		if (LoadingTimer > 0.5 && LoadingTimer < 1)
		{
			alphachange = 200;
		}
		if (LoadingTimer > 1.0 && LoadingTimer < 2.5)
		{
			alphachange = 255;
		}
		if (LoadingTimer > 2.5 && LoadingTimer < 2.6)
		{
			princessdown = 0;
			lampbreak = 0;
			alphachange = 0;
		}
	}
	if (lampbreak == 1)
	{
		Draw_Text(whitewithalpha, textsize, "The lamp has shattered", windowWidth / 2.2, windowHeight / 2);
		LoadingTimer += dt * 1;
		if (LoadingTimer > 0.5 && LoadingTimer < 1)
		{
			alphachange = 200;
		}
		if (LoadingTimer > 1.0 && LoadingTimer < 2.5)
		{
			alphachange = 255;
		}
		if (LoadingTimer > 2.5 && LoadingTimer < 2.6)
		{
			princessdown = 0;
			lampbreak = 0;
			alphachange = 0;
		}
	}
	
	if (lampbreak == 0 && princessdown == 0)
	{
		LoadingTimer += dt * 1;
		if (level == 1 && storymode == 0)
		{
			Draw_Text(whitewithalpha, textsize, "The light in the darkness", windowWidth / 2.7, windowHeight / 2);
			if (level == 1 && storymode == 1)
			{
				DrawStoryText(level1story);
			}
		}
	if (level == 2 && storymode == 0)
	{
		Draw_Text(whitewithalpha, textsize, "The Cliff", windowWidth / 2.2, windowHeight / 2);
	}
	if (level == 2 && storymode == 1)
	{
		DrawStoryText(level2story);
	}
	if (level == 3 && storymode == 0))
	{
		Draw_Text(whitewithalpha, textsize, "Catastrophe", windowWidth / 2.4, windowHeight / 2);
	}
	if (level == 3 && storymode == 1)
	{
		DrawStoryText(level3story);
	}
	
	
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
		princessdown = 0;
		lampbreak = 0;
		storymode = 0;
		CP_Engine_SetNextGameState(Level1_Init, Level1_Update, Level1_Exit);
	}
}

void LoadingScreen_Exit(void)
{

}