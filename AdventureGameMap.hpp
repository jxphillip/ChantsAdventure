#ifndef ADVENTUREGAMEMAP_HPP
#define ADVENTUREGAMEMAP_HPP

#include "Node.hpp"

namespace chants {

class AdventureGameMap {
public:
    AdventureGameMap();
    std::vector<Node> GetLocations() const;

private:
    void buildMapNodes();
    std::vector<Node> locations;
};

} // namespace chants

#endif // ADVENTUREGAMEMAP_HPP
