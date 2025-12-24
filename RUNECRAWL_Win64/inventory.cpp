#include <iostream>
#include <string>
#include "inventory.h"

using namespace std;

// actually makes the function and gives values to string name and int damage.
Weapon create_weapon(string name, int damage) {
	Weapon woodensword;
	woodensword.name = "Wooden Sword";
	woodensword.damage = 5;

	// puts woodensword into inventory.h so it can be grabbed in main.cpp .
	return woodensword;
}