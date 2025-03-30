#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include "D:/Code/Code/C++/Projet/battle_game/header/class.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/game.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/mob.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/Battle.hpp"

//Constructor

Battle::Battle(std::unique_ptr<Player> player, std::unique_ptr<Mob> mob) : player1(std::move(player)), ennemy1(std::move(mob)) {}   //Mode 1 Player constructor
Battle::Battle(std::unique_ptr<Player> _player1, std::unique_ptr<Player> _player2) : player1(std::move(_player1)), player2(std::move(_player2)) {}  //2 player constructorr

//Information

void Battle::playerInfo1()
{
    std::cout << "================================================================" << std::endl;
    std::cout << "\nNom : " << player1 ->getName()
              << "\nClasse: " << player1->getPlayerClass() 
              << "\nVHealth: " << player1->getHealth() << "/" << player1->getMaxHealth()
              << "\nAttack: " << player1->getAttack() 
              << "\nDefense: " << player1->getDefense()
              << "\nSpeed: " << player1->getSpeed() << std::endl;
}

void Battle::mobInfo()
{
    std::cout << "================================================================" << std::endl;
    std::cout << "\nMob name: " << ennemy1->getName() 
              << "\nHealth: " << ennemy1->getHealth() << "/" << ennemy1->getMaxHealth()
              << "\nAttack: " << ennemy1->getAttack() 
              << "\nDefense: " << ennemy1->getDefense()
              << "\nSpeed: " << ennemy1->getSpeed() << std::endl; 
    std::cout << "================================================================" << std::endl;      
}

//Action

void Battle::plDefAction()
{
    std::cout << "Def action" << "\n";
    enCanAtk = false;   //the ennemy can't attack
}

void Battle::attackAction(int ennemyDef)
{
    if(plCanAtk){ //The Player can attack ? 
        //init
        int playerDamage = player1 ->getAttack();

        int FinalDef = ennemyDef / 3; //Player def application
        int randomAdd = (std::rand() % (14 - (-14) + 1)) + (-14); //int randomValue = (std::rand() % (max - min + 1)) + min; // range : -14 to 14
        int finalDamage = (playerDamage + randomAdd) - FinalDef; 
        ennemy1 ->takeDamage(finalDamage);

        plCanAtk = true;//attack condition, reset
        std::this_thread::sleep_for(std::chrono::seconds(1));
    } else
    {
        std::cout << ennemy1 ->getName() << " use the defense action ! He take 0 damage " << "\n"; 
        std::this_thread::sleep_for(std::chrono::seconds(1));
        plCanAtk = true;
    }
}

void Battle::mobTurn()
{    
    std::cout << "Mob turn " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
                //Mob Attack
        //init
    int ennemyDamage = ennemy1 ->getAttack();
    int PlayerDef = player1 ->getDefense();

    int FinalDef = PlayerDef / 3;   //Player def application
    int randomAdd = (std::rand() % (14 - (-14) + 1)) + (-14); // range : -14 to 14
    int finalDamage = (ennemyDamage + randomAdd) - FinalDef;


    std::srand(std::time(0));
    int randomAction  = (std::rand()  % 2) + 1; // int randomValue = (std::rand() % (max - min + 1)) + min; 

    switch (randomAction)
    {
    case 1:
        if(enCanAtk){
            std::cout << "Mob Attack" << std::endl;
            player1 ->takeDamage(finalDamage);
        }else{
            std::cout << player1 ->getName() << " use the defense action ! He take 0 damage " << "\n";
            enCanAtk = true;
        }
        break;
    case 2:
        std::cout << "Def Action \n";
        plCanAtk = false;
        break;
    case 3:
        std::cout << "Use skill : coming soon \n";
        break;
    default:
        std::cout << "Error" << "\n"; 
        break;
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
}

//Other

void Battle::executionTurn(int choice)
{
    switch (choice)
    {
    case 1:
        attackAction(ennemy1 ->getDefense());
        break;
    case 2:
        plDefAction();
        break;
    
    default:
        std::cout << "Wrong choice, fail number" 
        << "\nAuto skip your turn" 
        << "\nPlease enter valide number the next time" << std::endl;
        for(int i = 0; i < 4; i++)
        {
            std::cout << 3 - i << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        break;
    }
}

void Battle::startOne()
{
    Game game;

    while (ennemy1 ->getHealth() > 0 && player1 ->getHealth() > 0)  //if one of the two is dead, end of loop
    {
        //Bot Action 
        mobTurn();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("cls");

        //Show stats in real time
        playerInfo1();
        mobInfo();

        //Player Action
        std::cout << "Action:   1. Attack   2. Defense   3. Use skill   4. Run  " << "\n";
        int choice = game.getPlayerChoice();
        executionTurn(choice);  //for player
       
        system("cls");  
    }
    
    if (ennemy1->getHealth() <= 0) {
        std::cout << "Win ! You beat the monster !" << std::endl;
    } else if (player1->getHealth() <= 0) {
        std::cout << "Game over..." << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));
}


