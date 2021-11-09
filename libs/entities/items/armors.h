#ifndef ARMORS_H
#define ARMORS_H

#include "libs/entities/game_item.h"

class LeatherCloth : public GameItem{
    public:
        LeatherCloth() : GameItem("Leather Cloth", PHY_RESIST, ARMOR){
            this->itemStat.phyResist = 3;
        };

        GameItem* copy(){
            return new LeatherCloth();
        }
};

class SilverChestplate : public GameItem{
    public:
        SilverChestplate() : GameItem("Silver Chestplate", PHY_RESIST, ARMOR){
            this->itemStat.phyResist = 10;
        };

        GameItem* copy(){
            return new SilverChestplate();
        }
};

class MageCloak : public GameItem{
    public:
        MageCloak() : GameItem("Mage Cloak", MAG_RESIST, ARMOR){
            this->itemStat.magResist = 15;
        };

        GameItem* copy(){
            return new SilverChestplate();
        }
};

#endif