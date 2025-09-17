#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void fight(int& playerHealth, int playerDamage, int& enemyHealth, int enemyDamage, int& playerCoin, int playerArmor) {
    int damageTaken;
    
    while (enemyHealth > 0 && playerHealth > 0) {
         
        enemyHealth -= playerDamage;
        damageTaken = enemyDamage - playerArmor;
        
        if(damageTaken < 0) {
            damageTaken = 0;
            }
            
        playerHealth -= damageTaken;
        
        cout << "You hit the enemy! Enemy HP: " << damageTaken << endl;
        cout << " " << endl;
        cout << "Enemy did " << damageTaken << " damage!" << endl;
        cout << "You did " << playerDamage << " damage!" << endl;
        cout << " " << endl;
        cout << "Your health is " << playerHealth << "!" << endl;
    }

    if (enemyHealth <= 0) {
        cout << "You have slain the enemy!" << endl;
        playerCoin += 10;
        cout << playerCoin << " coins added!" << endl;
        system("clear");
    }
    else {
        cout << "You're dead!";
    }
}

void shop(int& playerHealth, int& playerDamage, int& playerCoin, int& playerArmor) {
    int choice;

    cout << "Welcome to my shop!" << endl;

    cout << "You have " << playerCoin << " coins!" << endl;

    cout << "1. Buy damage +1: Costs 5 coins!" << endl;
    cout << "2. Buy health potion +25: Costs 15 coins!" << endl;
    cout << "3. Buy Armor +1 AP: Costs 30 coins!" << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;

    if (choice == 1) {
        system("clear");
        cout << "Bought damage +1: Costs 5 coins!" << endl;
        playerDamage += 1;
        playerCoin -= 5;
        cout << "Player damage: " << playerDamage << endl;
        cout << " " << endl;
        cout << "Coins remaining: " << playerCoin << endl;
    }
    else if (choice == 2) {
        system("clear");
        cout << "Bought health potion +25: Costs 15 coins!!" << endl;
        playerHealth += 25;
        playerCoin -= 15;
        cout << "Player health: " << playerHealth << endl;
        cout << " " << endl;
        cout << "Coins remaining: " << playerCoin << endl;
    } else if (choice == 3) {
		system("clear");
		cout << "Bought Armor +1 AP: Costs 30 coins!" << endl;
		playerArmor += 1;
		playerCoin -= 30;
		cout << "Armor Points: " << playerArmor << endl;
		cout << " " << endl;
		cout << "Coins remaining: " << playerCoin << endl;
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

    ifstream in("save.txt");
    if(!in) {
            cout << "No save file found!" << endl;
            cout << "Enter your name: ";
            cin >> inputName;
    }
    else {
        getline(in, inputName);
        in >> playerHealth;
        in >> playerDamage;
        in >> playerCoin;
        in >> playerArmor;
        in.close();
        cout << "Game loaded" << endl;
    }

    system("clear");

    cout << "Welcome, " << inputName << "!" << endl;
    cout << " " << endl;

    int choice;

    while (playerHealth > 0) {
        cout << "You can do " << playerDamage << " damage!\nYou have " << playerHealth << " health!\n" << "You have " << playerArmor << endl << endl;

        cout << "You have " << playerCoin << " coins!" << endl << endl;

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
        }
        else if (choice == 2) {
            cout << "Welcome to my shop!" << endl;
            system("clear");
            shop(playerHealth, playerDamage, playerCoin, playerArmor);
        }
        else if (choice == 3) {
            system("clear");
            ofstream out("save.txt");
            out << inputName << "\n";
            out << playerHealth << "\n";
            out << playerDamage << "\n";
            out << playerCoin << "\n";
            out << playerArmor << "\n";
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
