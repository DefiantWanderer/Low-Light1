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
	GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself.mp3"); //	 GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself
	GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyslf.mp3"); //	 GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself
	CommentAboutDarkness = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/CommentAboutDarkness.mp3");//CommentAboutDarknes
	CouldYouShineSomeLightHere = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/CouldYouShineSomeLightHere.mp3"); //	 CouldYouShineSomeLightHer
	GoodThingYouAreHere = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/GoodThingYouAreHere.mp3"); //	 GoodThingYouAreHer
	GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low - Light1/Assets/GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself.mp3");//	 GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself
	HelloIsAnyoneThere = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/HelloIsAnyoneThere.mp3"); //	 HelloIsAnyoneTher
	HoldThemBack = CP_Sound_Load("		C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/HoldThemBack.mp3"); //	 HoldThemBac
	ICantDoThatYetShineMoreLight = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/ICantDoThatYetShineMoreLight.mp3"); //	 ICantDoThatYetShineMoreLigh
	ICantMakeThatJumpIfICantSeeIt = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Lig ht1/Assets/ICantMakeThatJumpIfICantSeeIt.mp3"); //	 ICantMakeThatJumpIfICantSeeI
	ICantSeeAnythingLightTheWay = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/ICantSeeAnythingLightTheWay.mp3"); //	 ICantSeeAnythingLightTheWa
	IHopeYouEnjoyYourTimeHere = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/IHopeYouEnjoyYourTimeHere.mp3"); //	 IHopeYouEnjoyYourTimeHer
	IWonderWhatThisPlaceIs = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/IWonderWhatThisPlaceIs.mp3"); //	 IWonderWhatThisPlaceI
	KeyPickUpComment = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/KeyPickUpComment.mp3"); //	 KeyPickUpCommen
	LightCubePickUp = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LightCubePickUp.mp3"); //	 LightCubePickU
	LightTheWay = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/LightTheWay.mp3"); //	 LightTheWa
	mmmTasty = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/mmmTasty.mp3"); //	 mmmTasty
	mmmThatLooksDangerous = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/mmmThatLooksDangerous.mp3"); //	 mmmThatLooksDangerou
	NiceWork = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/NiceWork.mp3"); //	 NiceWor
	NotSureWhatThisPlaceIsExplore = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/NotSureWhatThisPlaceIsExplore.mp3"); //	 NotSureWhatThisPlaceIsExplor
	ObservationOfLightOnEnemies = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/ObservationOfLightOnEnemies.mp3"); //	 ObservationOfLightOnEnemie
	OhGoodThatYouAreHere = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/OhGoodThatYouAreHere.mp3"); //	 OhGoodThatYouAreHer
	ThanksForBeingMyLight = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/ThanksForBeingMyLight.mp3"); //	 ThanksForBeingMyLigh
	ThankYouForPlaying = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/ThankYouForPlaying.mp3"); //	 ThankYouForPlayin
	ThatsQuiteSmart = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/ThatsQuiteSmart.mp3"); //	 ThatsQuiteSmar
	ThatWasALotOfDoors = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/ThatWasALotOfDoors.mp3"); //	 ThatWasALotOfDoor
	ThereHasToBeAWayOutOfHere = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/ThereHasToBeAWayOutOfHere.mp3"); //	 ThereHasToBeAWayOutOfHer
	ThisShouldIncreaseTheBrightness = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/ThisShouldIncreaseTheBrightness.mp3"); //	 ThisShouldIncreaseTheBrightnes
	WeMadeItSoFar = CP_Sound_Load("	C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/WeMadeItSoFar.mp3"); //	 WeMadeItSoFa
	WeMadeItSoFarAndMore = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/WeMadeItSoFarAndMore.mp3"); //	 WeMadeItSoFarAndMor
	WhatAreYou = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/WhatAreYou.mp3"); //	 WhatAreYo
	WhatIsThat = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/WhatIsThat.mp3"); //	 WhatIsTha
	WhatIsYourName = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/WhatIsYourName.mp3"); //	 WhatIsYourNam
	WhoaMadeItToTheTop = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/WhoaMadeItToTheTop.mp3"); //	 WhoaMadeItToTheTo
	WhosThere = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/WhosThere.mp3"); //	 WhosTher
	WhyAmIHere = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/WhyAmIHere.mp3");//	 WhyAmIHer
	WhyAmWowImUpHere = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/WhyAmWowImUpHere.mp3"); //	 WhyAmWowImUpHer
	WhyAmIHereagain = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/WhyAmIHereagain.mp3"); //	 WhyAmIHereagai
	WowMadeTheJump = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/WowMadeTheJump.mp3"); //	 WowMadeTheJum
	WowThatsBright = CP_Sound_Load("C:/Users/yongw/SIT Stuff/CSD1401 Software Engineering Proj pass fail/New folder/Low-Light1/Assets/WowThatsBright.mp3"); //	 WowThatsBrigh

	//End of sound and graphics

	//sMainMenuMusicPlayedFirstTime = TRUE;

	//CP_Sound_PlayAdvanced(soundEffectSwordSwing, 1.0, 1.0, FALSE, CP_SOUND_GROUP_3);
}

