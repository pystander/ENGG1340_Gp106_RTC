#ifndef CHAR_SKILL_H
#define CHAR_SKILL_H

struct CharacterSkill;

#include <string>
#include "libs/entities/character.h"

typedef struct CharacterSkill{
    std::string name;
    int type;                // type defined in GameItem, eg. PHY_ATTACK | MAG_ATTACK
    int characterType;       // eg. WARRIOR
    int cooldown;            // measured in turns
    StatModiferStore modifier;
} CharacterSkill;

#endif