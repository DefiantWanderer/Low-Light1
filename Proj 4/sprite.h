#pragma once

typedef struct
{	//These r member variables
	CP_Image image;
	float x, y; //Position of the sprite
	float speed;
	int framecount;
	int currentframe;
	float framewidth, frameheight;
}Sprite; //This struct named Sprite contains



void Sprite_InIt(Sprite* sprite, const char* imagePath, float x, float y, float speed, int framecount, float framewidth, float frameheight);
void Sprite_Update(Sprite* sprite, float deltaTime);
void DrawSprite(Sprite* sprite);