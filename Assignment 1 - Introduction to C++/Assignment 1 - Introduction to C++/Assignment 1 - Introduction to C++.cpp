// Assignment 1 - Introduction to C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void PrintArray(int arr[], int size);


int main()
{
    // 1.
    // You are to make a function that takes an array of int. The function will step through each element and print it to the console. Put a comma after each element, 
    // but do NOT put a comma at the end.
    // Commit this to version control.

    int arr1[8] = { 5,3,7,9,18,36,64,4 };
    PrintArray(arr1, sizeof(arr1) / sizeof(arr1[0]));


}

void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (i != 0){ cout << ", " << arr[i]; }
        else { cout << arr[i]; }
    }
}

