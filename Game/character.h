
// Created by lukip on 23.05.2026.
//

#ifndef PROJEKT_LP_CHARACTER_H
#define PROJEKT_LP_CHARACTER_H
#include <iostream>
#include <string>

class Character
{
protected:
    std::string nickname;
    int currentHp;
    int max_hp;
    int damage;

public:
    bool isAlive();
    void takeDamage(int dmg);
    int getCurrentHp();
    int getMaxHp();
    int getDamage();
    std::string getNickname();
};
#endif //PROJEKT_LP_CHARACTER_H
