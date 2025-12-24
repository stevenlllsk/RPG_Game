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

weaponStore buy_weapon(string name, int damageAmount , int cost){
        weaponStore rustyIronSword;
        rustyIronSword.name = "Rusty Iron Sword";
        rustyIronSword.damageAmount = 9;
        rustyIronSword.cost = 45;

        return rustyIronSword;
}