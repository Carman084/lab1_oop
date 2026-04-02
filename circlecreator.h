#ifndef CIRCLECREATOR_H
#define CIRCLECREATOR_H

#include "figurecreator.h"
#include "circle.h"

class CircleCreator : public FigureCreator{
public:
    Figure* create(const std::string& name, Point centre, double radius) const{
        return new Circle(name, centre, radius);
    }
};


#endif // CIRCLECREATOR_H
