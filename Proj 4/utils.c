#include <math.h>
#include "utils.h"
#include "cprocessing.h"
#include <stdio.h>

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

//Maybe wrong but works so far.
char *levelnames[6] = { "C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/leveltest.txt", "C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/level1.txt", "C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/level2.txt", "C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/level3.txt" , "C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/level4.txt", "C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/level5.txt" }; //Set another array = to this array[level]

int level = 0;
struct platformdata fill1[5] = { 0 };
struct platformdata fill2[5] = { 0 };
struct platformdata fill3[5] = { 0 };
struct platformdata cliffleftarr[6] = { 0 };
struct platformdata cliffrightarr[6] = { 0 };
struct platformdata textarr[50] = { 0 };

//Player stats
lightradiusarray[5] = { 10.f, 50.f, 100.f, 175.f, 275.f };
lightlevel = 3;
*ptrlightlevel = &lightlevel;
lightradius = 0.f;

//Princess
flip = 1;
spriteframe = 0;
princessspritewidth = 24;
princessalpha = 50;

//Platform dimensions
platformgenerated = 0;

//Timer related
timeroneactivate = 0;
leaptimeractivate = 0;
leaprightmode = 0;
leapleftmode = 0;
timer = 0;
princessjumpactivate = 0;
princessjumptimer = 0;

//level related
gravity = 50.f;

numberofinportals = 0;
numberofoutportals = 0;
numberofleftcliffs = 0;
numberofrightcliffs = 0;

numberofleftwalls = 0;
numberofrightwalls = 0;

numberoftexts = 0;
//Array and draw function
char arr[1000] = { 0 };
stopgenerate = 0;
onplatform = 0;
buffer = 5;

//Level only

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

