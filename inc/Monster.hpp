#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <string>

class Monster {
public:
    Monster(const std::string& name, int health, int attackDamage);
    bool isDefeated();
    void takeDamage(int damage);
    void attackPlayer(int& playerHealth, int damage);
    std::string getName() const;
    int getHealth() const;
    int getAttackDamage() const;

private:
    std::string name;
    int health;
    int attackDamage;
};

#endif // MONSTER_HPP