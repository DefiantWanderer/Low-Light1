#pragma once

#ifndef UTILS_H
#define UTILS_H

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
int leapcheck(void);
int lampclicked(void);
int lamppickedup(void);
int lampborder(void);

struct platformdata
{
	float x;
	float y;
	float width;
	float height;
};

extern int level;
extern struct platformdata textarr[50];
extern struct platformdata cliffleftarr[6];
extern struct platformdata cliffrightarr[6];

//Platform fill
extern struct platformdata fill1[5];
extern struct platformdata fill2[5];
extern struct platformdata fill3[5];

/*Low Light variables                     */

//Player mouse position
extern CP_Vector playerposition;

//Player stats
float lightradiusarray[5];
int lightlevel;
int* ptrlightlevel;
float lightradius;

//Princess
float princessheight;
float princesseyelevel;
float princesswidth;
float princessmovement;
float princessjumpheight;
float princessvision;
int flip;
float spriteframe;
float princessspritewidth;
float princessalpha;

//Platform dimensions
float platformheight;
float platformwidth;
float lowestplatformy;
float platformsgenerated;

//Timer related
float timeroneactivate;
float leaptimeractivate;
int leaprightmode;
int leapleftmode;
float timer;
float princessjumpactivate;
float princessjumptimer;

//Spawn point x and y
CP_Vector spawnpoint;
float spawnx;
float spawny;

//Princess x and y
CP_Vector princess;

//Level related
float gravity;

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
struct platformdata platformarr[500];
float numberofplatforms;

struct platformdata lightcube[5];
float numberoflightcubes;
float lightcubewidth;
float lightcubeheight;

struct platformdata inportalarr[3];
struct platformdata outportalarr[3];
float numberofinportals;
float numberofoutportals;
float numberofleftcliffs;
float numberofrightcliffs;
float inportalwidth;
float inportalheight;
float outportalwidth;
float outportalheight;
float teleportoffset;
float cliffwidth;
float cliffheight;


struct platformdata leftwallarr[50];
struct platformdata rightwallarr[50];
float numberofleftwalls;
float numberofrightwalls;
float leftwallwidth;
float leftwallheight;




extern struct platformdata textarr[50];
float numberoftexts;
//Array and draw function
extern char arr[1000];
int stopgenerate;
int onplatform;
float buffer;

//Level only
//char* levelnames[6];
char* levelarr;

//Lamp 
float lanternwidth;
float lanternheight;
float lanternoffset;
float lampspawnx;
float lampspawny;

int lamppickup;


//int plat; //New row counter increases
//int platformcount;
//int inportalcount;
//int outportalcount;
//int lightcubecount;
//int leftwallcount;
//int rightwallcount;
//int textcount;
//int fill1count;
//int fill2count;
//int fill3count;
//int cliffleftcount;
//int cliffrightcount;
//
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

#endif // UTILS_H