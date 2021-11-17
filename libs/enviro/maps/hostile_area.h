#ifndef SPAWN_AREA_H
#define SPAWN_AREA_H

#include "libs/enviro/game_map.h"
#include "libs/entities/enemies/weaker_enemies.h"
#include "libs/entities/enemies/bosses.h"

class UnknownVillage : public GameMap{
    public:
        UnknownVillage(int difficulty) : GameMap("Unknown Village", difficulty){
            // see map_keys.h for reference
            this->keyName = "Unknown Village Key";
            this->lock();
        };

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

class Castle_F1 : public GameMap{
    public:
        Castle_F1(int difficulty) : GameMap("The Castle - 1/F", difficulty){};

        GameCharacter* spawnRandomMobs(){
            return new FireDragon();
        }
};

class Castle_F2 : public GameMap{
    public:
        Castle_F2(int difficulty) : GameMap("The Castle - 2/F", difficulty){};

        GameCharacter* spawnRandomMobs(){
            return new LichKing();
        }
};

#endif