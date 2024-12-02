#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include "Monster.hpp"

class Player {
public:
    Player(const std::string& name, int health);
    void takeItem(const std::string& item);
    void useItem(const std::string& item);
    void dropItem(const std::string& item);
    void attack(Monster& monster);
    void displayInventory();
    int getHealth() const;
    int& getHealthRef();
    int getAttackDamage() const;
    int getDefense() const;

private:
    std::string name;
    int health;
    int baseAttackDamage;
    int attackDamage;
    int defense;
    std::vector<std::string> inventory;
};

#endif // PLAYER_HPP