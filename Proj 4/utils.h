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

void DrawPrincess();
int DrawLight();
void DrawPlatform(float level);
void DrawRightWall(void);
void DrawLightCube(void);
void DrawPortals(void);
void Drawfill1(void);
void Drawfill2(void);
void Drawfill3(void);
//
void Updateplayerposition(void);
//
void PrincessGravity(void);
void wallcollision(void);
int PrincessSeeLight(void);
int princessseelight;
//void PrincessJump(void);
void PrincessLeap(void);
//
int LightCubePickup(void);
int TimerOne(void);
//
int CreateLevelDataArray(char arr[]);
int GeneratePlatformFromData(char arr[]);
void PortalLink(void);
int cliffintersectcheck(void);
void DrawInstructions(void);

int LeapCheck(void);
int leapcheck;
int lampclicked(void);
int lamppickedup(void);
int lampborder(void);

void DrawNextLevelDoor(void);
void NextLevelLink(void);

void DrawRedLines(CP_Color color, float x, float y);
void DrawSpikes(CP_Color color, float x, float y);
void RedLineSpawning(void);
void RedLinePlayer(void);
void SpikeSpawning(void);
void SpikePrincess(void);
void DrawFallingStars(CP_Color color, float x, float y);
void FallingStarSpawning(void);
void speechtimerone(CP_Sound sound);
void PrincessTalk(void);

void lampintersectstuff(struct platformdata arr[], int numberof, int maxalpha);
void lampintersectwall(void);
void LampIntersectSpike(struct platformdata arr[], int numberof, int maxalpha);

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

//The struct is here!
struct platformdata
{
	float x;
	float y;
	float width;
	float height;
	float alpha;
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

float dt;
//Player mouse position
extern CP_Vector playerposition;

//Player stats
float lightradiusarray[6];
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
float lightpickuptimer;
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
float windowWidth;
float windowHeight;

struct platformdata platformarr[500];
float numberofplatforms;

struct platformdata lightcube[5];
float numberoflightcubes;
float lightcubewidth;
float lightcubeheight;

struct platformdata inportalarr[5];
struct platformdata outportalarr[5];
float numberofinportals;
float numberofoutportals;
float numberofleftcliffs;
float numberofrightcliffs;
float inportalwidth;
float inportalheight;
float outportalwidth;
float outportalheight;
struct platformdata nextlevelarr[5];
float numberofnextlevels;
float teleportoffset;
float cliffwidth;
float cliffheight;


struct platformdata leftwallarr[100];
struct platformdata rightwallarr[100];
float numberofleftwalls;
float numberofrightwalls;
float leftwallwidth;
float leftwallheight;




extern struct platformdata textarr[50];
extern struct platformdata redlinearr[50];
extern struct platformdata spikearr[50];
extern struct platformdata fallingstararr[5];
int numberofspikes;
int numberofredlines;
float redlinewidth;
float redlineheight;
float spikewidth;
float spikeheight;
float numberoftexts;
//Array and draw function
extern char arr[1000];
int stopgenerate;
int onplatform;
float buffer;

//Level only
//char* levelnames[6];
char* levelarr;
char* levelnames[6];

//Lamp 
float lanternwidth;
float lanternheight;
float lanternoffset;
float lampspawnx;
float lampspawny;

float subtitlex;
float subtitley;

float speechtimer;
int speechtimeractivate;

int lamppickup;






#endif // UTILS_H