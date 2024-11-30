#include "Monster.hpp"

namespace chants {

Monster::Monster(const std::string& name, int health, int attackPower)
    : Combatant(name, health, attackPower) {}

int Monster::Fight() const {
    return attackPower;  // Return the monster's attack power for its counterattack
}

} // namespace chants
