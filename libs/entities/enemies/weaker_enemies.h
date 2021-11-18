#ifndef WEAKER_ENEMIES_H
#define WEAKER_ENEMIES_H

#include "libs/entities/character.h"
#include "libs/entities/items/weapons.h"
#include "libs/utils/random_util.h"

class Goblin : public GameCharacter{
    public:
        Goblin() : GameCharacter("Goblin", false, MONSTER){
            // Base stats
            this->baseStat.phyAttack = 40;
            this->baseStat.phyResist = 5;

            // Random loots;
            this->money = Random(30, 50).getInt();
            this->xp = Random(20, 50).getInt();

            // Hp Fixed
            this->maxHp = 100;
            this->currentHp = this->maxHp;
        };

        std::vector<GameItem*> dropRandomLoots(){
            std::vector<GameItem*> loots;

            // Random loots
            if(Random(0, 1).getFloat() >= 0.5)
                loots.push_back(new WoodenSword());

            return loots;
        }

        // No inventory
        void displayInventory(){}
};

class Wolf : public GameCharacter{
    public:
        Wolf() : GameCharacter("Wolf", false, MONSTER){
            // Base stats
            this->baseStat.phyAttack = 50;
            this->baseStat.phyResist = 9;

            // Random loots
            this->money = Random(70, 120).getInt();
            this->xp = Random(50, 70).getInt();

            // Level 4
            for(int i = 0; i < 3; i++)
                this->forceLevelup();

            // Hp Fixed
            this->maxHp = 120;
            this->currentHp = this->maxHp;
        };

        std::vector<GameItem*> dropRandomLoots(){
            std::vector<GameItem*> loots;
            loots.push_back(new WoodenSword());
            return loots;
        }

        // No inventory
        void displayInventory(){}
};

class DarkFairy : public GameCharacter{
    public:
        DarkFairy() : GameCharacter("Dark Fairy", false, MONSTER){
            // Base stats
            this->baseStat.magAttack = 50;
            this->baseStat.phyResist = 7;
            this->baseStat.magResist = 3;

            // Random loots
            this->money = Random(210, 250).getInt();
            this->xp = Random(60, 90).getInt();

            // Level 8
            for(int i = 0; i < 7; i++)
                this->forceLevelup();

            // Hp Fixed
            this->maxHp = 150;
            this->currentHp = this->maxHp;
        };
        
        std::vector<GameItem*> dropRandomLoots(){
            return std::vector<GameItem*>();
        }

        // No inventory
        void displayInventory(){}
};

class Dryad : public GameCharacter{
    public:
        Dryad() : GameCharacter("Dryad", false, MONSTER){
            // Base stats
            this->baseStat.phyAttack = 70;
            this->baseStat.phyResist = 15;

            // Random loots
            this->money = Random(230, 275).getInt();
            this->xp = Random(80, 120).getInt();

            // Level 10
            for(int i = 0; i < 9; i++)
                this->forceLevelup();

            // Hp Fixed
            this->maxHp = 180;
            this->currentHp = this->maxHp;
        };
        
        std::vector<GameItem*> dropRandomLoots(){
            return std::vector<GameItem*>();
        }

        // No inventory
        void displayInventory(){}
};

class Zombie : public GameCharacter{
    public:
        Zombie() : GameCharacter("Zombie", false, MONSTER){
            // Base stats
            this->baseStat.phyAttack = 40;
            this->baseStat.phyResist = 25;

            // Random loots
            this->money = Random(250, 290).getInt();
            this->xp = Random(100, 150).getInt();

            // Level 11
            for(int i = 0; i < 10; i++)
                this->forceLevelup();

            // Hp Fixed
            this->maxHp = 200;
            this->currentHp = this->maxHp;
        };
        
        std::vector<GameItem*> dropRandomLoots(){
            return std::vector<GameItem*>();
        }

        // No inventory
        void displayInventory(){}
};

class Spirit : public GameCharacter{
    public:
        Spirit() : GameCharacter("Spirit", false, MONSTER){
            this->baseStat.magAttack = 70;
            this->baseStat.magResist = 25;

            // Random loots
            this->money = Random(200, 230).getInt();
            this->xp = Random(90, 120).getInt();

            // Level 11
            for(int i = 0; i < 10; i++)
                this->forceLevelup();
            
            // Hp Fixed
            this->maxHp = 50;
            this->currentHp = this->maxHp;
        };
        
        std::vector<GameItem*> dropRandomLoots(){
            return std::vector<GameItem*>();
        }

        // No inventory
        void displayInventory(){}
};

#endif