#ifndef RECTANGLECREATOR_H
#define RECTANGLECREATOR_H

#include "figurecreator.h"
#include "rectangle.h"

class RectangleCreator : public FigureCreator{
public:
    Figure* create(const std::string& name, Point p1, Point p2) const{
        return new Rectangle(name, p1, p2);
    }
};

#endif // RECTANGLECREATOR_H
