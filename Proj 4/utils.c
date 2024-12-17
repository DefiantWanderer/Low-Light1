#include <math.h>
#include "utils.h"
#include "cprocessing.h"

//How to use sounds?
/*
1. Add "CP_Sound Coin" above your init.
2. Add "Coin = CP_Sound_LoadMusic("Assets/Coin.wav");" to your init.
3. Use PlaySound(Coin); to play the sound
*/
CP_Sound MainMenuMusic;				//MainMenuMusic = CP_Sound_LoadMusic("Assets/MainMenuMusic.mp3");
CP_Sound Coin;						//Coin = CP_Sound_LoadMusic("Assets/Coin.wav");
CP_Sound Dash;						//Dash = CP_Sound_LoadMusic("Assets/Dash.wav");
CP_Sound Door;						//Door = CP_Sound_LoadMusic("Assets/Door.wav");
CP_Sound EnemyHit;					//EnemyHit = CP_Sound_LoadMusic("Assets/EnemyHit.wav");
CP_Sound FallingDeath;				//FallingDeath = CP_Sound_LoadMusic("Assets/FallingDeath.wav");
CP_Sound Jump;						//Jump = CP_Sound_LoadMusic("Assets/Jump.wav");
CP_Sound KnifeEquip;				//KnifeEquip = CP_Sound_LoadMusic("Assets/KnifeEquip.wav");
CP_Sound LandingOnPlatform;			//LandingOnPlatform = CP_Sound_LoadMusic("Assets/LandingOnPlatform.wav");
CP_Sound MenuButton;				//MenuButton = CP_Sound_LoadMusic("Assets/MenuButton.wav");
CP_Sound Oof1;						//Oof1 = CP_Sound_LoadMusic("Assets/Oof1.wav");
CP_Sound Oof2;						//Oof2 = CP_Sound_LoadMusic("Assets/Oof2.wav");
CP_Sound Running1;					//Running1 = CP_Sound_LoadMusic("Assets/Running1.wav");
CP_Sound Running2;					//Running2 = CP_Sound_LoadMusic("Assets/Running2.wav");
CP_Sound RunningOnGrass;			//RunningOnGrass = CP_Sound_LoadMusic("Assets/RunningOnGrass.wav");
CP_Sound RunningOnWood;				//RunningOnWood = CP_Sound_LoadMusic("Assets/RunningOnWood.wav");
CP_Sound Shuriken1;					//Shuriken1 = CP_Sound_LoadMusic("Assets/Shuriken1.wav");
CP_Sound Shuriken2;					//Shuriken2 = CP_Sound_LoadMusic("Assets/Shuriken2.wav");
CP_Sound SwordSwing;				//SwordSwing = CP_Sound_LoadMusic("Assets/SwordSwing.wav");
CP_Sound SwordSwing2;				//SwordSwing2 = CP_Sound_LoadMusic("Assets/SwordSwing2.wav");
CP_Sound SwordDeflect;				//SwordDeflect = CP_Sound_LoadMusic("Assets/SwordDeflect.wav");
CP_Sound Win1;						//Win1 = CP_Sound_LoadMusic("Assets/Win1.wav");
CP_Sound Win2;						//Win2 = CP_Sound_LoadMusic("Assets/Win2.wav");
CP_Sound Win3;						//Win3 = CP_Sound_LoadMusic("Assets/Win3.wav");
CP_Sound Win4;						//Win4 = CP_Sound_LoadMusic("Assets/Win4.wav");

//How to use font and colors?
/*
1. Add "CP_Color grey" above your init.
2. Add "grey = CP_Color_Create(128, 128, 128, 255);" to your init.
3. Pass "grey" into the the Draw_Text, Draw_Rect, Draw_Circle, Draw_Star
*/
CP_Font myfont; //myfont = CP_Font_Load("Assets/Atma-Medium.ttf");
CP_Color grey; //grey = CP_Color_Create(128, 128, 128, 255);
CP_Color black; //black = CP_Color_Create(0, 0, 0, 255);
CP_Color red; //red = CP_Color_Create(230, 0, 10, 255);
CP_Color darkred; //darkred = CP_Color_Create(200, 50, 50, 255);
CP_Color blue; //blue = CP_Color_Create(0, 0, 255, 255);
CP_Color green; //green = CP_Color_Create(0, 255, 0, 255);
CP_Color blank; //blank = CP_Color_Create(0, 255, 0, 0);
CP_Color white; //white = CP_Color_Create(255, 255, 255, 255);
CP_Color gold; //gold = CP_Color_Create(255, 215, 0, 255);




int IsAreaClicked(float area_center_x, float area_center_y, float area_width, float area_height, float click_x, float click_y)
{
	if (click_x >= (area_center_x - area_width / 2) && click_x <= (area_center_x + area_width / 2) && click_y >= (area_center_y - area_height / 2) && click_y <= (area_center_y + area_height / 2))
	{
		return 1;
	}
	return 0;//This is critical. If not it'll just return 1 everywhere
}

