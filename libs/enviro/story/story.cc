#include <iostream>
#include <iomanip>
#include "libs/enviro/story/story.h"
#include "libs/enviro/game.h"
#include "libs/enviro/graphics/graphics.h"
#include "libs/utils/colored_output.h"

/*
A good RPG game must come with a great story.
The main protagonist needs to accomplish or achieve something great.
But time is always a scarce resource.

Words from Rain Leung
*/

void startStory(Game* game){
    std::cout << "Once upon a time, somewhere in a land full of monsters." << std::endl;
    std::cout << "The land beneath ones feet was once stepped by the three ancient Gods." << std::endl;
    std::cout << "But one day, the Gods suddenly disappeared and never return." << std::endl;
    std::cout << "Without protection from the Gods, people were miserably ravaged by monsters." << std::endl;
    std::cout << "But people did not lose their faith and had been waiting for their return" << std::endl;
    std::cout << std::endl;
    ColoredOutput::blue("Press any key to continue...\n");
    getchar();
    displayMagician(game);
    std::cout << std::endl;
    std::cout << "As the Prophecy foretold:" << std::endl;
    std::cout << std::endl;
    std::cout << "There will be a hero," << std::endl;
    std::cout << "walk through The Road to Castle." << std::endl;
    std::cout << "To reclaim, to reap all sorrow," << std::endl;
    std::cout << "the truth shall then unravel." << std::endl;
    std::cout << std::endl;
    std::cout << "Tick-tock, tick-tock," << std::endl;
    std::cout << "the Wheel of Fate starts to turn." << std::endl;
    std::cout << "When the key meets the lock," << std::endl;
    std::cout << "the land shall speak his name and yarn." << std::endl;
    std::cout << std::endl;
    ColoredOutput::blue("Press any key to continue...\n");
    getchar();
}

void endingStory(Game* game){
    std::cout << "You put the key into the lock, turn it and unlock the door." << std::endl;
    std::cout << "After the door, you only see a dull and hollow entrance." << std::endl;
    std::cout << "You are determined, and walk into the darkness." << std::endl;
    getchar();
    std::cout << "It is completely dark, a little spark will be a dazzle for you." << std::endl;
    std::cout << "You continue to walk, alone." << std::endl;
    std::cout << "Not knowing how long, or how far have you gone." << std::endl;
    std::cout << "Eventually, you see a soft, but bright light in front." << std::endl;
    // Not finished
}