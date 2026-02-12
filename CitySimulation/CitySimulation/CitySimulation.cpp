// CitySimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include <vector>
#include <unordered_map>
#include <random>


/*
 Struct for each suburb to hold how many people are in the city and what suburbs are connected to it
 Each turn can represent a day, events happen once every ten days
 
 Public transport will have to happen through a function and a for loop that goes through all the cities
 Might need temp variables to hold how many people stay in each city
 I could have 8 variables that are like "People to go to city 1" and I just add to that whenever people move to a city and subtract from the original amount

 Events related to all of the different civilians could be good

 



*/

struct Suburb {
    int suburbNumber;
    vector<int> connectingSuburbs;
    unsigned int population;
    string profession;
    unsigned int populationToMove;
};

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> distrib(1000, 100000);

Suburb suburb1 = { 1,{2,3,4,5,8}, distrib(gen),"Worker"};
Suburb suburb2 = { 2,{1,3,6,8}, distrib(gen),"Worker"};
Suburb suburb3 = { 3,{1,2,4,6}, distrib(gen),"Teacher"};
Suburb suburb4 = { 4,{1,3,5,6}, distrib(gen),"Worker"};
Suburb suburb5 = { 5,{1,4,6,7}, distrib(gen),"Artist"};
Suburb suburb6 = { 6,{2,3,4,5,8}, distrib(gen),"Teacher"};
Suburb suburb7 = { 7,{5}, distrib(gen),"Teacher"};
Suburb suburb8 = { 8,{1,2,6}, distrib(gen),"Artist"};

float randomPopPercentage;
void publicTransport();

Suburb suburbList[8] = { suburb1,suburb2,suburb3,suburb4,suburb5,suburb6,suburb7,suburb8 };
unsigned int popMovedOut;

int main()
{
    srand(time(NULL));

    cout << suburbList[0].population << endl;
    cout << suburbList[1].population << endl;
    cout << suburbList[2].population << endl;
    cout << suburbList[3].population << endl;
    cout << suburbList[4].population << endl;
    cout << suburbList[5].population << endl;
    cout << suburbList[6].population << endl;
    cout << suburbList[7].population << endl;
    

    cout << "\n\nAfter one day...\n\n";
    publicTransport();


    system("pause");

}



void publicTransport() {
    // Goes through all of the suberbs
    for (Suburb& suburb : suburbList) {
        popMovedOut = 0;
        // Goes through all of the connecting suburbs in a suburb
        for (int i : suburb.connectingSuburbs) {
            // Goes through all of the suberbs to check if one matches the connection number
            for (int k = 0; k < 8; k++) {
                if (i == suburbList[k].suburbNumber) {
                    // This calculates a random percentage to be used
                    randomPopPercentage = (rand() % 50 + 1);
                    // This adds the random percentage of people to the new city
                    suburbList[k].populationToMove += suburb.population * (randomPopPercentage/100);
                    popMovedOut += suburb.population * (randomPopPercentage / 100);
                    // This removes that random percentage of people from this city
                    suburb.population -= (suburb.population * (randomPopPercentage / 100));
                    break;
                }
            }
        }
        cout << popMovedOut << " People moved out of City " << suburb.suburbNumber << "\n" << endl;
    }

    system("pause");
    system("cls");
    cout << "\nPeople that moved: \n" << endl;

    for (int i = 0; i < 8; i++) {
        // This loop just adds all of the population that was meant to be moved onto the existing population, then wipes the populationToMove variable
        suburbList[i].population += suburbList[i].populationToMove;
        cout << suburbList[i].populationToMove << " People moved to City " << i + 1 << "\n" << endl;
        suburbList[i].populationToMove = 0;
    }
}



