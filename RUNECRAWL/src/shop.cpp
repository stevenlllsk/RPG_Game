#include <iostream>
#include <string>
#include "shop.h"

using namespace std;

Potion create_potion(string name, int amount, int cost) {
        Potion healthPotion;
        healthPotion.name = "Health Potion";
	healthPotion.amount = 15;
	healthPotion.cost = 10;

        return healthPotion;
}
