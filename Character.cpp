//The source file for the Character parent class											*Comments here*
#include "Character.h"																		//Includes the Character class header file.
#include <cstdlib>																			//Includes the cstdlib library, which is needed for use of strings in classes.
#include <string>																			//Includes the string library, which is needed for use of strings.
#include <iostream>																			//Includes the iostream library, which allows for input and output to the screen.
using namespace std;																		//A line which prevents the programmer from needing to type std:: in front of each output or input statement.
int Character::rollD4()																		//Defines the Character class function rollD4, which returns a random number 1-4.
{
	return rand() % 4 + 1;
}
int Character::rollD6()																		//Defines the Character class function rollD6, which returns a random number 1-6.
{
	return rand() % 6 + 1;
}
int Character::rollD8()																		//Defines the Character class function rollD8, which returns a random number 1-8.
{
	return rand() % 8 + 1;
}
int Character::rollD10()																	//Defines the Character class function rollD10, which returns a random number 1-10.
{
	return rand() % 10 + 1;
}
int Character::rollD20()																	//Defines the Character class function rollD20, which returns a random number 1-20.
{
	return rand() % 20 + 1;
}
void Character::dodge()																		//Defines the Character class function dodge.
{
	cout << name << " is focusing on the enemy, getting ready to dodge their next attack." << endl;//Outputs "name" is focusing on the enemy, getting ready to dodge their next attack.
	modAC += rollD4() + dex;																//Changes the character's AC by a random number 1-4 + their dexterity stat.
}
int Character::taunt(int eInt, int eWis, int eCha)											//Defines the Character class function taunt, which takes in the enemy's int, wis, and cha stats.
{
	int roll;																				//A local int variable to represent a randomly generated number.
	string answer;																			//A local string variable to hold user answers.
	if (name == "Enemy") {																	//If the current class is the AI enemy...
		roll = rand() % 3 + 1;																//Set roll to a random number 1-3.
		if (roll == 1) {																	//If roll == 1...
			answer = "Int";																	//Set the answer string to "Int".
		}
		else if (roll == 2) {																//If roll == 2...
			answer = "Wis";																	//Set the answer string to "Wis".
		}
		else if (roll == 3) {																//If roll == 3...
			answer = "Cha";																	//Set the answer string to "Cha".
		}
		else if (roll != 1 && roll != 2 && roll != 3) {										//If roll is not equal to 1-3...
			cout << "ERROR: Invalid roll" << endl;											//Output "ERROR: Invalid roll"
			taunt(eInt, eWis, eCha);														//Restart the taunt function.
		}
	}
	else																					//If the current class is the player...
	{
		cout << "Which stat do you want to use for your taunt? (Int, Wis, Cha)" << endl;	//Outputs "Which stat do you want to use for your taunt? (Int, Wis, Cha)"
		cin >> answer;																		//Lets the user input their answer.
	}
	try																						//Sets up a try/catch statement in case of errors.
	{
		if (answer == "Int") {																//If answer == "Int"...
			throw 1;																		//Throw error 1, which won't actually be an error.
		}
		else if (answer == "Wis") {															//If answer == "Wis"...
			throw 2;																		//Throw error 2, which won't actually be an error.
		}
		else if (answer == "Cha") {															//If answer == "Cha"...
			throw 3;																		//Throw error 3, which won't actually be an error.
		}
		else if (answer != "Int" && answer != "Wis" && answer != "Cha") {					//If answer is not equal to any of the above...
			throw 4;																		//Throw error 4.
		}
	}
	catch (int i)																			//The catch code block to catch the thrown errors, which will be stored in integer i.
	{
		if (i == 1) {																		//If i == 1, meaning if the user answered Int...
			cout << name << " asked the enemy a question, hoping to make them doubt everything they knew..." << endl;//Outputs "name" asked the enemy a question, hoping to make them doubt everything they knew...
			int roll;																		//A variable to represent a randomly generated number.
			int enemyRoll;																	//A variable to represent a randomly generated number for the enemy.
			roll = rollD20() + inT;															//Set roll to a random number 1-20 + this character's intelligence stat.
			enemyRoll = rollD20() + eInt;													//Set enemyRoll to a random number 1-20 + the enemy's intelligence stat.
			try																				//Set up another try/catch code block in case of errors.
			{																				
				if (roll > enemyRoll) {														//If this character got a random number higher than that of the enemy...
					throw 1;																//Throw error 1, which won't actually be an error.
				}
				else if (roll <= enemyRoll) {												//If the enemy got a higher roll than this character...
					throw 2;																//Throw error 2, which won't actually be an error.
				}
			}
			catch (int j)																	//The catch code block for catching errors, which will be stored in integer j.
			{
				if (j == 1) {																//If j == 1, meaning this character got the higher roll...
					cout << "The enemy's mind was blown!" << endl;							//Outputs The enemy's mind was blown!
					return rollD4();														//Return a random number 1-4, which will be subtracted from the enemy's AC.
				}
				else if (j == 2) {															//If j == 2, meaning the enemy got the higher roll...
					cout << "The enemy wasn't affected..." << endl;							//Outputs The enemy wasn't affected...
					return 0;																//Return 0, which means that nothing will happen.
				}
			}
		}
		if (i == 2) {																		//If i == 2, meaning if the user answered Wis...
			cout << name << " tested the enemy's knowledge with an amazing fact!" << endl;	//Outputs "name" tested the enemy's knowledge with an amazing fact!
			int roll;																		//A variable that will represent a random number.
			int enemyRoll;																	//A variable that will represent a random number for the enemy.
			roll = rollD20() + wis;															//Set roll to a random number 1-20 + this character's wisdom stat.
			enemyRoll = rollD20() + eWis;													//Set enemyRoll to a random number 1-20 + the enemy's wisdom stat.
			try																				//Sets up a try/catch code block in case of errors.
			{
				if (roll > enemyRoll) {														//If this character got a higher random number than the enemy...
					throw 1;																//Throw error 1, which won't actually be an error.
				}
				else if (roll <= enemyRoll) {												//If the enemy got a higher random number than this character...
					throw 2;																//Throw error 2, which won't actually be an error.
				}
			}
			catch (int j)																	//The catch code block for catching errors, which will be stored in integer j.
			{
				if (j == 1) {																//If j == 1, meaning if this character got the higher number...
					cout << "The enemy's mind was blown!" << endl;							//Outputs The enemy's mind was blown!
					return rollD4();														//Return a random number 1-4, which will be subtracted from the enemy's AC.
				}
				else if (j == 2) {															//If j == 2, meaning if the enemy got the higher number...
					cout << "The enemy wasn't affected..." << endl;							//Outputs The enemy wasn't affected...
					return 0;																//Return 0, so that nothing will happen.
				}
			}
		}
		if (i == 3) {																		//If i == 3, meaning if the user answered Cha...
			cout << name << " told the enemy a hilarious joke!" << endl;					//Outputs "name" told the enemy a hilarious joke!
			int roll;																		//A variable to store a random number.
			int enemyRoll;																	//A variable to store a random number for the enemy.
			roll = rollD20() + cha;															//Set roll to a random number 1-20 + this character's charisma stat.
			enemyRoll = rollD20() + eCha;													//Set enemyRoll to a random number 1-20 + the enemy's charisma stat.
			try																				//Sets up a try/catch code block in case of errors.
			{
				if (roll > enemyRoll) {														//If this character got a higher random number than the enemy...
					throw 1;																//Throw error 1, which won't actually be an error.
				}
				else if (roll <= enemyRoll) {												//If the enemy got a higher random number than this character...
					throw 2;																//Throw error 2, which won't actually be an error.
				}
			}
			catch (int j)																	//Catch code block for catching errors, which will be stored in integer j.
			{
				if (j == 1) {																//If j == 1, meaning this character got the higher roll...
					cout << "The enemy bent over and laughed hysterically!" << endl;		//Outputs The enemy bent over and laughed hysterically!
					return rollD4();														//Return a random number 1-4, which will be subtracted from the enemy's AC.
				}
				else if (j == 2) {															//If j == 2, meaning the enemy got the higher roll...
					cout << "The enemy wasn't affected..." << endl;							//Outputs The enemy wasn't affected...
					return 0;																//Return 0, so that nothing will happen.
				}
			}
		}
		else if (i == 4) {																	//If the user did not answer Int, Wis, or Cha...
			cout << "ERROR: Invalid Answer." << endl;										//Outputs ERROR: Invalid Answer.
			taunt(eInt, eWis, eCha);														//Recalls the taunt function
		}
	}
}