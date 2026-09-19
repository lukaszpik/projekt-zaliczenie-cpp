//
// Created by lukip on 23.05.2026.
//
#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>
#include "player.h"
using namespace std;

void Player::setNickname(const string& name)
{
    nickname = name;
}

void Player::welcomePlayer()
{
    cout << "Witaj " << nickname << "!" << endl;
}

void Player::statbar(const string& label, long long current, long long max)
{
    int szerokosc = 20;
    double wypelnienie = double(current) * szerokosc / max;

    cout << label << " [";
    for (int i = 0; i < szerokosc; i++)
    {
        if (i < wypelnienie)
            cout << "#";
        else
            cout << "-";
    }
    cout << "] " << current << "/" << max << endl;
}

int Player::getLevel()
{
    return level;
}

long long Player::xpNeededForNextLevel()
{
    return 100 * pow(level, 1.3);
}

int Player::getDamage()
{
    return damage;
}

void Player::showStatus()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "===============================================" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << nickname << "," <<  " Level" << " " << level << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    statbar("HP", currentHp, max_hp);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    statbar("XP", xp, xpNeededForNextLevel());
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << "Moc ataku: " << getDamage() << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout << "Zloto: " << moneyBag << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "===============================================" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

int Player::checkPlayerLevel()
{
    if (level == 10)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "\n=== UWAGA! ===" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "Osiagnales poziom 10!" << endl;
        cout << "Mozesz teraz zmierzyc sie z BOSSEM OSTATECZNYM!" << endl;
        cout << "Czy chcesz z nim walczyc?" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "1. Tak, walczymy!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "2. Nie, wracam sie dozbroic." << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        int wybor_boss;
        cin >> wybor_boss;

        if (wybor_boss == 1)
        {
            return 999;
        }
        else
        {
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            cout << "Rozsadna decyzja. Wrocisz, gdy bedziesz gotowy." << endl;
            return 0;
        }
    }
    return 0;
}

void Player::addXp(long long amount)
{
    xp += amount;
    long long reqXP = xpNeededForNextLevel();

    if (xp >= reqXP)
    {
        xp -= reqXP;
        level++;
        cout << "Awansowales na poziom " << level << "!" << endl;
    }
}

void Player::addMoney(long long amount_money) {moneyBag += amount_money; }

void Player::heal(int amountHp)
{
    currentHp += amountHp;
    if (currentHp > max_hp)
        currentHp = max_hp;
}

void Player::increaseDamage(int amountOfDamage)
{
    damage += amountOfDamage;
}

void Player::increaseMaxHp(int amountMaxHp)
{
    max_hp += amountMaxHp;
}

void Player::deathscreen()
{
        system("cls");

        cout << R"(

  ██████   █████  ███    ███ ███████      ██████  ██    ██ ███████ ██████
 ██       ██   ██ ████  ████ ██          ██    ██ ██    ██ ██      ██   ██
 ██   ███ ███████ ██ ████ ██ █████       ██    ██ ██    ██ █████   ██████
 ██    ██ ██   ██ ██  ██  ██ ██          ██    ██  ██  ██  ██      ██   ██
  ██████  ██   ██ ██      ██ ███████      ██████    ████   ███████ ██   ██


                  ☠  ZOSTAŁEŚ POKONANY!  ☠

             Twoja przygoda dobiegła końca...

)";
}

void Player::winScreen()
{
    system("cls");

    cout << R"(

 ██    ██  ██████  ██    ██     ██     ██ ██ ███    ██
  ██  ██  ██    ██ ██    ██     ██     ██ ██ ████   ██
   ████   ██    ██ ██    ██     ██  █  ██ ██ ██ ██  ██
    ██    ██    ██ ██    ██     ██ ███ ██ ██ ██  ██ ██
    ██     ██████   ██████       ███ ███  ██ ██   ████


               ★ ★ ★ ZWYCIĘSTWO! ★ ★ ★

          Pokonałeś ostatecznego przeciwnika!


)";
}