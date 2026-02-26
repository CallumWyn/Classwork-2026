
#include <iostream>
#include <random>
#include <cstdlib>
#include <cmath>

int randomRange(int min, int max);

void mainMenu();
void treeMenu();
void fireMenu();
void waterMenu();
void magicMenu();

void printResources();

std::string userInput;

int amount = 1;
int roundNumber = 1;
int turnNumber = 1;
int randomNumber;
int continueNumber;



struct Tree { // If tree runs out of bark, it's game over
    int bark; // Basically your life points. If you run out, it's game over.
    int leaves; // When added to magic, it can add to mana, and subtract from leaves
};
struct Fire { // If the fire runs out of fuel, you win
    int fuel; // When added to tree, it can subtract from bark, and add to fuel. The amount added is based on heat
    int heat; // Heat consumes a bit of fuel every round, and increases exponentionally depending on what the original heat value is
};
struct Water {
    int liquid; // When added to tree, it can add to bark and leaves, and subtract from liquid
    int ice; // When added to fire, it subtracts from ice and ???, and adds to liquid
};
struct Magic { // We can make magic a random event, that can have a good or bad effect.
    float mana; // When mana is added to anything, a multiplicative value is added to that, and a small amount of mana is removed. 
                // It can be added to bark, heat and ice
};

Tree tree{ 10,20 };
Water water{ 4,3 };
Fire fire{ 5,10 };
Magic magic{ 10 };


// Tree + Fire // Transfering Bark to Fuel & Fuel to Fire
Tree operator + (const Tree& left, Fire& right) {
    Tree* x = new Tree();
    x->leaves = left.leaves;
    x->bark = left.bark - floor(right.heat*0.30);
    std::cout << "\nThe fire has burned " << floor(right.heat*0.30) << " bark away and turned it into fuel!\n";
    system("pause");
    system("cls");
    right.fuel += (right.heat > 3 ) ? floor(right.heat*0.30) : ceil(right.heat * 0.30);
    right.heat += ceil(right.fuel*0.2);
    return *x;
}

// Tree + Water // Transfering Liquid to Bark and Leaves
Tree operator + (const Tree& left, Water& right) {
    Tree* x = new Tree();
    x->leaves = left.leaves + 8*amount;
    x->bark = left.bark + amount;
    std::cout << "\nYou have converted " << amount << " liquid into "<< 8*amount << " leaves and " << amount << " bark!\n";
    system("pause");
    system("cls");
    right.liquid -= amount;
    return *x;
}

// Tree + Magic // Transfering a bit of Mana to Bark
Tree operator + (const Tree& left, Magic& right) {
    Tree* x = new Tree();
    x->leaves = left.leaves;
    x->bark = left.bark + randomRange(1,4);
    right.mana -= 5;
    std::cout << "\nYou have converted 5 mana into some bark!\n";
    system("pause");
    system("cls");
    return *x;
}

// Tree * Fire // Random Chance for Fire to burn some Leaves
Tree operator * (const Tree& left, const Fire& right) {
    Tree* x = new Tree();
    x->leaves = floor(left.leaves * 0.5);
    x->bark = left.bark;
    std::cout << "\nThe fire has burned " << floor(left.leaves * 0.5) << " leaves!\n";
    system("pause");
    system("cls");
    return *x;
}

// Tree * Water // Transfering a few Leaves into a bit of Liquid
Water operator * (Tree& left, const Water& right) {
    Water* x = new Water();
    x->liquid = right.liquid + amount;
    x->ice = right.ice;
    left.leaves -= 16*amount;
    std::cout << "\nYou have converted " << 16*amount << " leaves into " << amount << " liquid!\n";
    system("pause");
    system("cls");
    return *x;
}

// Tree * Magic // Transfering Leaves to a bit of Mana
Magic operator * (Tree& left, const Magic& right) {
    Magic* x = new Magic();
    x->mana = right.mana + 4*amount;
    left.leaves -= 16*amount;
    std::cout << "\nYou have converted " << 16*amount << " leaves into " << 4*amount << " mana!\n";
    system("pause");
    system("cls");
    return *x;
}

// Tree && Fire // Willingly sacrificing the entire tree to Fire
Tree operator && (const Tree& left, Fire& right) {
    Tree* x = new Tree();
    x->leaves = 0;
    x->bark = 0;
    right.fuel += left.bark * 1.1;
    std::cout << "\nThe fire has burned away the entire tree!\n";
    system("pause");
    system("cls");
    return *x;
}

