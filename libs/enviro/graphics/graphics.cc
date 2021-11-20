#include <iostream>
#include <iomanip>
#include "libs/enviro/graphics/graphics.h"
#include "libs/enviro/game.h"

void displayStart(Game* game){
    // ASCII art from https://fsymbols.com/generators/carty/
    std::cout << "================================================================" << std::endl;
    std::cout << "▀█▀ █░█ █▀▀   █▀█ █▀█ ▄▀█ █▀▄   ▀█▀ █▀█   █▀▀ ▄▀█ █▀ ▀█▀ █░░ █▀▀" << std::endl;
    std::cout << "░█░ █▀█ ██▄   █▀▄ █▄█ █▀█ █▄▀   ░█░ █▄█   █▄▄ █▀█ ▄█ ░█░ █▄▄ ██▄" << std::endl;
    std::cout << "================================================================" << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(45) << "A text-based Fantasy RPG" << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(49) << "Press any key to start the game" << std::endl;
    getchar();
}

void displayMap(Game* game){
    std::cout << "+-----------+     +----------+     +---------------+     +-------------------+"  << std::endl;
    std::cout << "|Weapon Shop|-----|Spawn Area|-----|Unknown Village|-----|Dungeon of the Dawn|"  << std::endl;
    std::cout << "+-----------+    /+----------+     +---------------+     +-------------------+"  << std::endl;
    std::cout << "                /       |                    |                     |"            << std::endl;
    std::cout << "+----------+   / +---------------+    +--------------+       +----------+"      << std::endl;
    std::cout << "|Armor Shop|---  |Consumable Shop|    |The Lost Woods|       |The Castle|"      << std::endl;
    std::cout << "+----------+     +---------------+    +--------------+       +----------+"      << std::endl;
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