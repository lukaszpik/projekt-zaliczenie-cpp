#include <iostream>
#include <windows.h>
#include "../Projekt_LP/Game/menu.h"
#include "../Projekt_LP/Game/menu_las.h"
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    Menus m;
    GlowneMenu gm;
    gm.glowne_menu(m);
    return 0;
}