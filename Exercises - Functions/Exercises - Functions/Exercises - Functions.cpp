// Exercises - Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

float low(float num1, float num2);
void half(float num4);
void cointoss(int flips);
int SumTo(int num6);
int SumArray(int num7[], int num8);
int MinInArray(int num9[], int num10);
int MultiplyByIndex(int num9[], int num10);
int AddArrays(int num11[], int num12[],int num13, int num14[]);
int RunningArray(int num15[], int num16);
int SearchArray(int num17[], int num18, int num19);
int SplitArray(int num20[], int num21, int num22[],int num23[]);
int Power(int x, int y);
void LookandSay(int num24[], int num25);

void SPR(string playerInput);
bool PlayAgain();

bool played = false;

int main()
{
    srand(time(0));
    //{
    //    srand(time(0));

    //    float num1;
    //    float num2;
    //    float num3;
    //    float num5;
    //    /*2. Write a function that returns the smaller of two floats that are passed to it:
    //         You should make a program that asks the user for two different numbers, then passes the two numbers into a function and output what the function returns*/
    //    cout << "Please enter your first number" << endl;
    //    cin >> num1;
    //    cout << "Please enter your second number" << endl;
    //    cin >> num2;
    //    cout << "Please enter your third number" << endl;
    //    cin >> num3;
    //    cout << "The lowest number is " << low(low(num1, num2), num3) << endl;

    //    /*3. Add another function with the same name as the one you wrote in question 2, but with
    //         three floats instead of two. What is this language feature called?*/
    //         // I just put the function inside itself to do three

    //         /*4. The following statement calls a function named Half. The Half function returns a value that
    //              is half that of the argument. Write the function.*/

    //    half(5);

    //    /*5. Write a function named CoinToss that simulates the tossing of a coin.
    //         The function should use the standard library rand() function in order to generate a
    //         display of either “heads” or “tails”. The rand() can be added by adding #include <cstdlib>
    //         to the top of your program. It returns a random number between 0 and 32767.
    //         Demonstrate the function in a program that asks the user how many times they want to
    //         toss the coin, and then simulates the tossing of the coin that number of times.*/

    //    cout << "How many coins would you like to toss?" << endl;
    //    cin >> num5;
    //    cointoss(num5);

    //    /*7. Write a function called SumTo that accepts an integer parameter N and returns the sum of
    //         all integers from 1 to N, including N.*/

    //    int result = SumTo(3); //result = 1 + 2 + 3 = 6
    //    std::cout << result << std::endl;
    //    result = SumTo(15); //result should now be 120
    //    std::cout << result << std::endl;

    //    /*8. Write a function that takes as its parameters an array of integers and the size of the array
    //         and returns the sum of the values in the array.*/
    //    int integer_array[5] = { 7, 3, 2, 4, 9 };
    //    //int result = SumArray(integer_array, 5); //result = 25
    //    std::cout << SumArray(integer_array, 5) << std::endl;

    //    /*9. Write a function that takes as its parameter an array of integers and the size of the array
    //         and returns the minimum of the values in the array.*/
    //    int integer_array2[7] = { 10, 15, 7, 4, 13, 19, 8 };
    //    int result2 = MinInArray(integer_array2, 7); //result = 4
    //    std::cout << result2 << std::endl;

    //    /*11. Write a function that takes as its parameters two input arrays of integers , an integer for
    //          their size and an output array. Set the value at each index to the sum of the corresponding
    //          two elements of the input arrays at the same index. Assume the three arrays are of equal
    //          length. Write your own code for testing this function.*/

    //    int array1[3] = { 5, 7, 9 };
    //    int array2[3] = { 2, 4, 6 };
    //    int array3[3];

    //    AddArrays(array1, array2, 3, array3);

    //    for (int i = 0; i < 3; i++) {
    //        cout << array3[i] << " ";
    //    }

    //    /*12. Write a function that takes as its parameters an array called array_input of integers and the
    //          size of the array and modifies the given array so that it contains a running sum of its
    //          original values. For example, if the array originally had the values {3,2,4,7}, after running
    //          your function that array would instead contain {3,5,9,16}, and if you ran it another time
    //          passing the modified array in again, you'd have {3,8,17,33}. Write your own code for testing
    //          this function. */


    //    cout << "\n\n";
    //    int array4[4] = { 3,2,4,7 };
    //    RunningArray(array4, 4);
    //    cout << "\n\n";
    //    RunningArray(array4, 4);
    //    cout << "\n\n";

    //    /*13. Write a function that searches for a particular number in an array. The function should
    //          have three parameters: the array, the array size, and the number to be found. If the
    //          number is in the array, the function should return the position of the number in the array.
    //          If the number isn’t found, the function should return -1. In the case that the desired
    //          number appears more than once in the array, the function should return the position of
    //          the first occurrence. Write your own code to test this function.*/

    //    int array5[7] = { 5,9,0,2,17,42,7 };

    //    cout << "Index of 42: " << SearchArray(array5, 7, 42) << "\n\n" << endl;

    //    /*14. Write a function named Split that accepts one input array of integers, an integer for the
    //          size of the input array, and two output arrays. All numbers in the input array that are
    //          positive are copied into the first output array and all numbers in the input array that are
    //          negative are copied into the second output array. The function should return how many
    //          numbers were copied into the first output array. Write your own code to test this function.*/

    //    int array6[6] = { -5,-9,14,12,-2,-19 };
    //    int array7[6];
    //    int array8[6];

    //    cout << "\nThe amount of positive numbers in the array is " << SplitArray(array6, 6, array7, array8) << endl;

    //    /*15. Write a function that calculates and then returns x to the power of y.*/
    //    cout << "\n\n 5 to the power of 4 is " << Power(5, 4) << endl;

    //    /*16. Write a function that takes in an array of integers, and the size of the array. The function
    //          should print out the “look and say” sequence for the array. The look and say sequence
    //          works by printing out how many of the same number there are in a row followed by that
    //          number.*/

    //    int array9[19] = { 1,2,2,1,5,1,1,7,7,7,7,1,1,1,1,1,1,1,1 };

    //    LookandSay(array9, 19);

    //    cout << "\n";

    //}

    /*17. Write a program that lets the user play the game of Rock, Paper, Scissors against the
          computer.*/

    while (PlayAgain()) {
        string playerInput;
        played = true;
        cout << "\n\nLet's play Scissors Paper Rock! Which do you choose?" << endl;
        cin >> playerInput;
        SPR(playerInput);
    }

}

