#ifndef _GAME_
    #define _GAME_

#include <string>
#include <memory>
#include "D:/Code/Code/C++/Projet/battle_game/header/player.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/mob.hpp"

class Game
{
    public:
        Game();
        void start();
        void Menu();

    //Creation personnage
        std::unique_ptr <Player> playerCreation(std::string playerName, int playerNB);    //Player* playerCreation(std::string playerName);
        std::unique_ptr <Mob> ennemyCreation();
        std::string getPlayerName(int playerNB);
        
    //Différent type de jeux
        void modeOne();     //mode game 1, init 
        void modeTwo();     //local 1v1 player mode
        
    //Action
        int getPlayerChoice();
    private:
    //interface privé
        void card_interface();


};


#endif