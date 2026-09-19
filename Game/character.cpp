#include <iostream>
#include <string>
#include "character.h"
using namespace std;

bool Character::isAlive()
{
    return currentHp > 0;
}

void Character::takeDamage(int dmg) {
    currentHp -= dmg;
    if (currentHp < 0) currentHp = 0;
}

int Character::getCurrentHp()
{
    return currentHp;
}

int Character::getMaxHp()
{
    return max_hp;
}
int Character::getDamage()
{
    return damage;
}

string Character::getNickname()
{
    return nickname;
}
