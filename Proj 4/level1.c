#include "cprocessing.h"
#include <stdio.h>
#include "utils.h"
#include "mainmenu.h"
#include "level1.h"
#include "fileloader.h"
#include <Windows.h>

CP_Image LanternImage;
CP_Image PrincessImage;
CP_Font myfont;
CP_Color black; 
CP_Color white; 
CP_Color blue;

//Illumination colors
CP_Color orange;
CP_Color amber;
CP_Color goldenyellow;
CP_Color strokeorange;
CP_Color strokeamber;
CP_Color strokegoldenyellow;
CP_Color gold;
CP_Color transparent;

//Window height and dt
float windowWidth;
float windowHeight;
float dt;

//Camera
static const float SCALE_QUANTUM = 1.5f;
static const float ROTATION_QUANTUM = 15.0f;
static const float PAN_QUANTUM = 100.0f;
static const float FONT_SIZE = 50.0f;

static float currentScale;
static float currentRotation;
static CP_Vector currentPosition, centerOffset;
static CP_Matrix scaleMatrix, rotationMatrix, translationMatrix;

/*Low Light variables                     */

//Player mouse position
//CP_Vector playerposition;
//
////Player stats
//float lightradiusarray[5] = { 10.f, 50.f, 100.f, 175.f, 275.f };
//int lightlevel = 3;
//int* ptrlightlevel = &lightlevel;
//float lightradius = 0.f;
//
////Princess
//float princessheight;
//float princesseyelevel;
//float princesswidth;
//float princessmovement;
//float princessjumpheight;
//float princessvision;
//int flip = 1;
//float spriteframe = 0;
//float princessspritewidth = 24;
//float princessalpha = 50;
//					  
////Platform dimensions
//float platformheight;
//float platformwidth;
//float lowestplatformy;
//float platformsgenerated = 0;
//
////Timer related
//float timeroneactivate = 0;
//float leaptimeractivate = 0;
//int leaprightmode = 0;
//int leapleftmode = 0;
//float timer = 0;
//float princessjumpactivate = 0;
//float princessjumptimer = 0;
//
////Spawn point x and y
//CP_Vector spawnpoint;
//float spawnx;
//float spawny;
//
////Princess x and y
//CP_Vector princess;
//
////Level related
//float gravity = 50.f;

//Map generation
//
//{
//	float x;
//	float y;
//	float width;
//	float height;
//} 

//cliffleftarr[6]; 
//cliffrightarr[6];
//struct platformdata platformarr[500];
//float numberofplatforms;
//
//struct platformdata lightcube[5];
//float numberoflightcubes;
//float lightcubewidth;
//float lightcubeheight;
//
//struct platformdata inportalarr[3];
//struct platformdata outportalarr[3];
//float numberofinportals = 0;
//float numberofoutportals = 0;
//float numberofleftcliffs = 0;
//float numberofrightcliffs = 0;
//float inportalwidth;
//float inportalheight;
//float outportalwidth;
//float outportalheight;
//float teleportoffset;
//float cliffwidth;
//float cliffheight;
//
//
//struct platformdata leftwallarr[50];
//struct platformdata rightwallarr[50];
//float numberofleftwalls = 0;
//float numberofrightwalls = 0;
//float leftwallwidth;
//float leftwallheight;




//struct platformdata textarr[50];
//float numberoftexts = 0;
////Array and draw function
//char arr[1000] = { 0 };
//int stopgenerate = 0;
//int onplatform = 0;
//float buffer = 5;

//Level only
//char* levelnames[6] = {"C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/leveltest.txt", "C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/level1.txt", "C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/level2.txt", "C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/level3.txt" , "C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/level4.txt", "C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/level5.txt"}; //Set another array = to this array[level]
//char* levelarr;

//Lamp 
//float lanternwidth;
//float lanternheight;
//float lanternoffset;
//float lampspawnx;
//float lampspawny;
//
//int lamppickup = 0;


char* levelnames[6] = { "C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/leveltest.txt", "C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/level1.txt", "C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/level2.txt", "C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/level3.txt" , "C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/level4.txt", "C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LevelDesigns/level5.txt" }; //Set another array = to this array[level]


