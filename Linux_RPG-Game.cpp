#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void fight(int& playerHealth, int playerDamage, int& enemyHealth, int enemyDamage, int& playerCoin, int playerArmor) {
    int damageTaken;

    while (enemyHealth > 0 && playerHealth > 0) {

        cin.get();
        enemyHealth -= playerDamage;
        damageTaken = enemyDamage - playerArmor;

        if (damageTaken < 0) {
            damageTaken = 0;
        }

        playerHealth -= damageTaken;

        system("clear");
        cout << "You hit the enemy! Enemy HP: " << enemyHealth << endl;
        cout << " " << endl;
        cout << "Enemy did " << damageTaken << " damage!" << endl;
        cout << "You did " << playerDamage << " damage!" << endl;
        cout << " " << endl;
        cout << "Your health is " << playerHealth << "!" << endl;
    }

    if (enemyHealth <= 0 && enemyHealth <= 0) {
        cout << "You have slain the enemy!" << endl;
        playerCoin += 12;
        cout << playerCoin << " coins added!" << endl;
        system("clear");
    }
    else {
        system("clear");
        cout << "You're dead!";
    }
}

void shop(int& playerHealth, int& playerDamage, int& playerCoin, int& playerArmor) {
    int choice;

    system("clear");

    cout << "Welcome to my shop!" << endl;

    cout << "You have " << playerCoin << " coins!" << endl;

    cout << "1. Buy damage +1: Costs 5 coins!" << endl;
    cout << "2. Buy health potion +25: Costs 15 coins!" << endl;
    cout << "3. Buy Armor +1 AP: Costs 30 coins!" << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;
    system("clear");

    if (choice == 1 && playerCoin >= 5) {
        system("clear");
        cout << "Bought damage +1: Costs 5 coins!" << endl;
        playerDamage += 1;
        playerCoin -= 5;
        system("clear");
    }
    else if (choice == 2 && playerCoin >= 15) {
        system("clear");
        cout << "Bought health potion +25: Costs 15 coins!!" << endl;
        playerHealth += 25;
        playerCoin -= 15;
        system("clear");
    }
    else if (choice == 3 && playerCoin >= 30) {
        system("clear");
        cout << "Bought Armor +1 AP: Costs 30 coins!" << endl;
        playerArmor += 1;
        playerCoin -= 30;
        system("clear");
    }
}

void levelSystem(int& enemyHealth, int& enemyKills, int& playerLevel,int& enemyDamage, int& playerCoin) {
    if (enemyHealth <= 0) {
        enemyKills++;
    }

    if (enemyKills % 5 == 0 && enemyKills > 0) {
        playerLevel++;
        cout << "Congrats, you leveled up. Your level now is: " << playerLevel << "!" << endl;
    }

    if (playerLevel % 5 == 0 && playerLevel > 0) {
        enemyHealth += 10;
        enemyDamage += 1;
        playerCoin += 5;
    }
}

int main() {
    system("clear");

    string inputName;
    int playerHealth = 100;
    int playerDamage = 7;
    int playerCoin = 0;
    int playerArmor = 2;

    int enemyHealth = 50;
    int enemyDamage = 5;

    int playerLevel = 0;

    int enemyKills = 0;

    string key;

    ifstream in("save.txt");
    if (!in) {
        cout << "No save file found!" << endl;
        cout << "Enter your name: ";
        cin >> inputName;
    }
    else {
        while (in >> key) {
            if (key == "name")   in >> inputName;
            else if (key == "Health") in >> playerHealth;
            else if (key == "Damage") in >> playerDamage;
            else if (key == "Coins")  in >> playerCoin;
            else if (key == "Armor")  in >> playerArmor;
            else if (key == "Kills") in >> enemyKills;
            else if (key == "Level") in >> playerLevel;
        }
    }

    system("clear");

    cout << "                                 Ver 0.0.0.1" << endl;

    cout << "Welcome, " << inputName << "!" << endl;
    cout << " " << endl;

    int choice;

    while (playerHealth > 0) {
        cout << "You can do " << playerDamage << " damage!\nYou have " << playerHealth << " health!\n" << "You have " << playerArmor << " Armor!\n" << endl << endl;

        cout << "You have " << playerCoin << " coins!" << endl << endl;

        cout << "Enemy kills: " << enemyKills << endl;
        cout << "Player level: " << playerLevel << endl << endl;

        cout << "1. Fight another enemy!" << endl;
        cout << "2. Enter the shop!" << endl;
        cout << "3. Save Game!" << endl;
        cout << "4. Load Game!" << endl;
        cout << "5. Exit Game!" << endl;
        cout << " " << endl;
        cout << "Choose your option: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Fight another enemy!" << endl;
            system("clear");
            enemyHealth = 50;
            fight(playerHealth, playerDamage, enemyHealth, enemyDamage, playerCoin, playerArmor);
            levelSystem(enemyHealth, enemyKills, playerLevel, enemyDamage, playerCoin);
        }
        else if (choice == 2) {
            cout << "Welcome to my shop!" << endl;
            system("clear");
            shop(playerHealth, playerDamage, playerCoin, playerArmor);
        }
        else if (choice == 3) {
            system("clear");
            ofstream out("save.txt");
            out << "Name " << inputName << "\n"
                << "Health " << playerHealth << "\n"
                << "Damage " << playerDamage << "\n"
                << "Coins " << playerCoin << "\n"
                << "Armor " << playerArmor << "\n"
                << "Kills " << enemyKills << "\n"
                << "Level" << playerLevel << "\n";
            out.close();
            cout << "Game saved" << endl;
        }
        else if (choice == 4) {
            system("clear");
            ifstream in("save.txt");
            in >> inputName >> playerHealth >> playerDamage >> playerCoin >> playerArmor;
            in.close();
            cout << "Game loaded" << endl;
        }
        else if (choice == 5) {
            system("clear");
            cout << "Goodbye!" << endl;
            break;
        }
    }

    cin.ignore();
    cin.get();

    return 0;
}
