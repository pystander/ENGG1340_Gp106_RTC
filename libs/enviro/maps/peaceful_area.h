#ifndef PEACEFUL_AREA_H
#define PEACEFUL_AREA_H

#include "libs/enviro/game_map.h"
#include "libs/entities/items/consumables.h"
#include "libs/entities/items/weapons.h"
#include "libs/entities/items/armors.h"

// Too hard to build a maze, so we have maps instead

class WaitingArea : public GameMap{
    public:
        WaitingArea(int difficulty) : GameMap("Waiting Area", difficulty){
            this->peaceful = true;
            this->description = "This is the waiting area. You have to type 'start' in order to start \n";
            this->description += "the game. Feel free to type 'mapdesc' to show description of the map\n";
            this->description += "which you are currently in.\n";
        };

        GameCharacter* spawnRandomMobs(){
            return nullptr;
        }
};

class SpawnArea : public GameMap{
    public:
        SpawnArea(int difficulty) : GameMap("Spawn Area", difficulty){
            this->peaceful = true;
            this->description = "Welcome to the spawn area. This area is regarded as a peaceful area\n";
            this->description += "where monsters / enemies will not spawn here. For available commands\n";
            this->description += "feel free to use type 'help'. If you don't know what the command does\n";
            this->description += "feel free to use type 'man <cmd_name>' to get the description of those\n";
            this->description += "commands. For example, 'man enter' will show you description of the \n";
            this->description += "command 'enter'.\n";
            this->description += "\n";
            this->description += "Shops are here by default, remember we have different kinds of items\n";
            this->description += "in the game, each shop sells different items. You have to sell\n";
            this->description += "items of which its type matches the shop type.\n";
        };

        GameCharacter* spawnRandomMobs(){
            return nullptr;
        }
};

class ConsumableShop : public GameMap{
    public:
        ConsumableShop(int difficulty) : GameMap("Consumable Shop", difficulty){
            this->peaceful = true;

            // Text description
            this->description = "This is a consumable shop. You can buy potions in this area.\n";
            this->description += "Feel free to type 'shop' to see available potions. Use 'sell' to\n";
            this->description += "sell consumables from your inventory\n";
            this->description += "\n";

            // Graphical description
            // ASCII art from https://www.asciiart.eu/buildings-and-places/houses, by lgbeard, modified
            this->description += "          .\n";
            this->description += "        ('\n";
            this->description += "        '|\n";
            this->description += "        |'\n";
            this->description += "       [::]   _......_\n";
            this->description += "       [::].-'      _.-`.\n";
            this->description += "       [:.'    .-. '-._.-`.\n";
             this->description += "      [/ /\\   |  \\        `-..\n";
            this->description += "       / / |   `-.'      .-.   `-.\n";
            this->description += "      /  `-'            (   `.    `.\n";
            this->description += "     |           /\\      `-._/      \\\n";
            this->description += "     '    .'\\   /  `.           _.-'|\n";
            this->description += "    /    /  /   \\_.-'        _.':;:/\n";
            this->description += "  .'     \\_/             _.-':;_.-'\n";
            this->description += " /   .-.             _.-' \\;.-'\n";
            this->description += "/   (   \\       _..-'     |\n";
            this->description += "\\    `._/  _..-'    .--.  |\n";
            this->description += " `-.....-'/  _ _  .'    '.|\n";
            this->description += "          | |_|_| |      | \\  (o)\n";
            this->description += "     (o)  | |_|_| |      | | (\'/)\n";
            this->description += "    (\\'/)/  ''''' |     o|  \\;:;\n";
            this->description += "     :;  |        |      |  |/)\n";
            this->description += "      ;: `-.._    /__..--'\\.' ;:\n";
            this->description += "          :;  `--' :;   :;\n";

            // Shop items
            this->shopType = SHOP_CONSUMABLES;
            this->itemsOnSold.push_back(new StrengthPotion());
            this->itemsOnSold.push_back(new MagicFruit());
            this->itemsOnSold.push_back(new SmallHpPotion());
            this->itemsOnSold.push_back(new MediumHpPotion());
            this->itemsOnSold.push_back(new ExtraHpPotion());
        };

        GameCharacter* spawnRandomMobs(){
            return nullptr;
        }
};

