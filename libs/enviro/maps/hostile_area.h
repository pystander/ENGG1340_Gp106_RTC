#ifndef SPAWN_AREA_H
#define SPAWN_AREA_H

#include "libs/enviro/game_map.h"
#include "libs/entities/enemies/weaker_enemies.h"
#include "libs/entities/enemies/bosses.h"

class UnknownVillage : public GameMap{
    public:
        UnknownVillage(int difficulty) : GameMap("Unknown Village", difficulty){
            this->description = "This seems to be an abandoned village, nothing special.\n";
            this->description += "But the broken walls and windows remind you to be careful.\n";
            this->description += "You hear a few sharp noises coming from the woods,\n";
            this->description += "and the sound suddenly vanished, just like hallucinations.\n";
            this->description += "\n";
            this->description += "You see some goblins and wolfs wandering around.\n";
            this->description += "To engage into a battle, type 'engage'.\n";

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
        LostWoods(int difficulty) : GameMap("The Lost Woods", difficulty){
            this->description = "You step into the forest with bravery.\n";
            this->description += "The Woods is always covered with a heavy mist,\n";
            this->description += "and most travellers eventually end up losing their directions.\n";
        };

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
        DawnDungeon(int difficulty) : GameMap("Dungeon of the Dawn", difficulty){
            this->description = "You gradually walk down to the dungeon entrance.\n";
            this->description += "The gate is rotten, opening it would be an effortful task.\n";
            this->description += "You push the gate so hard, that finally it fell down.\n";
            this->description += "All of a sudden, your back and neck feel like freezing.\n";
        };

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