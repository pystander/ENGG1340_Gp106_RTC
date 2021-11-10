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
            
            // Deal with mana and hp differently
            // Set the currentHp to max as well.
            this->maxHp = 500;
            this->currentHp = this->maxHp;
            
            // feel free to raise its level
            for(int i = 0; i < 100; i++)
                this->forceLevelup();
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
            
            // Deal with mana and hp differently
            // Set the currentHp to max as well.
            this->maxHp = 300;
            this->currentHp = this->maxHp;

            for(int i = 0; i < 100; i++)
                this->forceLevelup();
        };

        // No inventory
        void displayInventory(){}
};

#endif