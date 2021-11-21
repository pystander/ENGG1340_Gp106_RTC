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
        static std::string redStr(std::string str){
            return "\x1B[31m" + str + "\x1B[0m";
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
        static std::string greenStr(std::string str){
            return "\x1B[32m" + str + "\x1B[0m";
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
        static std::string yellowStr(std::string str){
            return "\x1B[33m" + str + "\x1B[0m";
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
        static std::string blueStr(std::string str){
            return "\x1B[38;5;75m" + str + "\x1B[0m";
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
        static std::string cyanStr(std::string str){
            return "\x1B[36m" + str + "\x1B[0m";
        }

        // reset
        static std::ostream& reset(){
            std::cout << "\x1B[0m";
            return std::cout;
        }
};

#endif