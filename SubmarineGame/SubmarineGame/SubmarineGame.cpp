// SubmarineGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

int GetEnemyLocation(int enemyPos);
void AjustPlayerPosition(int rotationAmount, string rotationDirection);
int AjustPlayerPosition(int rotationAmount, string rotationDirection, int enemyLocation);
void FindLowestDistance();

bool enemyALiving = true;
bool enemyBLiving = true;
bool enemyCLiving = true;
bool enemyDLiving = true;

int enemyAPos;
int enemyBPos;
int enemyCPos;
int enemyDPos;

string enemyDirection;

enum lowestdistance {
    EnemyA,
    EnemyB,
    EnemyC,
    EnemyD
};
lowestdistance priorityEnemy;

bool priorityAlive = false;
int priorityTargetPos;

int rotationAmount;
string rotationAmountString;
string rotationDirection;

// Was planning on changing playerPos and compare it to enemyPos, but decided not to
//int playerPos = 0;
//int displayPlayerPos = 0;

int main()
{
    srand(time(NULL));

    

    enemyAPos = rand() % 360;
    // cout << "Enemy A is on this degree! > " << enemyAPos << "\n\n\n\n" << endl;
    enemyBPos = rand() % 360;
    // cout << "Enemy B is on this degree! > " << enemyBPos << "\n\n\n\n" << endl;
    enemyCPos = rand() % 360;
    // cout << "Enemy C is on this degree! > " << enemyCPos << "\n\n\n\n" << endl;
    enemyDPos = rand() % 360;
    // cout << "Enemy D is on this degree! > " << enemyDPos << "\n\n\n\n" << endl;

    /*cout << enemyAPos << endl;
    cout << enemyBPos << endl;
    cout << enemyCPos << endl;
    cout << enemyDPos << endl;*/

    // First, just do one enemy
    // Second, do 4
    // Third, prioritize the closest one

    // Outputs the enemy locations
    cout << "The first enemy is " << GetEnemyLocation(enemyAPos) << " degrees away to the " << enemyDirection << "!" << endl;
    cout << "The second enemy is " << GetEnemyLocation(enemyBPos) << " degrees away to the " << enemyDirection << "!" << endl;
    cout << "The third enemy is " << GetEnemyLocation(enemyCPos) << " degrees away to the " << enemyDirection << "!" << endl;
    cout << "The forth enemy is " << GetEnemyLocation(enemyDPos) << " degrees away to the " << enemyDirection << "!" << endl;

    // Runs until the player completes the game
    while (true) {
        
        priorityTargetPos = 361;

        FindLowestDistance();
        while (priorityAlive) {

            // Outputs the priority target
            switch (priorityEnemy) {
            case(lowestdistance::EnemyA):
                cout << "\nThe Priority Enemy is the First Enemy" << endl;
                break;
            case(lowestdistance::EnemyB):
                cout << "\nThe Priority Enemy is the Second Enemy" << endl;
                break;
            case(lowestdistance::EnemyC):
                cout << "\nThe Priority Enemy is the Third Enemy" << endl;
                break;
            case(lowestdistance::EnemyD):
                cout << "\nThe Priority Enemy is the Forth Enemy" << endl;
                break;
            }



            // Asks the player how much they want to rotate and in what direction
            cout << "\nHow many degrees would you like to move? (0-360)" << endl;
            cin >> rotationAmount;
            cout << "Which direction would you like to rotate? (Left/Right) (Capitalization is important)" << endl;
            cin >> rotationDirection;
            

            // Resets if the player enters a number above 360
            if (rotationAmount > 360 || rotationAmount < 0 || (rotationDirection != "Left" && rotationDirection != "Right")) {
                cout << "\nInvalid Input. Put in a valid degree (0-360) and direction (Left/Right)\n\n" << endl;
                continue;
                // cout << "\n\n" << rotationAmount << "\n\n";
            }


            //else if (rotationDirection != "Left") {
            //    if (rotationDirection != "Right") {
            //        cout << "\nInvalid Input. Put in a valid degree (0-360) and direction (Left/Right)\n\n" << endl;
            //        continue;
            //    }
            //}


            //AjustPlayerPosition(rotationAmount, rotationDirection);


            // If the enemy is still alive, it runs the AjustPlayerPosition function
            if (enemyALiving) { enemyAPos = AjustPlayerPosition(rotationAmount, rotationDirection, enemyAPos); }
            if (enemyBLiving) { enemyBPos = AjustPlayerPosition(rotationAmount, rotationDirection, enemyBPos); }
            if (enemyCLiving) { enemyCPos = AjustPlayerPosition(rotationAmount, rotationDirection, enemyCPos); }
            if (enemyDLiving) { enemyDPos = AjustPlayerPosition(rotationAmount, rotationDirection, enemyDPos); }

            system("cls");

            

            // Checks if the distance to the enemy is 0, and if it isn't the priority, it outputs failure
            if ((GetEnemyLocation(enemyAPos) == 0 && priorityEnemy) != (lowestdistance::EnemyA && enemyALiving)) { cout << "This enemy wasn't the priority target!\n" << endl; }
            if ((GetEnemyLocation(enemyBPos) == 0 && priorityEnemy) != (lowestdistance::EnemyB && enemyBLiving)) { cout << "This enemy wasn't the priority target!\n" << endl; }
            if ((GetEnemyLocation(enemyCPos) == 0 && priorityEnemy) != (lowestdistance::EnemyC && enemyCLiving)) { cout << "This enemy wasn't the priority target!\n" << endl; }
            if ((GetEnemyLocation(enemyDPos) == 0 && priorityEnemy) != (lowestdistance::EnemyD && enemyDLiving)) { cout << "This enemy wasn't the priority target!\n" << endl; }


            // Checks if the distance to the enemy is 0, and if the enemy is the priority target, kills it
            switch (priorityEnemy) {
            case(lowestdistance::EnemyA):
                if (GetEnemyLocation(enemyAPos) == 0) { cout << "You found the first Enemy!\n" << endl; enemyALiving = false; priorityAlive = false; }
                break;
            case(lowestdistance::EnemyB):
                if (GetEnemyLocation(enemyBPos) == 0) { cout << "You found the second Enemy!\n" << endl; enemyBLiving = false; priorityAlive = false;}
                break;
            case(lowestdistance::EnemyC):
                if (GetEnemyLocation(enemyCPos) == 0) { cout << "You found the third Enemy!\n" << endl; enemyCLiving = false; priorityAlive = false;}
                break;
            case(lowestdistance::EnemyD):
                if (GetEnemyLocation(enemyDPos) == 0) { cout << "You found the forth Enemy!\n" << endl; enemyDLiving = false; priorityAlive = false;}
                break;
            }

            // If the enemy is still alive, it outputs how far away they are
            if (enemyALiving) { cout << "The first enemy is " << GetEnemyLocation(enemyAPos) << " degrees away to the " << enemyDirection << "!" << endl; }
            if (enemyBLiving) { cout << "The second enemy is " << GetEnemyLocation(enemyBPos) << " degrees away to the " << enemyDirection << "!" << endl; }
            if (enemyCLiving) { cout << "The third enemy is " << GetEnemyLocation(enemyCPos) << " degrees away to the " << enemyDirection << "!" << endl; }
            if (enemyDLiving) { cout << "The forth enemy is " << GetEnemyLocation(enemyDPos) << " degrees away to the " << enemyDirection << "!" << endl; }

            if (!enemyALiving && !enemyBLiving && !enemyCLiving && !enemyDLiving) {
                cout << "\n\nYou found all the enemies! Congratulations!\n\n";
                break;
            }
        }
        
        if (!enemyALiving && !enemyBLiving && !enemyCLiving && !enemyDLiving) {
            break;
        }
    }

}

