#ifndef SHOP_H
#define	SHOP_H

struct Potion {
	std::string name;
	int amount;
	int cost;
};

Potion create_potion(std::string name, int amount, int cost);

#endif
