#ifndef PEACEFUL_AREA_H
#define PEACEFUL_AREA_H

#include "libs/enviro/game_map.h"
#include "libs/entities/items/consumables.h"
#include "libs/entities/items/weapons.h"
#include "libs/entities/items/armors.h"

class SpawnArea : public GameMap{
    public:
        SpawnArea(int difficulty) : GameMap("Spawn Area", difficulty){};

        GameCharacter* spawnRandomMobs(){
            return nullptr;
        }
};

class WaitingArea : public GameMap{
    public:
        WaitingArea(int difficulty) : GameMap("Waiting Area", difficulty){};

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