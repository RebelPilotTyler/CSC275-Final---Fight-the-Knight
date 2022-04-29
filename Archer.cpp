//Source code file for the Archer subclass                      *Comments Here*
#include "Archer.h"                                             //Includes the Archer class header file.
#include <iostream>                                             //Includes the iostream library, which allows for input and output to the screen.
#include <string>                                               //Includes the string library, which allows for the use of strings.
using namespace std;                                            //Prevents the programmer from having to type std:: in front of each input and output statement.
int Archer::quickShotAttack(int enemyAC) {                      //Defines the quickShotAttack function, which takes in the enemy's AC and returns an integer.
    cout << name << " notches 3 arrows, carefully aiming all of them at the enemy..." << endl;//Outputs "name" notches 3 arrows, carefully aiming all of them at the enemy...
    int roll = rollD20() + dex;                                 //A variable which stores a random number from 1-20 + this character's dexterity stat.
    cout << name << " rolled " << roll << endl;                 //Outputs this character's roll.
    try                                                         //Sets up a try/catch code block in case of errors.
    {
        if (roll == 1) {                                        //If roll == 1...
            throw 1;                                            //Throw error 1, which won't actually be an error.
        }
        else if (roll == 20) {                                  //If roll == 20...
            throw 2;                                            //Throw error 2, which won't actually be an error.
        }
        else if (roll < enemyAC) {                              //If roll is less than the enemy's AC...
            throw 3;                                            //Throw error 3, which won't actually be an error.
        }
        else if (roll >= enemyAC) {                             //If roll is greater than or equal to the enemy's AC...
            throw 4;                                            //Throw error 4, which won't actually be an error.
        }
        else {                                                  //If roll is not equal to any of the above...
            throw 5;                                            //Throw error 5.
        }
    }
    catch (int i)                                               //Catch code block for catching errors, which will be stored in integer i.
    {
        if (i == 1) {                                           //If i == 1, meaning roll == 1...
            cout << name << " fumbled an arrow and accidently cut themselves!" << endl;//Outputs "name" fumbled an arrow and accidently cut themselves!
            hp = hp - (rollD4() + dex);                         //Subtracts a random number from 1-4 + this character's dexterity stat from this character's hp.
        }
        else if (i == 2) {                                      //If i == 2, meaning roll == 20...
            cout << name << " landed a critical hit!" << endl;  //Outputs "name" landed a critical hit!
            return ((rollD6() + rollD6() + rollD6()) * 2) + dex;//Returns a random number 1-6 + 1-6 + 1-6 * 2 + this character's dexterity stat, to be subtracted from the enemy's hp.
        }
        else if (i == 3) {                                      //If i == 3, meaning roll is lower than the enemy's AC...
            cout << name << " shot and missed!" << endl;        //Outputs "name" shot and missed!
        }
        else if (i == 4) {                                      //If i == 4, meaning roll is higher than the enemy's AC...
            cout << name << " shot and struck a solid blow!" << endl;//Outputs "name" shot and struck a solid blow!
            return ((rollD6() + rollD6() + rollD6()) + dex);    //Returns a random number 1-6 + 1-6 + 1-6 + this character's dexterity stat to be subtracted from the enemy's hp.
        }
        else if (i == 5) {                                      //If i == 5...
            cout << "ERROR: Invalid Roll." << endl;             //Outputs ERROR: Invalid Roll.
            quickShotAttack(enemyAC);                           //Recall the quickShotAttack function.
        }
    }
}
int Archer::powerShotAttack(int enemyAC) {                      //Defines the powerShotAttack function, which takes in the enemy's AC and returns an integer.
    cout << name << " pulls their bow all the way back, preparing to let loose a powerful shot..." << endl;//Outputs "name" pulls their bow all the way back, preparing to let loose a powerful shot...
    int roll = rollD20() + dex;                                 //A variable for storing a random number 1-20 + this character's dexterity stat.
    cout << name << " rolled " << roll << endl;                 //Outputs this character's roll.
    try                                                         //Sets up a try/catch code block in case of errors.
    {
        if (roll == 1) {                                        //If roll == 1...
            throw 1;                                            //Throw error 1, which won't actually be an error.
        }
        else if (roll == 20) {                                  //If roll == 20...
            throw 2;                                            //Throw error 2, which won't actually be an error.
        }
        else if (roll < enemyAC) {                              //If roll is lower than the enemy's AC...
            throw 3;                                            //Throw error 3, which won't actually be an error.
        }
        else if (roll >= enemyAC) {                             //If roll is greater than or equal to the enemy's AC...
            throw 4;                                            //Throw error 4, which won't actually be an error.
        }
        else {                                                  //If roll is not equal to any of the above...
            throw 5;                                            //Throw error 5.
        }
    }
    catch (int i)                                               //Catch code block for catching errors, which will be stored in integer i.
    {
        if (i == 1) {                                           //If i == 1, meaning roll == 1, subtract hp from this character.
            cout << name << " fumbled the arrow and accidently cut themselves!" << endl;
            hp = hp - (rollD8() + dex);
        }
        else if (i == 2) {                                      //If i == 2, meaning roll == 20, subtract hp from the enemy, twice the amount it would normally be.
            cout << name << " landed a critical hit!" << endl;
            return (rollD10() * 2) + dex;
        }
        else if (i == 3) {                                      //If i == 3, meaning roll is lower than the enemy's AC, do nothing.
            cout << name << " shot and missed!" << endl;
        }
        else if (i == 4) {                                      //If i == 4, meaning roll is higher than the enemy's AC, subtract hp from the enemy.
            cout << name << " shot and struck a solid blow!" << endl;
            return (rollD10() + dex);
        }
        else if (i == 5) {                                      //If i == 5, output an error and recall the powerShotAttack function.
            cout << "ERROR: Invalid Roll." << endl;
            powerShotAttack(enemyAC);
        }
    }
}
int Archer::hide(int eWis) {                                    //Defines the hide function, which takes in the enemy's wisdom stat and outputs an integer.
    cout << name << " tried to vanish into the shadows..." << endl;//Outputs "name" tried to vanish into the shadows...
    int roll;                                                   //A variable for a random number.
    int enemyRoll;                                              //A variable storing a random number for the enemy.
    roll = rollD20() + dex;                                     //Set roll to a random number 1-20 + this character's dexterity.
    enemyRoll = rollD20() + eWis;                               //Set enemyRoll to a random number 1-20 + the enemy's wisdom stat.
    try                                                         //Sets up a try/catch code block in case of errors.
    {
        if (roll > enemyRoll) {                                 //If this character's roll is higher than the enemy's, throw error 1, which won't actually be an error.
            throw 1;
        }
        else if (roll <= enemyRoll) {                           //If this character's roll is less than or equal to the enemy's, throw error 2, which won't actually be an error.
            throw 2;
        }
    }
    catch (int j)                                               //Catch code block for catching errors, which will be stored in integer j.
    {
        if (j == 1) {                                           //If j == 1, meaning this character got the higher roll, return a random number 1-4 to be subtracted from the enemy's AC.
            cout << name << " suddenly vanished!" << endl;
            return rollD4();
        }
        else if (j == 2) {                                      //If j == 2, meaning the enemy got the higher roll, return 0, so nothing happens.
            cout << name << " tried to run but couldn't hide!" << endl;
            return 0;
        }
    }
}