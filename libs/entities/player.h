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
        bool enteredGame;
        int money;
    
    public:
        Player(std::string name);
        GameMap* getCurrentLoc();
        bool isEnteredGame();
        int getMoney();

        void enter(GameMap* map);
        // engage in a battle in the current location
        GameMatch* engage();
};

#endif