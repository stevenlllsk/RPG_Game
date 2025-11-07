#include <iostream>
#include <string>
#include "inventory.h"
#include "enemies.h"
#include "shop.h"

using namespace std;

void fightLoop(int& playerHealth, int& playerCoins, Weapon playerWeapon, Enemies& enemy, string playerName) {
    while (enemy.health > 0 && playerHealth > 0) {
        cin.get();
        enemy.health -= playerWeapon.damage;

        int damageTaken = enemy.damage;
        if (damageTaken < 0) damageTaken = 0;

        playerHealth -= damageTaken;

        system("clear");
        cout << "You hit the enemy! Enemy HP: " << enemy.health << endl;
        cout << "Enemy did " << damageTaken << " damage!" << endl;
        cout << "You did " << playerWeapon.damage << " damage!" << endl;
        cout << "Your health is " << playerHealth << "!" << endl;
    }

    if (playerHealth <= 0) {
        system("clear");
        cout << "You're dead!" << endl;
    } else {
        cout << "You defeated the enemy!" << endl;
	playerCoins + 20;
    }
}

void shop(int& playerCoins) {
	Potion healthPotion = create_potion("Health Potion", 15, 10 );

	// need to finish this, just need the if else statments for buying, and in int main somehow getting a more proper inventory.
	// may need to make actual inventory.h and cpp files the ACTUAL inventory, then seperate the weapons and soon armor into files.
	// its okay though, this shouldnt be too hard.
}

int main() {
	Weapon woodensword = create_weapon("Wooden Sword", 5);
	Enemies orc = create_enemies("Orc", 3, 25);

	string playerName;
	int playerHealth = 100;
	Weapon playerWeapon = woodensword;
	int playerCoins;

	cout << "Enter your player's name: ";
	cin >> playerName;

	system("clear");

		while (playerHealth > 0) {
			int choice;
			cout << "       RUNECRAWL              v0.0.1" << endl;
			cout << " " << endl;
			cout << " " << endl;
			cout << "1) Go fight!";
			cout << "2) Shop";
			cout << " " << endl;
			cout << "Enter your choice: ";
			cin >> choice;

			if (choice == 1) {
				fightLoop(playerHealth, playerCoins, playerWeapon, orc, playerName);
			} 
			else if (choice == 2) {
				shop()
			}
		}

    return 0;
}
