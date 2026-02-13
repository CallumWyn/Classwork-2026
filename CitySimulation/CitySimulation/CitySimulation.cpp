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

    STILL TO DO
    people leave city 4 two days after events for some reason
    still need to implement a way to kill people, and make an event or two to go along with it
 



*/

int day = 1;
int eventDay = 5;
int lastEventDay;
bool event = false;
bool collectedPeople = false;
unsigned int peopleStorage;

enum Events {
    ArtistAlley,
    BusinessConfrence,
    TeacherInterviews
};

vector<string> listOfEvents = { "Artist Alley", "A Business Confrence", "Teacher Interviews" };

Events currentEvent;

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
void publicTransport(unsigned int suburbNumber, float popPercent, Suburb suburb);
void publicTransport(unsigned int suburbNumber, float popPercent, vector<Suburb> suburbs);
void killPeople(Suburb suburb);


Suburb suburbList[8] = { suburb1,suburb2,suburb3,suburb4,suburb5,suburb6,suburb7,suburb8 };
unsigned int popMovedOut;

int main()
{
    

    srand(time(NULL));

    while (true) {
        cout << "\nDay " << day << endl;
        cout << "\nAmount of people in each city: \n" << endl;

        cout << "City 1: " << suburbList[0].population << "\n" << endl;
        cout << "City 2: " << suburbList[1].population << "\n" << endl;
        cout << "City 3: " << suburbList[2].population << "\n" << endl;
        cout << "City 4: " << suburbList[3].population << "\n" << endl;
        cout << "City 5: " << suburbList[4].population << "\n" << endl;
        cout << "City 6: " << suburbList[5].population << "\n" << endl;
        cout << "City 7: " << suburbList[6].population << "\n" << endl;
        cout << "City 8: " << suburbList[7].population << "\n" << endl;

        system("pause");
        system("cls");

        // To move people between suburb that aren't neighbors, can use a day counter and say "When day == day+2, move them to suburb". If it is trying to move people from city 8 to 7 or vise versa, it will be day+3

        cout << "\nAfter one day...\n" << endl;
        publicTransport();



        if (eventDay == day) {
            event = true;
            lastEventDay = eventDay;
            eventDay += 5;
            currentEvent = Events(rand() % 3);
        }



        if (event) {
            // publicTransportManual(8, 100, suburbList[3]);
            switch (currentEvent) {
            case(ArtistAlley): // Brings all the artists to a random suburb
                switch(rand() % 2 + 1) {
                case(1):
                    publicTransport(5, 100, suburbList[7]);
                    break;
                case(2):
                    publicTransport(8, 100, suburbList[4]);
                    break;
                }
            case(BusinessConfrence): // Brings all of the workers to a random suburb
                
                switch (rand()%3 + 1) {
                case(1):
                    publicTransport(1, 100, { suburbList[1],suburbList[3] });
                    break;
                case(2):
                    publicTransport(2, 100, { suburbList[0],suburbList[3] });
                    break;
                case(3):
                    publicTransport(4, 100, { suburbList[0],suburbList[1] });
                    break;
                }
                break;
            case(TeacherInterviews): // Brings all teachers to a random suburb // 3,6,7
                switch (rand() % 3 + 1) {
                case(1):
                    publicTransport(3, 100, { suburbList[5],suburbList[6] });
                    break;
                case(2):
                    publicTransport(6, 100, { suburbList[2],suburbList[6] });
                    break;
                case(3):
                    publicTransport(7, 100, { suburbList[2],suburbList[5] });
                    break;
                }
                break;
            }
        }

        system("pause");
        system("cls");

        day++;
    }

    
}



