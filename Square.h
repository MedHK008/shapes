#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
public:
    Square(double side);
    void draw() const override;

private:
    double side;
};

#endif // SQUARE_H
