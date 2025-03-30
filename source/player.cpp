#include <iostream>
#include <memory>
#include "D:/Code/Code/C++/Projet/battle_game/header/class.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/game.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/mob.hpp"


Player::Player(const std::string& _name, int _health, int _attack, int _defense,int _speed, const std::string& _PlayerClass)
: name(_name), health(_health), maxHealth(_health), attack(_attack), defense(_defense), speed(_speed), playerClass(_PlayerClass){
}

//Statistique/Info
Berserker::Berserker(const std::string& _name) : Player(_name, 200, 152, 75, 60, "Berserker") {}
Rider::Rider(const std::string& _name) : Player(_name, 165, 144, 70, 99, "Rider") {}
Saber::Saber(const std::string& _name) : Player(_name, 185, 161, 80, 75, "Saber") {}

//Player 
void Player::classInfo()    //Original virtual fonction info for Player
{
    std::cout << "Information Error" << std::endl;
}

//Berserker
void Berserker::classInfo()
{
    std::cout << "\nClasse: " << playerClass 
              << "\nVie: " << health << "/" << maxHealth 
              << "\nAttaque: " << attack 
              << "\nDefense: " << defense 
              << "\nVitesse: " << speed << std::endl;
}

//Saber
void Saber::classInfo()
{
    std::cout << "\nClasse: " << playerClass 
              << "\nVie: " << health << "/" << maxHealth 
              << "\nAttaque: " << attack 
              << "\nDefense: " << defense 
              << "\nVitesse: " << speed << std::endl;
}

//Rider
void Rider::classInfo()
{
    std::cout << "\nClasse: " << playerClass 
              << "\nVie: " << health << "/" << maxHealth 
              << "\nAttaque: " << attack 
              << "\nDefense: " << defense 
              << "\nVitesse: " << speed << std::endl;
}