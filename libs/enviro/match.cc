#include <iostream>
#include <vector>
#include "libs/enviro/match.h"
#include "libs/entities/character.h"
#include "libs/utils/colored_output.h"

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

void GameMatch::attackEnemy(GameCharacter* from, int index){
    if(this->playerAttackLeft > 0){
        if(index >= 0 && index < this->enemies.size()){
            from->attack(this->enemies[index]);
            this->playerAttackLeft--;

            this->cleanCorpse();
            if(this->enemiesLeft() == 0){
                ColoredOutput::blue("No more enemies left. When you are done, type 'next' to exit the battle.\n");
            }
        }
    }else{
        ColoredOutput::green(from->getName()) << " cannot keep attacking. Please use 'next', to end the round\n";
    }
}

void GameMatch::endTurn(){
    Random rng = Random(0, this->enemies.size());
    this->cleanCorpse();
    if(this->enemiesLeft() == 0){
        this->end();
    }else{
        this->playerAttackLeft = this->maxAttackPerRound;
        this->enemies[rng.getInt()]->attack(this->player);
    }

    // reset skills modifier / strength potion modifier
    this->player->manaRegen();
    this->player->resetModifier();
    this->player->updateCooldownSkills();
    for(int i = 0; i < this->enemies.size(); i++){
        this->enemies[i]->manaRegen();
        this->enemies[i]->resetModifier();
        this->enemies[i]->updateCooldownSkills();
    }
    
}

void GameMatch::cleanCorpse(){
    std::vector<GameCharacter*> cleaned;
    for(int i = 0; i < this->enemies.size(); i++){
        GameCharacter* enemy = this->enemies[i];
        if(!enemy->isDead()){
            cleaned.push_back(enemy);
        }else{
            std::vector<GameItem*> lootsDropped = enemy->dropRandomLoots();
            for(int j = 0; j < lootsDropped.size(); j++){
                this->loots.push_back(lootsDropped[j]);
            }
        }
    }
    this->enemies = cleaned;
}

void GameMatch::end(){
    if(!this->finished){
        ColoredOutput::blue("Battle ended, leaving battlefield\n");
        for(int i = 0; i < this->enemies.size(); i++){
            this->enemies[i]->restore();
        }
        this->finished = true;
        this->player->disengage();
    }
}

void GameMatch::loot(GameCharacter* player, int index){
    if(index >= 0 && index < this->loots.size()){
        player->addToInventory(this->loots[index]);
        std::cout << "Added item "; ColoredOutput::blue(this->loots[index]->getName()) << " to your inventory\n";
        //remove item from vector
        this->loots.erase(this->loots.begin() + index);
    }else{
        std::cout << "Cannot loot item of index: "; ColoredOutput::red(index) << "\n";
    }
}

void GameMatch::lootAll(GameCharacter* player){
    for(int i = this->loots.size()-1; i >= 0; i--){
        this->loot(player, i);
    }
}

void GameMatch::displayLoots(){
    if(this->loots.size() > 0){
        ColoredOutput::blue("Loots available:\n");
    }else{
        ColoredOutput::blue("No loots available\n");
    }
    for(int i = 0; i < this->loots.size(); i++){
        ColoredOutput::cyan("~ ~ ~ ~ ~ ~ ~\n");
        std::cout << "Item "; ColoredOutput::cyan(i) << ": \n";
        this->loots[i]->displaySimpleInfo();
    }
}

void GameMatch::displayInfo(){
    this->displayLoots();
    
    if(enemies.size() > 0){
        ColoredOutput::blue("Enemies remaining:\n");
    }else
        ColoredOutput::red("No more enemies in the match\n");
    for(int i = 0; i < enemies.size(); i++){
        ColoredOutput::cyan("~ ~ ~ ~ ~ ~ ~\n");
        std::cout << "Enemy "; ColoredOutput::cyan(i) << ": \n";
        enemies[i]->displayCharacterStatus();
    }
}