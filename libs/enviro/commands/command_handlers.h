#ifndef COMMAND_HANDLERS_H
#define COMMAND_HANDLERS_H

#include "libs/enviro/game.h"

//
// This header defines all command handlers for the commands.
// I know this is not a great way to handle commands, this
// semester is just packed with homeworks, crazy.
//
// Words from Vincent Ko
//

/**
 * @brief start a new game in the spawn area.
 */
void startGame(Game* game);

/**
 * @brief currently displays the info of the player 
 * and the info of the current location
 */
void printInfo(Game* game);

/**
 * @brief [normal] display a list of available commands
 */
void helpBase(Game* game);

/**
 * @brief [temporary] enter a battle area (UnknownVillage)
 */
void battle(Game* game);

/**
 * @brief [normal] move around the map
 */
void move(Game* game);

/**
 * @brief [normal] engage in a battle in the current location.
 */
void engage(Game* game);

/**
 * @brief [engaged] flee the battle 
 */
void disengage(Game* game);

/**
 * @brief [engaged] allow the game to update and spawn mobs
 */
void gameWait(Game* game);

/**
 * @brief [engaged] attack an enemy
 */
void attackEnemy(Game* game, GameMatch* battle, int index);

/**
 * @brief [engaged] get a list of available commands
 */
void helpBattle(Game* game);

#endif