/* LowLight */
int CreateLevelDataArray(char levelarr[])
{
	//FILE* fp = fopen("Assets/LevelDesigns/leveltest.txt", "r");
	FILE* fp = fopen(levelarr, "r");
	//fp = fopen(levelarr, "r");
	if (!fp)
	{
		printf("Unable to open leveltest.txt");

		return 0;
	}
	int count = 0;
	char c;
	while ((c = fgetc(fp)) != EOF)
	{
		//Overflow protection
		if (count < 1000)
		{
			arr[count] = c;
			printf("%c", arr[count]);
			count++;
		}
		else
		{
			printf("Exit: buffer overflow");
			break;
		}
	}
	arr[count] = '\0';
	fclose(fp);
	return 1;

}
//Able to generate platform, need to see how we can store each into the struct then pass it to be checked for collision.
int GeneratePlatformFromData(char arr[])
{

	if (stopgenerate == 0)
	{
		int j = 1; //Increments to newline
		int plat = 0; //New row counter increases
		int platformcount = 0;
		int inportalcount = 0;
		int outportalcount = 0;
		int lightcubecount = 0;
		int leftwallcount = 0;
		int rightwallcount = 0;
		int textcount = 0;
		int fill1count = 0;
		int fill2count = 0;
		int fill3count = 0;
		int cliffleftcount = 0;
		int cliffrightcount = 0;

		for (int i = 0; arr[i] != '\0';i++, plat++)
		{
			//Lightcube
			if (arr[i] == 'C')
			{
				lightcube[lightcubecount].x = 0 + plat * platformwidth;
				lightcube[lightcubecount].y = windowHeight / 45 * (2 * j);
				lightcube[lightcubecount].width = lightcubewidth;
				lightcube[lightcubecount].height = lightcubeheight;
				lightcubecount++;
				numberoflightcubes++;
			}
			//New line
			if (arr[i] == '1')
			{
				j++;
				plat = 0;
				continue;
			}
			//Tab to the end
			if (arr[i] == '-')
			{
				plat = 1;
				plat = plat * 56;
			}
			if (arr[i] == 'T')
			{
				textarr[textcount].x = -40 + plat * platformwidth / 2;
				textarr[textcount].y = windowHeight / 45 * (2 * j);
				textarr[textcount].width = platformwidth;
				textarr[textcount].height = platformheight;
				numberoftexts++;
				++plat;
			}
			//Fill
			if (arr[i] == 'f')
			{
				fill1[fill1count].x = -40 + plat * platformwidth;
				fill1[fill1count].y = windowHeight / 45 * (2 * j);
				++plat;
				fill1count++;
			}
			if (arr[i] == 'F')
			{
				fill2[fill2count].x = -40 + plat * platformwidth;
				fill2[fill2count].y = windowHeight / 45 * (2 * j);
				++plat;
				fill2count++;
			}
			if (arr[i] == 'g') //This will be the bottom
			{
				fill3[fill3count].x = -40 + plat * platformwidth;
				fill3[fill3count].y = windowHeight / 45 * (2 * j);
				++plat;
				fill3count++;
			}
			//Cliff detector (code this while drinking)

			//Cliffleftside
			if (arr[i] == 'd')
			{
				cliffleftarr[cliffleftcount].x = 80 + plat * platformwidth;
				cliffleftarr[cliffleftcount].y = windowHeight / 45 * (2 * j);
				cliffleftarr[cliffleftcount].width = platformwidth / 4;
				cliffleftarr[cliffleftcount].height = platformheight;

				plat++;
				cliffleftcount++;
				numberofleftcliffs++;


			}
			//Cliff right side
			if (arr[i] == 'D')
			{
				cliffrightarr[cliffrightcount].x = 80 + plat * platformwidth;
				cliffrightarr[cliffrightcount].y = windowHeight / 45 * (2 * j);
				cliffrightarr[cliffrightcount].width = platformwidth / 4;
				cliffrightarr[cliffrightcount].height = platformheight;

				plat++;
				cliffrightcount++;
				numberofrightcliffs++;


			}
			//Platform
			if ((arr[i] == '_') || arr[i] == 'X' || arr[i] == 'L')
			{
				if (arr[i] == 'X')
				{
					spawnx = -80 + plat * platformwidth;
					spawny = windowHeight / 48 * (2 * j);
					spawnpoint = CP_Vector_Set(spawnx, spawny);
				}
				if (arr[i] == 'L')
				{
					lampspawnx = -80 + plat * platformwidth;
					lampspawny = windowHeight / 58 * (2 * j); //40 instead fo 40 as I want it to be slightly higher
				}

				platformarr[platformcount].x = -60 + plat * platformwidth;
				platformarr[platformcount].y = windowHeight / 45 * (2 * j);
				platformarr[platformcount].width = platformwidth * 2;
				platformarr[platformcount].height = platformheight;
				//printf("%d:\n x: %f\n y: %f\n width: %f\n, height %f\n", platformcount, platformarr[platformcount].x, platformarr[platformcount].y, platformarr[platformcount].width, platformarr[platformcount].height);
				platformcount++;
				numberofplatforms++;
			}
			//left Wall
			if (arr[i] == '[')
			{
				leftwallarr[leftwallcount].x = (-40 + plat * platformwidth) - platformwidth + 10;
				//leftwallarr[leftwallcount].x = (-30 plat * platformwidth) + platformwidth / 2 - 41;
				leftwallarr[leftwallcount].y = windowHeight / 44 * (2 * j);
				leftwallarr[leftwallcount].width = leftwallwidth;
				leftwallarr[leftwallcount].height = leftwallheight;
				//printf("%d:\n x: %f\n y: %f\n width: %f\n, height %f\n", platformcount, platformarr[platformcount].x, platformarr[platformcount].y, platformarr[platformcount].width, platformarr[platformcount].height);
				leftwallcount++;
				numberofleftwalls++;
			}
			//Right Wall
			if (arr[i] == ']')
			{
				rightwallarr[rightwallcount].x = (-31 + plat * platformwidth) + platformwidth / 2 - 41;
				rightwallarr[rightwallcount].y = windowHeight / 44 * (2 * j);
				rightwallarr[rightwallcount].width = leftwallwidth;
				rightwallarr[rightwallcount].height = leftwallheight;
				//printf("%d:\n x: %f\n y: %f\n width: %f\n, height %f\n", platformcount, platformarr[platformcount].x, platformarr[platformcount].y, platformarr[platformcount].width, platformarr[platformcount].height);
				rightwallcount++;
				numberofrightwalls++;
			}
			//Portal entry
			if (arr[i] == 'I')
			{
				inportalarr[inportalcount].x = 0 + plat * platformwidth;
				inportalarr[inportalcount].y = windowHeight / 45 * (2 * j);
				inportalarr[inportalcount].width = inportalwidth;
				inportalarr[inportalcount].height = inportalheight;
				inportalcount++;
				numberofinportals++;
			}
			//Portal out
			if (arr[i] == 'O')
			{
				outportalarr[outportalcount].x = 0 + plat * platformwidth;
				outportalarr[outportalcount].y = windowHeight / 45 * (2 * j);
				outportalarr[outportalcount].width = outportalwidth;
				outportalarr[outportalcount].height = outportalheight;
				outportalcount++;
				numberofoutportals++;
			}

		}
		stopgenerate = 1;

	}
	return 0;
}

