#ifndef SPAWN_AREA_H
#define SPAWN_AREA_H

#include "libs/enviro/game_map.h"
#include "libs/entities/enemies/weaker_enemies.h"
#include "libs/entities/enemies/bosses.h"

// Visual elements and stories match perfectly

class UnknownVillage : public GameMap{
    public:
        UnknownVillage(int difficulty) : GameMap("Unknown Village", difficulty){
            this->peaceful = false;

            // Text description
            this->description = "This seems to be an abandoned village, nothing special.\n";
            this->description += "But the broken walls and windows remind you to be careful.\n";
            this->description += "You hear a few sharp noises coming from the woods,\n";
            this->description += "and the sound suddenly vanished, just like hallucinations.\n";
            this->description += "\n";

            // Graphical description
            // ASCII art from https://ascii.co.uk/art/forest, by ejm96, modified
            // May seem a little bit broken as escape character (\) is used
            this->description += " ^  ^  ^   ^      ___I_      ^  ^   ^  ^  ^   ^  ^\n";
            this->description += "/|\\/|\\/|\\ /|\\    /\\-_--\\    /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n";
            this->description += "/|\\/|\\/|\\ /|\\   /  \\_-__\\   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n";
            this->description += "/|\\/|\\/|\\ /|\\   |[]| [] |   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n";
            this->description += "\n";

            // see map_keys.h for reference
            this->keyName = "Unknown Village Key";
            this->lock();
        };

        GameCharacter* spawnRandomMobs(){
            Random rng = Random(0, 1);
            if(rng.getFloat() < 0.5){
                return new Goblin();
            }
            return new Wolf();
        }
};

class LostWoods : public GameMap{
    public:
        LostWoods(int difficulty) : GameMap("The Lost Woods", difficulty){
            this->peaceful = false;

            // Text description
            this->description = "You step into the forest with bravery.\n";
            this->description += "The Woods is always covered with a heavy mist,\n";
            this->description += "and most travellers eventually end up losing their directions.\n";
        };

        GameCharacter* spawnRandomMobs(){
            Random rng = Random(0, 1);
            if(rng.getFloat() < 0.5){
                return new DarkFairy();
            }
            return new Dryad();
        }
};

class DawnDungeon : public GameMap{
    public:
        DawnDungeon(int difficulty) : GameMap("Dungeon of the Dawn", difficulty){
            this->peaceful = false;

            // Text description
            this->description = "The gate in front of you is rotten, opening it would be effortful.\n";
            this->description += "You push the gate so hard, that finally it fell down.\n";
            this->description += "You gradually walk down to the dungeon entrance.\n";
            this->description += "You see empty cells and cages, blood stains on floor.\n";
            this->description += "All of a sudden, your back and neck feel like freezing.\n";
            this->description += "\n";

            // Graphical description
            // ASCII art from https://ascii.co.uk/art/dungeon, modified
            this->description += "   _________________________________________________________\n";
            this->description += " /|     -_-                 -__                         _-  |\\\n";
            this->description += "/ |                      -_    _-  _--                      | \\\n";
            this->description += "  | -_   .-'````````'.        '(`        .-'```````'-.      |\n";
            this->description += "  |    .` |           `. -_   `)'      .` |           `.    |\n";
            this->description += "  |   /   |   ()        \\      U      /   |    ()       \\   |\n";
            this->description += "  |  |    |     ;        |  .  |  .  |    |    ;         |  |\n";
            this->description += "  |  |    |____;_________|     |     |    |____;_________|  |\n";
            this->description += "  |  |   /  __ ;   -     |     !     |   /     `'() _ -  |  |\n";
            this->description += "  |  |  / __  ()        -|        -  |  /  __--      -   |  |\n";
            this->description += "  |  | /        __-- _   |   _- _ -  | /        __--_    |  |\n";
            this->description += "  |__|/__________________|___________|/__________________|__|\n";
            this->description += "/   -_- _ -             _- _---                       -_-  -_ \\\n";
        };

        GameCharacter* spawnRandomMobs(){
            Random rng = Random(0, 1);
            if(rng.getFloat() < 0.3){
                return new Zombie();
            }
            return new Spirit();
        }
};

class CastleEntrance : public GameMap{
    public:
        CastleEntrance(int difficulty) : GameMap("The Castle Entrance", difficulty){
            this->peaceful = false;

            // Text description
            this->description = "Passed through the Dungeon, you finally reach to The Castle\n";
            this->description += "This is where the Prophecy guided you to, where all it ends.\n";
            this->description += "You see lots of armored warriors and monsters outside the Castle.\n";
            this->description += "Seems like you need to have a tough fight before getting inside.\n";
            this->description += "\n";

            // Graphical description
            // ASCII art from https://www.asciiart.eu/buildings-and-places/castles, modified
            this->description += "                                  |>>>\n";
            this->description += "                                  |\n";
            this->description += "                    |>>>      _  _|_  _         |>>>\n";
            this->description += "                    |        |;| |;| |;|        |\n";
            this->description += "                _  _|_  _    \\.    .   /    _  _|_  _\n";
            this->description += "               |;|_|;|_|;|    \\:. ,   /    |;|_|;|_|;|\n";
            this->description += "               \\..      /     ||;   . |    \\.    .  /\n";
            this->description += "                \\.  ,  /      ||:  .  |     \\:  .  /\n";
            this->description += "                 ||:   |_   _ ||_ . _ | _   _||:   |\n";
            this->description += "                 ||:  .|||_|;|_|;|_|;|_|;|_|;||:.  |\n";
            this->description += "                 ||:   ||.    .     .      . ||:  .|\n";
            this->description += "                 ||: . || .     . .   .  ,   ||:   |       \\,/\n";
            this->description += "                 ||:   ||:  ,  _______   .   ||: , |            /`\\\n";
            this->description += "                 ||:   || .   /+++++++\\    . ||:   |\n";
            this->description += "                 ||:   ||.    |+++++++| .    ||: . |\n";
            this->description += "              __ ||: . ||: ,  |+++++++|.  . _||_   |\n";
            this->description += "     ____--`~    '--~~__|.    |+++++__|----~    ~`---,              ___\n";
            this->description += "-~--~                   ~---__|,--~'                  ~~----_____-~'   `~---~~\n";
        };

