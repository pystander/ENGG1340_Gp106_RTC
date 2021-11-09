#ifndef CONSUMABLES_H
#define CONSUMABLES_H

#include "libs/entities/game_item.h"
#include "libs/utils/random_util.h"

class SmallHpPotion : public GameItem{
    public:
        SmallHpPotion() : GameItem("Small HP potion", HEALING, CONSUMABLE){
            Random rng = Random(10, 20);
            this->itemStat.healAmount = rng.getInt();
        };

        GameItem* copy(){
            return new SmallHpPotion();
        }
};

class MideumHpPotion : public GameItem{
    public:
        MideumHpPotion() : GameItem("Medium HP potion", HEALING, CONSUMABLE){
            Random rng = Random(25, 40);
            this->itemStat.healAmount = rng.getInt();
        };

        GameItem* copy(){
            return new MideumHpPotion();
        }
};

class ExtraHpPotion : public GameItem{
    public:
        ExtraHpPotion() : GameItem("Extra HP potion", HEALING, CONSUMABLE){
            Random rng = Random(50, 75);
            this->itemStat.healAmount = rng.getInt();
        };

        GameItem* copy(){
            return new ExtraHpPotion();
        }
};

// Easter Egg - Harry Potter
class PhoenixTear : public GameItem{
    public:
        PhoenixTear() : GameItem("Phoenix Tear", HEALING, CONSUMABLE){
            Random rng = Random(80, 100);
            this->itemStat.healAmount = rng.getInt();
            
            Random rng = Random(80, 100);
            this->itemStat.manaAmount = rng.getInt();
        };

        GameItem* copy(){
            return new PhoenixTear();
        }
};

class SmallMpPotion : public GameItem{
    public:
        SmallMpPotion() : GameItem("Small MP Potion", HEALING, CONSUMABLE){
            Random rng = Random(20, 30);
            this->itemStat.manaAmount = rng.getInt();
        };

        GameItem* copy(){
            return new SmallMpPotion();
        }
};

class MediumMpPotion : public GameItem{
    public:
        MediumMpPotion() : GameItem("Medium MP Potion", HEALING, CONSUMABLE){
            Random rng = Random(50, 70);
            this->itemStat.manaAmount = rng.getInt();
        };

        GameItem* copy(){
            return new MediumMpPotion();
        }
};

class ExtraMpPotion : public GameItem{
    public:
        ExtraMpPotion() : GameItem("Extra MP Potion", HEALING, CONSUMABLE){
            Random rng = Random(80, 100);
            this->itemStat.manaAmount = rng.getInt();
        };

        GameItem* copy(){
            return new ExtraMpPotion();
        }
};

#endif