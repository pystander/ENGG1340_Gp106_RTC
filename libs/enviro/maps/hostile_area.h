#ifndef SPAWN_AREA_H
#define SPAWN_AREA_H

#include "libs/enviro/game_map.h"
#include "libs/entities/enemies/weaker_enemies.h"

class UnknownVillage : public GameMap{
    public:
        UnknownVillage(int difficulty) : GameMap("Unknown Village", difficulty){};

        GameCharacter* spawnRandomMobs(){
            GameCharacter* enemy = new Goblin();
            GameCharacter* enemy = new Wolf();
            return enemy;
        }
};

class LostWoods : public GameMap{
    public:
        LostWoods(int difficulty) : GameMap("The Lost Woods", difficulty){};

        GameCharacter* spawnRandomMobs(){
            GameCharacter* enemy = new DarkFairy();
            GameCharacter* enemy = new Dryad();
            return enemy;
        }
};

#endif