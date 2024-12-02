#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <vector>
#include "Monster.hpp"

class Node {
public:
    Node(int id, const std::string& name, const std::string& description);
    bool hasMonster() const;
    Monster& getMonster();
    void removeMonster();
    void AddConnection(Node* node);
    std::string getDescription() const;

private:
    int id;
    std::string name;
    std::string description;
    Monster* monster;
    std::vector<Node*> connections;
};

#endif // NODE_HPP