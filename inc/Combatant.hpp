#ifndef COMBATANT_HPP
#define COMBATANT_HPP

#include <string>

class Combatant {
public:
    Combatant(const std::string& name, int health, int attackPower);

    std::string GetName() const;
    int GetHealth() const;
    void TakeDamage(int damage);
    bool IsAlive() const;
    virtual int Fight() const = 0;

protected:
    std::string name;
    int health;
    int attackPower;
};

#endif // COMBATANT_HPP
