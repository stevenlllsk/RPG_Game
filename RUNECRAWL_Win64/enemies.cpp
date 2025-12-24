#include <iostream>
#include <string>
#include "enemies.h"

using namespace std;

Enemies create_enemies(string name, int damage, int health) {
        Enemies orc;
        orc.name = "Orc";
	orc.damage = 5;
	orc.health = 25;

        return orc;
}