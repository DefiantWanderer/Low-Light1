#pragma once
#include "utils.h"
#include "sprite.h"

void Level1_Init(void);
void Level1_Update(void);
void Level1_Exit(void);
//void CameraDemo_Init(void);
//void CameraDemo_Update(void);


void DrawPrincess();
int DrawLight();
void DrawPlatform(float level);
void DrawRightWall(void);
void DrawLightCube(void);
void DrawPortals(void);
void Drawfill1(void);
void Drawfill2(void);
void Drawfill3(void);

void Updateplayerposition(void);

void PrincessGravity(void);
void wallcollision(void);
int PrincessSeeLight(void);
void PrincessJump(void);
void PrincessLeap(void);

int LightCubePickup(void);
int TimerOne(void);

int CreateLevelDataArray(char arr[]);
int GeneratePlatformFromData(char arr[]);
void PortalLink(void);