float low(float num1, float num2) {
    if (num1 < num2) {
        return num1;
    }
    else {
        return num2;
    }
}

void half(float num4) {
    cout << "\n" << num4 / 2 << "\n" << endl;
}

void cointoss(int flips) {
    for (int i = 0; i < flips; i++) {
        
        int k = rand() % 2;
        if (k == 0) {
            cout << "You flipped Tails \n" << endl;
        }
        else if (k == 1){
            cout << "You flipped Heads \n" << endl;
        }
        else {
            cout << "Something went wrong \n" << endl;
        }
    }
}

int SumTo(int num6) {
    int k = 0;
    for (int i = 0; i < num6 + 1; i++) {
        k += i;
    }
    return k;
}

int SumArray(int num7[], int num8) {
    int k = 0;
    for (int i = 0; i < num8; i++) {
        k += num7[i];
    }
    return k;
}

int MinInArray(int num9[], int num10) {
    int j = num9[0];
    for (int i = 0; i < num10; i++) {
        if (j > num9[i]) {
            
            j = num9[i];
        }
    }
    return j;
}
int MultiplyByIndex(int num9[], int num10) {
    int j = num9[0];
    for (int i = 0; i < num10; i++) {
        if (j > num9[i]) {
            
            j = num9[i];
        }
    }
    return j;
}

int AddArrays(int num11[], int num12[], int num13, int num14[]) {
    for (int i = 0; i < num13; i++) {
        num14[i] = num11[i] + num12[i];
    }
    return 0;
}

int RunningArray(int num15[], int num16) {
    for (int i = 1; i < num16; i++) {
        num15[i] = num15[i] + num15[i - 1];
    }
    for (int i = 0; i < num16; i++) {
        cout << num15[i] << " ";
    }

    return 0;
}


int SearchArray(int num17[], int num18, int num19) {
    for (int i = 0; i < num18; i++) {
        if (num17[i] == num19) { return i; }
    }
    return -1;
}

int SplitArray(int num20[], int num21, int num22[], int num23[]) {
    int j = 0;
    int k = 0;
    for (int i = 0; i < num21; i++) {
        
        if (num20[i] < 0) {
            num22[j] = num20[i];
            j++;
        }
        else {
            num23[k] = num20[i];
            k++;
        }
    }
    return k;
}

int Power(int x, int y) {
    int z = 1;
    for (int i = 0; i < y; i++) {
        z *= x;
    }
    return z;
}

void LookandSay(int num24[], int num25) {
    int z = 0;
    int y = num24[0];
    for (int i = 0; i < num25 + 1; i++) {
        //cout << "\narray number right now: " << num24[i] << endl;
        if (num24[i] == y) {
            z++;
            
            continue;
        }
        if (i != 0) { cout << z << ", " << y << ", "; }
        //cout << "\n" << num24[i] << endl;
        
        y = num24[i];
        z = 1;
    }
}

void SPR(string playerInput) {
    string cpuInput;
    switch (rand() % 3) {
    case(0):
        cpuInput = "Scissors";
        break;
    case(1):
        cpuInput = "Rock";
        break;
    case(2):
        cpuInput = "Paper";
        break;
    }

    cout << "\n The computer played " << cpuInput << endl;

    if ((playerInput == "Paper" || playerInput == "paper") && cpuInput == "Scissors") { cout << "You Lose!\n" << endl; }
    if ((playerInput == "Paper" || playerInput == "paper") && cpuInput == "Paper") { cout << "It's a Tie!\n" << endl; }
    if ((playerInput == "Paper" || playerInput == "paper") && cpuInput == "Rock") { cout << "You Win!\n" << endl; }
    if ((playerInput == "Rock" || playerInput == "rock") && cpuInput == "Scissors") {cout << "You Win!\n" << endl;}
    if ((playerInput == "Rock" || playerInput == "rock") && cpuInput == "Paper") {cout << "You Lose!\n" << endl;}
    if ((playerInput == "Rock" || playerInput == "rock") && cpuInput == "Rock") { cout << "It's a Tie!\n" << endl;}
    if ((playerInput == "Scissors" || playerInput == "scissors") && cpuInput == "Scissors") { cout << "It's a Tie!\n" << endl;}
    if ((playerInput == "Scissors" || playerInput == "scissors") && cpuInput == "Paper") {cout << "You Win!\n" << endl;}
    if ((playerInput == "Scissors" || playerInput == "scissors") && cpuInput == "Rock") {cout << "You Lose!\n" << endl;}
    
}
bool PlayAgain() {
    if (!played){ cout << "\nWant to play Scissors Paper Rock? (Yes/No)" << endl; }
    else { cout << "\nWill you play again? (Yes/No)" << endl; }
    string again;
    cin >> again;
    if (again == "No") { return false; }
    else if (again == "no") { return false; }
    else { return true; }
}