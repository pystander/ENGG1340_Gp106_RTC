#ifndef MATCH_H
#define MATCH_H

class GameMatch;

#include "libs/enviro/game_map.h"
#include "libs/entities/player.h"

// Used when a match (battle) starts.
class GameMatch{
    private:
        // player takes the initiative on match start
        bool playersTurn = true;

    public:
        GameMatch(Player* player, GameMap* map);

        void start();
};

#endif