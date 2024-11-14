#ifndef SQUARE_FACTORY_H
#define SQUARE_FACTORY_H

#include "ShapeFactory.h"
#include "Square.h"

class SquareFactory  : public ShapeFactory {
public:
    Square* create(double side) {
        return new Square(side);
    }
};

#endif // SQUARE_FACTORY_H
