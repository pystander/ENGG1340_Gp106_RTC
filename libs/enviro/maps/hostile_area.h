#ifndef SPAWN_AREA_H
#define SPAWN_AREA_H

#include "libs/enviro/game_map.h"
#include "libs/entities/enemies/weaker_enemies.h"
#include "libs/entities/enemies/bosses.h"

class UnknownVillage : public GameMap{
    public:
        UnknownVillage(int difficulty) : GameMap("Unknown Village", difficulty){
            this->peaceful = false;

            // Graphical description
            // ASCII art from https://ascii.co.uk/art/forest, by ejm96, modified
            // May seem a little bit broken as escape character (\) is used
            this->description = " ^  ^  ^   ^      ___I_      ^  ^   ^  ^  ^   ^  ^\n";
            this->description += "/|\\/|\\/|\\ /|\\    /\\-_--\\    /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n";
            this->description += "/|\\/|\\/|\\ /|\\   /  \\_-__\\   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n";
            this->description += "/|\\/|\\/|\\ /|\\   |[]| [] |   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n";
            this->description += "\n";

            // Text description
            this->description += "This seems to be an abandoned village, nothing special.\n";
            this->description += "But the broken walls and windows remind you to be careful.\n";
            this->description += "You hear a few sharp noises coming from the woods,\n";
            this->description += "and the sound suddenly vanished, just like hallucinations.\n";

            // see map_keys.h for reference
            this->lockWith("Unknown Village Key");
        };

        GameCharacter* spawnRandomMobs(){
            Random rng = Random(0, 1);
            if(rng.getFloat() < 0.5){
                return new Goblin();
            }else if(rng.getFloat() < 0.5){
                return new Wolf();
            }
            return nullptr;
        }
};

class LostWoods : public GameMap{
    public:
        LostWoods(int difficulty) : GameMap("The Lost Woods", difficulty){
            this->peaceful = false;
            this->description = "You step into the forest with bravery.\n";
            this->description += "The Woods is always covered with a heavy mist,\n";
            this->description += "and most travellers eventually end up losing their directions.\n";
        };

        GameCharacter* spawnRandomMobs(){
            Random rng = Random(0, 1);
            if(rng.getFloat() < 0.5){
                return new DarkFairy();
            }else if(rng.getFloat() < 0.5){
                return new Dryad();
            }
            return nullptr;
        }
};

class DawnDungeon : public GameMap{
    public:
        DawnDungeon(int difficulty) : GameMap("Dungeon of the Dawn", difficulty){
            this->peaceful = false;
            this->description = "You gradually walk down to the dungeon entrance.\n";
            this->description += "The gate is rotten, opening it would be an effortful task.\n";
            this->description += "You push the gate so hard, that finally it fell down.\n";
            this->description += "All of a sudden, your back and neck feel like freezing.\n";
        };

        GameCharacter* spawnRandomMobs(){
            Random rng = Random(0, 1);
            if(rng.getFloat() < 0.3){
                return new Zombie();
            }else if(rng.getFloat() < 0.7){
                return new Spirit();
            }
            return nullptr;
        }
};

class Castle_F1 : public GameMap{
    private:
        int spawnCooldown = 0;

    public:
        Castle_F1(int difficulty) : GameMap("The Castle - 1/F", difficulty){
            this->peaceful = false;
        };

        GameCharacter* spawnRandomMobs(){
            if(spawnCooldown == 0){
                spawnCooldown = 3;
                return new FireDragon();
            }
            spawnCooldown--;
            return nullptr;
        }
};

class Castle_F2 : public GameMap{
    private:
        int spawnCooldown = 0;
        
    public:
        Castle_F2(int difficulty) : GameMap("The Castle - 2/F", difficulty){
            this->peaceful = false;
        };

        GameCharacter* spawnRandomMobs(){
            if(spawnCooldown == 0){
                spawnCooldown = 3;
                return new LichKing();
            }
            spawnCooldown--;
            return nullptr;
        }
};

#endif