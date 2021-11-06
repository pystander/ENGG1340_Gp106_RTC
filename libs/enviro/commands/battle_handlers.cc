#include <iostream>
#include "libs/enviro/commands/command_handlers.h"

void disengage(Game* game){
    std::cout << "Leaving battlefield\n";
    if(game->player->isInBattle())
        game->player->disengage();
}

void attackEnemy(Game* game, GameMatch* battle, int index){
    battle->attack(game->player, index);
}

void helpBattle(Game* game){
    std::cout << "Available commands while in battle:\n";
    std::cout << "next" << "\n";
    std::cout << "disengage" << "\n";
    std::cout << "attack" << "\n";
    std::cout << "info" << "\n";
    std::cout << "help" << "\n";
}