# Add the test executable
add_executable(adventure_test adventuretest.cpp ../src/AdventureGameMap.cpp ../src/Node.cpp ../src/Asset.cpp ../src/Player.cpp ../src/Monster.cpp)

# Link the test executable with gTest
find_package(GTest REQUIRED)
target_link_libraries(adventure_test PRIVATE GTest::GTest GTest::Main)

# Include the header files
target_include_directories(adventure_test PRIVATE ../inc)
