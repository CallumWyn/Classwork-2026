// Assignment 1 - Introduction to C++ - Part 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <assert.h>
#include <vector>

using namespace std;

// 6.1
int SearchArray(int array[], int size, int searchFor);

// 7.1
void SortArray(int array[], int size);

// 8.2
int BinarySearchArray(int array[], int size, int searchFor);


int main()
{
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