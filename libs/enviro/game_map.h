#ifndef GAME_MAP_H
#define GAME_MAP_H

class GameMap;

#include "libs/entities/character.h"

class GameMap{
    private:
        std::vector<GameCharacter*> enemies;
        int maxEnemyReserve;
        double enemySpawnRate;

    public:
        GameMap(int difficulty);

        /**
         * called after a round has ended
         * should create new mobs inside the map
         */
        void update();
        
        void displayInfo();
};

#endif