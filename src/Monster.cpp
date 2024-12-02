#include "Monster.hpp"

Monster::Monster(const std::string& name, int health, int attackDamage)
    : name(name), health(health), attackDamage(attackDamage) {}

bool Monster::isDefeated() {
    return health <= 0;
}

void Monster::takeDamage(int damage) {
    health -= damage;
}

void Monster::attackPlayer(int& playerHealth, int damage) {
    playerHealth -= damage;
}

std::string Monster::getName() const {
    return name;
}

int Monster::getHealth() const {
    return health;
}

int Monster::getAttackDamage() const {
    return attackDamage;
}