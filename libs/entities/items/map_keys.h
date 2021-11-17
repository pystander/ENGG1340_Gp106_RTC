#ifndef MAP_KEYS_H
#define MAP_KEYS_H

#include "libs/entities/game_item.h"

class UnknownVillageKey : public GameItem{
    public:
        UnknownVillageKey() : GameItem("Unknown Village Key", MISC, ITEM_KEY){
            this->can_sell = false;
        };

        GameItem* copy(){
            return new UnknownVillageKey();
        }
};

#endif