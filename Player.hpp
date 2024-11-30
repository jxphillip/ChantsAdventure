#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "Combatant.hpp"
#include "Asset.hpp"
#include "Monster.hpp"

class Player : public Combatant {
public:
    Player(const std::string& name, int health, int attackPower);

    void TakeAsset(chants::Asset& asset); // Correct Asset namespace
    bool DropAsset(const std::string& assetName);
    bool InspectAsset(const std::string& assetName);
    void ShowInventory() const;
    void AttackMonster(chants::Monster& monster);
    int Fight() const override; // Implement the Fight function

private:
    std::vector<chants::Asset> inventory; // Correct Asset namespace
};

#endif // PLAYER_HPP

