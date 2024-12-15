#include "cprocessing.h"
#include <stdio.h>
#include "utils.h"
#include "levelselect.h"


float width;
float height;

float play_center_x, play_center_y, play_width, play_height;
float exit_center_x, exit_center_y, exit_width, exit_height;

CP_Font myfont; //cpfont is a pointer to a struct
CP_Color grey;
CP_Color black;
CP_Color red;
CP_Color dred;
CP_Color blue;
CP_Color green;
CP_Color blank;
CP_Color white;

CP_Sound MainMenuMusic = NULL; //Music
CP_Image MainMenu = NULL;

static float timer = 0;

float window_settings[2]; //Contains width and height
float play_dimensions[4]; //Contains centre in x and y and width and height
float exit_dimensions[4];

float click_x;
float click_y;

void Main_Menu_Init(void)
{
	//Load stuff and colors
	MainMenu = CP_Image_Load("Assets/JapanImageNight1.jpg"); //Load background image
	myfont = CP_Font_Load("Assets/Atma-Medium.ttf"); //Load font
	MainMenuMusic = CP_Sound_LoadMusic("Assets/MainMenuMusic.mp3"); // Music
	grey = CP_Color_Create(128, 128, 128, 255);
	black = CP_Color_Create(0, 0, 0, 255);
	red = CP_Color_Create(230, 0, 10, 255);
	dred = CP_Color_Create(200, 50, 50, 255);
	blue = CP_Color_Create(0, 0, 255, 255);
	green = CP_Color_Create(0, 255, 0, 255);
	white = CP_Color_Create(255, 255, 255, 255);
	blank = CP_Color_Create(0, 255, 0, 0);

	//Window size
	width = CP_System_GetWindowWidth();
	height = CP_System_GetWindowHeight();
	
	//Window size array setting
	window_settings[0] = width; //Declaring here cus cprocessing is only called in the init.
	window_settings[1] = height;//Didn't check but should work

	//Play button size
	play_center_x = width / 2 - 120;
	play_center_y = (height / 4) * 3;
	play_width = width / 8;
	play_height = height / 8;

	//Play button array
	play_dimensions[0] = play_center_x;
	play_dimensions[1] = play_center_y;
	play_dimensions[2] = play_width;
	play_dimensions[3] = play_height;

	//Exit button size
	exit_center_x = width / 2 + 165;
	exit_center_y = (height /4) *3;
	exit_width = width / 8;
	exit_height = height / 8;
	//Exit button array
	exit_dimensions[0] = exit_center_x;
	exit_dimensions[1] = exit_center_y;
	exit_dimensions[2] = exit_width;
	exit_dimensions[3] = exit_height;

	CP_Sound_PlayAdvanced(MainMenuMusic, 1.0, 1.0, TRUE, CP_SOUND_GROUP_0);

}

void Main_Menu_Update(void)
{
	//Background and font
	CP_Graphics_ClearBackground(CP_Color_Create(128, 128, 128, 255));
	CP_Font_Set(myfont);

	

	//Background
	CP_Image_Draw(MainMenu, width/2, height/2, width, height, 255);

	//Sound stuff
	float songLength = 500; //Not entirely sure what this does yet
	static float timer = 0;

	timer += CP_System_GetDt();
		if (timer >= .5f * songLength)
		{
			CP_Sound_PauseGroup(CP_SOUND_GROUP_0); //Pause
		}
		if (timer >= songLength)
		{
			CP_Sound_ResumeGroup(CP_SOUND_GROUP_0); //Resume player
		}
	
	//Gamename
	Draw_Text(white, 200, "Phaze", width/2 - 89, height/3);

	//Play button
	Draw_Rect(white, play_dimensions[0], play_dimensions[1], play_dimensions[2], play_dimensions[3], 0, 0);
	Draw_Text(black, 60, "Play", play_dimensions[0] + 10, play_dimensions[1]+10);

	//Exit button
	Draw_Rect(white, exit_dimensions[0], exit_dimensions[1], exit_dimensions[2], exit_dimensions[3], 0, 0);
	Draw_Text(black, 60, "Exit", exit_dimensions[0] + 10, exit_dimensions[1]+10);


	//Button detection
	if (CP_Input_MouseClicked())
	{
		click_x = CP_Input_GetMouseX();
		click_y = CP_Input_GetMouseY();

		if (IsAreaClicked(play_dimensions[0], play_dimensions[1], play_dimensions[2], play_dimensions[3], click_x, click_y) == 1) //work on this only as it is the only thing that links to utils.c
		{
			printf("Play\n");
			//CP_Sound_PauseGroup(CP_SOUND_GROUP_0); //Pause music
			CP_Engine_SetNextGameState(LevelSelect_Init, LevelSelect_Update, LevelSelect_Exit); //CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
		}
		if (IsAreaClicked(exit_dimensions[0], exit_dimensions[1], exit_dimensions[2], exit_dimensions[3], click_x, click_y) == 1)
		{
			printf("Exit\n");
			CP_Sound_PauseGroup(CP_SOUND_GROUP_0);
			CP_Engine_Terminate();
		}

	}
}

void Main_Menu_Exit(void)
{
	
}