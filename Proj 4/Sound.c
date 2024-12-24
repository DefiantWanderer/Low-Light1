/******************************************************************************
@file SoundManager.c
@author(s) Clement Ang (ang.c), Yong Wei (l.yongwei)
@course Software Engineering Project
@section b
@team BM Platformers
@date 26/11/24
@contribution
Clement Ang - Collating all loading into 1 file and freeing, main menu play tracker
Yong Wei - Loading all sounds/music and their variables, playing all sounds/music
@brief This file contains the definition/logic for loading and freeing sounds into their variables, as well as playing main menu music
@copyright © Copyright: 2024, Digipen Institute of Technology, Singapore
******************************************************************************/
#include "Sound.h"

//How to use sounds?
/*
1. Add "CP_Sound Coin" above your init.
2. Add "Coin = CP_Sound_LoadMusic("Assets/Coin.wav");" to your init.
3. Use CP_Sound_PlayAdvanced(Jump, 1.0, 1.0, FALSE, CP_SOUND_GROUP_3); to play the sound
*/

void LoadSounds()
{
	//Music
	soundMainMenuMusic = CP_Sound_LoadMusic("Assets/MainMenuMusic.mp3"); // Music

	//Sounds effects. CP_Sound_PlayAdvanced(Dash, 1.0, 1.0, FALSE, CP_SOUND_GROUP_6);
	soundEffectSwordSwing = CP_Sound_Load("Assets/SwordSwing.mp3");
	sounndEffectSwordSwing2 = CP_Sound_Load("Assets/SwordSwing2.wav");
	soundEffectSwordDeflect = CP_Sound_Load("Assets/SwordDeflect.mp3");

	soundEffectCoin = CP_Sound_Load("Assets/Coin.wav");
	soundEffectJump = CP_Sound_Load("Assets/Jump.wav");
	soundEffectDash = CP_Sound_Load("Assets/Dash.wav");
	soundEffectDoor = CP_Sound_Load("Assets/Door.wav");
	soundEffectEnemyHit = CP_Sound_LoadMusic("Assets/EnemyHit.wav");
	soundEffectLandingOnPlatform = CP_Sound_Load("Assets/LandingOnPlatform.wav");
	soundEffectRunningOnWood = CP_Sound_Load("Assets/RunningOnWood.wav");
	soundEffectMenuButton = CP_Sound_Load("Assets/MenuButton.wav");
	soundEffectOof1 = CP_Sound_Load("Assets/Oof1.wav");
	soundEffectOof2 = CP_Sound_LoadMusic("Assets/Oof2.wav");
	soundEffectRunning1 = CP_Sound_Load("Assets/Running1.wav");
	soundEffectRunning2 = CP_Sound_Load("Assets/Running2.wav");
	soundEffectRunningOnGrass = CP_Sound_Load("Assets/RunningOnGrass.wav");
	soundEffectShuriken1 = CP_Sound_Load("Assets/Shuriken1.wav");
	soundEffectShuriken2 = CP_Sound_Load("Assets/Shuriken2.wav");


	soundEffectWin1 = CP_Sound_Load("Assets/Win1.wav");
	soundEffectWin2 = CP_Sound_Load("Assets/Win2.wav");
	soundEffectWin3 = CP_Sound_Load("Assets/Win3.wav");
	soundEffectWin4 = CP_Sound_Load("Assets/Win4.wav");
	soundEffectKnifeEquip = CP_Sound_Load("Assets/KnifeEquip.wav");
	soundEffectFallingDeath = CP_Sound_Load("Assets/FallingDeath.wav"); 
	soundEffectLevel1music = CP_Sound_Load("Assets/level1music.mp3");
	GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself = CP_Sound_Load("C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets / GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself"); //	 GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself
	GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself = CP_Sound_Load("C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets / GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyslf"); //	 GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself
	CommentAboutDarkness = CP_Sound_Load("C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /CommentAboutDarkness");//CommentAboutDarknes
	CouldYouShineSomeLightHere = CP_Sound_Load("C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /CouldYouShineSomeLightHere"); //	 CouldYouShineSomeLightHer
	GoodThingYouAreHere = CP_Sound_Load("C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /GoodThingYouAreHere"); //	 GoodThingYouAreHer
	GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself = CP_Sound_Load("C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets / GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself");//	 GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself
	HelloIsAnyoneThere = CP_Sound_Load("C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /HelloIsAnyoneThere"); //	 HelloIsAnyoneTher
	HoldThemBack = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /HoldThemBack"); //	 HoldThemBac
	ICantDoThatYetShineMoreLight = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /ICantDoThatYetShineMoreLight"); //	 ICantDoThatYetShineMoreLigh
	ICantMakeThatJumpIfICantSeeIt = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /ICantMakeThatJumpIfICantSeeIt"); //	 ICantMakeThatJumpIfICantSeeI
	ICantSeeAnythingLightTheWay = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /ICantSeeAnythingLightTheWay"); //	 ICantSeeAnythingLightTheWa
	IHopeYouEnjoyYourTimeHere = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /IHopeYouEnjoyYourTimeHere"); //	 IHopeYouEnjoyYourTimeHer
	IWonderWhatThisPlaceIs = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /IWonderWhatThisPlaceIs"); //	 IWonderWhatThisPlaceI
	KeyPickUpComment = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /KeyPickUpComment"); //	 KeyPickUpCommen
	LightCubePickUp = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /LightCubePickUp"); //	 LightCubePickU
	LightTheWay = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /LightTheWay"); //	 LightTheWa
	mmmTasty = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /mmmTasty"); //	 mmmTast
	mmmThatLooksDangerous = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /mmmThatLooksDangerous"); //	 mmmThatLooksDangerou
	NiceWork = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /NiceWork"); //	 NiceWor
	NotSureWhatThisPlaceIsExplore = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /NotSureWhatThisPlaceIsExplore"); //	 NotSureWhatThisPlaceIsExplor
	ObservationOfLightOnEnemies = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /ObservationOfLightOnEnemies"); //	 ObservationOfLightOnEnemie
	OhGoodThatYouAreHere = CP_Sound_Load("	C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /	OhGoodThatYouAreHere"); //	 OhGoodThatYouAreHer
	ThanksForBeingMyLight = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /ThanksForBeingMyLight"); //	 ThanksForBeingMyLigh
	ThankYouForPlaying = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /ThankYouForPlaying"); //	 ThankYouForPlayin
	ThatsQuiteSmart = CP_Sound_Load("	C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /	ThatsQuiteSmart"); //	 ThatsQuiteSmar
	ThatWasALotOfDoors = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /ThatWasALotOfDoors"); //	 ThatWasALotOfDoor
	ThereHasToBeAWayOutOfHere = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /ThereHasToBeAWayOutOfHere"); //	 ThereHasToBeAWayOutOfHer
	ThisShouldIncreaseTheBrightness = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /ThisShouldIncreaseTheBrightness"); //	 ThisShouldIncreaseTheBrightnes
	WeMadeItSoFar = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /WeMadeItSoFar"); //	 WeMadeItSoFa
	WeMadeItSoFarAndMore = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /WeMadeItSoFarAndMore"); //	 WeMadeItSoFarAndMor
	WhatAreYou = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /WhatAreYou"); //	 WhatAreYo
	WhatIsThat = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /WhatIsThat"); //	 WhatIsTha
	WhatIsYourName = CP_Sound_Load("	C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /	WhatIsYourName"); //	 WhatIsYourNam
	WhoaMadeItToTheTop = CP_Sound_Load("	C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /	WhoaMadeItToTheTop"); //	 WhoaMadeItToTheTo
	WhosThere = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /WhosThere"); //	 WhosTher
	WhyAmIHere = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /WhyAmIHere");//	 WhyAmIHer
	WhyAmWowImUpHere = CP_Sound_Load("	C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /	WhyAmWowImUpHere"); //	 WhyAmWowImUpHer
	WhyAmIHereagain = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /WhyAmIHereagain"); //	 WhyAmIHereagai
	WowMadeTheJump = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /WowMadeTheJump"); //	 WowMadeTheJum
	WowThatsBright = CP_Sound_Load("		C: / Users / yongw/ SIT Stuff / CSD1401 Software Engineering Proj pass fail / New folder / Low - Light1 / Assets /WowThatsBright"); //	 WowThatsBrigh

	//End of sound and graphics

	isMainMenuMusicPlayedFirstTime = TRUE;

	CP_Sound_PlayAdvanced(soundEffectSwordSwing, 1.0, 1.0, FALSE, CP_SOUND_GROUP_3);
}

