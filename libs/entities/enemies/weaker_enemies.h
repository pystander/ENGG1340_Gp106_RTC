#ifndef WEAKER_ENEMIES_H
#define WEAKER_ENEMIES_H

#include "libs/entities/character.h"

class Goblin : public GameCharacter{
    public:
        Goblin() : GameCharacter("Goblin", false, MONSTER){
            this->money = 150;
            this->xp = 50;
        };

        // No inventory
        void displayInventory(){}
};

#endif