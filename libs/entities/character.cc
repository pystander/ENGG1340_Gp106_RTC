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
    this->currentMana = this->currentMana;
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
    if(flags & HEALING)
        stat.healAmount = rng->getInt();
    if(flags & STUN)
        stat.stun = modifierRng.getFloat() > 0.5? 1 : 0;
    return stat;
}

StatModiferStore GameCharacter::genModifier(int flags){
    Random modifierRng = Random(0, 1);
    StatModiferStore stat;
    if(flags & PHY_ATTACK)
        stat.phyAttack = modifierRng.getFloat();
    if(flags & PHY_RESIST)
        stat.phyResist = modifierRng.getFloat();
    if(flags & MAG_ATTACK)
        stat.magAttack = modifierRng.getFloat();
    if(flags & MAG_RESIST)
        stat.magResist = modifierRng.getFloat();
    if(flags & HEALING)
        stat.healAmount = modifierRng.getFloat();
    if(flags & STUN)
        stat.stun = modifierRng.getFloat() > 0.5? 1 : 0;
    return stat;
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

GameItem* GameCharacter::getEquipped(){
    return this->equippedItem;
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

void GameCharacter::setup(){
    this->baseStat = this->genStat(PHY_ATTACK | PHY_RESIST | MAG_ATTACK | MAG_RESIST);
    this->forceLevelup();
}

void GameCharacter::useItem(GameItem* item){
    // check type
}

void GameCharacter::equipItem(GameItem* weapon){
    // check type
    this->equippedItem = weapon;
}

void GameCharacter::attack(GameCharacter* character){
    StatModiferStore blockAmount = character->block();
    float totalDamage = 0;
    totalDamage += this->baseStat.phyAttack - blockAmount.phyResist;
    totalDamage += this->baseStat.magAttack - blockAmount.magResist;
    totalDamage += this->equippedItem->getItemStat().phyAttack;
    totalDamage += this->equippedItem->getItemStat().magAttack;
    if(totalDamage > 0)
        character->currentHp -= totalDamage;
    if(character->currentHp < 0){
        character->dead();
    }
}

void GameCharacter::applyModifier(StatModiferStore modifier){
    if(modifier.phyAttack != -1)
        this->baseStat.phyAttack *= modifier.phyAttack;
    if(modifier.phyResist != -1)
        this->baseStat.phyResist *= modifier.phyResist;
    if(modifier.magAttack != -1)
        this->baseStat.magAttack *= modifier.magAttack;
    if(modifier.magResist != -1)
        this->baseStat.magResist *= modifier.magResist;
}

void GameCharacter::clearModifier(){
    this->battleStat = this->baseStat;
}

void GameCharacter::heal(GameItem* item){
    if(item->getType() & HEALING)
        this->currentHp += item->getItemStat().healAmount;
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
    if(xp > this->nextLevelXp){
        this->forceLevelup();
    }
}

void GameCharacter::dead(){
    this->is_dead = true;
}

void GameCharacter::displayCharacterStatus(){
    StatModiferStore stat = this->baseStat;
    std::cout << "Is dead?       : " << (this->isDead()? "true" : "false") << "\n";
    std::cout << "Current Level  : " << this->level << "\n";
    std::cout << "Class Type     : " << this->typeStr << "\n";
    std::cout << "Current Hp     : " << this->currentHp << "\n";
    std::cout << "Current Mana   : " << this->currentMana << "\n";
    std::cout << "Physical Attack: " << stat.phyAttack << "\n";
    std::cout << "Physical Resist: " << stat.phyResist << "\n";
    std::cout << "Magical  Attack: " << stat.magAttack << "\n";
    std::cout << "Magical  Resist: " << stat.magResist << "\n";
}