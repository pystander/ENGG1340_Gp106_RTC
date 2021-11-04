#ifndef GAME_ITEM_H
#define GAME_ITEM_H

struct CharacterStat;
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

typedef struct CharacterStat{
    float phyAttack; // modifiers
    float magAttack;
    float phyResist;
    float magResist;
    float healAmount;
    bool stun;
} CharacterStat;

class GameItem{
    private:
        std::string name;
        int type;        // eg. PHY_ATTACK | MAG_ATTACK
        int miscType;    // must have a MISC flag set in "type"
        CharacterStat itemStat;
    
    public:
        GameItem(std::string name, int type, int miscType) : name(name), type(type), miscType(miscType){};
        GameItem(std::string name, int type);
        std::string getName();
        int getType();
        int getMiscType();
        CharacterStat getValues();
};

#endif