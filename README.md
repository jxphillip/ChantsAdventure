

# Chants Adventure Game

This game is currently under development as part of a school project and is totally under construction. The goal is to build an engaging adventure game with different nodes, assets, and enemies.

## Objective

The main objective of **Chants Adventure Game** is to navigate through various nodes, battle monsters, collect assets, and uncover hidden treasures. The player must use strategy, manage their inventory, and interact with different elements in the game world to win. There will be specific quests or objectives to complete, and the player must interact with the world to discover and achieve these goals.

## Vocabulary

- **Node**: A location in the game world, which can have connections to other nodes. Nodes represent various places the player can explore.
- **Player**: The character controlled by the user, who will traverse nodes, collect assets, and battle monsters.
- **Monster**: The enemies the player will face in the game. These monsters will vary in strength and provide different challenges for the player.
- **Asset**: Objects that the player can collect, use, or interact with. Assets may be items for defense, health, or progression in the game.
- **Battle**: The combat mechanics in the game. The player will engage in turn-based battles with monsters, using strength and assets to defeat them.
- **Inventory**: The collection of assets that the player has gathered throughout the game.

## Player

The **Player** is the central character in the game, controlled by the user. The player has the following properties:

- **Health**: The player's life points. If health drops to zero, the player loses the game.
- **Attack Damage**: The player's fighting strength. This value is used to determine the success of attacks.
- **Defense**: The player's ability to reduce incoming damage from monsters.
- **Inventory**: The player can collect and manage assets, such as weapons and tools. The inventory is stored as a collection of assets.

### Player Actions

- **Take an asset**: Collect an item from the node the player is currently located in.
- **Drop an asset**: Remove an asset from the player's inventory.
- **use an asset**: View detailed information about an asset in the player's inventory.
- **Attack a monster**: Engage in combat with a monster using the player’s fighting strength and assets.

## Assets

**Assets** are items that the player can collect, use, and trade during the game. Each asset has the following attributes:

- **Name**: The name of the asset.
- **Description**: A short description of the asset.
- **Effect**: The effect of the asset, such as increasing attack damage, boosting health, or providing defense.

### Examples of Assets:

- **Sword**: Increases the player's attack damage.
- **Shield**: Lowers the damage taken from monster attacks.
- **Bow**: Increases the player's attack damage.
- **Health Potion**: Restores the player's health to 12500.
- **Magic Wand**: Boosts the player's health.
- **Armor**: Increases the player's health.
- **Helmet**: Increases the player's health.
- **Boots**: Increases the player's health.
- **Dagger**: Increases the player's attack damage.
- **Staff**: Boosts the player's attack damage.

## Monsters

**Monsters** are enemies in the game that the player must defeat to progress. Each monster has the following attributes:

- **Name**: The name of the monster.
- **Health**: The amount of health the monster has. If the monster's health reaches zero, the monster is defeated.
- **Attack Damage**: The amount of damage the monster can inflict on the player.

### Examples of Monsters:

- **Goblin**: A small but quick enemy.
- **Orc**: A strong and aggressive enemy.
- **Troll**: A large and powerful enemy.
- **Dragon**: A fearsome and deadly enemy.
- **Vampire**: A cunning and dangerous enemy.
- **Werewolf**: A fierce and relentless enemy.
- **Zombie**: A slow but persistent enemy.
- **Giant**: A massive and formidable enemy.
- **Demon**: A powerful and malevolent enemy.
- **Witch**: A cunning and magical enemy.

## Gameplay

The game revolves around exploring nodes, battling monsters, and collecting assets. The player navigates from node to node, each offering new challenges, such as enemies. The player’s choices determine how they interact with the world and which assets they collect.

### Game Loop

1. **Explore nodes**: The player chooses which node to move to, either by typing a node name or ID.
2. **Engage in battles**: Upon encountering a monster, the player can choose to fight or flee.
3. **Collect assets**: The player can take assets from the current node or drop unused ones.
4. **Manage inventory**: The player can check their inventory for usable items, including health-restoring or attack-enhancing assets.

## Future Development

- **Multiplayer functionality**: Allowing players to team up or compete.
- **Quest system**: Adding specific missions for the player to complete.
- **Leveling system**: Allowing the player to increase their strength and health as they progress.
- **More monsters and assets**: Introducing new challenges and items to collect.

## Installation

To build the game from source, use the following steps:

1. Clone the repository:
   
   git clone https://github.com/jxphillip/ChantsAdventure.git
   

