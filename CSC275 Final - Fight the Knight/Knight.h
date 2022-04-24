#pragma once
#include "Character.h"
class Knight : public Character {
	int slashAttack(int enemyAC);
	int stabAttack(int enemyAC);
	void block();
};

