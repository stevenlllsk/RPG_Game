#include <iostream>
#include <string>
#include "shop.h"

using namespace std;

Potion create_potion(string name, int healAmount, int cost, int amount) {
        Potion p;
        p.name = "Health Potion";
	p.healAmount = 15;
	p.cost = 10;
        p.amount = 0;

        return p;
}

weaponStore buy_weapon(string name, int damageAmount , int cost){
        weaponStore w;
        w.name = "Rusty Iron Sword";
        w.damageAmount = 9;
        w.cost = 45;

        return w;
}