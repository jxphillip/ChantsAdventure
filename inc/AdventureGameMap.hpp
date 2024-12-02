#ifndef ADVENTUREGAMEMAP_HPP
#define ADVENTUREGAMEMAP_HPP

#include <vector>
#include "Node.hpp"
#include "Monster.hpp"
#include "Player.hpp"

namespace chants {

class AdventureGameMap {
public:
    AdventureGameMap();
    void buildMapNodes();
    void displayCurrentLevel(const Player& player);  // Pass Player object
    void movePlayer();
    bool isMonsterPresent();
    Monster& getCurrentMonster();
    void removeCurrentMonster();
    bool isGameWon();
    std::string getCurrentItem();
    std::vector<Node> GetLocations() const;

private:
    std::vector<Node> locations;
    int currentLevel;
};

} // namespace chants

#endif // ADVENTUREGAMEMAP_HPP