
#include <iostream>
#include <cstdlib>
using namespace std;

string Positivity(int num);

int main()
{
    // Exercise 1
    // Write an if statement that assigns 100 to x when y is equal to zero

    // When y is zero, x is set to 100
    int x;
    int y = 0;

    if (y == 0) {
        x = 100;
    }

    cout << x << endl;


    // Exercise 2
    // Write a program that asks the user for two numbers and then display the larger number to the console.

    int num1;
    int num2;

    // Collects numbers from the user
    cout << "\n\nWhat is your first number?" << endl;
    cin >> num1;
    cout << "\n\nWhat is your second number?" << endl;
    cin >> num2;

    // Outputs the highest number
    if (num2 > num1) { cout << "\nThe biggest number is " << num2 << endl; }
    else { cout << "\nThe biggest number is " << num1 << endl; }


    // Exercise 3
    // Implement a C++ program that reads five (5) numbers and displays the word “positive” if the sum of the five numbers is positive and “negative” if the sum is negative. 
    // If the sum is equal to zero then the program must display “zero”

    // Collects 5 numbers from the user and runs all of them through the Positivity Function
    int num3, num4, num5, num6, num7;
    cout << "\nList 5 Numbers" << endl;
    cin >> num3 >> num4 >> num5 >> num6 >> num7;
    cout << Positivity(num3) << endl;
    cout << Positivity(num4) << endl;
    cout << Positivity(num5) << endl;
    cout << Positivity(num6) << endl;
    cout << Positivity(num7) << endl;

    int choice = 2;

    // See's what number choice is
    switch (choice) {
    case(1):
        cout << "1" << endl;
        break;
    // 2 Cases next to each other count as an or condition
    case(2):
    case(3):
        cout << "2 or 3" << endl;
        break;
    case(4):
        cout << "4" << endl;
        break;
    default:
        cout << "Invalid" << endl;
        break;
    }


    // Exercise 4
    // Convert the following if statement into a ternary operator

    int x2 = 5;
    // Basically a short if statement
    float y2 = (x2 == 0) ? 0 : 10 / x2;

    cout << "\n\n\n" << y2 << endl;

    int num8;
    int num9;
    float num10;
    string op;

    // Collects numbers and operator from the user
    cout << "\n\n\nEnter your first number:" << endl;
    cin >> num8;
    cout << "\n\n\nEnter your second number:" << endl;
    cin >> num9;
    cout << "\n\n\nEnter your operator: (+ - * / %)" << endl;
    cin >> op;

    // See's which operator the user selected and uses it to do an equation with the numbers provided by the user above
    if (op == "+") { num10 = num8 + num9; }
    else if (op == "-") {num10 = num8 - num9;}
    else if (op == "*") {num10 = num8 * num9;}
    else if (op == "/") {num10 = num8 / num9;}
    else if (op == "%") {num10 = num8 % num9;}

    cout << "\n\n" << num8 << " " << op << " " << num9 << " is " << num10 << endl;

    // Exercise 7
    // Write a program that accepts an integer that represents the month of the year. It should then display the number of days in that month. 
    // If a number that doesn’t correspond to a month is entered then the program should display an error message.

    int month;

    // Gets a number from 1-12
    cout << "\n\nWhich number of a month is your favourite?" << endl;
    cin >> month;

    // See's what month the user selected and outputs the amount of days it has
    switch (month) {
    case(9):
    case(4):
    case(6):
    case(11):
        cout << "That month has 30 days!" << endl;
        break;
    case(1):
    case(3):
    case(5):
    case(7):
    case(8):
    case(10):
    case(12):
        cout << "That month has 31 days!" << endl;
        break;
    case(2):
        cout << "That month can have 28 or 29 days!" << endl;
        break;
    default:
        // If it doesn't fall into one of the 12 numbers, it outputs as invalid
        cout << "Invalid Input" << endl;
        break;
    }

}

string Positivity(int num) {
    if (num > 0) { return "Positive"; }
    else if (num < 0) { return "Negative"; }
    else { return "Zero"; }
}