void PlayMainMenuMusic()
{
	/*if (isMainMenuMusicPlayedFirstTime == TRUE)
	{
		CP_Sound_PlayAdvanced(soundMainMenuMusic, (float)0.2, (float)0.95, TRUE, CP_SOUND_GROUP_0);
		CP_Sound_ResumeGroup(CP_SOUND_GROUP_0);
		isMainMenuMusicPlayedFirstTime = FALSE;
	}
	else
		CP_Sound_ResumeGroup(CP_SOUND_GROUP_0);*/
}

//Should be called on game close
void FreeSounds()
{
	CP_Sound_StopAll();

	//Sound Effects

		CP_Sound_Free(&GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself);
		CP_Sound_Free(&CommentAboutDarkness);
		CP_Sound_Free(&CouldYouShineSomeLightHere);
		CP_Sound_Free(&GoodThingYouAreHere);
		CP_Sound_Free(&GottaAdmitIWouldNotHaveBeenAbleToSolveThatMyself);
		CP_Sound_Free(&HelloIsAnyoneThere);
		CP_Sound_Free(&HoldThemBack);
		CP_Sound_Free(&ICantDoThatYetShineMoreLight);
		CP_Sound_Free(&ICantMakeThatJumpIfICantSeeIt);
		CP_Sound_Free(&ICantSeeAnythingLightTheWay);
		CP_Sound_Free(&IHopeYouEnjoyYourTimeHere);
		CP_Sound_Free(&IWonderWhatThisPlaceIs);
		CP_Sound_Free(&KeyPickUpComment);
		CP_Sound_Free(&LightCubePickUp);
		CP_Sound_Free(&LightTheWay);
		CP_Sound_Free(&mmmTasty);
		CP_Sound_Free(&mmmThatLooksDangerous);
		CP_Sound_Free(&NiceWork);
		CP_Sound_Free(&NotSureWhatThisPlaceIsExplore);
		CP_Sound_Free(&ObservationOfLightOnEnemies);
		CP_Sound_Free(&OhGoodThatYouAreHere);
		CP_Sound_Free(&ThanksForBeingMyLight);
		CP_Sound_Free(&ThankYouForPlaying);
		CP_Sound_Free(&ThatsQuiteSmart);
		CP_Sound_Free(&ThatWasALotOfDoors);
		CP_Sound_Free(&ThereHasToBeAWayOutOfHere);
		CP_Sound_Free(&ThisShouldIncreaseTheBrightness);
		CP_Sound_Free(&WeMadeItSoFar);
		CP_Sound_Free(&WeMadeItSoFarAndMore);
		CP_Sound_Free(&WhatAreYou);
		CP_Sound_Free(&WhatIsThat);
		CP_Sound_Free(&WhatIsYourName);
		CP_Sound_Free(&WhoaMadeItToTheTop);
		CP_Sound_Free(&WhosThere);
		CP_Sound_Free(&WhyAmIHere);
		CP_Sound_Free(&WhyAmWowImUpHere);
		CP_Sound_Free(&WhyAmIHereagain);
		CP_Sound_Free(&WowMadeTheJump); //	 WowMadeTheJum);
		CP_Sound_Free(&WowThatsBright);
}
