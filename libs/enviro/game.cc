#include <iostream>
#include "libs/enviro/game.h"
#include "libs/enviro/maps/hostile_area.h"
#include "libs/enviro/maps/peaceful_area.h"
#include "libs/entities/enemies/weaker_enemies.h"
#include "libs/enviro/commands/command_handlers.h"

// private
void Game::createPlayer(){
    std::cout << "Creating player...\n";
    this->player = new Player("Player", WARRIOR);
    this->player->enter(this->maps[WAITING_AREA]); // land in the waiting area first
    this->player->getCurrentLoc()->displayInfo();
}

void Game::setupMaps(){
    std::cout << "Setting up maps...\n";
    WaitingArea* waitingArea = new WaitingArea(this->difficulty);
    SpawnArea* spawnArea = new SpawnArea(this->difficulty);
    UnknownVillage* unknownVillage = new UnknownVillage(this->difficulty);

    // add the area according to the sequence in game.h
    this->maps.push_back(waitingArea);
    this->maps.push_back(spawnArea);
    this->maps.push_back(unknownVillage);
}

// public
Game::Game(int difficulty){
    this->difficulty = difficulty;
}

void Game::start(){
    this->setupMaps();
    this->createPlayer();

    std::cout << "Game is ready, type 'help' to get a list of available commands\n";
    std::string userInput;
    while(userInput != "exit" && userInput != "end"){
        std::cout << this->player->getCurrentLoc()->getName() << " >> ";
        std::cin >> userInput;
        if(userInput == "start"){
            startGame(this);
        }else if(userInput == "battle"){
            battle(this);
        }else if(userInput == "engage"){
            engage(this);
        }else if(userInput == "wait"){
            gameWait(this);
        }else if(userInput == "info"){
            printInfo(this);
        }else if(userInput == "help"){
            helpBase(this);
        }
    }
}

void Game::exitGame(){
    exit(0);
}

void Game::updateMaps(){
    for(int i = 0; i < this->maps.size(); i++){
        this->maps[i]->update();
    }
}

void Game::save(){

}

void Game::load(){

}