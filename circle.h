#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class Circle : public Figure{
private:
    Point centre;
    double radius;
public:
    Circle(const std::string& name, Point centre, double radius) : Figure(name), centre(centre), radius(radius){
        if (radius <= 0)
            throw FigureException("The radius must be positive\n");
    }

    double getArea() const override{
        return M_PI * radius * radius;
    }

    std::string getParams() const override{
        return ", centre(" + std::to_string(centre.getX()) + ", " + std::to_string(centre.getY()) + "), radius: " + std::to_string(radius);
    }

    std::string getType() const override{
        return "Circle";
    }
};

#endif // CIRCLE_H
