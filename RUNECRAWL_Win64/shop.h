#ifndef SHOP_H
#define	SHOP_H

#include <string>

struct Potion {
	std::string name;
	int amount;
	int cost;
};

struct weaponStore {
	std::string name;
	int damageAmount;
	int cost;
};

Potion create_potion(std::string name, int amount, int cost);
weaponStore buy_weapon(std::string name, int damageAmount, int cost);

#endif