void Updateplayerposition(void)
{
	playerposition.x = CP_Input_GetMouseX();
	playerposition.y = CP_Input_GetMouseY();
}


//Draw princess
void DrawPrincess()
{
	//Draw_Rect(white, princess.x, princess.y, princesswidth, princessheight, 0, 0);
	if (leaptimeractivate == 0)
	{
		if (princess.x > playerposition.x)
		{
			flip = -1;
		}
		else {
			flip = 1;
		}
	}
	CP_Image_DrawSubImage(PrincessImage, princess.x, princess.y, princesswidth * flip, princessheight, spriteframe * princessspritewidth, 0, (spriteframe + 1) * princessspritewidth, 38, princessalpha);
}
//Draw player
int DrawLight()
{
	if (lightlevel >= 0)
	{
		Draw_Circle(orange, strokeorange, playerposition.x, playerposition.y + lanternoffset, lightradiusarray[0]);
	}
	if (lightlevel >= 1)
	{
		Draw_Circle(amber, strokeamber, playerposition.x, playerposition.y + lanternoffset, lightradiusarray[1]);
	}
	if (lightlevel >= 2)
	{
		Draw_Circle(goldenyellow, strokegoldenyellow, playerposition.x, playerposition.y + lanternoffset, lightradiusarray[2]);
	}
	if (lightlevel >= 3)
	{
		Draw_Circle(goldenyellow, strokegoldenyellow, playerposition.x, playerposition.y + lanternoffset, lightradiusarray[3]);
	}
	if (lightlevel >= 4)
	{
		Draw_Circle(goldenyellow, strokegoldenyellow, playerposition.x, playerposition.y + lanternoffset, lightradiusarray[4]);
	}
	CP_Image_DrawSubImage(LanternImage, playerposition.x + 3, playerposition.y + lanternoffset, lanternwidth, lanternheight, 0, 0, 256, 256, 255);
	return lightlevel;
}
//Draw platform
void DrawPlatform(float level)
{
	if (level == 1)
	{

		for (int i = 0; i < numberofplatforms; i++)
		{
			//printf("%d:\n x: %f\n y: %f\n width: %f\n, height %f\n", i, platformarr[i].x, platformarr[i].y, platformarr[i].width, platformarr[i].height);
			CP_Settings_Stroke(transparent);
			Draw_Rect(blue, platformarr[i].x, platformarr[i].y, platformarr[i].width, platformarr[i].height, 0, 0);
		}
	}
	level = 2;
}
void DrawPortals(void)
{
	CP_Settings_Stroke(transparent);
	for (int i = 0; i < numberofinportals; i++)
	{
		//printf("%d:\n x: %f\n y: %f\n width: %f\n, height %f\n", i, platformarr[i].x, platformarr[i].y, platformarr[i].width, platformarr[i].height);
		Draw_Rect(orange, inportalarr[i].x, inportalarr[i].y, inportalarr[i].width, inportalarr[i].height, 0, 0);
		Draw_Rect(goldenyellow, outportalarr[i].x, outportalarr[i].y, outportalarr[i].width, outportalarr[i].height, 0, 0);
	}
}
void DrawRightWall(void)
{
	CP_Settings_Stroke(transparent);
	for (int i = 0; i < numberofrightwalls; i++)
	{
		//printf("%d:\n x: %f\n y: %f\n width: %f\n, height %f\n", i, platformarr[i].x, platformarr[i].y, platformarr[i].width, platformarr[i].height);
		Draw_Rect(orange, leftwallarr[i].x, leftwallarr[i].y, leftwallarr[i].width, leftwallarr[i].height, 0, 0);
		Draw_Rect(goldenyellow, rightwallarr[i].x, rightwallarr[i].y, rightwallarr[i].width, rightwallarr[i].height, 0, 0);
	}
}
void Drawfill1(void)
{
	fill1[4].x = (fill1[0].x + fill1[1].x) / 2;
	fill1[4].y = (fill1[0].y + fill1[2].y) / 2;
	fill1[4].width = (fill1[1].x - fill1[0].x);
	fill1[4].height = (fill1[2].y - fill1[0].y);

	Draw_Rect(blue, fill1[4].x, fill1[4].y, fill1[4].width, fill1[4].height, 0, 0);

}
void Drawfill2(void)
{
	fill2[4].x = (fill2[0].x + fill2[1].x) / 2;
	fill2[4].y = (fill2[0].y + fill2[2].y) / 2;
	fill2[4].width = (fill2[1].x - fill2[0].x);
	fill2[4].height = (fill2[2].y - fill2[0].y);

	Draw_Rect(blue, fill2[4].x, fill2[4].y, fill2[4].width, fill2[4].height, 0, 0);
}
void Drawfill3(void)
{
	fill3[4].x = -60 + (fill3[0].x + fill3[1].x) / 2;
	fill3[4].y = (fill3[0].y + fill3[2].y) / 1.9;
	fill3[4].width = (fill3[1].x - fill3[0].x) * 1.2;
	fill3[4].height = 5 * (fill3[2].y - fill3[0].y);

	Draw_Rect(blue, fill3[4].x, fill3[4].y, fill3[4].width, fill3[4].height, 0, 0);

}
void DrawLightCube(void)
{
	for (int i = 0; i < numberoflightcubes; i++)
	{
		Draw_Rect(gold, lightcube[i].x, lightcube[i].y, lightcube[i].width, lightcube[i].height, 0, 0);
	}
}



