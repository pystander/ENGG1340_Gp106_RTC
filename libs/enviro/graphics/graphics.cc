#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "libs/enviro/graphics/graphics.h"
#include "libs/enviro/game.h"

std::string repeatString(std::string str, int amount){
    std::string result = "";
    for(int i = 0; i < amount; i++){
        result += str;
    }
    return result;
}

void printTable(std::vector<std::string> content){
    int longestLength = 0;
    for(int i = 0; i < content.size(); i++){
        if(content[i].length() > longestLength){
            longestLength = content[i].length();
        }
    }
    std::string printStr = "";
    std::string cellContent = "";
    // upper frame
    if(content.size() >= 2){
        printStr += "┌" + repeatString("─", longestLength) + "";
        printStr += "┬" + repeatString("─", longestLength) + "┐\n";
    }else{
        printStr += "┌" + repeatString("─", longestLength) + "┐\n";
    }
    for(int i = 0; i < content.size(); i++){
        // left cell
        cellContent = content[i];
        cellContent += repeatString(" ", longestLength-cellContent.length());
        printStr += "│" + cellContent + "";
        if(i+1 < content.size()){
            // right
            cellContent = content[i+1];
            cellContent += repeatString(" ", longestLength-cellContent.length());
            printStr += "│" + cellContent + "│\n";
            i++;
        }else{
            // right empty
            cellContent = "";
            cellContent += repeatString(" ", longestLength-cellContent.length());
            printStr += "│" + cellContent + "│\n";
        }
    }
    // lower frame
    if(content.size() >= 2){
        printStr += "└" + repeatString("─", longestLength) + "";
        printStr += "┴" + repeatString("─", longestLength) + "┘\n";
    }else{
        printStr += "└" + repeatString("─", longestLength) + "┘\n";
    }
    std::cout << printStr;
}

void displayStart(Game* game){
    // ASCII art from https://fsymbols.com/generators/carty/
    std::cout << "================================================================" << std::endl;
    std::cout << "▀█▀ █░█ █▀▀   █▀█ █▀█ ▄▀█ █▀▄   ▀█▀ █▀█   █▀▀ ▄▀█ █▀ ▀█▀ █░░ █▀▀" << std::endl;
    std::cout << "░█░ █▀█ ██▄   █▀▄ █▄█ █▀█ █▄▀   ░█░ █▄█   █▄▄ █▀█ ▄█ ░█░ █▄▄ ██▄" << std::endl;
    std::cout << "================================================================" << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(45) << "A text-based Fantasy RPG" << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(48) << "Press ENTER to start the game" << std::endl;
    getchar();
}

void displayMap(Game* game){
    std::cout << "             ┌───────────────┐ ┌──────────────┐                        " << "\n";
    std::cout << "             │Consumable Shop│ │The Lost Woods│                        " << "\n";
    std::cout << "             └───────────────┘ └──────────────┘                        " << "\n";
    std::cout << "                     ⇧                ⇧                                " << "\n";
    std::cout << "┌──────────┐   ┌──────────┐   ┌───────────────┐   ┌───────────────────┐" << "\n";
    std::cout << "│Armor Shop│---│Spawn Area│---│Unknown Village│---│Dungeon of the Dawn│" << "\n";
    std::cout << "└──────────┘   └──────────┘   └───────────────┘   └───────────────────┘" << "\n";
    std::cout << "                     ⇩                                      ⇩          " << "\n";
    std::cout << "               ┌───────────┐         ┌──────────┐   ┌───────────────┐  " << "\n";
    std::cout << "               │Weapon Shop│         │The Castle|---│Castle Entrance│  " << "\n";
    std::cout << "               └───────────┘         └──────────┘   └───────────────┘  " << "\n";
}

