#include <iostream>
#include <string>
#include "libs/entities/player.h"
#include "libs/enviro/match.h"
#include "libs/enviro/game_map.h"

GameMap* Player::getCurrentLoc(){
    return this->currentLoc;
}

bool Player::isInBattle(){
    return this->enteredBattle;
}

void Player::enter(GameMap* map){
    if(this->currentLoc == nullptr || this->currentLoc->getName() == "Waiting Area"){
        this->currentLoc = map;
    }else{
        if(this->currentLoc->canGetTo(map)){
            this->currentLoc = map;
            // 0.4 of chance getting into a battle randomly on your way
            // Random rng = Random(0, 1);
            // if(rng.getFloat() < 0.4){
            //     this->engage();
            // }
        }else{
            std::cout << "Cannot get to " << map->getName() << "\n";
        }
    }
}

GameMatch* Player::engage(){
    free(this->recentMatch);
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

void Player::displayInventory(){
    std::cout << "Currently equipped item: " << this->equippedItem->getName() << "\n";
    std::vector<GameItem*> inv = this->inventory;
    if(inv.size() > 0)
        std::cout << "Your current inventory:\n";
    for(int i = 0; i < inv.size(); i++){
        std::cout << "~~~~~~~~~~~~~\n";
        std::cout << "Item " << i << ":\n";
        inv[i]->displayInfo();
        std::cout << "~~~~~~~~~~~~~\n";
    }
}

void Player::displayPlayerStatus(){
    StatModiferStore stat = this->baseStat;
    std::cout << "Your current statistics:\n";
    this->displayCharacterStatus();
    std::cout << "Current Location: " << this->currentLoc->getName() << "\n";
    std::cout << "Is in battle    : " << (this->isInBattle()? "true" : "false") << "\n";
}