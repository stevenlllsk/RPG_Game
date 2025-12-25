#include <iostream>
#include <string>
#include "shop.h"

using namespace std;

Potion create_potion(string name, int healAmount, int cost, int amount) {
    Potion p;
    p.name = name;
    p.healAmount = healAmount;
    p.cost = cost;
    p.amount = amount;
    return p;
}

weaponStore buy_weapon(string name, int damageAmount , int cost, bool owned) {
    weaponStore ws;
    ws.name = name;
    ws.damageAmount = damageAmount;
    ws.cost = cost;
    ws.owned = owned;
    return ws;
}
