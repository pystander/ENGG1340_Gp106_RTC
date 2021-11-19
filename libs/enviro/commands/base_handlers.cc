#include <iostream>
#include <string>
#include "libs/enviro/commands/command_handlers.h"
#include "libs/enviro/game.h"
#include "libs/utils/basic_converter.h"
#include "libs/utils/colored_output.h"

void startGame(Game* game){
    if(!game->hasGameStarted()){
        game->player->forceEnter(game->maps[SPAWN_AREA]);
        game->gameStarted();
    }
}

void buyItem(Game* game, int index){
    game->player->buyItem(index);
}

void sellItem(Game* game, int index){
    game->player->sellItem(index);
}

void discardItem(Game* game, int index){
    GameItem* item = game->player->getFromInventory(index);
    // You cannot discard "Hands" (index 0 by default)
    if(index > 0 && item != nullptr){
        std::cout << "Successfully deleted item: "; ColoredOutput::green(item->getName()) << "\n"; 
        game->player->deleteItem(item);
    }else{
        std::cout << "Cannot delete item with index: "; ColoredOutput::green(index) << "\n";
    }
}

void enterLoc(Game* game, int index){
    GameMap* map = game->player->getCurrentLoc()->getNeighborByIndex(index);
    if(map != nullptr){
        game->updateMaps();
        game->player->enter(map);
    }else{
        std::cout << "Cannot find neighbor with index: "; ColoredOutput::green(index) << "\n";
    }
}

void unlockLoc(Game* game, int mapIndex, int keyIndex){
    GameMap* map = game->player->getCurrentLoc()->getNeighborByIndex(mapIndex);
    if(map != nullptr){
        GameItem* item = game->player->getFromInventory(keyIndex);
        if(item != nullptr){
            game->player->unlockMap(map, item);
        }else{
            std::cout << "Cannot unlock map with item of index: "; ColoredOutput::green(keyIndex) << "\n";
        }
    }else{
        std::cout << "Cannot find neighbor with index: "; ColoredOutput::green(mapIndex) << "\n";
    }
}

void equipItem(Game* game, int index){
    GameItem* item = game->player->getFromInventory(index);
    if(item != nullptr){
        game->player->equipItem(item);
    }else{
        std::cout << "Cannot use item with index: "; ColoredOutput::green(index) << "\n";
    }
}

void useItem(Game* game, int index){
    GameItem* item = game->player->getFromInventory(index);
    if(item != nullptr){
        game->player->useItem(item);
    }else{
        std::cout << "Cannot use item with index: "; ColoredOutput::green(index) << "\n";
    }
}

void engage(Game* game){
    GameMatch* battle = game->player->engage();
    bool status = battle->start();
    if(!status){
        std::cout << "Cannot engage in a battle in "; ColoredOutput::green(game->player->getCurrentLoc()->getName()) << "\n";
        return;
    }
    std::cout << "Successfully engaged into a battle\n";
    battle->displayInfo();

    std::string userInput;
    std::string arg1;
    while(game->player->isInBattle()){
        // [engaged] commands
        // stuck inside this loop until disengage() or lose or all dead
        ColoredOutput::red(game->player->getCurrentLoc()->getName()) << "(Battle) >> ";
        std::cin >> userInput;
        if(userInput == "attack"){
            std::cin >> arg1;
            attackEnemy(game, battle, BasicConverter::safeToInt(arg1));
        }else if(userInput == "disengage"){
            disengage(game);
            break;
        }else if(userInput == "use"){
            std::cin >> arg1;
            useItem(game, BasicConverter::safeToInt(arg1));
        }else if(userInput == "skill"){
            std::cin >> arg1;
            useSkill(game, BasicConverter::safeToInt(arg1));
        }else if(userInput == "loot"){
            std::cin >> arg1;
            lootItem(game, battle, BasicConverter::safeToInt(arg1));
        }else if(userInput == "lootall"){
            lootAllItems(game, battle);
        }else if(userInput == "loots"){
            showLoots(game, battle);
        }else if(userInput == "next"){
            battle->endTurn();
        }else if(userInput == "help"){
            helpBattle(game);
        }else if(userInput == "info"){
            game->player->displayPlayerStatus();
            battle->displayInfo();
        }else if(userInput == "enemies"){
            battle->displayInfo();
        }else if(userInput == "stat"){
            game->player->displayPlayerStatus();
        }else if(userInput == "skills"){
            game->player->displaySkills();
        }else if(userInput == "inventory"){
            printInventory(game);
        }

        if(game->player->isDead())
            return;
    }
}

void gameWait(Game* game){
    std::cout << "You chose to take a rest\n";
    game->updateMaps();
}

void printMapDescription(Game* game){
    game->player->getCurrentLoc()->displayDescription();
}

void printInventory(Game* game){
    game->player->displayInventory();
}

void printShopItems(Game* game){
    GameMap* currentLoc = game->player->getCurrentLoc();
    currentLoc->displayShopItems();
}

void helpBase(Game* game){
    ColoredOutput::blue("Available commands normally:\n");
    if(!game->hasGameStarted()){
        std::cout << "start" << "\n";
        std::cout << "load <filename>" << "\n";
        std::cout << "exit" << "\n";
        std::cout << "end" << "\n";
        std::cout << "quit" << "\n";
        std::cout << "help" << "\n";
        std::cout << "man <cmd>" << "\n";
    }else{
        std::cout << "engage" << "\n";
        std::cout << "enter <index>" << "\n";
        std::cout << "unlock <map_index> <key_index>" << "\n";
        std::cout << "equip <index>" << "\n";
        std::cout << "use <index>" << "\n";
        std::cout << "buy <index>" << "\n";
        std::cout << "sell <index>" << "\n";
        std::cout << "discard <index>" << "\n";
        std::cout << "shop" << "\n";
        std::cout << "wait" << "\n";
        std::cout << "mapdesc" << "\n";
        std::cout << "info" << "\n";
        std::cout << "where" << "\n";
        std::cout << "stat" << "\n";
        std::cout << "skills" << "\n";
        std::cout << "inventory" << "\n";
        std::cout << "help" << "\n";
        std::cout << "exit" << "\n";
        std::cout << "end" << "\n";
        std::cout << "quit" << "\n";
        std::cout << "save <filename>" << "\n";
        std::cout << "load <filename>" << "\n";
        std::cout << "man <cmd>" << "\n";
    }
}