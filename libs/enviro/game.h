#ifndef GAME_H
#define GAME_H

class Game;

#include <stdlib.h>
#include <vector>
#include <string>
#include "libs/utils/random_util.h"
#include "libs/entities/player.h"
#include "libs/enviro/game_map.h"

#define DIFFICULTY_EASY   0
#define DIFFICULTY_NORMAL 1
#define DIFFICULTY_HARD   2

// Maps constants (of course we need a system to "travel" preferably)
#define WAITING_AREA    0
#define SPAWN_AREA      1

/**
 * Main game.
 */
class Game{
    private:
        bool started = false;
        void createPlayer();
        void setupMaps();
        void setupDifficulty();

    public:
        int difficulty;
        Player* player = nullptr;
        std::vector<GameMap*> maps;

        Game(int difficulty);

        bool hasGameStarted();
        void gameStarted();
        
        void start();

        void updateMaps();

        void exitGame();

        /**
         * @brief only player stat is saved (because of time constraint)
         * 
         * File structure (all case-sensitive):
         * [start]
         * [player]
         * <player data defined in Player::save()>
         * [end]
         */
        void save(std::string filename);

        // only player stat can be loaded
        void load(std::string filename);
};

#endif