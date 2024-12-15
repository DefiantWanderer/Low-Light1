#pragma once

#include "cprocessing.h"

int IsAreaClicked(float area_center_x, float area_center_y, float area_width, float area_height, float click_x, float click_y);
int IsCircleClicked(float circle_center_x, float circle_center_y, float diameter, float click_x, float click_y);
int AreCirclesIntersecting(float c1_x, float c1_y, float r1, float c2_x, float c2_y, float r2);
int AreRectIntersecting(float rect1_x, float rect1_y, float rect1_width, float rect1_height, float rect2_x, float rect2_y, float rect2_width, float rect2_height);
int IsMouseHovering(float circle_center_x, float circle_center_y, float diameter, float mouseX, float mouseY);
void Draw_Rect(CP_Color color, float area_center_x, float area_center_y, float area_width, float area_height, float angle, float cornerRadius);
void Draw_Circle(CP_Color color, CP_Color strokecolor, float circle_center_x, float circle_center_y, float diameter);
void Draw_Text(CP_Color fill, float size, const char* text, float x, float y);
void Draw_Star(CP_Color color,float x, float y);
void PlaySound(CP_Sound Music);
void spritesection(CP_Image, float X, float Y, float width, float height, float leftlimit, float toplimit, float rightlimit, float botlimit, float alpha);
void SpriteRunning(CP_Image image, float X, float Y, float height);
void SpriteJumping(CP_Image image, float X, float Y, float height);
void SpriteHit(CP_Image image, float X, float Y, float height);

CP_Color grey;
CP_Color black;
CP_Color red;
CP_Color blue;
CP_Color green;

//First

typedef struct {
	float Llim;
	float Top;
	float Rlim;
	float Bot;

}SpriteRunCoords, SpriteJumpCoords;

SpriteRunCoords coords[10];
SpriteJumpCoords coord[10];

//Pointers to affect sprite.
int increment; //increment for running
int *ptrincrement;
int hitincrement; //increment for running
int* ptrhitincrement;
int jumpincrement; //increment for jumping
int* ptrjumpincrement;
int flip;
int* pflip;
float jumptimer;
float* ptrjumptimer;
int jumpmode;
int* ptrjumpmode;
float timegap;
float* ptrtimegap;
float Simageheight;
float* ptrSimageheight;
float Simagejumpheight;
float *ptrSimagejumpheight;
float soundtimer;
float* ptrsoundtimer;
float soundmode;
float* ptrsoundmode;

//Last

//Credit list
/*
Collect Coin by bradwesson Id - 135936
Doors, Hardware, Lock, Unlock Metal Gate, Security Grill Door SND26177
weapon-knife-blade-equip-03
Dash by perduuus Id-701795
Musical, Plucked, Short Phrase, Musical Accent, Chinese Instrument, Guzheng SND97027
Musical, Plucked, Short Phrase, Musical Accent, Japanese Instrument, Koto 01 SND97003
Musical, Plucked, Short Phrase, Musical Accent, Japanese Instrument, Koto 02 SND97002
Musical, Stringed, Koto Short Melodic Phrase, Up, Down SND69651
Throwing Projectile Blades And Deflecting Sounds by Artninja Id-750490
Oof   Qdo by qdo Id-528732
Oof by CrimsonImaging Id-493743
Fall With Impact by smcameron Id-50776
Hop8 by felixyadomi Id-456374
jump-landing-hit-stone-concrete-default-03
Swooshes, Swish, Throwing Knife, Shuriken, Flying Star, Throw, Kung Fu SND34596
Swooshes, Swish, Throwing Knife, Whizz By SND115624 1
Throwing Projectile Blades And Deflecting Sounds by Artninja Id-750490
Throwing Projectile Blades Hit W Ringout 09022024 by Artninja Id-752684
Footsteps, Human, Asphalt, Bare Foot, Running 01 SND0992
Footsteps, Human, Fast Running, Wooden Steps SND17410
Footsteps, Human, Grass, Sneaker, Running SND1043
Male Leather Sole Shoes Sprinting Footstep Sound by Artninja Id-742970
Weapons, Sword, Swipe, Hit Body, Impact, Hard, Squelch, Head Or Limb Fall To Ground SND34529
Games, Video, Video Game, Fight Sword Swoosh, Slide SND60122
*/;