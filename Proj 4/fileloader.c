/******************************************************************************
@file fileloader.c
@author Lu Yong Wei
@email L.yongwei@digipen.edu.sg
@course CSD1401 Software Engineering Project
@game Low Light
@brief Reads level map text files and reads/writes level save data (stars, score, time, coins).
@copyright Copyright (C) 2026 DigiPen Institute of Technology Singapore. All rights reserved.
******************************************************************************/

#include "fileloader.h"
#include <string.h> // For strcat_s
#include <direct.h> // For _mkdir

#define FPMAXSIZE (50)

/*
// This function is used to read and get the contents of the respective level text file
// It takes an input, and uses it to form a file path to find a text file containing the map level design
// The contents of the text file will be read and added into a char array
// levelIndex - An integar value representing the number of the level shown to the player
*/
int LoadFile(int levelIndex)
{
	char filePath[FPMAXSIZE] = { "Assets/LevelDesigns/level" };
	char ext[] = ".txt";
	char level[] = "01";
	int numDigit = 1;
	int input = levelIndex;

	numDigit = GetNumDigits(input);

	// Based on how many digits, assign the respective char to the char array
	for (int i = numDigit - 1; i >= 0; --i)
	{
		int digit = input % 10;

		if (numDigit == 1)
		{
			level[0] = '0';
			level[1] = (char)(digit + '0');
		}
		else // 2 digit number
		{
			level[i] = (char)(digit + '0');
			input -= digit;
			input /= 10;
		}
	}

	// Combine all the char arrays into 1 single file path to read from
	strcat_s(filePath, FPMAXSIZE, level);
	strcat_s(filePath, FPMAXSIZE, ext);

	FILE* file;
	errno_t error = 0;
	error = fopen_s(&file, filePath, "r"); // r for read mode
	if (error == 0)
	{
		// Reset the contents of the array if needed
		for (int i = 0; i < (int)sizeof(loadedLevel); ++i)
		{
			loadedLevel[i] = ' ';
		}

		char c;
		int counter = 0;
		// Read the contents of the text file and assign the characters to the char array
		while ((c = fgetc(file)) != EOF)
		{
			loadedLevel[counter] = c;
			++counter;
		}

		//printf("Successfully loaded level design\n");
		fclose(file);

		return 1;
	}
	else
	{
		//printf("Error opening file!\n");
		return 0;
	}
}

/*
// This function is used to create a text file that will be used in the future
// Default values for every level is written to the text file
// numLevels - An integar value representing how many levels are available in total
*/
void CreateSaveDataFile(int numLevels)
{
	// Since bin folder is output directory, whatever saved data we write to will be directed to the bin folder
	// Create a new folder for the saved data if it does not exist 
	if (_mkdir("Assets/SavedData") == 0)
	{
		// The program will only come here once to create a new folder
		// Write default values to the text file
		//printf("Folder successfully created\n");

		FILE* file;
		errno_t error = 0;
		char filePath[FPMAXSIZE] = { "Assets/SavedData/data.txt" };
		const char* combined[3];
		char level[10] = { "level" };
		char num[10];
		char stats[30] = { "-0,0,0,0\n" }; // Representing number of stars, score, time taken in seconds, coins

		error = fopen_s(&file, filePath, "w"); // w for write mode 
		if (error == 0)
		{
			// Can assign before the for loop since it is constant
			// Only the level number will change in the char array
			combined[0] = level;
			combined[2] = stats;

			// Depending on the number of levels, write the default values for every level in the text file
			for (int index = 1; index <= numLevels; ++index)
			{
				// Find the number of digits for the index first
				int numDigits = GetNumDigits(index);

				// Based on the number of digits, assign the number characters respectively to the char array
				for (int i = 0; i < numDigits; ++i)
				{
					if (i == numDigits - 1) // Last digit of the number
						num[i] = (char)(index % 10 + '0');
					else
					{
						int multiplier = 1;
						for (int k = 1; k < numDigits - i; ++k)
						{
							multiplier *= 10;
						}
						num[i] = (char)(index / multiplier + '0');
						index -= (int)(num[i] - '0') * multiplier;
					}
				}

				// Make the rest of the char array to be null so that it won't be written in the text file
				SetRemainingArrayNULL(num);

				// Write to the text file
				combined[1] = num;
				for (int i = 0; i < 3; ++i)
				{
					fputs(combined[i], file);
				}
			}

			fclose(file);
			//printf("Created default values\n");
		}
		//else
			//printf("Error opening file!\n");
	}
	else
	{
		// Folder already exists, but the data.txt might or might not exist
		FILE* file;
		errno_t error = 0;
		char filePath[FPMAXSIZE] = { "Assets/SavedData/data.txt" };
		error = fopen_s(&file, filePath, "r"); // r for read mode 
		if (error == 0)
		{
			// Data save file already exists
			//printf("Folder already exists\n");
			fclose(file);
		}
		else
		{
			// Data save file does not exist
			if (_rmdir("Assets/SavedData") == 0)
			{
				//printf("No save file, proceed to create one\n");
				CreateSaveDataFile(numLevels);
			}
		}
	}
}

