#include "Player.hpp"
#include <iostream>
#include <algorithm>

Player::Player(const std::string& name, int health)
    : name(name), health(health), baseAttackDamage(50), attackDamage(50), defense(0) {}

void Player::takeItem(const std::string& item) {
    inventory.push_back(item);
    std::cout << "You have taken " << item << std::endl;
    if (item == "Sword" || item == "Bow" || item == "Dagger" || item == "Staff" || item == "Crossbow") {
        attackDamage += 20;
        std::cout << "Your attack damage increased to " << attackDamage << std::endl;
    } else if (item == "Armor" || item == "Helmet" || item == "Boots") {
        health += 50;
        std::cout << "Your health increased to " << health << std::endl;
    } else if (item == "Shield") {
        defense += 10;
        std::cout << "Your defense increased to " << defense << std::endl;
    } else if (item == "Magic Wand") {
        health += 100;
        std::cout << "Your health increased to " << health << std::endl;
    }
}

void Player::useItem(const std::string& item) {
    auto it = std::find(inventory.begin(), inventory.end(), item);
    if (it != inventory.end()) {
        if (item == "Health Potion") {
            health = 12500;
            std::cout << "You used a Health Potion. Health is now " << health << std::endl;
        } else if (item == "Elixir") {
            health += 50;
            std::cout << "You used an Elixir. Health is now " << health << std::endl;
        } else if (item == "Magic Wand") {
            health += 100;
            std::cout << "You used a Magic Wand. Health is now " << health << std::endl;
        } else {
            std::cout << "You used " << item << std::endl;
        }
        inventory.erase(it);
    } else {
        std::cout << "Item not found in inventory!" << std::endl;
    }
}

void Player::dropItem(const std::string& item) {
    auto it = std::find(inventory.begin(), inventory.end(), item);
    if (it != inventory.end()) {
        inventory.erase(it);
        std::cout << "You have dropped " << item << std::endl;
        if (item == "Sword" || item == "Bow" || item == "Dagger" || item == "Staff" || item == "Crossbow") {
            attackDamage -= 20;
            std::cout << "Your attack damage decreased to " << attackDamage << std::endl;
        } else if (item == "Armor" || item == "Helmet" || item == "Boots") {
            health -= 50;
            std::cout << "Your health decreased to " << health << std::endl;
        } else if (item == "Shield") {
            defense -= 10;
            std::cout << "Your defense decreased to " << defense << std::endl;
        } else if (item == "Magic Wand") {
            health -= 100;
            std::cout << "Your health decreased to " << health << std::endl;
        }
    } else {
        std::cout << "Item not found in inventory!" << std::endl;
    }
}

void Player::attack(Monster& monster) {
    monster.takeDamage(attackDamage);
    std::cout << "You attacked the monster!" << std::endl;
    if (!monster.isDefeated()) {
        int damage = monster.getAttackDamage() - defense;
        if (damage < 0) damage = 0;
        monster.attackPlayer(health, damage);
        std::cout << "The monster attacked you! Your health is now " << health << std::endl;
    }
}

void Player::displayInventory() {
    std::cout << "Inventory: ";
    for (const auto& item : inventory) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int Player::getHealth() const {
    return health;
}

int& Player::getHealthRef() {
    return health;
}

int Player::getAttackDamage() const {
    return attackDamage;
}

int Player::getDefense() const {
    return defense;
}