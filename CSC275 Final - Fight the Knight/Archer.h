//Subclass of Character class for Archer characters.	*Comments Here*
#pragma once											//Not sure what this line does, but it was included with the setup wizard.
#include "Character.h"									//Includes the Character class header file.
class Archer : public Character {						//Defines the Archer subclass.
public:													//Declares the following objects as public and accessible by any program.
	int quickShotAttack(int enemyAC);					//Declares the function quickShotAttack, which takes in the enemy's AC and returns an integer.
	int powerShotAttack(int enemyAC);					//Declares the function powerShotAttack, which takes in the enemy's AC and returns an integer.
	int hide(int eWis);									//Declares the function hide, which takes in the enemy's wisdom stat and returns an integer.
};

