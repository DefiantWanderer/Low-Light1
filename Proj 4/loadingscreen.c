#pragma once

#include "loadingscreen.h"
#include "level1.h"
#include "mainmenu.h"
#include "utils.h"

CP_Color black;
CP_Color white;
CP_Color orange;
CP_Color whitewithalpha;
CP_Image leapinstruction1;
CP_Image leapinstruction2;
CP_Image redlinekills;

float LoadingTimer =0;
int alphachange = 0;
float windowWidth;
float windowHeight;
float dt;
char level1story[200] = { "The Princess born in darkness.She knew nothing.She saw nothing.Suddenly, a light appeared.She was drawn towards the light." };
char level2story[200] = { "The Princess followed the light.Though it was dim she found brightness.The Princess realized she could affect the light.The light was a lamp unto her feet." };
char level3story[200] = { "The light revealed a catastrophe." };
float textstartpointx;
float textstartpointy;
float textintervalx;
float textintervaly;
float continuebuttonx;
float continuebuttony;
//Might need to double check if the value stored in level is transferred.
//Need to test and check the position of the words.
int level;
int princessdown;
int lampbreak;
int storymode;
int instructions = 0;
float textsize;
int storycharacteri;
int words = 30;
float click_x;
float click_y;
float atimer = 0;


CP_Font myfont;

void LoadingScreen_Init(void)
{
	LoadingTimer = 0;
	alphachange = 0;
	black = CP_Color_Create(0, 0, 0, 255);
	white = CP_Color_Create(255, 255, 255, 255);
	textsize = windowWidth / 16; //100
	myfont = CP_Font_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/Atma-Medium.ttf"); //Load font

	lamppickup = 0;
	textstartpointx = windowWidth / 16;
	textstartpointy = windowHeight / 9;
	textintervalx = windowWidth / 60;
	textintervaly = windowHeight / 9;
	continuebuttonx = windowWidth / 2.4f;
	continuebuttony = windowHeight / 4 * 3;

	
	leapinstruction1 = CP_Image_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/cliffno.png");
	leapinstruction2 = CP_Image_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/cliffyes.png");
	redlinekills = CP_Image_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/redlinevslamp.png");

	if(level ==1)
	{
		words = 30;
	}
	if (level == 2 || level ==3)
	{
		words = 32;
	}
	PrincessImage = CP_Image_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/IcePrincessSheet.png");
	LanternImage = CP_Image_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/Lantern.png");
	orange = CP_Color_Create(255, 165, 0, 255);
}

