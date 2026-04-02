#ifndef CREATORFACTORY_H
#define CREATORFACTORY_H

#include <map>
#include "figuretypes.h"
#include "circlecreator.h"
#include "rectanglecreator.h"
#include "trianglecreator.h"


class CreatorFactory {
private:
    std::map<FigureType, FigureCreator*> creators;
public:
    CreatorFactory() {
        creators[FigureType::CIRCLE] = new CircleCreator();
        creators[FigureType::RECTANGLE] = new RectangleCreator();
        creators[FigureType::TRIANGLE] = new TriangleCreator();
    }

    ~CreatorFactory() {
        for (auto it = creators.begin(); it != creators.end(); ++it)
            delete it->second;
        creators.clear();
    }

    FigureCreator* getCreator(FigureType type) {
        return creators[type];
    }
};

#endif // CREATORFACTORY_H
