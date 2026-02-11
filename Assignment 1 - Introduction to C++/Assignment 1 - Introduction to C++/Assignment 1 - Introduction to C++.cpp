// Assignment 1 - Introduction to C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

// 1.1
void PrintArray(int arr[], int size);

// 2.1
string FizzBuzz(int x);

// 3.1
int ArrayMinimum(int x[], int size);

// 4.1
int FPSAccuracy(float hits, float shots);

// 5.1
enum PotionType {
    HEALTH,
    SPEED,
    STRENGTH,
    MAGIC
};

struct Player { int health = 30; int speed = 10; int strength = 15; int magic = 30; };

Player applyPotion(PotionType effect, Player player);

void PlayerOutput(Player player);



int main()
{
    // 1.
    // You are to make a function that takes an array of int. The function will step through each element and print it to the console. Put a comma after each element, 
    // but do NOT put a comma at the end.

    // 1.2
    int arr1[8] = { 5,3,7,9,18,36,64,4 };
    PrintArray(arr1, sizeof(arr1) / sizeof(arr1[0]));

    // 2.
    //You are to make a function that returns the FizzBuzz string for any given input integer. 
    // An integer will return “Fizz” if the number is a multiple of 3. It will return “Buzz” if it’s a multiple of 5. 
    // It will return “FizzBuzz” if it’s a multiple of 3 AND 5. Otherwise it will return the input number converted to a string. 
    // You can use std::to_string() or equivalent for this assessment.

    // 2.2
    cout << "\n\n\n" << FizzBuzz(7) << endl;
    cout << FizzBuzz(3) << endl;
    cout << FizzBuzz(5) << endl;
    cout << FizzBuzz(15) << "\n\n" << endl;

    // 2.3
    for (int i = 0; i < 20; i++) {
        cout << FizzBuzz(i+1) << "\n";
    }

    // 3.
    // You are to make a function that finds and returns the smallest element of an int array. Pass the array to the function as an argument

    // 3.2
    int minArray[20] = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 };
    cout << "\nThe lowest is " << ArrayMinimum(minArray, sizeof(minArray) / sizeof(minArray[0])) << "!\n" << endl;

    // 4.
    // You are to make a function that calculates hit accuracy in an FPS. Your function will take two integer arguments, (number of hits, and number of shots fired) 
    // and return an int (rounded down) to represent the accuracy, as a percentage from 0 to 100.

    // 4.2
    cout << FPSAccuracy(3, 4) << endl;
    cout << FPSAccuracy(1, 2) << endl;
    cout << FPSAccuracy(13, 13) << endl;
    cout << FPSAccuracy(21, 173) << endl;
    cout << FPSAccuracy(0, 0) << endl;

    // 5.
    // You will write a function that takes an enum for a potion type and a Player struct and use a switch statement to apply the following effects. 
    // Your function should return the new altered Player.

    // 5.2
    cout << "\n\n\n";
    Player player;
    PlayerOutput(applyPotion(HEALTH,player));
    PlayerOutput(applyPotion(SPEED,player));
    PlayerOutput(applyPotion(STRENGTH,player));
    PlayerOutput(applyPotion(MAGIC,player));


}

// 1.1
void PrintArray(int arr[], int size) {
    // Gets the size of the array, and goes through a for loop that many times outputting a comma and the number in the array it's on
    for (int i = 0; i < size; i++) {
        if (i != 0){ cout << ", " << arr[i]; }
        // If it's the first iteration, a comma shouldn't be in front of the number
        else { cout << arr[i]; }
    }
}

// 2.1
string FizzBuzz(int x){
    // Checks if x / 3 or / 5 has any remainders. if neither do, it outputs FizzBuzz
    if (x % 3 == 0 && x % 5 == 0) { return "FizzBuzz"; }
    // If just 3 has remainders, outputs Fizz
    else if (x % 3 == 0) { return "Fizz"; }
    // If just 5 has remainders, outputs Buzz
    else if (x % 5 == 0) { return "Buzz"; }
    // If none of these are true, returns x
    return to_string(x);
}


// 3.1
int ArrayMinimum(int x[], int size) {
    // Sets the first number as the lowest
    int y = x[0];
    // Goes through the array, and sets y to the number it's on if it's lower than y
    for (int i = 0; i < size; i++){
        if (x[i] < y) {
            y = x[i];
        }
        //cout << x[i] << endl;
    }
    return y;
}

// 4.1
int FPSAccuracy(float hits, float shots) {
    // If the hits or shots are equal to 0, it returns 0 as to not get an error
    if (hits == 0 || shots == 0) { return 0; }
    // Does 100 multiplied by the hits to shots ratio to get the percentage
    float x = 100 * (hits / shots);
    // Returns it as an int
    return x;
}

// 5.1
Player applyPotion(PotionType effect, Player player) {
    // Goes through all the different potions and applies the effects of each
    switch (effect) {
    case(HEALTH):
        player.health = 100;
        break;
    case(SPEED):
        player.speed = 50;
        player.health -= 10;
        player.strength -= 10;
        player.magic = 10;
        break;
    case(STRENGTH):
        player.speed = 25;
        player.health *= 2;
        player.strength = 200;
        break;
    case(MAGIC):
        player.strength = 10;
        player.magic = 100;
        break;
    }
    return player;
}

// 5.2
void PlayerOutput(Player player) {
    // Simply just outputs the player stats
    cout << player.health << ", " << player.speed << ", " << player.strength << ", " << player.magic << endl;
}

