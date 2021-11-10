#ifndef SPAWN_AREA_H
#define SPAWN_AREA_H

#include "libs/enviro/game_map.h"
#include "libs/entities/enemies/weaker_enemies.h"

class UnknownVillage : public GameMap{
    public:
        UnknownVillage(int difficulty) : GameMap("Unknown Village", difficulty){};

        GameCharacter* spawnRandomMobs(){
            Random rng = Random(0, 1);
            if(rng.getFloat() < 0.5){
                return new Goblin();
            }
            return new Wolf();
        }
};

class LostWoods : public GameMap{
    public:
        LostWoods(int difficulty) : GameMap("The Lost Woods", difficulty){};

        GameCharacter* spawnRandomMobs(){
            Random rng = Random(0, 1);
            if(rng.getFloat() < 0.5){
                return new DarkFairy();
            }
            return new Dryad();
        }
};

class DawnDungeon : public GameMap{
    public:
        DawnDungeon(int difficulty) : GameMap("Dungeon of the Dawn", difficulty){};

        GameCharacter* spawnRandomMobs(){
            Random rng = Random(0, 1);
            if(rng.getFloat() < 0.3){
                return new Zombie();
            }
            return new Spirit();
        }
};

#endif