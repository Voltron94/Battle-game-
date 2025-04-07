#include <iostream>
#include <crtdbg.h>  
#include <windows.h>
#include "D:/Code/Code/C++/Projet/battle_game/header/player.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/game.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/mob.hpp"


int main()
{
    try {
        Game game;
        game.start();
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }  

    return 0;
}