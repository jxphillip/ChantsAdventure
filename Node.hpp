#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <string>
#include "Asset.hpp"
#include "Monster.hpp"

namespace chants {

class Node {
public:
    Node(int id, const std::string& name, const std::string& description);
    
    int GetId() const;
    std::string GetName() const;
    std::string GetDescription() const;

    void AddConnection(Node* node);
    std::vector<Node*> GetConnections() const;

    void AddAsset(Asset* asset);
    void RemoveAsset(Asset* asset);
    std::vector<Asset*> GetAssets() const;

    void AddMonster(Monster* monster);
    void RemoveMonster(Monster* monster);
    std::vector<Monster*> GetMonsters() const;

private:
    int id;
    std::string name;
    std::string description;
    std::vector<Node*> connections;
    std::vector<Asset*> assets;
    std::vector<Monster*> monsters;
};

} // namespace chants

#endif // NODE_HPP
