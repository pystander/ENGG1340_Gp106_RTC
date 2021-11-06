#ifndef GAME_H
#define GAME_H

class Game;

#include <stdlib.h>
#include <vector>
#include "libs/utils/random_util.h"
#include "libs/entities/player.h"
#include "libs/enviro/game_map.h"

#define DIFFICULTY_EASY   0
#define DIFFICULTY_NORMAL 1
#define DIFFICULTY_HARD   2

// Maps constants (of course we need a system to "travel" preferably)
#define WAITING_AREA    0
#define SPAWN_AREA      1
#define UNKNOWN_VILLAGE 2

/**
 * Main game.
 */
class Game{
    private:
        void createPlayer();
        void setupMaps();

    public:
        int difficulty;
        Player* player;
        std::vector<GameMap*> maps;

        Game(int difficulty);

        void start();

        void updateMaps();

        void exitGame();
        void save();
        void load();
};

#endif