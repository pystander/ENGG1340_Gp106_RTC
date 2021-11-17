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
 * @brief [start] start a new game in the spawn area.
 */
void startGame(Game* game);

/**
 * @brief [normal, engaged] 
 */
void printInventory(Game* game);

/**
 * @brief [normal] print shop items
 */
void printShopItems(Game* game);

/**
 * @brief [normal] display a list of available commands
 */
void helpBase(Game* game);

/**
 * @brief [normal] buy item from a shop 
 */
void buyItem(Game* game, int index);

/**
 * @brief [normal] sell item from inventory 
 */
void sellItem(Game* game, int index);

/**
 * @brief [normal] sell item from inventory 
 */
void discardItem(Game* game, int index);

/**
 * @brief [normal] move around the map
 */
void enterLoc(Game* game, int index);

/**
 * @brief [normal] unlock map
 */
void unlockLoc(Game* game, int mapIndex, int keyIndex);

/**
 * @brief [normal, engaged] use an item 
 */
void useItem(Game* game, int index);

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
 * @brief [engaged] loot in the battle field
 */
void lootItem(Game* game, GameMatch* battle, int index);

/**
 * @brief [engaged] loot all items in the battle field
 */
void lootAllItems(Game* game, GameMatch* battle);

/**
 * @brief [engaged] show loots
 */
void showLoots(Game* game, GameMatch* battle);

/**
 * @brief [engaged] get a list of available commands
 */
void helpBattle(Game* game);

/**
 * @brief [normal, engaged] get manual of a specified command
 * 
 * See ./man_pagge.h
 */
void showManual(std::string cmd);

#endif