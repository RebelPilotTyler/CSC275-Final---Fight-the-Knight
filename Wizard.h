//Subclass of Character for all Wizard characters.		*Comments Here*
#pragma once											//Not sure what this line does, but it was included with the class setup wizard.
#include "Character.h"									//Includes the Character class header file.
class Wizard : public Character {						//Defines the Wizard subclass.
public:													//Declares the following objects as public and accessible by any program.
	int fireAttack(int eStr);							//Declares the fireAttack function, which takes in the enemy's strength stat and returns an integer.
	int lightningAttack(int eDex);						//Declares the lightningAttack function, which takes in the enemy's dexterity stat and returns an integer.
	int iceAttack(int eCon);							//Declares the iceAttack function, which takes in the enemy's constitution stat and returns an integer.
};

