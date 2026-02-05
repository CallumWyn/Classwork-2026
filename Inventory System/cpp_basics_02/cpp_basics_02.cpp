#include <iostream>
using namespace std;

int main(){
    
	//cout << "\n .......... branching/condition statement ......  " << endl;

	// // 01 //////////////////
	//int a = 75;
	//int b = 2;

	//if (a > b) {
	//	cout << " a > b --  a is greater than b " << endl;
	//}
	//if (a < b) {
	//	cout << " a < b --  a is less than b   " << endl;
	//}
	//if (a == b) {
	//	cout << " a == b  ---  a is equal to b   " << endl;
	//}


	// // 02 //////////////////
	//string name_02 = "";
	//cout << "   01 ++ enter Supreme Commander fraction:  " << endl;
	//cin >> name_02;

	//if (name_02 == "Cybran") {
	//	cout << "  >>>>    Same team ...  " << endl;
	//}
	//else if (name_02 == "UEF") {
	//	cout << "  >>>>    Enemy detected !  " << endl;
	//}
	//else if (name_02 == "Aeon") {
	//	cout << "  >>>>    .. friendly unit.  " << endl;
	//}
	//else {
	//	cout << " unknown >>>> " << name_02 << endl;
	//}

	// // 03 //////////////////
	//int EnemyRank = 0;
	//cout << "\n   ++ enter Enemy Rank (1 - 4):  " << endl;
	//cin >> EnemyRank;

	//switch (EnemyRank) {
	//case 4:
	//	cout << "  xx  Total damage to shield.\n\n\n";
	//	break;
	//case 3:
	//	cout << "  xx  Serious damage to shield.\n\n\n";
	//	break;
	//case 2:
	//	cout << "  xx  Shield disabled for 5 sec, no damage.\n\n\n";
	//	break;
	//case 1:
	//	cout << "  xx  Minor damage to shield.\n\n\n";
	//	break;
	//default:
	//	cout << "-- no effect --- \n\n\n";
	//}

	// // research: https://stackoverflow.com/questions/650162/why-cant-the-switch-statement-be-applied-to-strings


	// // 04 //////////////////
	// ------ AND logic
	//bool Air = true;
	//bool Water = true;

	//if (Air && Water) { // AND operator 
	//	cout << "  ++ LIFE is possible ++   " << endl;
	//} else {
	//	cout << "  ++ we need AIR and WATER ++   " << endl;
	//}

	// ------ OR logic
	//bool Train = true;
	//bool AirPlane = true;

	//if (Train || AirPlane) { // OR operator 
	//	cout << "  ++ Traveling possible ++   " << endl;
	//	if (Train) { /* train messages */ }
	//	if (AirPlane) { /* plane messages */ }
	//} else {
	//	cout << "  ++ sorry, there is no empty seat ++   " << endl;
	//}

	//cout << "\n --------- end of code ------------ " << endl;


	bool run = true;
	string weaponChoice;
	int invSize = 24;
	string inventory[24];

	while (run) {
		// Tells the user how many inventory slots they have left
		cout << "You have " << invSize << " inventory slots remaining\n" << endl;

		// Lists the items and the slots they use
		cout << "What Item will you take? \n > Dagger (1 Slot) \n > Sword (2 Slots) \n > Spear (5 Slots) \n > Hammer (6 Slots)\n" << endl;
		cout << " > Torch (1 Slot) \n > Potion (1 Slot) \n > Crystal (4 Slots) \n > Rations (8 Slots) \n > Boulder (16 Slots)\n" << endl;
		cin >> weaponChoice;

		// To make space for the next line
		cout << "\n";

		// Checks if the item selected matches this one
		if (weaponChoice == "Dagger") {
			// Checks if there is enough space in the inventory
			if (invSize >= 1) {
				// Reduces inventory space
				invSize -= 1;
				// Goes through inventory till it finds an empty slot, then fills it with the item
				for (int i = 0; i < sizeof(inventory); i++) { if (inventory[i] == "") { inventory[i] = "Dagger"; break; } }
			}
			// Only runs if there isn't enough space in the inventory
			else {
				cout << "You do not have enough space for a Dagger" << endl;
			}
		}
		else if (weaponChoice == "Sword") {
			if (invSize >= 2) {
				invSize -= 2;
				for (int i = 0; i < sizeof(inventory); i++) { if (inventory[i] == "") { inventory[i] = "Sword"; break; } }
			}
			else {
				cout << "You do not have enough space for a Sword" << endl;
			}
		}
		else if (weaponChoice == "Spear") {
			if (invSize >= 5) {
				invSize -= 5;
				for (int i = 0; i < sizeof(inventory); i++) { if (inventory[i] == "") { inventory[i] = "Spear"; break; } }
			}
			else {
				cout << "You do not have enough space for a Spear" << endl;
			}
		}
		else if (weaponChoice == "Hammer") {
			if (invSize >= 6) {
			invSize -= 6;
			for (int i = 0; i < sizeof(inventory); i++) { if (inventory[i] == "") { inventory[i] = "Hammer"; break; } }
			}
			else {
				cout << "You do not have enough space for a Hammer" << endl;
			}
			
		}
		else if (weaponChoice == "Torch") {
			if (invSize >= 1) {
				invSize -= 1;
				for (int i = 0; i < sizeof(inventory); i++) { if (inventory[i] == "") { inventory[i] = "Torch"; break; } }
			}
			else {
				cout << "You do not have enough space for a Torch" << endl;
			}

		}
		else if (weaponChoice == "Potion") {
			if (invSize >= 1) {
				invSize -= 1;
				for (int i = 0; i < sizeof(inventory); i++) { if (inventory[i] == "") { inventory[i] = "Potion"; break; } }
			}
			else {
				cout << "You do not have enough space for a Potion" << endl;
			}

		}
		else if (weaponChoice == "Crystal") {
			if (invSize >= 4) {
				invSize -= 4;
				for (int i = 0; i < sizeof(inventory); i++) { if (inventory[i] == "") { inventory[i] = "Crystal"; break; } }
			}
			else {
				cout << "You do not have enough space for a Crystal" << endl;
			}

		}
		else if (weaponChoice == "Rations") {
			if (invSize >= 8) {
				invSize -= 8;
				for (int i = 0; i < sizeof(inventory); i++) { if (inventory[i] == "") { inventory[i] = "Rations"; break; } }
			}
			else {
				cout << "You do not have enough space for the Rations" << endl;
			}

		}
		else if (weaponChoice == "Boulder") {
			if (invSize >= 16) {
				invSize -= 16;
				for (int i = 0; i < sizeof(inventory); i++) { if (inventory[i] == "") { inventory[i] = "Boulder"; break; } }
			}
			else {
				cout << "You do not have enough space for a Boulder" << endl;
			}

		}


		else {
			cout << "Invalid Input. Weapon is not listed" << endl;
			continue;
		}
		
		
		cout << "Your inventory currently includes: \n" << endl;

		// Goes through the inventory array
		for (string i : inventory) {
			// Ends the loop when a blank slot is found
			if (i == "") {
				break;
			}
			// Prints the item in the inventory
			 cout << " > " << i << endl;
		}

		// Ends the full loop when there are no more inventory slots
		if (invSize == 0) {
			cout << "\nYou have run out of inventory space" << endl;
			break;
		}
		
		cout << "\n";
	}





}

/*
// challenge / class work
// 3 - player backpack  
// gun_typeA = 1 slots
// gun_typeB = 2 slots
// gun_typeC = 5 slots
// gun_typeD = 6 slots
// inv_type_01 = 1 slots
// inv_type_02 = 1 slots
// inv_type_03 = 4 slots
// inv_type_04 = 8 slots
// inv_type_05 = 16 slots

// allow to pick max 2 guns + max 4 inventories
// max size is 24 for level I backpack 
// example: 6 6 8 1 1 1 1 ---> | gun_typeD x2 | inv_type_04 x1 | inv_type_01 x3 | inv_type_02 x1 |
// ---------- develop code to:
// show inventory max size and then 
// ask for items 10 times, and on each time, calculate the remaining size,
// then show "available/unavailable" message to player on each turn and 
// print a list of items and count of each
// feel free to develop code on upgrade the backpack to level II scenario

*/
