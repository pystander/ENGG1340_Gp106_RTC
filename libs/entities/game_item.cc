#include <iostream>
#include <string>
#include "libs/entities/game_item.h"
#include "libs/utils/colored_output.h"

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
    std::cout << "Name: "; ColoredOutput::green(this->name) << "\n";
    ColoredOutput::red("Item statistics:\n");
    this->showStatisticsOnly();
}

void GameItem::displayInfo(){
    std::cout << "Name: "; ColoredOutput::green(this->name) << ", Type: [";
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
        std::cout << "Key,";
    if(details & WEAPON)
        std::cout << "Weapon,";
    if(details & CONSUMABLE)
        std::cout << "Consumable,";
    if(details & ARMOR)
        std::cout << "Armor,";
    std::cout << "], Item statistics:\n";
    this->showStatisticsOnly();
}

void GameItem::showStatisticsOnly(){
    StatModiferStore stat = this->itemStat;
    int details = this->details;
    if(details & CONSUMABLE){
        std::cout << "Item Value          : $"; ColoredOutput::greenStart() << this->valueMoney << "\n"; ColoredOutput::reset();
        std::cout << "Heal     Amount     : " ; ColoredOutput::greenStart() << stat.healAmount << "\n"; ColoredOutput::reset();
        std::cout << "Physical Attack (by): " ; ColoredOutput::greenStart() << stat.phyAttack << "\n"; ColoredOutput::reset();
        std::cout << "Physical Resist (by): " ; ColoredOutput::greenStart() << stat.phyResist << "\n"; ColoredOutput::reset();
        std::cout << "Magical  Attack (by): " ; ColoredOutput::greenStart() << stat.magAttack << "\n"; ColoredOutput::reset();
        std::cout << "Magical  Resist (by): " ; ColoredOutput::greenStart() << stat.magResist << "\n"; ColoredOutput::reset();
        std::cout << "Stuns               : " ; ColoredOutput::greenStart() << (stat.stun? "true" : "false") << "\n"; ColoredOutput::reset();
        std::cout << "Sellable            : " ; ColoredOutput::greenStart() << (this->can_sell? "true" : "false") << "\n"; ColoredOutput::reset();
    }else{
        std::cout << "Item Value     : $"; ColoredOutput::greenStart() << this->valueMoney << "\n"; ColoredOutput::reset();
        std::cout << "Heal     Amount: " ; ColoredOutput::greenStart() << stat.healAmount << "\n"; ColoredOutput::reset();
        std::cout << "Physical Attack: " ; ColoredOutput::greenStart() << stat.phyAttack << "\n"; ColoredOutput::reset();
        std::cout << "Physical Resist: " ; ColoredOutput::greenStart() << stat.phyResist << "\n"; ColoredOutput::reset();
        std::cout << "Magical  Attack: " ; ColoredOutput::greenStart() << stat.magAttack << "\n"; ColoredOutput::reset();
        std::cout << "Magical  Resist: " ; ColoredOutput::greenStart() << stat.magResist << "\n"; ColoredOutput::reset();
        std::cout << "Stuns          : " ; ColoredOutput::greenStart() << (stat.stun? "true" : "false") << "\n"; ColoredOutput::reset();
        std::cout << "Sellable       : " ; ColoredOutput::greenStart() << (this->can_sell? "true" : "false") << "\n"; ColoredOutput::reset();
    }
}