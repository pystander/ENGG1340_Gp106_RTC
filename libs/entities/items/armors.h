#ifndef ARMORS_H
#define ARMORS_H

#include "libs/entities/game_item.h"

class LeatherCloth : public GameItem{
    public:
        LeatherCloth() : GameItem("Leather Cloth", PHY_RESIST, ARMOR){
            this->itemStat.phyResist = 3;
            this->itemStat.magResist = 2;
            this->valueMoney = 150;
        };

        GameItem* copy(){
            return new LeatherCloth();
        }
};

class SilverChestplate : public GameItem{
    public:
        SilverChestplate() : GameItem("Silver Chestplate", PHY_RESIST, ARMOR){
            this->itemStat.phyResist = 12;
            this->itemStat.magResist = 7;
            this->valueMoney = 500;
        };

        GameItem* copy(){
            return new SilverChestplate();
        }
};

class AssassinRobe : public GameItem{
    public:
        AssassinRobe() : GameItem("Assassin Robe", PHY_RESIST, ARMOR){
            this->itemStat.phyAttack = 5; // testing
            this->itemStat.phyResist = 8;
            this->valueMoney = 500;
        };

        GameItem* copy(){
            return new AssassinRobe();
        }
};

class MageCloak : public GameItem{
    public:
        MageCloak() : GameItem("Mage Cloak", MAG_RESIST, ARMOR){
            this->itemStat.magResist = 15;
            this->itemStat.phyResist = 8;
            this->valueMoney = 800;
        };

        GameItem* copy(){
            return new SilverChestplate();
        }
};

class DragonVest : public GameItem{
    public:
        DragonVest() : GameItem("Dragon Vest", MAG_RESIST, ARMOR){
            this->itemStat.phyResist = 25;
            this->itemStat.magResist = 30;
            this->valueMoney = 1800;
        };

        GameItem* copy(){
            return new DragonVest();
        }
};

#endif