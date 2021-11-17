#include <iostream>
#include "libs/enviro/commands/command_handlers.h"
#include "libs/utils/colored_output.h"

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

void lootItem(Game* game, GameMatch* battle, int index){
    battle->loot(game->player, index);
}

void lootAllItems(Game* game, GameMatch* battle){
    battle->lootAll(game->player);
}

void showLoots(Game* game, GameMatch* battle){
    battle->displayLoots();
}

void helpBattle(Game* game){
    ColoredOutput::blue("Available commands while in battle:\n");
    std::cout << "next" << "\n";
    std::cout << "disengage" << "\n";
    std::cout << "attack <index>" << "\n";
    std::cout << "use <index>" << "\n";
    std::cout << "loot <index>" << "\n";
    std::cout << "lootall" << "\n";
    std::cout << "loots" << "\n";
    std::cout << "info" << "\n";
    std::cout << "enemies" << "\n";
    std::cout << "stat" << "\n";
    std::cout << "inventory" << "\n";
    std::cout << "help" << "\n";
    std::cout << "man <cmd>" << "\n";
}