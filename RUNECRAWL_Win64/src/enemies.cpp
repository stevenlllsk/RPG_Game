#include <iostream>
#include <string>
#include "enemies.h"

using namespace std;

Enemies create_enemies(string name, int damage, int health) {
    Enemies e;
    e.name = name;
    e.damage = damage;
    e.health = health;
    return e;
}
