//Fight the Knight, a text only, turn-based battle game with a custom soundtrack, and progress saving.
//Created by Tyler Widener, tylerwidenerlm@gmail.com																*Comments Here*
#include <iostream>																									//Includes the iostream library, which allows for input and output to the screen.
#include <string>																									//Includes the string library, which allows for the use of strings.
#include <fstream>																									//Includes the fstream library, which allows for input and output to files.
#include "Character.h"																								//Includes the Character class header file.
#include "Knight.h"																									//Includes the Knight class header file.
#include "Archer.h"																									//Includes the Archer class header file.
#include "Wizard.h"																									//Includes the Wizard class header file.
#include <string.h>																									//Includes the string.h file, which allows for further use of strings.
#ifdef _WIN32																										//The next few lines include a library for the sleep function, which allows for the program to be delayed.
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <thread>																									//Includes the thread library, which allows for the use of multithreading.
#pragma comment(lib, "Winmm.lib")																					//A line of code which allows for the use of playing sound.
using namespace std;																								//Prevents the programmer having to type std:: in front of each input and output statement.
string playerName;																									//A string to hold the player's name.
int XP;																												//An integer to hold the player's experience points.
int battlesWon;																										//An integer to hold the number of battles the player has won.
int battlesLost;																									//An integer to hold the number of battles the player has lost.
int battlesPlayed;																									//An integer to hold the number of battles the player has played.
ifstream inFile("Save File.txt");																					//Defines a file for the program to read, "Save File.txt".
string fileTest;																									//A string to see if the file contains data.
ofstream outFile;																									//Defines an object for a file to write to.
string answer;																										//A string to hold user answers.
char charClass;																										//A char to hold which class the character is playing as.
char enemyClass;																									//A char to hold which class the AI is playing as.
Knight playerKnight;																								//An object of class Knight for the player's Knight character.
Archer playerArcher;																								//An object of class Archer for the player's Archer character.
Wizard playerWizard;																								//An object of class Wizard for the player's Wizard character.
Knight enemyKnight;																									//An object of class Knight for the enemy's Knight character.
Archer enemyArcher;																									//An object of class Archer for the enemy's Archer character.
Wizard enemyWizard;																									//An object of class Wizard for the enemy's Wizard character.
bool saving = false;																								//A bool to keep track of when the player is saving their game.
bool firstMenu = true;																								//A bool to keep track of the first time the player enters the main menu.
int enemyLVL = 1;																									//An integer to keep track of the enemy player's level.
thread mainSong;																									//A thread object for playing the main theme song.
thread stopMainSong;																								//A thread object for stopping the main theme song.
thread battleSong;																									//A thread object for playing the battle song.
thread stopBattleSong;																								//A thread object for stopping the battle song.
const wchar_t* path = L"The Eternal Voyage - Main Theme.WAV";														//A constant for holding the filename of the main theme song.
const wchar_t* path2 = L"The Eternal Voyage - Battle Mor.WAV";														//A constant for holding the filename of the battle song.
void playMainSong() {																								//Plays the main theme song in a loop.
	PlaySound(path, NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
}
void stop_MainSong() {																								//Stops the main song from playing.
	PlaySound(NULL, NULL, 0);
}
void playBattleSong() {																								//Plays the battle song in a loop.
	PlaySound(path2, NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
void stop_BattleSong() {																							//Stops the battle song from playing.
	PlaySound(NULL, NULL, 0);
}
void clearScreen() {																								//Print 50 empty lines so that the screen clears.
	for (int i = 0; i <= 50; i++) {
		cout << endl;
	}
}
void buildNewCharacter() {																							//Function for building a new character for the player.
	clearScreen();																									
	cout << "Select a class for your character:" << endl;															//Outputs "Select a class for your character:"
	cout << "Knight | Archer | Wizard" << endl;																		//Outputs "Knight | Archer | Wizard"
	cin >> answer;																									//Allows the user to enter their answer.
	try																												//Sets up a try/catch block in case of errors.
	{
		if (answer == "Knight") {																					//If the player wants to play as a knight, throw error 1.
			throw 1;
		}
		if (answer == "Archer") {																					//If the player wants to play as an archer, throw error 2.
			throw 2;
		}
		if (answer == "Wizard") {																					//If the player wants to play as a wizard, throw error 3.
			throw 3;
		}
		else if ((answer != "Knight") && (answer != "Archer") && (answer != "Wizard")) {							//If answer is not any of the above, throw error 4.
			throw 4;
		}
	}
	catch (int i)																									//Catch block for catching errors, which are stored in integer i.
	{
		if (i == 1) {																								//If i == 1, meaning the player wants to play as a knight, ask if they are sure.
			cout << "Are you sure you want to play as a knight? (Yes, No)" << endl;
			cin >> answer;
			try
			{
				if (answer == "Yes") {																				//If the answer is yes, set the player's character class to a knight.
					cout << "Okay, Knight " << playerName << ", you are almost ready to go!" << endl;
					charClass = 'k';
				}
				if (answer == "No") {																				//If the answer is no, recall buildNewCharacter.
					buildNewCharacter();
				}
				else if (answer != "Yes" && answer != "No") {
					throw 1;
				}
			}
			catch (int j)																							//If the answer is not yes or no, recall buildNewCharacter and throw an error.
			{
				cout << "ERROR: Invalid answer." << endl;
				buildNewCharacter();
			}
		}
		if (i == 2) {																								//If i == 2, meaning the player wants to play as an archer, ask if they are sure.
			cout << "Are you sure you want to play as an archer? (Yes, No)" << endl;
			cin >> answer;
			try
			{
				if (answer == "Yes") {																				//If the answer is yes, set the player's character class to an archer.
					cout << "Okay, Archer " << playerName << ", you are almost ready to go!" << endl;
					charClass = 'a';
				}
				if (answer == "No") {																				//If the answer is no, recall buildNewCharacter.
					buildNewCharacter();
				}
				else if (answer != "Yes" && answer != "No") {
					throw 1;
				}
			}
			catch (int j)																							//If the answer is not yes or no, recall buildNewCharacter.
			{
				cout << "ERROR: Invalid answer." << endl;
				buildNewCharacter();
			}
		}
		if (i == 3) {																								//If i == 3, meaning the player wants to play as a wizard, ask if they are sure.
			cout << "Are you sure you want to play as a wizard? (Yes, No)" << endl;
			cin >> answer;
			try
			{
				if (answer == "Yes") {																				//If the answer is yes, set the player's character class to a wizard.
					cout << "Okay, Wizard " << playerName << ", you are almost ready to go!" << endl;
					charClass = 'w';
				}
				if (answer == "No") {																				//If the answer is no, recall buildNewCharacter.
					buildNewCharacter();
				}
				else if (answer != "Yes" && answer != "No") {
					throw 1;
				}
			}
			catch (int j)																							//If the answer is not yes or no, recall buildNewCharacter.
			{
				cout << "ERROR: Invalid answer." << endl;
				buildNewCharacter();
			}
		}
		else if (i == 4) {																							//If the player does not answer Knight, Archer, or Wizard, throw an error and recall buildNewCharacter.
			cout << "ERROR: Invalid answer." << endl;
			buildNewCharacter();
		}
	}
	Sleep(1000);																									//Pause the program for 1 second.
	cout << "Creating character stats..." << endl;																	//Outputs "Creating character stats..."
	Sleep(2000);																									//Pause the program for 2 seconds.
	try																												//Throw an error depending on which class the player's character was set to.
	{
		if (charClass == 'k') {
			throw 1;
		}
		if (charClass == 'a') {
			throw 2;
		}
		if (charClass == 'w') {
			throw 3;
		}
		else if (charClass != 'k' && charClass != 'a' && charClass != 'w') {
			throw 4;
		}
	}
	catch (int i)																									//Catch code block for catching errors.
	{
		if (i == 1) {																								//If i == 1, meaning the player is a knight, create stats for a knight, some of which are random.
			playerKnight.str = ((playerKnight.rollD6() + playerKnight.rollD6() + playerKnight.rollD6() + playerKnight.rollD6()) - 10) / 2;
			playerKnight.dex = ((playerKnight.rollD6() + playerKnight.rollD6() + playerKnight.rollD6() + playerKnight.rollD6()) - 10) / 2;
			playerKnight.con = ((playerKnight.rollD6() + playerKnight.rollD6() + playerKnight.rollD6() + playerKnight.rollD6()) - 10) / 2;
			playerKnight.inT = ((playerKnight.rollD6() + playerKnight.rollD6() + playerKnight.rollD6() + playerKnight.rollD6()) - 10) / 2;
			playerKnight.wis = ((playerKnight.rollD6() + playerKnight.rollD6() + playerKnight.rollD6() + playerKnight.rollD6()) - 10) / 2;
			playerKnight.cha = ((playerKnight.rollD6() + playerKnight.rollD6() + playerKnight.rollD6() + playerKnight.rollD6()) - 10) / 2;
			playerKnight.lvl = 1;
			playerKnight.name = playerName;
			playerKnight.maxHP = (playerKnight.con + 8) * playerKnight.lvl;
			playerKnight.hp = playerKnight.maxHP;
			playerKnight.AC = 11 + playerKnight.dex + 3;
			playerKnight.modAC = playerKnight.AC;
		}
		if (i == 2) {																								//If i == 2, meaning the player is an archer, create stats for an archer, some of which are random.
			playerArcher.str = ((playerArcher.rollD6() + playerArcher.rollD6() + playerArcher.rollD6() + playerArcher.rollD6()) - 10) / 2;
			playerArcher.dex = ((playerArcher.rollD6() + playerArcher.rollD6() + playerArcher.rollD6() + playerArcher.rollD6()) - 10) / 2;
			playerArcher.con = ((playerArcher.rollD6() + playerArcher.rollD6() + playerArcher.rollD6() + playerArcher.rollD6()) - 10) / 2;
			playerArcher.inT = ((playerArcher.rollD6() + playerArcher.rollD6() + playerArcher.rollD6() + playerArcher.rollD6()) - 10) / 2;
			playerArcher.wis = ((playerArcher.rollD6() + playerArcher.rollD6() + playerArcher.rollD6() + playerArcher.rollD6()) - 10) / 2;
			playerArcher.cha = ((playerArcher.rollD6() + playerArcher.rollD6() + playerArcher.rollD6() + playerArcher.rollD6()) - 10) / 2;
			playerArcher.lvl = 1;
			playerArcher.name = playerName;
			playerArcher.maxHP = (playerArcher.con + 8) * playerArcher.lvl;
			playerArcher.hp = playerArcher.maxHP;
			playerArcher.AC = 11 + playerArcher.dex;
			playerArcher.modAC = playerArcher.AC;
		}
		if (i == 3) {																								//If i == 3, meaning the player is a wizard, create stats for a wizard, some of which are random.
			playerWizard.str = ((playerWizard.rollD6() + playerWizard.rollD6() + playerWizard.rollD6() + playerWizard.rollD6()) - 10) / 2;
			playerWizard.dex = ((playerWizard.rollD6() + playerWizard.rollD6() + playerWizard.rollD6() + playerWizard.rollD6()) - 10) / 2;
			playerWizard.con = ((playerWizard.rollD6() + playerWizard.rollD6() + playerWizard.rollD6() + playerWizard.rollD6()) - 10) / 2;
			playerWizard.inT = ((playerWizard.rollD6() + playerWizard.rollD6() + playerWizard.rollD6() + playerWizard.rollD6()) - 10) / 2;
			playerWizard.wis = ((playerWizard.rollD6() + playerWizard.rollD6() + playerWizard.rollD6() + playerWizard.rollD6()) - 10) / 2;
			playerWizard.cha = ((playerWizard.rollD6() + playerWizard.rollD6() + playerWizard.rollD6() + playerWizard.rollD6()) - 10) / 2;
			playerWizard.lvl = 1;
			playerWizard.name = playerName;
			playerWizard.maxHP = (playerWizard.con + 8) * playerWizard.lvl;
			playerWizard.hp = playerWizard.maxHP;
			playerWizard.AC = 11 + playerWizard.dex - 1;
			playerWizard.modAC = playerWizard.AC;
		}
		else if (i == 4) {																							//If the player is not any of the above classes, throw an error and crash the program.
			cout << "ERROR: Invalid class! Program crashing..." << endl;
			abort();
		}
	}
	cout << "Alright " << playerName << ", you're all set to play!" << endl;
	Sleep(3000);																									//Pause the program for 3 seconds.
}
void welcome() {																									//Welcome function for when the player first starts the game.
	cout << endl;																									
	cout << "Please enter your name." << endl;																		//Ask the player their name and let them enter it.
	cin >> playerName;
	cout << "Do you want to go by " << playerName << "? (Yes, No)" << endl;											//Ask if they are sure of their name.
	cin >> answer;
	try																												//Try/catch statement in case of errors.
	{
		if (answer == "Yes") {																						//If answer is yes, start building a character for the player.
			cout << "Alright, thanks for playing " << playerName << "!" << endl;
			cout << "Next, you'll need to create a character." << endl;
			buildNewCharacter();
		}
		if (answer == "No") {																						//If the answer is no, recall the welcome function.
			welcome();
		}
		else if (answer != "Yes" && answer != "No") {
			throw 1;
		}
	}
	catch (int i)																									//If the answer is not yes or no, throw an error and recall the welcome function.
	{
		cout << "ERROR: Invalid answer." << endl;
		welcome();
	}
}
void mainMenu() {																									//Recursive function for the main menu.
	clearScreen();
	cout << "MAIN MENU" << endl;																					//Output options for the main menu and allow player to select an option.
	cout << "What would you like to do?" << endl;
	cout << "Save and Exit | Play | Build New Character | View Stats | Level Up Character | Reset Save" << endl;
	getline(cin, answer);
	try																												//Try/catch block in case of errors.
	{
		if (answer == "Save and Exit") {																			//If the player wants to save and exit...
			cout << endl;
			cout << endl;
			std::cout << "Saving progress..." << endl;
			Sleep(2000);																							//Pause the program for 2 seconds.
			outFile.open("Save File.txt");																			//Open the file to output save data to.
			outFile.clear();																						//Clear the save file just in case any data is there that shouldn't be.
			outFile << "0" << endl;																					//Next few lines save player data to file.
			outFile << playerName << endl;
			outFile << XP << endl;
			outFile << battlesPlayed << endl;
			outFile << battlesWon << endl;
			outFile << battlesLost << endl;
			outFile << charClass << endl;
			try																										//Throw an error depending on which class the player is.
			{
				if (charClass == 'k') {
					throw 1;
				}
				if (charClass == 'a') {
					throw 2;
				}
				if (charClass == 'w') {
					throw 3;
				}
				else if (charClass != 'k' && charClass != 'a' && charClass != 'w') {
					throw 4;
				}
			}
			catch (int i)																							//Catch block for catching errors.
			{
				if (i == 1) {																						//If i == 1, meaning the player is a knight, save the player's knight stats.
					outFile << playerKnight.lvl << endl;
					outFile << playerKnight.maxHP << endl;
					outFile << playerKnight.AC << endl;
					outFile << playerKnight.str << endl;
					outFile << playerKnight.dex << endl;
					outFile << playerKnight.con << endl;
					outFile << playerKnight.inT << endl;
					outFile << playerKnight.wis << endl;
					outFile << playerKnight.cha << endl;
				}
				if (i == 2) {																						//If i == 2, meaning the player is an archer, save the player's archer stats.
					outFile << playerArcher.lvl << endl;
					outFile << playerArcher.maxHP << endl;
					outFile << playerArcher.AC << endl;
					outFile << playerArcher.str << endl;
					outFile << playerArcher.dex << endl;
					outFile << playerArcher.con << endl;
					outFile << playerArcher.inT << endl;
					outFile << playerArcher.wis << endl;
					outFile << playerArcher.cha << endl;
				}
				if (i == 3) {																						//If i == 3, meaning the player is a wizard, save the player's wizard stats.
					outFile << playerWizard.lvl << endl;
					outFile << playerWizard.maxHP << endl;
					outFile << playerWizard.AC << endl;
					outFile << playerWizard.str << endl;
					outFile << playerWizard.dex << endl;
					outFile << playerWizard.con << endl;
					outFile << playerWizard.inT << endl;
					outFile << playerWizard.wis << endl;
					outFile << playerWizard.cha << endl;
				}
				else if (i == 4) {																					//If the player is not any of the above classes, throw an error, close the save file and restart the main menu.
					cout << "ERROR: Invalid class!" << endl;
					outFile.close();
					mainMenu();
				}
			}
			outFile.close();																						//Close the save file.
			cout << "Save complete!" << endl;
			Sleep(1000);																							//Pause the program for 1 second.
			cout << "Play again soon!" << endl;
			Sleep(1500);																							//Pause the program for 1.5 seconds.
			exit(0);																								//Stop the program.
			return;
		}
		else if (answer == "Play") {																				//If the player wants to play...
			cout << endl;																							//Next few lines setup creating the enemy character.
			cout << "Preparing to battle..." << endl;
			Sleep(2000);
			clearScreen();
			cout << "First, please select your opponent:" << endl;
			cout << "Knight | Archer | Wizard" << endl;
			cin >> answer;
			cout << "Creating character stats..." << endl;
			Sleep(2000);
			try																										//Throw an error depending on which class the player wants the enemy to be.
			{
				if (answer == "Knight") {
					throw 1;
				}
				if (answer == "Archer") {
					throw 2;
				}
				if (answer == "Wizard") {
					throw 3;
				}
				else if ((answer != "Knight") && (answer != "Archer") && (answer != "Wizard")) {
					throw 4;
				}
			}
			catch (int i)																							//Catch code block for catching errors.
			{
				if (i == 1) {																						//If i == 1, meaning the player wants to fight a knight, ask if they are sure.
					cout << "Are you sure you want to fight a knight? (Yes, No)" << endl;
					cin >> answer;
					try
					{
						if (answer == "Yes") {																		//If the player says yes, set the enemy's class to a knight.
							enemyClass = 'k';
						}
						if (answer == "No") {																		//If the player says no, restart the main menu.
							mainMenu();
						}
						else if (answer != "Yes" && answer != "No") {
							throw 1;
						}
					}
					catch (int j)																					//If the answer is not yes or no, throw an error and restart the main menu.
					{
						cout << "ERROR: Invalid answer." << endl;
						mainMenu();
					}
				}
				if (i == 2) {																						//If i == 2, meaning the player wants to fight an archer, ask if they are sure.
					cout << "Are you sure you want to fight an archer? (Yes, No)" << endl;
					cin >> answer;
					try
					{
						if (answer == "Yes") {																		//If the answer is yes, set the enemy's class to an archer.
							enemyClass = 'a';
						}
						if (answer == "No") {																		//If the answer is no, restart the main menu.
							mainMenu();
						}
						else if (answer != "Yes" && answer != "No") {
							throw 1;
						}
					}
					catch (int j)																					//If the answer is not yes or no, throw an error and restart the main menu.
					{
						cout << "ERROR: Invalid answer." << endl;
						mainMenu();
					}
				}
				if (i == 3) {																						//If i == 3, meaning the player wants to fight a wizard, ask if they are sure.
					cout << "Are you sure you want to fight a wizard? (Yes, No)" << endl;
					cin >> answer;
					try
					{
						if (answer == "Yes") {																		//If the answer is yes, set the enemy's class to a wizard.
							enemyClass = 'w';
						}
						if (answer == "No") {																		//If the answer is no, restart the main menu.
							mainMenu();
						}
						else if (answer != "Yes" && answer != "No") {
							throw 1;
						}
					}
					catch (int j)																					//If the answer is not yes or no, throw an error and restart the main menu.
					{
						cout << "ERROR: Invalid answer." << endl;
						mainMenu();
					}
				}
				else if (i == 4) {																					//If the answer is not knight, archer, or wizard, throw an error and restart the main menu.
					cout << "ERROR: Invalid answer." << endl;
					mainMenu();
				}
			}
			try																										//Ask the user what level of enemy they want to fight.
			{
				cout << endl;
				cout << "What level would you like the enemy to be?" << endl;
				cin >> answer;
				if (!isdigit(answer[0])) {																			//If the user did not enter a number, throw error 1.
					throw 1;
				}
				enemyLVL = stoi(answer);
				Sleep(2000);
			}
			catch (int i)																							//If the user did not enter a number above, throw an error and restart the main menu.
			{
				if (i == 1) {
					cout << "ERROR: Invalid answer" << endl;
					mainMenu();
				}
			}
			try																										//Throw an error depending on which class the enemy is.
			{
				if (enemyClass == 'k') {
					throw 1;
				}
				if (enemyClass == 'a') {
					throw 2;
				}
				if (enemyClass == 'w') {
					throw 3;
				}
				else if (enemyClass != 'k' && enemyClass != 'a' && enemyClass != 'w') {
					throw 4;
				}
			}
			catch (int i)																							//Catch code block for catching errors.
			{
				if (i == 1) {																						//If the enemy is a knight, create stats for an enemy knight.
					enemyKnight.str = ((enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6()) - 10) / 2;
					enemyKnight.dex = ((enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6()) - 10) / 2;
					enemyKnight.con = ((enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6()) - 10) / 2;
					enemyKnight.inT = ((enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6()) - 10) / 2;
					enemyKnight.wis = ((enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6()) - 10) / 2;
					enemyKnight.cha = ((enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6()) - 10) / 2;
					enemyKnight.lvl = enemyLVL;
					for (int i = 0; i <= enemyLVL; i++) {															//Increase a random stat for a number of times equal to the enemy's level.
						int roll = rand() % 6 + 1;
						if (roll == 1) {
							enemyKnight.str++;
						}
						else if (roll == 2) {
							enemyKnight.dex++;
						}
						else if (roll == 3) {
							enemyKnight.con++;
						}
						else if (roll == 4) {
							enemyKnight.inT++;
						}
						else if (roll == 5) {
							enemyKnight.wis++;
						}
						else if (roll == 6) {
							enemyKnight.cha++;
						}
						else if (roll != 1 && roll != 2 && roll != 3 && roll != 4 && roll != 5 && roll != 6) {		//If the roll wasn't 1-6, throw an error and restart the main menu.
							cout << "ERROR: Invalid roll" << endl;
							mainMenu();
						}
					}
					enemyKnight.name = "Enemy";//FIX ME
					enemyKnight.maxHP = (enemyKnight.con + 8) * enemyKnight.lvl;
					enemyKnight.hp = enemyKnight.maxHP;
					enemyKnight.AC = 11 + enemyKnight.dex + 3;
					enemyKnight.modAC = enemyKnight.AC;
				}
				if (i == 2) {																						//If the enemy is an archer, create stats for an enemy archer.
					enemyArcher.str = ((enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6()) - 10) / 2;
					enemyArcher.dex = ((enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6()) - 10) / 2;
					enemyArcher.con = ((enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6()) - 10) / 2;
					enemyArcher.inT = ((enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6()) - 10) / 2;
					enemyArcher.wis = ((enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6()) - 10) / 2;
					enemyArcher.cha = ((enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6()) - 10) / 2;
					enemyArcher.lvl = enemyLVL;
					for (int i = 0; i <= enemyLVL; i++) {															//Increase a random stat for a number of times equal to the enemies level.
						int roll = rand() % 6 + 1;
						if (roll == 1) {
							enemyArcher.str++;
						}
						else if (roll == 2) {
							enemyArcher.dex++;
						}
						else if (roll == 3) {
							enemyArcher.con++;
						}
						else if (roll == 4) {
							enemyArcher.inT++;
						}
						else if (roll == 5) {
							enemyArcher.wis++;
						}
						else if (roll == 6) {
							enemyArcher.cha++;
						}
						else if (roll != 1 && roll != 2 && roll != 3 && roll != 4 && roll != 5 && roll != 6) {		//If the roll wasn't 1-6, throw an error and restart the main menu.
							cout << "ERROR: Invalid roll" << endl;
							mainMenu();
						}
					}
					enemyArcher.name = "Enemy";//FIX ME
					enemyArcher.maxHP = (enemyArcher.con + 8) * enemyArcher.lvl;
					enemyArcher.hp = enemyArcher.maxHP;
					enemyArcher.AC = 11 + enemyArcher.dex;
					enemyArcher.modAC = enemyArcher.AC;
				}
				if (i == 3) {																						//If the enemy is a wizard, create stats for an enemy wizard.
					enemyWizard.str = ((enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6()) - 10) / 2;
					enemyWizard.dex = ((enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6()) - 10) / 2;
					enemyWizard.con = ((enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6()) - 10) / 2;
					enemyWizard.inT = ((enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6()) - 10) / 2;
					enemyWizard.wis = ((enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6()) - 10) / 2;
					enemyWizard.cha = ((enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6()) - 10) / 2;
					enemyWizard.lvl = enemyLVL;
					for (int i = 0; i <= enemyLVL; i++) {															//Increase a random stat for a number of times equal to the enemy's level.
						int roll = rand() % 6 + 1;
						if (roll == 1) {
							enemyWizard.str++;
						}
						else if (roll == 2) {
							enemyWizard.dex++;
						}
						else if (roll == 3) {
							enemyWizard.con++;
						}
						else if (roll == 4) {
							enemyWizard.inT++;
						}
						else if (roll == 5) {
							enemyWizard.wis++;
						}
						else if (roll == 6) {
							enemyWizard.cha++;
						}
						else if (roll != 1 && roll != 2 && roll != 3 && roll != 4 && roll != 5 && roll != 6) {		//If the roll wasn't 1-6, throw an error and restart the main menu.
							cout << "ERROR: Invalid roll" << endl;
							mainMenu();
						}
					}
					enemyWizard.name = "Enemy";//FIX ME
					enemyWizard.maxHP = (enemyWizard.con + 8) * enemyWizard.lvl;
					enemyWizard.hp = enemyWizard.maxHP;
					enemyWizard.AC = 11 + enemyWizard.dex - 2;
					enemyWizard.modAC = enemyWizard.AC;
				}
				else if (i == 4) {																					//If the character isn't any of the above classes, throw an error and crash the program.
					cout << "ERROR: Invalid class! Program crashing..." << endl;
					abort();
				}
			}
			Sleep(1500);
			cout << "Your opponent is ready!" << endl;
			Sleep(1500);
			cout << "Let the battle begin!" << endl;
			Sleep(1500);
			cout << "Press Enter to start." << endl;
			cin.ignore();
			return;																									//Return to the main function, which will start a battle.
		}
		else if (answer == "Build New Character") {																	//If the player wants to build a new character, ask if they are sure.
		cout << endl;
			cout << "Creating a new character will erase your old character, are you sure?" << endl;
			cin >> answer;
			try
			{
				if (answer == "Yes") {																				//If the answer is yes, call the buildNewCharacter function.
					cout << "Building new character..." << endl;
					buildNewCharacter();
				}
				if (answer == "No") {																				//If the answer is no, restart the main menu.
					mainMenu();
				}
				else if (answer != "Yes" && answer != "No") {
					throw 1;
				}
			}
			catch (int i)																							//If the answer is not yes or no, restart the main menu and throw an error.
			{
				cout << "ERROR: Invalid answer." << endl;
				mainMenu();
			}
			mainMenu();																								//After the buildNewCharacter function finishes, restart the main menu.
		}
		else if (answer == "View Stats") {																			//If the player wants to view their current stats, display them on screen.
		clearScreen();
			cout << "Here are your current stats for Fight the Knight:" << endl;
			cout << "Player's Name: " << playerName << endl;
			cout << "Experience: " << XP << endl;
			cout << "Battles Played: " << battlesPlayed << endl;
			cout << "Battles Won: " << battlesWon << endl;
			cout << "Battles Lost: " << battlesLost << endl;
			cout << endl;
			cout << "Character stats:" << endl;
			try																										//Throw an error depending on which class the player's character is.
			{
				if (charClass == 'k') {
					throw 1;
				}
				if (charClass == 'a') {
					throw 2;
				}
				if (charClass == 'w') {
					throw 3;
				}
				else if (charClass != 'k' && charClass != 'a' && charClass != 'w') {
					throw 4;
				}
			}
			catch (int i)																							//Catch block for catching errors.
			{
				if (i == 1) {																						//If i == 1, meaning the player is a knight, display knight stats.
					cout << "Character Class: Knight" << endl;
					cout << "Knight Level: " << playerKnight.lvl << endl;
					cout << "Knight HP: " << playerKnight.maxHP << endl;
					cout << "Knight AC: " << playerKnight.AC << endl;
					cout << "Knight Strength: " << playerKnight.str << endl;
					cout << "Knight Dexterity: " << playerKnight.dex << endl;
					cout << "Knight Constitution: " << playerKnight.con << endl;
					cout << "Knight Intelligence: " << playerKnight.inT << endl;
					cout << "Knight Wisdom: " << playerKnight.wis << endl;
					cout << "Knight Charisma: " << playerKnight.cha << endl;
				}
				if (i == 2) {																						//If i == 2, meaning the player is an archer, display archer stats.
					cout << "Character Class: Archer" << endl;
					cout << "Archer Level: " << playerArcher.lvl << endl;
					cout << "Archer HP: " << playerArcher.maxHP << endl;
					cout << "Archer AC: " << playerArcher.AC << endl;
					cout << "Archer Strength: " << playerArcher.str << endl;
					cout << "Archer Dexterity: " << playerArcher.dex << endl;
					cout << "Archer Constitution: " << playerArcher.con << endl;
					cout << "Archer Intelligence: " << playerArcher.inT << endl;
					cout << "Archer Wisdom: " << playerArcher.wis << endl;
					cout << "Archer Charisma: " << playerArcher.cha << endl;
				}
				if (i == 3) {																						//If i == 3, meaning the player is a wizard, display wizard stats.
					cout << "Character Class: Wizard" << endl;
					cout << "Wizard Level: " << playerWizard.lvl << endl;
					cout << "Wizard HP: " << playerWizard.maxHP << endl;
					cout << "Wizard AC: " << playerWizard.AC << endl;
					cout << "Wizard Strength: " << playerWizard.str << endl;
					cout << "Wizard Dexterity: " << playerWizard.dex << endl;
					cout << "Wizard Constitution: " << playerWizard.con << endl;
					cout << "Wizard Intelligence: " << playerWizard.inT << endl;
					cout << "Wizard Wisdom: " << playerWizard.wis << endl;
					cout << "Wizard Charisma: " << playerWizard.cha << endl;
				}
				else if (i == 4) {																					//If the player's class is not any of the above, throw an error and restart the main menu.
					cout << "ERROR: Invalid class!" << endl;
					mainMenu();
				}
			}
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "Press Enter to return to the Main Menu." << endl;
			cin.ignore();																							//Wait for the user to press enter before returning to the main menu.
			mainMenu();
		}
		else if (answer == "Level Up Character") {																	//If the player wants to level up their character...															
			clearScreen();
			cout << "Here are the current stats for your character:" << endl;
			try																										//Throw an error depending on which class the player is.
			{
				if (charClass == 'k') {
					throw 1;
				}
				if (charClass == 'a') {
					throw 2;
				}
				if (charClass == 'w') {
					throw 3;
				}
				else if (charClass != 'k' && charClass != 'a' && charClass != 'w') {
					throw 4;
				}
			}
			catch (int i)																							//Catch code block for catching errors.
			{
				if (i == 1) {																						//If i == 1, meaning the player is a knight, display knight stats.
					cout << "Character Class: Knight" << endl;
					cout << "Knight Level: " << playerKnight.lvl << endl;
					cout << "Knight HP: " << playerKnight.maxHP << endl;
					cout << "Knight AC: " << playerKnight.AC << endl;
					cout << "Knight Strength: " << playerKnight.str << endl;
					cout << "Knight Dexterity: " << playerKnight.dex << endl;
					cout << "Knight Constitution: " << playerKnight.con << endl;
					cout << "Knight Intelligence: " << playerKnight.inT << endl;
					cout << "Knight Wisdom: " << playerKnight.wis << endl;
					cout << "Knight Charisma: " << playerKnight.cha << endl;
				}
				if (i == 2) {																						//If i == 2, meaning the player is an archer, display archer stats.
					cout << "Character Class: Archer" << endl;
					cout << "Archer Level: " << playerArcher.lvl << endl;
					cout << "Archer HP: " << playerArcher.maxHP << endl;
					cout << "Archer AC: " << playerArcher.AC << endl;
					cout << "Archer Strength: " << playerArcher.str << endl;
					cout << "Archer Dexterity: " << playerArcher.dex << endl;
					cout << "Archer Constitution: " << playerArcher.con << endl;
					cout << "Archer Intelligence: " << playerArcher.inT << endl;
					cout << "Archer Wisdom: " << playerArcher.wis << endl;
					cout << "Archer Charisma: " << playerArcher.cha << endl;
				}
				if (i == 3) {																						//If i == 3, meaning the player is a wizard.
					cout << "Character Class: Wizard" << endl;
					cout << "Wizard Level: " << playerWizard.lvl << endl;
					cout << "Wizard HP: " << playerWizard.maxHP << endl;
					cout << "Wizard AC: " << playerWizard.AC << endl;
					cout << "Wizard Strength: " << playerWizard.str << endl;
					cout << "Wizard Dexterity: " << playerWizard.dex << endl;
					cout << "Wizard Constitution: " << playerWizard.con << endl;
					cout << "Wizard Intelligence: " << playerWizard.inT << endl;
					cout << "Wizard Wisdom: " << playerWizard.wis << endl;
					cout << "Wizard Charisma: " << playerWizard.cha << endl;
				}
				else if (i == 4) {																					//If the player is not any of the above classes, throw an error and restart the main menu.
					cout << "ERROR: Invalid class!" << endl;
					mainMenu();
				}
			}
			cout << endl;																							//Ask player which stat they want to upgrade, and let them input an answer.
			Sleep(1500);
			cout << "Which stat would you like to upgrade?" << endl;
			cout << "Strength | Dexterity | Constitution | Intelligence | Wisdom | Charisma" << endl;
			cin >> answer;
			try																										//Set up a try/catch code block in case of errors.
			{
				int xpRequired = 0;																					//Local variable to store the XP required for an upgrade.
				if (charClass == 'k') {																				//If the player is a knight, set XP required to 5 times knight level.
					xpRequired = playerKnight.lvl * 5;
				}
				else if (charClass == 'a') {																		//If the player is an archer, set XP required to 5 times archer level.
					xpRequired = playerArcher.lvl * 5;
				}
				else if (charClass == 'w') {																		//If the player is a wizard, set XP required to 5 times wizard level.
					xpRequired = playerWizard.lvl * 5;
				}
				if (XP < xpRequired) {																				//If the player has less XP than is currently required, throw error 2.
					throw 2;
				}
				else if (answer == "Strength") {																	//If the player wants to upgrade strength, ask if they are sure.
					cout << "Are you sure you want to spend " << xpRequired <<  " XP on upgrading strength ? " << endl;
					cin >> answer;
					try
					{
						if (answer == "Yes") {																		//If the answer is yes, throw an error depending on what class the player is.
							cout << "Upgrading..." << endl;
							Sleep(2000);
							try
							{
								if (charClass == 'k') {
									throw 1;
								}
								if (charClass == 'a') {
									throw 2;
								}
								if (charClass == 'w') {
									throw 3;
								}
								else if (charClass != 'k' && charClass != 'a' && charClass != 'w') {
									throw 4;
								}
							}
							catch (int i)																			//Catch code block for catching errors.
							{
								if (i == 1) {																		//If i == 1, meaning the player is a knight, upgrade knight strength by 1, upgrade hp, subtract XP, and restart the main menu.
									playerKnight.str++;
									playerKnight.lvl++;
									playerKnight.maxHP = (playerKnight.con + 8) * playerKnight.lvl;
									XP -= xpRequired;
									cout << "Strength Upgraded to " << playerKnight.str << endl;
									Sleep(2000);
									mainMenu();
								}
								if (i == 2) {																		//If i == 2, meaning the player is an archer, upgrade archer strength by 1, upgrade hp, subtract XP, and restart the main menu.
									playerArcher.str++;
									playerArcher.lvl++;
									playerArcher.maxHP = (playerArcher.con + 8) * playerArcher.lvl;
									XP -= xpRequired;
									cout << "Strength Upgraded to " << playerArcher.str << endl;
									Sleep(2000);
									mainMenu();
								}
								if (i == 3) {																		//If i == 3, meaning the player is a wizard, upgrade wizard strength by 1, upgrade hp, subtract XP, and restart the main menu.
									playerWizard.str++;
									playerWizard.lvl++;
									playerWizard.maxHP = (playerWizard.con + 8) * playerWizard.lvl;
									XP -= xpRequired;
									cout << "Strength Upgraded to " << playerWizard.str << endl;
									Sleep(2000);
									mainMenu();
								}
								else if (i == 4) {																	//If the player's class isn't any of the above, throw an error and restart the main menu.
									cout << "ERROR: Invalid class!" << endl;
									mainMenu();
								}
							}
						}
						if (answer == "No") {																		//If the answer was no, restart the main menu.
							mainMenu();
						}
						else if (answer != "Yes" && answer != "No") {												//If the answer was not yes or no, restart the main menu.
							throw 1;
						}
					}
					catch (int i)																					
					{
						cout << "ERROR: Invalid answer." << endl;
						mainMenu();
					}
				}
				else if (answer == "Dexterity") {																	//If the player wants to upgrade dexterity, ask if they are sure.
					cout << "Are you sure you want to spend " << xpRequired << " XP on upgrading dexterity?" << endl;
					cin >> answer;
					try
					{
						if (answer == "Yes") {																		//If the answer is yes, throw an error depending on what class the player is.
							cout << "Upgrading..." << endl;
							Sleep(2000);
							try
							{
								if (charClass == 'k') {
									throw 1;
								}
								if (charClass == 'a') {
									throw 2;
								}
								if (charClass == 'w') {
									throw 3;
								}
								else if (charClass != 'k' && charClass != 'a' && charClass != 'w') {
									throw 4;
								}
							}
							catch (int i)																			//Catch code block for catching errors.
							{
								if (i == 1) {																		//If i == 1, meaning the player is a knight, upgrade dexterity by 1, upgrade hp, subtract XP, and restart the main menu.
									playerKnight.dex++;
									playerKnight.lvl++;
									playerKnight.maxHP = (playerKnight.con + 8) * playerKnight.lvl;
									playerKnight.AC = 11 + playerKnight.dex + 3;
									XP -= xpRequired;
									cout << "Dexterity Upgraded to " << playerKnight.dex << endl;
									Sleep(2000);
									mainMenu();
								}
								if (i == 2) {																		//If i == 2, meaning the player is an archer, upgrade dexterity by 1, upgrade hp, subtract XP, and restart the main menu.
									playerArcher.dex++;
									playerArcher.lvl++;
									playerArcher.maxHP = (playerArcher.con + 8) * playerArcher.lvl;
									playerArcher.AC = 11 + playerArcher.dex + 3;
									XP -= xpRequired;
									cout << "Dexterity Upgraded to " << playerArcher.dex << endl;
									Sleep(2000);
									mainMenu();
								}
								if (i == 3) {																		//If i == 3, meaning the player is a wizard, upgrade dexterity by 1, upgrade hp, subtract XP, and restart the main menu.
									playerWizard.dex++;
									playerWizard.lvl++;
									playerWizard.maxHP = (playerWizard.con + 8) * playerWizard.lvl;
									playerWizard.AC = 11 + playerWizard.dex + 3;
									XP -= xpRequired;
									cout << "Dexterity Upgraded to " << playerWizard.dex << endl;
									Sleep(2000);
									mainMenu();
								}
								else if (i == 4) {																	//If the player is not any of the above classes, throw an error and restart the main menu.
									cout << "ERROR: Invalid class!" << endl;
									mainMenu();
								}
							}
						}
						if (answer == "No") {																		//If the answer was no, restart the main menu.
							mainMenu();
						}
						else if (answer != "Yes" && answer != "No") {												//If the answer was not yes or no, throw an error and restart the main menu.
							throw 1;
						}
					}
					catch (int i)
					{
						cout << "ERROR: Invalid answer." << endl;
						mainMenu();
					}
				}
				else if (answer == "Constitution") {																//If the player wants to upgrade constitution, ask if they are sure.
				cout << "Are you sure you want to spend " << xpRequired << " XP on upgrading constitution?" << endl;
				cin >> answer;
				try
				{
					if (answer == "Yes") {																			//If the answer is yes, throw an error depending on which class the player is.
						cout << "Upgrading..." << endl;
						Sleep(2000);
						try
						{
							if (charClass == 'k') {
								throw 1;
							}
							if (charClass == 'a') {
								throw 2;
							}
							if (charClass == 'w') {
								throw 3;
							}
							else if (charClass != 'k' && charClass != 'a' && charClass != 'w') {
								throw 4;
							}
						}
						catch (int i)
						{
							if (i == 1) {																			//If i == 1, meaning the player is a knight, upgrade constitution by 1, upgrade hp, subtract XP, and restart the main menu.
								playerKnight.con++;
								playerKnight.lvl++;
								playerKnight.maxHP = (playerKnight.con + 8) * playerKnight.lvl;
								XP -= xpRequired;
								cout << "Constitution Upgraded to " << playerKnight.con << endl;
								Sleep(2000);
								mainMenu();
							}
							if (i == 2) {																			//If i == 2, meaning the player is an archer, upgrade constitution by 1, upgrade hp, subtract XP, and restart the main menu.
								playerArcher.con++;
								playerArcher.lvl++;
								playerArcher.maxHP = (playerArcher.con + 8) * playerArcher.lvl;
								XP -= xpRequired;
								cout << "Constitution Upgraded to " << playerArcher.con << endl;
								Sleep(2000);
								mainMenu();
							}
							if (i == 3) {																			//If i == 3, meaning the player is a wizard, upgrade constitution by 1, upgrade hp, subtract XP, and restart the main menu.
								playerWizard.con++;
								playerWizard.lvl++;
								playerWizard.maxHP = (playerWizard.con + 8) * playerWizard.lvl;
								XP -= xpRequired;
								cout << "Constitution Upgraded to " << playerWizard.con << endl;
								Sleep(2000);
								mainMenu();
							}
							else if (i == 4) {																		//If the player is not any of the above classes, throw an error and restart the main menu.
								cout << "ERROR: Invalid class!" << endl;
								mainMenu();
							}
						}
					}
					if (answer == "No") {																			//If the answer was no, restart the main menu.
						mainMenu();
					}
					else if (answer != "Yes" && answer != "No") {													//If the answer was not yes or no, throw an error and restart the main menu.
						throw 1;
					}
				}
				catch (int i)
				{
					cout << "ERROR: Invalid answer." << endl;
					mainMenu();
				}
				}
				else if (answer == "Intelligence") {																//If the player wants to upgrade intelligence, ask if they are sure.
				cout << "Are you sure you want to spend " << xpRequired << " XP on upgrading intelligence?" << endl;
				cin >> answer;
				try
				{
					if (answer == "Yes") {																			//If the answer is yes, throw an error depending on which class the player is.
						cout << "Upgrading..." << endl;
						Sleep(2000);
						try
						{
							if (charClass == 'k') {
								throw 1;
							}
							if (charClass == 'a') {
								throw 2;
							}
							if (charClass == 'w') {
								throw 3;
							}
							else if (charClass != 'k' && charClass != 'a' && charClass != 'w') {
								throw 4;
							}
						}
						catch (int i)
						{
							if (i == 1) {																			//If i == 1, meaning the player is a knight, upgrade intelligence by 1, upgrade hp, subtract XP, and restart the main menu.
								playerKnight.inT++;
								playerKnight.lvl++;
								playerKnight.maxHP = (playerKnight.con + 8) * playerKnight.lvl;
								XP -= xpRequired;
								cout << "Intelligence Upgraded to " << playerKnight.inT << endl;
								Sleep(2000);
								mainMenu();
							}
							if (i == 2) {																			//If i == 2, meaning the player is an archer, upgrade intelligence by 1, upgrade hp, subtract XP, and restart the main menu.
								playerArcher.inT++;
								playerArcher.lvl++;
								playerArcher.maxHP = (playerArcher.con + 8) * playerArcher.lvl;
								XP -= xpRequired;
								cout << "Intelligence Upgraded to " << playerArcher.inT << endl;
								Sleep(2000);
								mainMenu();
							}
							if (i == 3) {																			//If i == 3, meaning the player is a wizard, upgrade intelligence by 1, upgrade hp, subtract XP, and restart the main menu.
								playerWizard.inT++;
								playerWizard.lvl++;
								playerWizard.maxHP = (playerWizard.con + 8) * playerWizard.lvl;
								XP -= xpRequired;
								cout << "Intelligence Upgraded to " << playerWizard.inT << endl;
								Sleep(2000);
								mainMenu();
							}
							else if (i == 4) {																		//If the player is not any of the above classes, throw an error and restart the main menu.
								cout << "ERROR: Invalid class!" << endl;
								mainMenu();
							}
						}
					}
					if (answer == "No") {																			//If the answer was no, restart the main menu.
						mainMenu();
					}
					else if (answer != "Yes" && answer != "No") {													//If the answer was not yes or no, throw an error and restart the main menu.
						throw 1;
					}
				}
				catch (int i)
				{
					cout << "ERROR: Invalid answer." << endl;
					mainMenu();
				}
				}
				else if (answer == "Wisdom") {																		//If the player wants to upgrade wisdom, ask if they are sure.
				cout << "Are you sure you want to spend " << xpRequired << " XP on upgrading wisdom?" << endl;
				cin >> answer;
				try
				{
					if (answer == "Yes") {																			//If the answer is yes, throw an error depending on which class the player is.
						cout << "Upgrading..." << endl;
						Sleep(2000);
						try
						{
							if (charClass == 'k') {
								throw 1;
							}
							if (charClass == 'a') {
								throw 2;
							}
							if (charClass == 'w') {
								throw 3;
							}
							else if (charClass != 'k' && charClass != 'a' && charClass != 'w') {
								throw 4;
							}
						}
						catch (int i)
						{
							if (i == 1) {																			//If i == 1, meaning the player is a knight, upgrade wisdom by 1, upgrade hp, subtract XP, and restart the main menu.
								playerKnight.wis++;
								playerKnight.lvl++;
								playerKnight.maxHP = (playerKnight.con + 8) * playerKnight.lvl;
								XP -= xpRequired;
								cout << "Wisdom Upgraded to " << playerKnight.wis << endl;
								Sleep(2000);
								mainMenu();
							}
							if (i == 2) {																			//If i == 2, meaning the player is an archer, upgrade wisdom by 1, upgrade hp, subtract XP, and restart the main menu.
								playerArcher.wis++;
								playerArcher.lvl++;
								playerArcher.maxHP = (playerArcher.con + 8) * playerArcher.lvl;
								XP -= xpRequired;
								cout << "Wisdom Upgraded to " << playerArcher.wis << endl;
								Sleep(2000);
								mainMenu();
							}
							if (i == 3) {																			//If i == 3, meaning the player is a wizard, upgrade wisdom by 1, upgrade hp, subtract XP, and restart the main menu.
								playerWizard.wis++;
								playerWizard.lvl++;
								playerWizard.maxHP = (playerWizard.con + 8) * playerWizard.lvl;
								XP -= xpRequired;
								cout << "Wisdom Upgraded to " << playerWizard.wis << endl;
								Sleep(2000);
								mainMenu();
							}
							else if (i == 4) {																		//If the player is not any of the above classes, throw an error and restart the main menu.
								cout << "ERROR: Invalid class!" << endl;
								mainMenu();
							}
						}
					}
					if (answer == "No") {																			//If the answer was no, restart the main menu.
						mainMenu();
					}
					else if (answer != "Yes" && answer != "No") {													//If the answer was not yes or no, throw an error and restart the main menu.
						throw 1;
					}
				}
				catch (int i)
				{
					cout << "ERROR: Invalid answer." << endl;
					mainMenu();
				}
				}
				else if (answer == "Charisma") {																	//If the player wants to upgrade charisma, ask if they are sure.
				cout << "Are you sure you want to spend " << xpRequired << " XP on upgrading charisma?" << endl;
				cin >> answer;
				try
				{
					if (answer == "Yes") {																			//If the answer is yes, throw an error depending on which class the player.
						cout << "Upgrading..." << endl;
						Sleep(2000);
						try
						{
							if (charClass == 'k') {
								throw 1;
							}
							if (charClass == 'a') {
								throw 2;
							}
							if (charClass == 'w') {
								throw 3;
							}
							else if (charClass != 'k' && charClass != 'a' && charClass != 'w') {
								throw 4;
							}
						}
						catch (int i)
						{
							if (i == 1) {																			//If i == 1, meaning the player is a knight, upgrade charisma by 1, upgrade hp, subtract XP, and restart the main menu.
								playerKnight.cha++;
								playerKnight.lvl++;
								playerKnight.maxHP = (playerKnight.con + 8) * playerKnight.lvl;
								XP -= xpRequired;
								cout << "Charisma Upgraded to " << playerKnight.cha << endl;
								Sleep(2000);
								mainMenu();
							}
							if (i == 2) {																			//If i == 2, meaning the player is an archer, upgrade charisma by 1, upgrade hp, subtract XP, and restart the main menu.
								playerArcher.cha++;
								playerArcher.lvl++;
								playerArcher.maxHP = (playerArcher.con + 8) * playerArcher.lvl;
								XP -= xpRequired;
								cout << "Charisma Upgraded to " << playerArcher.cha << endl;
								Sleep(2000);
								mainMenu();
							}
							if (i == 3) {																			//If i == 3, meaning the player is a wizard, upgrade charisma by 1, upgrade hp, subtract XP, and restart the main menu.
								playerWizard.cha++;
								playerWizard.lvl++;
								playerWizard.maxHP = (playerWizard.con + 8) * playerWizard.lvl;
								XP -= xpRequired;
								cout << "Charisma Upgraded to " << playerWizard.cha << endl;
								Sleep(2000);
								mainMenu();
							}
							else if (i == 4) {																		//If the player is not any of the above classes, throw an error and restart the main menu.
								cout << "ERROR: Invalid class!" << endl;
								mainMenu();
							}
						}
					}
					if (answer == "No") {																			//If the answer was no, restart the main menu.
						mainMenu();
					}
					else if (answer != "Yes" && answer != "No") {													//If the answer was not yes or no, throw an error and restart the main menu.
						throw 1;
					}
				}
				catch (int i)
				{
					cout << "ERROR: Invalid answer." << endl;
					mainMenu();
				}
				}
				else if (answer != "Strength" && answer != "Dexterity" && answer != "Constitution" && answer != "Intelligence" && answer != "Wisdom" && answer != "Charisma") {//If the answer was not any of the valid stats, throw an error.
					throw 1;
				}
			}
			catch (int i)
			{
				if (i == 1) {																						//If the player's answer was not any of the stats, throw an error and restart the main menu.
					cout << "ERROR: Invalid answer" << endl;
					mainMenu();
				}
				else if (i == 2) {																					//If the player doesn't have enough XP for an upgrade, throw an error and restart the main menu.
					cout << "You don't have enough XP to upgrade your character!" << endl;	
					Sleep(3000);
					mainMenu();
				}
			}
		}
		else if (answer == "Reset Save") {																			//If the player wants to reset their save, ask if they are sure.
		cout << "WARNING: Are you sure you want to reset your save progress? (It will not be recoverable)" << endl;
		cin >> answer;
		try
		{
			if (answer == "Yes") {																					//If the answer is yes, clear the save file and end the program.
				cout << "Resetting..." << endl;
				Sleep(2000);
				outFile.open("Save File.txt");
				outFile.clear();
				cout << "Reset Complete." << endl;
				Sleep(2000);
				exit(0);
			}
			else if (answer == "No") {																				//If the answer is no, restart the main menu.
				mainMenu();
			}
			else if (answer != "Yes" && answer != "No") {															//If the answer was not yes or no, throw an error and restart the main menu.
				throw 1;
			}
		}
		catch (int j)
		{
			if (j == 1) {
				cout << "ERROR: Invalid answer" << endl;
				mainMenu();
			}
		}
		}
		else if (answer == "") {																					//If the player just presses enter (error with cin.ignore() during testing), throw error 1.
			throw 1;
		}
		else if (answer != "Save and Exit" && answer != "Play" && answer != "Build New Character" && answer != "View Stats" && answer != "Level Up Character") {//If the player did not answer any of the main menu options, throw error 5.
			throw 5;
		}
	}
	catch (int i)
	{
		if (i == 5) {																								//If the player did not answer any of the main menu options, throw an error and restart the main menu.
			cout << "ERROR: Invalid answer" << endl;
			mainMenu();
		}
		if (i == 1) {																								//If the player just pressed enter, restart the main menu.
			mainMenu();
		}
	}
}
void checkBattleEnd() {																								//Function for checking to see if battle needs to end, due to one of the characters being out of hp.
	try
	{
		if (charClass == 'k' && enemyClass == 'k') {																//If both characters are knights...
			if (playerKnight.hp <= 0) {																				//If the player is out of hp, end the fight with a loss, stop the battle music, start the main theme song, and restart the main menu.
				cout << playerKnight.name << " fainted from exhaustion!" << endl;
				Sleep(3000);
				cout << playerName << " lost the fight!" << endl;
				battlesPlayed += 1;
				battlesLost += 1;
				playerKnight.hp = playerKnight.maxHP;
				XP++;
				cout << "Press Enter to continue." << endl;
				cin.ignore();
				thread stopBattleSong(stop_BattleSong);
				stopBattleSong.join();
				thread mainSong(playMainSong);
				mainSong.join();
				mainMenu();
			}
			else if (enemyKnight.hp <= 0) {																			//If enemy is out of hp, end the fight with a win, stop the battle music, start the main theme song, restart the main menu.
				cout << enemyKnight.name << " fainted from exhaustion!" << endl;
				Sleep(3000);
				cout << playerName << " won the fight!" << endl;
				battlesPlayed++;
				battlesWon++;
				playerKnight.hp = playerKnight.maxHP;
				XP += enemyLVL;
				cout << "Press Enter to continue." << endl;
				cin.ignore();
				thread stopBattleSong(stop_BattleSong);
				stopBattleSong.join();
				thread mainSong(playMainSong);
				mainSong.join();
				mainMenu();
			}
		}
		else if (charClass == 'k' && enemyClass == 'a') {															//If the player is a knight and the enemy is an archer...
			if (playerKnight.hp <= 0) {																				//If the player is out of hp, end the fight with a loss, stop the battle music, start the main theme song, and restart the main theme.
				cout << playerKnight.name << " fainted from exhaustion!" << endl;
				Sleep(3000);
				cout << playerName << " lost the fight!" << endl;
				battlesPlayed += 1;
				battlesLost += 1;
				playerKnight.hp = playerKnight.maxHP;
				XP++;
				cout << "Press Enter to continue." << endl;
				cin.ignore();
				thread stopBattleSong(stop_BattleSong);
				stopBattleSong.join();
				thread mainSong(playMainSong);
				mainSong.join();
				mainMenu();
			}
			else if (enemyArcher.hp <= 0) {																			//If the enemy is out of hp, end the fight with a win, stop the battle music, start the main theme song, and restart the main menu.
				cout << enemyArcher.name << " fainted from exhaustion!" << endl;
				Sleep(3000);
				cout << playerName << " won the fight!" << endl;
				battlesPlayed++;
				battlesWon++;
				playerKnight.hp = playerKnight.maxHP;
				XP += enemyLVL;
				cout << "Press Enter to continue." << endl;
				cin.ignore();
				thread stopBattleSong(stop_BattleSong);
				stopBattleSong.join();
				thread mainSong(playMainSong);
				mainSong.join();
				mainMenu();
			}
		}
		else if (charClass == 'k' && enemyClass == 'w') {															//If the player is a knight and the enemy is a wizard...
			if (playerKnight.hp <= 0) {																				//If player is out of hp, end the fight with a loss, stop the battle music, start the main theme song, and restart the main menu.
				cout << playerKnight.name << " fainted from exhaustion!" << endl;
				Sleep(3000);
				cout << playerName << " lost the fight!" << endl;
				battlesPlayed += 1;
				battlesLost += 1;
				playerKnight.hp = playerKnight.maxHP;
				XP++;
				cout << "Press Enter to continue." << endl;
				cin.ignore();
				thread stopBattleSong(stop_BattleSong);
				stopBattleSong.join();
				thread mainSong(playMainSong);
				mainSong.join();
				mainMenu();
			}
			else if (enemyWizard.hp <= 0) {																			//If the enemy is out of hp, end the fight with a win, stop the battle music, start the main theme song, and restart the main menu.
				cout << enemyWizard.name << " fainted from exhaustion!" << endl;
				Sleep(3000);
				cout << playerName << " won the fight!" << endl;
				battlesPlayed++;
				battlesWon++;
				playerKnight.hp = playerKnight.maxHP;
				XP += enemyLVL;
				cout << "Press Enter to continue." << endl;
				cin.ignore();
				thread stopBattleSong(stop_BattleSong);
				stopBattleSong.join();
				thread mainSong(playMainSong);
				mainSong.join();
				mainMenu();
			}
		}
		else if (charClass == 'a' && enemyClass == 'k') {															//If the player is an archer and the enemy is a knight...
			if (playerArcher.hp <= 0) {																				//If the player is out of hp, end the fight with a loss, stop the battle music, start the main theme song, and restart the main menu.
				cout << playerArcher.name << " fainted from exhaustion!" << endl;
				Sleep(3000);
				cout << playerName << " lost the fight!" << endl;
				battlesPlayed += 1;
				battlesLost += 1;
				playerArcher.hp = playerArcher.maxHP;
				XP++;
				cout << "Press Enter to continue." << endl;
				cin.ignore();
				thread stopBattleSong(stop_BattleSong);
				stopBattleSong.join();
				thread mainSong(playMainSong);
				mainSong.join();
				mainMenu();
			}
			else if (enemyKnight.hp <= 0) {																			//If the enemy is out of hp, end of the fight with a win, stop the battle music, start the main theme song, and restart the main menu.
				cout << enemyKnight.name << " fainted from exhaustion!" << endl;
				Sleep(3000);
				cout << playerName << " won the fight!" << endl;
				battlesPlayed++;
				battlesWon++;
				playerArcher.hp = playerArcher.maxHP;
				XP += enemyLVL;
				cout << "Press Enter to continue." << endl;
				cin.ignore();
				thread stopBattleSong(stop_BattleSong);
				stopBattleSong.join();
				thread mainSong(playMainSong);
				mainSong.join();
				mainMenu();
			}
		}
		else if (charClass == 'a' && enemyClass == 'a') {															//If both characters are archers...
			if (playerArcher.hp <= 0) {																				//If the player is out of hp, end the fight with a loss, stop the battle music, start the main theme song, and restart the main menu.
				cout << playerArcher.name << " fainted from exhaustion!" << endl;
				Sleep(3000);
				cout << playerName << " lost the fight!" << endl;
				battlesPlayed += 1;
				battlesLost += 1;
				playerArcher.hp = playerArcher.maxHP;
				XP++;
				cout << "Press Enter to continue." << endl;
				cin.ignore();
				thread stopBattleSong(stop_BattleSong);
				stopBattleSong.join();
				thread mainSong(playMainSong);
				mainSong.join();
				mainMenu();
			}
			else if (enemyArcher.hp <= 0) {																			//If the enemy is out of hp, end the fight with a win, stop the battle music, start the main theme song, and restart the main menu.
				cout << enemyArcher.name << " fainted from exhaustion!" << endl;
				Sleep(3000);
				cout << playerName << " won the fight!" << endl;
				battlesPlayed++;
				battlesWon++;
				playerArcher.hp = playerArcher.maxHP;
				XP += enemyLVL;
				cout << "Press Enter to continue." << endl;
				cin.ignore();
				thread stopBattleSong(stop_BattleSong);
				stopBattleSong.join();
				thread mainSong(playMainSong);
				mainSong.join();
				mainMenu();
			}
		}
		else if (charClass == 'a' && enemyClass == 'w') {															//If the player is an archer and the enemy is a wizard...
		if (playerArcher.hp <= 0) {																					//If the player is out of hp, end the fight with a loss, stop the battle music, start the main theme song, and restart the main menu.
			cout << playerArcher.name << " fainted from exhaustion!" << endl;
			Sleep(3000);
			cout << playerName << " lost the fight!" << endl;
			battlesPlayed += 1;
			battlesLost += 1;
			playerArcher.hp = playerArcher.maxHP;
			XP++;
			cout << "Press Enter to continue." << endl;
			cin.ignore();
			thread stopBattleSong(stop_BattleSong);
			stopBattleSong.join();
			thread mainSong(playMainSong);
			mainSong.join();
			mainMenu();
		}
		else if (enemyWizard.hp <= 0) {																				//If the enemy is out of hp, end the fight with a win, stop the battle music, start the main theme song, and restart the main menu.
			cout << enemyWizard.name << " fainted from exhaustion!" << endl;
			Sleep(3000);
			cout << playerName << " won the fight!" << endl;
			battlesPlayed++;
			battlesWon++;
			playerArcher.hp = playerArcher.maxHP;
			XP += enemyLVL;
			cout << "Press Enter to continue." << endl;
			cin.ignore();
			thread stopBattleSong(stop_BattleSong);
			stopBattleSong.join();
			thread mainSong(playMainSong);
			mainSong.join();
			mainMenu();
		}
		}
		else if (charClass == 'w' && enemyClass == 'k') {															//If the player is a wizard and the enemy is a knight...
		if (playerWizard.hp <= 0) {																					//If the player is out of hp, end the fight with a loss, stop the battle music, start the main theme song, and restart the main menu.
			cout << playerWizard.name << " fainted from exhaustion!" << endl;
			Sleep(3000);
			cout << playerName << " lost the fight!" << endl;
			battlesPlayed += 1;
			battlesLost += 1;
			playerWizard.hp = playerWizard.maxHP;
			XP++;
			cout << "Press Enter to continue." << endl;
			cin.ignore();
			thread stopBattleSong(stop_BattleSong);
			stopBattleSong.join();
			thread mainSong(playMainSong);
			mainSong.join();
			mainMenu();
		}
		else if (enemyKnight.hp <= 0) {																				//If the enemy is out of hp, end the fight with a win, stop the battle music, start the main theme song, and restart the main menu.
			cout << enemyKnight.name << " fainted from exhaustion!" << endl;
			Sleep(3000);
			cout << playerName << " won the fight!" << endl;
			battlesPlayed++;
			battlesWon++;
			playerWizard.hp = playerWizard.maxHP;
			XP += enemyLVL;
			cout << "Press Enter to continue." << endl;
			cin.ignore();
			thread stopBattleSong(stop_BattleSong);
			stopBattleSong.join();
			thread mainSong(playMainSong);
			mainSong.join();
			mainMenu();
		}
		}
		else if (charClass == 'w' && enemyClass == 'a') {															//If the player is a wizard and the enemy is an archer...
		if (playerWizard.hp <= 0) {																					//If player is out of hp, end the fight with a loss, stop the battle music, start the main theme song, and restart the main menu.
			cout << playerWizard.name << " fainted from exhaustion!" << endl;
			Sleep(3000);
			cout << playerName << " lost the fight!" << endl;
			battlesPlayed += 1;
			battlesLost += 1;
			playerWizard.hp = playerWizard.maxHP;
			XP++;
			cout << "Press Enter to continue." << endl;
			cin.ignore();
			thread stopBattleSong(stop_BattleSong);
			stopBattleSong.join();
			thread mainSong(playMainSong);
			mainSong.join();
			mainMenu();
		}
		else if (enemyArcher.hp <= 0) {																				//If the enemy is out of hp, end the fight with a win, stop the battle music, start the main theme son, and restart the main menu.
			cout << enemyArcher.name << " fainted from exhaustion!" << endl;
			Sleep(3000);
			cout << playerName << " won the fight!" << endl;
			battlesPlayed++;
			battlesWon++;
			playerWizard.hp = playerWizard.maxHP;
			XP += enemyLVL;
			cout << "Press Enter to continue." << endl;
			cin.ignore();
			thread stopBattleSong(stop_BattleSong);
			stopBattleSong.join();
			thread mainSong(playMainSong);
			mainSong.join();
			mainMenu();
		}
		}
		else if (charClass == 'w' && enemyClass == 'w') {															//If both characters are wizards...
		if (playerWizard.hp <= 0) {																					//If the player is out of hp, end the fight with a loss, stop the battle music, start the main theme song, and restart the main menu.
			cout << playerWizard.name << " fainted from exhaustion!" << endl;
			Sleep(3000);
			cout << playerName << " lost the fight!" << endl;
			battlesPlayed += 1;
			battlesLost += 1;
			playerWizard.hp = playerWizard.maxHP;
			XP++;
			cout << "Press Enter to continue." << endl;
			cin.ignore();
			thread stopBattleSong(stop_BattleSong);
			stopBattleSong.join();
			thread mainSong(playMainSong);
			mainSong.join();
			mainMenu();
		}
		else if (enemyWizard.hp <= 0) {																				//If the enemy is out of hp, end the fight with a win, stop the battle music, start the main theme song, and restart the main menu.
			cout << enemyWizard.name << " fainted from exhaustion!" << endl;
			Sleep(3000);
			cout << playerName << " won the fight!" << endl;
			battlesPlayed++;
			battlesWon++;
			playerWizard.hp = playerWizard.maxHP;
			XP += enemyLVL;
			cout << "Press Enter to continue." << endl;
			cin.ignore();
			thread stopBattleSong(stop_BattleSong);
			stopBattleSong.join();
			thread mainSong(playMainSong);
			mainSong.join();
			mainMenu();
		}
		}
		else if (charClass != 'k' && charClass != 'a' && charClass != 'w' && enemyClass == 'k' && enemyClass == 'a' && enemyClass == 'w') {//If the characters don't have valid classes, throw an error and restart the main menu.
			throw 1;
		}
	}
	catch (int z)
	{
		if (z == 1) {
			cout << "ERROR: Invalid class" << endl;
			mainMenu();
		}
	}
}
/*
* The following 9 function govern the battle mechanics for Fight the Knight. As they are all nearly identical except for calls to classes,
	the first function (battlekk()) will be commented while the rest will not.
*/
void battlekk() {																									
	clearScreen();																									//Display player and enemy stats.
	cout << playerName << endl;
	cout << "HP: " << playerKnight.hp << "/" << playerKnight.maxHP << endl;
	cout << "AC: " << playerKnight.modAC << "/" << playerKnight.AC << endl;
	cout << endl;
	cout << enemyKnight.name << endl;
	cout << "HP: " << enemyKnight.hp << "/" << enemyKnight.maxHP << endl;
	cout << "AC: " << enemyKnight.modAC << "/" << enemyKnight.AC << endl;
	if (playerKnight.dex > enemyKnight.dex) {																		//If the player has a higher dexterity stat, they take their turn first.
		playerKnight.modAC = playerKnight.AC;
		enemyKnight.modAC = enemyKnight.AC;
		cout << endl;
		cout << playerKnight.name << " speeds ahead of their opponent..." << endl;
		Sleep(2000);
		cout << endl;
		cout << "What move would you like to use?" << endl;															//Display a menu of move options, and allow the user to input an answer.
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Slash Attack: A basic slashing attack." << endl;
		cout << "Stab Attack: A basic stab attack." << endl;
		cout << "Block: Use your shield to help block attacks!" << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {																				//If the player answered dodge, call the Character class's dodge function.
				playerKnight.dodge();
			}
			else if (answer == "Taunt") {																			//If the player answered taunt, call the Character class's taunt function.
				enemyKnight.modAC -= playerKnight.taunt(enemyKnight.inT, enemyKnight.wis, enemyKnight.cha);
			}
			else if (answer == "Slash Attack") {																	//If the player answered slash attack, call the Knight class's slashAttack function, and check to see if the battle is won.
				enemyKnight.hp -= playerKnight.slashAttack(enemyKnight.modAC);
				checkBattleEnd();
			}
			else if (answer == "Stab Attack") {																		//If the player answered stab attack, call the Knight class's stabAttack function, and check to see if the battle is over.
				enemyKnight.hp -= playerKnight.stabAttack(enemyKnight.modAC);
				checkBattleEnd();
			}
			else if (answer == "Block") {																			//If the player answered block, call the Knight class's block function.
				playerKnight.block();
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Slash Attack" && answer != "Stab Attack" && answer != "Block") {//If the player did not answer any of the above, throw an error and recall the battle function.
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battlekk();
			}
		}

		
		cout << "Press Enter to continue." << endl;
		cin.ignore();
		cout << endl;
		cout << endl;
		int enemyMove = rand() % 7 + 1;																				//Randomly pick a move for the enemy.
		try																											//Execute moves using called functions, attacks have double the weight.
		{
			if (enemyMove == 1) {
				enemyKnight.dodge();
			}
			else if (enemyMove == 2) {
				playerKnight.modAC -= enemyKnight.taunt(playerKnight.inT, playerKnight.wis, playerKnight.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerKnight.hp -= enemyKnight.slashAttack(playerKnight.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerKnight.hp -= enemyKnight.stabAttack(playerKnight.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				enemyKnight.block();
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {		//If the random number isn't valid, throw an error and recall the battle function.
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battlekk();
			}
		}
		Sleep(5000);
	}
	else if (enemyKnight.dex >= playerKnight.dex) {																	//If the enemy has a higher dexterity stat then the player, they take their turn first.
		cout << endl;
		cout << enemyKnight.name << " speeds ahead of " << playerKnight.name << "..." << endl;
		Sleep(3000);
		cout << endl;
		int enemyMove = rand() % 7 + 1;																				//Randomly pick a move for the enemy.
		try																											//Execute moves using called functions, attacks have double the weight.
		{
			if (enemyMove == 1) {
				enemyKnight.dodge();
			}
			else if (enemyMove == 2) {
				playerKnight.modAC -= enemyKnight.taunt(playerKnight.inT, playerKnight.wis, playerKnight.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerKnight.hp -= enemyKnight.slashAttack(playerKnight.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerKnight.hp -= enemyKnight.stabAttack(playerKnight.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				enemyKnight.block();
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {		//If the random number isn't valid, throw an error and recall the battle function.
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battlekk();
			}
		}


		cout << "Press Enter to continue." << endl;
		cin.ignore();
		playerKnight.modAC = playerKnight.AC;
		enemyKnight.modAC = enemyKnight.AC;
		cout << endl;
		cout << endl;
		cout << "What move would you like to use?" << endl;															//Display a menu of move options, and allow the user to input an answer.
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Slash Attack: A basic slashing attack." << endl;
		cout << "Stab Attack: A basic stab attack." << endl;
		cout << "Block: Use your shield to help block attacks!" << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {																				//If the player answered dodge, call the Character class's dodge function.
				playerKnight.dodge();
			}
			else if (answer == "Taunt") {																			//If the player answered taunt, call the Character class's taunt function.
				enemyKnight.modAC -= playerKnight.taunt(enemyKnight.inT, enemyKnight.wis, enemyKnight.cha);
			}
			else if (answer == "Slash Attack") {																	//If the player answered slash attack, call the Knight class's slashAttack function, and check to see if the battle is won.
				enemyKnight.hp -= playerKnight.slashAttack(enemyKnight.modAC);
				checkBattleEnd();
			}
			else if (answer == "Stab Attack") {																		//If the player answered stab attack, call the Knight class's stabAttack function, and check to see if the battle is over.
				enemyKnight.hp -= playerKnight.stabAttack(enemyKnight.modAC);
				checkBattleEnd();
			}
			else if (answer == "Block") {																			//If the player answered block, call the Knight class's block function.
				playerKnight.block();
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Slash Attack" && answer != "Stab Attack" && answer != "Block") {//If the player did not answer any of the above, throw an error and recall the battle function.
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battlekk();
			}
		}
		Sleep(5000);
	}
	cout << "Press Enter to continue." << endl;																		//Wait for the user to press enter before recalling the battle function, so the battle continues until one character is out of hp.
	cin.ignore();
	battlekk();
}
void battleka() {
	clearScreen();
	cout << playerName << endl;
	cout << "HP: " << playerKnight.hp << "/" << playerKnight.maxHP << endl;
	cout << "AC: " << playerKnight.modAC << "/" << playerKnight.AC << endl;
	cout << endl;
	cout << enemyArcher.name << endl;
	cout << "HP: " << enemyArcher.hp << "/" << enemyArcher.maxHP << endl;
	cout << "AC: " << enemyArcher.modAC << "/" << enemyArcher.AC << endl;
	if (playerKnight.dex > enemyArcher.dex) {
		playerKnight.modAC = playerKnight.AC;
		enemyArcher.modAC = enemyArcher.AC;
		cout << endl;
		cout << playerKnight.name << " speeds ahead of their opponent..." << endl;
		Sleep(2000);
		cout << endl;
		cout << "What move would you like to use?" << endl;
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Slash Attack: A basic slashing attack." << endl;
		cout << "Stab Attack: A basic stab attack." << endl;
		cout << "Block: Use your shield to help block attacks!" << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {
				playerKnight.dodge();
			}
			else if (answer == "Taunt") {
				enemyArcher.modAC -= playerKnight.taunt(enemyArcher.inT, enemyArcher.wis, enemyArcher.cha);
			}
			else if (answer == "Slash Attack") {
				enemyArcher.hp -= playerKnight.slashAttack(enemyArcher.modAC);
				checkBattleEnd();
			}
			else if (answer == "Stab Attack") {
				enemyArcher.hp -= playerKnight.stabAttack(enemyArcher.modAC);
				checkBattleEnd();
			}
			else if (answer == "Block") {
				playerKnight.block();
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Slash Attack" && answer != "Stab Attack" && answer != "Block") {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battleka();
			}
		}


		cout << "Press Enter to continue." << endl;
		cin.ignore();
		cout << endl;
		cout << endl;
		int enemyMove = rand() % 7 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyArcher.dodge();
			}
			else if (enemyMove == 2) {
				playerKnight.modAC -= enemyArcher.taunt(playerKnight.inT, playerKnight.wis, playerKnight.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerKnight.hp -= enemyArcher.quickShotAttack(playerKnight.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerKnight.hp -= enemyArcher.powerShotAttack(playerKnight.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				playerKnight.modAC -= enemyArcher.hide(playerKnight.wis);
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battleka();
			}
		}
		Sleep(5000);
	}
	else if (enemyArcher.dex >= playerKnight.dex) {
		cout << endl;
		cout << enemyArcher.name << " speeds ahead of " << playerKnight.name << "..." << endl;
		Sleep(3000);
		cout << endl;
		int enemyMove = rand() % 7 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyArcher.dodge();
			}
			else if (enemyMove == 2) {
				playerKnight.modAC -= enemyArcher.taunt(playerKnight.inT, playerKnight.wis, playerKnight.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerKnight.hp -= enemyArcher.quickShotAttack(playerKnight.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerKnight.hp -= enemyArcher.powerShotAttack(playerKnight.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				playerKnight.modAC -= enemyArcher.hide(playerKnight.wis);
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battleka();
			}
		}


		cout << "Press Enter to continue." << endl;
		cin.ignore();
		playerKnight.modAC = playerKnight.AC;
		enemyArcher.modAC = enemyArcher.AC;
		cout << endl;
		cout << endl;
		cout << "What move would you like to use?" << endl;
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Slash Attack: A basic slashing attack." << endl;
		cout << "Stab Attack: A basic stab attack." << endl;
		cout << "Block: Use your shield to help block attacks!" << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {
				playerKnight.dodge();
			}
			else if (answer == "Taunt") {
				enemyArcher.modAC -= playerKnight.taunt(enemyArcher.inT, enemyArcher.wis, enemyArcher.cha);
			}
			else if (answer == "Slash Attack") {
				enemyArcher.hp -= playerKnight.slashAttack(enemyArcher.modAC);
				checkBattleEnd();
			}
			else if (answer == "Stab Attack") {
				enemyArcher.hp -= playerKnight.stabAttack(enemyArcher.modAC);
				checkBattleEnd();
			}
			else if (answer == "Block") {
				playerKnight.block();
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Slash Attack" && answer != "Stab Attack" && answer != "Block") {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battleka();
			}
		}
		Sleep(5000);
	}
	cout << "Press Enter to continue." << endl;
	cin.ignore();
	battleka();
}
void battlekw() {
	clearScreen();
	cout << playerName << endl;
	cout << "HP: " << playerKnight.hp << "/" << playerKnight.maxHP << endl;
	cout << "AC: " << playerKnight.modAC << "/" << playerKnight.AC << endl;
	cout << endl;
	cout << enemyWizard.name << endl;
	cout << "HP: " << enemyWizard.hp << "/" << enemyWizard.maxHP << endl;
	cout << "AC: " << enemyWizard.modAC << "/" << enemyWizard.AC << endl;
	if (playerKnight.dex > enemyWizard.dex) {
		playerKnight.modAC = playerKnight.AC;
		enemyWizard.modAC = enemyWizard.AC;
		cout << endl;
		cout << playerKnight.name << " speeds ahead of their opponent..." << endl;
		Sleep(2000);
		cout << endl;
		cout << "What move would you like to use?" << endl;
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Slash Attack: A basic slashing attack." << endl;
		cout << "Stab Attack: A basic stab attack." << endl;
		cout << "Block: Use your shield to help block attacks!" << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {
				playerKnight.dodge();
			}
			else if (answer == "Taunt") {
				enemyWizard.modAC -= playerKnight.taunt(enemyWizard.inT, enemyWizard.wis, enemyWizard.cha);
			}
			else if (answer == "Slash Attack") {
				enemyWizard.hp -= playerKnight.slashAttack(enemyWizard.modAC);
				checkBattleEnd();
			}
			else if (answer == "Stab Attack") {
				enemyWizard.hp -= playerKnight.stabAttack(enemyWizard.modAC);
				checkBattleEnd();
			}
			else if (answer == "Block") {
				playerKnight.block();
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Slash Attack" && answer != "Stab Attack" && answer != "Block") {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battlekw();
			}
		}


		cout << "Press Enter to continue." << endl;
		cin.ignore();
		cout << endl;
		cout << endl;
		int enemyMove = rand() % 7 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyWizard.dodge();
			}
			else if (enemyMove == 2) {
				playerKnight.modAC -= enemyWizard.taunt(playerKnight.inT, playerKnight.wis, playerKnight.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerKnight.hp -= enemyWizard.fireAttack(playerKnight.str);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerKnight.hp -= enemyWizard.lightningAttack(playerKnight.dex);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				playerKnight.hp -= enemyWizard.iceAttack(playerKnight.con);
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battlekw();
			}
		}
		Sleep(5000);
	}
	else if (enemyWizard.dex >= playerKnight.dex) {
		cout << endl;
		cout << enemyWizard.name << " speeds ahead of " << playerKnight.name << "..." << endl;
		Sleep(3000);
		cout << endl;
		int enemyMove = rand() % 7 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyWizard.dodge();
			}
			else if (enemyMove == 2) {
				playerKnight.modAC -= enemyWizard.taunt(playerKnight.inT, playerKnight.wis, playerKnight.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerKnight.hp -= enemyWizard.fireAttack(playerKnight.str);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerKnight.hp -= enemyWizard.lightningAttack(playerKnight.dex);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				playerKnight.hp -= enemyWizard.iceAttack(playerKnight.con);
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battlekw();
			}
		}


		cout << "Press Enter to continue." << endl;
		cin.ignore();
		playerKnight.modAC = playerKnight.AC;
		enemyWizard.modAC = enemyWizard.AC;
		cout << endl;
		cout << endl;
		cout << "What move would you like to use?" << endl;
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Slash Attack: A basic slashing attack." << endl;
		cout << "Stab Attack: A basic stab attack." << endl;
		cout << "Block: Use your shield to help block attacks!" << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {
				playerKnight.dodge();
			}
			else if (answer == "Taunt") {
				enemyWizard.modAC -= playerKnight.taunt(enemyWizard.inT, enemyWizard.wis, enemyWizard.cha);
			}
			else if (answer == "Slash Attack") {
				enemyWizard.hp -= playerKnight.slashAttack(enemyWizard.modAC);
				checkBattleEnd();
			}
			else if (answer == "Stab Attack") {
				enemyWizard.hp -= playerKnight.stabAttack(enemyWizard.modAC);
				checkBattleEnd();
			}
			else if (answer == "Block") {
				playerKnight.block();
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Slash Attack" && answer != "Stab Attack" && answer != "Block") {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battlekw();
			}
		}
		Sleep(5000);
	}
	cout << "Press Enter to continue." << endl;
	cin.ignore();
	battlekw();
}
void battleak() {
	clearScreen();
	cout << playerName << endl;
	cout << "HP: " << playerArcher.hp << "/" << playerArcher.maxHP << endl;
	cout << "AC: " << playerArcher.modAC << "/" << playerArcher.AC << endl;
	cout << endl;
	cout << enemyKnight.name << endl;
	cout << "HP: " << enemyKnight.hp << "/" << enemyKnight.maxHP << endl;
	cout << "AC: " << enemyKnight.modAC << "/" << enemyKnight.AC << endl;
	if (playerArcher.dex > enemyKnight.dex) {
		playerArcher.modAC = playerArcher.AC;
		enemyKnight.modAC = enemyKnight.AC;
		cout << endl;
		cout << playerArcher.name << " speeds ahead of their opponent..." << endl;
		Sleep(2000);
		cout << endl;
		cout << "What move would you like to use?" << endl;
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Quick Shot Attack: Shoot 3 arrows at your opponent." << endl;
		cout << "Power Shot Attack: Shoot 1 powerful arrow at your opponent." << endl;
		cout << "Hide: Hide from your enemy and lower their defense!" << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {
				playerArcher.dodge();
			}
			else if (answer == "Taunt") {
				enemyKnight.modAC -= playerArcher.taunt(enemyKnight.inT, enemyKnight.wis, enemyKnight.cha);
			}
			else if (answer == "Quick Shot Attack") {
				enemyKnight.hp -= playerArcher.quickShotAttack(enemyKnight.modAC);
				checkBattleEnd();
			}
			else if (answer == "Power Shot Attack") {
				enemyKnight.hp -= playerArcher.powerShotAttack(enemyKnight.modAC);
				checkBattleEnd();
			}
			else if (answer == "Hide") {
				enemyKnight.modAC -= playerArcher.hide(enemyKnight.wis);
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Quick Shot Attack" && answer != "Power Shot Attack" && answer != "Hide") {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battleak();
			}
		}


		cout << "Press Enter to continue." << endl;
		cin.ignore();
		cout << endl;
		cout << endl;
		int enemyMove = rand() % 7 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyKnight.dodge();
			}
			else if (enemyMove == 2) {
				playerArcher.modAC -= enemyKnight.taunt(playerArcher.inT, playerArcher.wis, playerArcher.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerArcher.hp -= enemyKnight.slashAttack(playerArcher.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerArcher.hp -= enemyKnight.stabAttack(playerArcher.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				enemyKnight.block();
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battleak();
			}
		}
		Sleep(5000);
	}
	else if (enemyKnight.dex >= playerArcher.dex) {
		cout << endl;
		cout << enemyKnight.name << " speeds ahead of " << playerArcher.name << "..." << endl;
		Sleep(3000);
		cout << endl;
		int enemyMove = rand() % 7 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyKnight.dodge();
			}
			else if (enemyMove == 2) {
				playerArcher.modAC -= enemyKnight.taunt(playerArcher.inT, playerArcher.wis, playerArcher.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerArcher.hp -= enemyKnight.slashAttack(playerArcher.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerArcher.hp -= enemyKnight.stabAttack(playerArcher.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				enemyKnight.block();
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battleak();
			}
		}


		cout << "Press Enter to continue." << endl;
		cin.ignore();
		playerArcher.modAC = playerArcher.AC;
		enemyKnight.modAC = enemyKnight.AC;
		cout << endl;
		cout << endl;
		cout << "What move would you like to use?" << endl;
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Quick Shot Attack: Shoot 3 arrows at your opponent." << endl;
		cout << "Power Shot Attack: Shoot one powerful shot at your opponent." << endl;
		cout << "Hide: Hide from your enemy and lower their defense!" << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {
				playerArcher.dodge();
			}
			else if (answer == "Taunt") {
				enemyKnight.modAC -= playerArcher.taunt(enemyKnight.inT, enemyKnight.wis, enemyKnight.cha);
			}
			else if (answer == "Quick Shot Attack") {
				enemyKnight.hp -= playerArcher.quickShotAttack(enemyKnight.modAC);
				checkBattleEnd();
			}
			else if (answer == "Power Shot Attack") {
				enemyKnight.hp -= playerArcher.powerShotAttack(enemyKnight.modAC);
				checkBattleEnd();
			}
			else if (answer == "Hide") {
				enemyKnight.modAC -= playerArcher.hide(enemyKnight.wis);
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Quick Shot Attack" && answer != "Power Shot Attack" && answer != "Hide") {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battleak();
			}
		}
		Sleep(5000);
	}
	cout << "Press Enter to continue." << endl;
	cin.ignore();
	battleak();
}
void battleaa() {
	clearScreen();
	cout << playerName << endl;
	cout << "HP: " << playerArcher.hp << "/" << playerArcher.maxHP << endl;
	cout << "AC: " << playerArcher.modAC << "/" << playerArcher.AC << endl;
	cout << endl;
	cout << enemyArcher.name << endl;
	cout << "HP: " << enemyArcher.hp << "/" << enemyArcher.maxHP << endl;
	cout << "AC: " << enemyArcher.modAC << "/" << enemyArcher.AC << endl;
	if (playerArcher.dex > enemyArcher.dex) {
		playerArcher.modAC = playerArcher.AC;
		enemyArcher.modAC = enemyArcher.AC;
		cout << endl;
		cout << playerArcher.name << " speeds ahead of their opponent..." << endl;
		Sleep(2000);
		cout << endl;
		cout << "What move would you like to use?" << endl;
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Quick Shot Attack: Shoot 3 arrows at your opponent." << endl;
		cout << "Power Shot Attack: Shoot 1 powerful arrow at your opponent." << endl;
		cout << "Hide: Hide from your enemy and lower their defense!" << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {
				playerArcher.dodge();
			}
			else if (answer == "Taunt") {
				enemyArcher.modAC -= playerArcher.taunt(enemyArcher.inT, enemyArcher.wis, enemyArcher.cha);
			}
			else if (answer == "Quick Shot Attack") {
				enemyArcher.hp -= playerArcher.quickShotAttack(enemyArcher.modAC);
				checkBattleEnd();
			}
			else if (answer == "Power Shot Attack") {
				enemyArcher.hp -= playerArcher.powerShotAttack(enemyArcher.modAC);
				checkBattleEnd();
			}
			else if (answer == "Hide") {
				enemyArcher.modAC -= playerArcher.hide(enemyArcher.wis);
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Quick Shot Attack" && answer != "Power Shot Attack" && answer != "Hide") {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battleaa();
			}
		}


		cout << "Press Enter to continue." << endl;
		cin.ignore();
		cout << endl;
		cout << endl;
		int enemyMove = rand() % 7 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyArcher.dodge();
			}
			else if (enemyMove == 2) {
				playerArcher.modAC -= enemyArcher.taunt(playerArcher.inT, playerArcher.wis, playerArcher.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerArcher.hp -= enemyArcher.quickShotAttack(playerArcher.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerArcher.hp -= enemyArcher.powerShotAttack(playerArcher.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				playerArcher.modAC -= enemyArcher.hide(playerArcher.wis);
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battleaa();
			}
		}
		Sleep(5000);
	}
	else if (enemyArcher.dex >= playerArcher.dex) {
		cout << endl;
		cout << enemyArcher.name << " speeds ahead of " << playerArcher.name << "..." << endl;
		Sleep(3000);
		cout << endl;
		int enemyMove = rand() % 7 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyArcher.dodge();
			}
			else if (enemyMove == 2) {
				playerArcher.modAC -= enemyArcher.taunt(playerArcher.inT, playerArcher.wis, playerArcher.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerArcher.hp -= enemyArcher.quickShotAttack(playerArcher.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerArcher.hp -= enemyArcher.powerShotAttack(playerArcher.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				playerArcher.modAC -= enemyArcher.hide(playerArcher.wis);
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battleaa();
			}
		}


		cout << "Press Enter to continue." << endl;
		cin.ignore();
		playerArcher.modAC = playerArcher.AC;
		enemyArcher.modAC = enemyArcher.AC;
		cout << endl;
		cout << endl;
		cout << "What move would you like to use?" << endl;
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Quick Shot Attack: Shoot 3 arrows at your opponent." << endl;
		cout << "Power Shot Attack: Shoot one powerful shot at your opponent." << endl;
		cout << "Hide: Hide from your enemy and lower their defense!" << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {
				playerArcher.dodge();
			}
			else if (answer == "Taunt") {
				enemyArcher.modAC -= playerArcher.taunt(enemyArcher.inT, enemyArcher.wis, enemyArcher.cha);
			}
			else if (answer == "Quick Shot Attack") {
				enemyArcher.hp -= playerArcher.quickShotAttack(enemyArcher.modAC);
				checkBattleEnd();
			}
			else if (answer == "Power Shot Attack") {
				enemyArcher.hp -= playerArcher.powerShotAttack(enemyArcher.modAC);
				checkBattleEnd();
			}
			else if (answer == "Hide") {
				enemyArcher.modAC -= playerArcher.hide(enemyArcher.wis);
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Quick Shot Attack" && answer != "Power Shot Attack" && answer != "Hide") {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battleaa();
			}
		}
		Sleep(5000);
	}
	cout << "Press Enter to continue." << endl;
	cin.ignore();
	battleaa();
}
void battleaw() {
	clearScreen();
	cout << playerName << endl;
	cout << "HP: " << playerArcher.hp << "/" << playerArcher.maxHP << endl;
	cout << "AC: " << playerArcher.modAC << "/" << playerArcher.AC << endl;
	cout << endl;
	cout << enemyWizard.name << endl;
	cout << "HP: " << enemyWizard.hp << "/" << enemyWizard.maxHP << endl;
	cout << "AC: " << enemyWizard.modAC << "/" << enemyWizard.AC << endl;
	if (playerArcher.dex > enemyWizard.dex) {
		playerArcher.modAC = playerArcher.AC;
		enemyWizard.modAC = enemyWizard.AC;
		cout << endl;
		cout << playerArcher.name << " speeds ahead of their opponent..." << endl;
		Sleep(2000);
		cout << endl;
		cout << "What move would you like to use?" << endl;
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Quick Shot Attack: Shoot 3 arrows at your opponent." << endl;
		cout << "Power Shot Attack: Shoot 1 powerful arrow at your opponent." << endl;
		cout << "Hide: Hide from your enemy and lower their defense!" << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {
				playerArcher.dodge();
			}
			else if (answer == "Taunt") {
				enemyWizard.modAC -= playerArcher.taunt(enemyWizard.inT, enemyWizard.wis, enemyWizard.cha);
			}
			else if (answer == "Quick Shot Attack") {
				enemyWizard.hp -= playerArcher.quickShotAttack(enemyWizard.modAC);
				checkBattleEnd();
			}
			else if (answer == "Power Shot Attack") {
				enemyWizard.hp -= playerArcher.powerShotAttack(enemyWizard.modAC);
				checkBattleEnd();
			}
			else if (answer == "Hide") {
				enemyWizard.modAC -= playerArcher.hide(enemyWizard.wis);
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Quick Shot Attack" && answer != "Power Shot Attack" && answer != "Hide") {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battleaw();
			}
		}


		cout << "Press Enter to continue." << endl;
		cin.ignore();
		cout << endl;
		cout << endl;
		int enemyMove = rand() % 7 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyWizard.dodge();
			}
			else if (enemyMove == 2) {
				playerArcher.modAC -= enemyWizard.taunt(playerArcher.inT, playerArcher.wis, playerArcher.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerArcher.hp -= enemyWizard.fireAttack(playerArcher.str);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerArcher.hp -= enemyWizard.lightningAttack(playerArcher.dex);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				playerArcher.hp -= enemyWizard.iceAttack(playerArcher.con);
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battleaw();
			}
		}
		Sleep(5000);
	}
	else if (enemyWizard.dex >= playerArcher.dex) {
		cout << endl;
		cout << enemyWizard.name << " speeds ahead of " << playerArcher.name << "..." << endl;
		Sleep(3000);
		cout << endl;
		int enemyMove = rand() % 7 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyWizard.dodge();
			}
			else if (enemyMove == 2) {
				playerArcher.modAC -= enemyWizard.taunt(playerArcher.inT, playerArcher.wis, playerArcher.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerArcher.hp -= enemyWizard.fireAttack(playerArcher.str);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerArcher.hp -= enemyWizard.lightningAttack(playerArcher.dex);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				playerArcher.hp -= enemyWizard.iceAttack(playerArcher.con);
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battleaw();
			}
		}


		cout << "Press Enter to continue." << endl;
		cin.ignore();
		playerArcher.modAC = playerArcher.AC;
		enemyWizard.modAC = enemyWizard.AC;
		cout << endl;
		cout << endl;
		cout << "What move would you like to use?" << endl;
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Quick Shot Attack: Shoot 3 arrows at your opponent." << endl;
		cout << "Power Shot Attack: Shoot one powerful shot at your opponent." << endl;
		cout << "Hide: Hide from your enemy and lower their defense!" << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {
				playerArcher.dodge();
			}
			else if (answer == "Taunt") {
				enemyWizard.modAC -= playerArcher.taunt(enemyWizard.inT, enemyWizard.wis, enemyWizard.cha);
			}
			else if (answer == "Quick Shot Attack") {
				enemyWizard.hp -= playerArcher.quickShotAttack(enemyWizard.modAC);
				checkBattleEnd();
			}
			else if (answer == "Power Shot Attack") {
				enemyWizard.hp -= playerArcher.powerShotAttack(enemyWizard.modAC);
				checkBattleEnd();
			}
			else if (answer == "Hide") {
				enemyWizard.modAC -= playerArcher.hide(enemyWizard.wis);
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Quick Shot Attack" && answer != "Power Shot Attack" && answer != "Hide") {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battleaw();
			}
		}
		Sleep(5000);
	}
	cout << "Press Enter to continue." << endl;
	cin.ignore();
	battleaw();
}
void battlewk() {
	clearScreen();
	cout << playerName << endl;
	cout << "HP: " << playerWizard.hp << "/" << playerWizard.maxHP << endl;
	cout << "AC: " << playerWizard.modAC << "/" << playerWizard.AC << endl;
	cout << endl;
	cout << enemyKnight.name << endl;
	cout << "HP: " << enemyKnight.hp << "/" << enemyKnight.maxHP << endl;
	cout << "AC: " << enemyKnight.modAC << "/" << enemyKnight.AC << endl;
	if (playerWizard.dex > enemyKnight.dex) {
		playerWizard.modAC = playerWizard.AC;
		enemyKnight.modAC = enemyKnight.AC;
		cout << endl;
		cout << playerWizard.name << " speeds ahead of their opponent..." << endl;
		Sleep(2000);
		cout << endl;
		cout << "What move would you like to use?" << endl;
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Fire Attack: Throw a ball of fire at your opponent." << endl;
		cout << "Lightning Attack: Shoot a bolt of lightning at your opponent." << endl;
		cout << "Ice Attack: Throw a ball of ice at your opponent." << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {
				playerWizard.dodge();
			}
			else if (answer == "Taunt") {
				enemyKnight.modAC -= playerWizard.taunt(enemyKnight.inT, enemyKnight.wis, enemyKnight.cha);
			}
			else if (answer == "Fire Attack") {
				enemyKnight.hp -= playerWizard.fireAttack(enemyKnight.str);
				checkBattleEnd();
			}
			else if (answer == "Lightning Attack") {
				enemyKnight.hp -= playerWizard.lightningAttack(enemyKnight.dex);
				checkBattleEnd();
			}
			else if (answer == "Ice Attack") {
				enemyKnight.hp -= playerWizard.iceAttack(enemyKnight.con);
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Fire Attack" && answer != "Lightning Attack" && answer != "Ice Attack") {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battlewk();
			}
		}


		cout << "Press Enter to continue." << endl;
		cin.ignore();
		cout << endl;
		cout << endl;
		int enemyMove = rand() % 7 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyKnight.dodge();
			}
			else if (enemyMove == 2) {
				playerWizard.modAC -= enemyKnight.taunt(playerWizard.inT, playerWizard.wis, playerWizard.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerWizard.hp -= enemyKnight.slashAttack(playerWizard.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerWizard.hp -= enemyKnight.stabAttack(playerWizard.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				enemyKnight.block();
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battlewk();
			}
		}
		Sleep(5000);
	}
	else if (enemyKnight.dex >= playerWizard.dex) {
		cout << endl;
		cout << enemyKnight.name << " speeds ahead of " << playerWizard.name << "..." << endl;
		Sleep(3000);
		cout << endl;
		int enemyMove = rand() % 7 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyKnight.dodge();
			}
			else if (enemyMove == 2) {
				playerWizard.modAC -= enemyKnight.taunt(playerWizard.inT, playerWizard.wis, playerWizard.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerWizard.hp -= enemyKnight.slashAttack(playerWizard.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerWizard.hp -= enemyKnight.stabAttack(playerWizard.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				enemyKnight.block();
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battlewk();
			}
		}


		cout << "Press Enter to continue." << endl;
		cin.ignore();
		playerWizard.modAC = playerWizard.AC;
		enemyKnight.modAC = enemyKnight.AC;
		cout << endl;
		cout << endl;
		cout << "What move would you like to use?" << endl;
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Fire Attack: Throw a ball of fire at your opponent." << endl;
		cout << "Lightning Attack: Shoot a bolt of lightning at your opponent." << endl;
		cout << "Ice Attack: Throw a ball of ice at your opponent." << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {
				playerWizard.dodge();
			}
			else if (answer == "Taunt") {
				enemyKnight.modAC -= playerWizard.taunt(enemyKnight.inT, enemyKnight.wis, enemyKnight.cha);
			}
			else if (answer == "Fire Attack") {
				enemyKnight.hp -= playerWizard.fireAttack(enemyKnight.str);
				checkBattleEnd();
			}
			else if (answer == "Lightning Attack") {
				enemyKnight.hp -= playerWizard.lightningAttack(enemyKnight.dex);
				checkBattleEnd();
			}
			else if (answer == "Ice Attack") {
				enemyKnight.hp -= playerWizard.iceAttack(enemyKnight.con);
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Fire Attack" && answer != "Lightning Attack" && answer != "Ice Attack") {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battlewk();
			}
		}
		Sleep(5000);
	}
	cout << "Press Enter to continue." << endl;
	cin.ignore();
	battlewk();
}
void battlewa() {
	clearScreen();
	cout << playerName << endl;
	cout << "HP: " << playerWizard.hp << "/" << playerWizard.maxHP << endl;
	cout << "AC: " << playerWizard.modAC << "/" << playerWizard.AC << endl;
	cout << endl;
	cout << enemyArcher.name << endl;
	cout << "HP: " << enemyArcher.hp << "/" << enemyArcher.maxHP << endl;
	cout << "AC: " << enemyArcher.modAC << "/" << enemyArcher.AC << endl;
	if (playerWizard.dex > enemyArcher.dex) {
		playerWizard.modAC = playerWizard.AC;
		enemyArcher.modAC = enemyArcher.AC;
		cout << endl;
		cout << playerWizard.name << " speeds ahead of their opponent..." << endl;
		Sleep(2000);
		cout << endl;
		cout << "What move would you like to use?" << endl;
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Fire Attack: Throw a ball of fire at your opponent." << endl;
		cout << "Lightning Attack: Shoot a bolt of lightning at your opponent." << endl;
		cout << "Ice Attack: Throw a ball of ice at your opponent." << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {
				playerWizard.dodge();
			}
			else if (answer == "Taunt") {
				enemyArcher.modAC -= playerWizard.taunt(enemyArcher.inT, enemyArcher.wis, enemyArcher.cha);
			}
			else if (answer == "Fire Attack") {
				enemyArcher.hp -= playerWizard.fireAttack(enemyArcher.str);
				checkBattleEnd();
			}
			else if (answer == "Lightning Attack") {
				enemyArcher.hp -= playerWizard.lightningAttack(enemyArcher.dex);
				checkBattleEnd();
			}
			else if (answer == "Ice Attack") {
				enemyArcher.hp -= playerWizard.iceAttack(enemyArcher.con);
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Fire Attack" && answer != "Lightning Attack" && answer != "Ice Attack") {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battlewa();
			}
		}


		cout << "Press Enter to continue." << endl;
		cin.ignore();
		cout << endl;
		cout << endl;
		int enemyMove = rand() % 7 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyArcher.dodge();
			}
			else if (enemyMove == 2) {
				playerWizard.modAC -= enemyArcher.taunt(playerWizard.inT, playerWizard.wis, playerWizard.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerWizard.hp -= enemyArcher.quickShotAttack(playerWizard.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerWizard.hp -= enemyArcher.powerShotAttack(playerWizard.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				playerWizard.modAC -= enemyArcher.hide(playerWizard.wis);
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battlewa();
			}
		}
		Sleep(5000);
	}
	else if (enemyArcher.dex >= playerWizard.dex) {
		cout << endl;
		cout << enemyArcher.name << " speeds ahead of " << playerWizard.name << "..." << endl;
		Sleep(3000);
		cout << endl;
		int enemyMove = rand() % 7 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyArcher.dodge();
			}
			else if (enemyMove == 2) {
				playerWizard.modAC -= enemyArcher.taunt(playerWizard.inT, playerWizard.wis, playerWizard.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerWizard.hp -= enemyArcher.quickShotAttack(playerWizard.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerWizard.hp -= enemyArcher.powerShotAttack(playerWizard.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				playerWizard.modAC -= enemyArcher.hide(playerWizard.wis);
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battlewa();
			}
		}


		cout << "Press Enter to continue." << endl;
		cin.ignore();
		playerWizard.modAC = playerWizard.AC;
		enemyArcher.modAC = enemyArcher.AC;
		cout << endl;
		cout << endl;
		cout << "What move would you like to use?" << endl;
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Fire Attack: Throw a ball of fire at your opponent." << endl;
		cout << "Lightning Attack: Shoot a bolt of lightning at your opponent." << endl;
		cout << "Ice Attack: Throw a ball of ice at your opponent." << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {
				playerWizard.dodge();
			}
			else if (answer == "Taunt") {
				enemyArcher.modAC -= playerWizard.taunt(enemyArcher.inT, enemyArcher.wis, enemyArcher.cha);
			}
			else if (answer == "Fire Attack") {
				enemyArcher.hp -= playerWizard.fireAttack(enemyArcher.str);
				checkBattleEnd();
			}
			else if (answer == "Lightning Attack") {
				enemyArcher.hp -= playerWizard.lightningAttack(enemyArcher.dex);
				checkBattleEnd();
			}
			else if (answer == "Ice Attack") {
				enemyArcher.hp -= playerWizard.iceAttack(enemyArcher.con);
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Fire Attack" && answer != "Lightning Attack" && answer != "Ice Attack") {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battlewa();
			}
		}
		Sleep(5000);
	}
	cout << "Press Enter to continue." << endl;
	cin.ignore();
	battlewa();
}
void battleww() {
	clearScreen();
	cout << playerName << endl;
	cout << "HP: " << playerWizard.hp << "/" << playerWizard.maxHP << endl;
	cout << "AC: " << playerWizard.modAC << "/" << playerWizard.AC << endl;
	cout << endl;
	cout << enemyWizard.name << endl;
	cout << "HP: " << enemyWizard.hp << "/" << enemyWizard.maxHP << endl;
	cout << "AC: " << enemyWizard.modAC << "/" << enemyWizard.AC << endl;
	if (playerWizard.dex > enemyWizard.dex) {
		playerWizard.modAC = playerWizard.AC;
		enemyWizard.modAC = enemyWizard.AC;
		cout << endl;
		cout << playerWizard.name << " speeds ahead of their opponent..." << endl;
		Sleep(2000);
		cout << endl;
		cout << "What move would you like to use?" << endl;
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Fire Attack: Throw a ball of fire at your opponent." << endl;
		cout << "Lightning Attack: Shoot a bolt of lightning at your opponent." << endl;
		cout << "Ice Attack: Throw a ball of ice at your opponent." << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {
				playerWizard.dodge();
			}
			else if (answer == "Taunt") {
				enemyWizard.modAC -= playerWizard.taunt(enemyWizard.inT, enemyWizard.wis, enemyWizard.cha);
			}
			else if (answer == "Fire Attack") {
				enemyWizard.hp -= playerWizard.fireAttack(enemyWizard.str);
				checkBattleEnd();
			}
			else if (answer == "Lightning Attack") {
				enemyWizard.hp -= playerWizard.lightningAttack(enemyWizard.dex);
				checkBattleEnd();
			}
			else if (answer == "Ice Attack") {
				enemyWizard.hp -= playerWizard.iceAttack(enemyWizard.con);
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Fire Attack" && answer != "Lightning Attack" && answer != "Ice Attack") {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battleww();
			}
		}


		cout << "Press Enter to continue." << endl;
		cin.ignore();
		cout << endl;
		cout << endl;
		int enemyMove = rand() % 7 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyWizard.dodge();
			}
			else if (enemyMove == 2) {
				playerWizard.modAC -= enemyWizard.taunt(playerWizard.inT, playerWizard.wis, playerWizard.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerWizard.hp -= enemyWizard.fireAttack(playerWizard.str);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerWizard.hp -= enemyWizard.lightningAttack(playerWizard.dex);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				playerWizard.hp -= enemyWizard.iceAttack(playerWizard.con);
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battleww();
			}
		}
		Sleep(5000);
	}
	else if (enemyWizard.dex >= playerWizard.dex) {
		cout << endl;
		cout << enemyWizard.name << " speeds ahead of " << playerWizard.name << "..." << endl;
		Sleep(3000);
		cout << endl;
		int enemyMove = rand() % 7 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyWizard.dodge();
			}
			else if (enemyMove == 2) {
				playerWizard.modAC -= enemyWizard.taunt(playerWizard.inT, playerWizard.wis, playerWizard.cha);
			}
			else if (enemyMove == 3 || enemyMove == 6) {
				playerWizard.hp -= enemyWizard.fireAttack(playerWizard.str);
				checkBattleEnd();
			}
			else if (enemyMove == 4 || enemyMove == 7) {
				playerWizard.hp -= enemyWizard.lightningAttack(playerWizard.dex);
				checkBattleEnd();
			}
			else if (enemyMove == 5) {
				playerWizard.hp -= enemyWizard.iceAttack(playerWizard.con);
			}
			else if (enemyMove != 1 && enemyMove != 2 && enemyMove != 3 && enemyMove != 4 && enemyMove != 5) {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid enemy move" << endl;
				battleww();
			}
		}


		cout << "Press Enter to continue." << endl;
		cin.ignore();
		playerWizard.modAC = playerWizard.AC;
		enemyWizard.modAC = enemyWizard.AC;
		cout << endl;
		cout << endl;
		cout << "What move would you like to use?" << endl;
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Fire Attack: Throw a ball of fire at your opponent." << endl;
		cout << "Lightning Attack: Shoot a bolt of lightning at your opponent." << endl;
		cout << "Ice Attack: Throw a ball of ice at your opponent." << endl;
		getline(cin, answer);
		Sleep(2000);
		try
		{
			if (answer == "Dodge") {
				playerWizard.dodge();
			}
			else if (answer == "Taunt") {
				enemyWizard.modAC -= playerWizard.taunt(enemyWizard.inT, enemyWizard.wis, enemyWizard.cha);
			}
			else if (answer == "Fire Attack") {
				enemyWizard.hp -= playerWizard.fireAttack(enemyWizard.str);
				checkBattleEnd();
			}
			else if (answer == "Lightning Attack") {
				enemyWizard.hp -= playerWizard.lightningAttack(enemyWizard.dex);
				checkBattleEnd();
			}
			else if (answer == "Ice Attack") {
				enemyWizard.hp -= playerWizard.iceAttack(enemyWizard.con);
			}
			else if (answer != "Dodge" && answer != "Taunt" && answer != "Fire Attack" && answer != "Lightning Attack" && answer != "Ice Attack") {
				throw 1;
			}
		}
		catch (int i)
		{
			if (i == 1) {
				cout << "ERROR: Invalid answer" << endl;
				battleww();
			}
		}
		Sleep(5000);
	}
	cout << "Press Enter to continue." << endl;
	cin.ignore();
	battleww();
}

