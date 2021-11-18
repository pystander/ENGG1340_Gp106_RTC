#include "libs/enviro/game_map.h"
#include "libs/enviro/game.h"
#include "libs/utils/colored_output.h"

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
    this->difficulty = difficulty;
}

void GameMap::connectTo(GameMap* nextMap){
    this->neighbors.insert(nextMap);
    nextMap->neighbors.insert(this);
}

bool GameMap::canGetTo(GameMap* nextLoc){
    if(this->neighbors.count(nextLoc) && !nextLoc->isLocked()){
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

bool GameMap::isLocked(){
    return this->locked;
}

void GameMap::lock(){
    this->locked = true;
}

void GameMap::unlock(GameItem* key){
    if(!this->isLocked()){
        ColoredOutput::green(this->getName()) << " is already unlocked\n";
        return;
    }
    if((key->getItemCategory() & ITEM_KEY) &&  key->getName() == this->keyName){
        this->locked = false;
        std::cout << "Unlocked new map: "; ColoredOutput::green(this->getName()) << " with item "; ColoredOutput::green(key->getName()) << "\n";
    }else{
        std::cout << "Cannot unlock map: "; ColoredOutput::green(this->getName()) << " with item "; ColoredOutput::green(key->getName()) << "\n";
    }
}

int GameMap::getDifficulty(){
    return this->difficulty;
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
            std::cout << "You bought "; ColoredOutput::green(itemBeBought->getName()) << " for "; ColoredOutput::green(itemBeBought->getValueMoney()) << "\n";
        }else{
            std::cout << "You do not have enough money to buy "; ColoredOutput::green(itemBeBought->getName()) << "\n";
        }
    }else{
        std::cout << "Cannot buy item with index: "; ColoredOutput::green(index) << "\n";
    }
}

void GameMap::sellItem(GameCharacter* seller, int index){
    GameItem* item = seller->getFromInventory(index);
    if(item != nullptr){
        if(item->canSell()){
            if(this->shopType == SHOP_WEAPON && item->getItemCategory() != WEAPON){
                std::cout << "You need to sell weapons at a "; ColoredOutput::blue("Weapon Shop") << "\n";
                return;
            }else if(this->shopType == SHOP_ARMOR && item->getItemCategory() != ARMOR){
                std::cout << "You need to sell armors at an "; ColoredOutput::blue("Armor Shop") << "\n";
                return;
            }else if(this->shopType == SHOP_CONSUMABLES && item->getItemCategory() != CONSUMABLE){
                std::cout << "You need to sell consumables at a "; ColoredOutput::blue("Consumable Shop") << "\n";
                return;
            }
            seller->addMoney(item->getValueMoney());
            seller->deleteItem(item);
            std::cout << "You sold "; ColoredOutput::green(item->getName()) << " for " << item->getValueMoney() << "\n";
        }else{
            std::cout << "You cannot sell "; ColoredOutput::green(item->getName()) << "\n";
        }
    }else{
        std::cout << "Cannot sell item with index: "; ColoredOutput::green(index) << "\n";
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
    ColoredOutput::blue("Showing map info:\n");
    std::cout << "Map name: "; ColoredOutput::green(this->name); std::cout << "\n";
    if(this->shopType & SHOP_ARMOR){
        std::cout << "Shop type: Armor shop\n";
    }else if(this->shopType & SHOP_WEAPON){
        std::cout << "Shop type: Weapon shop\n";
    }else if(this->shopType & SHOP_CONSUMABLES)
        std::cout << "Shop type: Consumable shop\n";
    if(this->enemies.size() > 0)
        ColoredOutput::blue("Showing present mobs:\n");
    for(int i = 0; i < this->enemies.size(); i++){
        GameCharacter* c = this->enemies[i];
        std::cout << "Mob "; ColoredOutput::cyan(i) << ": "; ColoredOutput::green(c->getName()) << "\n";
    }
    this->displayNeighbors();
}

void GameMap::displayNeighbors(){
    if(this->neighbors.size() > 0){
        ColoredOutput::blue("Neighbor locations for " + this->getName() + ":\n");
    }
    int i = 0;
    for(const auto& place: this->neighbors){
        if(place->isLocked()){
            std::cout << "Neighbor "; ColoredOutput::cyan(i++) << ": "; ColoredOutput::green(place->getName()) << " ("; ColoredOutput::red("locked") << ")\n";
        }else{
            std::cout << "Neighbor "; ColoredOutput::cyan(i++) << ": "; ColoredOutput::green(place->getName()) << "\n";
        }
    }
}

void GameMap::displayShopItems(){
    if(this->shopType & NOT_SHOP){
        ColoredOutput::red("You are not in a shop currently\n");
        return;
    }
    ColoredOutput::blue("Shop items available:\n");
    for(int i = 0; i < this->itemsOnSold.size(); i++){
        ColoredOutput::cyan("------------------------\n");
        std::cout << "Item "; ColoredOutput::cyan(i) << ":\n";
        this->itemsOnSold[i]->displayInfo();
    }
}

void GameMap::displayDescription(){
    std::cout << this->description << "\n";
}