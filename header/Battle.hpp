#ifndef _BATTLE_
    #define _BATTLE_

#include <iostream>
#include <memory>
#include "D:/Code/Code/C++/Projet/battle_game/header/class.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/game.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/mob.hpp"

class Battle
{
    public:
        Battle(std::unique_ptr<Player> player, std::unique_ptr<Mob> mob);   //mode 1: Player vs Mob; constructor
        Battle(std::unique_ptr<Player> _player1, std::unique_ptr<Player> _player2); //mode 2: versus mode; constructor
        std::unique_ptr<Player> player1;
        std::unique_ptr<Player> player2;
        std::unique_ptr<Mob> ennemy1;

        //Battle Action
        void executionTurn(int choice);
        void attackAction(int ennemyDef);
        bool mobDefAction();
        void mobTurn();


        //GameMode
        void startOne();
        void startTwo();
        void startTree();

        //Entity information
        void playerInfo1();  //Player information, refresh all turn
        void mobInfo(); 

    private:
        bool canPlAtk; //Boolean, use for the defense action
};


#endif