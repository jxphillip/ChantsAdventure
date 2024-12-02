#include <iostream>
#include "AdventureGameMap.hpp"
#include "Player.hpp"
#include "Monster.hpp"

int main() {
    std::string playerName;
    std::cout << "Enter your name: ";
    std::cin >> playerName;

    Player player(playerName, 12500);
    chants::AdventureGameMap map;
    bool gameRunning = true;

    while (gameRunning && !map.isGameWon()) {
        map.displayCurrentLevel(player);  // Pass Player object
        std::string command;
        std::cout << "Enter command (move, take, attack, inventory, use, drop, quit): ";
        std::cin >> command;

        if (command == "move") {
            map.movePlayer();
        } else if (command == "take") {
            player.takeItem(map.getCurrentItem());
        } else if (command == "attack") {
            if (map.isMonsterPresent()) {
                std::cout << "The battle has started!" << std::endl;
                player.attack(map.getCurrentMonster());
                if (map.getCurrentMonster().isDefeated()) {
                    std::cout << "Monster is defeated!" << std::endl;
                    map.removeCurrentMonster();
                } else {
                    map.getCurrentMonster().attackPlayer(player.getHealthRef(), map.getCurrentMonster().getAttackDamage() - player.getDefense());
                    std::cout << "The monster attacked you! Your health is now " << player.getHealth() << std::endl;
                }
            } else {
                std::cout << "No monster to attack!" << std::endl;
            }
        } else if (command == "inventory") {
            player.displayInventory();
        } else if (command == "use") {
            std::string item;
            std::cout << "Enter item to use: ";
            std::cin >> item;
            player.useItem(item);
        } else if (command == "drop") {
            std::string item;
            std::cout << "Enter item to drop: ";
            std::cin >> item;
            player.dropItem(item);
        } else if (command == "quit") {
            gameRunning = false;
            std::cout << "You have quit the game." << std::endl;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }

    if (map.isGameWon()) {
        std::cout << "Congratulations! You have defeated all the monsters and won the game!" << std::endl;
    }

    return 0;
}