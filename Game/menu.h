//
// Created by lukip on 24.05.2026.
//

#ifndef PROJEKT_LP_MENU_H
#define PROJEKT_LP_MENU_H
#include <iostream>
#include <string>
#include "player.h"
#include "menu_las.h"


class GlowneMenu;
class UtworzGracza;

class Menus
{
public:
    void game_title();
    void wybor1();
    int choice_wybor1(UtworzGracza & ug, GlowneMenu & gm);
    void wybor2();
    int choice_wybor2(UtworzGracza & ug, GlowneMenu & gm);
};

class UtworzGracza
{
private:
    std::string name;
    public:
    void createPlayer(Menus & m, Player & player);
};

class GlowneMenu
{
public:
    void glowne_menu(Menus & m);
};



#endif //PROJEKT_LP_MENU_H