void LoadingScreen_Update(void)
{
	click_x = CP_Input_GetMouseX();
	click_y = CP_Input_GetMouseY();
	CP_Font_Set(myfont);
	CP_Graphics_ClearBackground(black);

	whitewithalpha = CP_Color_Create(255, 255, 255, alphachange);

	stopgenerate = 0;

	if (princessdown == 1)
	{
		Draw_Text(whitewithalpha, textsize, "The Princess has fallen", windowWidth / 2.8f, windowHeight / 2);
		CP_Image_DrawSubImageAdvanced(PrincessImage, windowWidth / 2, windowHeight / 1.5, princesswidth * 2 * 1, princessheight * 2, spriteframe * princessspritewidth, 0, (spriteframe + 1) * princessspritewidth, 38, 125, 270);
		
		atimer += dt * 1;
		if (atimer > 0.5 && atimer < 1)
		{
			alphachange = 200;
		}
		if (atimer > 1.0 && atimer < 2.5)
		{
			alphachange = 255;
		}
		if (atimer > 2.5 && atimer < 2.6)
		{
			atimer = 0;
			princessdown = 0;
			lampbreak = 0;
			alphachange = 0;
		}
	}
	if (lampbreak == 1)
	{
		Draw_Text(whitewithalpha, textsize, "The lamp has shattered", windowWidth / 2.8f, windowHeight / 2);
		CP_Image_Draw(redlinekills, textstartpointx * 2.6, textstartpointy + 2 * textintervaly, 189, 303, 255);
		atimer += dt * 1;
		if (atimer > 0.1 && atimer < 0.15)
		{
			//
		}
		if (atimer > 0.5 && atimer < 1)
		{
			alphachange = 200;
		}
		if (atimer > 1.0 && atimer < 2.5)
		{
			alphachange = 255;
		}
		if (atimer > 2.5 && atimer < 2.6)
		{
			atimer = 0;
			princessdown = 0;
			lampbreak = 0;
			alphachange = 0;
		}
	}

	if (lampbreak == 0 && princessdown == 0);
	{
		//LoadingTimer += dt * 1;
		if (level == 1 && storymode == 0)
		{
			LoadingTimer += dt * 1;
			Draw_Text(whitewithalpha, textsize, "The light in the darkness", windowWidth / 2.7f, windowHeight / 2);
		}
		if (level == 1 && storymode == 1)
		{
			
			DrawStoryText(level1story);
			if (words == 30)
			{
				if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
				{
					words += 17;
					
				}
			}
			else if (words == 47)
			{
				if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
				{
					words += 16;
				}
			}
			else if (words == 63)
			{
				if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
				{
					words += 27;
					
				}
			}
			else if (words == 90)
			{
				if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
				{
					words += 32;
				}
			}
			else if (words > 90)
			{
				Draw_Text(white, textsize, "Continue ->", continuebuttonx, continuebuttony);
				//Draw_Rect(white, continuebuttonx+100, continuebuttony, textsize*3, textsize, 0, 0);
				if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
				{
					if((IsAreaClicked(continuebuttonx + 100, continuebuttony, textsize*3, 100, click_x, click_y) == 1))
					{ 
						storymode = 0;
						words = 0;
					}
				}
			}

		}
		if (level == 2 && storymode == 0)
		{
			LoadingTimer += dt * 1;
			Draw_Text(whitewithalpha, textsize, "The Cliff", windowWidth / 2.2f, windowHeight / 2);
		}
		if (level == 2 && storymode == 1)
		{
			DrawStoryText(level2story);
			if (words == 32)
			{
				if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
				{
					words += 39;

				}
			}
			else if (words == 71)
			{
				if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
				{
					words += 49;
				}
			}
			else if (words == 120)
			{
				if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
				{
					words += 35;

				}
			}
			else if (words == 155)
			{
				Draw_Text(white, textsize, "Continue ->", continuebuttonx, continuebuttony);
				if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
				{
					if ((IsAreaClicked(continuebuttonx + 100, continuebuttony, textsize * 3, 100, click_x, click_y) == 1))
					{
						words = 0;
						instructions = 1;
						

					}
				}
			}
		}

		if (level == 2 && instructions == 1)
		{
			Draw_Text(white, textsize/2, "Left click to make the princess jump across a gap", textstartpointx, textstartpointy );
			CP_Image_Draw(leapinstruction2, textstartpointx*3, textstartpointy + 2*textintervaly, 388, 226, 255);

			Draw_Text(white, textsize / 2, "She won't jump unless you light up both ends", 1600 - textstartpointx*6, textstartpointy);
			CP_Image_Draw(leapinstruction1, 1600-textstartpointx*3, textstartpointy + 2 * textintervaly, 388, 226, 255);

			if (atimer < 0.43)
			{
			atimer += 2 * dt;
			}
			if (atimer > 0.4)
			{
			Draw_Text(white, textsize, "Continue ->", continuebuttonx, continuebuttony);
			//Draw_Rect(white, continuebuttonx+100, continuebuttony, textsize*3, textsize, 0, 0);
			if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
			{
				if ((IsAreaClicked(continuebuttonx + 100, continuebuttony, textsize * 3, 100, click_x, click_y) == 1))
				{
					instructions = 0;
					storymode = 0;
					atimer = 0;
				}
			}
			}

		}
		if (level == 3 && storymode == 0 && lampbreak == 0 && princessdown==0)
		{
			LoadingTimer += dt * 1;
			Draw_Text(whitewithalpha, textsize, "Catastrophe", windowWidth / 2.4f, windowHeight / 2);
		}
		if (level == 3 && storymode == 1)
		{
			DrawStoryText(level3story);
			Draw_Text(white, textsize, "Continue ->", continuebuttonx, continuebuttony);
			
			if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
			{
				if ((IsAreaClicked(continuebuttonx + 100, continuebuttony, textsize * 3, 100, click_x, click_y) == 1))
				{
					storymode = 0;
					words = 0;
				}
			}
		}

		if (storymode == 0)
		{

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
				storymode = 0;
				LoadingTimer = 0;
				CP_Engine_SetNextGameState(Level1_Init, Level1_Update, Level1_Exit);
			}
		}
	}
}

void LoadingScreen_Exit(void)
{
	CP_Image_Free(leapinstruction1);
	CP_Image_Free(leapinstruction2);
	CP_Image_Free(redlinekills);
}