void displayFireDragon(Game* game){
    // ASCII art from https://www.asciiart.eu/mythology/dragons, modified
    std::cout << "                                             __----~~~~~~~~~~~------___"      << std::endl;
    std::cout << "                                  .  .   ~~//====......          __--~ ~~"    << std::endl;
    std::cout << "                  -.            _|//     |||\\  ~~~~~~::::... /~"             << std::endl;
    std::cout << "               ___-==_       _-~o~  /    |||  \\            _/~~-"            << std::endl;
    std::cout << "       __---~~~.==~||/=_    -_--~/_-~|-   |\\   \\        _/~"                << std::endl;
    std::cout << "   _-~~     .=~    |  \\-_    '-~7  /-   /  ||    /      /"                   << std::endl;
    std::cout << " .~       .~       |   \\ -_    /  /-   /   ||      /   /"                    << std::endl;
    std::cout << "/  ____  /         |     \\ ~-_/  /|- _/   .||       / /"                     << std::endl;
    std::cout << "|~~    ~~|--~~~~--_ /     ~==-/   | /~--===~~        .\""                     << std::endl;
    std::cout << "         '         ~-|      /|    |-~/~~       __--~~"                        << std::endl;
    std::cout << "                     |-~~-_/ |    |   ~/_   _-~            /\""               << std::endl;
    std::cout << "                          /  /     /__   //~                /__"              << std::endl;
    std::cout << "                      _--~ _/ | .-~~____--~-/                  ~~==."         << std::endl;
    std::cout << "                     ((->/~   '.|||' -_|    ~~-/ ,              . _||"        << std::endl;
    std::cout << "                                -_     ~/      ~~---l__i__i__i--~~_/"         << std::endl;
    std::cout << "                                _-~-__   ~)  /--______________--~~"           << std::endl;
    std::cout << "                              //.-~~~-~_--~- |-------~~~~~~~~"                << std::endl;
    std::cout << "                                     //.-~~~--\""                             << std::endl;
}

void displayLichKing(Game* game){
    // ASCII art from https://www.asciiart.eu/people/occupations/knights, modified
    std::cout << "      _,."                    << std::endl;
    std::cout << "    ,` -.)"                   << std::endl;
    std::cout << "   ( _/-\\-._"                << std::endl;
    std::cout << "  /,|`--._,-^|           ,"   << std::endl;
    std::cout << "  /_| |`-._/||         ,'|"   << std::endl;
    std::cout << "    |  `-, / |        /  /"   << std::endl;
    std::cout << "     `r-._||/   __   /  /"    << std::endl;
    std::cout << " __,-<_     )`-/  `./  /"     << std::endl;
    std::cout << "'  |   `---'   |   /  /"      << std::endl;
    std::cout << "    |           |./  /"       << std::endl;
    std::cout << "    /           //  /"        << std::endl;
    std::cout << "__/' |         |/  /"         << std::endl;
    std::cout << " |    |   _,^-'/  /"          << std::endl;
    std::cout << " |    , ``   _/  /_"          << std::endl;
    std::cout << "  |,.->._   ((_O_)/"          << std::endl;
    std::cout << "  (  /   `-._//^`"            << std::endl;
    std::cout << "   `Y-.____(__}"              << std::endl;
    std::cout << "    |     {__)"               << std::endl;
    std::cout << "          //"                 << std::endl;
}

void displayMagician(Game* game){
    // ASCII art from https://www.asciiart.eu/people/occupations/wizards by Morfina, modified
    std::cout << "                    ____ '"               << std::endl;
    std::cout << "                  .'* *.'"                << std::endl;
    std::cout << "               __/_*_*(_"                 << std::endl;
    std::cout << "              / _______ /"                << std::endl;
    std::cout << "             _/_)/___/(_/_ "              << std::endl;
    std::cout << "            / _((/- -/))_ /"              << std::endl;
    std::cout << "            / /())(-)(()/ /"              << std::endl;
    std::cout << "             ' /(((()))/ '"               << std::endl;
    std::cout << "            / ' /)).))/ ' /"              << std::endl;
    std::cout << "           / _ / - | - /_  /"             << std::endl;
    std::cout << "          (   ( .;''';. .'  )"            << std::endl;
    std::cout << "          _/'__ /    )/ __'/_"            << std::endl;
    std::cout << "            //  /   ' /  //"              << std::endl;
    std::cout << "             .'  '...' ' )"               << std::endl;
    std::cout << "              / /  |  / /"                << std::endl;
    std::cout << "             / .   .   . /"               << std::endl;
    std::cout << "            /   .     .   /"              << std::endl;
    std::cout << "           /   /   |   /   /"             << std::endl;
    std::cout << "         .'   /    /    '.  '."           << std::endl;
    std::cout << "     _.-'    /     //     '-. '-._"       << std::endl; 
    std::cout << " _.-'       |      ///       '-.  '-. "   << std::endl;
    std::cout << "(________////____./////.________)____)"   << std::endl;
}