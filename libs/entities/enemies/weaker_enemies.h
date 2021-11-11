#ifndef WEAKER_ENEMIES_H
#define WEAKER_ENEMIES_H

#include "libs/entities/character.h"
#include "libs/utils/random_util.h"

class Goblin : public GameCharacter{
    public:
        Goblin() : GameCharacter("Goblin", false, MONSTER){
            // Base stats
            this->maxHp = 100;
            this->baseStat.phyAttack = 35;
            this->baseStat.phyResist = 2;

            // Random loots;
            this->money = Random(30, 50).getInt();
            this->xp = Random(20, 50).getInt();

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

            // Random loots
            this->money = Random(70, 120).getInt();
            this->xp = Random(50, 70).getInt();

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

            // Random loots
            this->money = Random(210, 250).getInt();
            this->xp = Random(60, 90).getInt();

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
            this->baseStat.phyAttack = 70;
            this->baseStat.phyResist = 7;

            // Random loots
            this->money = Random(230, 275).getInt();
            this->xp = Random(80, 120).getInt();

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
            this->maxHp = 150;
            this->baseStat.phyAttack = 40;
            this->baseStat.phyResist = 15;

            // Random loots
            this->money = Random(250, 290).getInt();
            this->xp = Random(100, 150).getInt();

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
            this->baseStat.magResist = 25;

            // Random loots
            this->money = Random(200, 230).getInt();
            this->xp = Random(90, 120).getInt();

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