class WeaponShop : public GameMap{
    public:
        WeaponShop(int difficulty) : GameMap("Weapon Shop", difficulty){
            this->peaceful = true;

            // Text description
            this->description = "This is a weapon shop. You can buy and sell weapons in this area.\n";
            this->description += "Feel free to type 'shop' to see available weapons. Use 'sell' to\n";
            this->description += "sell weapons from your inventory\n";
            this->description += "\n";

            // Graphical description
            // ASCII art from https://www.asciiart.eu/buildings-and-places/houses, modified
            this->description += "                          (    )\n";
            this->description += "                            )  )\n";
            this->description += "                           (  (                  /\\\n";
            this->description += "                            (_)                 /  \\  /\\\n";
            this->description += "                    ________[_]________      /\\/    \\/  \\\n";
            this->description += "           /\\      /\\        ______    \\    /   /\\/\\  /\\/\\\n";
            this->description += "          /  \\    //_\\       \\    /\\    \\  /\\/\\/    \\/    \\\n";
            this->description += "   /\\    / /\\/\\  //___\\       \\__/  \\    \\/\n";
            this->description += "  /  \\  /\\/    \\//_____\\       \\ |[]|     \\\n";
            this->description += " /\\/\\/\\/       //_______\\       \\|__|      \\\n";
            this->description += "/      \\      /XXXXXXXXXX\\                  \\\n";
            this->description += "        \\    /_I_II  I__I_\\__________________\\\n";
            this->description += "               I_I|  I__I_____[]_|_[]_____I\n";
            this->description += "               I_II  I__I_____[]_|_[]_____I\n";
            this->description += "               I II__I  I     XXXXXXX     I\n";
            this->description += "               ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

            // Shop items
            this->shopType = SHOP_WEAPON;
            this->itemsOnSold.push_back(new WoodenSword());
            this->itemsOnSold.push_back(new BronzeDagger());
            this->itemsOnSold.push_back(new IronScimitar());
            this->itemsOnSold.push_back(new BattleAxe());
            this->itemsOnSold.push_back(new WarHammer());
            this->itemsOnSold.push_back(new WoodenWand());
            this->itemsOnSold.push_back(new MithrilSword());
            this->itemsOnSold.push_back(new RuneStone());
        };

        GameCharacter* spawnRandomMobs(){
            return nullptr;
        }
};

class ArmorShop : public GameMap{
    public:
        ArmorShop(int difficulty) : GameMap("Armor Shop", difficulty){
            this->peaceful = true;

            // Text description
            this->description = "This is a armor shop. You can buy and sell armors in this area.\n";
            this->description += "Feel free to type 'shop' to see available armors. Use 'sell' to\n";
            this->description += "sell armors from your inventory\n";
            this->description += "\n";

            // Graphical description
            // ASCII art from https://www.asciiart.eu/buildings-and-places/houses, modified
            this->description += "     _|=|__________\n";
            this->description += "    /              \\\n";
            this->description += "   /                \\\n";
            this->description += "  /__________________\\\n";
            this->description += "   ||  || /--\\ ||  ||\n";
            this->description += "   ||[]|| | .| ||[]||\n";
            this->description += " ()||__||_|__|_||__||()\n";
            this->description += "( )|-|-|-|====|-|-|-|( ) \n";
            this->description += "^^^^^^^^^^====^^^^^^^^^^^\n";

            // Shop items
            this->shopType = SHOP_ARMOR;
            this->itemsOnSold.push_back(new LeatherCloth());
            this->itemsOnSold.push_back(new SilverChestplate());
            this->itemsOnSold.push_back(new AssassinRobe());
            this->itemsOnSold.push_back(new MageCloak());
            this->itemsOnSold.push_back(new DragonVest());
        };

        GameCharacter* spawnRandomMobs(){
            return nullptr;
        }
};

class TheDoor : public GameMap{
    public:
        TheDoor(int difficulty) : GameMap("The Door", difficulty){
            this->peaceful = true;

            // Text description
            this->description = "You defeat the wizard with all you effort.\n";
            this->description += "\"You are talented, cough..., I just don't know why...\"\n";
            this->description += "You are determined and said:\n";
            this->description += "\"Gods may not exist, but they are the symbols for all people.\n";
            this->description += "They give us Hope and Peace, which keep us motivated.\n";
            this->description += "But the truth should be told, even if it hurts.\"\n";
            this->description += "\n";
            this->description += "You leave the wizard here and put the key into the door.\n";
            this->description += "With a clean sound from the lock, the door is slowly opening.\n";
            this->description += "After the door, you only see a dull and hollow entrance.\n";
            this->description += "\n";
            this->description += "You are determined, and walk into the darkness.\n";
            this->description += "It is completely dark, a little spark will be a dazzle for you.\n";
            this->description += "You continue to walk, alone.\n";
            this->description += "Not knowing how long, or how far have you gone.\n";
            this->description += "Eventually, you see a soft, but warm light coming from a room.\n";
            this->description += "You found it empty, just like your heart at the moment.\n";
            this->description += "The Gods do not exist, but you will be there, a hero for all people.\n";

            this->lockWith("Door Key");
        };

        GameCharacter* spawnRandomMobs(){
            return new Magician();
        }
};

class Ending : public GameMap{
    public:
        Ending(int difficulty) : GameMap("Ending", difficulty){
            this->peaceful = true;

            // Text description
            this->description = "Thank you for playing!\n";
            this->description += "You have reached all the content of this game.\n";
            this->description += "Please feel free to let us know if you encounter any bug or problem.\n";
            this->description += "\n";

            // Graphical description
            this->description += "                                   .''.\n";
            this->description += "       .''.      .        *''*    :_\\/_:     .\n";
            this->description += "      :_\\/_:   _\\(/_  .:.*_\\/_*   : /\\ :  .'.:.'.\n";
            this->description += "  .''.: /\\ :   ./)\\   ':'* /\\ * :  '..'.  -=:o:=-\n";
            this->description += " :_\\/_:'.:::.    ' *''*    * '.\'/.' _\\(/_'.':'.'\n";
            this->description += " : /\\ : :::::     *_\\/_*     -= o =-  /)\\    '  *\n";
            this->description += "  '..'  ':::'     * /\\ *     .'/.\'.   '\n";
            this->description += "      *            *..*         :\n";
        };

        GameCharacter* spawnRandomMobs(){
            return nullptr;
        }
};

#endif