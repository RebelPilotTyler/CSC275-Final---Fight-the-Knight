//Character subclass for all Knight characters.				*Comments Here*
#pragma once												//Not sure what this line does, but it was included with the setup wizard.
#include "Character.h"										//Includes the Character class header file.
class Knight : public Character {							//Defines the Knight class, a subclass of Character.
public:														//Declares the following objects as public and accessible by any program.
	int slashAttack(int enemyAC);							//Declares the function slashAttack, which takes in the enemy's AC and outputs an integer.
	int stabAttack(int enemyAC);							//Declares the function stabAttack, which takes in the enemy's AC and outputs an integer.
	void block();											//Declares the function block.
};

