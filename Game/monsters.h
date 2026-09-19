//
// Created by lukip on 23.05.2026.
//

#ifndef PROJEKT_LP_MONSTERS_H
#define PROJEKT_LP_MONSTERS_H
#include <iostream>
#include "character.h"
#include "player.h"
#include <string>
#include <ctime>

class Monster;
Monster* getRandomMonster(Player & player);

class Monster : public Character {
protected:
    int xpReward;
    int hpReward;
    int moneyReward;
public:
    Monster(std::string n, int hp, int dmg, int exp, int mon) {
        nickname = n;
        max_hp = hp;
        currentHp = hp;
        damage = dmg;
        xpReward = exp;
        moneyReward = mon;
    }

    int getXpReward()
    {
        return xpReward;
    }
    int getMoneyReward()
    {
        return moneyReward;
    }
};

class Zombie : public Monster
{
    public:
        Zombie()
            : Monster("Zombie",
                      20 + rand() % 6,
                      4 + rand() % 4,
                      8 + rand() % 4,
                      5 + rand() % 6)
        {}
};

class Skeleton : public Monster
{
public:
    Skeleton()
        : Monster("Skeleton",
                  28 + rand() % 7,
                  6 + rand() % 4,
                  12 + rand() % 6,
                  5 + rand() % 6)
    {}
};

class Ghost : public Monster
{
public:
    Ghost()
        : Monster("Ghost",
                  40 + rand() % 10,
                  8 + rand() % 3,
                  20 + rand() % 8,
                  5 + rand() % 6)
    {}
};

class Golem : public Monster
{
public:
    Golem()
        : Monster("Golem",
                  60 + rand() % 20,
                  10 + rand() % 3,
                  35 + rand() % 10,
                  5 + rand() % 6)
    {}
};

class Ork : public Monster
{
public:
    Ork()
        : Monster("Ork",
                  90 + rand() % 30,
                  15 + rand() % 5,
                  50 + rand() % 20,
                  5 + rand() % 6)
    {}
};

#endif //PROJEKT_LP_MONSTERS_H
