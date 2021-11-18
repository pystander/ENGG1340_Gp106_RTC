#ifndef GAME_ITEM_H
#define GAME_ITEM_H

struct StatModiferStore;
class GameItem;

#include <string>

// Types
#define PHY_ATTACK    0b0000001
#define MAG_ATTACK    0b0000010
#define PHY_RESIST    0b0000100
#define MAG_RESIST    0b0001000
#define HEALING       0b0010000 // for healing hp and restoring mana
#define STUN          0b0100000
#define MISC          0b1000000

// Different item category (just few categories, hence integer is used)
//details
#define ITEM_QUEST  0b0000001
#define ITEM_KEY    0b0000010
#define WEAPON      0b0000100
#define CONSUMABLE  0b0001000 // consumable takes factors as values (eg. 1.2, 0.5)
#define ARMOR       0b0010000
#define RESERVED0   0b0100000
#define RESERVED1   0b1000000

typedef struct StatModiferStore{
    float phyAttack = 0;
    float magAttack = 0;
    float phyResist = 0;
    float magResist = 0;
    float healAmount = 0;
    float manaAmount = 0;
    bool stun;
} StatModiferStore;

extern int GLOBAL_ID;

class GameItem{
    protected:
        int id = GLOBAL_ID++;
        std::string name;
        bool can_sell = true; // eg. Hands cannot be sold
        int type;             // eg. PHY_ATTACK | MAG_ATTACK
        int details;
        int valueMoney = 0;   // how much this item is valued in the market?
        StatModiferStore itemStat;
    
    public:
        GameItem(std::string name, int type, int details) : name(name), type(type), details(details){};
        virtual ~GameItem(){}

        int getId();
        std::string getName();
        bool canSell();
        // eg. damage type
        int getType();
        // eg. weapon, armor, ...
        int getItemCategory();
        int getValueMoney();
        StatModiferStore getItemStat();

        virtual GameItem* copy() = 0;

        void displaySimpleInfo();
        void displayInfo();
        void showStatisticsOnly();
};

#endif