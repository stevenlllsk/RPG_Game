#ifndef ENEMIES_H
#define ENEMIES_H

#include <string>

struct Enemies{
	std::string name;
	int damage;
	int health;
};

Enemies create_enemies(std::string name, int damage, int health);

#endif