void battleStart() {																								//Function for starting the battle.
	thread stopMainSong(stop_MainSong);																				//Stop the main theme song and start the battle song.
	stopMainSong.join();
	thread battleSong(playBattleSong);
	battleSong.join();
	try
	{
		if (charClass == 'k' && enemyClass == 'k') {																//If both characters are knights, set the player's hp and ac to normal before starting a battle.
			playerKnight.hp = playerKnight.maxHP;
			playerKnight.modAC = playerKnight.AC;
			battlekk();
		}
		else if (charClass == 'k' && enemyClass == 'a') {															//Do the same if the player is a knight and the enemy is an archer.
			playerKnight.hp = playerKnight.maxHP;
			playerKnight.modAC = playerKnight.AC;
			battleka();
		}
		else if (charClass == 'k' && enemyClass == 'w') {															//Do the same if the player is a knight and the enemy is a wizard.
			playerKnight.hp = playerKnight.maxHP;
			playerKnight.modAC = playerKnight.AC;
			battlekw();
		}
		else if (charClass == 'a' && enemyClass == 'k') {															//Do the same if the player is an archer and the enemy is a knight.
			playerArcher.hp = playerArcher.maxHP;
			playerArcher.modAC = playerArcher.AC;
			battleak();
		}
		else if (charClass == 'a' && enemyClass == 'a') {															//Do the same if the player is an archer and the enemy is an archer.
			playerArcher.hp = playerArcher.maxHP;
			playerArcher.modAC = playerArcher.AC;
			battleaa();
		}
		else if (charClass == 'a' && enemyClass == 'w') {															//Do the same if the player is an archer and enemy is a wizard.
			playerArcher.hp = playerArcher.maxHP;
			playerArcher.modAC = playerArcher.AC;
			battleaw();
		}
		else if (charClass == 'w' && enemyClass == 'k') {															//Do the same if the player is a wizard and the enemy is a knight.
			playerWizard.hp = playerWizard.maxHP;
			playerWizard.modAC = playerWizard.AC;
			battlewk();
		}
		else if (charClass == 'w' && enemyClass == 'a') {															//Do the same if the player is a wizard and the enemy is an archer.
			playerWizard.hp = playerWizard.maxHP;
			playerWizard.modAC = playerWizard.AC;
			battlewa();
		}
		else if (charClass == 'w' && enemyClass == 'w') {															//Do the same if both characters are wizards.
			playerWizard.hp = playerWizard.maxHP;
			playerWizard.modAC = playerWizard.AC;
			battleww();
		}
		else if (charClass != 'k' && charClass != 'a' && charClass != 'w' && enemyClass == 'k' && enemyClass == 'a' && enemyClass == 'w') {//If neither character has a valid class, throw an error and restart the main menu.
			throw 1;
		}
	}
	catch (int z)
	{
		if (z == 1) {
			cout << "ERROR: Invalid class" << endl;
			mainMenu();
		}
	}
}
int main() {																										//Main function, which executes on startup and handles starting processes for the program.
	srand(time(0));																									//Line of code which makes the random function more random.
	clearScreen();
	thread mainSong(playMainSong);																					//Play the main theme song using multithreading.
	mainSong.join();
	cout << "Welcome to Fight the Knight!" << endl;																	//Present the title screen.
	cout << "Press Enter to start" << endl;
	cin.ignore();
	cout << endl;
	cout << "Detecting save file..." << endl;																		
	inFile >> fileTest;																								//Test the save file to see if there is data inside.
	if (fileTest == "") {																							//If the save file doesn't contain data, close the file and call the welcome function.
		cout << "No save file detected." << endl;
		cout << "Welcome, new player!" << endl;
		inFile.close();
		welcome();
		mainMenu();
		if (saving == true) {
			return 0;
		}
		battleStart();
	}
	else {																											//If the save file contains data, load the game.
		cout << "Save file detected!" << endl;
		cout << "Loading save file..." << endl;
		inFile >> playerName;
		cout << "Welcome back, " << playerName << "!" << endl;
		inFile >> XP;
		inFile >> battlesPlayed;
		inFile >> battlesWon;
		inFile >> battlesLost;
		inFile >> charClass;
		try																											//Throw an error depending on what class the player is.
		{
			if (charClass == 'k') {
				throw 1;
			}
			if (charClass == 'a') {
				throw 2;
			}
			if (charClass == 'w') {
				throw 3;
			}
			else if (charClass != 'k' && charClass != 'a' && charClass != 'w') {
				throw 4;
			}
		}
		catch (int i)
		{
			if (i == 1) {																							//If the player is a knight, load data for a knight.
				inFile >> playerKnight.lvl;
				inFile >> playerKnight.maxHP;
				inFile >> playerKnight.AC;
				inFile >> playerKnight.str;
				inFile >> playerKnight.dex;
				inFile >> playerKnight.con;
				inFile >> playerKnight.inT;
				inFile >> playerKnight.wis;
				inFile >> playerKnight.cha;
				playerKnight.name = playerName;
			}
			if (i == 2) {																							//If the player is an archer, load data for an archer.
				inFile >> playerArcher.lvl;
				inFile >> playerArcher.maxHP;
				inFile >> playerArcher.AC;
				inFile >> playerArcher.str;
				inFile >> playerArcher.dex;
				inFile >> playerArcher.con;
				inFile >> playerArcher.inT;
				inFile >> playerArcher.wis;
				inFile >> playerArcher.cha;
				playerArcher.name = playerName;
			}
			if (i == 3) {																							//If the player is a wizard, load data for a wizard.
				inFile >> playerWizard.lvl;
				inFile >> playerWizard.maxHP;
				inFile >> playerWizard.AC;
				inFile >> playerWizard.str;
				inFile >> playerWizard.dex;
				inFile >> playerWizard.con;
				inFile >> playerWizard.inT;
				inFile >> playerWizard.wis;
				inFile >> playerWizard.cha;
				playerWizard.name = playerName;
			}
			else if (i == 4) {																						//If the player is not a valid class, throw an error, close the file and end the program.
				cout << "ERROR: Invalid class!" << endl;
				inFile.close();
				return 1;
			}
		}
		cout << "Save data loaded!" << endl;
		mainMenu();																									//Start the main menu.
		if (saving == true) {																						//If the player is saving their progress and exiting, end the program.
			return 0;
		}
		battleStart();																								//If not, start a battle. (Seems weird but it needed to function this way)
	}
	return 0;																										//Return 0, which indicates that the program ran all the way through successfully.
}