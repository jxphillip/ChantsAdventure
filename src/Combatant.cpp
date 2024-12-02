#include "Combatant.hpp"

Combatant::Combatant(const std::string& name, int health, int attackPower)
    : name(name), health(health), attackPower(attackPower) {}

std::string Combatant::GetName() const {
    return name;
}

int Combatant::GetHealth() const {
    return health;
}

void Combatant::TakeDamage(int damage) {
    health -= damage;
}

bool Combatant::IsAlive() const {
    return health > 0;
}