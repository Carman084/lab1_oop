#ifndef SOLUTION_H
#define SOLUTION_H

#include "inputhandler.h"
#include <map>
#include "creatorfactory.h"
#include <functional>

class Solution{
private:
    CreatorFactory& factory;
    InputHandler& inputHandler;
    std::map<FigureType, std::function<Figure*()>> inputFunctions;

    void initCreatorsMap(){
        inputFunctions[FigureType::CIRCLE] = [this](){
            return inputHandler.input(static_cast<CircleCreator*>(factory.getCreator(FigureType::CIRCLE))); //static_cast, чтобы метод input понимал, что метод getCreator возвращает конкретно InputCircle
        };
        inputFunctions[FigureType::RECTANGLE] = [this](){
            return inputHandler.input(static_cast<RectangleCreator*>(factory.getCreator(FigureType::RECTANGLE)));
        };
        inputFunctions[FigureType::TRIANGLE] = [this](){
            return inputHandler.input(static_cast<TriangleCreator*>(factory.getCreator(FigureType::TRIANGLE)));
        };
    }
public:
    Solution(CreatorFactory& factory, InputHandler& inputHandler) : factory(factory), inputHandler(inputHandler){
        initCreatorsMap();
    }

    ~Solution(){
        inputFunctions.clear();
    }

    Figure* makeFigure(FigureType figure){
        return inputFunctions[figure]();
    }
};

#endif // SOLUTION_H
