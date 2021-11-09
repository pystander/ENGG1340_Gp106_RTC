#ifndef PEACEFUL_AREA_H
#define PEACEFUL_AREA_H

#include "libs/enviro/game_map.h"

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

class ShopArea : public GameMap{
    public:
        ShopArea(int difficulty) : GameMap("Shop Area", difficulty){};

        GameCharacter* spawnRandomMobs(){
            return nullptr;
        }
};

#endif