// Tree && Water // Transfering a bit of Bark into Liquid
Water operator && (Tree& left, const Water& right) {
    Water* x = new Water();
    x->liquid = right.liquid + amount/2;
    x->ice = right.ice;
    left.bark -= amount;
    std::cout << "\nYou have converted " << amount << " bark into " << amount/2 << " liquid!\n";
    system("pause");
    system("cls");
    return *x;
}

// Tree && Magic // Transfering Bark into Mana
Magic operator && (Tree& left, const Magic& right) {
    Magic* x = new Magic();
    x->mana = right.mana + 8*amount;
    left.bark -= amount;
    std::cout << "\nYou have converted " << amount << " bark into " << 8*amount << " mana!\n";
    system("pause");
    system("cls");
    return *x;
}

// Fire + Water // Transfering Ice and Heat into Liquid
Water operator + (Fire& left, const Water& right) {
    Water* x = new Water();
    x->liquid = right.liquid + amount;
    x->ice = right.ice - amount;
    left.heat -= amount;
    std::cout << "\nYou have reduced the heat of the fire by using " << amount << " ice, and got " << amount << " liquid!\n";
    system("pause");
    system("cls");
    return *x;
}

// Magic + Fire // Removes a bit of Mana and Fuel
Magic operator + (const Magic& left,  Fire& right) {
    Magic* x = new Magic();
    x->mana = left.mana - 5;
    right.fuel -= randomRange(2,4);
    std::cout << "\nYou have used 5 mana to get rid of some fuel!\n";
    system("pause");
    system("cls");
    return *x;
}

// Water + Magic // Transfers a bit of Mana into Ice
Water operator + (Magic& left, const Water& right) {
    Water* x = new Water();
    x->liquid = right.liquid;
    x->ice = right.ice + randomRange(2,6);
    left.mana -= 5;
    std::cout << "\nYou have converted 5 mana into some ice!\n";
    system("pause");
    system("cls");
    return *x;
}

// Magic * Fire // Transfers Mana into Heat
Fire operator * (Magic& left, const Fire& right) {
    Fire* x = new Fire();
    x->fuel = right.fuel;
    x->heat = right.heat + randomRange(2,4);
    left.mana -= 5;
    std::cout << "\nYou have converted 5 mana into some heat!\n";
    system("pause");
    system("cls");
    return *x;
}

// Magic && Fire // Transfers Mana into Fuel
Fire operator && (Magic& left, const Fire& right) {
    Fire* x = new Fire();
    x->fuel = right.fuel + randomRange(3,5);
    x->heat = right.heat;
    left.mana -= 5;
    std::cout << "\nYou have converted 5 mana into some fuel!\n";
    system("pause");
    system("cls");
    return *x;
}

// Water + Water // Turns Liquid into Ice
Water operator + (const Water& left, const Water& right) {
    Water* x = new Water();
    x->liquid = left.liquid - amount*4;
    x->ice = right.ice + amount;
    std::cout << "\nYou have converted " << amount*4 << " liquid into " << amount << " ice!\n";
    system("pause");
    system("cls");
    return *x;
}
// Water += Water // Collects a random amount of Liquid
Water operator += (const Water& left, const Water& right) {
    Water* x = new Water();
    randomNumber = randomRange(2, 6);
    x->liquid = left.liquid + randomNumber;
    x->ice = left.ice;
    std::cout << "\nYou went to a nearby river and managed to collect " << randomNumber << " liquid\n";
    system("pause");
    system("cls");
    return *x;
}


int main()
{
    
    while ((tree.bark > 0) && (fire.heat > 0) && (fire.fuel > 0)) {
        mainMenu();
        roundNumber++;
    }

    if (fire.heat <= 0 || fire.fuel <= 0) {
        std::cout << "\nYou Win!";
    }
    if (tree.bark <= 0) {
        std::cout << "\nGame Over!";
    }

}


