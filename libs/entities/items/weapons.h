#ifndef WEAPONS_H
#define WEAPONS_H

#include "libs/entities/game_item.h"

// Who needs a weapon if a punch solves everything

class WeaponHands : public GameItem{
    public:
        WeaponHands() : GameItem("Hands", PHY_ATTACK, WEAPON){
            this->can_sell = false;
            this->itemStat.phyAttack = 5;
            // this->itemStat.phyAttack = 155; // testing
        };

        GameItem* copy(){
            return new WeaponHands();
        }
};

class WoodenSword : public GameItem{
    public:
        WoodenSword() : GameItem("Wooden Sword", PHY_ATTACK, WEAPON){
            this->itemStat.phyAttack = 10;
            this->valueMoney = 100;
        };

        GameItem* copy(){
            return new WoodenSword();
        }
};

class BronzeDagger : public GameItem{
    public:
        BronzeDagger() : GameItem("Bronze Dagger", PHY_ATTACK, WEAPON){
            this->itemStat.phyAttack = 15;
            this->valueMoney = 300;
        };

        GameItem* copy(){
            return new BronzeDagger();
        }
};

class IronScimitar : public GameItem{
    public:
        IronScimitar() : GameItem("Iron Scimitar", PHY_ATTACK, WEAPON){
            this->itemStat.phyAttack = 20;
            this->valueMoney = 750;
        };

        GameItem* copy(){
            return new IronScimitar();
        }
};

class BattleAxe : public GameItem{
    public:
        BattleAxe() : GameItem("Battle Axe", PHY_ATTACK, WEAPON){
            this->itemStat.phyAttack = 35;
            this->valueMoney = 1000;
        };

        GameItem* copy(){
            return new BattleAxe();
        }
};

class WarHammer : public GameItem{
    public:
        WarHammer() : GameItem("War Hammer", PHY_ATTACK, WEAPON){
            this->itemStat.phyAttack = 50;
            this->valueMoney = 1500;
        };

        GameItem* copy(){
            return new WarHammer();
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
            this->itemStat.magAttack = 15;
            this->valueMoney = 200;
        };
        
        GameItem* copy(){
            return new WoodenWand();
        }
};

class MithrilSword : public GameItem{
    public:
        MithrilSword() : GameItem("Mithril Sword", MAG_ATTACK, WEAPON){
            this->itemStat.magAttack = 35;
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

class RuneStone : public GameItem{
    public:
        RuneStone() : GameItem("Runestone", MAG_ATTACK, WEAPON){
            this->itemStat.magAttack = 85;
            this->valueMoney = 2000;
        };

        GameItem* copy(){
            return new RuneStone();
        }
};

#endif