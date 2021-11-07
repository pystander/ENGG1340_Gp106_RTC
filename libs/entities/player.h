#ifndef PLAYER_H
#define PLAYER_H

class Player;

#include <string>
#include <vector>
#include "libs/entities/character.h"
#include "libs/skills/char_skill.h"
#include "libs/enviro/game_map.h"
#include "libs/enviro/match.h"

class Player : public GameCharacter{
    private:
        // not planning to add skill to mobs
        std::vector<CharacterSkill> skills;
        GameMap* currentLoc;
        GameMatch* recentMatch;
        bool enteredBattle;
    
    public:
        Player(std::string name, int type) : GameCharacter(name, true, type) {}
        GameMap* getCurrentLoc();
        bool isInBattle();

        void enter(GameMap*);
        // engage in a battle in the current location
        GameMatch* engage();
        void disengage();

        // null if not in a battle. It can be ongoing.
        GameMatch* getRecentMatch();

        void displayInventory();
        void displayPlayerStatus();
};

#endif