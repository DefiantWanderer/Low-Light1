#include "cprocessing.h"
#include "sprite.h"

//typedef struct
//{
//	CP_Image image;
//	float x, y; //Position of the sprite
//	float speed;
//	int framecount;
//	int currentframe;
//	float framewidth, frameheight;
//}Sprite; //This struct named Sprite contains



void Sprite_InIt(Sprite* sprite, const char* imagePath, float x, float y, float speed, int framecount, float framewidth, float frameheight) //This function initializes the sprite.
{
	sprite->image = CP_Image_Load("Assets/BlueNinjaMove.png"); //Initialize ninja as image
	sprite->x = x; //initialize x
	sprite->y = y; //initialize y
	sprite->speed = speed; //Set speed
	sprite->framecount = framecount; //Set the frame count limit
	sprite->currentframe = 0; //Frame zero is the sprite default
	sprite->framewidth = framewidth;
	sprite->frameheight = frameheight;
}

//Static animations
void Sprite_Update(Sprite* sprite, float deltaTime) //This function updates the sprite
{
	static float frametimer = 0; //time between each from update
	static const float frameinterval = 0.1f; //it affects the frame change rate. const cus this is my no-no zone, 
	frametimer += deltaTime;
	if (frametimer >= frameinterval)
	{
		frametimer -= frameinterval;
	}
	
	sprite->x += sprite->speed * deltaTime; //The sprite is constantly being updated by *deltaTime if you +1 or +deltaTime the scaling is diff for diff resolutions

	if (sprite->x < 0 || sprite->x > CP_System_GetWindowWidth() - sprite->framewidth)
	{
		sprite->speed = -sprite->speed;	//If sprite becomes negative reverse the direction
	}

	sprite->currentframe = (sprite->currentframe + 1) % (sprite->framecount -1); //remainder value of next frame / frame count limit to update currentframe number. 
	
}

//Draw sprite
void DrawSprite(Sprite* sprite)
{
	//int frameX = sprite->currentframe * sprite->framewidth;
	//int frameY = row * sprite->frameheight;//Target a specific row in sheet
	SpriteRunning(sprite->image, sprite->x, sprite->y, sprite->framewidth, sprite->frameheight, 0);
	//SpriteRunning(sprite->image, sprite->x, sprite->y, sprite->framewidth, sprite->frameheight, 0);

}