void Level1_Init(void)
{
	myfont = CP_Font_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/Atma-Medium.ttf"); //Load font

		windowWidth = (float)CP_System_GetWindowWidth();
		windowHeight = (float)CP_System_GetWindowHeight();

		//Princess
		princessheight = windowHeight / 14.0625f;	//64.f;
		princesseyelevel = -(windowHeight / 45);	//20.f;
		princesswidth = windowWidth / 40;//40.f;
		princessmovement = windowWidth / 18; //50.f;
		princessvision = 0; //This controls how far the princess can see the light. Edit value below
		princessjumpheight = platformheight;

		//Platform dimensions
		princessvision = 20;

		//Portal dimensions
		inportalwidth = windowWidth / 45;
		inportalheight = windowHeight / 12; 
		outportalwidth = windowWidth / 45; //160
		outportalheight = windowHeight / 12; //45
		teleportoffset = windowWidth / 40;

		//Platform dimensions
		platformheight = windowHeight / 35.f; 
		platformwidth = windowHeight /31.f; //Adjusting here makes everything smaller or bigger. Make changes in the Generate platform from data
		leftwallwidth = 2;
		leftwallheight = 2*platformheight;

		//Lightcube dimensions
		lightcubewidth = windowWidth / 80.f;
		lightcubeheight = windowHeight / 41.f;

		//Lantern
		lanternwidth = windowWidth / 20;
		lanternheight = windowHeight / 11;
		lanternoffset = windowHeight / 20;


		float centerX = CP_System_GetWindowWidth() / 2.0f;
		float centerY = CP_System_GetWindowHeight() / 2.0f;
		centerOffset = CP_Vector_Set(centerX, centerY);
		currentPosition = CP_Vector_Zero();
		translationMatrix = CP_Matrix_Translate(currentPosition);
		white = CP_Color_Create(255, 255, 255, 255);
		black = CP_Color_Create(0, 0, 0, 255);
		blue = CP_Color_Create(10, 10, 235, 255);
		orange = CP_Color_Create(255, 165, 0, 100);
		strokeorange = CP_Color_Create(255, 165, 0, 30);
		amber = CP_Color_Create(255, 191, 0, 100);
		strokeamber = CP_Color_Create(255, 191, 0, 30);
		goldenyellow = CP_Color_Create(255, 192, 0, 50);
		strokegoldenyellow = CP_Color_Create(255, 192, 0, 15);
		gold = CP_Color_Create(255, 215, 0, 255);
		transparent = CP_Color_Create(0, 0, 0, 0);

		//Level loading
		level = 2;
		levelarr = levelnames[level];
		CreateLevelDataArray(levelarr);
		GeneratePlatformFromData(arr);

		//Spawn
		princess = CP_Vector_Set(spawnx, spawny); //Set princess position to spawn point.
		playerposition.x = lampspawnx;
		playerposition.y = lampspawny;
		//Image load
		PrincessImage = CP_Image_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/IcePrincessSheet.png");
		LanternImage = CP_Image_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/Lantern.png");

}