void mainMenu() {
    for (int i = 1; i < 6; i++) { // I made this a for loop so that you can have multiple turns in a round
        continueNumber = 0;
        turnNumber = i;
        system("cls");
        printResources();
        std::cout << "What would you like to interact with? (Input a number 1-5)\n"
            << "1. Tree\n"
            << "2. Fire\n"
            << "3. Water\n"
            << "4. Magic\n"
            << "5. Continue\n\n";
        std::cin >> userInput;
        if (userInput == "1") { treeMenu(); }
        else if (userInput == "2") { fireMenu(); }
        else if (userInput == "3") { waterMenu(); }
        else if (userInput == "4") { magicMenu(); }
        else if (userInput == "5") { break; }
        else { i -= 1; continue; }
        i -= continueNumber;
    }

    if ((fire.heat != 0) && (fire.fuel != 0)) {
        system("cls");
        printResources();
        // This function removes a percentage of bark based on heat
        tree = tree + fire;
        randomNumber = randomRange(1, 10);
        // Gets a random number and has a 20% chance of running tree * fire
        switch (randomNumber) {
        case(10):
        case(9):
            tree = tree * fire;
        }
    }
}

// Either need to turn these into int functions and return -1 if back is selected, or make a new variable to deal with it
void treeMenu() {
    while (true) {
        system("cls");
        printResources();
        std::cout << "What would you like to do? (Input a number 1-5)\n"
            << "1. Turn Liquid into Bark & Leaves\n"
            << "2. Turn Leaves into Liquid\n"
            << "3. Turn Leaves into Mana\n"
            << "4. Turn Bark into Mana\n"
            << "5. Turn Bark into Liquid\n"
            << "6. Back\n\n";
        std::cin >> userInput;
        if (userInput == "1") { 
            std::cout << "How much would you like to convert: "; 
            std::cin >> amount; 
            // Checks to see if the amount selected is more than the amount you own
            if (water.liquid < amount) { std::cout << "\nYou do not have enough of this resource to convert\n"; system("pause"); }
            else if (water.liquid >= amount) { tree = tree + water; break; } // Transfering Liquid to Bark and Leaves
        }
        else if (userInput == "2") {
            std::cout << "How much would you like to convert (16:1): ";
            std::cin >> amount;
            // Checks to see if the amount selected is more than the amount you own
            if (tree.leaves < amount) { std::cout << "\nYou do not have enough of this resource to convert\n"; system("pause"); }
            // Also checks to see if it is a multiple of 16, as 16 leaves turn into 1 liquid, but 24 leaves does not turn into 1.5 liquid
            else if (amount % 16 != 0) { std::cout << "\nThe amount you select must be an increment of 16\n"; system("pause"); }
            // Divides amount by 16 so it can be used correctly in the equation
            else if (tree.leaves >= amount) { amount /= 16; water = tree * water; break; } // Transfering a few Leaves into a bit of Liquid
        }
        else if (userInput == "3") {
            std::cout << "How much would you like to convert (16:1): ";
            std::cin >> amount;
            // Checks to see if the amount selected is more than the amount you own
            if (tree.leaves < amount) { std::cout << "\nYou do not have enough of this resource to convert\n"; system("pause"); }
            // Also checks to see if it is a multiple of 16, as 16 leaves turn into 1 liquid, but 24 leaves does not turn into 1.5 liquid
            else if (amount % 16 != 0) { std::cout << "\nThe amount you select must be an increment of 16\n"; system("pause"); }
            // Divides amount by 16 so it can be used correctly in the equation
            else if (tree.leaves >= amount) { amount /= 16; magic = tree * magic; break; } // Transfering Leaves to a bit of Mana
        }
        else if (userInput == "4") {
            std::cout << "How much would you like to convert: ";
            std::cin >> amount;
            // Checks to see if the amount selected is more than the amount you own, and also makes sure you don't end the game by converting too much bark
            if ((tree.bark < amount) || (tree.bark - amount <= 0)) { std::cout << "\nYou do not have enough of this resource to convert\n"; system("pause"); }
            else if (tree.bark >= amount) { magic = tree && magic; break; } // Transfering Bark into Mana
        }
        else if (userInput == "5") {
            std::cout << "How much would you like to convert (2:1): ";
            std::cin >> amount;
            // Checks to see if the amount selected is more than the amount you own, and also makes sure you don't end the game by converting too much bark
            if ((tree.bark < amount) || (tree.bark - amount <= 0)) { std::cout << "\nYou do not have enough of this resource to convert\n"; system("pause"); }
            else if (amount % 2 != 0) { std::cout << "\nThe amount you select must be an increment of 2\n"; system("pause"); }
            else if (tree.bark >= amount) { water = tree && water; break; } // Transfering a bit of Bark into Liquid
        }
        else if (userInput == "6") { continueNumber++; break; }
    }
    
}

