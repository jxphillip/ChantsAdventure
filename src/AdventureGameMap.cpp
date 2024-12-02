
#include "AdventureGameMap.hpp"
#include <iostream>
#include <tuple>  // Include this header

namespace chants {

AdventureGameMap::AdventureGameMap() : currentLevel(0) {
    buildMapNodes();
}

void AdventureGameMap::buildMapNodes() {
    // Build all nodes with descriptions
    Node home(0, "Home", "You are standing in the front yard of a warm and comfortable home that exudes charm and tranquility, inviting visitors to feel welcome even before they step inside.\n");

    Node mountain(1, "Mountain", "A majestic mountain rises grandly from the landscape, its towering peak piercing the sky and exuding a sense of awe and reverence.\n");

    Node city(2, "City", "A typical city is a bustling hub of activity, blending diverse elements of architecture, culture, and human interaction. It features a variety of neighborhoods, each with its own character, from high-rise apartment buildings and business districts to residential areas and parks.\n");

    Node ocean(3, "Ocean", "The sea appears restless and chaotic, with surging swells that seem to roil and churn, as if the ocean itself is furious, thrashing in a wild, unpredictable rhythm.\n");

    Node island(4, "Island", "In the midst of an angry sea, the island appears as a defiant outpost, battered but unyielding against the surrounding chaos. Jagged cliffs rise abruptly from the churning waters, their rugged faces streaked with dark, wet stone, dripping with the constant assault of waves.\n");

    Node hut(5, "Hut", "A hut stands as a weathered refuge, small and sturdy against the backdrop of the raging sea. Its wooden walls, gray and splintered from years of exposure to salt and wind, are patched together with whatever materials the island could provide—driftwood, palm fronds, and rough-hewn stone. The roof is thatched with dried leaves, lashed tightly to withstand the powerful gusts that whip across the island.\n");

    Node quicksand(6, "Quick Sand", "A patch of treacherous quicksand lurks, deceptively blending into the surrounding terrain. It lies at the edge of a narrow clearing, where the ground transitions from rocky soil to a stretch of damp, silty earth.\n");

    Node cave(7, "Cave", "Here is a cave nestled into the rocky cliffs that rise above the angry sea, is a cave that seems carved by nature's fury over centuries. Its entrance is half-hidden by thick vines and jagged boulders, giving it an air of mystery and shelter. The mouth of the cave is wide and low, just tall enough for a person to crouch and enter, and it faces away from the wind, offering some protection from the relentless storm.\n");

    Node beach(8, "Beach", "A beautiful beach stretches out in a graceful curve, bordered by soft, powdery sand that gleams white under the sunlight. Each grain feels fine and smooth beneath bare feet, as though sculpted by the gentle hands of time and tide. The shoreline is kissed by the crystal-clear waters of the ocean, where the surf laps quietly and rhythmically, creating a soft, soothing sound with each wave.\n");

    Node forest(9, "Forest", "A dense forest where sunlight struggles to penetrate through the thick canopy above. The air is cool and moist, and the ground is covered in thick layers of fallen leaves.\n");

    Node village(10, "Village", "A peaceful village nestled in a valley, with quaint houses, a bustling market square, and winding cobblestone streets.\n");

    Node castle(11, "Castle", "A towering medieval castle with stone walls and a moat, offering an imposing view of the surrounding land.\n");

    Node desert(12, "Desert", "A vast expanse of golden sand, with nothing but scorching heat and the occasional cactus in sight.\n");

    Node swamp(13, "Swamp", "A murky swamp where the air is thick with the smell of damp earth and rotting vegetation. The ground is soft and treacherous.\n");

    Node tundra(14, "Tundra", "A cold, barren landscape, dominated by snow and ice. The wind howls relentlessly, and the silence is almost oppressive.\n");

    Node volcano(15, "Volcano", "A massive, active volcano whose molten lava bubbles ominously in the crater. The ground is scorched, and the air is thick with ash.\n");

    Node ruins(16, "Ruins", "The remnants of an ancient civilization, with crumbling stone structures and overgrown vegetation. It feels like a place steeped in history and mystery.\n");

    Node forestEdge(17, "Forest Edge", "The edge of the forest, where the trees start to thin out and the land opens up to vast plains.\n");

    Node river(18, "River", "A wide river flowing rapidly through a valley. The sound of rushing water fills the air, and the banks are lined with wild vegetation.\n");

    Node monastery(19, "Monastery", "An ancient, serene monastery perched atop a hill, offering a peaceful retreat with breathtaking views of the surrounding land.\n");

    // Connect nodes with paths
    home.AddConnection(&mountain);
    home.AddConnection(&city);

    mountain.AddConnection(&home);
    mountain.AddConnection(&ocean);
    mountain.AddConnection(&city);

    ocean.AddConnection(&mountain);
    ocean.AddConnection(&city);
    ocean.AddConnection(&island);

    city.AddConnection(&home);
    city.AddConnection(&mountain);
    city.AddConnection(&ocean);

    island.AddConnection(&ocean);
    island.AddConnection(&cave);
    island.AddConnection(&beach);
    island.AddConnection(&quicksand);
    island.AddConnection(&hut);

    cave.AddConnection(&home);
    cave.AddConnection(&beach);
    cave.AddConnection(&island);

    beach.AddConnection(&cave);
    beach.AddConnection(&island);

    hut.AddConnection(&island);
    hut.AddConnection(&quicksand);

    quicksand.AddConnection(&hut);
    quicksand.AddConnection(&island);

    // Add the new nodes and their connections
    village.AddConnection(&castle);
    village.AddConnection(&forest);
    forest.AddConnection(&forestEdge);
    forestEdge.AddConnection(&river);
    river.AddConnection(&monastery);

    // Adding more connections to ensure we have 20 nodes connected
    desert.AddConnection(&monastery);
    ruins.AddConnection(&tundra);
    tundra.AddConnection(&volcano);

    // Build map in the same order as Node Ids above.
    locations.push_back(home);
    locations.push_back(mountain);
    locations.push_back(city);
    locations.push_back(ocean);
    locations.push_back(island);
    locations.push_back(hut);
    locations.push_back(quicksand);
    locations.push_back(cave);
    locations.push_back(beach);
    locations.push_back(forest);
    locations.push_back(village);
    locations.push_back(castle);
    locations.push_back(desert);
    locations.push_back(swamp);
    locations.push_back(tundra);
    locations.push_back(volcano);
    locations.push_back(ruins);
    locations.push_back(forestEdge);
    locations.push_back(river);
    locations.push_back(monastery);
}

void AdventureGameMap::displayCurrentLevel(const Player& player) {
    std::cout << "You are on level " << currentLevel + 1 << " (" << locations[currentLevel].getDescription() << ")" << std::endl;
    std::cout << "Player Health: " << player.getHealth() << std::endl;
    if (locations[currentLevel].hasMonster()) {
        std::cout << "There is a monster here: " << locations[currentLevel].getMonster().getName() << " with " << locations[currentLevel].getMonster().getHealth() << " health." << std::endl;
    } else {
        std::cout << "No monster here." << std::endl;
    }
    std::cout << "Item at this node: " << getCurrentItem() << std::endl;
}

void AdventureGameMap::movePlayer() {
    if (currentLevel < locations.size() - 1) {
        ++currentLevel;
    } else {
        std::cout << "You are at the final level!" << std::endl;
    }
}

bool AdventureGameMap::isMonsterPresent() {
    return locations[currentLevel].hasMonster();
}

Monster& AdventureGameMap::getCurrentMonster() {
    return locations[currentLevel].getMonster();
}

void AdventureGameMap::removeCurrentMonster() {
    locations[currentLevel].removeMonster();
}

bool AdventureGameMap::isGameWon() {
    for (const auto& location : locations) {
        if (location.hasMonster()) {
            return false;
        }
    }
    return true;
}

std::string AdventureGameMap::getCurrentItem() {
    static const std::vector<std::string> items = {
        "Sword", "Shield", "Bow", "Health Potion", "Magic Wand", "Armor", "Helmet", "Boots", "Ring", "Amulet",
        "Dagger", "Staff", "Crossbow", "Elixir", "Lantern", "Map", "Compass", "Rope", "Torch", "Book of Spells"
    };
    return items[currentLevel % items.size()];
}

std::vector<Node> AdventureGameMap::GetLocations() const {
    return locations;
}

} // namespace chants