/******************************************************************************
@file SoundManager.h
@author(s) Clement Ang (ang.c), Yong Wei (l.yongwei)
@course Software Engineering Project
@section b
@team BM Platformers
@date 26/11/24
@contribution
Clement Ang - Collating all loading into 1 file and freeing, main menu play tracker
Yong Wei - Loading all sounds/music and their variables, playing all sounds/music
@brief This file contains the declaration for loading and freeing sounds and thier variables, as well as playing main menu music
@copyright © Copyright: 2024, Digipen Institute of Technology, Singapore
******************************************************************************/

#pragma once
#include <cprocessing.h>
#include <stdio.h>


//How to use sounds?
/*
1. Add "CP_Sound Coin" above your init.
2. Add "Coin = CP_Sound_LoadMusic("Assets/Coin.wav");" to your init.
3. Use CP_Sound_PlayAdvanced(Jump, 1.0, 1.0, FALSE, CP_SOUND_GROUP_3); to play the sound
*/

CP_Sound soundMainMenuMusic; //MainMenuMusic = CP_Sound_LoadMusic("Assets/MainMenuMusic.mp3");


//Sounds
CP_Sound soundEffectSwordDeflect;				//SwordDeflect = CP_Sound_LoadMusic("Assets/SwordDeflect.wav");
CP_Sound soundEffectSwordSwing;				//SwordSwing = CP_Sound_LoadMusic("Assets/SwordSwing.wav");
CP_Sound sounndEffectSwordSwing2;				//SwordSwing2 = CP_Sound_LoadMusic("Assets/SwordSwing2.wav");

CP_Sound soundEffectCoin;
CP_Sound soundEffectDash;
CP_Sound soundEffectDoor;						//Door = CP_Sound_LoadMusic("Assets/Door.wav");
CP_Sound soundEffectEnemyHit;					//EnemyHit = CP_Sound_LoadMusic("Assets/EnemyHit.wav");
CP_Sound soundEffectFallingDeath;				//FallingDeath = CP_Sound_LoadMusic("Assets/FallingDeath.wav");
CP_Sound soundEffectJump;
CP_Sound soundEffectKnifeEquip;				//KnifeEquip = CP_Sound_LoadMusic("Assets/KnifeEquip.wav"); CP_Sound_PlayAdvanced(KnifeEquip, 1.0, 1.0, FALSE, CP_SOUND_GROUP_6);
CP_Sound soundEffectLandingOnPlatform;
CP_Sound soundEffectMenuButton;				//MenuButton = CP_Sound_LoadMusic("Assets/MenuButton.wav");
CP_Sound soundEffectOof1;						//Oof1 = CP_Sound_LoadMusic("Assets/Oof1.wav");
CP_Sound soundEffectOof2;						//Oof2 = CP_Sound_LoadMusic("Assets/Oof2.wav");
CP_Sound soundEffectRunning1;					//Running1 = CP_Sound_LoadMusic("Assets/Running1.wav");
CP_Sound soundEffectRunning2;					//Running2 = CP_Sound_LoadMusic("Assets/Running2.wav");
CP_Sound soundEffectRunningOnGrass;			//RunningOnGrass = CP_Sound_LoadMusic("Assets/RunningOnGrass.wav");
CP_Sound soundEffectRunningOnWood;				//RunningOnWood = CP_Sound_LoadMusic("Assets/RunningOnWood.wav");
CP_Sound soundEffectShuriken1;					//Shuriken1 = CP_Sound_LoadMusic("Assets/Shuriken1.wav");
CP_Sound soundEffectShuriken2;					//Shuriken2 = CP_Sound_LoadMusic("Assets/Shuriken2.wav");


CP_Sound soundEffectWin1;						//Win1 = CP_Sound_LoadMusic("Assets/Win1.wav");
CP_Sound soundEffectWin2;						//Win2 = CP_Sound_LoadMusic("Assets/Win2.wav");
CP_Sound soundEffectWin3;						//Win3 = CP_Sound_LoadMusic("Assets/Win3.wav");
CP_Sound soundEffectWin4;						//Win4 = CP_Sound_LoadMusic("Assets/Win4.wav");	
CP_Sound soundEffectLevel1music;				//Level1music = CP_Sound_LoadMusic("Assets/level1music.mp3);
CP_Sound soundEffectLandingOnPlatform;
CP_Sound GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself;
CP_Sound CommentAboutDarkness;
	CP_Sound CouldYouShineSomeLightHere;
		CP_Sound GoodThingYouAreHere;
			CP_Sound GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself;
				CP_Sound HelloIsAnyoneThere;
					CP_Sound HoldThemBack;
					CP_Sound ICantDoThatYetShineMoreLight;
					CP_Sound ICantMakeThatJumpIfICantSeeIt;
					CP_Sound ICantSeeAnythingLightTheWay;
					CP_Sound IHopeYouEnjoyYourTimeHere;
					CP_Sound IWonderWhatThisPlaceIs;
										CP_Sound KeyPickUpComment;
										CP_Sound LightCubePickUp;
										CP_Sound LightTheWay;
										CP_Sound mmmTasty;
										CP_Sound mmmThatLooksDangerous;
											CP_Sound NiceWork;
											CP_Sound NotSureWhatThisPlaceIsExplore;
											CP_Sound ObservationOfLightOnEnemies;
											CP_Sound OhGoodThatYouAreHere;
											CP_Sound ThanksForBeingMyLight;
											CP_Sound ThankYouForPlaying;
											CP_Sound ThatsQuiteSmart;
											CP_Sound ThatWasALotOfDoors;
																	CP_Sound ThereHasToBeAWayOutOfHere;
																		CP_Sound ThisShouldIncreaseTheBrightness;
																			CP_Sound WeMadeItSoFar;
																			CP_Sound WeMadeItSoFarAndMore;
																				CP_Sound WhatAreYou;
CP_Sound WhatIsThat;
CP_Sound WhatIsYourName;
CP_Sound WhoaMadeItToTheTop;
CP_Sound WhosThere;
CP_Sound WhyAmIHere;
CP_Sound WhyAmWowImUpHere;
CP_Sound WhyAmIHereagain;
CP_Sound WowMadeTheJump; //	 WowMadeTheJum
CP_Sound WowThatsBright;

//Load all sounds into memory for use
void LoadSounds();

//Play main menu music for 
void PlayMainMenuMusic();

//Free all sounds from memory
void FreeSounds();

//Has the main menu been played before? Var to check it
CP_BOOL isMainMenuMusicPlayedFirstTime;