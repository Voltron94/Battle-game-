#ifndef _GAME_
    #define _GAME_

#include <string>
#include <memory>
#include "D:/Code/Code/C++/Projet/battle_game/header/class.hpp"
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
        std::string getPlayerName();
        
    //Différent type de jeux
        void modeOne();     //mode game 1, init 
        
    //Action
        int getPlayerChoice();
    private:
    //interface privé
        void card_interface();


};


#endif