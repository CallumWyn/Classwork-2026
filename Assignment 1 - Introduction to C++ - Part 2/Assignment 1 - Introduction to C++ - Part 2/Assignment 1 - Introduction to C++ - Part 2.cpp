// Assignment 1 - Introduction to C++ - Part 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <string>
#include <assert.h>
#include <vector>
#include <cstdlib>

using namespace std;

// 6.1
int SearchArray(int array[], int size, int searchFor);

// 7.1
void SortArray(int array[], int size);

// 8.2
int BinarySearchArray(int array[], int size, int searchFor);

// 9.1
void NumberSwap(int *x, int *y);


struct Enemy {
    string name; // Name of the enemy
    int health; // Enemy health
    pair<int, int> damageRange; // The minimum and maximum amount of damage that can be done
    bool dead = false; // If the enemy is dead


    void AttackEnemy(Enemy &enemy) { // Gets a reference of the enemy it's attacking so the damage stays

        // Allows a random amount of damage between the damage range to be generated
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distrib(damageRange.first, damageRange.second);
        
        // Generates a random amount of damage and deals it to the enemy
        int damage = distrib(gen);
        enemy.health -= damage;

        // Outputs how much damage has been done 
        cout << "\n" << name << " dealt " << damage << " damage to the " << enemy.name << "!" << endl;
        
        // Sets the enemy to dead if it has 0 health left, otherwise tells the user how much health it has remaining
        if (enemy.health <= 0) { enemy.dead = true; cout << enemy.name << " has died!\n"; }
        else { cout << enemy.name << " has " << enemy.health << " health remaining!\n" << endl; }

        // Pauses the system to allow the user time to look at the results
        system("pause");
        system("cls");
    }
};


int main()
{
    srand(NULL);

    // 6.
    // You will write a function that performs a linear search through an integer array by passing the target value, and the array,
    // as function arguments. The function will return the index where the target is found, otherwise it will return -1.

    

    int arr1[20] = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 };

    cout << SearchArray(arr1, sizeof(arr1) / sizeof(arr1[0]), 3) << endl;
    cout << SearchArray(arr1, sizeof(arr1) / sizeof(arr1[0]), 7) << endl;
    cout << SearchArray(arr1, sizeof(arr1) / sizeof(arr1[0]), 67) << endl;
    cout << SearchArray(arr1, sizeof(arr1) / sizeof(arr1[0]), 88) << endl;

    cout << "\n";
    
    while (true) {
        // Gets the user's number input
        cout << "\nWhat number would you like to find in the array?" << endl;
        int userNumber;
        cin >> userNumber;
        // Runs the SearchArray function and puts it in an int variable
        int userNumberIndex = SearchArray(arr1, sizeof(arr1) / sizeof(arr1[0]), userNumber);
        // Outputs an error if the value isn't found, and outputs the index if it is found
        if (userNumberIndex == -1) { cout << "Error. Could not find your number in the array" << endl; }
        else { cout << userNumber << " could be found at the index " << userNumberIndex << endl; break; }
    }


    // 7.
    // Using the tutorials you will write a function that performs an ‘in-place’ bubble sort by passing an array of integers to it. 
    // Sort in ascending order (smallest to largest). You do not need to return any values from the function.

    SortArray(arr1, sizeof(arr1) / sizeof(arr1[0]));
    cout << "\n\n";


    // 8.
    // You will implement a function that searches a sorted array for a given value. 
    // Pass the target value and the array to your function and return the index where the value was found if it exists in the array. 
    // If it is not in the array return -1.

    // 8.4
    cout << BinarySearchArray(arr1, sizeof(arr1) / sizeof(arr1[0]), 11) << endl;
    cout << BinarySearchArray(arr1, sizeof(arr1) / sizeof(arr1[0]), 23) << endl;
    cout << BinarySearchArray(arr1, sizeof(arr1) / sizeof(arr1[0]), 97) << endl;
    cout << BinarySearchArray(arr1, sizeof(arr1) / sizeof(arr1[0]), 88) << endl;

    // 8.5
    while (true) {
        // Gets the user's number input
        cout << "\nWhat number would you like to find in the array?" << endl;
        int userNumber; // I use the same variable because it's easy to remember and only exists in this scope, so it doesn't matter much
        cin >> userNumber;
        // Runs the BinarySearchArray function and puts it in an int variable
        int userNumberIndex = BinarySearchArray(arr1, sizeof(arr1) / sizeof(arr1[0]), userNumber);
        // Outputs an error if the value isn't found, and outputs the index if it is found
        if (userNumberIndex == -1) { cout << "Error. Could not find your number in the array" << endl; }
        else { cout << userNumber << " could be found at the index " << userNumberIndex << endl; break; }
    }

    // 9.
    // You will write a function to swap the value of two integers. 
    // You will do this by passing pointers to those integers into the function and performing the swap through pointer manipulation. 
    // Your function will not return any values.

    // 9.2
    int a = 5;
    int b = 7;
    NumberSwap(&a, &b);

    cout << "\n";

    cout << a << endl;
    cout << b << endl;

    // 10
    // Make a struct that represents a Mob, it should have an attack skill, a damage rating, a name and health.
    // Write a function that determines the outcome of a battle by passing two Mobs by reference.
    // In the battle function make each Mob perform an attack on the other by using their attack skills to determine the outcome somehow.
    // How is up to you, but some form of simulated dice roll using randomness is suggested(think tabletop RPGs).


    // 10.2
    cout << "\n";
    system("pause");
    system("cls");

    // Creates 2 different enemy types
    Enemy goblin = { "Goblin", 25, {6, 12} };
    Enemy orc = { "Orc", 55, {1,10} };
    
    // Creates a look where alive enemies attack
    do {
        if (!goblin.dead) { goblin.AttackEnemy(orc); }
        if (!orc.dead) { orc.AttackEnemy(goblin); }
    } while (!orc.dead && !goblin.dead);

    // Runs a victory message after the battle is over
    if (orc.dead) { cout << "\nGoblin has won!\n"; }
    else if (goblin.dead) { cout << "\nOrc has won!\n"; }

}

