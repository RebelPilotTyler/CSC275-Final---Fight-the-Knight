#pragma once
#include "Character.h"
class Wizard : public Character {
public:
	int fireAttack(int eStr);
	int lightningAttack(int eDex);
	int iceAttack(int eCon);
};

