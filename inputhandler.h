#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <iostream>
#include "validator.h"
#include "point.h"
#include "creatorfactory.h"

class InputHandler {
public:
    Figure* input(CircleCreator* creator) {
        double x, y, radius;
        std::string name;
        std::cout << "Enter the name, coordinates of the center (x y) and radius: ";
        std::cin >> name >> x >> y >> radius;
        Validator::checkInput(std::cin.fail());
        return creator->create(name, Point(x, y), radius);
    }

    Figure* input(RectangleCreator* creator) {
        double x1, y1, x2, y2;
        std::string name;
        std::cout << "Enter the name, upper left (x y) and lower right corners (x y): ";
        std::cin >> name >> x1 >> y1 >> x2 >> y2;
        Validator::checkInput(std::cin.fail());
        return creator->create(name, Point(x1, y1), Point(x2, y2));
    }

    Figure* input(TriangleCreator* creator) {
        double x1, y1, x2, y2, x3, y3;
        std::string name;
        std::cout << "Enter the name, first vertex (x y), second vertex (x y), third vertex (x y): ";
        std::cin >> name >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Validator::checkInput(std::cin.fail());
        return creator->create(name, Point(x1, y1), Point(x2, y2), Point(x3, y3));
    }
};

#endif // INPUTHANDLER_H
