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

#endif