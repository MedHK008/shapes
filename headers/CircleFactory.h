#ifndef CIRCLE_FACTORY_H
#define CIRCLE_FACTORY_H

#include "ShapeFactory.h"
#include "Circle.h"

class CircleFactory : public ShapeFactory {
public:
    Circle* create(double radius) {
        return new Circle(radius);
    }
};

#endif // CIRCLE_FACTORY_H