void publicTransport() { // This version of the function is used every time a day passes, when people automatically move from suburb to suburb
    // Goes through all of the suburbs
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

void publicTransport(unsigned int destinationNumber, float popPercent, Suburb suburb) { // This version of the function is used when manually moving people from suburb to suburb (During Events and things like that)
    bool connecting = false;
    int arrivalDay = lastEventDay + 2;
    for (int i : suburb.connectingSuburbs) {
        if (i == destinationNumber) {
            bool connecting = true;
            // cout << suburbList[suburb.suburbNumber - 1].population * (popPercent / 100) << endl;
            suburbList[destinationNumber - 1].population += (suburbList[suburb.suburbNumber - 1].population * (popPercent / 100));
            suburbList[suburb.suburbNumber - 1].population -= (suburbList[suburb.suburbNumber - 1].population * (popPercent / 100));
            break;
        }
    }
    if (!connecting) {
        if (!collectedPeople) {
            peopleStorage += (suburbList[suburb.suburbNumber - 1].population * (popPercent / 100));
            suburbList[suburb.suburbNumber - 1].population -= (suburbList[suburb.suburbNumber - 1].population * (popPercent / 100));
            collectedPeople = true;
        }
        // This only runs when the destination is 8 and the current location is 7, or vise versa, as they are 3 days away
        if (((destinationNumber == 8) && (suburb.suburbNumber == 7)) || ((destinationNumber == 7) && (suburb.suburbNumber == 8))) {
            if (day == lastEventDay + 3) {
                suburbList[destinationNumber - 1].population += peopleStorage;
                peopleStorage = 0;
                collectedPeople = false;
                event = false;
            }
        }
        // Every other location takes 2 days, unless they're connecting
        else if (day == lastEventDay + 2) {
            suburbList[destinationNumber - 1].population += peopleStorage;
            peopleStorage = 0;
            collectedPeople = false;
            event = false;
        }
        /*if (event) {
            cout << peopleStorage << " people have gone on a trip to City " << destinationNumber << "\n" << endl;
        }*/

    }

    if (event) {
        cout << "\nThere is an event in City " << destinationNumber << " on Day " << arrivalDay << endl;
        cout << "\n" << peopleStorage << " people have gone on a trip to City " << destinationNumber << " for " << listOfEvents[currentEvent] << " event" << endl;
        /*system("pause");
        system("cls");*/
    }


}

void publicTransport(unsigned int destinationNumber, float popPercent, vector<Suburb> suburbs) {
    bool connecting = false;
    int arrivalDay = lastEventDay + 2;
    for (Suburb suburb : suburbs) {
        for (int i : suburb.connectingSuburbs) {
            if (lastEventDay == day) {
                if (i == destinationNumber) {
                    bool connecting = true;
                    // cout << suburbList[suburb.suburbNumber - 1].population * (popPercent / 100) << endl;
                    suburbList[destinationNumber - 1].population += (suburbList[suburb.suburbNumber - 1].population * (popPercent / 100));
                    suburbList[suburb.suburbNumber - 1].population -= (suburbList[suburb.suburbNumber - 1].population * (popPercent / 100));
                    break;
                }
            }
        }
        if (!connecting) {
            if (!collectedPeople) {
                peopleStorage += (suburbList[suburb.suburbNumber - 1].population * (popPercent / 100));
                suburbList[suburb.suburbNumber - 1].population -= (suburbList[suburb.suburbNumber - 1].population * (popPercent / 100));
                //collectedPeople = true;
            }
            // This only runs when the destination is 8 and the current location is 7, or vise versa, as they are 3 days away
            if (((destinationNumber == 8) && (suburb.suburbNumber == 7)) || ((destinationNumber == 7) && (suburb.suburbNumber == 8))) {
                if (day == lastEventDay + 3) {
                    suburbList[destinationNumber - 1].population += peopleStorage;
                    peopleStorage = 0;
                    collectedPeople = false;
                    event = false;
                }
                arrivalDay = lastEventDay + 3;
            }
            // Every other location takes 2 days, unless they're connecting
            else if (day == lastEventDay + 2) {
                suburbList[destinationNumber - 1].population += peopleStorage;
                peopleStorage = 0;
                collectedPeople = false;
                event = false;
            }


        }
    }
    if (lastEventDay == day) {
        collectedPeople = true;
    }
    if (peopleStorage == 0) {
        event = false;
        collectedPeople = false;
    }
    if (event) {
        cout << "\nThere is an event in City " << destinationNumber << " on Day " << arrivalDay << endl;
        cout << "\n" << peopleStorage << " people have gone on a trip to City " << destinationNumber << " for " << listOfEvents[currentEvent] << " event\n" << endl;
        //system("pause");
        //system("cls");
    }
}

