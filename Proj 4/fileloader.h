/******************************************************************************
@file fileloader.h
@author Lu Yong Wei
@email L.yongwei@digipen.edu.sg
@course CSD1401 Software Engineering Project
@game Low Light
@brief Declarations for loading level files and saving/loading level data.
@copyright Copyright (C) 2026 DigiPen Institute of Technology Singapore. All rights reserved.
******************************************************************************/

#pragma once
#include <stdio.h>

// LoadFile() is used to read and get the contents of the respective level text file
int LoadFile(int levelIndex);

// CreateSaveDataFile() is used to create a text file that will be used to save data in the future
void CreateSaveDataFile(int numLevels);

// LoadData() is used to read and get the data of the respective level like number of stars, score, time taken, coins
void LoadData(int levelNum);

// SaveData() is used to save the data of the respective level like number of stars, score, time taken, coins to a text file
int SaveData(int levelNum, int numStars, int score, int timeTaken, int numCoins);

// SetRemainingArrayNULL() is used to set the remaining values of a char array to be NULL
void SetRemainingArrayNULL(char input[]);

// GetNumDigits() is used to get the number of digits of an integar number
int GetNumDigits(int input);

// ConvertIntToChar() is used to convert an integar number to a char and add it into a char array
void ConvertIntToChar(int numDigits, int input);

// This function is temporary, it demonstrates how to use the functions in FileLoader.c
void FileLoaderTesting(void);

char loadedLevel[1000]; // Represents the respective level's level design
const char* currentLevelData[4]; // Represents the respective level's data - stars, score, time taken, coins
int currentLevelDataValues[4]; // Represents the respective level's data in integars, use this variable to display the info on the screen
char saveData[300]; // Represents the data to be saved into a text file
int saveDataIndex; // Index used with the saveData[]