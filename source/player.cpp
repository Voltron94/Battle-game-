#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include "D:/Code/Code/C++/Projet/battle_game/header/player.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/game.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/mob.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/Battle.hpp"


Player::Player(const std::string& _name, int _health, int _attack, int _defense,int _speed, const std::string& _PlayerClass)
: name(_name), health(_health), maxHealth(_health), attack(_attack), defense(_defense), speed(_speed), playerClass(_PlayerClass){
}

//Statistique/Info
Berserker::Berserker(const std::string& _name) : Player(_name, 320, 90, 85, 25, "Berserker") {}
Rider::Rider(const std::string& _name) : Player(_name, 240, 65, 60, 110, "Rider") {}
Saber::Saber(const std::string& _name) : Player(_name, 275, 75, 75, 85, "Saber") {}

//Player 
void Player::classInfo()    //Original virtual fonction info for Player
{
    std::cout << "whats a heck are you doing here ?" << std::endl;
}

void Player::buffSkill(int choice)
{
    std::cout << "whats a heck are you doing here ?" << std::endl;
}

void Player::buffSkillList()
{
    std::cout << "whats a heck are you doing here ?" << std::endl;
}

int Player::takeDamage(int damage)
{
    // Berserker Buff Active ?
    if (protectionBuff) {
        std::cout << "Protection turn are used \n";
        
        int pourcentageDamage = damage * 0.30; // 30% de réduction
        damage -= pourcentageDamage; // Réduit les dégâts de 30%
    }


    health -= damage; 
    return damage;
}


//Berserker
void Berserker::classInfo()
{
    std::cout << "\nClass: " << playerClass 
              << "\nHealth: " << health << "/" << maxHealth 
              << "\nAttack: " << attack 
              << "\nDefense: " << defense 
              << "\nSpeed: " << speed << std::endl;
}

void Berserker::buffSkillList()
{
    std::cout << "1. Sanity Down     2. Wild stamina  \n";
}

void Berserker::buffSkill(int choice)
{
    //Nerf / buff
    int healthNerf = 80;
    int attackBuff = 30;
    int defenseBuff = 12;

    switch (choice)
    {
    case 1: //Sanity down
        if(oneUselimit < 1){
            std::cout << "Skill used : Wild stamina \n";
            std::cout << "Berserker lose his sanity, puissance Up \n";
            health -= healthNerf;
            std::cout << "health update : " << healthNerf * -1 << "\n";
            attack += attackBuff;
            std::cout << "Attack update : " << attackBuff << "\n";
            oneUselimit += 1;
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        }else{ 
            std::cout << "Limit reached,you can't use more Wild stamina\n"; 
        }
        break;
    case 2: 
        std::cout << "Wild stamina" << "\n";
        std::cout << "Berserker gain sanity, 30% " << "damage protection \n";
        std::cout << "Can use only for 1 time, use more is without effect \n";
        protectionBuff = true;
        oneUselimit += 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        break;
    default:
        std::cout << "Wrong choice, fail number" 
        << "\nAuto skip your turn" 
        << "\nPlease enter valide number the next time" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        break;
    }
}

//Saber
void Saber::classInfo()
{
    std::cout << "\nClass: " << playerClass 
              << "\nHealth: " << health << "/" << maxHealth 
              << "\nAttack: " << attack 
              << "\nDefense: " << defense 
              << "\nSpeed: " << speed << std::endl;
}

void Saber::buffSkillList()
{
    std::cout << "1. Battle Continuation     2. Last encore \n";
}


void Saber::buffSkill(int choice)
{
    //Nerf / buff
    int defenseBuff = 14;

    switch (choice)
    {
    case 1: // Battle Continuation
        if(threeUselimit < 3)
        {
            std::cout << "Battle Continuation \n";
            std::cout << "Can use only for 3 time, use more is without effect\n";
            defense += defenseBuff;
            std::cout << "Defense update : " << defenseBuff << "\n";
            threeUselimit += 1;
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        }else
        {
            std::cout << "Can't use this atttack, skill limit are reach \n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1800));
        }       

        break;
    case 2: 
        if(health < 45 && oneUselimit < 1)
        {
            std::cout << "Last encore";
            std::cout << "For honnor, saber class give you the power of the last chance \n";
            std::cout << "Can use only for 1 time, use more is without effect \n";
            oneUselimit += 1;
            std::cout << "healt Update : +45 \n";
            std::cout << "attack Update: +35 \n";
            std::cout << "defense Update : +20 \n";
           
            health += 45;
            attack += 35;
            defense += 20;

            std::this_thread::sleep_for(std::chrono::milliseconds(2500));
        }else
        {
            std::cout << "Can't use this atttack with High Hp, less than 45 hp for use it \n";
            std::cout << "Or, you have reached your usage limit \n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1800));
        }
        break;
    default:
        std::cout << "Wrong choice, fail number" 
        << "\nAuto skip your turn" 
        << "\nPlease enter valide number the next time" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        break;
    }
}

//Rider
void Rider::classInfo()
{
    std::cout << "\nClass: " << playerClass 
              << "\nHealth: " << health << "/" << maxHealth 
              << "\nAttack: " << attack 
              << "\nDefense: " << defense 
              << "\nSpeed: " << speed << std::endl;
}

void Rider::buffSkillList()
{
    std::cout << "1.Bellerophon      2.Sacrifice  \n";
}


void Rider::buffSkill(int choice)
{
    switch (choice)
    {
    case 1: //Bellerophon / Pegas
        if(oneUselimit < 1)
        {
            std::cout << "Bellerophon";
            std::cout << "Rider summons a legendary pegasus, Bellerophon !";
            std::cout << "Can use only for 1 time, use more is without effect \n";
            std::cout << "Speed Update : +70 \n";
            speed += 70;
            std::cout << "Defense Update : -15 \n";
            defense -= 15;
            oneUselimit += 1;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        }
        else{
            std::cout << "You have reached your usage limit \n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        }
        break;
    case 2: 
        std::cout << "Sacrifice \n";
        std::cout << "Sacrifice your speed for more damage \n";
        std::cout << "Increase damage \n";
        attack += 20;
        std::cout << "Speed Update : -40 \n";
        speed -= 40;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        break;
    
    default:
        std::cout << "Wrong choice, fail number" 
        << "\nAuto skip your turn" 
        << "\nPlease enter valide number the next time" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        break;
    }
}