//Gravity
void PrincessGravity(void)
{
	onplatform = 0;
	for (int i = 0; i < numberofplatforms; i++)
	{
		/*if (AreRectIntersecting(princess.x, princess.y, princesswidth, princessheight, platformarr[i].x, platformarr[i].y, platformarr[i].width, platformarr[i].height) == 0)
		{
			onplatform = 1;
			break;
		}*/
		if (AreRectIntersecting(princess.x, princess.y, princesswidth, princessheight, platformarr[i].x, platformarr[i].y, platformarr[i].width + buffer, platformarr[i].height + buffer) == 1)
		{
			//This detects if the princess hits her head on a platform and prevents her from phasing through and cancels the leap timer
			if (princess.y > platformarr[i].y)
			{
				princess.y += 5;
				timer += 2;
			}
			onplatform = 1;
			break;
		}
	}
	for (int i = 0; i < numberofplatforms; i++)
	{
		if (AreRectIntersecting(princess.x, princess.y, princesswidth, princessheight, leftwallarr[i].x, leftwallarr[i].y, leftwallarr[i].width + buffer, leftwallarr[i].height + buffer) == 1)
		{
			onplatform = 1;
			break;
		}
		if (AreRectIntersecting(princess.x, princess.y, princesswidth, princessheight, rightwallarr[i].x, rightwallarr[i].y, rightwallarr[i].width + buffer, rightwallarr[i].height + buffer) == 1)
		{
			onplatform = 1;
			break;
		}
	}
	if ((!onplatform) && (timer == 0))
	{
		princess.y += dt * gravity * 2;
	}
}
void wallcollision(void)
{
	for (int i = 0; i < numberofleftwalls; i++)
	{
		if (AreRectIntersecting(princess.x, princess.y, princesswidth, princessheight, leftwallarr[i].x, leftwallarr[i].y, leftwallarr[i].width + buffer, leftwallarr[i].height) == 1)
		{
			princess.x -= 5;
		}
		if (AreRectIntersecting(princess.x, princess.y, princesswidth, princessheight, rightwallarr[i].x, rightwallarr[i].y, rightwallarr[i].width + buffer, rightwallarr[i].height) == 1)
		{
			princess.x += 5;
		}
	}

	//got some issue here.
	for (int i = 0; i < numberofplatforms; i++)
	{
		if (AreRectIntersecting(princess.x, princess.y, princesswidth, princessheight, platformarr[i].x, platformarr[i].y, platformarr[i].width + buffer, platformarr[i].height - buffer) == 1)
		{
			if (princess.x < platformarr[i].x)
			{
				princess.x -= 5;
			}
			if (princess.x > platformarr[i].x)
			{
				princess.x += 5;
			}
		}
	}
}
//Princess moves left or right Consider increasing sensetivity
int PrincessSeeLight(void)
//Next step add, a check if rect intersecting for platform checks.
{
	//Princessmovement detection
	//Algo for this doesn't make sense.
	if ((onplatform == 1) && (AreCirclesIntersecting(princess.x, princess.y + princesseyelevel, princesswidth * 2, playerposition.x, playerposition.y, lightradius + princesswidth * 2) == 1)) //1 is right
	{
		if ((princess.x > playerposition.x) && (timer == 0) && (princess.y > playerposition.y) && (princess.x >= 6 * buffer) && (cliffintersectcheck() != 2))
		{
			princess.x -= dt * princessmovement;
			princessalpha = 150;
			return 1;

		}
		if ((princess.x < playerposition.x) && (timer == 0) && (princess.y > playerposition.y) && (princess.x <= windowWidth - 6 * buffer) && (cliffintersectcheck() != 1))
		{
			princess.x += dt * princessmovement;
			princessalpha = 150;

			return 1;
		}
	}
	princessalpha = 50;
	return 0;
}