void fireMenu() {
    while (true) {
        system("cls");
        printResources();
        std::cout << "What would you like to do? (Input a number 1-2)\n"
            << "1. Sacrifice the Tree to the Fire\n"
            << "2. Back\n\n";
        std::cin >> userInput;
        if (userInput == "1") {
            // Asks the user just in case they don't want to end the game
            std::cout << "Are you sure? This will end the game (Input Yes or No): ";
            std::cin >> userInput;
            // Sets all the letters in the string to upper case
            for (auto& i : userInput) {
                i = toupper(i);
            }
            if (userInput == "YES") { tree = tree && fire; break; } // Willingly sacrificing the entire tree to Fire
        }
        else if (userInput == "2") { continueNumber++; break; }
    }
}

void waterMenu() {
    while (true) {
        system("cls");
        printResources();
        std::cout << "What would you like to do? (Input a number 1-3)\n"
            << "1. Turn Ice and Heat into Liquid\n"
            << "2. Turn Liquid into Ice\n"
            << "3. Collect Liquid\n"
            << "4. Back\n\n";
        std::cin >> userInput;
        if (userInput == "1") {
            std::cout << "How much would you like to convert: ";
            std::cin >> amount;
            // Checks to see if the amount selected is more than the amount you own
            if (water.ice < amount) { std::cout << "\nYou do not have enough of this resource to convert\n"; system("pause"); }
            else if (water.ice >= amount) { water = fire + water; break; } // Transfering Ice and Heat into Liquid
        }
        else if (userInput == "2") {
            std::cout << "How much would you like to convert (4:1): ";
            std::cin >> amount;
            // Checks to see if the amount selected is more than the amount you own
            if (water.liquid < amount) { std::cout << "\nYou do not have enough of this resource to convert\n"; system("pause"); }
            else if (amount % 4 != 0) { std::cout << "\nThe amount you select must be an increment of 4\n"; system("pause"); }
            else if (water.liquid >= amount) { amount /= 4; water = water + water; break; } // Turns Liquid into Ice
        }
        else if (userInput == "3") {
            water = water += water; // Collects a random amount of Liquid
            break;
        }
        else if (userInput == "4") { continueNumber++; break; }
    }
}

// Tree + Magic // Transfering a bit of Mana to Bark
// Magic + Fire // Removes a bit of Mana and Fuel
// Water + Magic // Transfers a bit of Mana into Ice
// Magic * Fire // Transfers Mana into Heat
// Magic && Fire // Transfers Mana into Fuel

void magicMenu() {
    while (true) {
        system("cls");
        printResources();
        std::cout << "Are you sure you want to use 5 mana on a random magic action? (Yes/No)\n";
        std::cin >> userInput;
        // Sets the string to full caps
        for (auto& i : userInput) {
            i = toupper(i);
        }
        // Checks if the player has enough mana
        if (magic.mana >= 5) {
            // Checks if the input was a variation of YES (yes, YeS, etc)
            if (userInput == "YES") {
                int randInput = randomRange(0, 9);
                // Gets a random number and chooses a operation at random
                switch (randInput) {
                case(0):
                case(5):
                case(8):
                    tree = tree + magic; break; // 30% // Transfering a bit of Mana to Bark
                case(1):
                case(6):
                    magic = magic + fire; break; // 20% // Removes a bit of Mana and Fuel
                case(2):
                case(7):
                case(9):
                    water = magic + water; break; // 30% // Transfers a bit of Mana into Ice
                case(3):
                    fire = magic * fire; break; // 10% // Transfers Mana into Heat
                case(4):
                    fire = magic && fire; break; // 10% // Transfers Mana into Fuel
                }
                break;
            }
            if (userInput == "NO") { continueNumber++; break; }
        }
        else { std::cout << "\nYou do not have enough mana"; continueNumber++; break; }
    }
}

void printResources() {
    // Basically just prints a list of all of the resources the player owns
    std::cout << "Round " << roundNumber
        << "\nTurn " << turnNumber << "\n";
    std::cout << "\n" << "TREE:  " << tree.bark << " Bark    " << tree.leaves << " Leaves\n"
        << "WATER: " << water.liquid << " Liquid   " << water.ice << " Ice\n"
        << "FIRE:  " << fire.fuel << " Fuel     " << fire.heat << " Heat\n"
        << "MAGIC: " << magic.mana << " Mana\n\n\n";
}

int randomRange(int min, int max) { // Just a function I use to generate random numbers whenever I need them
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(min, max);
    return distrib(gen);
}

