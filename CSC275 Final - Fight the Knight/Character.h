//Header file for the Character class, which is a parent class for all the characters.		*Comments Here*
#pragma once																				//Not sure what this line does, but the class setup wizard included it.
#include <string>																			//Includes the string library, which allows for the use of strings.
using namespace std;																		//A line which prevents the programmer having to type std:: in front of all input and output statements.
class Character																				//Declares the Character class.
{
public:																						//Declares all of the following objects as public, so any function can access them.
	int str;																				//Defines the variable str, short for strength, which holds the strength stat of the character.
	int dex;																				//Defines the variable dex, short for dexterity, which holds the dexterity stat of the character.
	int con;																				//Defines the variable con, short for constitution, which holds the constitution stat of the character.
	int inT;																				//Defines the variable inT, short for intelligence, which holds the intelligence stat of the character.
	int wis;																				//Defines the variable wis, short for wisdom, which holds the wisdom stat of the character.
	int cha;																				//Defines the variable cha, short for charisma, which holds the charisma stat of the character.
	int lvl;																				//Defines the variable lvl, short for level, which holds the character's level.
	string name;																			//Defines the variable name, which holds the character's name.
	int hp;																					//Defines the variable hp, short for health points, which holds the character's current hp.
	int maxHP;																				//Defines the variable maxHP, which holds the character's max hp/
	int AC;																					//Defines the variable AC, short for armor class, which represents the character's defense. This variable holds the true value.
	int modAC;																				//Defines the variable modAC, which holds the character's ac as it is modded in combat.
	int rollD4();																			//Defines the function rollD4, which will return a random number 1-4.
	int rollD6();																			//Defines the function rollD6, which will return a random number 1-6.
	int rollD8();																			//Defines the function rollD8, which will return a random number 1-8.
	int rollD10();																			//Defines the function rollD10, which will return a random number 1-10.
	int rollD20();																			//Defines the function rollD20, which will return a random number 1-20.
	void dodge();																			//Defines the function dodge, which will make the character dodge in combat.
	int taunt(int eInt, int eWis, int eCha);												//Defines the function taunt, which will make the character taunt in combat.
};

