// Exercises - Constants.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

void calling();
float ToGallons(float litres);
const float GALLONCONVERSION = 3.78533;

int main()
{
    // Exercise 2
    // Write a function that, when you call it, displays a message telling how many times it has been called: “I have been called 3 times” for instance.
    // Write a main function that calls this function at least 10 times.

    for (int i = 0; i < 20; i++) {
        calling();
    }

    float litres;
    cout << "\n\n\nHow many litres would you like to convert to gallons?" << endl;
    cin >> litres;
    cout << litres << " litres is " << ToGallons(litres) << " gallons!" << endl;
    
}

void calling() {
    static int times = 0;
    times++;
    if (times == 1) { cout << "I have been called " << times << " time" << endl; }
    else { cout << "I have been called " << times << " times" << endl; }
    
}

float ToGallons(float litres) {
    return litres / GALLONCONVERSION;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
