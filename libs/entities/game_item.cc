#include <iostream>
#include <string>
#include "libs/entities/game_item.h"

std::string GameItem::getName(){
    return this->name;
}

int GameItem::getType(){
    return this->type;
}

int GameItem::getMiscType(){
    return this->miscType;
}

StatModiferStore GameItem::getItemStat(){
    return this->itemStat;
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
    if(flags & MISC)
        std::cout << "Miscellaneous";
    std::cout << "], Misc type: [";
    int miscType = this->miscType;
    if(miscType & MISC_QUEST){
        std::cout << "Quest,";
    }
    if(miscType & MISC_KEY){
        std::cout << "Key";
    }
    std::cout << "], Item statistics:\n";

    StatModiferStore stat = this->itemStat;
    std::cout << "Heal     Amount: " << stat.healAmount << "\n";
    std::cout << "Physical Attack: " << stat.phyAttack << "\n";
    std::cout << "Physical Resist: " << stat.phyResist << "\n";
    std::cout << "Magical  Attack: " << stat.magAttack << "\n";
    std::cout << "Magical  Resist: " << stat.magResist << "\n";
    std::cout << "Stuns          : " << (stat.stun? "true" : "false") << "\n";
}