#ifndef TRIANGLECREATOR_H
#define TRIANGLECREATOR_H

#include "figurecreator.h"
#include "triangle.h"

class TriangleCreator : public FigureCreator{
public:
    Figure* create(const std::string& name, Point p1, Point p2, Point p3) const{
        return new Triangle(name, p1, p2, p3);
    }
};

#endif // TRIANGLECREATOR_H
