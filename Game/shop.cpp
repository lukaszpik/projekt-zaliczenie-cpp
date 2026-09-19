#include <iostream>
#include <windows.h>
#include "shop.h"
using namespace std;

void Shop::bannershop()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "==================================================" << endl;
    cout << "=                  SKLEP                         =" << endl;
    cout << "==================================================" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Shop::wyborshop()
{
    cout << "            Wybierz akcje:                       " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout << "            1. Kup cos.                          " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "            2. Wyjscie.                          " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Shop::wybieranie_shop(Player & player)
{
    bannershop();
    cout << endl;
    wyborshop();
    int wybor_shop;
    cin >> wybor_shop;

    switch (wybor_shop)
    {
    case 1:
        {
            system("cls");
            kupowanie_shop(player);
            break;
        }
    case 2:
        {
            cout << "Jak sie dorobisz to moze cos kupisz ;p." << endl;
            break;
        }
    }
}

void Shop::kupowanie_shop(Player& player)
{
        int wybor_shop2;

        bannershop();
        cout << endl;
        player.showStatus();
        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "1. Mala mikstura zycia (+20 HP) - 10 zlota" << endl;
        cout << "2. Srednia mikstura zycia (+50 HP) - 25 zlota" << endl;
        cout << "3. Duza mikstura zycia (+100 HP) - 50 zlota" << endl;
        cout << "4. Ulepszenie ataku (+1 dmg) - 30 zlota" << endl;
        cout << "5. Ulepszenie max HP (+10 HP) - 40 zlota" << endl;
        cout << "6. Wyjdz" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        do {
        cin >> wybor_shop2;
        switch (wybor_shop2)
        {
        case 1:
            {
                if (player.moneyBag >= 10)
                {
                    player.moneyBag -= 10;
                    player.heal(20);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    cout << "Kupiles mala miksture zycia!" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else
                    cout << "Za malo zlota!" << endl;
                break;
            }

        case 2:
            {
                if (player.moneyBag >= 25) {
                    player.moneyBag -= 25;
                    player.heal(50);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    cout << "Kupiles srednia miksture zycia !" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else
                    cout << "Za malo zlota!" << endl;
                break;
            }

        case 3:
            {
                if (player.moneyBag >= 50) {
                    player.moneyBag -= 50;
                    player.heal(100);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    cout << "Kupiles duza miksture!" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else
                    cout << "Za malo zlota!" << endl;
                break;
            }

        case 4:
            {
                if (player.moneyBag >= 30) {
                    player.moneyBag -= 30;
                    player.increaseDamage(1);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                    cout << "Twoj atak wzrosl o 1!" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else
                    cout << "Za malo zlota!" << endl;
                break;
            }

        case 5:
            {
                if (player.moneyBag >= 40) {
                    player.moneyBag -= 40;
                    player.increaseMaxHp(10);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    cout << "Twoje maksymalne HP wzroslo o 10!" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else
                    cout << "Za malo zlota!" << endl;
                break;
            }

        case 6:
            cout << "Wychodzisz ze sklepu..." << endl;
            break;

        default:
            cout << "Niepoprawny wybor!" << endl;
            break;
        }
    }while (wybor_shop2 != 6);
}