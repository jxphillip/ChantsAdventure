#include "Node.hpp"
#include <algorithm>

namespace chants {

Node::Node(int id, const std::string& name, const std::string& description)
    : id(id), name(name), description(description) {}

int Node::GetId() const { return id; }
std::string Node::GetName() const { return name; }
std::string Node::GetDescription() const { return description; }

void Node::AddConnection(Node* node) {
    connections.push_back(node);
}

std::vector<Node*> Node::GetConnections() const {
    return connections;
}

void Node::AddAsset(Asset* asset) {
    assets.push_back(asset);
}

void Node::RemoveAsset(Asset* asset) {
    assets.erase(std::remove(assets.begin(), assets.end(), asset), assets.end());
}

std::vector<Asset*> Node::GetAssets() const {
    return assets;
}

void Node::AddMonster(Monster* monster) {
    monsters.push_back(monster);
}

void Node::RemoveMonster(Monster* monster) {
    monsters.erase(std::remove(monsters.begin(), monsters.end(), monster), monsters.end());
}

std::vector<Monster*> Node::GetMonsters() const {
    return monsters;
}

} // namespace chants
