#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "Combatant.hpp"

namespace chants {

class Monster : public Combatant {
public:
    Monster(const std::string& name, int health, int attackPower);

    int Fight() const override;
};

} // namespace chants

#endif // MONSTER_HPP