int LightCubePickup(void)
{
	for (int i = 0; i < numberoflightcubes; i++)
	{
		if (AreRectIntersecting(princess.x, princess.y, princesswidth, princessheight, lightcube[i].x, lightcube[i].y, lightcube[i].width, lightcube[i].height) == 1)
		{
			lightcube[i].width = 0;
			lightcube[i].y = 1600;//making it go off the screen
			return 1;
		}
	}
	return 0;
}
//Timer for 1 second
int TimerOne(void)
{
	if ((timeroneactivate == 1) && (timer <= 2))
	{
		timer += 1 * dt;
		printf("%f\n", timer);
		if ((timer >= 0.1) && (timer <= 0.18))
		{
			spriteframe = 3;
		}
		if ((timer >= 0.2) && (timer <= 0.28))
		{
			spriteframe = 2;
		}
		if ((timer >= 0.3) && (timer <= 0.38))
		{
			spriteframe = 1;
		}
		if ((timer >= 0.4) && (timer <= 0.48))
		{
			spriteframe = 2;
		}
		if ((timer >= 0.5) && (timer <= 0.58))
		{
			spriteframe = 3;
		}
		if ((timer >= 0.6) && (timer <= 0.68))
		{
			spriteframe = 0;
		}

		if (timer >= 1.0)
		{
			timeroneactivate = 0;
			timer = 0;
			*ptrlightlevel += 1;
			return 1;
		}
	}
	return 0;

}


void PrincessJump(void)
//Make it so that she can leap in a direction by adding vector. Need to check if she is facing left or right.
{
	//Don't quite understand the jumping but it's a start.
	if (onplatform == 1)
	{
		if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
		{
			float jumpspeed = -2000;//-gravity * 40;
			jumpspeed = CP_Math_ClampFloat(jumpspeed, -4000 * 30, 6000);
			princess.y += jumpspeed * dt;

			/*princessjumpactivate = 1;
			if ((princessjumpactivate == 1) && (princessjumptimer <= 1))
			{

				princessjumptimer += 1 * dt;

				for (int i = 0; timer <= 1; i++)
				{
					if()
				}

				if (princessjumptimer >= 1.0)
				{
					princessjumpactivate = 0;
					princessjumptimer = 0;
					return 1;
				}

			}*/
		}
	}
}
void PrincessLeap(void)
{
	//If there are no cliff collisions the princess will leap whenever the lamp is clicked.

	//printf("%d", PrincessSeeLight());
	CP_Vector leapright = { 50,-50 };
	CP_Vector leapleft = { -50, -50 };


	//Edit this line as the conditional check if they should jump
	if ((leapcheck() == 1) && (PrincessSeeLight() == 1))
	{
		if ((CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT)) && (timer == 0))
		{
			leaptimeractivate = 1;
			if (playerposition.x > princess.x)
			{
				leapleftmode = 1;
				leaprightmode = 0;
				flip = 1;
				printf("jumping");
			}
			if (playerposition.x < princess.x)
			{
				leaprightmode = 1;
				leapleftmode = 0;
				flip = -1;
				printf("jumping");
			}
		}
	}
	//I want to make so that the left or right has been predetermined and the princess is commit to that direction. But will relook once I implment the check for cliff.
	if (leaptimeractivate == 1)
	{
		printf("%f\n", timer);
		timer += 1 * dt;
		if (timer <= 0.5)
		{
			//Lamp on left Jump left
			if (leapleftmode == 1)
			{
				princess.x += princessmovement * dt;
			}
			//lamp on right walk right
			if (leaprightmode == 1)
			{
				princess.x -= princessmovement * dt;
			}

		}
		if ((timer >= 0.5) && (timer <= 3))
		{
			if (leapleftmode == 1)
			{
				princess.x += princessmovement * dt;
				princess.y -= princessmovement / 2 * dt;
			}
			//lamp on right walk right
			if (leaprightmode == 1)
			{
				princess.x -= princessmovement * dt;
				princess.y -= princessmovement / 2 * dt;
			}
		}
		if (timer >= 3)
		{
			leaptimeractivate = 0;
			timer = 0;
			leaprightmode = 0;
			leapleftmode = 0;
		}
	}

}


