#pragma once
#include <string>
using namespace std;
class Character
{
public:
	int str;
	int dex;
	int con;
	int inT;
	int wis;
	int cha;
	int lvl;
	string name;
	int hp;
	int maxHP;
	int AC;
	int modAC;
	int rollD4();
	int rollD6();
	int rollD8();
	int rollD10();
	int rollD20();
	void dodge();
	int taunt(int eInt, int eWis, int eCha);
};

