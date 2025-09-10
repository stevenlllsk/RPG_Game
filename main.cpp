#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void fight(int& playerHealth, int playerDamage, int& enemyHealth, int enemyDamage, int& playerCoin) {
    while (enemyHealth > 0 && playerHealth > 0) {
        cin.get();
        enemyHealth -= playerDamage;
        playerHealth -= enemyDamage;
        cout << "You hit the enemy! Enemy HP: " << enemyHealth << endl;
        cout << " " << endl;
        cout << "Enemy did " << enemyDamage << " damage!" << endl;
        cout << "You did " << playerDamage << " damage!" << endl;
        cout << " " << endl;
        cout << "Your health is " << playerHealth << "!" << endl;
    }

    if (enemyHealth <= 0) {
        cout << "You have slain the enemy!" << endl;
        playerCoin += 10;
        cout << playerCoin << " coins added!" << endl;
        system("cls");
    }
    else {
        cout << "You're dead!";
    }
}

void shop(int& playerHealth, int& playerDamage, int& playerCoin) {
    int choice;

    cout << "Welcome to my shop!" << endl;

    cout << "You have " << playerCoin << " coins!" << endl;

    cout << "1. Buy damage +1 ." << endl;
    cout << "2. Buy health +5 ." << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;

    if (choice == 1) {
        system("cls");
        cout << "Bought 1 damage!" << endl;
        playerDamage += 1;
        playerCoin -= 5;
        cout << "Player damage: " << playerDamage << endl;
        cout << " " << endl;
        cout << "Coins remaining: " << playerCoin << endl;
    }
    else if (choice == 2) {
        system("cls");
        cout << "Bought 5 health!" << endl;
        playerHealth += 5;
        playerCoin -= 5;
        cout << "Player health: " << playerHealth << endl;
        cout << " " << endl;
        cout << "Coins remaining: " << playerCoin << endl;
    }
}

int main() {
    system("cls");

    string inputName;
    int playerHealth = 100;
    int playerDamage = 7;
    int playerCoin = 0;

    int enemyHealth = 50;
    int enemyDamage = 5;

    cout << "Enter your name: ";
    cin >> inputName;
    system("cls");

    cout << "Welcome, " << inputName << "!" << endl;
    cout << " " << endl;

    int choice;

    while (playerHealth > 0) {
        cout << "You can do " << playerDamage << " damage!\nYou have " << playerHealth << " health!" << endl << endl;

        cout << "You have " << playerCoin << " coins!" << endl << endl;

        cout << "1. Fight another enemy!" << endl;
        cout << "2. Enter the shop!" << endl;
        cout << "3. Save Game!" << endl;
        cout << "4. Load Game!" << endl;
        cout << " " << endl;
        cout << "Choose your option: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Fight another enemy!" << endl;
            system("cls");
            enemyHealth = 50;
            fight(playerHealth, playerDamage, enemyHealth, enemyDamage, playerCoin);
        }
        else if (choice == 2) {
            cout << "Welcome to my shop!" << endl;
            system("cls");
            shop(playerHealth, playerDamage, playerCoin);
        }
        else if (choice == 3) {
            ofstream out("save.txt");
            out << playerHealth << "\n";
            out << playerDamage << "\n";
            out << playerCoin << "\n";
            out.close();
            cout << "Game saved" << endl;
        }
        else if (choice == 4) {
            ifstream in("save.txt");
            in >> playerHealth >> playerDamage >> playerCoin;
            in.close();
            cout << "Game loaded" << endl;
        }
    }

    cin.ignore();
    cin.get();

    return 0;
}