void Level1_Update(void)
{
	dt = CP_System_GetDt();
	
	//Player mouse position
	//Updateplayerposition();
	
	//Set background                                                              
	CP_Graphics_ClearBackground(black);

	/*Camera start
	

	if (CP_Input_KeyDown(KEY_R))
	{
		currentRotation += dt * ROTATION_QUANTUM;
		rotationMatrix = CP_Matrix_Rotate(currentRotation);
	}
	else if (CP_Input_KeyDown(KEY_T))
	{
		currentRotation += dt * -ROTATION_QUANTUM;
		rotationMatrix = CP_Matrix_Rotate(currentRotation);
	}

	if (CP_Input_KeyDown(KEY_I))
	{
		currentScale += dt * SCALE_QUANTUM;
		scaleMatrix = CP_Matrix_Scale(CP_Vector_Set(currentScale, currentScale));
	}
	else if (CP_Input_KeyDown(KEY_O))
	{
		currentScale += dt * -SCALE_QUANTUM;
		scaleMatrix = CP_Matrix_Scale(CP_Vector_Set(currentScale, currentScale));
	}

	if (CP_Input_KeyDown(KEY_UP))
	{
		currentPosition.y += dt * PAN_QUANTUM;
		translationMatrix = CP_Matrix_Translate(currentPosition);
		printf("Current Pos: %f %f\n", currentPosition.x, currentPosition.y);
	}
	else if (CP_Input_KeyDown(KEY_DOWN))
	{
		currentPosition.y += dt * -PAN_QUANTUM;
		translationMatrix = CP_Matrix_Translate(currentPosition);
		printf("Current Pos: %f %f\n", currentPosition.x, currentPosition.y);
	}
	else if (CP_Input_KeyDown(KEY_RIGHT))
	{
		currentPosition.x += dt * -PAN_QUANTUM;
		translationMatrix = CP_Matrix_Translate(currentPosition);
		printf("Current Pos: %f %f\n", currentPosition.x, currentPosition.y);
	}
	else if (CP_Input_KeyDown(KEY_LEFT))
	{
		currentPosition.x += dt * PAN_QUANTUM;
		translationMatrix = CP_Matrix_Translate(currentPosition);
		printf("Current Pos: %f %f\n", currentPosition.x, currentPosition.y);
	}

	CP_Vector offsetOrigin = CP_Vector_Scale(currentPosition, -1.0f);
	CP_Vector offsetVector = CP_Vector_Add(offsetOrigin, centerOffset);
	CP_Matrix offsetMatrix = CP_Matrix_Translate(CP_Vector_Scale(offsetVector, -1.0f));
	//translate all objects by the world space position of the current screen center
	CP_Matrix offsetUndoMatrix = CP_Matrix_Translate(offsetVector);
	//now all objects are within the screen center's local coord system
	//so we apply the scale
	CP_Matrix transform = CP_Matrix_Multiply(scaleMatrix, offsetMatrix);
	//then the rotation
	transform = CP_Matrix_Multiply(rotationMatrix, transform);
	//then we return all objects to the world space
	transform = CP_Matrix_Multiply(offsetUndoMatrix, transform);
	//translate objects in world space based on the current camera panning
	transform = CP_Matrix_Multiply(translationMatrix, transform);

	//This is the head of the snake.
	CP_Settings_ApplyMatrix(transform);

	
	//Draw environment props that do not move
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Font_DrawText("R and T to rotate camera", 255, 255);
	CP_Font_DrawText("I and O to zoom", 450, 200);
	CP_Font_DrawText("Arrow keys to translate", 750, 20);

	//this draws the center circle in which the scale and rotation transformations
	//take reference from
	
	CP_Graphics_DrawCircle(offsetVector.x, offsetVector.y, 50.0f);

	//Camera end

	//Accounts for panning, zooming still has issues.
	playerposition = CP_Vector_Add(playerposition, offsetOrigin);
	*/

	//Player lamp //Got some known bug when zooming in, the draw circle is not off centre from mouse.
	lightradius = lightradiusarray[lightlevel]/2;

	//Princess movt
	PrincessSeeLight();
	//PrincessJump();
	PrincessLeap();

	//Player Gravity and platform collision
	PrincessGravity();
	wallcollision();

	//Lightcube
	DrawLightCube();
	
	//LightCubePickup need to make a timer as it's adding a bit too fast.
	if (LightCubePickup() == 1)
	{
		timeroneactivate = 1;
	}
	TimerOne();

	//Illumination and Princess
	DrawPrincess();
	DrawLight(lightlevel);

	//Platform
	DrawPlatform(1);
	Drawfill1();
	Drawfill2();
	Drawfill3();
	DrawRightWall();

	//Portals
	DrawPortals();

	PortalLink();

	lampclicked();
	lamppickedup();

	DrawInstructions();

	//Use this to check for the position of the lamp.
	//printf("Lampx: %f, Lampy: %f\n", playerposition.x, playerposition.y);

}
int CreateLevelDataArray(char levelarr[])
{
	//FILE* fp = fopen("Assets/LevelDesigns/leveltest.txt", "r");
	FILE* fp = fopen(levelarr, "r");
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
				textarr[textcount].x = -40 + plat * platformwidth/2;
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
				cliffleftarr[cliffleftcount].x = 80+ plat * platformwidth;
				cliffleftarr[cliffleftcount].y = windowHeight / 45 * (2 * j);
				cliffleftarr[cliffleftcount].width = platformwidth/4;
				cliffleftarr[cliffleftcount].height = platformheight;

				plat++;
				cliffleftcount++;
				numberofleftcliffs++;


			}
			//Cliff right side
			if (arr[i] == 'D')
			{
				cliffrightarr[cliffrightcount].x = 80+ plat * platformwidth;
				cliffrightarr[cliffrightcount].y = windowHeight / 45 * (2 * j);
				cliffrightarr[cliffrightcount].width = platformwidth/4;
				cliffrightarr[cliffrightcount].height = platformheight;

				plat++;
				cliffrightcount++;
				numberofrightcliffs++;


			}
			//Platform
			if ((arr[i] == '_')||arr[i]=='X'|| arr[i]=='L')
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
				platformarr[platformcount].y = windowHeight/45 * (2 * j);
				platformarr[platformcount].width = platformwidth*2;
				platformarr[platformcount].height = platformheight;
				//printf("%d:\n x: %f\n y: %f\n width: %f\n, height %f\n", platformcount, platformarr[platformcount].x, platformarr[platformcount].y, platformarr[platformcount].width, platformarr[platformcount].height);
				platformcount++;
				numberofplatforms++;
			}
			//left Wall
			if (arr[i] == '[')
			{
				leftwallarr[leftwallcount].x = (-40+ plat * platformwidth) - platformwidth +10;
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
				rightwallarr[rightwallcount].x = (-31 + plat * platformwidth) + platformwidth/2 - 41;
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

void Level1_Exit(void)
{
	CP_Image_Free(&LanternImage);
	CP_Image_Free(&PrincessImage);
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
	if(leaptimeractivate == 0)
	{
		if (princess.x > playerposition.x)
		{
			flip = -1;
		}
		else {
			flip = 1;
		}
	}
	CP_Image_DrawSubImage(PrincessImage, princess.x, princess.y, princesswidth*flip, princessheight, spriteframe*princessspritewidth, 0, (spriteframe+1)*princessspritewidth, 38, princessalpha);
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
	fill3[4].y = (fill3[0].y + fill3[2].y) /1.9;
	fill3[4].width = (fill3[1].x - fill3[0].x) * 1.2;
	fill3[4].height = 5*(fill3[2].y - fill3[0].y);

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
		if (AreRectIntersecting(princess.x, princess.y, princesswidth, princessheight, platformarr[i].x, platformarr[i].y, platformarr[i].width+buffer, platformarr[i].height+buffer) == 1)
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
		princess.y += dt * gravity*2;
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
		if (AreRectIntersecting(princess.x, princess.y, princesswidth, princessheight, platformarr[i].x, platformarr[i].y, platformarr[i].width + buffer, platformarr[i].height-buffer) == 1)
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
	if ((onplatform == 1)&&(AreCirclesIntersecting(princess.x, princess.y + princesseyelevel, princesswidth*2, playerposition.x, playerposition.y, lightradius + princesswidth*2) == 1)) //1 is right
	{
		if ((princess.x > playerposition.x) && (timer == 0) && (princess.y > playerposition.y) && (princess.x >= 6 * buffer) && (cliffintersectcheck() != 2))
				{
					princess.x -= dt * princessmovement;
					princessalpha = 150;
					return 1;

				}
				if ((princess.x < playerposition.x) && (timer == 0) && (princess.y > playerposition.y) && (princess.x <= windowWidth-6*buffer) && (cliffintersectcheck() != 1))
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
	for (int i =0; i< numberoflightcubes; i++)
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
		if ((timer >= 0.1)&&(timer <= 0.18))
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
	if ((leapcheck() == 1)&& (PrincessSeeLight() == 1))
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
			princess.y -= princessmovement/2 * dt;
			}
			//lamp on right walk right
			if (leaprightmode == 1)
			{
			princess.x -= princessmovement * dt;
			princess.y -= princessmovement/2 * dt;
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
	for(int i=0; i<numberofinportals; i++)
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
		if ((AreCirclesIntersecting(playerposition.x, playerposition.y, lightradius*1.2, cliffleftarr[i].x, cliffleftarr[i].y, cliffleftarr[i].width) == 1) && (AreCirclesIntersecting(playerposition.x, playerposition.y, lightradius*1.2, cliffrightarr[i].x, cliffrightarr[i].y, cliffrightarr[i].width) == 1))
		{
			return 1;
		}
		return 0;
	}
}