// This function was for the first task when it was just looking for one enemy
void AjustPlayerPosition(int rotationAmount, string rotationDirection) {
    // Rotate left adds
    // Rotate right subtracts
    // If number is below zero, add 360
    // If number is above 360, subtract 360

    // Changes the enemy position based off of the rotation direction and amount selected by the player previously
    if (rotationDirection == "Right") {
        enemyAPos -= rotationAmount;
    }
    else if (rotationDirection == "Left") {
        enemyAPos += rotationAmount;
    }

    // Ajusts the distance incase it falls out of range
    if (enemyAPos > 360) {
        enemyAPos -= 360;
    }
    if (enemyAPos < 0) {
        enemyAPos += 360;
    }
}

int AjustPlayerPosition(int rotationAmount, string rotationDirection, int enemyLocation) {
    // Changes the enemy position based off of the rotation direction and amount selected by the player previously
    if (rotationDirection == "Right") {
        enemyLocation -= rotationAmount;
        //cout << "enemy - rotation: " << enemyLocation << endl;
    }
    else if (rotationDirection == "Left") {
        enemyLocation += rotationAmount;
        //cout << "enemy + rotation: " << enemyLocation << endl;
    }

    // Ajusts the distance incase it falls out of range
    if (enemyLocation > 360) {
        enemyLocation -= 360;
    }
    if (enemyLocation < 0) {
        enemyLocation += 360;
    }
    return enemyLocation;
}

int GetEnemyLocation(int enemyPos) {

    // Checks whether the enemy position is on the left or right, and then ajusts the position based on that
    // This is used to tell the player how far away the enemy is and in what direction
    if (enemyPos > 180) {
        enemyDirection = "Left";
        return 360 - enemyPos;
    }
    else {
        enemyDirection = "Right";
        return enemyPos;
    }
}

// Goes through all the enemies current positions and finds the smallest one.
void FindLowestDistance() {
    if (enemyALiving && GetEnemyLocation(enemyAPos) < priorityTargetPos) { priorityTargetPos = GetEnemyLocation(enemyAPos); priorityEnemy = lowestdistance::EnemyA; }

    if (enemyBLiving && GetEnemyLocation(enemyBPos) < priorityTargetPos) { priorityTargetPos = GetEnemyLocation(enemyBPos); priorityEnemy = lowestdistance::EnemyB; }

    if (enemyCLiving && GetEnemyLocation(enemyCPos) < priorityTargetPos) { priorityTargetPos = GetEnemyLocation(enemyCPos); priorityEnemy = lowestdistance::EnemyC; }

    if (enemyDLiving && GetEnemyLocation(enemyDPos) < priorityTargetPos) { priorityTargetPos = GetEnemyLocation(enemyDPos); priorityEnemy = lowestdistance::EnemyD; }

    priorityAlive = true;
}


