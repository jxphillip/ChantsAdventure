#include <gtest/gtest.h>
#include "Player.hpp"
#include "Asset.hpp"

using namespace chants;

// Test for TakeAsset function
TEST(PlayerTest, TestTakeAsset) {
    Player player("Hero", 100, 50);
    Asset sword("Sword", "A sharp blade", 100, true);

    player.TakeAsset(sword);
    ASSERT_EQ(player.GetInventorySize(), 1);  // Ensure inventory size is 1
    ASSERT_EQ(player.GetInventoryItem(0).GetName(), "Sword");  // Ensure the correct item is in the inventory
}

// Test for DropAsset function
TEST(PlayerTest, TestDropAsset) {
    Player player("Hero", 100, 50);
    Asset sword("Sword", "A sharp blade", 100, true);

    player.TakeAsset(sword);
    ASSERT_EQ(player.GetInventorySize(), 1);  // Before dropping, inventory size should be 1

    player.DropAsset("Sword");
    ASSERT_EQ(player.GetInventorySize(), 0);  // After dropping, inventory size should be 0
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
