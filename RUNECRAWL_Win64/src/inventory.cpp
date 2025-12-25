#include <iostream>
#include <string>
#include "inventory.h"

using namespace std;

Inventory create_weapon(string name, int damage, bool equipped) {
    Inventory w;
    w.name = name;
    w.damage = damage;
    w.equipped = equipped;
    return w;
}
