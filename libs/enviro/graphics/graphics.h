#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "libs/enviro/game.h"

/*
This header defines all function prototypes for text graphics.
Isn't it interesting to add some visual elements in a text-based game?

Words from Rain Leung
*/

/**
 * @brief display game start screen
 */
void displayStart(Game* game);

/**
 * @brief display the graphics for boss - Fire Dragon
 */
void displayFireDragon(Game* game);

/**
 * @brief display the graphics for boss - The Lich King
 */
void displayLichKing(Game* game);

/**
 * @brief display the graphics for boss - The Magician
 */
void displayMagician(Game* game);

#endif