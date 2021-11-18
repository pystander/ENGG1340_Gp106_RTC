#ifndef STORY_H
#define STORY_H

#include "libs/enviro/game.h"

/**
 * @brief display the starting story lines
 */
void startStory(Game* game);

/**
 * @brief display the ending if player walks through the game
 */
void endingStory(Game* game);

#endif