void PortalLink(void)
{
	for (int i = 0; i < numberofinportals; i++)
	{
		if (AreRectIntersecting(princess.x, princess.y, princesswidth, princessheight, inportalarr[i].x, inportalarr[i].y, inportalwidth, inportalheight) == 1)
		{
			//Apprach left //Exit right
			if (princess.x < inportalarr[i].x)
			{
				princess.x = outportalarr[i].x - teleportoffset;
				princess.y = outportalarr[i].y - buffer;
			}
			else
			{
				princess.x = outportalarr[i].x + teleportoffset;
				princess.y = outportalarr[i].y - buffer;
			}

		}
		if (AreRectIntersecting(princess.x, princess.y, princesswidth, princessheight, outportalarr[i].x, outportalarr[i].y, inportalwidth, inportalheight) == 1)
		{
			if (princess.x < inportalarr[i].x)
			{
				princess.x = inportalarr[i].x - teleportoffset;
				princess.y = inportalarr[i].y - buffer;
			}
			else
			{
				princess.x = inportalarr[i].x + teleportoffset;
				princess.y = inportalarr[i].y - buffer;
			}
		}
	}
}
int cliffintersectcheck(void)
{
	for (int i = 0; i < numberofrightcliffs;i++)
	{
		if (AreRectIntersecting(princess.x, princess.y, princesswidth, princessheight, cliffleftarr[i].x, cliffleftarr[i].y, cliffleftarr[i].width, cliffleftarr[i].height) == 1)
		{
			return 1;
		}
		if (AreRectIntersecting(princess.x, princess.y, princesswidth, princessheight, cliffrightarr[i].x, cliffrightarr[i].y, cliffrightarr[i].width, cliffrightarr[i].height) == 1)
		{
			return 2;
		}
	}
	return 0;
}

int leapcheck(void)
{
	//Check if light intersect both left and rightside of the cliff
	for (int i = 0; i < numberofleftcliffs;i++)
	{
		if ((AreCirclesIntersecting(playerposition.x, playerposition.y, lightradius * 1.2, cliffleftarr[i].x, cliffleftarr[i].y, cliffleftarr[i].width) == 1) && (AreCirclesIntersecting(playerposition.x, playerposition.y, lightradius * 1.2, cliffrightarr[i].x, cliffrightarr[i].y, cliffrightarr[i].width) == 1))
		{
			return 1;
		}
		return 0;
	}
}

int lampclicked(void)
{
	if ((CP_Input_MouseDown(MOUSE_BUTTON_LEFT) && (lamppickup == 0)))
	{
		if ((IsAreaClicked(playerposition.x, playerposition.y, lanternwidth, lanternheight, CP_Input_GetMouseX(), CP_Input_GetMouseY()) == 1))
		{
			playerposition.x = CP_Input_GetMouseX();
			playerposition.y = CP_Input_GetMouseY();
			lamppickup = 1;
			return 1;
		}
		return 0;
	}
	//It causes the lamp to be deselected too fast
	/*if ((CP_Input_MouseDown(MOUSE_BUTTON_LEFT) && (lamppickup == 1)))
	{
		lamppickup = 0;
	}*/
}

int lamppickedup(void)
{
	if (lamppickup == 1)
	{
		playerposition.x = CP_Input_GetMouseX();
		playerposition.y = CP_Input_GetMouseY();
	}
}
int lampborder(void)
{
	//Lamp intersect wall.

	//Lamp intersect platform. (lampy more than platformy. then pop it up., if lampy less than platformy then pop it up)

	//Lamp intersect platform from the side.
	//lamppickup = 0;
	//if(playerposition.x)
}


void DrawInstructions(void)
//Hard coding for each level
{
	if (level == 1)
	{
		Draw_Text(white, 100, "Click on the lamp to move it", textarr[0].x, textarr[0].y / 2);
	}
	if (level == 2)
	{
		//
	}
	if (level == 3)
	{
		//
	}
	if (level == 4)
	{
		//
	}
}

void PrincessTalk(void)
{
	if (level == 1)
	{
		//Sound, volume, pitch, looping, group
		//CP_Sound_PlayAdvanced(); 
	}
	if (level == 2)
	{
		//
	}
	if (level == 3)
	{
		//
	}
	if (level == 4)
	{
		//
	}
}