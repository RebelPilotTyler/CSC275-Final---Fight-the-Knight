#pragma once
#include "Character.h"
class Archer : public Character {
public:
	int quickShotAttack(int enemyAC);
	int powerShotAttack(int enemyAC);
	int hide(int eWis);
};

