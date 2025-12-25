#include <iostream>
#include <string>
#include "inventory.h"

using namespace std;

// actually makes the function and gives values to string name and int damage.
Inventory create_weapon(string name, int damage) {
	Inventory w;
	w.name = "Wooden Sword";
	w.damage = 5;

	// puts woodensword into inventory.h so it can be grabbed in main.cpp .
	return w;
}