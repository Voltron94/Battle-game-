#ifndef _PLAYER_
    #define _PLAYER_

#include <string>
#include <memory>


class Player
{
    public:
        Player() = delete;
        Player(const std::string& name, int health, int attack, int defense,int speed, const std::string& playerClass);
        virtual void classInfo();

    //Condition
        // bool playTurn(bool turn){ return turn;}  //For versus mode

    //getter
        std::string getName() {return name;}
        int getHealth(){return health;}
        int getMaxHealth(){return maxHealth;}
        int getAttack(){return attack;}
        int getDefense(){return defense;}
        int getSpeed(){return speed;}
        std::string getPlayerClass(){return playerClass;}

        //Nerf effect
        // int takeDefenseDamage(int def){ std::cout <<  "Defense are Nerf "; defense -= def; return defense;}
        int takeDamage(int damage);

        virtual void buffSkill(int choice);
        virtual void buffSkillList();

    protected:
    //Stats
        std::string name;
        int health;
        int maxHealth;
        int attack;
        int defense;
        int speed;
        std::string playerClass;

        //30 % buff protection
        bool protectionBuff;
        //Limit buff skill
        int oneUselimit = 0; //Default 0
        int twoUselimit = 0;
        int threeUselimit = 0;
};


class Berserker : public Player
{
    public:
        Berserker() = delete;
        Berserker(const std::string& _name);

        void classInfo() override;
        void buffSkill(int choice ) override;
        void buffSkillList() override;
};

class Saber : public Player
{
    public:
        Saber() = delete;
        Saber(const std::string& _name);

        void classInfo() override;
        void buffSkill(int choice) override;
        void buffSkillList() override;
};

class Rider : public Player
{
    public:
        Rider() = delete;
        Rider(const std::string& _name);

        void classInfo() override;
        void buffSkill(int choice) override;
        void buffSkillList() override;
};

//  Class Card




#endif