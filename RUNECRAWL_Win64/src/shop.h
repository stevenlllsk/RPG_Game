#ifndef SHOP_H
#define	SHOP_H

#include <string>

struct Potion {
	std::string name;
	int healAmount;
	int cost;
	int amount;
};

struct weaponStore {
	std::string name;
	int damageAmount;
	int cost;
	bool owned;
};

Potion create_potion(std::string name, int healAmount, int cost, int amount);
weaponStore buy_weapon(std::string name, int damageAmount, int cost, bool owned);

#endif
