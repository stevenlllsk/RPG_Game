#include <iostream>
#include <string>
#include "enemies.h"

using namespace std;

Enemies create_enemies(string name, int damage, int health) {
        Enemies e;
        e.name = "Orc";
	e.damage = 5;
	e.health = 25;

        return e;
}