#ifndef CHARACTER_H
#define CHARACTER_H

class GameCharacter;

#include <stdlib.h>
#include <string>
#include <vector>
#include <math.h>

#include "libs/entities/game_item.h"
#include "libs/entities/items/weapons.h"
#include "libs/utils/random_util.h"

#define WARRIOR  0 // balanced     (good armor, good attack)
#define WIZARD   1 // balanced     (normal armor, very good attack)
#define ASSASSIN 2 // over-powered (very low armor, super good attack)
#define MONSTER  3 // enemy-only type

class GameCharacter{
    protected:
        std::string name;
        std::string typeStr; // eg. warrior, wizard, assassin
        int classType;       // eg. WARRIOR (0)
        std::vector<GameItem*> inventory;
        GameItem* equippedItem = nullptr;
        GameItem* armor = nullptr;
        Random statRng = Random(0, 100);
        bool is_player;
        bool stunned = false;  // timeout for 1 round. (may not be implemented)
        bool is_dead = false;
        int money = 0; // will be added to the killer if a person killed
        int level = 0; // default 0, setup() will add one
        // default 0 (enemies will have more than 0 xp, 
        // whoever claim their lives will take their xp)
        int xp = 0;
        int nextLevelXp = 100; // calculated in forceLevelup();
        StatModiferStore baseStat; // healAmount and stun will not be used
        StatModiferStore additionalStat; // additional to base stat. (eg. equipment stat.)
        StatModiferStore modifierStat; // factors, eg. 1.5, 0.5
        float currentHp = 100; // default 100
        float maxHp = 100;
        float currentMana = 100; // default 100
        float maxMana = 100;

        /**
         * @param flags types of stat to generate, 0 for all
         */
        StatModiferStore genStat(int flags);
        StatModiferStore genStatWithRng(Random* rng, int flags);
        StatModiferStore genModifier(int flags);

    public:
        GameCharacter(std::string name, bool is_player, int classType) : name(name), is_player(is_player), classType(classType){
            if(classType == WIZARD){
                this->typeStr = "WIZARD";
            }else if(classType == ASSASSIN){
                this->typeStr = "ASSASSIN";
            }else if(classType == MONSTER){
                this->typeStr = "MONSTER";
            }else{
                this->typeStr = "WARRIOR";
            }
            this->setup();
        };
        virtual ~GameCharacter(){
            for(int i = 0; i < inventory.size(); i++)
                delete inventory[i];
        }

        std::string getName();
        std::string getType(); // classtype in string
        int getClassType();
        std::vector<GameItem*> getInventory();
        // returns null if index is invalid
        GameItem* getFromInventory(int index);
        GameItem* getEquipped();
        int getMoneyAmount();
        bool isPlayer();
        bool isStunned();
        bool isDead();
        void setBaseStat(StatModiferStore);
        // set displayed level and next level xp required to levelup
        void setLevel(int lvl, int nextLevelXp);
        void addXp(int);
        void addToInventory(GameItem*);
        void addMoney(int);
        // subtracts the amount of money.
        // returns whether the person has enough money or not 
        // (success or not)
        bool subMoney(int);

        // setup stats for character
        void setup();

        // delete an item from inventory
        void deleteItem(GameItem*);
        void useItem(GameItem*);
        void equipItem(GameItem*); // weapons only

        void attack(GameCharacter*);
        // maybe modified by skills. (takes factors as argument)
        void applyModifier(StatModiferStore);
        void resetModifier();
        void recalculateAdditionalStat();
        void heal(GameItem*);
        void manaRegen();
        // used in attack(); to block enemy attack according to your resistance
        StatModiferStore block(); // generate defense values
        void forceLevelup();
        void levelup();
        void dead();
        void restore(); // for enemies only

        virtual std::vector<GameItem*> dropRandomLoots() = 0;

        virtual void displayInventory() = 0; // print
        void displayCharacterStatus(); // print
};

#endif