#ifndef PEACEFUL_AREA_H
#define PEACEFUL_AREA_H

#include "libs/enviro/game_map.h"
#include "libs/entities/items/consumables.h"
#include "libs/entities/items/weapons.h"
#include "libs/entities/items/armors.h"

class WaitingArea : public GameMap{
    public:
        WaitingArea(int difficulty) : GameMap("Waiting Area", difficulty){
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
            this->shopType = SHOP_CONSUMABLES;
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
            this->shopType = SHOP_WEAPON;
            this->itemsOnSold.push_back(new WoodenSword());
            this->itemsOnSold.push_back(new BronzeDagger());
            this->itemsOnSold.push_back(new IronScimitar());
            this->itemsOnSold.push_back(new WoodenWand());
            this->itemsOnSold.push_back(new MithrilSword());
        };

        GameCharacter* spawnRandomMobs(){
            return nullptr;
        }
};

class ArmorShop : public GameMap{
    public:
        ArmorShop(int difficulty) : GameMap("Armor Shop", difficulty){
            this->shopType = SHOP_ARMOR;
            this->itemsOnSold.push_back(new LeatherCloth());
            this->itemsOnSold.push_back(new SilverChestplate());
            this->itemsOnSold.push_back(new MageCloak());
        };

        GameCharacter* spawnRandomMobs(){
            return nullptr;
        }
};

#endif