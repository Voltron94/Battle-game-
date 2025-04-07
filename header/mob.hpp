#ifndef _MOB_
    #define _MOB_

#include <string>


class Mob   
{
    public:
        Mob() = delete;
        Mob(const std::string& MobName, int health, int attack, int defense, int speed);

    //getter
        std::string getName() {return MobName;}
        int getHealth(){return health;}
        int getMaxHealth(){return maxHealth;}
        int getAttack(){return attack;}
        int getDefense(){return defense;}
        int getSpeed(){return speed;}
     //Nerf / Buff
        int takeDamage(int damage){ health -= damage; return damage;}
        int takeDefenseDamage(int def){ std::cout << MobName << " Defense are Nerf "; defense -= def; defense -= def; return defense;}

    
    protected:
        std::string MobName;
        int health;
        int maxHealth;
        int attack;
        int defense;
        int speed;
};

class Android : public Mob
{
    public:
        Android();

    protected:
        std::string name;
};

class Undead : public Mob
{
    public:
        Undead();

    protected:
        std::string name;

};

class Goblin : public Mob
{
    public:
        Goblin();

    protected:
        std::string name;

};

#endif