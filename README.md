# The Road to Castle
A text-based RPG for HKU ENGG1340 group project.

## Group Members
- Rain
- Vincent

## Introduction
The Road to Castle is a fantasy text-based RPG. Players will act as the main protagonist, a hero under a prophecy who dooms to conquer and save the land.
The ultimate goal of this game is to slay the monsters amid the road, arive to the Castle, and defeat all bosses.

## Installation
You can clone this repository over HTTPS into your local folder
```bash
git clone https://github.com/pystander/ENGG1340_Gp106_RTC.git
```

Enter the directory to make files
```bash
cd ENGG1340_Gp106_RTC/
make all
```

Run the executable `main` created in `bin/`
```bash
cd bin/
./main
```

## Features
- Multiple Character Classes: Warrior, Mage, Assassin
    - There will be a level system (higher player level will have higher player statistics, eg. higher attack value)
    - Each class with their own unique abilities
    - Files are stored in `.h` and `.cc` with different classes contained in their own file (eg. `Player.cc`, `Player.h`, `Game.cc`, `Warrior.cc`, etc.) (CR5)

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

## Implementation for Code Requirement
- CR1 - A util class `Random` is created to generate random variables. `uniform_int_distribution` is used to ensure "truer" randomness than using `rand()`. For the use of `Random` class, see `libs/entities/enemies/weaker_enemies.h`.
- CR2 - vector and set are used to store data so far.
- CR3 - Since object-oriented programming is used in the project, lots of the time, we will create `new` objects. When a character is being deleted, this code is being called `delete inventory[i]`. When we load a new game from a file, a new player is being loaded while the old one will be deleted using `delete this->player`.
- CR4 - File IO is used to store character statistics only. Save files are denoted by `.rtc` file extension.
- CR5 - Many files are created. `.h` files are often accompanied by `.cc`.
    - `.cc` is used because of its simplicity
- CR6 - indentation is definitely proper. Codes are definitely readable.
- CR7 - since Vincent is the one who created the framework, documentation is definitely needed. However, if you got good naming styles, no documentation is really needed. Often, `.h` contains the most comments acting as documentation.

## Project Structure
`libs/` and `src/` are the source codes.

`libs/` is essentially the game source code files with headers.

`bin/` contains the compiled and linked binary (game executable) called `main`.
