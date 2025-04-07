#include <iostream>
#include <memory>
#include "D:/Code/Code/C++/Projet/battle_game/header/player.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/game.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/Mob.hpp"

Mob::Mob(const std::string& _name, int _health, int _attack, int _defense,int _speed)
: MobName(_name), health(_health), maxHealth(_health), attack(_attack), defense(_defense), speed(_speed){
}

Android::Android() : Mob("Android", 180, 70, 80, 30){}
Undead::Undead() : Mob("Undead", 200, 60, 60, 50){}
Goblin::Goblin() : Mob("Goblin", 140, 65, 40, 90) {}
