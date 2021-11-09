#ifndef WEAKER_ENEMIES_H
#define WEAKER_ENEMIES_H

#include "libs/entities/character.h"

class Goblin : public GameCharacter{
    public:
        Goblin() : GameCharacter("Goblin", false, MONSTER){
            this->baseStat.magAttack = 30;
            this->money = 150;
            this->xp = 50;
        };

        // No inventory
        void displayInventory(){}
};

class Wolf : public GameCharacter{
    public:
        Wolf() : GameCharacter("Wolf", false, MONSTER){
            this->baseStat.magAttack = 35;
            this->money = 200;
            this->xp = 70;
        };

        // No inventory
        void displayInventory(){}
};

class DarkFairy : public GameCharacter{
    public:
        DarkFairy() : GameCharacter("Dark Fairy", false, MONSTER){
            this->baseStat.magAttack = 50;
            this->money = 250;
            this->xp = 100;
        };

        // No inventory
        void displayInventory(){}
};

class Dryad : public GameCharacter{
    public:
        Dryad() : GameCharacter("Dryad", false, MONSTER){
            this->baseStat.magAttack = 50;
            this->money = 250;
            this->xp = 100;
        };

        // No inventory
        void displayInventory(){}
};

#endif