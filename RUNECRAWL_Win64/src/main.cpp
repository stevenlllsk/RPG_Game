#include <iostream>
#include <string>
#include "inventory.h"
#include "enemies.h"
#include "shop.h"

using namespace std;

// ====== FIGHT LOOP ======
void fightLoop(int& playerHealth, int& playerCoins, Inventory playerWeapon, Enemies& e, string playerName) {
    while (e.health >= 0 && playerHealth >= 1) {
        cin.get();
        e.health -= playerWeapon.damage;

        e.health -= playerWeapon.damage;

		int damageTaken = 0;
		if (e.health > 0) {
    		damageTaken = e.damage;
    		if (damageTaken < 0) damageTaken = 0;
		}

        playerHealth -= damageTaken;

        system("cls");
        cout << playerName << " hit the " << e.name << "! " << e.name << " HP: " << e.health << endl;
        cout << e.name << " did " << damageTaken << " damage!" << endl;
        cout << playerName << " did " << playerWeapon.damage << " damage!" << endl;
        cout << "Your health is " << playerHealth << "!" << endl;
    }

    if (playerHealth <= 0) {
        system("cls");
        cout << "You're dead!" << endl;
    } else {
        cout << "You defeated the " << e.name << "!" << endl;
	playerCoins += 20;
    }
	system("cls");
}

// ====== SHOP ======
void shop(int& playerCoins, Inventory& playerWeapon, Potion& p, weaponStore& ws) {

	int choice;
	cout << "1) Buy Health Potion (" << p.cost << " coins)" << endl;
	cout << "2) Buy " << ws.name << " (" << ws.cost << " coins)" << endl;
	cout << "3) Leave" << endl;
	cout << "Enter your choice: ";
	cin >> choice;

	if(choice == 1){
		if (playerCoins >= p.cost) {
			p.amount += 1;
			playerCoins -= p.cost;
			cout << "Bought! You now have " << p.amount << " potion(s)." << endl;
		} else {
			cout << "Not enough coins!" << endl;
		}
	}

	if(choice == 2){
		if(playerCoins >= ws.cost){
			if(!ws.owned){
				playerCoins -= ws.cost;
				ws.owned = true;
				cout << "You bought the " << ws.name << "!" << endl;
				playerWeapon.equipped = false;
				if(ws.owned == true){
					playerWeapon.name = ws.name;
					playerWeapon.damage = ws.damageAmount;
					playerWeapon.equipped = true;
				}
			}
			else{
				cout << "You already own the " << ws.name << "!" << endl;
			}
		}
		else{
			cout << "Not enough coins to buy the " << ws.name << "!" << endl;
		}
	}

	if (choice == 3){
		cout << "Leaving shop..." << endl;
	}

	cin.get();
	cin.get();

	system("cls");
}

// ====== PLAYER INVENTORY ======
void playerInventory(int& playerHealth, Potion& p){
	int choice;

	cout << "Health Potions: " << p.amount<< endl;

	cout << "1) Take Health Potion" << endl;
	cout << " " << endl;

	cout << "Enter your choice: ";
	cin >> choice;

	if(choice == 1){
		if(p.amount >= 1){
			playerHealth += p.healAmount;
		}
		else if(p.amount <= 0){
			cout << "You do not have any Health Potions, visit the shop and buy some!" << endl;
		}

	}
	else{
		exit(1);
	}

	system("cls");
}

// ====== MAIN LOOP ======
int main() {
	Inventory w = create_weapon("Wooden Sword", 5, true);
	Enemies e = create_enemies("Orc", 3, 25);
	Potion p = create_potion("Health Potion", 15, 10, 0);
	weaponStore ws = buy_weapon("Rusty Iron Sword", 9, 45, false);

	string playerName;
	int playerHealth = 100;
	Inventory playerWeapon = w;
	int playerCoins = 0;

	cout << "Enter your player's name: ";
	cin >> playerName;

	system("cls");

	while (playerHealth > 0) {
		int choice;
		cout << "             ======  RUNECRAWL  ======           v0.0.6 Alpha" << endl;
		cout << " " << endl;
		cout << " " << endl;
		cout << "Player Name: " << playerName << endl;
		cout << " " << endl;
		cout << " " << endl;
		cout << "Coins: " << playerCoins << endl;
		cout << "Player Health: " << playerHealth << endl;
		cout << "Current Weapon: " << playerWeapon.name << endl;
		cout << "Current Weapon Damage: " << playerWeapon.damage << endl;
		cout << " " << endl;
		cout << " " << endl;
		cout << "1) Go fight" << endl;
		cout << "2) Shop" << endl;
		cout << "3) Open Inventory" << endl;
		cout << "4) Exit RUNECRAWL" << endl;
		cout << " " << endl;
		cout << " " << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) {
			Enemies orcFight = create_enemies("Orc", 3, 25);
			fightLoop(playerHealth, playerCoins, playerWeapon, orcFight, playerName);
		} 
		else if (choice == 2) {
			shop(playerCoins, playerWeapon, p, ws);
		}
		else if (choice == 3){
			playerInventory(playerHealth, p);
		}
		else if (choice == 4){
			cout << "Goodbye!" << endl;
			cin.get();
			cin.get();
			break;
		}
	}

	return 0;
}
