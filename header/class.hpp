#ifndef _CLASS_
    #define _CLASS_

#include <string>
#include <memory>


class Player
{
    public:
        Player() = delete;
        Player(const std::string& name, int health, int attack, int defense,int speed, const std::string& playerClass);
        virtual void classInfo();

    //Condition
        bool playTurn(bool turn){ return turn;}  //For versus mode

    //getter
        std::string getName() {return name;}
        int getHealth(){return health;}
        int getMaxHealth(){return maxHealth;}
        int getAttack(){return attack;}
        int getDefense(){return defense;}
        int getSpeed(){return speed;}
        std::string getPlayerClass(){return playerClass;}

        void takeDamage(int damage){ health -= damage;}

    protected:
        std::string name;
        int health;
        int maxHealth;
        int attack;
        int defense;
        int speed;
        std::string playerClass;
        bool turn = false;
};


class Berserker : public Player
{
    public:
        Berserker() = delete;
        Berserker(const std::string& _name);

        void classInfo() override;
};

class Saber : public Player
{
    public:
        Saber() = delete;
        Saber(const std::string& _name);

        void classInfo() override;
};

class Rider : public Player
{
    public:
        Rider() = delete;
        Rider(const std::string& _name);

        void classInfo() override;

};

//  Class Card




#endif