/*
// This function is used to read and get the data of the respective level like number of stars, coins, time taken etc
// levelNum - An integar value representing the specific level's data we want to load
*/
void LoadData(int levelNum)
{
	FILE* file;
	errno_t error = 0;
	char filePath[FPMAXSIZE] = { "Assets/SavedData/data.txt" };
	error = fopen_s(&file, filePath, "r"); // r for read mode
	if (error == 0)
	{
		char c;
		char numCoins[10] = { "" };
		char numStars[10] = { "" };
		char timeTaken[10] = { "" };
		char score[10] = { "" };
		int counter = 0;
		int tempDataIndex = 0;
		int levelDataIndex = 0;
		int movedFilePointer = 0;
		// Read the contents of the text file and assign the characters to the char array
		while ((c = fgetc(file)) != EOF)
		{
			// Find the line that is supposed to be read first, to move the file pointer
			if (movedFilePointer == 0)
			{
				// Based on the level num, find the level data using \n
				if (c == '\n')
					counter++;

				if (counter == levelNum - 1)
				{
					int offset = 7; // Go to position after 'level1-' in the text file
					// If it is the first line, it is at the start of the text file
					if (counter == 0)
					{
						fseek(file, offset, SEEK_SET);
					}
					else // It is at the \n position right before the line of the level data
					{
						offset += GetNumDigits(levelNum) - 1; // + any extra digits from level number
						fseek(file, offset, SEEK_CUR);
					}
					movedFilePointer = 1;
				}
			}
			else
			{
				// File pointer position has been moved, proceed to read the level data values
				if (c != ',' && c != '\n')
				{
					// Set the remaining values of the char arrays to be NULL
					SetRemainingArrayNULL(numStars);
					SetRemainingArrayNULL(score);
					SetRemainingArrayNULL(timeTaken);
					SetRemainingArrayNULL(numCoins);

					// Assign the valid level data value
					switch (levelDataIndex)
					{
					default: numStars[tempDataIndex] = c;  break;
					case 1:  score[tempDataIndex] = c;	   break;
					case 2:  timeTaken[tempDataIndex] = c; break;
					case 3:  numCoins[tempDataIndex] = c;  break;
					}

					tempDataIndex++;
				}
				else if (c == ',')
				{
					// Switch to the next set of values
					tempDataIndex = 0;
					levelDataIndex++;
				}
				else if (c == '\n')
				{
					// Assign all the values
					currentLevelData[0] = numStars;
					currentLevelData[1] = score;
					currentLevelData[2] = timeTaken;
					currentLevelData[3] = numCoins;
					break;
				}
			}
		}

		fclose(file);

		// Now convert the current level data from char to int values
		for (int i = 0; i < 4; ++i)
		{
			int numChar = (int)strlen(currentLevelData[i]);
			int sum = 0;
			for (int j = 0; j < numChar; ++j)
			{
				int multiplier = 1;

				for (int k = 1; k < numChar - j; ++k)
				{
					multiplier *= 10;
				}

				sum += (int)(currentLevelData[i][j] - '0') * multiplier;
			}
			currentLevelDataValues[i] = sum;
		}
		//printf("Successfully loaded and converted level data\n");
	}
	else
	{
		//printf("Error opening file!\n");
	}
}

