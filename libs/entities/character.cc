#include "libs/entities/character.h"
#include "libs/entities/game_item.h"
#include "libs/utils/random_util.h"

//protected
void GameCharacter::forceLevelup(){
    this->level += 1;
    Random major = Random(15, 30);
    Random minor = Random(5, 15);
    CharacterStat stat;
    if(this->getClassType() == WARRIOR){
        stat = this->genGeneralStat(&major, PHY_ATTACK | PHY_RESIST | MAG_RESIST);
        // minorStat = genGeneral
    }else if(this->getClassType() == WIZARD){
        stat = this->genGeneralStat(&major, PHY_ATTACK | PHY_RESIST | MAG_RESIST);
    }else if(this->getClassType() == ASSASSIN){
        stat = this->genGeneralStat(&major, PHY_ATTACK);
    }else if(this->getClassType() == MONSTER){
        stat = this->genGeneralStat(&major, PHY_ATTACK);
    }
}

CharacterStat GameCharacter::genStat(int flags){
    return this->genGeneralStat(this->statRng, flags);
}

CharacterStat GameCharacter::genGeneralStat(Random* rng, int flags){
    CharacterStat stat;
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
        stat.stun = this->modifierRng->getFloat() > 0.5? 1 : 0;
}

CharacterStat GameCharacter::genModifier(int flags){
    CharacterStat stat;
    if(flags & PHY_ATTACK)
        stat.phyAttack = this->modifierRng->getFloat();
    if(flags & PHY_RESIST)
        stat.phyResist = this->modifierRng->getFloat();
    if(flags & MAG_ATTACK)
        stat.magAttack = this->modifierRng->getFloat();
    if(flags & MAG_RESIST)
        stat.magResist = this->modifierRng->getFloat();
    if(flags & HEALING)
        stat.healAmount = this->modifierRng->getFloat();
    if(flags & STUN)
        stat.stun = this->modifierRng->getFloat() > 0.5? 1 : 0;
}

//public
std::string GameCharacter::getName(){
    return this->name;
}

std::string GameCharacter::getType(){
    return this->type;
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

void GameCharacter::useItem(GameItem* item){
    // check type
}

void GameCharacter::equipItem(GameItem* weapon){
    // check type
}

void GameCharacter::attack(GameCharacter* character){
    // logic
}

void GameCharacter::heal(GameItem* item){
    if(item->getType() & HEALING)
        this->currentHp += item->getValues().healAmount;
}

CharacterStat GameCharacter::block(){
    return this->genModifier(PHY_RESIST | MAG_RESIST);
}

void GameCharacter::levelup(){
    if(xp > this->nextLevelXp){
        this->forceLevelup();
    }
}

void GameCharacter::setMagicResist(int val){
    this->magicResist = val;
}

void GameCharacter::setPhysicalResist(int val){
    this->physicalResist = val;
}

void GameCharacter::setMaxHp(int val){
    this->maxHp = val;
}

void GameCharacter::setMaxMana(int val){
    this->maxMana = val;
}