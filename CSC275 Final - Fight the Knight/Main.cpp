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
	cout << "Save and Exit | Play | Build New Character | View Stats" << endl;
	getline(cin, answer);
	try
	{
		if (answer == "Save and Exit") {
			
		}
		else if (answer == "Play") {
			
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
		else if (answer != "Save and Exit" && answer != "Play" && answer != "Build New Character" && answer != "View Stats") {
			throw 5;
		}
	}
	catch (int i)
	{
		if (i == 1) {
			//FIX ME: Save and Exit
		}
		if (i == 2) {
			//FIX ME: Start a battle
		}
		if (i == 3) {
			
		}
		if (i == 4) {
			
		}
		if (i == 5) {
			cout << "ERROR: Invalid answer" << endl;
			mainMenu();
		}
	}
}
int main() {
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
	}
	//FIX ME
	return 0;
}