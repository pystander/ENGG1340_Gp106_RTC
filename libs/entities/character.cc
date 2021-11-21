#include <iostream>
#include "libs/entities/character.h"
#include "libs/entities/game_item.h"
#include "libs/utils/random_util.h"
#include "libs/utils/colored_output.h"

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
    this->nextLevelXp = pow(2, this->level) * log(this->level) + this->level*100;
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

void GameCharacter::setLevel(int lvl, int nextLevelXp){
    if(lvl > 0)
        this->level = lvl;
    if(nextLevelXp > 0)
        this->nextLevelXp = nextLevelXp;
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
        std::cout << "Using item: "; ColoredOutput::green(item->getName()) << "\n";
        if(type & HEALING){
            this->heal(item);
        }
        deleteItem(item);
    }else{
        std::cout << "Cannot use non-consumable item: "; ColoredOutput::green(item->getName()) << "\n";
    }
}

void GameCharacter::useSkill(int index){
    if(this->isSkillOnCooldown(index)){
        std::cout << "Skill "; ColoredOutput::green(this->skills[index].name) << " is on cooldown\n";
        return;
    }
    if(index >= 0 && index < this->skills.size()){
        std::cout << "Using skill: "; ColoredOutput::green(this->skills[index].name) << "\n";
        if(this->currentMana - this->skills[index].manaDeduction >= 0){
            this->currentMana -= this->skills[index].manaDeduction;
            if(this->skills[index].manaDeduction > 0){
                std::cout << "Mana decreases by "; ColoredOutput::green(this->skills[index].manaDeduction) << "\n";
            }
            applyModifier(this->skills[index].modifier);
            this->onCooldown.push_back(index);
            this->onCooldownRoundsLeft.push_back(this->skills[index].cooldown);
        }else{
            ColoredOutput::blue(this->getName() + " do not have enough mana!\n");
        }
    }else{
        std::cout << "Cannot use skill with index: "; ColoredOutput::green(index) << "\n";
    }
}

bool GameCharacter::isSkillOnCooldown(int index){
    for(int i = 0; i < this->onCooldown.size(); i++){
        if(index == this->onCooldown[i]) return true;
    }
    return false;
}

void GameCharacter::updateCooldownSkills(){
    for(int i = this->onCooldown.size()-1; i >= 0; i--){
        this->onCooldownRoundsLeft[i]--;
        if(this->onCooldownRoundsLeft[i] == 0){
            // delete skill from cooldown list
            this->onCooldown.erase(this->onCooldown.begin() + i);
            this->onCooldownRoundsLeft.erase(this->onCooldownRoundsLeft.begin() + i);
        }
    }
}

void GameCharacter::clearCooldownSkills(){
    this->onCooldown.clear();
    this->onCooldownRoundsLeft.clear();
}

