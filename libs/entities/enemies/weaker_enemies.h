#ifndef WEAKER_ENEMIES_H
#define WEAKER_ENEMIES_H

#include "libs/entities/character.h"

class Goblin : public GameCharacter{
    public:
        Goblin() : GameCharacter("Goblin", false, MONSTER){
            // Base stats
            this->maxHp = 100;
            this->baseStat.phyAttack = 35;
            this->baseStat.phyResist = 2;

            // Loots
            this->money = 150;
            this->xp = 50;

            // Level
            const int level = 1;
            for(int i = 0; i < level; i++)
                this->forceLevelup();

            // Initialize HP
            this->currentHp = this->maxHp;
        };

        // No inventory
        void displayInventory(){}
};

class Wolf : public GameCharacter{
    public:
        Wolf() : GameCharacter("Wolf", false, MONSTER){
            // Base stats
            this->maxHp = 150;
            this->baseStat.phyAttack = 40;
            this->baseStat.phyResist = 3;

            // Loots
            this->money = 200;
            this->xp = 70;

            // Level
            const int level = 3;
            for(int i = 0; i < level; i++)
                this->forceLevelup();

            // Initialize HP
            this->currentHp = this->maxHp;
        };

        // No inventory
        void displayInventory(){}
};

class DarkFairy : public GameCharacter{
    public:
        DarkFairy() : GameCharacter("Dark Fairy", false, MONSTER){
            // Base stats
            this->maxHp = 120;
            this->baseStat.magAttack = 50;
            this->baseStat.phyResist = 5;

            // Loots
            this->money = 250;
            this->xp = 100;

            // Level
            const int level = 7;
            for(int i = 0; i < level; i++)
                this->forceLevelup();

            // Initialize HP
            this->currentHp = this->maxHp;
        };

        // No inventory
        void displayInventory(){}
};

class Dryad : public GameCharacter{
    public:
        Dryad() : GameCharacter("Dryad", false, MONSTER){
            // Base stats
            this->maxHp = 150;
            this->currentHp = this->maxHp;
            this->baseStat.phyAttack = 70;
            this->baseStat.phyResist = 7;

            // Loots
            this->money = 275;
            this->xp = 120;

            // Level
            const int level = 9;
            for(int i = 0; i < level; i++)
                this->forceLevelup();

            // Initialize HP
            this->currentHp = this->maxHp;
        };

        // No inventory
        void displayInventory(){}
};

class Zombie : public GameCharacter{
    public:
        Zombie() : GameCharacter("Zombie", false, MONSTER){
            // Base stats
            this->maxHp = 120;
            this->baseStat.phyAttack = 50;
            this->baseStat.phyResist = 15;

            // Loots
            this->money = 300;
            this->xp = 150;

            // Level
            const int level = 10;
            for(int i = 0; i < level; i++)
                this->forceLevelup();
            
            // Initialize HP
            this->currentHp = this->maxHp;
        };

        // No inventory
        void displayInventory(){}
};

class Spirit : public GameCharacter{
    public:
        Spirit() : GameCharacter("Spirit", false, MONSTER){
            this->maxHp = 50;
            this->baseStat.magAttack = 50;
            this->baseStat.phyResist = -1; // Immune to physical attack

            // Loots
            this->money = 50;
            this->xp = 150;

            // Level
            for(int i = 0; i < 10; i++)
                this->forceLevelup();
            
            // Initialize HP
            this->currentHp = this->maxHp;
        };

        // No inventory
        void displayInventory(){}
};

#endif