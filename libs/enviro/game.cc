#include <iostream>
#include "libs/utils/colored_output.h"
#include "libs/enviro/game.h"
#include "libs/enviro/maps/hostile_area.h"
#include "libs/enviro/maps/peaceful_area.h"
#include "libs/enviro/commands/command_handlers.h"
#include "libs/enviro/commands/man_page.h"
#include "libs/entities/enemies/weaker_enemies.h"
#include "libs/entities/items/consumables.h"
#include "libs/entities/items/map_keys.h"

// private
void Game::createPlayer(){
    std::cout << "Creating player...\n";
    this->player = new Player("Player", WARRIOR);
    this->player->forceEnter(this->maps[WAITING_AREA]); // land in the waiting area first
    this->player->getCurrentLoc()->displayInfo();
    this->player->getCurrentLoc()->displayDescription();
    this->player->addMoney(500);
    for(int i = 0; i < 5; i++)
        this->player->addToInventory(new SmallHpPotion());
    this->player->addToInventory(new UnknownVillageKey());
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
    int index, secondIndex;
    while(userInput != "exit" && userInput != "end" && userInput != "quit"){
        ColoredOutput::red(this->player->getCurrentLoc()->getName()) << " >> ";
        std::cin >> userInput;
        // [normal] commands
        if(!this->hasGameStarted()){
            if(userInput == "start"){
                startGame(this);
            }else if(userInput == "help"){
                helpBase(this);
            }else if(userInput == "mapdesc"){
                this->player->getCurrentLoc()->displayDescription();
            }
        }else{
            if(userInput == "engage"){
                engage(this);
            }else if(userInput == "wait"){
                gameWait(this);
            }else if(userInput == "enter"){
                std::cin >> index;
                enterLoc(this, index);
            }else if(userInput == "unlock"){
                std::cin >> index;
                std::cin >> secondIndex;
                unlockLoc(this, index, secondIndex);
            }else if(userInput == "use"){
                std::cin >> index;
                useItem(this, index);
            }else if(userInput == "buy"){
                std::cin >> index;
                buyItem(this, index);
            }else if(userInput == "sell"){
                std::cin >> index;
                sellItem(this, index);
            }else if(userInput == "discard"){
                std::cin >> index;
                discardItem(this, index);
            }else if(userInput == "shop"){
                printShopItems(this);
            }else if(userInput == "mapdesc"){
                printMapDescription(this);
            }else if(userInput == "info"){
                this->player->displayPlayerStatus();
                this->player->getCurrentLoc()->displayInfo();
            }else if(userInput == "where"){
                this->player->getCurrentLoc()->displayInfo();
            }else if(userInput == "stat"){
                this->player->displayPlayerStatus();
            }else if(userInput == "inventory"){
                printInventory(this);
            }else if(userInput == "help"){
                helpBase(this);
            }else if(userInput == "man"){
                std::string cmd;
                std::cin >> cmd;
                showManual(cmd);
            }
        }

        if(this->player->isDead()){
            for(int i = 0; i < 10; i++)
                std::cout << ".\n";
            ColoredOutput::red("You are dead. Resetting...\n");
            for(int i = 0; i < 10; i++)
                std::cout << ".\n";
            this->started = false;
            delete this->player;
            this->createPlayer();
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