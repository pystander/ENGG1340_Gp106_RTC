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
#define LOST_WOODS      3
#define DAWN_DUNGEON    4

/**
 * Main game.
 */
class Game{
    private:
        bool started = false;
        void createPlayer();
        void setupMaps();

    public:
        int difficulty;
        Player* player;
        std::vector<GameMap*> maps;

        Game(int difficulty);

        bool hasGameStarted();
        void gameStarted();
        
        void start();

        void updateMaps();

        void exitGame();

        // only player stat is saved
        void save();

        // only player stat can be loaded
        void load();
};

#endif