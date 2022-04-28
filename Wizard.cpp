//Source code file for the Wizard subclass						*Comments Here*
#include "Wizard.h"												//Includes the Wizard class header file.
#include <iostream>												//Includes the iostream library, which allows for input and output to the screen.
#include <string>												//Includes the string library, which allows for the use of strings.
using namespace std;											//Prevents the programmer having to type std:: in front of each input and output statement.
int Wizard::fireAttack(int eStr)								//Defines the fireAttack function, which takes in the enemy's strength stat and return and integer.
{
	cout << name << " began creating a ball of fire in their hands, preparing to hurl it at the enemy..." << endl;//Outputs "name" began creating a ball of fire in their hands, preparing to hurl it at the enemy...
	int roll;													//Variable for storing a random number.
	int enemyRoll;												//Variable for storing a random number for the enemy.
	roll = rollD20() + inT;										//Set roll to a random number 1-20 + this character's intelligence stat.
	enemyRoll = rollD20() + eStr;								//Set enemyRoll to a random number 1-20 + the enemy's strength stat.
	try															//Sets up a try/catch code block in case of errors.
	{
		if (roll > enemyRoll) {									//If this character's roll is higher than the enemy's, throw error 1, which won't actually be an error.
			throw 1;
		}
		else if (roll <= enemyRoll) {							//If this character's roll is lower than the enemy's, throw error 2, which won't actually be an error.
			throw 2;
		}
	}
	catch (int j)												//Catch code block for catching errors, which will be stored in integer j.
	{
		if (j == 1) {											//If j == 1, meaning this character got the higher roll, return a number to decrease the enemy's hp.
			cout << "The enemy was scorched by fire!" << endl;
			return rollD10() + inT;
		}
		else if (j == 2) {										//If j == 2, meaning the enemy got the higher roll, do nothing.
			cout << name << "'s fireball missed!" << endl;
			return 0;
		}
	}
}
int Wizard::lightningAttack(int eDex)							//Defines the lightningAttack function, which takes in the enemy's dexterity stat and returns an integer.
{
	cout << name << " began creating a ball of electricity in their hands, preparing to hurl it at the enemy..." << endl;//Outputs "name" began creating a ball of electricity in their hands, preparing to hurl it at the enemy...
	int roll;													//Variable for storing a random number.
	int enemyRoll;												//Variable for storing a random number for the enemy.
	roll = rollD20() + wis;										//Set roll to a random number 1-20 + this character's wisdom stat.
	enemyRoll = rollD20() + eDex;								//Set enemyRoll to a random number 1-20 + the enemy's dexterity stat.
	try															//Sets up a try/catch code block in case of errors.
	{
		if (roll > enemyRoll) {									//If this character's roll is higher than the enemy's, throw error 1, which won't actually be an error.
			throw 1;
		}
		else if (roll <= enemyRoll) {							//If this character's roll is lower than the enemy's, throw error 2, which won't actually be an error.
			throw 2;
		}
	}
	catch (int j)												//Catch code block for catching errors, which will be stored in integer j.
	{
		if (j == 1) {											//If j == 1, meaning this character got the higher roll, return a number to decrease the enemy's hp.
			cout << "The enemy was shocked by electricity!" << endl;
			return rollD10() + wis;
		}
		else if (j == 2) {										//If j == 2, meaning the enemy got the higher roll, return 0 so nothing happens.
			cout << name << "'s thunderbolt missed!" << endl;
			return 0;
		}
	}
}
int Wizard::iceAttack(int eCon)									//Defines the iceAttack function which takes in the enemy's constitution stat and returns an integer.
{
	cout << name << " began creating a ball of ice in their hands, preparing to hurl it at the enemy..." << endl;//Outputs "name" began creating a ball of ice in their hands, preparing to hurl it at the enemy...
	int roll;													//Variable for storing a random number.
	int enemyRoll;												//Variable for storing a random number for the enemy.
	roll = rollD20() + cha;										//Set roll to a random number 1-20 + this character's charisma stat.
	enemyRoll = rollD20() + eCon;								//Set enemyRoll to a random number 1-20 + the enemy's constitution stat.
	try															//Sets up a try/catch code block in case of errors.
	{
		if (roll > enemyRoll) {									//If this character's roll is higher than the enemy's, throw error 1, which won't actually be an error.
			throw 1;
		}
		else if (roll <= enemyRoll) {							//If this character's roll is lower than the enemy's, throw error 2, which won't actually be an error.
			throw 2;
		}
	}
	catch (int j)												//Catch code block for catching errors, which will be stored in integer j.
	{
		if (j == 1) {											//If j == 1, meaning this character got the higher roll, return a number to decrease the enemy's hp.
			cout << "The enemy was frozen solid!" << endl;
			return rollD10() + cha;
		}
		else if (j == 2) {										//If j == 2, meaning the enemy got the higher roll, return 0 so nothing happens.
			cout << name << "'s ice attack missed!" << endl;
			return 0;
		}
	}
}