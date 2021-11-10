#include <iostream>
#include <string>
#include "libs/entities/game_item.h"

int GLOBAL_ID = 0;

int GameItem::getId(){
    return this->id;
}

std::string GameItem::getName(){
    return this->name;
}

bool GameItem::canSell(){
    return this->can_sell;
}

int GameItem::getType(){
    return this->type;
}

int GameItem::getItemCategory(){
    return this->details;
}

int GameItem::getValueMoney(){
    return this->valueMoney;
}

StatModiferStore GameItem::getItemStat(){
    return this->itemStat;
}

void GameItem::displaySimpleInfo(){
    std::cout << "Name: " << name << "\n";
    std::cout << "Item statistics:\n";
    this->showStatisticsOnly();
}

void GameItem::displayInfo(){
    std::cout << "Name: " << name << ", Type: [";
    int flags = this->type;
    if(flags & PHY_ATTACK)
        std::cout << "PHY Damage,";
    if(flags & PHY_RESIST)
        std::cout << "PHY Resist,";
    if(flags & MAG_ATTACK)
        std::cout << "MAG Damage,";
    if(flags & MAG_RESIST)
        std::cout << "MAG Resist,";
    if(flags & HEALING)
        std::cout << "Healing,";
    if(flags & STUN)
        std::cout << "Stuns,";
    std::cout << "], Item details: [";
    int details = this->details;
    if(details & ITEM_QUEST)
        std::cout << "Quest,";
    if(details & ITEM_KEY)
        std::cout << "Key";
    if(details & WEAPON)
        std::cout << "Weapon";
    if(details & CONSUMABLE)
        std::cout << "Consumable";
    if(details & ARMOR)
        std::cout << "Armor";
    std::cout << "], Item statistics:\n";
    this->showStatisticsOnly();
}

void GameItem::showStatisticsOnly(){
    StatModiferStore stat = this->itemStat;
    int details = this->details;
    if(details & CONSUMABLE){
        std::cout << "Item Value          : " << this->valueMoney << "\n";
        std::cout << "Heal     Amount     : " << stat.healAmount << "\n";
        std::cout << "Physical Attack (by): " << stat.phyAttack << "\n";
        std::cout << "Physical Resist (by): " << stat.phyResist << "\n";
        std::cout << "Magical  Attack (by): " << stat.magAttack << "\n";
        std::cout << "Magical  Resist (by): " << stat.magResist << "\n";
        std::cout << "Stuns               : " << (stat.stun? "true" : "false") << "\n";
    }else{
        std::cout << "Item Value          : " << this->valueMoney << "\n";
        std::cout << "Heal     Amount: " << stat.healAmount << "\n";
        std::cout << "Physical Attack: " << stat.phyAttack << "\n";
        std::cout << "Physical Resist: " << stat.phyResist << "\n";
        std::cout << "Magical  Attack: " << stat.magAttack << "\n";
        std::cout << "Magical  Resist: " << stat.magResist << "\n";
        std::cout << "Stuns          : " << (stat.stun? "true" : "false") << "\n";
    }
}