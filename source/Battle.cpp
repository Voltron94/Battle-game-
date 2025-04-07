#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include "D:/Code/Code/C++/Projet/battle_game/header/player.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/game.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/mob.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/Battle.hpp"

//Constructor

Battle::Battle(){}  
Battle::Battle(std::unique_ptr<Player> player, std::unique_ptr<Mob> mob) : player1(std::move(player)), ennemy1(std::move(mob)) {}   //Mode 1 Player constructor
Battle::Battle(std::unique_ptr<Player> _player1, std::unique_ptr<Player> _player2) : player1(std::move(_player1)), player2(std::move(_player2)) {}  //2 player constructorr

//Information

void Battle::playerInfo1()
{
    std::cout << "================================================================" << std::endl;
    std::cout << "\nNom : " << player1 ->getName()
              << "\nClasse: " << player1->getPlayerClass() 
              << "\nHealth: " << player1->getHealth() << "/" << player1->getMaxHealth()
              << "\nAttack: " << player1->getAttack() 
              << "\nDefense: " << player1->getDefense()
              << "\nSpeed: " << player1->getSpeed() << std::endl;
}

void Battle::playerInfo2()
{
    std::cout << "================================================================" << std::endl;
    std::cout << "\nNom : " << player2 ->getName()
              << "\nClasse: " << player2->getPlayerClass() 
              << "\nHealth: " << player2->getHealth() << "/" << player2->getMaxHealth()
              << "\nAttack: " << player2->getAttack() 
              << "\nDefense: " << player2->getDefense()
              << "\nSpeed: " << player2->getSpeed() << std::endl;
    std::cout << "================================================================" << std::endl;
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

void Battle::DefAction()
{
    if(mode1 == true)
    {
        player1UseDef = true;
        std::cout << "Def action \n";
        enCanAtk = false;   //the ennemy can't attack
    }

    
    if(mode2 == true)
    {
        player1UseDef = true;
        player2UseDef = true;
        
        if(player1Turn)
        {
            std::cout << player1 ->getName() << " use the Def action \n";
            pl2CanAtk = false;
        }

        if(player2Turn)
        {
            std::cout << player2 ->getName() << " use the Def action \n";
            pl1CanAtk = false;
        }
    }
        
}

void Battle::dodge()
{
    if(mode1 == true)  
    {
        //Ennemy dodge ?
        int speedDiff = ennemy1 ->getSpeed() - player1 ->getSpeed();
        int dodgeChance = (speedDiff / 12) * 100;
        if(dodgeChance < 0){dodgeChance *= -1;}
        int randNb = (std::rand() % (100 - 0 + 1));
        enDodge = false;    //default init
        
        if(dodgeChance >= randNb)
        {
            std::cout << ennemy1 ->getName() << " dodge the hit \n";
            enDodge = true;
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        }
        //Ennemy dodge ? End   

        //For the mode1, the player1 dodge are in the mobTurn()
    }
}

void Battle::attackAction()
{
    if(mode1 == true)
    {
        dodge();

        if(pl1CanAtk && !enDodge){ //The Player can attack ? 
            //init
            int playerDamage = player1 ->getAttack();
            int ennemyDef = ennemy1 ->getDefense();

            int FinalDef = ennemyDef / 3; //Player def application
            int randomAdd = (std::rand() % (14 - (-14) + 1)) + (-14); //int randomValue = (std::rand() % (max - min + 1)) + min; // range : -14 to 14
            int finalDamage = (playerDamage + randomAdd) - FinalDef; 
            std::cout << "Ennemy take : " << ennemy1 ->takeDamage(finalDamage) << " damage\n";
            
            enDodge = false;
            std::this_thread::sleep_for(std::chrono::milliseconds(750));
        } 
        else if(enUseDef == !enDodge)
        {
            std::cout << ennemy1 ->getName() << " use the defense action ! He take 0 damage " << "\n"; 
            std::this_thread::sleep_for(std::chrono::milliseconds(750));
            enUseDef = false;
            pl1CanAtk = true; //Attack condition reset
        }
        else if(enDodge)
        {
            enDodge = false;
        }
    }

    if(mode2 == true)
    {
        if(player1Turn && pl1CanAtk){ //Player1 can atk ?
            //init
            int playerDamage = player1 ->getAttack();
            int player2def = player2 ->getDefense();  

            int FinalDef = player2def / 3; //Player def application
            int randomAdd = (std::rand() % (14 - (-14) + 1)) + (-14); //int randomValue = (std::rand() % (max - min + 1)) + min; // range : -14 to 14
            int finalDamage = (playerDamage + randomAdd) - FinalDef; 
            std::cout << "The player 2 take :" << player2 ->takeDamage(finalDamage) << " damage\n";

            std::this_thread::sleep_for(std::chrono::milliseconds(750));
            player1Turn = false;
        }else if(player1Turn && !pl1CanAtk) //his turn but can't attack
        {
            std::cout << player2 ->getName() 
            << " use the defense action ! He take 0 damage \n";
            pl1CanAtk = true;
        }

        if(player2Turn && pl2CanAtk)
        {
            int playerDamage = player2 ->getAttack();
            int player1def = player1 ->getDefense(); 
            
            int FinalDef = player1def / 3; //Player def application
            int randomAdd = (std::rand() % (14 - (-14) + 1)) + (-14); 
            int finalDamage = (playerDamage + randomAdd) - FinalDef; 
            std::cout << "The player 1 take : " << player1 ->takeDamage(finalDamage) << " damage \n";
            
            std::this_thread::sleep_for(std::chrono::milliseconds(750));
            player2Turn = false;
        }else if(player2Turn && !pl2CanAtk) //his turn but can't attack
        {
            std::cout << player1 ->getName() 
            << " use the defense action ! He take 0 damage \n";
            pl2CanAtk = true;
        }

    }
}

void Battle::mobTurn()
{    
    std::cout << "Mob turn " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(750));

    //Player dodge ?
    int speedDiff =  player1 ->getSpeed()- ennemy1 ->getSpeed();
    int dodgeChance = (speedDiff / 19) * 100;
    if(dodgeChance < 0){dodgeChance *= -1;}
    int randNb = (std::rand() % (100 - 0 + 1));
    player1Dodge = false;    //default init
        
    if(dodgeChance >= randNb)
    {
        std::cout << player1 ->getName() << " dodge the hit \n";
        player1Dodge = true;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    }
    //Player dodge ? End       

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
        if(enCanAtk && !player1Dodge){
            std::cout << "Mob Attack" << std::endl;
            std::cout << "Player take : " << player1 ->takeDamage(finalDamage) << " damage\n";
        }else if(player1Dodge)
        {
            player1Dodge = false;
        }
        else{   //!enCanAtk && !player1Dodge
            std::cout << player1 ->getName() << " use the defense action ! He take 0 damage " << "\n";
            enCanAtk = true;
        }
        break;
    case 2:
        std::cout << "Def Action \n";
        pl1CanAtk = false;
        enUseDef = true;
        break;
    case 3:
        std::cout << "Use skill : coming soon \n";
        break;
    default:
        std::cout << "Error" << "\n"; 
        break;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(750));
}

