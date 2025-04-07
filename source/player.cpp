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
Berserker::Berserker(const std::string& _name) : Player(_name, 320, 90, 45, 30, "Berserker") {}
Rider::Rider(const std::string& _name) : Player(_name, 240, 70, 60, 90, "Rider") {}
Saber::Saber(const std::string& _name) : Player(_name, 275, 80, 75, 65, "Saber") {}

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
    if (protectionBuff && oneUselimit == 1) {
        std::cout << "Protection turn are used \n";
        
        int pourcentageDamage = damage * 0.30; // 30% de réduction
        damage -= pourcentageDamage; // Réduit les dégâts de 30%
    } else if (oneUselimit > 1) {
        std::cout << "Limit reached,you can't use more Wild stamina\n"; 
        oneUselimit -= 1;
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
    int healthBuff = 20;
    int attackBuff = 60;
    int attackNerf = 11;
    int defenseBuff = 14;

    switch (choice)
    {
    case 1: //Sanity down
        std::cout << "Skill used : Wild stamina \n";
        std::cout << "Berserker lose his sanity, puissance Up \n";
        health -= healthNerf;
        std::cout << "health update : " << healthNerf * -1 << "\n";
        attack += attackBuff;
        std::cout << "Attack update : " << attackBuff << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
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
        throw std::invalid_argument("invalid argument");
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
    std::cout << "1. Battle Continuation     2. Smart Vision \n";
}


void Saber::buffSkill(int choice)
{
    //Nerf / buff
    int defenseBuff = 14;

    switch (choice)
    {
    case 1: // Battle Continuation
        std::cout << "Battle Continuation";
        defense += defenseBuff;
        std::cout << "Defense update : " << defenseBuff << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(750));
        break;
    case 2: 
        std::cout << " ";
        break;
    default:
        throw std::invalid_argument("invalid argument");
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
    std::cout << "1.      2.  \n";
}


void Rider::buffSkill(int choice)
{
    switch (choice)
    {
    case 1: //Sanity down
        std::cout << "Rider skill used";
        break;
    case 2: //Terror 
        std::cout << "";
        break;
    
    default:
        throw std::invalid_argument("invalid argument");
        break;
    }
}