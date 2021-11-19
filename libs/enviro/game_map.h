#ifndef GAME_MAP_H
#define GAME_MAP_H

class GameMap;

#include <string>
#include <vector>
#include <set>
#include "libs/entities/character.h"

#define NOT_SHOP         1 << 0 // 0b0001
#define SHOP_WEAPON      1 << 1 // 0b0010
#define SHOP_ARMOR       1 << 2 // 0b0100
#define SHOP_CONSUMABLES 1 << 3 // 0b1000

class GameMap{
    protected:
        std::vector<GameCharacter*> enemies;
        std::set<GameMap*> neighbors;
        std::string name;
        std::string description;
        int difficulty;
        int maxEnemyReserve;
        double enemySpawnRate;
        
        bool locked = false;
        bool peaceful = false;
        std::string keyName = ""; // used when the map is locked

        // For shops
        int shopType = NOT_SHOP;           // eg. NOT_SHOP for being not a shop.
        std::vector<GameItem*> itemsOnSold;

    public:
        bool hasComeHereBefore = false;

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

        bool isLocked();
        bool isPeaceful();
        void lock();
        // returns whether the unlock is successful or not
        bool unlock(GameItem* key);

        int getDifficulty();
        int getShopType();
        // index from of itemsOnSold
        void buyItem(GameCharacter* buyer, int index);
        // index of inventory
        void sellItem(GameCharacter* seller, int index);

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
        void displayShopItems();
        void displayDescription();
};

#endif