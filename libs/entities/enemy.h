#ifndef ENEMY_H
#define ENEMY_H

class Enemy;

#include <string>
#include "libs/entities/character.h"

class Enemy : public GameCharacter{
    public:
        Enemy(std::string name);
};

#endif