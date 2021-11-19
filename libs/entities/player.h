#ifndef PLAYER_H
#define PLAYER_H

class Player;

#include <fstream>
#include <string>
#include <vector>
#include "libs/entities/character.h"
#include "libs/skills/char_skill.h"
#include "libs/enviro/game.h"
#include "libs/enviro/game_map.h"
#include "libs/enviro/match.h"

class Player : public GameCharacter{
    private:
        // not planning to add skill to mobs
        std::vector<GameItem*> mapsUnlocked; // will be used to unlock maps after loading
        GameMap* currentLoc;
        GameMatch* recentMatch;
        bool enteredBattle = false;
    
    public:
        Player(std::string name, int type) : GameCharacter(name, true, type) {}
        GameMap* getCurrentLoc();
        bool isInBattle();

        void unlockMap(GameMap* map, GameItem* item);
        void forceEnter(GameMap*);
        void enter(GameMap*);
        // engage in a battle in the current location
        GameMatch* engage();
        void disengage();

        // null if not in a battle. It can be ongoing.
        std::vector<GameItem*> getMapsUnlocked();
        GameMatch* getRecentMatch();
        void buyItem(int index);
        void sellItem(int index);

        std::vector<GameItem*> dropRandomLoots();

        void displaySkills();
        void displayInventory();
        void displayPlayerStatus();

        static Player* load(std::fstream& instream, Game* game);
        static std::string exportData(Player* player);
};

#endif