cmake_minimum_required(VERSION 3.26)
project(gameRPG)

set(CMAKE_CXX_STANDARD 17)

# Add an executable target
add_executable(gameRPG
        src/main.cpp
        src/Player.cpp
        include/Player.h
        src/Map.cpp
        include/Map.h
        include/Quest.h
        include/Item.h
        src/Quest.cpp
        src/Item.cpp
<<<<<<< HEAD
=======
        include/Weapon.h
        src/Weapon.cpp
        include/GameEngine.h
        src/GameEngine.cpp
        include/Inventory.h
        src/Inventory.cpp
        include/Potion.h
        src/Potion.cpp
        include/Shield.h
        src/Shield.cpp
>>>>>>> origin/inventory
)
