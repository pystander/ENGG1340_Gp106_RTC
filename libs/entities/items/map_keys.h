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

class CastleKey : public GameItem{
    public:
        CastleKey() : GameItem("The Castle Key", MISC, ITEM_KEY){
            this->can_sell = false;
        };

        GameItem* copy(){
            return new CastleKey();
        }
};

class CastleKey_2F : public GameItem{
    public:
        CastleKey_2F() : GameItem("The Castle 2/F Key", MISC, ITEM_KEY){
            this->can_sell = false;
        };

        GameItem* copy(){
            return new CastleKey_2F();
        }
};

class CastleKey_3F : public GameItem{
    public:
        CastleKey_3F() : GameItem("The Castle 3/F Key", MISC, ITEM_KEY){
            this->can_sell = false;
        };

        GameItem* copy(){
            return new CastleKey_3F();
        }
};

class DoorKey : public GameItem{
    public:
        DoorKey() : GameItem("Door Key", MISC, ITEM_KEY){
            this->can_sell = false;
        };

        GameItem* copy(){
            return new DoorKey();
        }
};

#endif