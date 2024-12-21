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

void Level1_Exit(void)
{
	CP_Image_Free(&LanternImage);
	CP_Image_Free(&PrincessImage);
}








