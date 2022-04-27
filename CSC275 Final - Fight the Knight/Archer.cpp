#include "Archer.h"
#include <iostream>
#include <string>
using namespace std;
int Archer::quickShotAttack(int enemyAC) {
    cout << name << " notches 3 arrows, carefully aiming all of them at the enemy..." << endl;
    int roll = rollD20() + dex;
    cout << name << " rolled " << roll << endl;
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
            cout << name << " fumbled an arrow and accidently cut themselves!" << endl;
            hp = hp - (rollD4() + dex);
        }
        else if (i == 2) {
            cout << name << " landed a critical hit!" << endl;
            return ((rollD6() + rollD6() + rollD6()) * 2) + dex;
        }
        else if (i == 3) {
            cout << name << " shot and missed!" << endl;
        }
        else if (i == 4) {
            cout << name << " shot and struck a solid blow!" << endl;
            return ((rollD6() + rollD6() + rollD6()) + dex);
        }
        else if (i == 5) {
            cout << "ERROR: Invalid Roll." << endl;
            quickShotAttack(enemyAC);
        }
    }
}
int Archer::powerShotAttack(int enemyAC) {
    cout << name << " pulls their bow all the way back, preparing to let loose a powerful shot..." << endl;
    int roll = rollD20() + dex;
    cout << name << " rolled " << roll << endl;
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
            cout << name << " fumbled the arrow and accidently cut themselves!" << endl;
            hp = hp - (rollD8() + dex);
        }
        else if (i == 2) {
            cout << name << " landed a critical hit!" << endl;
            return (rollD10() * 2) + dex;
        }
        else if (i == 3) {
            cout << name << " shot and missed!" << endl;
        }
        else if (i == 4) {
            cout << name << " shot and struck a solid blow!" << endl;
            return (rollD10() + dex);
        }
        else if (i == 5) {
            cout << "ERROR: Invalid Roll." << endl;
            powerShotAttack(enemyAC);
        }
    }
}
int Archer::hide(int eWis) {
    cout << name << " tried to vanish into the shadows..." << endl;
    int roll;
    int enemyRoll;
    roll = rollD20() + dex;
    enemyRoll = rollD20() + eWis;
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
            cout << name << " suddenly vanished!" << endl;
            return rollD4();
        }
        else if (j == 2) {
            cout << name << " tried to run but couldn't hide!" << endl;
            return 0;
        }
    }
}