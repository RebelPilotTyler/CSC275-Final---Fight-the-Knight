#include <iostream>
#include <string>
#include <fstream>
#include "Character.h"
#include "Knight.h"
#include "Archer.h"
#include "Wizard.h"
#include <string.h>
using namespace std;
string playerName;
int XP;
int battlesWon;
int battlesLost;
int battlesPlayed;
ifstream inFile("Save File.txt");
string fileTest;
ofstream outFile;
string answer;
char charClass;
char enemyClass;
Knight playerKnight;
Archer playerArcher;
Wizard playerWizard;
Knight enemyKnight;
Archer enemyArcher;
Wizard enemyWizard;
bool saving = false;
void buildNewCharacter() {
	cout << endl;
	cout << "Select a class for your character:" << endl;
	cout << "Knight, Archer, Wizard" << endl;
	cin >> answer;
	try
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
	catch (int i)
	{
		if (i == 1) {
			cout << "Are you sure you want to play as a knight? (Yes, No)" << endl;
			cin >> answer;
			try
			{
				if (answer == "Yes") {
					cout << "Okay, Knight " << playerName << ", you are almost ready to go!" << endl;
					charClass = 'k';
				}
				if (answer == "No") {
					buildNewCharacter();
				}
				else if (answer != "Yes" && answer != "No") {
					throw 1;
				}
			}
			catch (int j)
			{
				cout << "ERROR: Invalid answer." << endl;
				buildNewCharacter();
			}
		}
		if (i == 2) {
			cout << "Are you sure you want to play as an archer? (Yes, No)" << endl;
			cin >> answer;
			try
			{
				if (answer == "Yes") {
					cout << "Okay, Archer " << playerName << ", you are almost ready to go!" << endl;
					charClass = 'a';
				}
				if (answer == "No") {
					buildNewCharacter();
				}
				else if (answer != "Yes" && answer != "No") {
					throw 1;
				}
			}
			catch (int j)
			{
				cout << "ERROR: Invalid answer." << endl;
				buildNewCharacter();
			}
		}
		if (i == 3) {
			cout << "Are you sure you want to play as a wizard? (Yes, No)" << endl;
			cin >> answer;
			try
			{
				if (answer == "Yes") {
					cout << "Okay, Wizard " << playerName << ", you are almost ready to go!" << endl;
					charClass = 'w';
				}
				if (answer == "No") {
					buildNewCharacter();
				}
				else if (answer != "Yes" && answer != "No") {
					throw 1;
				}
			}
			catch (int j)
			{
				cout << "ERROR: Invalid answer." << endl;
				buildNewCharacter();
			}
		}
		else if (i == 4) {
			cout << "ERROR: Invalid answer." << endl;
			buildNewCharacter();
		}
	}
	cout << "Creating character stats..." << endl;
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
		if (i == 1) {
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
		if (i == 2) {
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
			playerArcher.AC = 11 + playerArcher.dex + 3;
			playerArcher.modAC = playerArcher.AC;
		}
		if (i == 3) {
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
			playerWizard.AC = 11 + playerWizard.dex + 3;
			playerWizard.modAC = playerWizard.AC;
		}
		else if (i == 4) {
			cout << "ERROR: Invalid class! Program crashing..." << endl;
			abort();
		}
	}
	cout << "Alright " << playerName << ", you're all set to play!" << endl;
}
void welcome() {
	cout << endl;
	cout << "Please enter your name." << endl;
	cin >> playerName;
	cout << "Do you want to go by " << playerName << "? (Yes, No)" << endl;
	cin >> answer;
	try
	{
		if (answer == "Yes") {
			cout << "Alright, thanks for playing " << playerName << "!" << endl;
			cout << "Next, you'll need to create a character." << endl;
			buildNewCharacter();
		}
		if (answer == "No") {
			welcome();
		}
		else if (answer != "Yes" && answer != "No") {
			throw 1;
		}
	}
	catch (int i)
	{
		cout << "ERROR: Invalid answer." << endl;
		welcome();
	}
}
void mainMenu() {
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "MAIN MENU" << endl;
	cout << "What would you like to do?" << endl;
	cout << "Save and Exit | Play | Build New Character | View Stats | Level Up Character | Reset Save" << endl;
	getline(cin, answer);
	try
	{
		if (answer == "Save and Exit") {
			cout << endl;
			cout << endl;
			std::cout << "Saving progress..." << endl;																
			outFile.open("Save File.txt");																			
			outFile.clear();
			outFile << "0" << endl;
			outFile << playerName << endl;
			outFile << XP << endl;
			outFile << battlesPlayed << endl;
			outFile << battlesWon << endl;
			outFile << battlesLost << endl;
			outFile << charClass << endl;
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
				if (i == 1) {
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
				if (i == 2) {
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
				if (i == 3) {
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
				else if (i == 4) {
					cout << "ERROR: Invalid class!" << endl;
					outFile.close();
					mainMenu();
				}
			}
			outFile.close();
			cout << "Save complete!" << endl;
			cout << "Play again soon!" << endl;
			saving = true;
			return;
		}
		else if (answer == "Play") {
			cout << endl;
			cout << "Preparing to battle..." << endl;
			cout << "First, please select your opponent:" << endl;
			cout << "Knight | Archer | Wizard" << endl;
			cin >> answer;
			cout << "Creating character stats..." << endl;
			try
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
			catch (int i)
			{
				if (i == 1) {
					cout << "Are you sure you want to fight a knight? (Yes, No)" << endl;
					cin >> answer;
					try
					{
						if (answer == "Yes") {
							enemyClass = 'k';
						}
						if (answer == "No") {
							mainMenu();
						}
						else if (answer != "Yes" && answer != "No") {
							throw 1;
						}
					}
					catch (int j)
					{
						cout << "ERROR: Invalid answer." << endl;
						mainMenu();
					}
				}
				if (i == 2) {
					cout << "Are you sure you want to fight an archer? (Yes, No)" << endl;
					cin >> answer;
					try
					{
						if (answer == "Yes") {
							enemyClass = 'a';
						}
						if (answer == "No") {
							mainMenu();
						}
						else if (answer != "Yes" && answer != "No") {
							throw 1;
						}
					}
					catch (int j)
					{
						cout << "ERROR: Invalid answer." << endl;
						mainMenu();
					}
				}
				if (i == 3) {
					cout << "Are you sure you want to fight a wizard? (Yes, No)" << endl;
					cin >> answer;
					try
					{
						if (answer == "Yes") {
							enemyClass = 'w';
						}
						if (answer == "No") {
							mainMenu();
						}
						else if (answer != "Yes" && answer != "No") {
							throw 1;
						}
					}
					catch (int j)
					{
						cout << "ERROR: Invalid answer." << endl;
						mainMenu();
					}
				}
				else if (i == 4) {
					cout << "ERROR: Invalid answer." << endl;
					buildNewCharacter();
				}
			}
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
				if (i == 1) {
					enemyKnight.str = ((enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6()) - 10) / 2;
					enemyKnight.dex = ((enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6()) - 10) / 2;
					enemyKnight.con = ((enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6()) - 10) / 2;
					enemyKnight.inT = ((enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6()) - 10) / 2;
					enemyKnight.wis = ((enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6()) - 10) / 2;
					enemyKnight.cha = ((enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6() + enemyKnight.rollD6()) - 10) / 2;
					enemyKnight.lvl = 1;
					enemyKnight.name = "Enemy";//FIX ME
					enemyKnight.maxHP = (enemyKnight.con + 8) * enemyKnight.lvl;
					enemyKnight.hp = enemyKnight.maxHP;
					enemyKnight.AC = 11 + enemyKnight.dex + 3;
					enemyKnight.modAC = enemyKnight.AC;
				}
				if (i == 2) {
					enemyArcher.str = ((enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6()) - 10) / 2;
					enemyArcher.dex = ((enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6()) - 10) / 2;
					enemyArcher.con = ((enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6()) - 10) / 2;
					enemyArcher.inT = ((enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6()) - 10) / 2;
					enemyArcher.wis = ((enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6()) - 10) / 2;
					enemyArcher.cha = ((enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6() + enemyArcher.rollD6()) - 10) / 2;
					enemyArcher.lvl = 1;
					enemyArcher.name = "Enemy";//FIX ME
					enemyArcher.maxHP = (enemyArcher.con + 8) * enemyArcher.lvl;
					enemyArcher.hp = enemyArcher.maxHP;
					enemyArcher.AC = 11 + enemyArcher.dex + 3;
					enemyArcher.modAC = enemyArcher.AC;
				}
				if (i == 3) {
					enemyWizard.str = ((enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6()) - 10) / 2;
					enemyWizard.dex = ((enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6()) - 10) / 2;
					enemyWizard.con = ((enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6()) - 10) / 2;
					enemyWizard.inT = ((enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6()) - 10) / 2;
					enemyWizard.wis = ((enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6()) - 10) / 2;
					enemyWizard.cha = ((enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6() + enemyWizard.rollD6()) - 10) / 2;
					enemyWizard.lvl = 1;
					enemyWizard.name = "Enemy";//FIX ME
					enemyWizard.maxHP = (enemyWizard.con + 8) * enemyWizard.lvl;
					enemyWizard.hp = enemyWizard.maxHP;
					enemyWizard.AC = 11 + enemyWizard.dex + 3;
					enemyWizard.modAC = enemyWizard.AC;
				}
				else if (i == 4) {
					cout << "ERROR: Invalid class! Program crashing..." << endl;
					abort();
				}
			}
			cout << "Your opponent is ready!" << endl;
			cout << "Let the battle begin!" << endl;
			return;
		}
		else if (answer == "Build New Character") {
			cout << "Creating a new character will erase your old character, are you sure?" << endl;
			cin >> answer;
			try
			{
				if (answer == "Yes") {
					cout << "Building new character..." << endl;
					buildNewCharacter();
				}
				if (answer == "No") {
					mainMenu();
				}
				else if (answer != "Yes" && answer != "No") {
					throw 1;
				}
			}
			catch (int i)
			{
				cout << "ERROR: Invalid answer." << endl;
				mainMenu();
			}
			mainMenu();
		}
		else if (answer == "View Stats") {
			cout << endl;
			cout << "Here are your current stats for Fight the Knight:" << endl;
			cout << "Player's Name: " << playerName << endl;
			cout << "Experience: " << XP << endl;
			cout << "Battles Played: " << battlesPlayed << endl;
			cout << "Battles Won: " << battlesWon << endl;
			cout << "Battles Lost: " << battlesLost << endl;
			cout << endl;
			cout << "Character stats:" << endl;
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
				if (i == 1) {
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
				if (i == 2) {
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
				if (i == 3) {
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
				else if (i == 4) {
					cout << "ERROR: Invalid class!" << endl;
					mainMenu();
				}
			}
			mainMenu();
		}
		else if (answer == "Level Up Character") {
			cout << "Here are the current stats for your character:" << endl;
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
				if (i == 1) {
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
				if (i == 2) {
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
				if (i == 3) {
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
				else if (i == 4) {
					cout << "ERROR: Invalid class!" << endl;
					mainMenu();
				}
			}
			cout << endl;
			cout << "Which stat would you like to upgrade?" << endl;
			cout << "Strength | Dexterity | Constitution | Intelligence | Wisdom | Charisma" << endl;
			cin >> answer;
			try
			{
				if (XP <= 5) {
					throw 2;
				}
				else if (answer == "Strength") {
					cout << "Are you sure you want to spend 5 XP on upgrading strength?" << endl;
					cin >> answer;
					try
					{
						if (answer == "Yes") {
							cout << "Upgrading..." << endl;
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
								if (i == 1) {
									playerKnight.str++;
									playerKnight.lvl++;
									playerKnight.maxHP += playerKnight.rollD8();
									XP -= 5;
									cout << "Strength Upgraded to " << playerKnight.str << endl;
									mainMenu();
								}
								if (i == 2) {
									playerArcher.str++;
									playerArcher.lvl++;
									playerArcher.maxHP += playerArcher.rollD8();
									XP -= 5;
									cout << "Strength Upgraded to " << playerArcher.str << endl;
									mainMenu();
								}
								if (i == 3) {
									playerWizard.str++;
									playerWizard.lvl++;
									playerWizard.maxHP += playerWizard.rollD8();
									XP -= 5;
									cout << "Strength Upgraded to " << playerWizard.str << endl;
									mainMenu();
								}
								else if (i == 4) {
									cout << "ERROR: Invalid class!" << endl;
									mainMenu();
								}
							}
						}
						if (answer == "No") {
							mainMenu();
						}
						else if (answer != "Yes" && answer != "No") {
							throw 1;
						}
					}
					catch (int i)
					{
						cout << "ERROR: Invalid answer." << endl;
						mainMenu();
					}
				}
				else if (answer == "Dexterity") {
					cout << "Are you sure you want to spend 5 XP on upgrading dexterity?" << endl;
					cin >> answer;
					try
					{
						if (answer == "Yes") {
							cout << "Upgrading..." << endl;
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
								if (i == 1) {
									playerKnight.dex++;
									playerKnight.lvl++;
									playerKnight.maxHP += playerKnight.rollD8();
									XP -= 5;
									cout << "Dexterity Upgraded to " << playerKnight.dex << endl;
									mainMenu();
								}
								if (i == 2) {
									playerArcher.dex++;
									playerArcher.lvl++;
									playerArcher.maxHP += playerArcher.rollD8();
									XP -= 5;
									cout << "Dexterity Upgraded to " << playerArcher.dex << endl;
									mainMenu();
								}
								if (i == 3) {
									playerWizard.dex++;
									playerWizard.lvl++;
									playerWizard.maxHP += playerWizard.rollD8();
									XP -= 5;
									cout << "Dexterity Upgraded to " << playerWizard.dex << endl;
									mainMenu();
								}
								else if (i == 4) {
									cout << "ERROR: Invalid class!" << endl;
									mainMenu();
								}
							}
						}
						if (answer == "No") {
							mainMenu();
						}
						else if (answer != "Yes" && answer != "No") {
							throw 1;
						}
					}
					catch (int i)
					{
						cout << "ERROR: Invalid answer." << endl;
						mainMenu();
					}
				}
				else if (answer == "Constitution") {
				cout << "Are you sure you want to spend 5 XP on upgrading constitution?" << endl;
				cin >> answer;
				try
				{
					if (answer == "Yes") {
						cout << "Upgrading..." << endl;
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
							if (i == 1) {
								playerKnight.con++;
								playerKnight.lvl++;
								playerKnight.maxHP += playerKnight.rollD8();
								XP -= 5;
								cout << "Constitution Upgraded to " << playerKnight.con << endl;
								mainMenu();
							}
							if (i == 2) {
								playerArcher.con++;
								playerArcher.lvl++;
								playerArcher.maxHP += playerArcher.rollD8();
								XP -= 5;
								cout << "Constitution Upgraded to " << playerArcher.con << endl;
								mainMenu();
							}
							if (i == 3) {
								playerWizard.con++;
								playerWizard.lvl++;
								playerWizard.maxHP += playerWizard.rollD8();
								XP -= 5;
								cout << "Constitution Upgraded to " << playerWizard.con << endl;
								mainMenu();
							}
							else if (i == 4) {
								cout << "ERROR: Invalid class!" << endl;
								mainMenu();
							}
						}
					}
					if (answer == "No") {
						mainMenu();
					}
					else if (answer != "Yes" && answer != "No") {
						throw 1;
					}
				}
				catch (int i)
				{
					cout << "ERROR: Invalid answer." << endl;
					mainMenu();
				}
				}
				else if (answer == "Intelligence") {
				cout << "Are you sure you want to spend 5 XP on upgrading intelligence?" << endl;
				cin >> answer;
				try
				{
					if (answer == "Yes") {
						cout << "Upgrading..." << endl;
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
							if (i == 1) {
								playerKnight.inT++;
								playerKnight.lvl++;
								playerKnight.maxHP += playerKnight.rollD8();
								XP -= 5;
								cout << "Intelligence Upgraded to " << playerKnight.inT << endl;
								mainMenu();
							}
							if (i == 2) {
								playerArcher.inT++;
								playerArcher.lvl++;
								playerArcher.maxHP += playerArcher.rollD8();
								XP -= 5;
								cout << "Intelligence Upgraded to " << playerArcher.inT << endl;
								mainMenu();
							}
							if (i == 3) {
								playerWizard.inT++;
								playerWizard.lvl++;
								playerWizard.maxHP += playerWizard.rollD8();
								XP -= 5;
								cout << "Intelligence Upgraded to " << playerWizard.inT << endl;
								mainMenu();
							}
							else if (i == 4) {
								cout << "ERROR: Invalid class!" << endl;
								mainMenu();
							}
						}
					}
					if (answer == "No") {
						mainMenu();
					}
					else if (answer != "Yes" && answer != "No") {
						throw 1;
					}
				}
				catch (int i)
				{
					cout << "ERROR: Invalid answer." << endl;
					mainMenu();
				}
				}
				else if (answer == "Wisdom") {
				cout << "Are you sure you want to spend 5 XP on upgrading wisdom?" << endl;
				cin >> answer;
				try
				{
					if (answer == "Yes") {
						cout << "Upgrading..." << endl;
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
							if (i == 1) {
								playerKnight.wis++;
								playerKnight.lvl++;
								playerKnight.maxHP += playerKnight.rollD8();
								XP -= 5;
								cout << "Wisdom Upgraded to " << playerKnight.wis << endl;
								mainMenu();
							}
							if (i == 2) {
								playerArcher.wis++;
								playerArcher.lvl++;
								playerArcher.maxHP += playerArcher.rollD8();
								XP -= 5;
								cout << "Wisdom Upgraded to " << playerArcher.wis << endl;
								mainMenu();
							}
							if (i == 3) {
								playerWizard.wis++;
								playerWizard.lvl++;
								playerWizard.maxHP += playerWizard.rollD8();
								XP -= 5;
								cout << "Wisdom Upgraded to " << playerWizard.wis << endl;
								mainMenu();
							}
							else if (i == 4) {
								cout << "ERROR: Invalid class!" << endl;
								mainMenu();
							}
						}
					}
					if (answer == "No") {
						mainMenu();
					}
					else if (answer != "Yes" && answer != "No") {
						throw 1;
					}
				}
				catch (int i)
				{
					cout << "ERROR: Invalid answer." << endl;
					mainMenu();
				}
				}
				else if (answer == "Charisma") {
				cout << "Are you sure you want to spend 5 XP on upgrading charisma?" << endl;
				cin >> answer;
				try
				{
					if (answer == "Yes") {
						cout << "Upgrading..." << endl;
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
							if (i == 1) {
								playerKnight.cha++;
								playerKnight.lvl++;
								playerKnight.maxHP += playerKnight.rollD8();
								XP -= 5;
								cout << "Charisma Upgraded to " << playerKnight.cha << endl;
								mainMenu();
							}
							if (i == 2) {
								playerArcher.cha++;
								playerArcher.lvl++;
								playerArcher.maxHP += playerArcher.rollD8();
								XP -= 5;
								cout << "Charisma Upgraded to " << playerArcher.cha << endl;
								mainMenu();
							}
							if (i == 3) {
								playerWizard.cha++;
								playerWizard.lvl++;
								playerWizard.maxHP += playerWizard.rollD8();
								XP -= 5;
								cout << "Charisma Upgraded to " << playerWizard.cha << endl;
								mainMenu();
							}
							else if (i == 4) {
								cout << "ERROR: Invalid class!" << endl;
								mainMenu();
							}
						}
					}
					if (answer == "No") {
						mainMenu();
					}
					else if (answer != "Yes" && answer != "No") {
						throw 1;
					}
				}
				catch (int i)
				{
					cout << "ERROR: Invalid answer." << endl;
					mainMenu();
				}
				}
				else if (answer != "Strength" && answer != "Dexterity" && answer != "Constitution" && answer != "Intelligence" && answer != "Wisdom" && answer != "Charisma") {
					throw 1;
				}
			}
			catch (int i)
			{
				if (i == 1) {
					cout << "ERROR: Invalid answer" << endl;
					mainMenu();
				}
				else if (i == 2) {
					cout << "You don't have enough XP to upgrade your character!" << endl;
					mainMenu();
				}
			}
		}
		else if (answer == "Reset Save") {
		cout << "WARNING: Are you sure you want to reset your save progress? (It will not be recoverable)" << endl;
		cin >> answer;
		try
		{
			if (answer == "Yes") {
				cout << "Resetting..." << endl;
				outFile.open("Save File.txt");
				outFile.clear();
				saving = true;
				return;
			}
			else if (answer == "No") {
				mainMenu();
			}
			else if (answer != "Yes" && answer != "No") {
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
		else if (answer != "Save and Exit" && answer != "Play" && answer != "Build New Character" && answer != "View Stats" && answer != "Level Up Character") {
			throw 5;
		}
	}
	catch (int i)
	{
		if (i == 5) {
			cout << "ERROR: Invalid answer" << endl;
			mainMenu();
		}
	}
}
void checkBattleEnd() {
	try
	{
		if (charClass == 'k' && enemyClass == 'k') {
			if (playerKnight.hp <= 0) {
				cout << playerKnight.name << " fainted from exhaustion!" << endl;
				cout << playerName << " lost the fight!" << endl;
				battlesPlayed += 1;
				battlesLost += 1;
				playerKnight.hp = playerKnight.maxHP;
				XP++;
				mainMenu();
			}
			else if (enemyKnight.hp <= 0) {
				cout << enemyKnight.name << " fainted from exhaustion!" << endl;
				cout << playerName << " won the fight!" << endl;
				battlesPlayed++;
				battlesWon++;
				playerKnight.hp = playerKnight.maxHP;
				XP += 3;
				mainMenu();
			}
		}
		else if (charClass == 'k' && enemyClass == 'a') {
			if (playerKnight.hp <= 0) {
				cout << playerKnight.name << " fainted from exhaustion!" << endl;
				cout << playerName << " lost the fight!" << endl;
				battlesPlayed += 1;
				battlesLost += 1;
				playerKnight.hp = playerKnight.maxHP;
				XP++;
				mainMenu();
			}
			else if (enemyArcher.hp <= 0) {
				cout << enemyArcher.name << " fainted from exhaustion!" << endl;
				cout << playerName << " won the fight!" << endl;
				battlesPlayed++;
				battlesWon++;
				playerKnight.hp = playerKnight.maxHP;
				XP += 3;
				mainMenu();
			}
		}
		else if (charClass == 'k' && enemyClass == 'w') {
			if (playerKnight.hp <= 0) {
				cout << playerKnight.name << " fainted from exhaustion!" << endl;
				cout << playerName << " lost the fight!" << endl;
				battlesPlayed += 1;
				battlesLost += 1;
				playerKnight.hp = playerKnight.maxHP;
				XP++;
				mainMenu();
			}
			else if (enemyWizard.hp <= 0) {
				cout << enemyWizard.name << " fainted from exhaustion!" << endl;
				cout << playerName << " won the fight!" << endl;
				battlesPlayed++;
				battlesWon++;
				playerKnight.hp = playerKnight.maxHP;
				XP += 3;
				mainMenu();
			}
		}
		else if (charClass == 'a' && enemyClass == 'k') {
			if (playerArcher.hp <= 0) {
				cout << playerArcher.name << " fainted from exhaustion!" << endl;
				cout << playerName << " lost the fight!" << endl;
				battlesPlayed += 1;
				battlesLost += 1;
				playerArcher.hp = playerArcher.maxHP;
				XP++;
				mainMenu();
			}
			else if (enemyKnight.hp <= 0) {
				cout << enemyKnight.name << " fainted from exhaustion!" << endl;
				cout << playerName << " won the fight!" << endl;
				battlesPlayed++;
				battlesWon++;
				playerArcher.hp = playerArcher.maxHP;
				XP += 3;
				mainMenu();
			}
		}
		else if (charClass == 'a' && enemyClass == 'a') {
			if (playerArcher.hp <= 0) {
				cout << playerArcher.name << " fainted from exhaustion!" << endl;
				cout << playerName << " lost the fight!" << endl;
				battlesPlayed += 1;
				battlesLost += 1;
				playerArcher.hp = playerArcher.maxHP;
				XP++;
				mainMenu();
			}
			else if (enemyArcher.hp <= 0) {
				cout << enemyArcher.name << " fainted from exhaustion!" << endl;
				cout << playerName << " won the fight!" << endl;
				battlesPlayed++;
				battlesWon++;
				playerArcher.hp = playerArcher.maxHP;
				XP += 3;
				mainMenu();
			}
		}
		else if (charClass == 'a' && enemyClass == 'w') {
		if (playerArcher.hp <= 0) {
			cout << playerArcher.name << " fainted from exhaustion!" << endl;
			cout << playerName << " lost the fight!" << endl;
			battlesPlayed += 1;
			battlesLost += 1;
			playerArcher.hp = playerArcher.maxHP;
			XP++;
			mainMenu();
		}
		else if (enemyWizard.hp <= 0) {
			cout << enemyWizard.name << " fainted from exhaustion!" << endl;
			cout << playerName << " won the fight!" << endl;
			battlesPlayed++;
			battlesWon++;
			playerArcher.hp = playerArcher.maxHP;
			XP += 3;
			mainMenu();
		}
		}
		else if (charClass == 'w' && enemyClass == 'k') {
		if (playerWizard.hp <= 0) {
			cout << playerWizard.name << " fainted from exhaustion!" << endl;
			cout << playerName << " lost the fight!" << endl;
			battlesPlayed += 1;
			battlesLost += 1;
			playerWizard.hp = playerWizard.maxHP;
			XP++;
			mainMenu();
		}
		else if (enemyKnight.hp <= 0) {
			cout << enemyKnight.name << " fainted from exhaustion!" << endl;
			cout << playerName << " won the fight!" << endl;
			battlesPlayed++;
			battlesWon++;
			playerWizard.hp = playerWizard.maxHP;
			XP += 3;
			mainMenu();
		}
		}
		else if (charClass == 'w' && enemyClass == 'a') {
		if (playerWizard.hp <= 0) {
			cout << playerWizard.name << " fainted from exhaustion!" << endl;
			cout << playerName << " lost the fight!" << endl;
			battlesPlayed += 1;
			battlesLost += 1;
			playerWizard.hp = playerWizard.maxHP;
			XP++;
			mainMenu();
		}
		else if (enemyArcher.hp <= 0) {
			cout << enemyArcher.name << " fainted from exhaustion!" << endl;
			cout << playerName << " won the fight!" << endl;
			battlesPlayed++;
			battlesWon++;
			playerWizard.hp = playerWizard.maxHP;
			XP += 3;
			mainMenu();
		}
		}
		else if (charClass == 'w' && enemyClass == 'w') {
		if (playerWizard.hp <= 0) {
			cout << playerWizard.name << " fainted from exhaustion!" << endl;
			cout << playerName << " lost the fight!" << endl;
			battlesPlayed += 1;
			battlesLost += 1;
			playerWizard.hp = playerWizard.maxHP;
			XP++;
			mainMenu();
		}
		else if (enemyWizard.hp <= 0) {
			cout << enemyWizard.name << " fainted from exhaustion!" << endl;
			cout << playerName << " won the fight!" << endl;
			battlesPlayed++;
			battlesWon++;
			playerWizard.hp = playerWizard.maxHP;
			XP += 3;
			mainMenu();
		}
		}
		else if (charClass != 'k' && charClass != 'a' && charClass != 'w' && enemyClass == 'k' && enemyClass == 'a' && enemyClass == 'w') {
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
void battlekk() {
	cout << endl;
	cout << playerName << endl;
	cout << "HP: " << playerKnight.hp << "/" << playerKnight.maxHP << endl;
	cout << "AC: " << playerKnight.modAC << "/" << playerKnight.AC << endl;
	cout << endl;
	cout << enemyKnight.name << endl;
	cout << "HP: " << enemyKnight.hp << "/" << enemyKnight.maxHP << endl;
	cout << "AC: " << enemyKnight.modAC << "/" << enemyKnight.AC << endl;
	if (playerKnight.dex > enemyKnight.dex) {
		playerKnight.modAC = playerKnight.AC;
		enemyKnight.modAC = enemyKnight.AC;
		cout << endl;
		cout << playerKnight.name << " speeds ahead of their opponent..." << endl;
		cout << endl;
		cout << "What move would you like to use?" << endl;
		cout << "Move List:" << endl;
		cout << "Dodge: Get a bonus to AC as you attempt to dodge your opponent's next attack." << endl;
		cout << "Taunt: Lower the enemy's AC using Intelligence, Wisdom, or Charisma." << endl;
		cout << "Slash Attack: A basic slashing attack." << endl;
		cout << "Stab Attack: A basic stab attack." << endl;
		cout << "Block: Use your shield to help block attacks!" << endl;
		getline(cin, answer);
		try
		{
			if (answer == "Dodge") {
				playerKnight.dodge();
			}
			else if (answer == "Taunt") {
				enemyKnight.modAC -= playerKnight.taunt(enemyKnight.inT, enemyKnight.wis, enemyKnight.cha);
			}
			else if (answer == "Slash Attack") {
				enemyKnight.hp -= playerKnight.slashAttack(enemyKnight.modAC);
				checkBattleEnd();
			}
			else if (answer == "Stab Attack") {
				enemyKnight.hp -= playerKnight.stabAttack(enemyKnight.modAC);
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
				battlekk();
			}
		}

		

		cout << endl;
		cout << endl;
		int enemyMove = rand() % 5 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyKnight.dodge();
			}
			else if (enemyMove == 2) {
				playerKnight.modAC -= enemyKnight.taunt(playerKnight.inT, playerKnight.wis, playerKnight.cha);
			}
			else if (enemyMove == 3) {
				playerKnight.hp -= enemyKnight.slashAttack(playerKnight.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 4) {
				playerKnight.hp -= enemyKnight.stabAttack(playerKnight.modAC);
				checkBattleEnd();
			}
			else if (enemyMove) {
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
				battlekk();
			}
		}
	}
	else if (enemyKnight.dex >= playerKnight.dex) {
		cout << endl;
		cout << enemyKnight.name << " speeds ahead of " << playerKnight.name << "..." << endl;
		cout << endl;
		int enemyMove = rand() % 5 + 1;
		try
		{
			if (enemyMove == 1) {
				enemyKnight.dodge();
			}
			else if (enemyMove == 2) {
				playerKnight.modAC -= enemyKnight.taunt(playerKnight.inT, playerKnight.wis, playerKnight.cha);
			}
			else if (enemyMove == 3) {
				playerKnight.hp -= enemyKnight.slashAttack(playerKnight.modAC);
				checkBattleEnd();
			}
			else if (enemyMove == 4) {
				playerKnight.hp -= enemyKnight.stabAttack(playerKnight.modAC);
				checkBattleEnd();
			}
			else if (enemyMove) {
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
				battlekk();
			}
		}



		playerKnight.modAC = playerKnight.AC;
		enemyKnight.modAC = enemyKnight.AC;
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
		try
		{
			if (answer == "Dodge") {
				playerKnight.dodge();
			}
			else if (answer == "Taunt") {
				enemyKnight.modAC -= playerKnight.taunt(enemyKnight.inT, enemyKnight.wis, enemyKnight.cha);
			}
			else if (answer == "Slash Attack") {
				enemyKnight.hp -= playerKnight.slashAttack(enemyKnight.modAC);
				checkBattleEnd();
			}
			else if (answer == "Stab Attack") {
				enemyKnight.hp -= playerKnight.stabAttack(enemyKnight.modAC);
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
				battlekk();
			}
		}
	}
	battlekk();
}
void battleka() {

}
void battlekw() {

}
void battleak() {

}
void battleaa() {

}
void battleaw() {

}
void battlewk() {

}
void battlewa() {

}
void battleww() {

}
void battleStart() {
	try
	{
		if (charClass == 'k' && enemyClass == 'k') {
			playerKnight.hp = playerKnight.maxHP;
			battlekk();
		}
		else if (charClass == 'k' && enemyClass == 'a') {
			playerKnight.hp = playerKnight.maxHP;
			battleka();
		}
		else if (charClass == 'k' && enemyClass == 'w') {
			playerKnight.hp = playerKnight.maxHP;
			battlekw();
		}
		else if (charClass == 'a' && enemyClass == 'k') {
			playerArcher.hp = playerArcher.maxHP;
			battleak();
		}
		else if (charClass == 'a' && enemyClass == 'a') {
			playerArcher.hp = playerArcher.maxHP;
			battleaa();
		}
		else if (charClass == 'a' && enemyClass == 'w') {
			playerArcher.hp = playerArcher.maxHP;
			battleaw();
		}
		else if (charClass == 'w' && enemyClass == 'k') {
			playerWizard.hp = playerWizard.maxHP;
			battlewk();
		}
		else if (charClass == 'w' && enemyClass == 'a') {
			playerWizard.hp = playerWizard.maxHP;
			battlewa();
		}
		else if (charClass == 'w' && enemyClass == 'w') {
			playerWizard.hp = playerWizard.maxHP;
			battleww();
		}
		else if (charClass != 'k' && charClass != 'a' && charClass != 'w' && enemyClass == 'k' && enemyClass == 'a' && enemyClass == 'w') {
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
int main() {
	srand(time(0));
	cout << "Welcome to Fight the Knight!" << endl;
	cout << "Press Enter to start" << endl;
	cin.ignore();
	cout << endl;
	cout << "Detecting save file..." << endl;
	inFile >> fileTest;
	if (fileTest == "") {
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
	else {
		cout << "Save file detected!" << endl;
		cout << "Loading save file..." << endl;
		inFile >> playerName;
		cout << "Welcome back, " << playerName << "!" << endl;
		inFile >> XP;
		inFile >> battlesPlayed;
		inFile >> battlesWon;
		inFile >> battlesLost;
		inFile >> charClass;
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
			if (i == 1) {
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
			if (i == 2) {
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
			if (i == 3) {
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
			else if (i == 4) {
				cout << "ERROR: Invalid class!" << endl;
				inFile.close();
				return 1;
			}
		}
		cout << "Save data loaded!" << endl;
		mainMenu();
		if (saving == true) {
			return 0;
		}
		battleStart();
	}
	return 0;
}