#ifndef CHARACTER_H
#define CHARACTER_H

class GameCharacter;

#include <string>
#include <vector>
#include <math.h>

#include "libs/entities/game_item.h"
#include "libs/utils/random_util.h"

#define GAME_ENEMY  0
#define GAME_PLAYER 1

#define WARRIOR  0 // balanced     (good armor, good attack)
#define WIZARD   1 // balanced     (normal armor, very good attack)
#define ASSASSIN 2 // over-powered (very low armor, super good attack)
#define MONSTER  3 // enemy-only type

class GameCharacter{
    protected:
        std::string name;
        std::string type; // eg. warrior, wizard, assassin
        int classType;
        std::vector<GameItem*> inventory;
        GameItem* equippedItem;
        Random* statRng;     // 0-100 rng (easy mode)
        Random* modifierRng; // 0-1 rng
        bool is_player;
        bool stunned;  // timeout for 1 round.
        int level = 1; // default 1
        int xp = 0;    // default 0
        int nextLevelXp = pow(2, level) * log(level) + 100; // calculated using a formula
        float magicResist;
        float physicalResist;
        float currentHp = 100; // default 100
        float maxHp;
        float currentMana = 100; // default 100
        float maxMana;

        // different for different character types
        void forceLevelup();
        /**
         * @param flags types of stat to generate, 0 for all
         */
        CharacterStat genStat(int flags);
        CharacterStat genGeneralStat(Random* rng, int flags);
        CharacterStat genModifier(int flags);

    public:
        GameCharacter(std::string name, bool is_player, int type) : name(name), is_player(is_player), classType(type){
            if(type == WARRIOR){
                this->name = "WARRIOR";
            }else if(type == WIZARD){
                this->name = "WIZARD";
            }else if(type == ASSASSIN){
                this->name = "ASSASSIN";
            }else if(type == MONSTER){
                this->name = "MONSTER";
            }
        };

        std::string getName();
        std::string getType(); // classtype in string
        int getClassType(); 
        std::vector<GameItem*> getInventory();
        GameItem* getEquipped();
        bool isPlayer();
        bool isStunned();

        // use item will have no effect on weapons
        void useItem(GameItem*);
        void equipItem(GameItem*); // weapons only

        void attack(GameCharacter*);
        void heal(GameItem*);
        // used in attack(); to block enemy attack according to your resistance
        CharacterStat block(); // generate defense values
        void levelup();

        void setMagicResist(int);
        void setPhysicalResist(int);
        void setMaxHp(int);
        void setMaxMana(int);

        virtual void displayInventory() = 0; // print
        virtual void displayStatus() = 0; // print
};

#endif