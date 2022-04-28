//The source file for the Knight subclass                               *Comments Here*
#include "Knight.h"                                                     //Includes the Knight header file.
#include "Character.h"                                                  //Includes the Character class header file.
#include <iostream>                                                     //Includes the iostream library, which will allow for input and output to the monitor.
using namespace std;                                                    //Line which prevents the programmer having to type std:: in front of each input and output statement.
int Knight::slashAttack(int enemyAC)                                    //Defines the Knight class's slashAttack function, which takes in the enemy's AC and returns and integer.
{
    cout << name << " holds their sword high, preparing to strike..." << endl;//Outputs "name" holds their sword high, preparing to strike...
    int roll = rollD20() + str;                                         //A variable that is set to a random number between 1-20 + this character's strength stat.
    cout << name << " rolled " << roll << endl;                         //Outputs what this character rolled.
    try                                                                 //Sets up a try/catch code block in case of errors.
    {
        if (roll == 1) {                                                //If roll == 1...
            throw 1;                                                    //Throw error 1, which won't actually be an error.
        }
        else if (roll == 20) {                                          //If roll == 20...
            throw 2;                                                    //Throw error 2, which won't actually be an error.
        }
        else if (roll < enemyAC) {                                      //If roll < the enemy's AC...
            throw 3;                                                    //Throw error 3, which won't actually be an error.
        }
        else if (roll >= enemyAC) {                                     //If roll >= the enemy's AC...
            throw 4;                                                    //Throw error 4, which won't actually be an error.
        }
        else {                                                          //If roll is not any of the above...
            throw 5;                                                    //Throw error 5.
        }
    }
    catch (int i)                                                       //Catch code block for catching errors, which will be stored in integer i.
    {
        if (i == 1) {                                                   //If i == 1, meaning roll == 1...
            cout << name << " stumbled and accidently cut themselves!" << endl;//Outputs "name" stumbled and accidently cut themselves!
            hp = hp - (rollD4() + dex);                                 //Subtract a random number from 1-4 + dex from this character's hp.
            return 0;                                                   //Return 0, so nothing happens to the enemy.
        }
        else if (i == 2) {                                              //If i == 2, meaning roll == 20...
            cout << name << " landed a critical hit!" << endl;          //Outputs "name" landed a critical hit!
            return (rollD8() * 2) + dex;                                //Return a random number from 1-8 * 2 + this character's dexterity stat, which will be subtracted from the enemy's hp.
        }
        else if (i == 3) {                                              //If i == 3, meaning roll is lower than the enemy's AC...
            cout << name << " swung and missed!" << endl;               //Outputs "name" swung and missed!
        }
        else if (i == 4) {                                              //If i == 4, meaning roll is higher than the enemy's AC...
            cout << name << " swung and struck a solid blow!" << endl;  //Outputs "name" swung and struck a solid blow!
            return (rollD8() + dex);                                    //Return a random number 1-8 + this character's dexterity stat, which will be subtracted from the enemy's hp.
        }
        else if (i == 5) {                                              //If i == 5...
            cout << "ERROR: Invalid Roll." << endl;                     //Outputs ERROR: Invalid Roll.
            slashAttack(enemyAC);                                       //Recall the slashAttack function.
        }
    }
}
int Knight::stabAttack(int enemyAC)                                     //Defines the Knight class's stabAttack function.
{
    cout << name << " pulled back their sword, preparing to thrust it at the enemy..." << endl;//Outputs "name" pulled back their sword, preparing to thrust it at the enemy...
    int roll = rollD20() + dex;                                         //A variable to store a random number 1-20 + this character's dexterity stat.
    cout << name << " rolled " << roll << endl;                         //Outputs this character's roll.
    try                                                                 //Sets up a try/catch code block in case of errors.
    {
        if (roll == 1) {                                                //If roll == 1...
            throw 1;                                                    //Throw error 1, which won't actually be an error.
        }   
        else if (roll == 20) {                                          //If roll == 20...
            throw 2;                                                    //Throw error 2, which won't actually be an error.
        }
        else if (roll < enemyAC) {                                      //If roll is less than the enemy's AC...
            throw 3;                                                    //Throw error 3, which won't actually be an error.
        }
        else if (roll >= enemyAC) {                                     //If roll is greater than or equal to the enemy's AC...
            throw 4;                                                    //Throw error 4, which won't actually be an error.
        }
        else {                                                          //If roll is not any of the above...
            throw 5;                                                    //Throw error 5.
        }
    }
    catch (int i)                                                       //Catch code block for catching error, which will be stored in integer i.
    {
        if (i == 1) {                                                   //If i == 1, meaning roll == 1...
            cout << name << " stumbled and accidently cut themselves!" << endl;//Outputs "name" stumbled and accidently cut themselves!
            hp = hp - (rollD4() + str);                                 //Subtracts a random number from 1-4 + this character's strength stat from this character's hp.
            return 0;                                                   //Return 0, so that nothing will happen to the enemy.
        }
        else if (i == 2) {                                              //If i == 2, meaning roll == 20...
            cout << name << " landed a critical hit!" << endl;          //Outputs "name" landed a critical hit!
            return (rollD8() * 2) + str;                                //Return a random number from 1-8 * 2 + this character's strength stat, which will be subtracted from the enemy's hp.
        }
        else if (i == 3) {                                              //If i == 3, meaning roll is lower than the enemy's AC...
            cout << name << " thrusted and missed!" << endl;            //Outputs "name" thrusted and missed!
        }
        else if (i == 4) {                                              //If i == 4, meaning roll is higher than the enemy's AC...
            cout << name << " thrusted and solidly struck the enemy!" << endl;//Outputs "name" thrusted and solidly struck the enemy!
            return (rollD8() + str);                                    //Returns a random number from 1-8 + this character's strength stat.
        }
        else if (i == 5) {                                              //If i == 5...
            cout << "ERROR: Invalid Roll." << endl;                     //Outputs ERROR: Invalid Roll.
            stabAttack(enemyAC);                                        //Recalls the stabAttack function.
        }
    }
}
void Knight::block()                                                    //Defines the Knight class's block function.
{
    cout << name << " is using their shield to help block attacks!" << endl;//Outputs "name" is using their shield to help block attacks!
    modAC += rollD8() + str;                                            //Adds a random number from 1-8 + this character's strength stat to this character's AC.
}