#pragma once

#include "loadingscreen.h"
#include "level1.h"
#include "mainmenu.h"
#include "utils.h"
#include "story.h"
#include "cprocessing.h"

CP_Color black;
CP_Color whitewithalpha;

float StoryTimer = 0;
LoadingTimer;
float storyalpha;
alphachange;
float windowWidth;
float windowHeight;
float dt;
//char level1story[200] = { "The Princess born in darkness. She knew nothing, and saw nothing. Then a light appeared. She was drawn towards the light." };
//char level2story[200] = { "The Princess followed the light. Though it was dim she found brightness. The Princess realized she could affect the light. The light was a lamp unto her feet" };
//char level3story[200] = { "The light revealed a catatrophe." };
float textstartpointx;
float textstartpointy;
//Might need to double check if the value stored in level is transferred.
//Need to test and check the position of the words.
int level;
int princessdown;
int lampbreak;
int storymode;
float textsize;
int levelsong;


CP_Font myfont;

void StoryScreen_Init(void)
{
	StoryTimer = 0;
	
	black = CP_Color_Create(255, 0, 0, 255);
	textsize = windowWidth/16; //100
	myfont = CP_Font_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/Atma-Medium.ttf"); //Load font

	for (int i = 0; level1story[i] != NULL;i++)
	{
		printf("%c\n", level1story[i]);
	}
	printf("end");
	textstartpointx = windowWidth / 16;
	textstartpointy = windowHeight / 9;
	if (level == 1)
{
	for (int i = 0; i < 4;i++)
	{
		char currentletter[2] = { level1story[i], '\0' };
		Draw_Text(CP_Color_Create(255, 255, 255, 255), 1000, currentletter, 800, 400);
		
	}
	
}
	LoadSounds();
}

void StoryScreen_Update(void)
{
	CP_Font_Set(myfont);
	CP_Graphics_ClearBackground(black);

	whitewithalpha = CP_Color_Create(255, 255, 255, alphachange);

	Draw_Text(CP_Color_Create(255, 255, 255, 255), 500, "currentletter", 800, 400);

	stopgenerate = 0;



	if (level == 1)
	{
		Draw_Text(whitewithalpha, textsize, "The light in the darkness", windowWidth / 2.7, windowHeight / 2);
	}
	if (level == 2)
	{
		Draw_Text(whitewithalpha, textsize, "The Cliff", windowWidth / 2.2, windowHeight / 2);
	}
	if (level == 3)
	{
		Draw_Text(whitewithalpha, textsize, "Catastrophe", windowWidth / 2.4, windowHeight / 2);
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
void StoryScreen_Exit(void)
{

}