int IsCircleClicked(float circle_center_x, float circle_center_y, float diameter, float click_x, float click_y)
{
	if (click_x >= (circle_center_x - diameter / 2) && click_x <= (circle_center_x + diameter / 2) && click_y >= (circle_center_y - diameter / 2) && click_y <= (circle_center_y + diameter / 2))
	{
		return 3;
	}
	return 0;
}

int AreCirclesIntersecting(float c1_x, float c1_y, float r1, float c2_x, float c2_y, float r2) 
{
	float c1c2diff;
	c1c2diff = sqrt(((c1_x - c2_x) * (c1_x - c2_x)) + ((c1_y - c2_y) * (c1_y - c2_y)));
	{
		if (c1c2diff <= (r1 - r2)) //Right side and bot right
		{
			return 1;
		}
		if (c1c2diff <= (r2 - r1)) //Right side and top right
		{
			return 1;
		}
		if (c1c2diff < (r1 + r2)) //Left side and top left
		{
			return 1;
		}
		if (c1c2diff == (r1 + r2)) //Left side and bot right
		{
			return 1;
		}
	}
	
	return 0;
}
int AreRectIntersecting(float rect1_x, float rect1_y, float rect1_width, float rect1_height, float rect2_x, float rect2_y, float rect2_width, float rect2_height)
{
	float x1x2distance = (rect1_width / 2) + (rect2_width / 2);
	float x1x2heightdistance = (rect1_height / 2) + (rect2_height / 2);
	float x1x2diff = rect1_x - rect2_x;
	float x1x2heightdiff = rect1_y - rect2_y;
	if (x1x2diff < 0)
	{
		x1x2diff = -(x1x2diff);
	}
	if (x1x2heightdiff < 0)
	{
		x1x2heightdiff = -(x1x2heightdiff);
	}
	//Intersect is 1 doesn't intersect is 0
	if ((x1x2diff <= x1x2distance) && (x1x2heightdiff <= x1x2heightdistance))
	{
		return 1;
	}
	return 0;
}

int IsMouseHovering(float circle_center_x, float circle_center_y, float diameter, float mouseX, float mouseY)
{
	if (mouseX >= (circle_center_x - diameter / 2) && mouseX <= (circle_center_x + diameter / 2) && mouseY >= (circle_center_y - diameter / 2) && mouseY <= (circle_center_y + diameter / 2))
	{
		return 4;
	}
	return 0;
}

void Draw_Rect(CP_Color color, float area_center_x, float area_center_y, float area_width, float area_height, float degrees, float cornerRadius) //Function to draw rectangle including color
{
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_Fill(color);
	CP_Graphics_DrawRectAdvanced(area_center_x, area_center_y, area_width, area_height, degrees, cornerRadius);
}
void Draw_Circle(CP_Color color, CP_Color strokecolor, float circle_center_x, float circle_center_y, float diameter) //Function to draw circle including color
{
	CP_Settings_Fill(color);
	CP_Settings_Stroke(strokecolor);
	CP_Graphics_DrawCircle(circle_center_x, circle_center_y, diameter);
}

void Draw_Star(CP_Color color, float x, float y)
{
	CP_Graphics_BeginShape(); //x=800, height = 180
	CP_Settings_Fill(color);
	CP_Graphics_AddVertex(x, y); //Top
	CP_Graphics_AddVertex(x - 12, y + 40); //2
	CP_Graphics_AddVertex(x - 55, y + 40);//3
	CP_Graphics_AddVertex(x - 22, y + 60);//4
	CP_Graphics_AddVertex(x -38, y + 95);//5
	CP_Graphics_AddVertex(x, y + 75);//6
	CP_Graphics_AddVertex(x + 38, y + 95);//7
	CP_Graphics_AddVertex(x + 22, y + 60);//8
	CP_Graphics_AddVertex(x + 55, y + 40);//9
	CP_Graphics_AddVertex(x + 12, y + 40);//10
	CP_Graphics_EndShape();
}
void Draw_Text(CP_Color fill, float size, const char* text, float x, float y) //Function to draw text including color
{
	CP_TEXT_ALIGN_HORIZONTAL horizontal = CP_TEXT_ALIGN_H_LEFT;
	CP_TEXT_ALIGN_VERTICAL vertical = CP_TEXT_ALIGN_V_BASELINE;
	if (x >= 0)
	{
		CP_Settings_TextAlignment(horizontal, vertical);
		horizontal = CP_TEXT_ALIGN_H_CENTER;
	}
	CP_Settings_Fill(fill);
	CP_Settings_TextSize(size);
	CP_Font_DrawText(text, x - 50, y);

}
void PlaySound(CP_Sound Music)
{
	CP_Sound_PlayAdvanced(Music, 1.0, 1.0, TRUE, CP_SOUND_GROUP_0);
}
