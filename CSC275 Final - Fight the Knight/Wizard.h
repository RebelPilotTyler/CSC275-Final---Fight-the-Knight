#pragma once
#include "Character.h"
class Wizard : public Character {
	int fireAttack(int eStr);
	int lightningAttack(int eDex);
	int iceAttack(int eCon);
};

