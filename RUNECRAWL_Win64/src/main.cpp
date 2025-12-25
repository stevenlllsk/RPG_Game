#include <iostream>
#include <string>
#include "inventory.h"
#include "enemies.h"
#include "shop.h"

using namespace std;

// ====== FIGHT LOOP ======
void fightLoop(int& playerHealth, int& playerCoins, Inventory playerWeapon, Enemies& e, string playerName) {
    while (e.health >= 0 && playerHealth >= 0) {
        cin.get();
        e.health -= playerWeapon.damage;

        int damageTaken = e.damage;
        if (damageTaken < 0) damageTaken = 0;

        playerHealth -= damageTaken;

        system("cls");
        cout << "You hit the enemy! Enemy HP: " << e.health << endl;
        cout << "Enemy did " << damageTaken << " damage!" << endl;
        cout << "You did " << playerWeapon.damage << " damage!" << endl;
        cout << "Your health is " << playerHealth << "!" << endl;
    }

    if (playerHealth <= 0) {
        system("cls");
        cout << "You're dead!" << endl;
    } else {
        cout << "You defeated the enemy!" << endl;
	playerCoins += 20;
    }
	system("cls");
}

// ====== SHOP ======
void shop(int& playerCoins, Potion& p) {
	weaponStore w = buy_weapon("Rusty Iron Sword", 9, 45);

	int choice;
	cout << "1) Buy Health Potion (" << p.cost << " coins)" << endl;
	cout << "2) Leave" << endl;
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
	} else {
		cout << "Goodbye!" << endl;
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
	Inventory w = create_weapon("Wooden Sword", 5);
	Enemies e = create_enemies("Orc", 3, 25);
	Potion p = create_potion("Health Potion", 15, 10, 0);

	string playerName;
	int playerHealth = 100;
	Inventory playerWeapon = w;
	int playerCoins = 0;

	cout << "Enter your player's name: ";
	cin >> playerName;

	system("cls");

	while (playerHealth > 0) {
		int choice;
		cout << "             ====  RUNECRAWL  ====         v0.0.2 Alpha" << endl;
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
		cout << "2) Shop(Not Finished!)" << endl;
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
			shop(playerCoins, p);
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