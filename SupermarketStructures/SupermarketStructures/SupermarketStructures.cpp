// SupermarketStructures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

#include <vector>
#include <unordered_map>

struct Items {
    string name;
    float price;
    string category;
    int size;
};

// List of items
vector<Items> listOfItems;



struct Basket {
    vector<Items> collectedItems;
    int spaceAvailable;
};

struct Aisle {
    vector<Items> itemList;
    vector<int> itemAmounts;
    string aisleCategory;
};

struct Store {
    string storeName;
    pair<int, int> openTimes;
    int aisleAmount;
    vector<Aisle> aisles;
};


string itemCategories[12] = {
    "Cereal", // Weetbix, Rice Bubbles, Cornflakes, etc
    "Baking", // Sugar, Flour, all things like that
    "Grains", // Things like Pasta and Rice
    "Baked Goods", // Bread and All Bakery Related Things 
    "Caffine", // Different Types of Tea and Coffee
    "Herbs & Spices", // Origano, Thyme, Rosemary, etc
    "Frozen", // Chocolate, Ice Cream, Popsicles, Milk, etc
    "Meats", // Beef, Chicken, Pork, Different types and cuts of it
    "Fruits", // I feel like this is self explanitory (Apples, Banana, Capsicum, etc)
    "Vegetables" // I think this is also self explanitory (Carrots, Corn, etc)
    "Snacks", // Chips, Shapes, Cookies, etc
    "Drinks" // Coca-Cola, Pepsi, etc 
};

int main()
{

    // Makes a vector to store all of the items to go through later
    vector<Items> listOfItems;
#pragma region Items (and lots of them)

    // Cereal
    listOfItems.push_back(Items({ "Coco Pops", 7, "Cereal", 5 }));
    listOfItems.push_back(Items({ "Nutri Grain", 7, "Cereal", 5 }));
    listOfItems.push_back(Items({ "Sultana Bran", 7, "Cereal", 5 }));
    listOfItems.push_back(Items({ "Froot Loops", 7, "Cereal", 5 }));
    listOfItems.push_back(Items({ "Weet-Bix", 7, "Cereal", 6 }));
    listOfItems.push_back(Items({ "Corn Flakes", 6.9, "Cereal", 5 }));
    listOfItems.push_back(Items({ "Frosties", 9, "Cereal", 5 }));
    
    // Baking
    listOfItems.push_back(Items({ "Flour", 1.3, "Baking", 4 }));
    listOfItems.push_back(Items({ "Self Raising Flour", 1.3, "Baking", 4 }));
    listOfItems.push_back(Items({ "Bi Carb Soda", 4, "Baking", 3 }));
    listOfItems.push_back(Items({ "Baking Powder", 2.85, "Baking", 2 }));
    listOfItems.push_back(Items({ "Cocoa Powder", 8.3, "Baking", 3 }));
    listOfItems.push_back(Items({ "Caster Sugar", 3.1, "Baking", 4 }));
    listOfItems.push_back(Items({ "Brown Sugar", 4.4, "Baking", 4 }));
    listOfItems.push_back(Items({ "Icing Sugar", 4.45, "Baking", 4 }));
    listOfItems.push_back(Items({ "Raw Sugar", 1.8, "Baking", 4 }));
    listOfItems.push_back(Items({ "Eggs", 11.6, "Baking", 5 }));
    listOfItems.push_back(Items({ "Vanilla Extract", 8, "Baking", 2 }));

    // Grains
    listOfItems.push_back(Items({ "Pasta", 1.3, "Baking", 4 }));
    listOfItems.push_back(Items({ "Spagetti", 1.3, "Baking", 4 }));
    listOfItems.push_back(Items({ "Macaroni & Cheese", 1.3, "Baking", 4 }));

    // Baked Goods
    listOfItems.push_back(Items({ "Flour", 1.3, "Baking", 4 }));

    // Caffine
    listOfItems.push_back(Items({ "Flour", 1.3, "Baking", 4 }));

    // Herbs & Spices
    listOfItems.push_back(Items({ "Flour", 1.3, "Baking", 4 }));

    // Frozen
    listOfItems.push_back(Items({ "Flour", 1.3, "Baking", 4 }));

    // Meats
    listOfItems.push_back(Items({ "Flour", 1.3, "Baking", 4 }));

    // Fruits
    listOfItems.push_back(Items({ "Flour", 1.3, "Baking", 4 }));

    // Vegetables
    listOfItems.push_back(Items({ "Flour", 1.3, "Baking", 4 }));

    // Snacks
    listOfItems.push_back(Items({ "Flour", 1.3, "Baking", 4 }));

    // Drinks
    listOfItems.push_back(Items({ "Flour", 1.3, "Baking", 4 }));

    
#pragma endregion
    
    /// IDEAS /// 
/*   Structure for Stores(Store name, Open times, Number of Aisles, Aisles themselves? (Gotta store them somewhere) )
     Structure for Aisles (Items in aisle, Amount of an item found in Aisle, Category of items in aisle,etc)
     Structure for Items (Name of item, Item Category, Item price, Item Size)
     Structure for Basket (Area to store items, Amount of space)
     Structure for ??
     
     GENERAL IDEAS
     Have a list of store names and program a way to randomly select one of them, along with their open times and Aisles
     The categories of the Aisles found in the store are randomly selected
     The Aisle struct will have a list that stores the Item structures that have matching categories
     Possibly make a function that automatically sorts Items into Aisles
     Possibly make a function that will calculate total cost. Could also just make a counter for that.

     Layout could be something like this:

     "Where would you like to go?"
     "Aisle 1 - Sweets"
     "Aisle 2 - Grains"
     "Aisle 3 - Fruit"
     "Aisle 4 - Dairy"

     Would also be nice to implement a method of viewing items in the basket

     "Basket"
     "Chocolate x1"
     "Bread Rolls x3"
     "Cheese x8"

     "Remaining Space:"

     Basically just make an Average Shopping Simulator

     */


    


    

}

