#include <iostream>
#include "libs/entities/character.h"
#include "libs/entities/game_item.h"
#include "libs/utils/random_util.h"

//protected
void GameCharacter::forceLevelup(){
    Random major = Random(15, 30);
    Random minor = Random(5, 15);
    StatModiferStore majorStat;
    StatModiferStore minorStat = this->genStatWithRng(&minor, PHY_ATTACK | MAG_ATTACK | PHY_RESIST | MAG_RESIST | HEALING);
    // healing stands for HP and MANA increase
    if(this->getClassType() == WARRIOR){
        majorStat = this->genStatWithRng(&major, PHY_ATTACK | PHY_RESIST | MAG_RESIST);
    }else if(this->getClassType() == WIZARD){
        majorStat = this->genStatWithRng(&major, MAG_ATTACK);
    }else if(this->getClassType() == ASSASSIN){
        majorStat = this->genStatWithRng(&major, PHY_ATTACK | MAG_ATTACK);
        minorStat = this->genStatWithRng(&minor, PHY_ATTACK | MAG_ATTACK | HEALING);
    }else if(this->getClassType() == MONSTER){
        majorStat = this->genStatWithRng(&major, PHY_ATTACK);
    }
    StatModiferStore result;
    result.phyAttack = majorStat.phyAttack + minorStat.phyAttack;
    result.phyResist = majorStat.phyResist + minorStat.phyResist;
    result.magAttack = majorStat.magAttack + minorStat.magAttack;
    result.magResist = majorStat.magResist + minorStat.magResist;
    this->setBaseStat(result);
    this->maxHp += majorStat.healAmount + minorStat.healAmount;
    this->maxMana += majorStat.healAmount + minorStat.healAmount;
    this->currentHp = this->maxHp;
    this->currentMana = this->maxMana;
    this->level++;
    this->nextLevelXp = pow(2, this->level) * log(this->level) + 100;
}

StatModiferStore GameCharacter::genStat(int flags){
    return this->genStatWithRng(&this->statRng, flags);
}

StatModiferStore GameCharacter::genStatWithRng(Random* rng, int flags){
    Random modifierRng = Random(0, 1);
    StatModiferStore stat;
    if(flags & PHY_ATTACK)
        stat.phyAttack = rng->getInt();
    if(flags & PHY_RESIST)
        stat.phyResist = rng->getInt();
    if(flags & MAG_ATTACK)
        stat.magAttack = rng->getInt();
    if(flags & MAG_RESIST)
        stat.magResist = rng->getInt();
    if(flags & HEALING){
        stat.healAmount = rng->getInt();
        stat.manaAmount = rng->getInt();
    }
    if(flags & STUN)
        stat.stun = modifierRng.getFloat() > 0.5? 1 : 0;
    return stat;
}

StatModiferStore GameCharacter::genModifier(int flags){
    Random modifierRng = Random(0, 1);
    return this->genStatWithRng(&modifierRng, flags);
}

//public
std::string GameCharacter::getName(){
    return this->name;
}

std::string GameCharacter::getType(){
    return this->typeStr;
}

int GameCharacter::getClassType(){
    return this->classType;
}

std::vector<GameItem*> GameCharacter::getInventory(){
    return this->inventory;
}

GameItem* GameCharacter::getFromInventory(int index){
    if(index >= 0 && index < this->inventory.size()){
        return this->inventory[index];
    }
    return nullptr;
}

GameItem* GameCharacter::getEquipped(){
    return this->equippedItem;
}

int GameCharacter::getMoneyAmount(){
    return this->money;
}

bool GameCharacter::isPlayer(){
    return this->is_player;
}

bool GameCharacter::isStunned(){
    return this->stunned;
}

bool GameCharacter::isDead(){
    return this->is_dead;
}

void GameCharacter::setBaseStat(StatModiferStore stat){
    this->baseStat.phyAttack = stat.phyAttack;
    this->baseStat.phyResist = stat.phyResist;
    this->baseStat.magAttack = stat.magAttack;
    this->baseStat.magResist = stat.magResist;
}

void GameCharacter::addXp(int xp){
    this->xp += xp;
    this->levelup(); // try to level up
}

void GameCharacter::addToInventory(GameItem* item){
    if(item != nullptr){
        this->inventory.push_back(item);
    }
}


void GameCharacter::addMoney(int amount){
    this->money += amount;
}

bool GameCharacter::subMoney(int amount){
    if(this->money - amount < 0){
        return false;
    }else{
        this->money -= amount;
        return true;
    }
}

void GameCharacter::setup(){
    this->baseStat = this->genStat(PHY_ATTACK | PHY_RESIST | MAG_ATTACK | MAG_RESIST);
    this->inventory.push_back(new WeaponHands());
    this->equipItem(this->inventory[0]);
    this->forceLevelup();
    this->resetModifier();
    this->recalculateAdditionalStat();
}

void GameCharacter::deleteItem(GameItem* item){
    std::vector<GameItem*> newInv;
    for(int i = 0; i < this->inventory.size(); i++){
        if(item->getId() != this->inventory[i]->getId()){
            newInv.push_back(this->inventory[i]);
        }
    }
    this->inventory = newInv;
}

void GameCharacter::useItem(GameItem* item){
    if((item->getItemCategory() & CONSUMABLE)){
        int type = item->getType();
        this->applyModifier(item->getItemStat());
        if(type & HEALING){
            this->heal(item);
        }
        deleteItem(item);
    }else{
        std::cout << "Cannot use non-consumable item: " << item->getName() << "\n";
    }
}

