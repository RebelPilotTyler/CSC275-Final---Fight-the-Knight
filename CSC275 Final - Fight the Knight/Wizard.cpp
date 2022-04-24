#include "Wizard.h"
#include <iostream>
#include <string>
using namespace std;
int Wizard::fireAttack(int eStr)
{
	cout << name << " began creating a ball of fire in their hands, preparing to hurl it at the enemy..." << endl;
	int roll;
	int enemyRoll;
	roll = rollD20() + inT;
	enemyRoll = rollD20() + eStr;
	try
	{
		if (roll > enemyRoll) {
			throw 1;
		}
		else if (roll <= enemyRoll) {
			throw 2;
		}
	}
	catch (int j)
	{
		if (j == 1) {
			cout << "The enemy was scorched by fire!" << endl;
			return rollD10() + inT;
		}
		else if (j == 2) {
			cout << name << "'s fireball missed!" << endl;
			return 0;
		}
	}
}
int Wizard::lightningAttack(int eDex)
{
	cout << name << " began creating a ball of electricity in their hands, preparing to hurl it at the enemy..." << endl;
	int roll;
	int enemyRoll;
	roll = rollD20() + wis;
	enemyRoll = rollD20() + eDex;
	try
	{
		if (roll > enemyRoll) {
			throw 1;
		}
		else if (roll <= enemyRoll) {
			throw 2;
		}
	}
	catch (int j)
	{
		if (j == 1) {
			cout << "The enemy was shocked by electricity!" << endl;
			return rollD10() + wis;
		}
		else if (j == 2) {
			cout << name << "'s thunderbolt missed!" << endl;
			return 0;
		}
	}
}
int Wizard::iceAttack(int eCon)
{
	cout << name << " began creating a ball of ice in their hands, preparing to hurl it at the enemy..." << endl;
	int roll;
	int enemyRoll;
	roll = rollD20() + cha;
	enemyRoll = rollD20() + eCon;
	try
	{
		if (roll > enemyRoll) {
			throw 1;
		}
		else if (roll <= enemyRoll) {
			throw 2;
		}
	}
	catch (int j)
	{
		if (j == 1) {
			cout << "The enemy was frozen solid!" << endl;
			return rollD10() + cha;
		}
		else if (j == 2) {
			cout << name << "'s ice attack missed!" << endl;
			return 0;
		}
	}
}