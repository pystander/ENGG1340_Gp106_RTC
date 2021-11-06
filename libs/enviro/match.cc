#include <iostream>
#include "libs/enviro/match.h"

int GameMatch::enemiesLeft(){
    return this->enemies.size();
}

bool GameMatch::start(){
    this->enemies = map->getSomeEnemies();
    if(this->enemies.size() == 0){
        this->end();
        return false;
    }
    return true;
}

void GameMatch::attack(GameCharacter* from, int index){
    if(index >= 0 && index < this->enemies.size()){
        from->attack(this->enemies[index]);
        //better output can be made, eg. difference?
    }
}

void GameMatch::endTurn(){
    Random rng = Random(0, this->enemies.size());
    this->enemies[rng.getInt()]->attack(this->player);
    this->cleanCorpse();
    if(this->enemiesLeft() == 0){
        this->end();
        // TODO: drop loots for players to get
    }
}

void GameMatch::cleanCorpse(){
    std::vector<GameCharacter*> cleaned;
    for(int i = 0; i < this->enemies.size(); i++){
        if(!this->enemies[i]->isDead()){
            cleaned.push_back(this->enemies[i]);
        }
    }
    this->enemies = cleaned;
}

void GameMatch::end(){
    this->player->disengage();
    this->finished = true;
}

void GameMatch::displayInfo(){
    for(int i = 0; i < enemies.size(); i++){
        std::cout << "Enemy " << i << ": \n";
        enemies[i]->displayCharacterStatus();
    }
}