#include "monsters.h"
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

Monster* getRandomMonster(Player & player)
{
    vector<Monster*> availableMonsters;

    if (player.getLevel() >= 1) availableMonsters.push_back(new Zombie());
    if (player.getLevel() >= 2) availableMonsters.push_back(new Skeleton());
    if (player.getLevel() >= 4) availableMonsters.push_back(new Ghost());
    if (player.getLevel() >= 6) availableMonsters.push_back(new Golem());
    if (player.getLevel() >= 8) availableMonsters.push_back(new Ork());

    int index = rand() % availableMonsters.size();
    return availableMonsters[index];
}
