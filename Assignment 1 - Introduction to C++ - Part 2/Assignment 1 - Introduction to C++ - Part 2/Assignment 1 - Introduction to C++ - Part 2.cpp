// Assignment 1 - Introduction to C++ - Part 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

// 6.1
int SearchArray(int array[], int size, int searchFor);


int main()
{
    // 6.
    // You will write a function that performs a linear search through an integer array by passing the target value, and the array,
    // as function arguments. The function will return the index where the target is found, otherwise it will return -1.


    int arr1[20] = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 };

    assert(SearchArray(arr1, sizeof(arr1) / sizeof(arr1[0]), 3) == 2);
    assert(SearchArray(arr1, sizeof(arr1) / sizeof(arr1[0]), 7) == 11);
    assert(SearchArray(arr1, sizeof(arr1) / sizeof(arr1[0]), 67) == 0);
    assert(SearchArray(arr1, sizeof(arr1) / sizeof(arr1[0]), 88) == -1);
    
    while (true) {
        cout << "\nWhat number would you like to find in the array?" << endl;
        int userNumber;
        cin >> userNumber;
        int userNumberIndex = SearchArray(arr1, sizeof(arr1) / sizeof(arr1[0]), userNumber);
        if (userNumberIndex == -1) { cout << "Error. Could not find your number in the array" << endl; }
        else { cout << userNumber << " could be found at the index " << userNumberIndex << endl; }
    }


}

// 6.1
int SearchArray(int array[], int size, int searchFor) {
    for (int i = 0; i < size; i++) {
        if (array[i] == searchFor) {
            return i;
        }
    }
    return -1;
}


