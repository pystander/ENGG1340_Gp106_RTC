#ifndef GAME_MAP_H
#define GAME_MAP_H

class GameMap;

#include <string>
#include <vector>
#include <set>
#include "libs/entities/character.h"

class GameMap{
    protected:
        std::vector<GameCharacter*> enemies;
        std::set<GameMap*> neighbors;
        std::string name;
        int maxEnemyReserve;
        double enemySpawnRate;

    public:
        // spawn rate is defined inside the constructor
        GameMap(std::string name, int difficulty);
        ~GameMap(){
            for(int i = 0; i < this->enemies.size(); i++)
                delete this->enemies[i];
        }
        
        // bi-direction connect operation
        void connectTo(GameMap* nextMap);
        bool canGetTo(GameMap* nextLoc);

        std::string getName();

        // Will return 1-3 enemies, 0 if none
        std::vector<GameCharacter*> getSomeEnemies();
        std::set<GameMap*> getNeighbors();
        GameMap* getNeighborByIndex(int);

        /**
         * Spawn random mobs
         * @return GameCharacter* nullptr if the map is peaceful.
         */
        virtual GameCharacter* spawnRandomMobs() = 0;
        void setEnemySpawnRate(double);

        /**
         * called after a round has ended
         * should create new mobs inside the map
         */
        void update();
        void cleanCorpse(); // will delete dead enemies
        void displayInfo();
        void displayNeighbors();
};

#endif