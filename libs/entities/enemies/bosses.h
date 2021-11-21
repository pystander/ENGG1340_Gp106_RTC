#ifndef BOSSES_H
#define BOSSES_H

#include "libs/entities/character.h"
#include "libs/entities/items/map_keys.h"
#include "libs/utils/random_util.h"

class FireDragon : public GameCharacter{
    public:
        FireDragon() : GameCharacter("Fire Dragon", false, MONSTER){
            // Base stats
            this->baseStat.phyAttack = 200;
            this->baseStat.magAttack = 250;
            this->baseStat.phyResist = 75;
            this->baseStat.magResist = 90;

            // Fixed loots
            this->money = 1000;
            this->xp = 700;

            for(int i = 0; i < 50; i++)
                this->forceLevelup();

            // Hp Fixed
            this->maxHp = 500;
            this->currentHp = this->maxHp;
        };

        std::vector<GameItem*> dropRandomLoots(){
            std::vector<GameItem*> loots;
            loots.push_back(new CastleKey_2F());
            return loots;
        }

        // No inventory
        void displayInventory(){}
};

// Easter Egg - World of Warcraft
class LichKing : public GameCharacter{
    public:
        LichKing() : GameCharacter("The Lich King", false, MONSTER){
            // Base stats
            this->baseStat.phyAttack = 300;
            this->baseStat.magAttack = 300;
            this->baseStat.phyResist = 95;
            this->baseStat.magResist = 80;

            // Fixed loots
            this->money = 1500;
            this->xp = 1200;

            // Level
            for(int i = 0; i < 70; i++)
                this->forceLevelup();

            // Hp Fixed
            this->maxHp = 500;
            this->currentHp = this->maxHp;
        };
        
        std::vector<GameItem*> dropRandomLoots(){
            std::vector<GameItem*> loots;
            loots.push_back(new PaleJustice());
            loots.push_back(new CastleKey_3F());
            return loots;
        }

        // No inventory
        void displayInventory(){}
};

class Magician : public GameCharacter{
    public:
        Magician() : GameCharacter("The Magician", false, MONSTER){
            // Base stats
            this->baseStat.phyAttack = 100;
            this->baseStat.magAttack = 550;
            this->baseStat.phyResist = 70;
            this->baseStat.magResist = 99;

            // Fixed loots
            this->money = 1200;
            this->xp = 1500;

            // Level
            for(int i = 0; i < 70; i++)
                this->forceLevelup();

            // Hp Fixed
            this->maxHp = 350;
            this->currentHp = this->maxHp;
        };
        
        std::vector<GameItem*> dropRandomLoots(){
            std::vector<GameItem*> loots;
            loots.push_back(new DoorKey());
            return loots;
        }

        // No inventory
        void displayInventory(){}
};

#endif