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
