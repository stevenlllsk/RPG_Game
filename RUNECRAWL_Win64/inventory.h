#ifndef INVENTORY_H // Stands for if not defined, checks if, for example INVENTORY_H has already been defined.
#define INVENTORY_H // Keeps from being included again, and doing ifndef again, defines INVENTORY_H

// from what i know, whatever is after #ifndef and #define needs to be the file name
// like this file is inventory.h, so it needs to be INVENTORY_H

#include <string>

// makes the struct for holding Weapon names and damage amounts, could hold more like critChance
struct Weapon{
	std::string name;
	int damage;
};

// makes the function for creating the weapon, then pushed over to inventory.cpp to be 
// further made and then main.cpp
Weapon create_weapon(std::string name, int damage);

#endif