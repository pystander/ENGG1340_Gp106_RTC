#ifndef WEAPONS_H
#define WEAPONS_H

#include "libs/entities/game_item.h"

class WeaponHands : public GameItem{
    public:
        WeaponHands() : GameItem("Hands", PHY_ATTACK, WEAPON){
            this->itemStat.phyAttack = 5;
        };

        GameItem* copy(){
            return new WeaponHands();
        }
};

class WoodenSword : public GameItem{
    public:
        WoodenSword() : GameItem("Wooden Sword", PHY_ATTACK, WEAPON){
            this->itemStat.phyAttack = 15;
        };

        GameItem* copy(){
            return new WoodenSword();
        }
};

#endif