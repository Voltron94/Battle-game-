#ifndef _BATTLE_
    #define _BATTLE_

#include <iostream>
#include <memory>
#include "D:/Code/Code/C++/Projet/battle_game/header/player.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/game.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/mob.hpp"

class Battle
{
    public:
        Battle();
        Battle(std::unique_ptr<Player> player, std::unique_ptr<Mob> mob);   //mode 1: Player vs Mob; constructor
        Battle(std::unique_ptr<Player> _player1, std::unique_ptr<Player> _player2); //mode 2: versus mode; constructor
        std::unique_ptr<Player> player1;
        std::unique_ptr<Player> player2;
        std::unique_ptr<Mob> ennemy1;

        //Action
        void executionTurn(int choice);
        void attackAction();
        void DefAction();
        void dodge();

        //MobAction
        void mobTurn();


        //GameMode
        void startOne();
        void startTwo();

        //Get Entity information
        void playerInfo1(); 
        void playerInfo2();
        void mobInfo(); 

        bool mode1; //Player vs Bot
        bool mode2; //Player vs Player (local)
        bool mode3; //Auto 
        bool mode4; //Online

    private:
        //Attack state
        bool pl1CanAtk = true;//Boolean, player  1 can use the attack action ? default: true
        bool pl2CanAtk = true;
        bool enCanAtk = true; //Ennemy can attack ?
        //Player Turn State; for mode 2
        bool player1Turn;
        bool player2Turn; 
        //State: Battle mode use
        bool player1UseDef;
        bool player2UseDef;
        bool enUseDef;
        //dodge
        bool enDodge;
        bool player1Dodge;
        bool player2Dodge;
};


#endif