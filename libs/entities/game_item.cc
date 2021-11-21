#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "libs/entities/game_item.h"
#include "libs/entities/items/armors.h"
#include "libs/entities/items/weapons.h"
#include "libs/entities/items/consumables.h"
#include "libs/entities/items/map_keys.h"
#include "libs/utils/colored_output.h"

int GLOBAL_ID = 0;

// there is a more efficient way, no time for that.
std::unordered_map<std::string, GameItem*> NAME_TO_ITEM = {
    // armors
    {"Leather Cloth", new LeatherCloth()},
    {"Silver Chestplate", new SilverChestplate()},
    {"Assassin Robe", new AssassinRobe()},
    {"Mage Cloak", new MageCloak()},
    {"Dragon Vest", new DragonVest()},

    // weapons
    {"Hands", new WeaponHands()},
    {"Wooden Sword", new WoodenSword()},
    {"Bronze Dagger", new BronzeDagger()},
    {"Iron Scimitar", new IronScimitar()},
    {"Battle Axe", new BattleAxe()},
    {"War Hammer", new WarHammer()},
    {"Pale Justice", new PaleJustice()},
    {"Wooden Wand", new WoodenWand()},
    {"Mithril Sword", new MithrilSword()},
    {"Mage Staff", new MageStaff()},
    {"Runestone", new RuneStone()},

    // consumables
    {"Strength Potion", new StrengthPotion()},
    {"Magic Fruit", new MagicFruit()},
    {"Small HP potion", new SmallHpPotion()},
    {"Medium HP potion", new MediumHpPotion()},
    {"Extra HP potion", new ExtraHpPotion()},
    {"Phoenix Tear", new PhoenixTear()},
    {"Small MP Potion", new SmallMpPotion()},
    {"Medium MP Potion", new MediumMpPotion()},
    {"Extra MP Potion", new ExtraMpPotion()},

    // map keys
    {"Unknown Village Key", new UnknownVillageKey()},
    {"The Castle Key", new CastleKey()},
    {"The Castle 2/F Key", new CastleKey_2F()},
    {"The Castle 3/F Key", new CastleKey_3F()},
    {"Door Key", new DoorKey()},
};

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
        std::cout << "Tradable            : " ; ColoredOutput::greenStart() << (this->can_sell? "true" : "false") << "\n"; ColoredOutput::reset();
    }else{
        std::cout << "Item Value     : $"; ColoredOutput::greenStart() << this->valueMoney << "\n"; ColoredOutput::reset();
        std::cout << "Heal     Amount: " ; ColoredOutput::greenStart() << stat.healAmount << "\n"; ColoredOutput::reset();
        std::cout << "Physical Attack: " ; ColoredOutput::greenStart() << stat.phyAttack << "\n"; ColoredOutput::reset();
        std::cout << "Physical Resist: " ; ColoredOutput::greenStart() << stat.phyResist << "\n"; ColoredOutput::reset();
        std::cout << "Magical  Attack: " ; ColoredOutput::greenStart() << stat.magAttack << "\n"; ColoredOutput::reset();
        std::cout << "Magical  Resist: " ; ColoredOutput::greenStart() << stat.magResist << "\n"; ColoredOutput::reset();
        std::cout << "Stuns          : " ; ColoredOutput::greenStart() << (stat.stun? "true" : "false") << "\n"; ColoredOutput::reset();
        std::cout << "Tradable       : " ; ColoredOutput::greenStart() << (this->can_sell? "true" : "false") << "\n"; ColoredOutput::reset();
    }
}

GameItem* GameItem::load(std::fstream& instream){
    std::string in;
    instream >> in;
    if(in == "[item]") // just in case
        instream >> in;
    if(in == "null")
        return nullptr;
    if(in == "name:"){
        instream.ignore(1); // skip ' '
        std::getline(instream, in);
        return NAME_TO_ITEM[in];
    }else{
        ColoredOutput::red("Error: ") << "Cannot parse item\n";
    }
    return nullptr;
}

std::string GameItem::exportData(GameItem* item){
    std::string data = "[item]";
    data += "\nname: " + item->getName();
    data += "\n";
    return data;
}


StatModiferStore GameItem::importStat(std::fstream& instream){
    StatModiferStore stat;
    std::string arg;
    instream >> arg;
    stat.phyAttack = std::stof(arg); 
    instream >> arg;
    stat.magAttack = std::stof(arg); 
    instream >> arg;
    stat.phyResist = std::stof(arg); 
    instream >> arg;
    stat.magResist = std::stof(arg); 
    instream >> arg;
    stat.healAmount = std::stof(arg);
    instream >> arg;
    stat.manaAmount = std::stof(arg);
    instream >> arg;
    stat.stun = std::stoi(arg);
    return stat;
}

std::string GameItem::exportStat(StatModiferStore stat){
    std::string data = "";
    data += std::to_string(stat.phyAttack) + " ";
    data += std::to_string(stat.magAttack) + " ";
    data += std::to_string(stat.phyResist) + " ";
    data += std::to_string(stat.magResist) + " ";
    data += std::to_string(stat.healAmount) + " ";
    data += std::to_string(stat.manaAmount) + " ";
    data += std::to_string(stat.stun);
    return data;
}