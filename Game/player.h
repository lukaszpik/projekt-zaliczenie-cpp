//
// Created by lukip on 23.05.2026.
//

#ifndef PROJEKT_LP_PLAYER_H
#define PROJEKT_LP_PLAYER_H
#include <iostream>
#include <string>
#include "character.h"


class Player : public Character
{

    protected:
    long level;
    long long xp;
    long long xptonextlevel;
    long long xpNeededForNextLevel();
public:
    int moneyBag;
    Player()
    {
        nickname = "unknown";
        max_hp = 1000;
        currentHp = 1000;
        level = 10;
        xp = 0;
        damage = 500;
        xptonextlevel = xpNeededForNextLevel();
        moneyBag = 0;
    };

public:
    void setNickname(const std::string& nickname);
    void welcomePlayer();
    void statbar(const std::string& label, long long current, long long max);
    int getLevel();
    int getDamage();
    void showStatus();
    void addXp(long long amount);
    void addMoney(long long amount_money);
    int checkPlayerLevel();
    void heal(int amountHp);
    void increaseDamage(int amountOfDamage);
    void increaseMaxHp(int amountMaxHp);
    void deathscreen();
    void winScreen();
};
#endif //PROJEKT_LP_PLAYER_H