void PlayMainMenuMusic()
{
	if (isMainMenuMusicPlayedFirstTime == TRUE)
	{
		CP_Sound_PlayAdvanced(soundMainMenuMusic, (float)0.2, (float)0.95, TRUE, CP_SOUND_GROUP_0);
		CP_Sound_ResumeGroup(CP_SOUND_GROUP_0);
		isMainMenuMusicPlayedFirstTime = FALSE;
	}
	else
		CP_Sound_ResumeGroup(CP_SOUND_GROUP_0);
}

//Should be called on game close
void FreeSounds()
{
	CP_Sound_StopAll();

	CP_Sound_Free(&soundMainMenuMusic);

	//Sound Effects
	CP_Sound_Free(&soundEffectSwordDeflect);
	CP_Sound_Free(&soundEffectSwordSwing);
	CP_Sound_Free(&sounndEffectSwordSwing2);
	CP_Sound_Free(&soundEffectCoin);
	CP_Sound_Free(&soundEffectDash);
	CP_Sound_Free(&soundEffectDoor);
	CP_Sound_Free(&soundEffectEnemyHit);
	CP_Sound_Free(&soundEffectFallingDeath);
	CP_Sound_Free(&soundEffectJump);
	CP_Sound_Free(&soundEffectKnifeEquip);
	CP_Sound_Free(&soundEffectLandingOnPlatform);
	CP_Sound_Free(&soundEffectMenuButton);
	CP_Sound_Free(&soundEffectOof1);
	CP_Sound_Free(&soundEffectOof2);
	CP_Sound_Free(&soundEffectRunning1);
	CP_Sound_Free(&soundEffectRunning2);
	CP_Sound_Free(&soundEffectRunningOnGrass);
	CP_Sound_Free(&soundEffectRunningOnWood);
	CP_Sound_Free(&soundEffectShuriken1);
	CP_Sound_Free(&soundEffectShuriken2);
	CP_Sound_Free(&soundEffectWin1);
	CP_Sound_Free(&soundEffectWin2);
	CP_Sound_Free(&soundEffectWin3);
	CP_Sound_Free(&soundEffectWin4);
	CP_Sound_Free(&soundEffectLevel1music);
	CP_Sound_Free(&soundEffectLandingOnPlatform);

}
