#include "Character.h"
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
int Character::rollD4()
{
	return rand() % 4 + 1;
}
int Character::rollD6()
{
	return rand() % 6 + 1;
}
int Character::rollD8()
{
	return rand() % 8 + 1;
}
int Character::rollD10()
{
	return rand() % 10 + 1;
}
int Character::rollD20()
{
	return rand() % 20 + 1;
}
void Character::dodge()
{
	cout << name << " is focusing on the enemy, getting ready to dodge their next attack." << endl;
	modAC += rollD4() + dex;
}
int Character::taunt(int eInt, int eWis, int eCha)
{
	cout << "Which stat do you want to use for your taunt? (Int, Wis, Cha)" << endl;
	string answer;
	cin >> answer;
	try
	{
		if (answer == "Int") {
			throw 1;
		}
		else if (answer == "Wis") {
			throw 2;
		}
		else if (answer == "Cha") {
			throw 3;
		}
		else if (answer != "Int" && answer != "Wis" && answer != "Cha") {
			throw 4;
		}
	}
	catch (int i)
	{
		if (i == 1) {
			cout << name << " asked the enemy a question, hoping to make them doubt everything they knew..." << endl;
			int roll;
			int enemyRoll;
			roll = rollD20() + inT;
			enemyRoll = rollD20() + eInt;
			try
			{
				if (roll > enemyRoll) {
					throw 1;
				}
				else if (roll <= enemyRoll) {
					throw 2;
				}
			}
			catch (int j)
			{
				if (j == 1) {
					cout << "The enemy's mind was blown!" << endl;
					return rollD4();
				}
				else if (j == 2) {
					cout << "The enemy wasn't affected..." << endl;
					return 0;
				}
			}
		}
		if (i == 2) {
			cout << name << " tested the enemy's knowledge with an amazing fact!" << endl;
			int roll;
			int enemyRoll;
			roll = rollD20() + wis;
			enemyRoll = rollD20() + eWis;
			try
			{
				if (roll > enemyRoll) {
					throw 1;
				}
				else if (roll <= enemyRoll) {
					throw 2;
				}
			}
			catch (int j)
			{
				if (j == 1) {
					cout << "The enemy's mind was blown!" << endl;
					return rollD4();
				}
				else if (j == 2) {
					cout << "The enemy wasn't affected..." << endl;
					return 0;
				}
			}
		}
		if (i == 3) {
			cout << name << " told the enemy a hilarious joke!" << endl;
			int roll;
			int enemyRoll;
			roll = rollD20() + cha;
			enemyRoll = rollD20() + eCha;
			try
			{
				if (roll > enemyRoll) {
					throw 1;
				}
				else if (roll <= enemyRoll) {
					throw 2;
				}
			}
			catch (int j)
			{
				if (j == 1) {
					cout << "The enemy bent over and laughed hysterically!" << endl;
					return rollD4();
				}
				else if (j == 2) {
					cout << "The enemy wasn't affected..." << endl;
					return 0;
				}
			}
		}
		else if (i == 4) {
			cout << "ERROR: Invalid Answer." << endl;
			taunt(eInt, eWis, eCha);
		}
	}
}