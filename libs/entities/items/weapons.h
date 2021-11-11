#ifndef WEAPONS_H
#define WEAPONS_H

#include "libs/entities/game_item.h"

class WeaponHands : public GameItem{
    public:
        WeaponHands() : GameItem("Hands", PHY_ATTACK, WEAPON){
            this->can_sell = false;
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
            this->valueMoney = 100;
        };

        GameItem* copy(){
            return new WoodenSword();
        }
};

class BronzeDagger : public GameItem{
    public:
        BronzeDagger() : GameItem("Bronze Dagger", PHY_ATTACK, WEAPON){
            this->itemStat.phyAttack = 20;
            this->valueMoney = 300;
        };

        GameItem* copy(){
            return new BronzeDagger();
        }
};

class IronScimitar : public GameItem{
    public:
        IronScimitar() : GameItem("Iron Scimitar", PHY_ATTACK, WEAPON){
            this->itemStat.phyAttack = 25;
            this->valueMoney = 750;
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

class WoodenWand : public GameItem{
    public:
        WoodenWand() : GameItem("Wooden Wand", MAG_ATTACK, WEAPON){
            this->itemStat.magAttack = 20;
            this->valueMoney = 200;
        };
        
        GameItem* copy(){
            return new WoodenWand();
        }
};

class MithrilSword : public GameItem{
    public:
        MithrilSword() : GameItem("Mithril Sword", MAG_ATTACK, WEAPON){
            this->itemStat.magAttack = 30;
            this->valueMoney = 600;
        };

        GameItem* copy(){
            return new MithrilSword();
        }
};

class MageStaff : public GameItem{
    public:
        MageStaff() : GameItem("Mage Staff", MAG_ATTACK, WEAPON){
            this->itemStat.magAttack = 50;
            this->valueMoney = 1200;
        };

        GameItem* copy(){
            return new MageStaff();
        }
};

#endif