#ifndef CHARACTER_H
#define CHARACTER_H

class GameCharacter;

#include <string>
#include <vector>

#include "libs/entities/game_item.h"

#define GAME_ENEMY  0
#define GAME_PLAYER 1

#define WARRIOR  0 // balanced     (good armor, good attack)
#define WIZARD   1 // balanced     (normal armor, very good attack)
#define ASSASSIN 2 // over-powered (very low armor, super good attack)

class GameCharacter{
    protected:
        std::string name;
        std::string type;
        std::vector<GameItem*> inventory;
        GameItem* equippedItem;
        bool is_player;
        bool stunned;  // timeout for 1 round.
        int level = 1; // default 1
        int xp = 0;    // default 0
        int nextLevelXp; // calculated using a formula
        float magicResist;
        float physicalResist;
        float currentHp = 100; // default 100
        float maxHp;
        float currentMana = 100; // default 100
        float maxMana;

    public:
        GameCharacter(std::string name, bool is_player) : name(name), is_player(is_player){};

        std::string getName();
        std::string getType();
        std::vector<GameItem*> getInventory();
        GameItem* getEquipped();
        bool isPlayer();
        bool isStunned();

        // use item will have no effect on weapons
        void useItem(GameItem*);
        void equipItem(GameItem*);

        void attack(GameCharacter*);
        void heal(GameItem*);
        // used in attack(); to block enemy attack according to your resistance
        void block();
        void levelup();

        void setMagicResist(int);
        void setPhysicalResist(int);
        void setMaxHp(int);
        void setMaxMana(int);

        virtual void displayInventory() = 0; // print
        virtual void displayStatus() = 0; // print
};

#endif