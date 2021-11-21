#include <iostream>
#include <fstream>
#include "libs/utils/basic_converter.h"
#include "libs/utils/colored_output.h"
#include "libs/enviro/game.h"
#include "libs/enviro/maps/hostile_area.h"
#include "libs/enviro/maps/peaceful_area.h"
#include "libs/enviro/commands/command_handlers.h"
#include "libs/enviro/commands/man_page.h"
#include "libs/enviro/graphics/graphics.h"
#include "libs/enviro/story/story.h"
#include "libs/entities/enemies/weaker_enemies.h"
#include "libs/entities/items/consumables.h"
#include "libs/entities/items/map_keys.h"

// private
void Game::createPlayer(){
    ColoredOutput::blue("Creating") << " player...\n";

    std::string name;
    std::string classType;
    if(this->player == nullptr){
        std::cout << "What do you want your in-game name to be? ";
        std::cin >> name;
        std::cout << "What class you want your character to be? (type in a number)\n";
        std::cout << "1. warrior (default)\n";
        std::cout << "2. wizard\n";
        std::cout << "3. assassin\n";
        std::cout << "Ans: ";
        std::cin >> classType;
    }else{
        name = this->player->getName();
        classType = std::to_string(this->player->getClassType()+1);
    }
    
    this->player = new Player(name, BasicConverter::safeToInt(classType)-1);
    this->player->forceEnter(this->maps[WAITING_AREA]); // land in the waiting area first
    this->player->getCurrentLoc()->displayInfo();
    this->player->getCurrentLoc()->displayDescription();
    this->player->addMoney(500);
    for(int i = 0; i < 5; i++)
        this->player->addToInventory(new SmallHpPotion());
    for(int i = 0; i < 2; i++)
        this->player->addToInventory(new StrengthPotion());
    this->player->addToInventory(new UnknownVillageKey());

    if(this->difficulty == DIFFICULTY_EASY){
        this->player->forceLevelup();
        this->player->forceLevelup();
        this->player->setLevel(1, 100); // just like a fresh start
    }
    if(this->difficulty == DIFFICULTY_NORMAL){
        this->player->forceLevelup();
        this->player->setLevel(1, 100);
    }
    // no statistics boosting for hard
}

void Game::setupMaps(){
    ColoredOutput::blue("Setting") << " up maps...\n";

    // Peaceful maps
    WaitingArea* waitingArea = new WaitingArea(this->difficulty);
    SpawnArea* spawnArea = new SpawnArea(this->difficulty);
    ConsumableShop* consumableShop = new ConsumableShop(this->difficulty);
    WeaponShop* weaponShop = new WeaponShop(this->difficulty);
    ArmorShop* armorShop = new ArmorShop(this->difficulty);

    // Hostile maps
    UnknownVillage* unknownVillage = new UnknownVillage(this->difficulty);
    LostWoods* lostWoods = new LostWoods(this->difficulty);
    DawnDungeon* dawnDungeon = new DawnDungeon(this->difficulty);
    CastleEntrance* castleEntrance = new CastleEntrance(this->difficulty);

    // Boss maps
    Castle_1F* castle_1F = new Castle_1F(this->difficulty);
    Castle_2F* castle_2F = new Castle_2F(this->difficulty);
    Castle_3F* castle_3F = new Castle_3F(this->difficulty);

    // Connections
    spawnArea->connectTo(unknownVillage);
    spawnArea->connectTo(consumableShop);
    spawnArea->connectTo(weaponShop);
    spawnArea->connectTo(armorShop);

    unknownVillage->connectTo(lostWoods);
    unknownVillage->connectTo(dawnDungeon);
    dawnDungeon->connectTo(castleEntrance);
    castleEntrance->connectTo(castle_1F);
    castle_1F->connectTo(castle_2F);
    castle_2F->connectTo(castle_3F);

    this->maps.push_back(waitingArea);
    this->maps.push_back(spawnArea);
    this->maps.push_back(consumableShop);
    this->maps.push_back(weaponShop);
    this->maps.push_back(armorShop);
    this->maps.push_back(unknownVillage);
    this->maps.push_back(lostWoods);
    this->maps.push_back(dawnDungeon);
    this->maps.push_back(castle_1F);
    this->maps.push_back(castle_2F);
    this->maps.push_back(castle_3F);
}

void Game::setupDifficulty(){
    std::string difficultyStr;
    std::cout << "What difficulty do you want? (type in a number)\n";
    std::cout << "1. easy\n";
    std::cout << "2. normal (default)\n";
    std::cout << "3. hard\n";
    std::cout << "Ans: ";
    std::cin >> difficultyStr;
    int difficultyInt = BasicConverter::safeToInt(difficultyStr)-1;
    if(difficultyInt == DIFFICULTY_EASY || difficultyInt == DIFFICULTY_NORMAL || difficultyInt == DIFFICULTY_HARD){
        this->difficulty = difficultyInt;
    }else{
        this->difficulty = DIFFICULTY_NORMAL;
    }
}

Game::Game(int difficulty){
    this->difficulty = difficulty;
}

bool Game::hasGameStarted(){
    return this->started;
}

void Game::gameStarted(){
    this->started = true;
}

