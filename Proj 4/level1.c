#include "cprocessing.h"
#include <stdio.h>
#include "utils.h"
#include "mainmenu.h"
#include "level1.h"
#include "fileloader.h"
#include "loadingscreen.h"
#include <stdlib.h>
#include "sound.h"

//Camera
static const float SCALE_QUANTUM = 1.5f;
static const float ROTATION_QUANTUM = 15.0f;
static const float PAN_QUANTUM = 100.0f;
static const float FONT_SIZE = 50.0f;

static float currentScale;
static float currentRotation;
static CP_Vector currentPosition, centerOffset;
static CP_Matrix scaleMatrix, rotationMatrix, translationMatrix;

float redlinex[10];
float redliney[10];

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

CP_Sound test;
float alpha;


void Level1_Init(void)
{
	myfont = CP_Font_Load("C:/ Users /yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/Atma-Medium.ttf"); //Load font
	test = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/ThanksForBeingMyLight.mp3");

		windowWidth = (float)CP_System_GetWindowWidth();
		windowHeight = (float)CP_System_GetWindowHeight();

		//Princess
		princessheight = windowHeight / 14.0625f;	//64.f;
		princesseyelevel = -(windowHeight / 45);	//20.f;
		princesswidth = windowWidth / 40;//40.f;
		princessmovement = windowWidth / 12; //50.f;
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
		platformheight = windowHeight / 25.f; 
		platformwidth = windowHeight /31.f; //Adjusting here makes everything smaller or bigger. Make changes in the Generate platform from data
		leftwallwidth = 1;
		leftwallheight = windowHeight / 10.3f;

		//Lightcube dimensions
		lightcubewidth = windowWidth / 80.f;
		lightcubeheight = windowHeight / 41.f;

		//Lantern
		lanternwidth = windowWidth / 20;
		lanternheight = windowHeight / 11;
		lanternoffset = windowHeight / 20;

		//RedLine and spikes
		redlinewidth = (windowWidth/2) / 3200;
		redlineheight = windowHeight /720;
		
 		spikewidth = windowWidth / 67; //24 and 90
		spikeheight = windowHeight / 45;

		subtitlex = 500;//windowWidth / 4;
			subtitley = 700;//windowHeight / 0.9;
		

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
		red = CP_Color_Create(255, 0, 0, 255);
		transparent = CP_Color_Create(0, 0, 0, 0);

		//Level loading
		//level = 2;
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
		
		//Rng for redlines
		srand(100);
		for (int i = 0; i < 10; i++)
		{
			redlinearr[i].x = (float)(rand() % (int)windowWidth);
			redlinearr[i].y = (float)(rand() % 200) - 0;
			spikearr[i].x = (float)(rand() % (int)windowWidth);
			spikearr[i].y = (float)(rand() % 200) - 0;
		}
		for (int i = 0; i < 3; i++)
		{
			fallingstararr[i].x = windowWidth/16 + 100 * i;
			fallingstararr[i].y = (float)(rand() % 200) - 0;
			
		}
		if (level == 1)
		{
			lightlevel = 0;
			numberofspikes = 0;
			numberofredlines = 0;
		}
		if (level == 2)
		{
			lightlevel = 0;
			numberofspikes = 0;
			numberofredlines = 0;
		}
		if (level == 3)
		{
			lightlevel = 0;
			numberofspikes = 15;
			numberofredlines = 15;
		}


}

void Level1_Update(void)
{
	dt = CP_System_GetDt();

	//Color updates
	orangealpha = CP_Color_Create(255, 165, 0, alpha);
	blackalpha = CP_Color_Create(0, 0, 0, alpha);
	whitealpha = CP_Color_Create(255, 255, 255, alpha);
	grey1 = CP_Color_Create(129, 133, 137, alpha);
	grey2 = CP_Color_Create(211, 211, 211, alpha);
	grey3 = CP_Color_Create(137, 148, 153, alpha);
	grey4 = CP_Color_Create(133, 121, 126, alpha);

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
	//CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Font_DrawText("R and T to rotate camera", 255, 255);
	CP_Font_DrawText("I and O to zoom", 450, 200);
	CP_Font_DrawText("Arrow keys to translate", 750, 20);

	//this draws the center circle in which the scale and rotation transformations
	//take reference from
	
	CP_Graphics_DrawCircle(offsetVector.x, offsetVector.y, 50.0f);

	Camera end

	//Accounts for panning, zooming still has issues.
	playerposition = CP_Vector_Add(playerposition, offsetOrigin);
	*/

	//Player lamp //Got some known bug when zooming in, the draw circle is not off centre from mouse.
	lightradius = lightradiusarray[lightlevel]/2;


	LoadSounds();

	//Princess movt
	princessseelight = PrincessSeeLight();
	//PrincessJump();
	PrincessLeap();

	//Deactivated for now
	//PrincessTalk();

	//Player Gravity and platform collision
	PrincessGravity();
	wallcollision();

	//Lightcube
	DrawLightCube();
	
	//LightCubePickup need to make a timer as it's adding a bit too fast.
	if ((LightCubePickup() == 1))
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

	DrawNextLevelDoor();
	NextLevelLink();

	//This is the draw redline and spawning logic.
	
	if (level == 3)
	{
	RedLineSpawning();
	RedLinePlayer();
	SpikeSpawning();
	SpikePrincess();
	
	FallingStarSpawning();
	}

	if (CP_Input_KeyTriggered(KEY_6))
	{
		CP_Sound_PlayAdvanced(mmmThatLooksDangerous, 100, 1, FALSE, CP_SOUND_GROUP_0);
	}

	if (onplatform == 0)
	{
		princess.y += dt * gravity;
	}
	
	
	//Skip
	if (CP_Input_KeyTriggered(KEY_5))
	{
		level += 1;
		CP_Engine_SetNextGameState(LoadingScreen_Init, LoadingScreen_Update, LoadingScreen_Exit);
	}
	
	//Check if lamp intersects and increase alpha.
	lampintersectstuff(inportalarr, numberofinportals, 50);
	lampintersectstuff(outportalarr, numberofoutportals, 50);
	lampintersectstuff(platformarr, numberofplatforms, 255);
	lampintersectstuff(nextlevelarr, numberofnextlevels, 150);
	lampintersectwall();
	LampIntersectSpike(spikearr, numberofspikes, 150);
	LampIntersectSpike(redlinearr, numberofredlines, 150);
	//Use this to check for the position of the lamp.
	//printf("Lampx: %f, Lampy: %f\n", playerposition.x, playerposition.y);

}

void Level1_Exit(void)
{
	CP_Image_Free(&LanternImage);
	CP_Image_Free(&PrincessImage);
}








