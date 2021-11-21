#ifndef MAN_PAGE_H
#define MAN_PAGE_H

#include <string>
#include "libs/enviro/commands/command_handlers.h"
#include "libs/enviro/game.h"
#include "libs/utils/colored_output.h"

void universalHeader(std::string cmd, std::string type){
    std::cout << "Manual command: "; ColoredOutput::blue(cmd) << "\n";
    std::cout << "Command Type  : "; ColoredOutput::blue(type) << "\n";
    std::cout << "Description   : ";
}

/**
 * @brief I know I can do this better, but time is a real constraint. 
 */
void showManual(std::string cmd){
    if(cmd == "start"){
        universalHeader(cmd, "start");
        std::cout << "Command used when a new game is created" << "\n";
    }else if(cmd == "exit" || cmd == "end" || cmd == "quit"){
        universalHeader(cmd, "base");
        std::cout << "Used when you want to exit game" << "\n";
    }else if(cmd == "save"){
        universalHeader(cmd, "base");
        std::cout << "Save current player statistics. Map stats are not saved for now." << "\n";
        std::cout << "It is yet to be implemented. It is not possible to save in battle." << "\n";
        std::cout << "See 'load' for loading data from a file." << "\n";
        std::cout << "\n";
        std::cout << "First parameter <filename> indicates the filename where the data" << "\n";
        std::cout << "will be saved. '.rtc' file extension will be automatically appended" << "\n";
        std::cout << "at the end of the filename. Hence, do not include any file extension." << "\n";
    }else if(cmd == "load"){
        universalHeader(cmd, "base");
        std::cout << "Load data from a file. It is not possible to load during a battle" << "\n";
        std::cout << "See 'save' manual to find out what data is being saved" << "\n";
        std::cout << "\n";
        std::cout << "First parameter <filename> indicates the filename where the data" << "\n";
        std::cout << "will be loaded. '.rtc' file extension will be automatically appended" << "\n";
        std::cout << "at the end of the filename. Hence, do not include any file extension." << "\n";
    }else if(cmd == "engage"){
        universalHeader(cmd, "base");
        std::cout << "Engage in a battle. But you need to be in a map where mobs will spawn." << "\n";
        std::cout << "Feel free to use 'wait' command to wait for mobs to spawn." << "\n";
    }else if(cmd == "enter"){
        universalHeader(cmd, "base");
        std::cout << "Enter a neighbor location / map" << "\n";
        std::cout << "\n";
        std::cout << "First parameter <index> indicates the neighbor index which you can find" << "\n";
        std::cout << "out using the 'where' command." << "\n";
    }else if(cmd == "unlock"){
        universalHeader(cmd, "base");
        std::cout << "Unlock a location / map. After you unlocked a map, the key stays." << "\n";
        std::cout << "If you wish to discard the key, use 'discard' command." << "\n";
        std::cout << "\n";
        std::cout << "First parameter <map_index> indicates the neighbor index which you can find" << "\n";
        std::cout << "out using the 'where' command." << "\n";
        std::cout << "Second parameter <key_index> indicates the inventory index of an item of" << "\n";
        std::cout << "a type 'key' which you can find out using the 'inventory' command." << "\n";
        std::cout << "The name of the key is going to let you know what map it can open." << "\n";
    }else if(cmd == "equip"){
        universalHeader(cmd, "base");
        std::cout << "Equip an item from inventory" << "\n";
        std::cout << "\n";
        std::cout << "First parameter <index> indicates the inventory index of an item" << "\n";
        std::cout << "you want to equip which you can find out using the 'inventory' command." << "\n";
    }else if(cmd == "use"){
        universalHeader(cmd, "base");
        std::cout << "Use an item from inventory" << "\n";
        std::cout << "\n";
        std::cout << "First parameter <index> indicates the inventory index of an item" << "\n";
        std::cout << "which you can find out using the 'inventory' command." << "\n";
    }else if(cmd == "buy"){
        universalHeader(cmd, "base");
        std::cout << "Buy an item from any shop. However, you need to be in a map of any shop." << "\n";
        std::cout << "\n";
        std::cout << "First parameter <index> indicates the shop inventory index of an item" << "\n";
        std::cout << "which you can find out using the 'shop' command." << "\n";
    }else if(cmd == "sell"){
        universalHeader(cmd, "base");
        std::cout << "Sell an item from your inventory. However, you need to be in a map of the" << "\n";
        std::cout << "right shop where the shop type corresponds to the item type which you" << "\n";
        std::cout << "want to sell." << "\n";
        std::cout << "\n";
        std::cout << "First parameter <index> indicates the inventory index of an item" << "\n";
        std::cout << "which you can find out using the 'inventory' command." << "\n";
    }else if(cmd == "discard"){
        universalHeader(cmd, "base");
        std::cout << "Discard an item from your inventory." << "\n";
        std::cout << "\n";
        std::cout << "First parameter <index> indicates the inventory index of an item" << "\n";
        std::cout << "which you can find out using the 'inventory' command." << "\n";
    }else if(cmd == "shop"){
        universalHeader(cmd, "base");
        std::cout << "Shows what the shop that you're currently in has to offer." << "\n";
    }else if(cmd == "wait"){
        universalHeader(cmd, "base");
        std::cout << "Wait for mobs to spawn." << "\n";
    }else if(cmd == "mapdesc"){
        universalHeader(cmd, "base");
        std::cout << "Shows the description of the current location / map. It " << "\n";
        std::cout << "will contain the story for the map as well. Guidance may" << "\n";
        std::cout << "also shown in the description." << "\n";
    }else if(cmd == "info"){
        universalHeader(cmd, "base");
        std::cout << "Shows information of your statistics and map / battle." << "\n";
        std::cout << "You may also use other commands to get information of the game." << "\n";
        std::cout << "For example, 'stat', 'inventory', 'where'." << "\n";
    }else if(cmd == "iteminfo"){
        universalHeader(cmd, "base");
        std::cout << "Shows the statistics of the item and it's type." << "\n";
        std::cout << "You can find out, for example, its physical damage" << "\n";
        std::cout << "physical resistance, whether its sellable and so on" << "\n";
        std::cout << "\n";
        std::cout << "First parameter <index> indicates the inventory index of an item" << "\n";
        std::cout << "which you can find out using the 'inventory' command." << "\n";
    }else if(cmd == "where"){
        universalHeader(cmd, "base");
        std::cout << "Shows information of the current map and neighboring maps." << "\n";
    }else if(cmd == "stat"){
        universalHeader(cmd, "base");
        std::cout << "Shows information of the player." << "\n";
    }else if(cmd == "skills"){
        universalHeader(cmd, "base");
        std::cout << "Shows information of the player's skills. Skills which are " << "\n";
        std::cout << "cooling down will also be shown, if any." << "\n";
    }else if(cmd == "inventory"){
        universalHeader(cmd, "base");
        std::cout << "Shows information of player's inventory." << "\n";
    }else if(cmd == "help"){
        universalHeader(cmd, "base");
        std::cout << "This is a command used when you want to see available commands." << "\n";
    }else if(cmd == "man"){
        universalHeader(cmd, "base");
        std::cout << "Manual page that gives information on what a command does and " << "\n";
        std::cout << "how to use the command." << "\n";
        std::cout << "\n";
        std::cout << "First parameter <cmd> indicates the command you want to search for." << "\n";
    }else if(cmd == "next"){
        universalHeader(cmd, "battle");
        std::cout << "End the current turn of this battle. One random enemy will attack you." << "\n";
    }else if(cmd == "disengage"){
        universalHeader(cmd, "battle");
        std::cout << "Disengage from the battle. However, enemies will be back on full " << "\n";
        std::cout << "hp and mana." << "\n";
    }else if(cmd == "attack"){
        universalHeader(cmd, "battle");
        std::cout << "Attack an enemy and end turn automatically." << "\n";
        std::cout << "\n";
        std::cout << "First parameter <index> indicates the enemy index which you" << "\n";
        std::cout << "can find out using the 'enemies' command during the battle." << "\n";
    }else if(cmd == "skill"){
        universalHeader(cmd, "battle");
        std::cout << "Activate a skill for one round, then it will be on cooldown." << "\n";
        std::cout << "\n";
        std::cout << "First parameter <index> indicates the skill index which you" << "\n";
        std::cout << "can find out using the 'skills' command during the battle." << "\n";
    }else if(cmd == "loot"){
        universalHeader(cmd, "battle");
        std::cout << "Get a loot from the battle." << "\n";
        std::cout << "\n";
        std::cout << "First parameter <index> indicates the loot index which you" << "\n";
        std::cout << "can find out using the 'loots' command during the battle." << "\n";
    }else if(cmd == "lootall"){
        universalHeader(cmd, "battle");
        std::cout << "Get all loots from the battle. If you want to loot an item" << "\n";
        std::cout << "at a time, use 'loot' instead." << "\n";
    }else if(cmd == "loots"){
        universalHeader(cmd, "battle");
        std::cout << "Show loots that are dropped on the battlefield." << "\n";
    }else if(cmd == "enemies"){
        universalHeader(cmd, "battle");
        std::cout << "Show enemies which you are currently engaged with." << "\n";
    }else{
        std::cout << "Cannot find command: "; ColoredOutput::blue(cmd) << "\n";
    }
}

#endif