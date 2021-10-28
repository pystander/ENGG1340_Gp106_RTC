# The Road to Castle
A text-based RPG for HKU ENGG1340 group project.


## Group Members
- Leung Chiu Yuen, Rain
- Ko King Nam, Vincent


## Introduction
The Ultimate Goal is to defeat the monsters amid the road and arive to the Castle.


## Features
- Multiple Character Classes: Warrior, Mage, Archer
    - There will be a level system (higher player level will have higher player statistics, eg. higher attack value)
    - Each class with their own unique abilities
    - Files are stored in `.h` and `.cpp` with different classes contained in their own file (eg. `Player.cpp`, `Player.h`, `Game.cpp`, `Warrior.cpp`, etc.) (CR5)

- Random mobs, monsters, and events
    - Game events occur randomly (CR1)
    - Monster types and attributes are randomly generated (CR1)
    - Will drop equipments / keys for unlocking bosses

- Shop items: weapon, armour, consumables
    - Equipment systems (CR3)
    - Different pieces of equipment will have different attack / defense values.

- Level and Save System
    - Multiple saves allowed (CR4)
    - Player attributes (eg. Health, Level) are stored (CR2)

- Game Difficulty
    - Normal: More health or resistance values
    - Hard: randomly generated player statistics (CR1)

*CR = Code Requirement