/*
// This function is used to save the data of the respective level like number of stars, coins, time taken etc to a text file
// levelNum - An integar value representing the number of the level we are saving
// numStars - An integar value representing the number of stars we are saving
// score - An integar value representing the total score we are saving
// timeTaken - An integar value representing the time taken to complete the level in seconds we are saving
// numCoins - An integar value representing the number of coins we are saving
*/
int SaveData(int levelNum, int numStars, int score, int timeTaken, int numCoins)
{
	FILE* file;
	errno_t error = 0;
	char filePath[FPMAXSIZE] = { "Assets/SavedData/data.txt" };
	error = fopen_s(&file, filePath, "r"); // r for read mode
	if (error == 0)
	{
		char c;
		int counter = 0;
		char level[] = "\nlevel";
		saveDataIndex = 0;
		// Read the contents of the text file and assign the characters to the char array
		while ((c = fgetc(file)) != EOF)
		{
			if (c == '\n')
				counter++;

			if (counter < levelNum - 1 || counter >= levelNum + 1) // Havent reach the line yet
			{
				saveData[saveDataIndex] = c;
				saveDataIndex++;
			}
			// Reached the line that is going to be changed
			else if (counter == levelNum - 1)
			{
				// We want to change the data for the first level
				if (counter == 0)
				{
					// Find out the number of digits for each int variable
					// Using the num of digits, assign the chars to temp[]
					for (int i = 1; i < (int)sizeof(level) - 1; ++i)
					{
						saveData[saveDataIndex] = level[i];
						saveDataIndex++;
					}

					ConvertIntToChar(GetNumDigits(levelNum), levelNum);
					saveData[saveDataIndex] = '-'; saveDataIndex++;
					ConvertIntToChar(GetNumDigits(numStars), numStars);
					saveData[saveDataIndex] = ','; saveDataIndex++;
					ConvertIntToChar(GetNumDigits(score), score);
					saveData[saveDataIndex] = ','; saveDataIndex++;
					ConvertIntToChar(GetNumDigits(timeTaken), timeTaken);
					saveData[saveDataIndex] = ','; saveDataIndex++;
					ConvertIntToChar(GetNumDigits(numCoins), numCoins);
					counter++;
				}
				else // Other levels
				{
					for (int i = 0; i < (int)sizeof(level) - 1; ++i)
					{
						saveData[saveDataIndex] = level[i];
						saveDataIndex++;
					}

					ConvertIntToChar(GetNumDigits(levelNum), levelNum);
					saveData[saveDataIndex] = '-'; saveDataIndex++;
					ConvertIntToChar(GetNumDigits(numStars), numStars);
					saveData[saveDataIndex] = ','; saveDataIndex++;
					ConvertIntToChar(GetNumDigits(score), score);
					saveData[saveDataIndex] = ','; saveDataIndex++;
					ConvertIntToChar(GetNumDigits(timeTaken), timeTaken);
					saveData[saveDataIndex] = ','; saveDataIndex++;
					ConvertIntToChar(GetNumDigits(numCoins), numCoins);
					counter++;
				}
			}
		}

		fclose(file);
		//printf("Successfully read data from text file\n");
	}
	else
	{
		//printf("Error opening file to read data!\n");
		return 0;
	}

	error = fopen_s(&file, filePath, "w"); // w for write mode
	if (error == 0)
	{
		fputs(saveData, file);
		fclose(file);
		//printf("Successfully saved data to text file\n");
		return 1;
	}
	else
	{
		//printf("Error opening file to write data!\n");
		return 0;
	}
}

/*
// This function is used to set the remaining values of the char arrays to be NULL
// input - A char array representing the char array we want to ammend the values of
*/
void SetRemainingArrayNULL(char input[])
{
	for (int i = 0; i < (int)sizeof(input); ++i)
	{
		if (input[i] < '0' || input[i] > '9')
			input[i] = '\0';
	}
}

/*
// This function is used to get the number of digits of an integar number
// input - An integar value representing the number we want to count the number of digits for
*/
int GetNumDigits(int input)
{
	int numDigits = 1;
	while (input > 0)
	{
		input /= 10;
		if (input >= 1)
			numDigits += 1;
	}
	return numDigits;
}

/*
// This function is used to convert an integar number to a char and add it into a char array
// numDigits - An integar value representing the number of digits of the integar number
// input     - An integar value representing the integar number we want to convert
*/
void ConvertIntToChar(int numDigits, int input)
{
	for (int i = 0; i < numDigits; ++i)
	{
		if (i == numDigits - 1) // Last digit of the number
			saveData[saveDataIndex] = (char)(input % 10 + '0');
		else
		{
			int multiplier = 1;
			for (int k = 1; k < numDigits - i; ++k)
			{
				multiplier *= 10;
			}
			saveData[saveDataIndex] = (char)(input / multiplier + '0');
			input -= (int)(saveData[saveDataIndex] - '0') * multiplier;
		}
		saveDataIndex++;
	}
}

void FileLoaderTesting(void)
{
	// The below code is to demonstrate how to use the functions in FileLoader.c

	// Getting current data from the text file
	LoadData(1);
	for (int i = 0; i < 4; ++i)
	{
		//printf("%d\n", currentLevelDataValues[i]);
	}

	// Saving data to the text file before getting it again to printf
	SaveData(5, 3, 12442, 41, 34112);
	LoadData(5);
	for (int i = 0; i < 4; ++i)
	{
		//printf("%d\n", currentLevelDataValues[i]);
	}

	// Loading the level design from a text file for level 31
	if (LoadFile(31) == 1)
	{
		//printf("loading level successful!\n");
		// Testing to print
		for (int i = 0; i < (int)sizeof(loadedLevel); ++i)
		{
			//printf("%c", loadedLevel[i]);
		}
		//printf("\n");
	}
}