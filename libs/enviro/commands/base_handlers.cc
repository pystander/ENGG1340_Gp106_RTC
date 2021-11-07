#include <iostream>
#include <string>
#include "libs/enviro/commands/command_handlers.h"
#include "libs/enviro/game.h"

void startGame(Game* game){
    game->player->enter(game->maps[SPAWN_AREA]);
}

void battle(Game* game){
    game->updateMaps();
    game->player->enter(game->maps[UNKNOWN_VILLAGE]);
}

void move(Game* game){
    // move logic, preferably from one map move to another map
    // no teleporting?
    //
    //Temporarily use battle();
}

void useItem(Game* game, int index){
    game->player->useItem(game->player->getInventory()[index]);
}

void engage(Game* game){
    GameMatch* battle = game->player->engage();
    bool status = battle->start();
    if(!status){
        std::cout << "Cannot engage in a battle in " << game->player->getCurrentLoc()->getName() << "\n";
        return;
    }
    std::cout << "Successfully engaged into a battle\n";
    battle->displayInfo();

    int index;
    std::string userInput;
    while(game->player->isInBattle()){
        // stuck inside this loop until disenge() or lose
        std::cout << game->player->getCurrentLoc()->getName() << "(Battle) >> ";
        std::cin >> userInput;
        if(userInput == "attack"){
            std::cin >> index;
            attackEnemy(game, battle, index);
        }else if(userInput == "disengage"){
            disengage(game);
            break;
        }else if(userInput == "use"){
            std::cin >> index;
            useItem(game, index);
        }else if(userInput == "next"){
            battle->endTurn();
        }else if(userInput == "help"){
            helpBattle(game);
        }else if(userInput == "info"){
            game->player->displayPlayerStatus();
            battle->displayInfo();
        }else if(userInput == "inventory"){
            printInventory(game);
        }
    }
}

void gameWait(Game* game){
    std::cout << "You chose to take a rest\n";
    game->updateMaps();
}

void printInfo(Game* game){
    game->player->displayPlayerStatus();
    game->player->getCurrentLoc()->displayInfo();
}

void printInventory(Game* game){
    game->player->displayInventory();
}

void helpBase(Game* game){
    std::cout << "Available commands normally:\n";
    if(game->player->getCurrentLoc() == game->maps[WAITING_AREA])
        std::cout << "start" << "\n";
    std::cout << "battle" << "\n";
    std::cout << "engage" << "\n";
    std::cout << "use <index>" << "\n";
    std::cout << "wait" << "\n";
    std::cout << "inventory" << "\n";
    std::cout << "info" << "\n";
    std::cout << "help" << "\n";
}