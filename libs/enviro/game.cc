#include <iostream>
#include "libs/enviro/game.h"
#include "libs/enviro/maps/hostile_area.h"
#include "libs/enviro/maps/peaceful_area.h"
#include "libs/entities/enemies/weaker_enemies.h"
#include "libs/entities/items/consumables.h"
#include "libs/enviro/commands/command_handlers.h"

// private
void Game::createPlayer(){
    std::cout << "Creating player...\n";
    this->player = new Player("Player", WARRIOR);
    this->player->enter(this->maps[WAITING_AREA]); // land in the waiting area first
    this->player->getCurrentLoc()->displayInfo();
    this->player->addMoney(500);
    for(int i = 0; i < 5; i++)
        this->player->addToInventory(new SmallHpPotion());
}

void Game::setupMaps(){
    std::cout << "Setting up maps...\n";

    // Peaceful maps
    WaitingArea* waitingArea = new WaitingArea(this->difficulty);
    SpawnArea* spawnArea = new SpawnArea(this->difficulty);
    ConsumableShop* consumableShop = new ConsumableShop(this->difficulty);
    WeaponShop* weaponShop = new WeaponShop(this->difficulty);
    ArmorShop* armorShop = new ArmorShop(this->difficulty);

    // Hostile maps
    UnknownVillage* unknownVillage = new UnknownVillage(this->difficulty);
    LostWoods* lostWoods = new LostWoods(this->difficulty);
    DawnDungeon* dawnDungeon = new DawnDungeon(this->difficulty);

    // Boss maps
    Castle_F1* castle_F1 = new Castle_F1(this->difficulty);
    Castle_F2* castle_F2 = new Castle_F2(this->difficulty);

    // Connections
    spawnArea->connectTo(unknownVillage);
    spawnArea->connectTo(consumableShop);
    spawnArea->connectTo(weaponShop);
    spawnArea->connectTo(armorShop);

    unknownVillage->connectTo(lostWoods);
    unknownVillage->connectTo(dawnDungeon);
    dawnDungeon->connectTo(castle_F1);
    castle_F1->connectTo(castle_F2);

    this->maps.push_back(waitingArea);
    this->maps.push_back(spawnArea);
    this->maps.push_back(consumableShop);
    this->maps.push_back(weaponShop);
    this->maps.push_back(armorShop);
    this->maps.push_back(unknownVillage);
    this->maps.push_back(lostWoods);
    this->maps.push_back(dawnDungeon);
    this->maps.push_back(castle_F1);
    this->maps.push_back(castle_F2);
}

// public
Game::Game(int difficulty){
    this->difficulty = difficulty;
}

bool Game::hasGameStarted(){
    return this->started;
}

void Game::gameStarted(){
    this->started = true;
}

void Game::start(){
    this->setupMaps();
    this->createPlayer();

    std::cout << "Game is ready, type 'help' to get a list of available commands\n";
    std::string userInput;
    int index;
    while(userInput != "exit" && userInput != "end" && userInput != "quit"){
        std::cout << this->player->getCurrentLoc()->getName() << " >> ";
        std::cin >> userInput;
        // [normal] commands
        if(!this->hasGameStarted()){
            if(userInput == "start"){
                startGame(this);
            }else if(userInput == "help"){
                helpBase(this);
            }
        }else{
            if(userInput == "enter"){
                std::cin >> index;
                enterLoc(this, index);
            }else if(userInput == "engage"){
                engage(this);
            }else if(userInput == "wait"){
                gameWait(this);
            }else if(userInput == "use"){
                std::cin >> index;
                useItem(this, index);
            }else if(userInput == "buy"){
                std::cin >> index;
                buyItem(this, index);
            }else if(userInput == "sell"){
                std::cin >> index;
                sellItem(this, index);
            }else if(userInput == "shop"){
                printShopItems(this);
            }else if(userInput == "info"){
                printInfo(this);
            }else if(userInput == "inventory"){
                printInventory(this);
            }else if(userInput == "help"){
                helpBase(this);
            }
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