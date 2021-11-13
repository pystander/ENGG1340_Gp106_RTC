#ifndef COLORED_OUTPUT_H
#define COLORED_OUTPUT_H

class ColoredOutput;

#include <iostream>
#include <string>

class ColoredOutput{
    public:
        // red
        static std::ostream& redStart(){
            std::cout << "\x1B[31m";
            return std::cout;
        }
        static std::ostream& red(std::string str){
            std::cout << "\x1B[31m" << str << "\x1B[0m";
            return std::cout;
        }
        static std::ostream& red(double str){
            std::cout << "\x1B[31m" << str << "\x1B[0m";
            return std::cout;
        }

        // green
        static std::ostream& greenStart(){
            std::cout << "\x1B[32m";
            return std::cout;
        }
        static std::ostream& green(std::string str){
            std::cout << "\x1B[32m" << str << "\x1B[0m";
            return std::cout;
        }
        static std::ostream& green(double str){
            std::cout << "\x1B[32m" << str << "\x1B[0m";
            return std::cout;
        }

        // yellow
        static std::ostream& yellowStart(){
            std::cout << "\x1B[33m";
            return std::cout;
        }
        static std::ostream& yellow(std::string str){
            std::cout << "\x1B[33m" << str << "\x1B[0m";
            return std::cout;
        }
        static std::ostream& yellow(double str){
            std::cout << "\x1B[33m" << str << "\x1B[0m";
            return std::cout;
        }

        // blue
        static std::ostream& blueStart(){
            std::cout << "\x1B[38;5;75m";
            return std::cout;
        }
        static std::ostream& blue(std::string str){
            std::cout << "\x1B[38;5;75m" << str << "\x1B[0m";
            return std::cout;
        }
        static std::ostream& blue(double str){
            std::cout << "\x1B[38;5;75m" << str << "\x1B[0m";
            return std::cout;
        }

        // cyan
        static std::ostream& cyanStart(){
            std::cout << "\x1B[36m";
            return std::cout;
        }
        static std::ostream& cyan(std::string str){
            std::cout << "\x1B[36m" << str << "\x1B[0m";
            return std::cout;
        }
        static std::ostream& cyan(double str){
            std::cout << "\x1B[36m" << str << "\x1B[0m";
            return std::cout;
        }

        // reset
        static std::ostream& reset(){
            std::cout << "\x1B[0m";
            return std::cout;
        }
};

#endif