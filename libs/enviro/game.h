#ifndef GAME_H
#define GAME_H

class Game;

#include <vector>
#include "libs/utils/random_util.h"
#include "libs/entities/player.h"
#include "libs/enviro/game_map.h"

#define DIFFICULTY_EASY   0
#define DIFFICULTY_Normal 1
#define DIFFICULTY_HARD   2

/**
 * Main game.
 */
class Game{
    private:
        int difficulty;
        Player* player;
        std::vector<GameMap*> maps;

        void createPlayer();
        void setupMaps();

    public:
        Game(int difficulty);

        // [blocking] Start game
        void start();
};

#endif