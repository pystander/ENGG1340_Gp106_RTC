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
        if(i == index)
            return place;
    }
    return nullptr;
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