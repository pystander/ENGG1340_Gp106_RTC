#ifndef GAME_ITEM_H
#define GAME_ITEM_H

struct StatModiferStore;
class GameItem;

#include <string>

#define PHY_ATTACK  0b0000001
#define MAG_ATTACK  0b0000010
#define PHY_RESIST  0b0000100
#define MAG_RESIST  0b0001000
#define HEALING     0b0010000
#define STUN        0b0100000
#define MISC        0b1000000

#define MISC_QUEST  0b0001
#define MISC_KEY    0b0010

typedef struct StatModiferStore{
    float phyAttack = -1; // modifiers
    float magAttack = -1;
    float phyResist = -1;
    float magResist = -1;
    float healAmount = -1;
    bool stun;
} StatModiferStore;

class GameItem{
    protected:
        std::string name;
        int type;        // eg. PHY_ATTACK | MAG_ATTACK
        int miscType;    // must have a MISC flag set in "type"
        StatModiferStore itemStat;
    
    public:
        GameItem(std::string name, int type, int miscType) : name(name), type(type), miscType(miscType){};
        GameItem(std::string name, int type) : name(name), type(type), miscType(0){};
        std::string getName();
        int getType();
        int getMiscType();
        StatModiferStore getItemStat();

        virtual GameItem* copy() = 0;

        void displayInfo();
};

#endif