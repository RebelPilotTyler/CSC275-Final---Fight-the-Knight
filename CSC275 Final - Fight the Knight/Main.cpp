#include <iostream>
#include <string>
#include <fstream>
#include "Character.h"
#include "Knight.h"
#include "Archer.h"
#include "Wizard.h"
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
Character player;
Character enemy;

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
	{//FIX ME: Class Selector
		if (i == 1) {
			
		}
		if (i == 2) {
			
		}
		if (i == 3) {
			
		}
		else if (i == 4) {
			cout << "ERROR: Invalid class! Program crashing..." << endl;
			abort();
		}
	}
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
	}
	//FIX ME
	return 0;
}