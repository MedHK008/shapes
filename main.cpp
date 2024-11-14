#include <iostream>
#include "Shape.h"

#include "SquareFactory.h"
#include "CircleFactory.h"

int main() {
    ShapeFactory* squareFactory = new SquareFactory();
    ShapeFactory* circleFactory = new CircleFactory();

    Shape* square = squareFactory->create(5);
    Shape* circle = circleFactory->create(5);

    square->draw();
    circle->draw();

    delete square;
    delete circle;
    delete squareFactory;
    delete circleFactory;

    return 0;
}
