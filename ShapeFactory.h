#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include "Shape.h"

class ShapeFactory {
public:
    virtual Shape* create(double) = 0;
    virtual ~ShapeFactory() = default;
};

#endif // SHAPE_FACTORY_H