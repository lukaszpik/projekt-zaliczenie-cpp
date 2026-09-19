cmake_minimum_required(VERSION 4.2)
project(Projekt_LP)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projekt_LP main.cpp
        Game/character.h
        Game/character.cpp
        Game/player.h
        Game/player.cpp
        Game/monsters.cpp
        Game/monsters.h
        Game/menu.cpp
        Game/menu.h
        Game/menu_las.h
        Game/menu_las.cpp
        Game/shop.h
        Game/shop.cpp)