void GameCharacter::equipItem(GameItem* item){
    if(item->getItemCategory() & WEAPON){
        this->equippedItem = item;
        if(this->isPlayer()){
            std::cout << "Equipping weapon: "; ColoredOutput::green(item->getName()) << "\n";
        }
    }else if(item->getItemCategory() & ARMOR){
        this->armor = item;
        if(this->isPlayer()){
            std::cout << "Equipping armor: "; ColoredOutput::green(item->getName()) << "\n";
        }
    }else{
        std::cout << "Cannot equip item: "; ColoredOutput::green(item->getName()) << "\n";
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
    ColoredOutput::green(character->getName()) << " took "; ColoredOutput::green(totalDamage) << " damage!\n";
    if(character->currentHp < 0){
        character->dead();
        ColoredOutput::green(character->getName()) << " is dead, type 'loots' to show loots dropped\n";
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
    this->recalculateAdditionalStat();
}

void GameCharacter::resetModifier(){
    this->modifierStat.phyAttack = 1;
    this->modifierStat.phyResist = 1;
    this->modifierStat.magAttack = 1;
    this->modifierStat.magResist = 1;
    this->recalculateAdditionalStat();
}

void GameCharacter::recalculateAdditionalStat(){
    // never multiply by 0 (if you want no effect on mobs, 
    // use 99999 on mobs phy/mag resistance instead)
    StatModiferStore equippedItemStat = this->equippedItem->getItemStat();
    this->additionalStat.phyAttack = (equippedItemStat.phyAttack? equippedItemStat.phyAttack : 1) * this->modifierStat.phyAttack;
    this->additionalStat.phyResist = (equippedItemStat.phyResist? equippedItemStat.phyResist : 1) * this->modifierStat.phyResist;
    this->additionalStat.magAttack = (equippedItemStat.magAttack? equippedItemStat.magAttack : 1) * this->modifierStat.magAttack;
    this->additionalStat.magResist = (equippedItemStat.magResist? equippedItemStat.magResist : 1) * this->modifierStat.magResist;

    if(this->armor){
        StatModiferStore armorStat = this->armor->getItemStat();
        this->additionalStat.phyAttack += (armorStat.phyAttack? armorStat.phyAttack : 1) * this->modifierStat.phyAttack;
        this->additionalStat.phyResist += (armorStat.phyResist? armorStat.phyResist : 1) * this->modifierStat.phyResist;
        this->additionalStat.magAttack += (armorStat.magAttack? armorStat.magAttack : 1) * this->modifierStat.magAttack;
        this->additionalStat.magResist += (armorStat.magResist? armorStat.magResist : 1) * this->modifierStat.magResist;
    }
}

void GameCharacter::heal(GameItem* item){
    StatModiferStore stat = item->getItemStat();
    if(item->getType() & HEALING){
        if(stat.healAmount != 0){
            this->currentHp += item->getItemStat().healAmount;
            if(this->currentHp > this->maxHp)
                this->currentHp = this->maxHp;
            ColoredOutput::green(this->getName()) << " healed for " << item->getItemStat().healAmount << " HP\n";
        }
        if(stat.manaAmount != 0){
            this->currentMana += item->getItemStat().manaAmount;
            if(this->currentMana > this->maxMana)
                this->currentMana = this->maxMana;
            std::cout << "Added " << item->getItemStat().manaAmount << " points of mana\n";
        }
    }
}

int GameCharacter::manaRegen(){
    int regenAmount = Random(0, 30).getFloat();
    this->currentMana += regenAmount;
    if(this->currentMana > this->maxMana){
        this->currentMana = this->maxMana;
    }
    return regenAmount;
}

int GameCharacter::hpRegen(){
    int regenAmount = Random(0, 10).getFloat();
    this->currentHp += regenAmount;
    if(this->currentHp > this->maxHp){
        this->currentHp = this->maxHp;
    }
    return regenAmount;
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
    while(this->xp >= this->nextLevelXp){
        if(this->isPlayer()){
            ColoredOutput::green(this->getName()) << " has leveled up to level "; ColoredOutput::green(this->level) << "\n";
        }
        this->forceLevelup();
    }
}

void GameCharacter::dead(){
    this->is_dead = true;
}

void GameCharacter::restore(){
    this->currentHp = this->maxHp;
    this->currentMana = this->maxMana;
    this->resetModifier();
}

void GameCharacter::displayCharacterStatus(){
    StatModiferStore stat = this->baseStat;
    std::cout << "Name           : " ; ColoredOutput::greenStart() << this->name << "\n"; ColoredOutput::reset();
    std::cout << "Is dead?       : " ; ColoredOutput::greenStart() << (this->isDead()? "true" : "false") << "\n"; ColoredOutput::reset();
    std::cout << "Class Type     : " ; ColoredOutput::greenStart() << this->typeStr << "\n"; ColoredOutput::reset();
    std::cout << "Current Level  : " ; ColoredOutput::greenStart() << this->level << "\n"; ColoredOutput::reset();
    std::cout << "Current xp     : " ; ColoredOutput::greenStart() << this->xp << "\n"; ColoredOutput::reset();
    std::cout << "Next level xp  : " ; ColoredOutput::greenStart() << this->nextLevelXp << "\n"; ColoredOutput::reset();
    std::cout << "Money          : $"; ColoredOutput::greenStart() << this->money << "\n"; ColoredOutput::reset();
    std::cout << "Current Hp     : " ; ColoredOutput::greenStart() << this->currentHp   << ", (max: " << this->maxHp << ")" << "\n"; ColoredOutput::reset();
    std::cout << "Current Mana   : " ; ColoredOutput::greenStart() << this->currentMana << ", (max: " << this->maxMana << ")" << "\n"; ColoredOutput::reset();
    std::cout << "Physical Attack: " ; ColoredOutput::greenStart() << stat.phyAttack << ", (add: " << this->additionalStat.phyAttack << "; mod: " << this->modifierStat.phyAttack << ")" << "\n"; ColoredOutput::reset();
    std::cout << "Physical Resist: " ; ColoredOutput::greenStart() << stat.phyResist << ", (add: " << this->additionalStat.phyResist << "; mod: " << this->modifierStat.phyResist << ")" << "\n"; ColoredOutput::reset();
    std::cout << "Magical  Attack: " ; ColoredOutput::greenStart() << stat.magAttack << ", (add: " << this->additionalStat.magAttack << "; mod: " << this->modifierStat.magAttack << ")" << "\n"; ColoredOutput::reset();
    std::cout << "Magical  Resist: " ; ColoredOutput::greenStart() << stat.magResist << ", (add: " << this->additionalStat.magResist << "; mod: " << this->modifierStat.magResist << ")" << "\n"; ColoredOutput::reset();
}