#include <iostream>
#include <fstream>
#include <sstream>
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
    if(map->unlock(item)){
        this->mapsUnlocked.push_back(item->copy());
        this->deleteItem(item);
    }
}

void Player::forceEnter(GameMap* map){
    this->currentLoc = map;
}

void Player::enter(GameMap* map){
    if(this->currentLoc->canGetTo(map)){
        if(!map->hasComeHereBefore)
            map->displayDescription();
        this->currentLoc = map;
        map->hasComeHereBefore = true;
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

std::vector<GameItem*> Player::getMapsUnlocked(){
    return this->mapsUnlocked;
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

void Player::displaySkills(){
    std::cout << "Displaying skills for class: "; ColoredOutput::green(this->typeStr) << "\n";
    std::vector<CharacterSkill> skills = this->skills;
    for(int i = 0; i < skills.size(); i++){
        ColoredOutput::cyan("~ ~ ~ ~ ~ ~ ~\n");
        std::cout << "Skill "; ColoredOutput::cyan(i) << ":\n";
        std::cout << "Name       : "; ColoredOutput::green(skills[i].name) << "\n";
        std::cout << "Cooldown   : "; ColoredOutput::green(skills[i].cooldown) << "\n";
        std::cout << "Mana needed: "; ColoredOutput::green(skills[i].manaDeduction) << "\n";
        std::cout << "Phy  attack: "; ColoredOutput::green(skills[i].modifier.phyAttack) << "\n";
        std::cout << "Phy  resist: "; ColoredOutput::green(skills[i].modifier.phyResist) << "\n";
        std::cout << "Mag  attack: "; ColoredOutput::green(skills[i].modifier.magAttack) << "\n";
        std::cout << "Mag  resist: "; ColoredOutput::green(skills[i].modifier.magResist) << "\n";
    }
    if(this->onCooldown.size() > 0){
        ColoredOutput::blue("Displaying skills on cooldown:\n");
        for(int i = 0; i < this->onCooldown.size(); i++){
            std::cout << this->skills[this->onCooldown[i]].name << " ("; ColoredOutput::blue(this->onCooldownRoundsLeft[i]) << " rounds left)\n";
        }
    }
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
    std::cout << "Currently equipped item: "; ColoredOutput::green(this->equippedItem->getName()) << "\n";
    StatModiferStore stat = this->baseStat;
    ColoredOutput::blue("Your current statistics:\n");
    this->displayCharacterStatus();
    std::cout << "Current Location: "; ColoredOutput::green(this->currentLoc->getName()) << "\n";
    std::cout << "Is in battle    : "; ColoredOutput::green(this->isInBattle()? "true" : "false") << "\n";
}

Player* Player::load(std::fstream& instream, Game* game){
    std::string in;
    std::string name;
    std::string classType;
    instream >> in;
    if(in == "[player]") // just in case
        instream >> in;
    instream >> name;
    instream >> in; instream >> classType;
    Player* player = new Player(name, std::stoi(classType));
    player->inventory.clear();

    instream >> in;
    if(in == "mapsUnlocked:"){
        instream >> in;
        while(in == "[item]"){
            player->addToInventory(GameItem::load(instream));
            instream >> in;
        }
    }else{
        ColoredOutput::red("Error: ") << "Invalid sequence of properties\n";
    }
    // instream >> in;
    if(in == "inventory:"){
        instream >> in;
        while(in == "[item]"){
            player->addToInventory(GameItem::load(instream));
            instream >> in;
        }
    }else{
        ColoredOutput::red("Error: ") << "Invalid sequence of properties\n";
    }
    // instream >> in;
    if(in == "equippedItem:"){
        instream >> in;
        if(in == "[item]"){
            player->equipItem(GameItem::load(instream));
        }
    }else{
        ColoredOutput::red("Error: ") << "Invalid sequence of properties\n";
    }
    instream >> in;
    if(in == "armor:"){
        instream >> in;
        if(in == "[item]"){
            player->equipItem(GameItem::load(instream));
        }
    }else{
        ColoredOutput::red("Error: ") << "Invalid sequence of properties\n";
    }
    instream >> in; instream >> in; 
    player->money = std::stoi(in);
    instream >> in; instream >> in; 
    player->level = std::stoi(in);
    instream >> in; instream >> in; 
    player->xp = std::stoi(in);
    instream >> in; instream >> in; 
    player->nextLevelXp = std::stoi(in);
    instream >> in;
    player->baseStat = GameItem::importStat(instream);
    instream >> in;
    player->additionalStat = GameItem::importStat(instream);
    instream >> in;
    player->modifierStat = GameItem::importStat(instream);
    instream >> in; instream >> in; 
    player->currentHp = std::stof(in);
    instream >> in; instream >> in; 
    player->maxHp = std::stof(in);
    instream >> in; instream >> in; 
    player->currentMana = std::stof(in);
    instream >> in; instream >> in; 
    player->maxMana = std::stof(in);

    player->forceEnter(game->maps[SPAWN_AREA]);
    return player;
}

std::string Player::exportData(Player* player){
    std::string data = "[player]";
    data += "\nname: " + player->name;
    data += "\ntype: " + std::to_string(player->classType);
    data += "\nmapsUnlocked: \n";
    for(int i = 0; i < player->mapsUnlocked.size(); i++)
        data += GameItem::exportData(player->mapsUnlocked[i]);
    data += "\ninventory: \n";
    for(int i = 0; i < player->inventory.size(); i++)
        data += GameItem::exportData(player->getFromInventory(i));
    data += "\nequippedItem: \n" + GameItem::exportData(player->equippedItem);
    data += "\narmor: \n" + (player->armor? GameItem::exportData(player->armor) : "null");
    data += "\nmoney: " + std::to_string(player->money);
    data += "\nlevel: " + std::to_string(player->level);
    data += "\nxp: " + std::to_string(player->xp);
    data += "\nnextLevelXp: " + std::to_string(player->nextLevelXp);
    data += "\nbaseStat: " + GameItem::exportStat(player->baseStat);
    data += "\nadditionalStat: " + GameItem::exportStat(player->additionalStat);
    data += "\nmodifierStat: " + GameItem::exportStat(player->modifierStat);
    data += "\ncurrentHp: " + std::to_string(player->currentHp);
    data += "\nmaxHp: " + std::to_string(player->maxHp);
    data += "\ncurrentMana: " + std::to_string(player->currentMana);
    data += "\nmaxMana: " + std::to_string(player->maxMana);
    data += "\n";
    return data;
}