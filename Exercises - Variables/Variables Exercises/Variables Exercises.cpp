#include <iostream>
#include <cstdlib>
using namespace std;



int main() {
	// Exercise 1

	// I deleted it as I went through it

	
	// Exercise 2
	// Celsius to Fahrenheit

	float degCelsius = 78.0f;
	float degFahrenheit = 0.0f; // Modify this variable below.

	degFahrenheit = 1.8 * degCelsius + 32;

	std::cout << "Celsius to Fahrenheit)" << std::endl;
	std::cout << "Celsius:    " << degCelsius << std::endl;
	std::cout << "Fahrenheit: " << degFahrenheit << "\n\n" << std::endl;


	// Exercise 3
	// Area of a Rectangle

	float rectWidth = 0.0f;  // Modify this variable below.
	float rectHeight = 0.0f; // Modify this variable below.
	float rectArea = 0.0f;   // Modify this variable below.

	cout << "Rectangle Height?\n";
	cin >> rectHeight;
	cout << "Rectangle Width?\n";
	cin >> rectWidth;

	rectArea = rectHeight * rectWidth;

	std::cout << "Area of a Rectangle)" << std::endl;
	std::cout << "H: " << rectHeight << " , W: " << rectWidth << std::endl;
	std::cout << "Area: " << rectArea << "\n\n" << std::endl;


	// Exercise 4
	// Average of Five
	srand(time(0));

	float a, b, c, d, e;    // Modify these variables below.
	float avg;              // Modify this variable below.
	avg = a = b = c = d = e = 0.0f; // Initialize all to zero.
	a = rand() % 100;
	b = rand() % 100;
	c = rand() % 100;
	d = rand() % 100;
	e = rand() % 100;
	avg = (a + b + c + d + e) / 5;
	

	std::cout << "Average of Five" << std::endl;
	std::cout << a << "," << b << "," << c << "," << d << "," << e << std::endl;
	std::cout << "avg: " << avg << std::endl;


	// Exercise 5
	// Number Swap

	int x;
	int y;
	int z;

	cout << "\n\nFirst number? (x)" << endl;
	cin >> x;
	cout << "Second number? (y)" << endl;
	cin >> y;

	z = y;
	y = x;
	x = z;

	std::cout << "Number Swap" << std::endl;
	std::cout << "x is " << x << std::endl;
	std::cout << "y is " << y << std::endl;


	// Exercise 6
	// Fun Facts for Your Age

	int age;

	cout << "\n\nHow old are you?" << endl;
	cin >> age;

	// <Your work can go here.>

	// <You must add more lines to output to the terminal>
	std::cout << "Howdy! You are " << age << " years old!" << endl;
	cout << "You have lived for at least " << age * 12 << " months!" << endl;
	cout << "You have lived for " << age / 10 << " decades!" << endl;


	// Challenge 1
	// Conforming to Conventions

	//int age;
	//int bullet_count;
	//float dog_years;
	//int qty;
	//float shield_value;
	//float defense_matrix_cooldown;
	//int red_armor_value;
	//float red_armor_ratio;
	//int happiness;
	//int gandhi_aggression;

	// Challenge 2
	// The Right Tool for the Job

	//float a;
	//int b;
	//string c;
	//enum d;
	//bool e;
	//long f;
	//short g;
	//unsigned h;
	//double i;
	//char j;
	//int k[1];

	// Challenge 3
	// Number Swap (Difficulty Up)

	float x2[2];
	float y2[2];

	cout << "\n\nFirst number? (x)" << endl;
	cin >> x2[0];
	x2[1] = x2[0];
	cout << "Second number? (y)" << endl;
	cin >> y2[0];
	y2[1] = y2[0];

	x2[0] = y2[1];
	y2[0] = x2[1];

	std::cout << "Number Swap" << std::endl;
	std::cout << "x is " << x2[0] << std::endl;
	std::cout << "y is " << y2[0] << std::endl;


}




