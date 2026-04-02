#ifndef FIGURE_H
#define FIGURE_H

#include <string>
#include <iostream>
#include <cmath>
#include "point.h"
#include "figureexception.h"

class Figure {
protected:
    std::string name;
public:
    Figure(const std::string& name) : name(name){}
    virtual ~Figure() = default;
    std::string getName() const{
        return name;
    }
    virtual std::string getType() const = 0;
    virtual double getArea() const = 0;
    virtual std::string getParams() const = 0;
};

#endif // FIGURE_H
