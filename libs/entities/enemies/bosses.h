#ifndef BOSSES_H
#define BOSSES_H

#include "libs/entities/character.h"

class FireDragon : public GameCharacter{
    public:
        FireDragon() : GameCharacter("Fire Dragon", false, MONSTER){
            this->baseStat.phyAttack = 200;
            this->baseStat.magAttack = 275;
            this->money = 1000;
            this->xp = 700;
        };

        // No inventory
        void displayInventory(){}
};

// Easter Egg - World of Warcraft
class LichKing : public GameCharacter{
    public:
        LichKing() : GameCharacter("The Lich King", false, MONSTER){
            this->baseStat.phyAttack = 300;
            this->baseStat.magAttack = 300;
            this->money = 1500;
            this->xp = 1200;
        };

        // No inventory
        void displayInventory(){}
};

#endif