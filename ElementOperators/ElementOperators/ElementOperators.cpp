
#include <iostream>
#include <random>
#include <cstdlib>

int randomRange(int min, int max);

void mainMenu();

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


// Tree + Fire // Transfering Bark to Fuel
Tree operator + (const Tree& left, Fire& right) {
    Tree* x = new Tree();
    x->leaves = left.leaves;
    x->bark = left.bark - right.heat;
    std::cout << "\nThe fire has burned " << right.heat << " bark away and turned it into fuel!";
    system("pause");
    system("cls");
    right.fuel += right.heat * 1.1;
    return *x;
}

// Tree + Water // Transfering Liquid to Bark and Leaves
Tree operator + (const Tree& left, Water& right) {
    Tree* x = new Tree();
    x->leaves = left.leaves + 8;
    x->bark = left.bark + 1;
    std::cout << "\nYou have converted 1 liquid into 8 leaves and 2 bark!\n";
    system("pause");
    system("cls");
    right.liquid--;
    return *x;
}

// Tree + Magic // Transfering a bit of Mana to Bark
Tree operator + (const Tree& left, Magic& right) {
    Tree* x = new Tree();
    x->leaves = left.leaves;
    x->bark = left.bark + (right.mana / 10); // Adds 10% of mana to bark
    std::cout << "\nYou have converted " << right.mana * 0.66 << " mana into " << right.mana / 10 << " leaves!\n";
    system("pause");
    system("cls");
    right.mana *= 0.66;
    return *x;
}

// Tree * Fire // Random Chance for Fire to burn some Leaves
Tree operator * (const Tree& left, const Fire& right) {
    Tree* x = new Tree();
    x->leaves = left.leaves * 0.85;
    x->bark = left.bark;
    std::cout << "\nThe fire has burned " << left.leaves * 0.85 << " leaves!\n";
    system("pause");
    system("cls");
    return *x;
}

// Tree * Water // Transfering a few Leaves into a bit of Liquid
Water operator * (Tree& left, const Water& right) {
    Water* x = new Water();
    x->liquid = right.liquid + 1;
    x->ice = right.ice;
    left.leaves -= 16;
    std::cout << "\nYou have converted 16 leaves into 1 liquid!\n";
    system("pause");
    system("cls");
    return *x;
}

// Tree * Magic // Transfering Leaves to a bit of Mana
Magic operator * (Tree& left, const Magic& right) {
    Magic* x = new Magic();
    x->mana = right.mana + 4;
    left.leaves -= 16;
    std::cout << "\nYou have converted 16 leaves into 4 mana!\n";
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
    x->liquid = right.liquid + 2;
    x->ice = right.ice;
    left.bark -= 1;
    std::cout << "\nYou have converted 1 bark into 2 liquid!\n";
    system("pause");
    system("cls");
    return *x;
}

// Tree && Magic // Transfering Bark into Mana
Magic operator && (Tree& left, const Magic& right) {
    Magic* x = new Magic();
    x->mana = right.mana + 16;
    left.bark -= 2;
    std::cout << "\nYou have converted 2 bark into 16 mana!\n";
    system("pause");
    system("cls");
    return *x;
}

// Fire + Water // Transfering Ice and Heat into Liquid
Water operator + (Fire& left, const Water& right) {
    Water* x = new Water();
    x->liquid = right.liquid + 1;
    x->ice = right.ice - 1;
    left.heat *= 0.70;
    std::cout << "\nYou have reduced the heat of the fire by using 1 ice, and got 1 liquid!\n";
    system("pause");
    system("cls");
    return *x;
}

// Magic + Fire // Removes a bit of Mana and Fuel
Magic operator + (const Magic& left,  Fire& right) {
    Magic* x = new Magic();
    x->mana = left.mana - 1;
    right.fuel -= 4;
    std::cout << "\nYou have used 1 mana to get rid of 4 fuel!\n";
    system("pause");
    system("cls");
    return *x;
}

// Water + Magic // Transfers a bit of Mana into Ice
Water operator + (Magic& left, const Water& right) {
    Water* x = new Water();
    x->liquid = right.liquid;
    x->ice = right.ice + 3;
    left.mana--;
    std::cout << "\nYou have converted 1 mana into 3 ice!\n";
    system("pause");
    system("cls");
    return *x;
}

// Magic * Fire // Transfers Mana into Heat
Fire operator * (Magic& left, const Fire& right) {
    Fire* x = new Fire();
    x->fuel = right.fuel;
    x->heat = right.heat + 2;
    left.mana--;
    std::cout << "\nYou have converted 1 mana into 2 heat!\n";
    system("pause");
    system("cls");
    return *x;
}

// Magic && Fire // Transfers Mana into Fuel
Fire operator && (Magic& left, const Fire& right) {
    Fire* x = new Fire();
    x->fuel = right.fuel + 5;
    x->heat = right.heat;
    left.mana--;
    std::cout << "\nYou have converted 1 mana into 5 fuel!\n";
    system("pause");
    system("cls");
    return *x;
}

// Water + Water // Turns Liquid into Ice
Water operator + (const Water& left, const Water& right) {
    Water* x = new Water();
    x->liquid = left.liquid;
    x->ice = right.ice + 1;
    std::cout << "\nYou have converted 1 liquid into 1 ice!\n";
    system("pause");
    system("cls");
    return *x;
}


int main()
{
    Tree tree{ 10,20 };
    Water water{ 3,3 };
    Fire fire{ 5,2 };
    Magic magic{ 10 };
    while (tree.bark != 0 || tree.bark < 0) {
        mainMenu();
    }

}

// FUNCTIONS NEEDED
// 1. Function for main interaction menu
//  1.1. Functions for all of the different interactions
// 2. Function for selecting a random mana event
// 3. Function for burning tree

void mainMenu() {
    std::cout << "\nWhat would you like to interact with? (Input a number 1-5)\n"
        << "1. Tree\n"
        << "2. Fire\n"
        << "3. Water\n"
        << "4. Magic\n"
        << "5. Continue\n";
    std::string userInput;
    std::cin >> userInput;
    if      (userInput == "1") {} // Function for 
    else if (userInput == "2") {}
    else if (userInput == "3") {}
    else if (userInput == "4") {}
    else if (userInput == "5") {}
    else {}
}

int randomRange(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(min, max);
    return distrib(gen);
}
