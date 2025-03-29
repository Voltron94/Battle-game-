#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <limits>
#include <chrono>
#include <thread>
#include "D:/Code/Code/C++/Projet/battle_game/header/class.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/mob.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/Game.hpp"
#include "D:/Code/Code/C++/Projet/battle_game/header/Battle.hpp"

//=======================================  Demarrage ======================================= 

Game::Game(){}

std::string Game::getPlayerName() 
{ 
    std::string name;
    system("cls");
    std::cout << "Enter your name :" << std::endl; 
    std::getline(std::cin, name);
    std::cout << "Welcome, " << name << "!" << "\n"  << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("cls");
    return name;
}

void Game::card_interface()
{
    std::cout << "=====================================\n";
    std::cout << "           Class Information         \n";
    std::cout << "=====================================\n";

    Berserker tempBerserker("Temp");
    Saber tempSaber("Temp");
    Rider tempRider("Temp");

    std::cout << "\n=== Berserker ===\n";
    tempBerserker.classInfo();

    std::cout << "\n=== Saber ===\n";
    tempSaber.classInfo();

    std::cout << "\n=== Rider ===\n";
    tempRider.classInfo();

    std::cout << "\n=====================================\n";
}

int Game::getPlayerChoice() {
    int choice = 0;
    while (true) {
        std::cout << "Votre choix : ";
        
        // Lecture de l'entree
        if (std::cin >> choice) {
            // Si lecture reussie, on vide le buffer et on retourne
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
        else {
            // Gestion de l'erreur
            std::cin.clear();  // Reinitialise l'etat d'erreur
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Vide le buffer
            std::cout << "Erreur : Veuillez entrer un nombre valide.\n";
        }
    }
}

void Game::Menu()
{
    system("cls");

    std::cout << "\n===================================== "
              << "\n              Game Mode               "
              << "\n===================================== "
              << "\n         Choose your option :         " 
              << "\n\n                                    "
              << "\n 1. 1 Player       2. 2 Player     3. Auto fight   "<<"\n";

    
    int choice = getPlayerChoice();

    switch (choice)
    {
    case 1:
        system("cls");
        modeOne();  
        break;
    case 2:
        system("cls");
        std::cout << "Coming soon" << "\n";
        // std::unique_ptr<Player> player1 = playerCreation("Default", 1);
        // std::unique_ptr<Player> player2 = playerCreation("Default", 2);
        break;
    case 3:
        system("cls");
        std::cout << "Coming soon" << "\n";
        break;
    default:
        throw std::invalid_argument("invalid argument");
        int wait;
        std::cout << "Enter any it touches of your keybord for exit :" ; 
        std::cin >> wait;
        break;
    }
}

void Game::start()     //Menu démarage
{
    int wait;
    std::cout << "\n=====================================        "
              << "\n              Battle Game                    "
              << "\n=====================================        "
              << "\n          Choose your option :               "  
              << "\n\n                                           "
              << "\n  1. Play       2.How to play     3.Option   "<<"\n";

    int choice = getPlayerChoice();

    switch (choice)
    {
    case 1:
        Menu();
        break;
    case 2:
        std::cout << "Coming soon" << "\n";
        break;
    case 3:
        std::cout << "Coming soon" << "\n";
        break;
    default:
        throw std::invalid_argument("invalid argument");
        std::cout << "Enter any it touches of your keybord for exit :" ; 
        std::cin >> wait;
        break;
    }
}


std::unique_ptr<Player> Game::playerCreation(std::string name, int playerNB)
{
    std::cout << "==================================================================================================== \n";
    std::cout << "                                            Battle Game                                              \n";
    std::cout << "====================================================================================================\n"; 
    name = getPlayerName();
    std::cout << name << "are the player" << playerNB << std::endl;
    std::cout << "Card class information: " << "\n";
    card_interface();
    
    std::cout << "Choose your class : " << "\n";
    int choice = getPlayerChoice(); //ERREUR POTENTIELLE
    
    switch(choice)
    {
        case 1:
            std::cout << "Berserker class are chose" << "\n";
            return std::make_unique<Berserker>(name);  
            break;
        case 2:
            std::cout << "Saber class are chose" << "\n";
            return std::make_unique<Saber>(name);
            break;
        case 3:
            std::cout << "Rider class are chose" << "\n";
            return std::make_unique<Rider>(name); 
            break;
        default:
            std::cout << "Invalid choice, defaulting to Saber\n";
            return std::make_unique<Saber>(name);
            break;
    }
}

std::unique_ptr<Mob> Game::ennemyCreation()
{
    std::srand(std::time(0));
    int randomEnnemy  = (std::rand()  % 3) + 1; // range : 1 - 3

    switch (randomEnnemy)
    {
    case 1:
        return std::make_unique<Android>(); //return new Android() //retourne un pointer vers Android
        break;
    case 2:
        return std::make_unique<Undead>();
        break;
    case 3:
        return std::make_unique<Goblin>();
        break;
    default:
        std::cout << "Error, restart in few second" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(4));
        return nullptr;
        break;
    }
    
}

void Game::modeOne()
{
    try {
        std::cout << "Creation du joueur...\n";
        auto player1 = playerCreation("Default", 1);
        
        if (!player1) {
            throw std::runtime_error("Echec de la creation du joueur");
        } else{ 
            std::cout << "Joueur cree avec succès!\n"; 
        }

        std::cout << "Creation de l'ennemi...\n";
        auto mob1 = ennemyCreation();
        
        if (!mob1) {
            throw std::runtime_error("Echec de la creation de l'ennemi");
        }else { 
            std::cout << "Ennemi cree avec succès!\n"; 
        }

        // Verification finale avant creation du combat
        std::cout << "Initialisation du combat...\n";
        Battle battle(std::move(player1), std::move(mob1));
        
        system("cls");
        battle.startOne();
    }
    catch (const std::exception& e) {
        std::cerr << "ERREUR CRITIQUE: " << e.what() << "\n";
        std::cerr << "Le programme va se fermer dans :";
        for(int i = 0; i < 4; i++)
        {
            std::cout << 3 - i << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}