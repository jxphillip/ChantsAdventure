#include <iostream>
#include <vector>
#include <string>
#include "Node.hpp"
#include "Asset.hpp"
#include "Player.hpp"
#include "Monster.hpp"
#include "AdventureGameMap.hpp"

using namespace std;
using namespace chants;

bool isNumber(const string &str) {
    for (char const &c : str) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

void AtNode(Node &viewPort, Player &player) {
    cout << "\033[2J\033[1;1H"; // Clear screen

    // Output contents of this Node
    cout << "Location: " << viewPort.GetName() << "\n\n";
    cout << viewPort.GetDescription() << endl
         << "There are paths here:" << endl;
    for (Node *node : viewPort.GetConnections()) {
        cout << "- " << node->GetName() << endl;
    }

    // Show all assets in Node
    for (Asset *asset : viewPort.GetAssets()) {
        cout << "Asset at this node: " << asset->GetName() << " - " << asset->GetMessage()
             << " (Value: " << asset->GetValue() << ")" << endl;
    }

    // Show any monsters at this Node
    for (Monster *monster : viewPort.GetMonsters()) {
        cout << "Monster at this node: " << monster->GetName() << " (Health: "
             << monster->GetHealth() << ")" << endl;
    }

    // Display player's health
    cout << "Your health: " << player.GetHealth() << endl;

    cout << "\n";
}

int Battle(Player &player, Monster &monster) {
    cout << "You've started a battle with " << monster.GetName() << "!" << endl;

    // Player attacks monster
    player.AttackMonster(monster);
    if (!monster.IsAlive()) {
        cout << "Congratulations! You defeated " << monster.GetName() << "!" << endl;
        return 1; // Monster defeated
    }

    // Monster counter-attacks
    int damage = monster.Fight();
    player.TakeDamage(damage);
    cout << monster.GetName() << " attacks back! You take " << damage << " damage." << endl;

    // Display player's health after attack
    cout << "Your health: " << player.GetHealth() << endl;

    return player.IsAlive() ? 0 : -1; // 0 for ongoing, -1 if player is defeated
}

std::string getLastWord(const std::string &str) {
    size_t pos = str.find_last_of(' ');
    return (pos == string::npos) ? str : str.substr(pos + 1);
}

int main() {
    AdventureGameMap gameMap; // Use AdventureGameMap to initialize nodes

    // Retrieve the game locations (nodes)
    vector<Node> locations = gameMap.GetLocations();

    // Player and initial game setup
    Player player("Hero", 12500, 100);

    // Create monsters
    vector<Monster> monsters = {
        Monster("Goblin", 100, 50),
        Monster("Dragon", 200, 75),
        Monster("Troll", 150, 60),
        Monster("Orc", 120, 55),
        Monster("Vampire", 180, 70),
        Monster("Werewolf", 160, 65),
        Monster("Zombie", 90, 45)
    };

    // Add monsters every 3 nodes
    for (size_t i = 0; i < locations.size(); i += 3) {
        if (i / 3 < monsters.size()) {
            locations[i].AddMonster(&monsters[i / 3]);
        }
    }

    // Create items
    vector<Asset> items = {
        Asset("Sword", "A sharp blade for fighting monsters.", 100, true),
        Asset("Shield", "A sturdy shield for protection.", 80, true),
        Asset("Potion", "A healing potion to restore health.", 50, true)
    };

    // Add items to every node
    for (size_t i = 0; i < locations.size() && i < items.size(); ++i) {
        locations[i].AddAsset(&items[i]);
    }

    int currentNode = 0; // Start at Home (index 0)
    string input;

    while (true) {
        AtNode(locations[currentNode], player); // Show the current node details and player's health

        // Display available actions
        cout << "Choose action (e.g., 'move Mountain', 'take Sword', 'attack Goblin', "
                "'inspect Sword', 'drop Sword', 'inventory', 'exit'):\n";

        getline(cin, input);

        if (input == "exit")
            break;

        // Parse action and target
        size_t spacePos = input.find(' ');
        string action = input.substr(0, spacePos);
        string target = (spacePos != string::npos) ? input.substr(spacePos + 1) : "";

        // Movement action
        if (action == "move") {
            bool moved = false;
            for (Node *connectedNode : locations[currentNode].GetConnections()) {
                if (connectedNode->GetName() == target) {
                    currentNode = connectedNode->GetId();
                    cout << "You moved to: " << connectedNode->GetName() << endl;
                    moved = true;
                    break;
                }
            }
            if (!moved)
                cout << "Invalid location: " << target << endl;
        }
        // Take asset
        else if (action == "take") {
            bool taken = false;
            for (Asset *asset : locations[currentNode].GetAssets()) {
                if (asset->GetName() == target) {
                    player.TakeAsset(*asset);
                    locations[currentNode].RemoveAsset(asset);
                    cout << "You've picked up the " << target << "." << endl;
                    taken = true;
                    break;
                }
            }
            if (!taken)
                cout << "No such asset found: " << target << endl;
        }
        // Drop asset
        else if (action == "drop") {
            if (player.DropAsset(target)) {
                cout << "You dropped the " << target << "." << endl;
            } else {
                cout << "You don't have that asset: " << target << endl;
            }
        }
        // Inspect asset
        else if (action == "inspect") {
            if (!player.InspectAsset(target)) {
                cout << "You don't have that asset: " << target << endl;
            } else {
                cout << "You inspected the " << target << "." << endl;
            }
        }
        // Attack monster
        else if (action == "attack") {
            bool found = false;
            for (Monster *monster : locations[currentNode].GetMonsters()) {
                if (monster->GetName() == target) {
                    found = true;
                    int result = Battle(player, *monster);
                    if (result == -1) {
                        cout << "You have been defeated. Game Over!" << endl;
                        return 0;
                    } else if (result == 1) {
                        locations[currentNode].RemoveMonster(monster);
                    }
                    break;
                }
            }
            if (!found)
                cout << "No such monster found: " << target << endl;
        }
        // Show inventory
        else if (action == "inventory") {
            cout << "Your inventory contains:" << endl;
            player.ShowInventory();
        }
        // Invalid action
        else {
            cout << "Invalid action. Try again" << endl;
        }
    }

    return 0;
}