void Game::start(){
    displayStart(this);
    startStory(this);

    this->setupMaps();
    this->setupDifficulty();
    this->createPlayer();

    ColoredOutput::blue("Game is ready") << ", type '"; ColoredOutput::blue("help") << "' to get a list of available commands\n";
    std::cout << "Type '"; ColoredOutput::blue("man <command>") << "' to see what the command do\n";
    std::cout << "For example, you can type '"; ColoredOutput::blue("man help") << "' to see what 'help' do\n";
    std::string userInput;
    std::string arg1;
    std::string arg2;
    while(userInput != "exit" && userInput != "end" && userInput != "quit"){
        ColoredOutput::red(this->player->getCurrentLoc()->getName()) << " >> ";
        std::cin >> userInput;
        // [normal] commands
        if(!this->hasGameStarted()){
            if(userInput == "start"){
                startGame(this);
            }else if(userInput == "help"){
                helpBase(this);
            }else if(userInput == "mapdesc"){
                this->player->getCurrentLoc()->displayDescription();
            }else if(userInput == "load"){
                std::cin >> arg1;
                this->load(arg1);
            }else if(userInput == "man"){
                std::string cmd;
                std::cin >> cmd;
                showManual(cmd);
            }
        }else{
            if(userInput == "engage"){
                engage(this);
            }else if(userInput == "wait"){
                gameWait(this);
            }else if(userInput == "enter"){
                std::cin >> arg1;
                enterLoc(this, BasicConverter::safeToInt(arg1));
            }else if(userInput == "unlock"){
                std::cin >> arg1;
                std::cin >> arg2;
                unlockLoc(this, BasicConverter::safeToInt(arg1), BasicConverter::safeToInt(arg2));
            }else if(userInput == "equip"){
                std::cin >> arg1;
                equipItem(this, BasicConverter::safeToInt(arg1));
            }else if(userInput == "use"){
                std::cin >> arg1;
                useItem(this, BasicConverter::safeToInt(arg1));
            }else if(userInput == "buy"){
                std::cin >> arg1;
                buyItem(this, BasicConverter::safeToInt(arg1));
            }else if(userInput == "sell"){
                std::cin >> arg1;
                sellItem(this, BasicConverter::safeToInt(arg1));
            }else if(userInput == "discard"){
                std::cin >> arg1;
                discardItem(this, BasicConverter::safeToInt(arg1));
            }else if(userInput == "shop"){
                printShopItems(this);
            }else if(userInput == "mapdesc"){
                printMapDescription(this);
            }else if(userInput == "info"){
                std::cout << "Game difficulty: "; ColoredOutput::blue(std::to_string(this->difficulty)) << "\n";
                this->player->displayPlayerStatus();
                this->player->getCurrentLoc()->displayInfo();
            }else if(userInput == "where"){
                this->player->getCurrentLoc()->displayInfo();
            }else if(userInput == "stat"){
                this->player->displayPlayerStatus();
            }else if(userInput == "skills"){
                this->player->displaySkills();
            }else if(userInput == "inventory"){
                printInventory(this);
            }else if(userInput == "map"){
                displayMap(this);
            }else if(userInput == "help"){
                helpBase(this);
            }else if(userInput == "save"){
                std::cin >> arg1;
                this->save(arg1);
            }else if(userInput == "load"){
                std::cin >> arg1;
                this->load(arg1);
            }else if(userInput == "man"){
                std::string cmd;
                std::cin >> cmd;
                showManual(cmd);
            }
        }

        if(this->player->isDead()){
            for(int i = 0; i < 10; i++)
                std::cout << ".\n";
            ColoredOutput::red("You are dead. Resetting...\n");
            for(int i = 0; i < 10; i++)
                std::cout << ".\n";
            this->started = false;
            delete this->player;
            this->createPlayer();
        }
    }
}

void Game::exitGame(){
    exit(0);
}

void Game::updateMaps(){
    for(int i = 0; i < this->maps.size(); i++){
        this->maps[i]->update();
    }
}

void Game::save(std::string filename){
    ColoredOutput::blue("Saving...\n");
    std::fstream instream(filename + ".rtc");
    if(instream.good()){
        ColoredOutput::blue(filename + ".rtc") << " exists. Please use another filename.\n";
        return;
    }
    instream.open(filename + ".rtc", std::ios::out);
    instream << "[start]\n";
    instream << this->player->exportData(this->player);
    instream << "[end]\n";
    
    instream.close();
}

void Game::load(std::string filename){
    ColoredOutput::blue("Loading...\n");
    std::fstream instream;
    instream.open(filename + ".rtc", std::ios::in);
    if(instream.fail()){
        ColoredOutput::red("Error: ") << "Cannot open file of name "; ColoredOutput::blue(filename + ".rtc") << "\n";
        return;
    }
    std::string line;
    std::getline(instream, line);
    if(line != "[start]"){
        ColoredOutput::red("Error: ") << "Invalid game save header\n";
        return;
    }
    while(std::getline(instream, line)){
        if(line == "[player]"){
            Player* p = Player::load(instream, this);
            p->displayPlayerStatus();
            this->player = p;
            continue;
        }else if(line == "[end]"){
            break;
        }
    }
    instream.close();
}