        GameCharacter* spawnRandomMobs(){
            return new FireDragon();
        }
};

class Castle_1F : public GameMap{
    public:
        Castle_1F(int difficulty) : GameMap("The Castle - 1/F", difficulty){
            this->peaceful = false;

            // Text description
            this->description = "You kill the monster guards outside and get into the Castle.\n";
            this->description += "You see a... a Dragon!\n";
            this->description += "Luckily, the dragon is be sleeping, but it blocks the way upstairs.\n";
            this->description += "If you want to go up, seems you need to defeat it.\n";
            this->description += "\n";

            // Graphical description
            // ASCII art from https://ascii.co.uk/art/dragon, by SSt, modified
            this->description += "                                                       ____________\n";
            this->description += "                                 (`-..________....---''  ____..._.-`\n";
            this->description += "                                  \\`._______.._,.---'''     ,'\n";
            this->description += "                                  ; )`.      __..-'`-.      /\n";
            this->description += "                                 / /     _.-' _,.;;._ `-._,'\n";
            this->description += "        Z                       / /   ,-' _.-'  //   ``--._``._\n";
            this->description += "       Z                      ,','_.-' ,-' _.- (( =-    -. `-._`-._____\n";
            this->description += "      z                     ,;.''__..-'   _..--.\\.--'````--.._``-.`-._`.\n";
            this->description += "     z       _          |\\,' .-''        ```-'`---'`-...__,._  ``-.`-.`-.`.\n";
            this->description += "  _     _.-,'(__)\\__)\\-'' `     ___  .          `     \\      `--._\n";
            this->description += ",',)---' /_)          `     `      ``-.   `     /     /     `     `-.\n";
            this->description += "\\_____--.  '`  `               __..-.  \\     . (   < _...-----..._   `.\n";
            this->description += " \\_,--..__. \\  .-`.\\----'';``,..-.__ \\  \\      ,`_. `.,-'`--'`---''`.  )\n";
            this->description += "           `.\\`.\\  `_.-..' ,'   _,-..'  /..,-''(, ,' ; ( _______`___..'__\n";
            this->description += "                   ((,(,__(    ((,(,__,'  ``'-- `'`.(\\  `.,..______\n";
            this->description += "                                                      ``--------..._``--.__\n";

            this->keyName = "The Castle Key";
            this->lock();
        };

        GameCharacter* spawnRandomMobs(){
            return new FireDragon();
        }
};

class Castle_2F : public GameMap{
    public:
        Castle_2F(int difficulty) : GameMap("The Castle - 2/F", difficulty){
            this->peaceful = false;

            // Text description
            this->description = "After a death fight with the dragon, you eventually go to the 2/F.\n";
            this->description += "The first thing you see is a giant armor statue holding a sword.\n";
            this->description += "Suddenly, the statue moves a little, and you heard:\n";
            this->description += "\"No one shall pass through the \'Gate\', no one!\"\n";
            this->description += "You see the stairs after it, so prepare for the next battle!\n";
            this->description += "\n";

            // Graphical description
            // ASCII art from https://www.asciiart.eu/people/occupations/knights, by Joan G. Stark, modified
            this->description += "              {}\n";
            this->description += "            .-''-.\n";
            this->description += "           /  __  \\\n";
            this->description += "          /.-'  '-.\\\n";
            this->description += "          \\::.  .::/\n";
            this->description += "           \\'    '/\n";
            this->description += "      __ ___)    (___ __\n";
            this->description += "    .'   \\          /   `.\n";
            this->description += "   /     | '-.__.-' |     \\\n";
            this->description += "   |     |  '::::'  |     |\n";
            this->description += "   |    /    '::'    \\    |\n";
            this->description += "   |_.-;\\     __     /;-._|\n";
            this->description += "   \\.'^`\\    \\/    //`^'./\n";
            this->description += "   /   _.-._ _||_ _.-._   \\\n";
            this->description += "  `\\___\\    '-..-'    /___/`\n";
            this->description += "       /'---.  `\\.---'\\\n";
            this->description += "      ||    |`\\\\|    ||\n";
            this->description += "      ||    | || |    ||\n";
            this->description += "      |;.__.' || '.__.;|\n";

            this->keyName = "The Castle 2/F Key";
            this->lock();
        };

        GameCharacter* spawnRandomMobs(){
            return new LichKing();
        }
};

class Castle_3F : public GameMap{
    public:
        Castle_3F(int difficulty) : GameMap("The Castle - 3/F", difficulty){
            this->peaceful = false;

            // Text description

            // Graphical description

            this->keyName = "The Castle 3/F Key";
            this->lock();
        };

        GameCharacter* spawnRandomMobs(){
            return new Magician();
        }
};

#endif