//
// Created by lukip on 25.05.2026.
//

#ifndef PROJEKT_LP_MENU_LAS_H
#define PROJEKT_LP_MENU_LAS_H
#include <iostream>
#include "player.h"
#include "menu.h"
#include "monsters.h"

class GlowneMenu;
class Menus;

class MenuLas
{
    public:
    void forest();
    void wyborforest();
    int run(Player& r);
    void waitForEnter();
    int preCombat(Player& player);
    int combat(Player & player, Monster & enemy);
    void endgame(Player & player);

    private:
    bool wLesie = true;
};
#endif //PROJEKT_LP_MENU_LAS_H
