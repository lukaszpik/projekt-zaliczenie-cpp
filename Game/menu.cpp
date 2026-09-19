#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include "menu.h"
using namespace std;

void Menus::game_title()
{
    system("cls");
    cout << "╔══════════════════════════════════════════╗" << endl;
    cout << "║                                          ║" << endl;
    cout << "║     L A S   O S T A T E C Z N E G O      ║" << endl;
    cout << "║           Z A L I C Z E N I A            ║" << endl;
    cout << "║                                          ║" << endl;
    cout << "║           by Lukasz Pikulik              ║" << endl;
    cout << "║                                          ║" << endl;
    cout << "╚══════════════════════════════════════════╝" << endl;
    cout << endl;
}


void Menus::wybor1()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout << "            1. Graj                              " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "            2. Wyjscie                           " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Menus::wybor2()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout << "            1. Stworz postac                     " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "            2. Wyjscie                           " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}



void UtworzGracza::createPlayer(Menus & m, Player & player)
{
    m.game_title();
    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout << "           Podaj nazwe postaci:              " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    cin >> name;
    player.setNickname(name);
}

void GlowneMenu::glowne_menu(Menus& m)
{
    UtworzGracza ug;
    Player player;
    m.game_title();
    m.wybor1();
    m.choice_wybor1(ug, *this);
}


int Menus::choice_wybor1(UtworzGracza & ug, GlowneMenu & gm)
{
    int choice;
    cin >> choice;
    switch(choice)
    {
    case 1:
        system("cls");
        game_title();
        wybor2();
        return choice_wybor2(ug, gm);
    case 2:
        system("cls");
        cout << "Zamykanie gry..." << endl;
        return 0;
    default:
        cout << "Nieprawidłowy wybor!" << endl;
        break;
    }
    return 0;
}

int Menus::choice_wybor2(UtworzGracza & ug, GlowneMenu& gm)
{
    int choice2;
    cin >> choice2;
    switch(choice2)
    {
    case 1:
        {
            system("cls");
            game_title();
            Player player;
            ug.createPlayer(*this, player);
            player.welcomePlayer();
            MenuLas f;
            f.run(player);
            break;
        }
    case 2: {
            system("cls");
            game_title();
            wybor1();
            choice_wybor1(ug, gm);
            return 0;
    }
        default:
           cout << "Niewlasciwy wybor!" << endl;
           break;
    }
    return 0;
}


