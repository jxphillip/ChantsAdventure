#include "Player.hpp"
#include "Asset.hpp" // Include Asset header
#include "Monster.hpp" // Include Monster header
#include <iostream>

using namespace chants;

Player::Player(const std::string& name, int health, int attackPower)
    : Combatant(name, health, attackPower) {}

void Player::TakeAsset(Asset& asset) {
    inventory.push_back(asset); // Add asset to inventory
}

bool Player::DropAsset(const std::string& assetName) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->GetName() == assetName) {
            inventory.erase(it); // Remove asset from inventory
            return true;
        }
    }
    return false; // Return false if asset not found
}

bool Player::InspectAsset(const std::string& assetName) {
    for (const auto& asset : inventory) {
        if (asset.GetName() == assetName) {
            std::cout << "Inspecting " << asset.GetName() << ": " << asset.GetMessage() << std::endl;
            return true;
        }
    }
    return false; // Return false if asset not found
}

void Player::ShowInventory() const {
    if (inventory.empty()) {
        std::cout << "Your inventory is empty." << std::endl;
        return;
    }

    std::cout << "Your inventory contains:" << std::endl;
    for (const auto& asset : inventory) {
        std::cout << "- " << asset.GetName() << " (Value: " << asset.GetValue() << ")" << std::endl;
    }
}

void Player::AttackMonster(Monster& monster) {
    monster.TakeDamage(attackPower); // Player attacks monster
}

// Implement the Fight function
int Player::Fight() const {
    // Simple placeholder implementation for the fight action.
    // You can add more complex logic here if needed, such as determining damage based on weapons, items, etc.
    return attackPower; // Return attackPower as damage dealt
}
