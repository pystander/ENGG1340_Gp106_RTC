#include <iostream>
#include "libs/enviro/commands/command_handlers.h"

void disengage(Game* game){
    std::cout << "Leaving battlefield\n";
    if(game->player->isInBattle()){
        game->player->getRecentMatch()->end();
    }
}

void attackEnemy(Game* game, GameMatch* battle, int index){
    battle->attackEnemy(game->player, index);
    battle->cleanCorpse();
}

void helpBattle(Game* game){
    std::cout << "Available commands while in battle:\n";
    std::cout << "next" << "\n";
    std::cout << "disengage" << "\n";
    std::cout << "attack <index>" << "\n";
    std::cout << "use <index>" << "\n";
    std::cout << "inventory" << "\n";
    std::cout << "info" << "\n";
    std::cout << "help" << "\n";
}