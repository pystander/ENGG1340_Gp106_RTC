#ifndef PEACEFUL_AREA_H
#define PEACEFUL_AREA_H

#include "libs/enviro/game_map.h"
#include "libs/entities/items/consumables.h"

class SpawnArea : public GameMap{
    public:
        SpawnArea(int difficulty) : GameMap("Spawn Area", difficulty){};

        GameCharacter* spawnRandomMobs(){
            return nullptr;
        }
};

class WaitingArea : public GameMap{
    public:
        WaitingArea(int difficulty) : GameMap("Waiting Area", difficulty){};

        GameCharacter* spawnRandomMobs(){
            return nullptr;
        }
};

class ConsumableShop : public GameMap{
    public:
        ConsumableShop(int difficulty) : GameMap("Consumable Shop", difficulty){
            this->shopType = SHOP_CONSUMABLES;
            this->itemsOnSold.push_back(new SmallHpPotion());
            this->itemsOnSold.push_back(new MediumHpPotion());
            this->itemsOnSold.push_back(new ExtraHpPotion());
        };

        GameCharacter* spawnRandomMobs(){
            return nullptr;
        }
};

#endif