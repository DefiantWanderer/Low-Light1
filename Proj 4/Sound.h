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

CP_Sound Level1song;
CP_Sound Level2song;
CP_Sound Level3song;
CP_Sound Level4song;
CP_Sound LampBreak;

CP_Sound mainmenu1;
CP_Sound mainmenu2;
CP_Sound mainmenu3;
CP_Sound Storysong1;
CP_Sound Storysong2;
CP_Sound Rumbling;








//Load all sounds into memory for use
void LoadSounds();

//Play main menu music for 
void PlayMainMenuMusic();

//Free all sounds from memory
void FreeSounds();

//Has the main menu been played before? Var to check it
CP_BOOL isMainMenuMusicPlayedFirstTime;