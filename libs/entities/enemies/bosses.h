#ifndef BOSSES_H
#define BOSSES_H

#include "libs/entities/character.h"
#include "libs/utils/random_util.h"

class FireDragon : public GameCharacter{
    public:
        FireDragon() : GameCharacter("Fire Dragon", false, MONSTER){
            // Base stats
            this->maxHp = 500;
            this->baseStat.phyAttack = 200;
            this->baseStat.magAttack = 250;
            this->baseStat.phyResist = 75;
            this->baseStat.magResist = 90;

            // Fixed loots
            this->money = 1000;
            this->xp = 700;

            for(int i = 0; i < 50; i++)
                this->forceLevelup();
        };

        // No inventory
        void displayInventory(){}
};

// Easter Egg - World of Warcraft
class LichKing : public GameCharacter{
    public:
        LichKing() : GameCharacter("The Lich King", false, MONSTER){
            // Base stats
            this->maxHp = 500;
            this->baseStat.phyAttack = 300;
            this->baseStat.magAttack = 300;

            // Fixed loots
            this->money = 1500;
            this->xp = 1200;

            // Level
            for(int i = 0; i < 70; i++)
                this->forceLevelup();
        };

        // No inventory
        void displayInventory(){}
};

#endif