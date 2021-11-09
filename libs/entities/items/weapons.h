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

class BronzeDagger : public GameItem{
    public:
        BronzeDagger() : GameItem("Bronze Dagger", PHY_ATTACK, WEAPON){
            this->itemStat.phyAttack = 20;
        };

        GameItem* copy(){
            return new BronzeDagger();
        }
};

class IronScimitar : public GameItem{
    public:
        IronScimitar() : GameItem("Iron Scimitar", PHY_ATTACK, WEAPON){
            this->itemStat.phyAttack = 25;
        };

        GameItem* copy(){
            return new IronScimitar();
        }
};

// Easter Egg - Icewind Dale
class PaleJustice : public GameItem{
    public:
        PaleJustice() : GameItem("Pale Justice", PHY_ATTACK, WEAPON){
            this->itemStat.phyAttack = 10;
        };

        GameItem* copy(){
            return new PaleJustice();
        }
};

#endif