void GameCharacter::equipItem(GameItem* item){
    if(item->getItemCategory() & WEAPON){
        this->equippedItem = item;
    }else if(item->getItemCategory() & ARMOR){
        // this->armor = item;
    }else{
        std::cout << "Cannot equip item: " << item->getName() << "\n";
    }
    this->recalculateAdditionalStat();
}

void GameCharacter::attack(GameCharacter* character){
    StatModiferStore blockAmount = character->block();
    float totalDamage = 0;
    float phyDamange = this->baseStat.phyAttack + this->additionalStat.phyAttack - blockAmount.phyResist;
    float magDamange = this->baseStat.magAttack + this->additionalStat.magAttack - blockAmount.magResist;
    if(phyDamange > 0) totalDamage += phyDamange;
    if(magDamange > 0) totalDamage += magDamange;
    character->currentHp -= totalDamage;
    std::cout << character->getName() << " took " << totalDamage << " damage!\n";
    if(character->currentHp < 0){
        character->dead();
        std::cout << character->getName() << " is dead\n";
        this->addXp(character->xp);
        this->money += character->getMoneyAmount();
    }
}

void GameCharacter::applyModifier(StatModiferStore modifier){
    // do not multiply by 0 to reset the whole stat.
    this->modifierStat.phyAttack *= modifier.phyAttack == 0? 1 : modifier.phyAttack;
    this->modifierStat.phyResist *= modifier.phyResist == 0? 1 : modifier.phyResist;
    this->modifierStat.magAttack *= modifier.magAttack == 0? 1 : modifier.magAttack;
    this->modifierStat.magResist *= modifier.magResist == 0? 1 : modifier.magResist;
}

void GameCharacter::resetModifier(){
    this->modifierStat.phyAttack = 1;
    this->modifierStat.phyResist = 1;
    this->modifierStat.magAttack = 1;
    this->modifierStat.magResist = 1;
}

void GameCharacter::recalculateAdditionalStat(){
    StatModiferStore equippedItemStat = this->equippedItem->getItemStat();
    this->additionalStat.phyAttack = equippedItemStat.phyAttack * this->modifierStat.phyAttack;
    this->additionalStat.phyResist = equippedItemStat.phyResist * this->modifierStat.phyResist;
    this->additionalStat.magAttack = equippedItemStat.magAttack * this->modifierStat.magAttack;
    this->additionalStat.magResist = equippedItemStat.magResist * this->modifierStat.magResist;

    // armor calculations...
}

void GameCharacter::heal(GameItem* item){
    StatModiferStore stat = item->getItemStat();
    if(item->getType() & HEALING){
        if(stat.healAmount != 0){
            this->currentHp += item->getItemStat().healAmount;
            if(this->currentHp > this->maxHp)
                this->currentHp = this->maxHp;
            std::cout << "You healed for " << item->getItemStat().healAmount << " HP\n";
        }
        if(stat.manaAmount != 0){
            this->currentMana += item->getItemStat().manaAmount;
            if(this->currentMana > this->maxMana)
                this->currentMana = this->maxMana;
            std::cout << "Added " << item->getItemStat().manaAmount << " points of mana\n";
        }
    }
}

StatModiferStore GameCharacter::block(){
    StatModiferStore stat = this->baseStat;
    // 0 is the min
    Random phyResistRng = Random(stat.phyResist - 5 < 0? 0 : stat.phyResist - 5, stat.phyResist + 5);
    Random magResistRng = Random(stat.magResist - 5 < 0? 0 : stat.magResist - 5, stat.magResist + 5);
    StatModiferStore blockAmount;
    blockAmount.phyResist = phyResistRng.getFloat();
    blockAmount.magResist = magResistRng.getFloat();
    return blockAmount;
}

void GameCharacter::levelup(){
    if(this->xp >= this->nextLevelXp){
        if(this->isPlayer())
            std::cout << this->getName() << " has leveled up to level " << this->level << "\n";
        this->forceLevelup();
    }
}

void GameCharacter::dead(){
    this->is_dead = true;
}

void GameCharacter::displayCharacterStatus(){
    StatModiferStore stat = this->baseStat;
    std::cout << "Is dead?       : " << (this->isDead()? "true" : "false") << "\n";
    std::cout << "Class Type     : " << this->typeStr << "\n";
    std::cout << "Current Level  : " << this->level << "\n";
    std::cout << "Current xp     : " << this->xp << "\n";
    std::cout << "Next level xp  : " << this->nextLevelXp << "\n";
    std::cout << "Money          : $" << this->money << "\n";
    std::cout << "Current Hp     : " << this->currentHp   << ", (max: " << this->maxHp << ")" << "\n";
    std::cout << "Current Mana   : " << this->currentMana << ", (max: " << this->maxMana << ")" << "\n";
    std::cout << "Physical Attack: " << stat.phyAttack << ", (add: " << this->additionalStat.phyAttack << ")" << "\n";
    std::cout << "Physical Resist: " << stat.phyResist << ", (add: " << this->additionalStat.phyResist << ")" << "\n";
    std::cout << "Magical  Attack: " << stat.magAttack << ", (add: " << this->additionalStat.magAttack << ")" << "\n";
    std::cout << "Magical  Resist: " << stat.magResist << ", (add: " << this->additionalStat.magResist << ")" << "\n";
}