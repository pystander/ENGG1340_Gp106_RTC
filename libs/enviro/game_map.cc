#include "libs/enviro/game_map.h"
#include "libs/enviro/game.h"

#include <iostream>
#include <string>

GameMap::GameMap(std::string name, int difficulty) : name(name){
    if(difficulty == DIFFICULTY_EASY){
        maxEnemyReserve = 5;
        enemySpawnRate = 0.5;
    }else if(difficulty == DIFFICULTY_NORMAL){
        maxEnemyReserve = 10;
        enemySpawnRate = 0.55;
    }else if(difficulty == DIFFICULTY_HARD){
        maxEnemyReserve = 15;
        enemySpawnRate = 0.6;
    }
}

void GameMap::connectTo(GameMap* nextMap){
    this->neighbors.insert(nextMap);
    nextMap->neighbors.insert(this);
}

bool GameMap::canGetTo(GameMap* nextLoc){
    if(this->neighbors.count(nextLoc)){
        return true;
    }
    return false;
}

std::string GameMap::getName(){
    return this->name;
}

std::vector<GameCharacter*> GameMap::getSomeEnemies(){
    std::vector<GameCharacter*> result;
    if(this->enemies.size() == 0) 
        return result;
    // 3 at most
    Random rng = Random(1, this->enemies.size() > 3? 3 : this->enemies.size());
    for(int i = 0; i < rng.getInt(); i++){
        result.push_back(this->enemies[i]);
    }
    return result;
}

std::set<GameMap*> GameMap::getNeighbors(){
    return this->neighbors;
}

GameMap* GameMap::getNeighborByIndex(int index){
    int i = 0;
    for(const auto& place: this->neighbors){
        if(i++ == index)
            return place;
    }
    return nullptr;
}

int GameMap::getShopType(){
    return this->shopType;
}

void GameMap::buyItem(GameCharacter* buyer, int index){
    if(index >= 0 && index < this->itemsOnSold.size()){
        GameItem* itemBeBought = this->itemsOnSold[index];
        if(buyer->getMoneyAmount() >= itemBeBought->getValueMoney()){
            buyer->subMoney(itemBeBought->getValueMoney());
            buyer->addToInventory(itemBeBought->copy());
            std::cout << "You bought " << itemBeBought->getName() << " for " << itemBeBought->getValueMoney() << "\n";
        }else
            std::cout << "You do not have enough money to buy " << itemBeBought->getName() << "\n";
    }else{
        std::cout << "Cannot buy item with index: " << index << "\n";
    }
}

void GameMap::sellItem(GameCharacter* seller, int index){
    GameItem* item = seller->getFromInventory(index);
    if(item != nullptr){
        if(item->canSell()){
            seller->addMoney(item->getValueMoney());
            seller->deleteItem(item);
            std::cout << "You sold " << item->getName() << " for " << item->getValueMoney() << "\n";
        }else
            std::cout << "You cannot sell " << item->getName() << "\n";
    }else{
        std::cout << "Cannot sell item with index: " << index << "\n";
    }
}

void GameMap::setEnemySpawnRate(double spawnRate){
    this->enemySpawnRate = spawnRate;
}

void GameMap::update(){
    Random rng = Random(0, 1);
    if(rng.getFloat() < this->enemySpawnRate){
        if(this->enemies.size() < this->maxEnemyReserve){
            // Some maps do not have mobs
            GameCharacter* character = this->spawnRandomMobs();
            if(character)
                this->enemies.push_back(character);
        }
    }
}

void GameMap::cleanCorpse(){
    std::vector<GameCharacter*> cleaned;
    for(int i = 0; i < this->enemies.size(); i++){
        if(!this->enemies[i]->isDead()){
            cleaned.push_back(this->enemies[i]);
        }
    }
    this->enemies = cleaned;
}

void GameMap::displayInfo(){
    std::cout << "Map name: " << this->name << "\n";
    if(this->shopType & SHOP_ARMOR){
        std::cout << "Shop type: Armor shop\n";
    }else if(this->shopType & SHOP_WEAPON){
        std::cout << "Shop type: Weapon shop\n";
    }else if(this->shopType & SHOP_CONSUMABLES)
        std::cout << "Shop type: Consumable shop\n";
    if(this->enemies.size() > 0)
        std::cout << "Showing present mobs:\n";
    for(int i = 0; i < this->enemies.size(); i++){
        GameCharacter* c = this->enemies[i];
        std::cout << "Mob " << i << ": " << c->getName() << "\n";
    }
    this->displayNeighbors();
}

void GameMap::displayNeighbors(){
    std::cout << "Neighbor locations for " << this->getName() << ":\n";
    int i = 0;
    for(const auto& place: this->neighbors){
        std::cout << "Neighbor " << i++ << ": " << place->getName() << "\n";
    }
}

void GameMap::displayShopItems(){
    if(this->shopType & NOT_SHOP){
        std::cout << "You are not in a shop currently\n";
        return;
    }
    std::cout << "Shop items available:\n";
    for(int i = 0; i < this->itemsOnSold.size(); i++){
        std::cout << "------------------------\n";
        std::cout << "Item " << i << ":\n";
        this->itemsOnSold[i]->displayInfo();
    }
}