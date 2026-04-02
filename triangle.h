#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure{
private:
    Point point1, point2, point3;
public:
    Triangle(const std::string& name, Point point1, Point point2, Point point3) :
        Figure(name), point1(point1), point2(point2), point3(point3){
        if (!Triangle::getArea())
            throw FigureException("The triangle is degenerate\n");
    }

    double getArea() const override{
        return 0.5 * std::abs(point1.getX() * (point2.getY() - point3.getY())
                              + point2.getX()*(point3.getY() - point1.getY()) + point3.getX() * (point1.getY() - point2.getY()));
    }

    std::string getParams() const override{
        return ", peaks: (" + std::to_string(point1.getX()) + ", " + std::to_string(point1.getY()) + "), (" + std::to_string(point2.getX())
        + ", " + std::to_string(point2.getY()) + "), (" + std::to_string(point3.getX()) + ", " + std::to_string(point3.getY()) + ")";
    }

    std::string getType() const override{
        return "Triangle";
    }
};

#endif // TRIANGLE_H