// 6.1
int SearchArray(int array[], int size, int searchFor) {
    for (int i = 0; i < size; i++) { // Goes through the array
        if (array[i] == searchFor) { // If the number being searched for matches a value in the array, it returns the index
            return i;
        }
    }
    return -1;
}

// 7.1
void SortArray(int array[], int size) {
    // Creates an int for temporarily storing an array value
    int x;

    // Goes through all of the array, in case you need to move one value from one side to the other
    for (int i = 0; i < size; i++) {
        // Goes through all of the array and swaps values if one is smaller than the other
        for (int j = 1; j < size; j++) {
            if (array[j] < array[j - 1]) { x = array[j - 1]; array[j - 1] = array[j]; array[j] = x; }
        }
    }
    // FOR DEBUGGING // prints all of the array
    for (int i = 0; i < size; i++) { cout << array[i] << ", "; }

}

// 8.2
int BinarySearchArray(int array[], int size, int searchFor) {
    // Finds out if the number being searched for is higher or lower than the halfway point in the array
    if(array[size/2] <= searchFor){
        // Goes through the second half of the array
        for (int i = size/2; i < size; i++) { 
            if (array[i] == searchFor) { // If the number being searched for matches a value in the array, it returns the index
                return i;
            }
        }
    }
    else {
        // Goes through the first half of the array
        for (int i = 0; i < size/2; i++) { // Goes through the array
            if (array[i] == searchFor) { // If the number being searched for matches a value in the array, it returns the index
                return i;
            }
        }
    }

    
    return -1;
}

// 9.1
void NumberSwap(int* x, int* y) {
    // Temporarily stores a pointer
    int z = *x;
    // Sets x to y
    *x = *y;
    // Sets y to x
    *y = z;
}