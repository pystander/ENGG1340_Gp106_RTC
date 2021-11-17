#include <iostream>
#include <string>
#include "libs/entities/player.h"
#include "libs/enviro/game.h"
#include "libs/enviro/match.h"
#include "libs/enviro/game_map.h"
#include "libs/utils/colored_output.h"

GameMap* Player::getCurrentLoc(){
    return this->currentLoc;
}

bool Player::isInBattle(){
    return this->enteredBattle;
}

void Player::unlockMap(GameMap* map, GameItem* item){
    map->unlock(item);
}

void Player::forceEnter(GameMap* map){
    this->currentLoc = map;
}

void Player::enter(GameMap* map){
    if(this->currentLoc->canGetTo(map)){
        this->currentLoc = map;
        if(this->currentLoc->getDifficulty() != DIFFICULTY_EASY){
            // 0.1 of chance getting into a battle randomly
            Random rng = Random(0, 1);
            if(rng.getFloat() < 0.1){
                std::cout << "Enemies intercepts you on your way to "; ColoredOutput::blue(map->getName()) << "!\n";
                this->engage();
            }
        }
    }else if(map->isLocked()){
        ColoredOutput::blue(map->getName()) << " is locked. Use '"; ColoredOutput::blue("unlock") << "' command to unlock it with a key\n";
    }else{
        std::cout << "Cannot get to "; ColoredOutput::green(map->getName()) << "\n";
    }
}

GameMatch* Player::engage(){
    delete this->recentMatch;
    GameMatch* match = new GameMatch(this, this->currentLoc);
    this->recentMatch = match;
    this->enteredBattle = true;
    return match;
}

void Player::disengage(){
    this->currentLoc->cleanCorpse();
    this->recentMatch = nullptr;
    this->enteredBattle = false;
}

GameMatch* Player::getRecentMatch(){
    return this->recentMatch;
}

void Player::buyItem(int index){
    GameMap* currentLoc = this->getCurrentLoc();
    if(currentLoc->getShopType() & NOT_SHOP){
        std::cout << "You are not in a shop\n";
    }else{
        currentLoc->buyItem(this, index);
    }
}

void Player::sellItem(int index){
    GameMap* currentLoc = this->getCurrentLoc();
    if(currentLoc->getShopType() & NOT_SHOP){
        std::cout << "You are not in a shop\n";
    }else{
        currentLoc->sellItem(this, index);
    }
}

std::vector<GameItem*> Player::dropRandomLoots(){
    return std::vector<GameItem*>();
}

void Player::displayInventory(){
    std::cout << "Currently equipped item: "; ColoredOutput::green(this->equippedItem->getName()) << "\n";
    std::vector<GameItem*> inv = this->inventory;
    if(inv.size() > 0)
        ColoredOutput::blue("Your current inventory:\n");
    for(int i = 0; i < inv.size(); i++){
        ColoredOutput::cyan("~~~~~~~~~~~~~\n");
        std::cout << "Item "; ColoredOutput::cyan(i) << ":\n";
        inv[i]->displayInfo();
    }
}

void Player::displayPlayerStatus(){
    StatModiferStore stat = this->baseStat;
    ColoredOutput::blue("Your current statistics:\n");
    this->displayCharacterStatus();
    std::cout << "Current Location: "; ColoredOutput::green(this->currentLoc->getName()) << "\n";
    std::cout << "Is in battle    : "; ColoredOutput::green(this->isInBattle()? "true" : "false") << "\n";
}