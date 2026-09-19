//
// Created by lukip on 25.05.2026.
//
#include <iostream>
#include <windows.h>
#include "menu_las.h"
#include "monsters.h"
#include "shop.h"
using namespace std;


void MenuLas::forest()
{
    cout << "\n" << R"( ... )" << "\n";
    cout << R"( &&&   &&&                          &&&   &&&
               &&&&& &&&&&                        &&&&& &&&&&
              &&&&&&&&&&&&&                      &&&&&&&&&&&&&
                 ||    ||                           ||    ||
                ||||  ||||                         ||||  ||||
                 ||    ||                           ||    ||
              ^^^^^^^^^^^^__________________________^^^^^^^^
              ^^^^^^^________________________________^^^^^^^
              ^^^^^^^^________________________________^^^^^^^^
              ^^^^^^^________________________________^^^^^^^)" << endl;
    cout << "\n" << R"( ... )" << "\n";
}


void MenuLas::wyborforest()
{
    cout << "            Wybierz akcje:                       " << endl;
    cout << "            1. Idz do lasu                       " << endl;
    cout << "            2. Sklep                             " << endl;
    cout << "            3. Wyjscie                           " << endl;
}

int MenuLas::run(Player& r)
{


    while (wLesie){
        forest();
        r.showStatus();
        wyborforest();

        int wyborf;
        cin >> wyborf;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "Zły wybor!" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            continue;
        }

        switch (wyborf)
        {
        case 1:
            {
                system("cls");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                cout << "Idziesz w glab lasu..." << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

                int czyBoss = r.checkPlayerLevel();
                if (czyBoss == 999)
                {
                    endgame(r);
                }
                else if (czyBoss == 0)
                {
                    preCombat(r);
                    break;
                }
                break;
            }

        case 2:
            {
                system("cls");
                Shop s;
                s.wybieranie_shop(r);
                break;
            }

        case 3:
            {
                system("cls");
                wLesie = false;
                cout << "Zamykanie gry... " << endl;

                return 0;
            }

        default:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "Zly wybor!" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
    }
}

void MenuLas::waitForEnter()
{
    cin.clear();
    cin.ignore();
    cin.get();
}

int MenuLas::preCombat(Player & player)
{
    Monster* enemy = getRandomMonster(player);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout << "\nSpotkales " << enemy->getNickname() << "!" << endl;
    cout << "HP: " << enemy->getCurrentHp() << "/" << enemy->getMaxHp() << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    cout << "\nCo chcesz zrobic:" << endl;
    cout << "1. Walcz" << endl;
    cout << "2. Uciekaj" << endl;

    int precombat_wybor;
    cin >> precombat_wybor;

    switch (precombat_wybor)
    {
    case 1: {
            system("cls");
            combat(player, *enemy);
            break;
    }
    case 2:
        {
            system("cls");
            cout << "Uciekasz z powrotem do bezpiecznego miejsca..." << endl;
            delete enemy;
            return 0;
        }
        default:
        {
            cout << "Nieznana opcja -  stoisz niezdecydowany.." << endl;
            break;
        }
    }
    delete enemy;
    return 0;
}


int MenuLas::combat(Player& player, Monster& enemy)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout << "\n======== WALKA ROZPOCZETA =========" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "Przeciwnik: " << enemy.getNickname() << " (HP: " << enemy.getCurrentHp() << "/" << enemy.getMaxHp() << ")" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    while (player.isAlive() && enemy.isAlive())
    {
        cout << "Naciśnij ENTER, aby zaatakowac..." << endl;
        waitForEnter();

        enemy.takeDamage(player.getDamage());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "Uderzasz " << enemy.getNickname() << " za " << player.getDamage() << " obrazen!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        if (!enemy.isAlive())
        {
            cout << "Pokonales  " << enemy.getNickname() << "!" << endl;
            player.addXp(enemy.getXpReward());
            player.addMoney(enemy.getMoneyReward());
            break;
        }

        int enemyDamage = enemy.getDamage() + rand() % 2;
        player.takeDamage(enemyDamage);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << enemy.getNickname() << " kontratakuje za " << enemyDamage << " obrazen!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        if (!player.isAlive())
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "Zostales pokonany przez " << enemy.getNickname() << "..." << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            player.deathscreen();
            wLesie = false;
            break;
        }

        cout << "\nTwoje HP: " << player.getCurrentHp() << "/" << player.getMaxHp() << " | HP przeciwnika: " << enemy.getCurrentHp() << "/" << enemy.getMaxHp() << endl;
    }
    cout << "\n=== KONIEC WALKI ===" << endl;
    cout << "Nacisnij ENTER, aby wrocic..." << endl;
    waitForEnter();
    return 0;
}

void MenuLas::endgame(Player& player)
{
    system("cls");
    Monster boss("ZALICZENIE PROJEKTU", 500, 50, 99999, 99999);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "\n=== WALKA Z BOSSEM OSTATECZNYM ===" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    combat(player, boss);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    if (player.isAlive())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "\nPokonales BOSSA! Wygrales gre!" << endl;
        cout << endl;
        player.winScreen();
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "\nBoss cie pokonal... Slabiutko" << endl;
        player.deathscreen();
        wLesie = false;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "Nacisnij ENTER, aby wrocic..." << endl;
    waitForEnter();
}

