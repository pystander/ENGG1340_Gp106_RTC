#ifndef SPAWN_AREA_H
#define SPAWN_AREA_H

#include "libs/enviro/game_map.h"
#include "libs/entities/enemies/weaker_enemies.h"

class UnknownVillage : public GameMap{
    public:
        UnknownVillage(int difficulty) : GameMap("Unknown Village", difficulty){};

        GameCharacter* spawnRandomMobs(){
            GameCharacter* enemy = new Goblin();
            return enemy;
        }
};

class LostWoods : public GameMap{
    public:
        LostWoods(int difficulty) : GameMap("Lost Woods", difficulty){};

        GameCharacter* spawnRandomMobs(){
            GameCharacter* enemy = new Wolf();
            GameCharacter* enemy = new DarkFairy();
            return enemy;
        }
};

#endif