// Assignment 1 - Introduction to C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

// 1.1
void PrintArray(int arr[], int size);

// 2.
string FizzBuzz(int x);


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


}

// 1.1
void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (i != 0){ cout << ", " << arr[i]; }
        else { cout << arr[i]; }
    }
}

// 2.1
string FizzBuzz(int x){
    if (x % 3 == 0 && x % 5 == 0) { return "FizzBuzz"; }
    else if (x % 3 == 0) { return "Fizz"; }
    else if (x % 5 == 0) { return "Buzz"; }
    return to_string(x);
}


