#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include <vector>
#include <random>

int day = 1;
int eventDay = 5;
int lastEventDay;
int randomCity;
bool event = false;
bool collectedPeople = false;
unsigned int peopleStorage;

enum Events {
    ArtistAlley,
    BusinessConfrence,
    TeacherInterviews,
    Earthquake,
    Tsunami,
    Landslide,
    Tornado
};

vector<string> listOfEvents = { "Artist Alley", "A Business Confrence", "Teacher Interviews", "Earthquake", "Tsunami", "Landslide", "Tornado"};

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
void killPeople(Suburb& suburb, pair<float,float> popPercentRange);
int chooseRandomCity(const vector<int> list, int size);
int randomBetweenRange(int min, int max);

Suburb suburbList[8] = { suburb1,suburb2,suburb3,suburb4,suburb5,suburb6,suburb7,suburb8 };
unsigned int popMovedOut;
unsigned int popDead;

int main()
{
    srand(time(NULL));

    while (true) {
        cout << "\nDay " << day << endl;
        cout << "\nAmount of people in each city: \n" << endl;

        // Prints every city's population
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

        cout << "\nAfter one day...\n" << endl;
        publicTransport();

        // This ensures that events happen
        if (eventDay == day) {
            event = true;
            lastEventDay = eventDay;
            eventDay += 5;
            currentEvent = Events(randomBetweenRange(0,6));
        }

        if (event) {
            // publicTransportManual(8, 100, suburbList[3]);
            if (currentEvent == ArtistAlley) { // Brings all the artists to a random artist suburb (5, 8)
                if (lastEventDay == day) { randomCity = randomBetweenRange(1,2); }
                switch (randomCity) {
                case(1):
                    publicTransport(5, 50, suburbList[7]);
                    break;
                case(2):
                    publicTransport(8, 50, suburbList[4]);
                    break;
                }
            }
            else if (currentEvent == BusinessConfrence) { // Brings all of the workers to a random worker suburb (1, 2, 4)
                if (lastEventDay == day) { randomCity = randomBetweenRange(1, 3); }
                switch (randomCity) {
                case(1):
                    publicTransport(1, 70, { suburbList[1],suburbList[3] });
                    break;
                case(2):
                    publicTransport(2, 70, { suburbList[0],suburbList[3] });
                    break;
                case(3):
                    publicTransport(4, 70, { suburbList[0],suburbList[1] });
                    break;
                }
            }
            else if (currentEvent == TeacherInterviews){ // Brings all teachers to a random teacher suburb (3, 6, 7)
                if (lastEventDay == day) { randomCity = randomBetweenRange(1, 3); }
                switch (randomCity) {
                case(1):
                    publicTransport(3, 90, { suburbList[5],suburbList[6] });
                    break;
                case(2):
                    publicTransport(6, 90, { suburbList[2],suburbList[6] });
                    break;
                case(3):
                    publicTransport(7, 90, { suburbList[2],suburbList[5] });
                    break;
                }
            } 
            else if (currentEvent == Earthquake) { // Earthquake hits a random city
                killPeople(suburbList[randomBetweenRange(0, 7)], { 5,25 });
                cout << " due to an Earthquake" << endl;
            }
            else if (currentEvent == Tsunami) { // Tsunami hits a random city on the coast
                killPeople(suburbList[chooseRandomCity({ 1,2,6,8 },4)], {20,30});
                cout << " due to a Tsunami" << endl;
            }
            else if (currentEvent == Landslide) { // Landslide hits a random city on the land border
                killPeople(suburbList[chooseRandomCity({ 1,5,7 }, 3)], { 10,15 });
                cout << " due to a Landslide" << endl;
            }
            else if (currentEvent == Tornado) { // Landslide hits a random city on the land border
                killPeople(suburbList[chooseRandomCity({ 3,4 }, 2)], { 30,35 }); 
                cout << " due to a Tornado" << endl;
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
    // Goes through all of the suburb's connecting suburbs list
    for (int i : suburb.connectingSuburbs) {
        // Checks if one of them matches the destination
        if (i == destinationNumber) {
            bool connecting = true;
            // cout << suburbList[suburb.suburbNumber - 1].population * (popPercent / 100) << endl;
            suburbList[destinationNumber - 1].population += (suburbList[suburb.suburbNumber - 1].population * (popPercent / 100));
            suburbList[suburb.suburbNumber - 1].population -= (suburbList[suburb.suburbNumber - 1].population * (popPercent / 100));
            break;
        }
    }
    // If none of them match, it is either 2 or 3 days travel
    if (!connecting) {
        // This makes sure that people are only collected once by changing a global bool to true
        if (!collectedPeople) {
            // Adds a percentage of people to people storage
            peopleStorage += (suburbList[suburb.suburbNumber - 1].population * (popPercent / 100));
            // Removes those people from the suburb they came from
            suburbList[suburb.suburbNumber - 1].population -= (suburbList[suburb.suburbNumber - 1].population * (popPercent / 100));
            collectedPeople = true;
        }
        // This only runs when the destination is 8 and the current location is 7, or vise versa, as they are 3 days away
        if (((destinationNumber == 8) && (suburb.suburbNumber == 7)) || ((destinationNumber == 7) && (suburb.suburbNumber == 8))) {
            if (day == lastEventDay + 3) {
                suburbList[destinationNumber - 1].population += peopleStorage;
                cout << "\n" << peopleStorage << " people have arrived in City " << destinationNumber << " for " << listOfEvents[currentEvent] << " event\n" << endl;
                peopleStorage = 0;
                collectedPeople = false;
                event = false;
            }
        }
        // Every other location takes 2 days, unless they're connecting
        else if (day == lastEventDay + 2) {
            suburbList[destinationNumber - 1].population += peopleStorage;
            cout << "\n" << peopleStorage << " people have arrived in City " << destinationNumber << " for " << listOfEvents[currentEvent] << " event\n" << endl;
            peopleStorage = 0;
            collectedPeople = false;
            event = false;
        }
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
    int arrivalDay = lastEventDay + 3;
    //if (event) {
    // Goes through all of the suburbs in the list of suburbs
    for (Suburb suburb : suburbs) {
        connecting = false;
        // Goes through all of the suburb's connecting suburbs list
        for (int i : suburb.connectingSuburbs) {
            // Makes sure the people are only collected on the first day
            if (lastEventDay == day) {
                // Checks if one of them matches the destination
                if (i == destinationNumber) {
                    connecting = true;
                    // cout << suburbList[suburb.suburbNumber - 1].population * (popPercent / 100) << endl;
                    cout << (int)(suburbList[suburb.suburbNumber - 1].population * (popPercent / 100)) << " people from City " << suburb.suburbNumber << " have gone to City " 
                        << destinationNumber << " for " << listOfEvents[currentEvent] << " event\n" << endl;
                    suburbList[destinationNumber - 1].population += (suburbList[suburb.suburbNumber - 1].population * (popPercent / 100));
                    suburbList[suburb.suburbNumber - 1].population -= (suburbList[suburb.suburbNumber - 1].population * (popPercent / 100));
                    break;
                }
            }
        }
        // If none of them match, it is either 2 or 3 days travel
        if (!connecting) {
            // This makes sure that people are only collected once
            if (!collectedPeople) {
                peopleStorage += (suburbList[suburb.suburbNumber - 1].population * (popPercent / 100));
                suburbList[suburb.suburbNumber - 1].population -= (suburbList[suburb.suburbNumber - 1].population * (popPercent / 100));
                //collectedPeople = true;
            }
            // This only runs when the destination is 8 and the current location is 7, or vise versa, as they are 3 days away
            if (((destinationNumber == 8) && (suburb.suburbNumber == 7)) || ((destinationNumber == 7) && (suburb.suburbNumber == 8))) {
                if (day == lastEventDay + 3) {
                    suburbList[destinationNumber - 1].population += peopleStorage;
                    cout << "\n" << peopleStorage << " people have arrived in City " << destinationNumber << " for " << listOfEvents[currentEvent] << " event\n" << endl;
                    peopleStorage = 0;
                    collectedPeople = false;
                    event = false;
                    break;
                }
                arrivalDay = lastEventDay + 4;
            }
            // Every other location takes 2 days, unless they're connecting
            else if (day == lastEventDay + 2) {
                suburbList[destinationNumber - 1].population += peopleStorage;
                cout << "\n" << peopleStorage << " people have arrived in City " << destinationNumber << " for " << listOfEvents[currentEvent] << " event\n" << endl;
                peopleStorage = 0;
                collectedPeople = false;
                event = false;
                break;
            }


        }
    }

    // Makes sure people aren't collected twice
    if (lastEventDay == day) {
        collectedPeople = true;
    }
    // Checks if all the people were in connecting suburbs
    if (peopleStorage == 0) {
        event = false;
        collectedPeople = false;
    }
    if (event) {
        cout << "\nThere is an event in City " << destinationNumber << " on Day " << arrivalDay << endl;
        cout << "\n" << peopleStorage << " people from far away have gone on a trip to City " << destinationNumber << " for " << listOfEvents[currentEvent] << " event\n" << endl;
    }
        
        //system("pause");
        //system("cls");
    //}
}

void killPeople(Suburb& suburb, pair<float, float> popPercentRange) {
    // Generates a random number in a range
    uniform_int_distribution<int> distrib(popPercentRange.first, popPercentRange.second);
    float killPercent = distrib(gen);
    killPercent /= 100;

    // Gets the amount of people selected from the percentage and removes it from the suburb population
    popDead = suburbList[suburb.suburbNumber - 1].population * killPercent;
    suburb.population -= popDead;

    event = false;

    // Starts a sentance that gets finished outside the function so it can change depending on what happens
    cout << popDead << " passed away in City " << suburb.suburbNumber;
}

// Just a function to choose a random number from a vector
int chooseRandomCity(const vector<int> list, int size) {
    uniform_int_distribution<int> distrib(0, size-1);
    return list[distrib(gen)] - 1;
}

int randomBetweenRange(int min, int max) {
    uniform_int_distribution<int> distrib(min, max);
    return distrib(gen);
}