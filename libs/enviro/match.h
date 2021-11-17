#ifndef MATCH_H
#define MATCH_H

class GameMatch;

#include <vector>
#include "libs/enviro/game_map.h"
#include "libs/entities/player.h"
#include "libs/entities/game_item.h"

// Used when a match (battle) starts.
class GameMatch{
    private:
        bool finished = false;
        std::vector<GameCharacter*> enemies; // enemies brought to the battlefield
        std::vector<GameItem*> loots; // loots available for collection
        Player* player;
        GameMap* map;
        const int maxAttackPerRound = 1;
        int playerAttackLeft = 1; // allows player to attack 1 or multiple times in 1 turn 

    public:
        GameMatch(Player* player, GameMap* map) : player(player), map(map) {};

        int enemiesLeft();

        /**
         * @brief Will look for 1-3 enemies from the map.
         * @return whether it's success or not (if no enemies found, it returns false)
         */
        bool start();
        // index of "enemies"
        void attackEnemy(GameCharacter* from, int index);
        // "AI" will return favor
        void endTurn();
        // collect loot on corpses as well
        void cleanCorpse();
        void end();

        void loot(GameCharacter* player, int index);
        void lootAll(GameCharacter* player);

        void displayLoots();
        void displayInfo();
};

#endif