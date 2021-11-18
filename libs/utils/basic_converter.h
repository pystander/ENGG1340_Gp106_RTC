#ifndef BASIC_CONVERTER_H
#define BASIC_CONVERTER_H

class BasicConverter;

#include <string>
#include "libs/utils/colored_output.h"

class BasicConverter{
    public:
        /**
         * -1 if error occured. That's why you should 
         * use this function for positive integers.
         */
        static int intFromString(std::string str){
            try{
                return std::stoi(str);
            }catch(std::invalid_argument exception){
                ColoredOutput::red("Error") << ": "; ColoredOutput::blue(str) << " is not a valid number\n";
                return -1;
            }
        }
};

#endif