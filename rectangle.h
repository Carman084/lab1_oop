#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure{
private:
    Point point1, point2;
public:
    Rectangle(const std::string& name, Point point1, Point point2) :
        Figure(name), point1(point1), point2(point2){
        if (point2.getX() <= point1.getX() || point1.getY() <= point2.getY())
            throw FigureException("Incorrect coordinates: the rectangle is degenerate\n");
    }

    double getArea() const override{
        return (point2.getX() - point1.getX()) * (point1.getY() - point2.getY());
    }

    std::string getParams() const override{
        return ", upper left corner(" + std::to_string(point1.getX()) + ", " + std::to_string(point1.getY())
               + "), lower right corner (" + std::to_string(point2.getX()) + ", " + std::to_string(point2.getY()) + ")";
    }

    std::string getType() const override{
        return "Rectangle";
    }
};

#endif // RECTANGLE_H
