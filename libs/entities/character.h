#ifndef CHARACTER_H
#define CHARACTER_H

class GameCharacter;

#include <stdlib.h>
#include <string>
#include <vector>
#include <math.h>

#include "libs/entities/game_item.h"
#include "libs/utils/random_util.h"
#include "libs/entities/items/weapons.h"

#define GAME_ENEMY  0
#define GAME_PLAYER 1

#define WARRIOR  0 // balanced     (good armor, good attack)
#define WIZARD   1 // balanced     (normal armor, very good attack)
#define ASSASSIN 2 // over-powered (very low armor, super good attack)
#define MONSTER  3 // enemy-only type

class GameCharacter{
    protected:
        std::string name;
        std::string typeStr; // eg. warrior, wizard, assassin
        int classType;
        std::vector<GameItem*> inventory;
        GameItem* equippedItem;
        Random statRng = Random(0, 100);
        bool is_player;
        bool stunned;  // timeout for 1 round.
        bool is_dead;
        int level = 0; // default 0, setup() will add one
        int xp = 0;    // default 0
        int nextLevelXp = 100; // calculated in forceLevelup();
        StatModiferStore baseStat; // healAmount and stun will not be used
        StatModiferStore battleStat; // base should not be modified
        float currentHp = 100; // default 100
        float maxHp = 100;
        float currentMana = 100; // default 100
        float maxMana = 100;

        // different for different character types
        void forceLevelup();
        /**
         * @param flags types of stat to generate, 0 for all
         */
        StatModiferStore genStat(int flags);
        StatModiferStore genStatWithRng(Random* rng, int flags);
        StatModiferStore genModifier(int flags);

    public:
        GameCharacter(std::string name, bool is_player, int classType) : name(name), is_player(is_player), classType(classType){
            if(classType == WARRIOR){
                this->typeStr = "WARRIOR";
            }else if(classType == WIZARD){
                this->typeStr = "WIZARD";
            }else if(classType == ASSASSIN){
                this->typeStr = "ASSASSIN";
            }else if(classType == MONSTER){
                this->typeStr = "MONSTER";
            }
            this->setup();
            this->inventory.push_back(new WeaponHands());
            this->equippedItem = this->inventory[0];
        };
        ~GameCharacter(){
            for(int i = 0; i < inventory.size(); i++)
                free(inventory[i]);
        }

        std::string getName();
        std::string getType(); // classtype in string
        int getClassType(); 
        std::vector<GameItem*> getInventory();
        GameItem* getEquipped();
        bool isPlayer();
        bool isStunned();
        bool isDead();
        void setBaseStat(StatModiferStore);

        // setup stats for character
        void setup();

        // use item will have no effect on weapons
        void useItem(GameItem*);
        void equipItem(GameItem*); // weapons only

        void attack(GameCharacter*);
        // maybe modified by skills. (takes factors as argument)
        void applyModifier(StatModiferStore);
        void clearModifier();
        void heal(GameItem*);
        // used in attack(); to block enemy attack according to your resistance
        StatModiferStore block(); // generate defense values
        void levelup();
        void dead();

        virtual void displayInventory() = 0; // print
        void displayCharacterStatus(); // print
};

#endif