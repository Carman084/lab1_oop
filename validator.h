#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <limits>
#include <iostream>
#include "validationexception.h"

class Validator{
public:
    Validator() = delete;
    static void checkInput(bool value){
        if (value){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw ValidationException("Error of input\n");
        }
    }

    static void checkChoice(int choice, int size){
        if (choice < 1 || choice > size)
            throw ValidationException("Incorrect choice\n");
    }

    static void checkEmptyVector(bool value){
        if (value)
            throw ValidationException("The list of figures is empty\n");
    }

    static void checkDelFigure(bool value){
        if (value)
            throw ValidationException("Error of number\n");
    }

    static void checkArea(double area){
        if (area <= 0)
            throw ValidationException("Incorrect area\n");
    }
};

#endif // VALIDATOR_H
