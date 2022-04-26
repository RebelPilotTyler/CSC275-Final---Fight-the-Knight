#include "Knight.h"
#include "Character.h"
#include <iostream>
using namespace std;
int Knight::slashAttack(int enemyAC)
{
    cout << name << " holds their sword high, preparing to strike..." << endl;
    int roll = rollD20() + str;
    cout << "You rolled " << roll << endl;
    try
    {
        if (roll == 1) {
            throw 1;
        }
        else if (roll == 20) {
            throw 2;
        }
        else if (roll < enemyAC) {
            throw 3;
        }
        else if (roll >= enemyAC) {
            throw 4;
        }
        else {
            throw 5;
        }
    }
    catch (int i)
    {
        if (i == 1) {
            cout << name << " stumbled and accidently cut themselves!" << endl;
            hp = hp - (rollD4() + dex);
            return 0;
        }
        else if (i == 2) {
            cout << name << " landed a critical hit!" << endl;
            return (rollD8() * 2) + dex;
        }
        else if (i == 3) {
            cout << name << " swung and missed!" << endl;
        }
        else if (i == 4) {
            cout << name << " swung and struck a solid blow!" << endl;
            return (rollD8() + dex);
        }
        else if (i == 5) {
            cout << "ERROR: Invalid Roll." << endl;
            slashAttack(enemyAC);
        }
    }
}
int Knight::stabAttack(int enemyAC)
{
    cout << name << " pulled back their sword, preparing to thrust it at the enemy..." << endl;
    int roll = rollD20() + dex;
    cout << "You rolled " << roll << endl;
    try
    {
        if (roll == 1) {
            throw 1;
        }
        else if (roll == 20) {
            throw 2;
        }
        else if (roll < enemyAC) {
            throw 3;
        }
        else if (roll >= enemyAC) {
            throw 4;
        }
        else {
            throw 5;
        }
    }
    catch (int i)
    {
        if (i == 1) {
            cout << name << " stumbled and accidently cut themselves!" << endl;
            hp = hp - (rollD4() + str);
        }
        else if (i == 2) {
            cout << name << " landed a critical hit!" << endl;
            return (rollD8() * 2) + str;
        }
        else if (i == 3) {
            cout << name << " thrusted and missed!" << endl;
        }
        else if (i == 4) {
            cout << name << " thrusted and solidly struck the enemy!" << endl;
            return (rollD8() + str);
        }
        else if (i == 5) {
            cout << "ERROR: Invalid Roll." << endl;
            stabAttack(enemyAC);
        }
    }
}
void Knight::block()
{
    cout << name << " is using their shield to help block attacks!" << endl;
    modAC += rollD8() + str;
}