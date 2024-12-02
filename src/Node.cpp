#include "Node.hpp"
#include <tuple>  // Include this header

Node::Node(int id, const std::string& name, const std::string& description)
    : id(id), name(name), description(description), monster(nullptr) {
    // Create monsters for every second node
    if (id % 2 == 0) {
        static const std::vector<std::tuple<std::string, int, int>> monsterData = {
            {"Goblin", 200, 100}, {"Orc", 150, 300}, {"Troll", 200, 20}, {"Dragon", 450, 410},
            {"Vampire", 180, 70}, {"Werewolf", 220, 75}, {"Zombie", 80, 8}, {"Giant", 250, 390},
            {"Demon", 270, 350}, {"Witch", 900, 600}
        };
        monster = new Monster(std::get<0>(monsterData[id / 2]), std::get<1>(monsterData[id / 2]), std::get<2>(monsterData[id / 2]));
    }
}

bool Node::hasMonster() const {
    return monster != nullptr;
}

Monster& Node::getMonster() {
    return *monster;
}

void Node::removeMonster() {
    delete monster;
    monster = nullptr;
}

void Node::AddConnection(Node* node) {
    connections.push_back(node);
}

std::string Node::getDescription() const {
    return description;
}