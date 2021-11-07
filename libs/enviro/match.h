#ifndef MATCH_H
#define MATCH_H

class GameMatch;

#include "libs/enviro/game_map.h"
#include "libs/entities/player.h"

// Used when a match (battle) starts.
class GameMatch{
    private:
        bool finished = false;
        std::vector<GameCharacter*> enemies; // enemies brought to the battlefield
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
        void cleanCorpse();
        void end();

        void displayInfo();
};

#endif