//Other

void Battle::executionTurn(int choice)
{
    Game game;
    int choiceSkill;
    
    if(mode1 == true)   //Mode 1
    {
        switch (choice)
        {
        case 1:
            std::cout << "Player use attack action \n";
            attackAction();
            break;
        case 2:
            DefAction();
            break;
        case 3:
            player1 ->buffSkillList();
            choiceSkill = game.getPlayerChoice();
            player1 ->buffSkill(choiceSkill);
            break;
        case 4:
            std::cout << "Coming soon \n";
            break;
        default:
            std::cout << "Wrong choice, fail number" 
            << "\nAuto skip your turn" 
            << "\nPlease enter valide number the next time" << std::endl;
            for(int i = 0; i < 4; i++)
            {
                std::cout << 3 - i << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
            break;
        }
    }

    if(mode2 == true)
    {
        if(player1Turn == true)
        {
            switch (choice)
            {
                case 1:
                    attackAction();
                    break;
                case 2:
                    DefAction();
                    break;
                case 3:
                    player1 ->buffSkillList();
                    choiceSkill = game.getPlayerChoice();
                    player1 ->buffSkill(choiceSkill);
                    break;
                default:
                    std::cout << "Wrong choice, fail number" 
                    << "\nAuto skip your turn" 
                    << "\nPlease enter valide number the next time" << std::endl;
                    for(int i = 0; i < 4; i++)
                    {
                        std::cout << 3 - i << std::endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(750));
                    }
                    break;
            }
        }
        else if(player2Turn == true)
        {
            switch (choice)
            {
                case 1:
                    attackAction();
                    break;
                case 2:
                    DefAction();
                    break;
                default:
                    std::cout << "Wrong choice, fail number" 
                    << "\nAuto skip your turn" 
                    << "\nPlease enter valide number the next time" << std::endl;
                    for(int i = 0; i < 4; i++)
                    {
                        std::cout << 3 - i << std::endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(750));
                    }
                    break;
            }
        }
        else
        {
            std::cout << "State turn error" << std::endl;
        }
    }

}

void Battle::startOne()
{
    Game game;
    mode1 = true;

    while (ennemy1 ->getHealth() > 0 && player1 ->getHealth() > 0)  //if one of the two is dead, end of loop
    {
        //Bot Action 
        mobTurn();
        std::this_thread::sleep_for(std::chrono::milliseconds(750));
        system("cls");

        //Show stats in real time
        playerInfo1();
        mobInfo();

        //Player Action
        std::cout << "Action:   1. Attack   2. Defense   3. Use skill" << "\n";
        int choice = game.getPlayerChoice();
        executionTurn(choice);  
       
        system("cls");  
    }
    
    if (ennemy1->getHealth() <= 0) {
        std::cout << "Win ! You beat the monster !" << std::endl;
    } else if (player1->getHealth() <= 0) {
        std::cout << "Game over..." << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(750));
}


void Battle::startTwo()
{
    Game game;
    int choice;
    mode2 = true;

    while(player1 ->getHealth() > 0 && player2 ->getHealth() > 0)
    {
    //==================== Player 1 turn ====================
        if(player1 ->getHealth() > 0)
        {
            playerInfo1();
            playerInfo2();
            std::cout << "Player 1 turn \n";
            std::cout << "Action:   1. Attack   2. Defense   3. Buff skill   4. Attack/Nerf skill" << "\n";
            player2Turn = false;
            player1Turn = true;
            int choice = game.getPlayerChoice();
            executionTurn(choice);
            std::this_thread::sleep_for(std::chrono::milliseconds(750));
            system("cls");
        }

    //==================== Player 2 turn ====================
        if(player2 ->getHealth() > 0)
        {
            playerInfo1();
            playerInfo2();
            std::cout << "Player 2 turn \n";
            std::cout << "Action:   1. Attack   2. Defense   3. Use skill" << "\n";
            
            player1Turn = false;
            player2Turn = true; 
            choice = game.getPlayerChoice();
            executionTurn(choice);  
            std::this_thread::sleep_for(std::chrono::milliseconds(750));
            system("cls");
        }
    }

}