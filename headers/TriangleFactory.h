
#ifndef TRIANGLE_FACTORY_H
#define TRIANGLE_FACTORY_H

#include "ShapeFactory.h"
#include "Triangle.h"

class TriangleFactory : public ShapeFactory {
public:
    Triangle* create(double side) {
        return new Triangle(side);
    }
};

#endif // TRIANGLE_FACTORY_H