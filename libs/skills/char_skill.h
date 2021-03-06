#ifndef CHAR_SKILL_H
#define CHAR_SKILL_H

struct CharacterSkill;
class SkillSets;

#include <string>
#include <vector>
#include "libs/entities/character.h"

// All skills should have a duration of 1 (after enemy attack)
// This one may not be implemented due to time constraint
typedef struct CharacterSkill{
    std::string name;
    int type;                // type defined in GameItem, eg. PHY_ATTACK | MAG_ATTACK
    int characterType;       // eg. WARRIOR
    int cooldown;            // measured in turns
    int manaDeduction = 0;
    StatModiferStore modifier;
} CharacterSkill;

/**
 * Functions doing the main logic:
 * GameCharacter::updateCooldownSkills()
 * 
 * GameMatch::endTurn()
 */
class SkillSets{
    public:
        static std::vector<CharacterSkill> warriorSkills(){
            std::vector<CharacterSkill> skills;
            // 1st
            CharacterSkill defensive;
            defensive.name = "Defensive";
            defensive.type = PHY_RESIST | MAG_RESIST;
            defensive.characterType = WARRIOR;
            defensive.cooldown = 2;
            StatModiferStore defensiveModifier;
            defensiveModifier.phyResist = 1.2;
            defensiveModifier.magResist = 1.2;
            defensive.modifier = defensiveModifier;
            skills.push_back(defensive);
            // 2nd
            CharacterSkill charge;
            charge.name = "Charge";
            charge.type = PHY_ATTACK;
            charge.characterType = WARRIOR;
            charge.cooldown = 1;
            StatModiferStore chargeModifier;
            chargeModifier.phyAttack = 1.2;
            charge.modifier = chargeModifier;
            skills.push_back(charge);
            // 3nd
            CharacterSkill cleave;
            cleave.name = "Cleave";
            cleave.type = PHY_ATTACK;
            cleave.characterType = WARRIOR;
            cleave.cooldown = 2;
            StatModiferStore cleaveModifier;
            cleaveModifier.phyAttack = 1.5;
            cleave.modifier = cleaveModifier;
            skills.push_back(cleave);
            return skills;
        }

        // Wizard has high damage but low defense
        static std::vector<CharacterSkill> wizardSkills(){
            std::vector<CharacterSkill> skills;
            // 1st
            CharacterSkill magicMissile;
            magicMissile.name = "Magic Missile";
            magicMissile.type = MAG_ATTACK;
            magicMissile.characterType = WIZARD;
            magicMissile.cooldown = 1;
            magicMissile.manaDeduction = 5;
            StatModiferStore magicMissileModifier;
            magicMissileModifier.magAttack = 1.2;
            magicMissile.modifier = magicMissileModifier;
            skills.push_back(magicMissile);
            // 2nd
            CharacterSkill spectralBlade;
            spectralBlade.name = "Spectral Blade";
            spectralBlade.type = PHY_ATTACK;
            spectralBlade.characterType = WIZARD;
            spectralBlade.cooldown = 2;
            spectralBlade.manaDeduction = 15;
            StatModiferStore spectralBladeModifier;
            spectralBladeModifier.phyAttack = 1.7;
            spectralBlade.modifier = spectralBladeModifier;
            skills.push_back(spectralBlade);
            // 3nd
            CharacterSkill tornado;
            tornado.name = "Tornado";
            tornado.type = MAG_ATTACK;
            tornado.characterType = WIZARD;
            tornado.cooldown = 2;
            tornado.manaDeduction = 15;
            StatModiferStore tornadoModifier;
            tornadoModifier.magAttack = 1.7;
            tornado.modifier = tornadoModifier;
            skills.push_back(tornado);
            // 4th
            CharacterSkill iceArmor;
            iceArmor.name = "Ice Armor";
            iceArmor.type = PHY_RESIST | MAG_RESIST;
            iceArmor.characterType = WIZARD;
            iceArmor.cooldown = 2;
            iceArmor.manaDeduction = 10;
            StatModiferStore iceArmorModifier;
            iceArmorModifier.phyResist = 1.5;
            iceArmorModifier.magResist = 1.5;
            iceArmor.modifier = iceArmorModifier;
            skills.push_back(iceArmor);
            return skills;
        }

        
        static std::vector<CharacterSkill> assassinSkills(){
            std::vector<CharacterSkill> skills;
            // 1st
            CharacterSkill onYourBack;
            onYourBack.name = "On your back";
            onYourBack.type = PHY_ATTACK | MAG_ATTACK;
            onYourBack.characterType = ASSASSIN;
            onYourBack.cooldown = 4;
            StatModiferStore onYourBackModifier;
            onYourBackModifier.phyAttack = 5.0;
            onYourBackModifier.magAttack = 5.0;
            onYourBack.modifier = onYourBackModifier;
            skills.push_back(onYourBack);
            // 2nd
            CharacterSkill dodge;
            dodge.name = "Dodge";
            dodge.type = PHY_RESIST | MAG_RESIST;
            dodge.characterType = ASSASSIN;
            dodge.cooldown = 2;
            StatModiferStore dodgeModifier;
            dodgeModifier.phyResist = 3.0;
            dodgeModifier.magResist = 3.0;
            dodge.modifier = dodgeModifier;
            skills.push_back(dodge);
            // 3nd
            CharacterSkill sneakAttack;
            sneakAttack.name = "Sneak Attack";
            sneakAttack.type = PHY_ATTACK | MAG_ATTACK | PHY_RESIST | MAG_RESIST;
            sneakAttack.characterType = ASSASSIN;
            sneakAttack.cooldown = 4;
            StatModiferStore sneakAttackModifier;
            sneakAttackModifier.phyAttack = 1.5;
            sneakAttackModifier.phyResist = 1.5;
            sneakAttackModifier.magAttack = 1.5;
            sneakAttackModifier.magResist = 1.5;
            sneakAttack.modifier = sneakAttackModifier;
            skills.push_back(sneakAttack);
            return skills;
        }
};

#endif