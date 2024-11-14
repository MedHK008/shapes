
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
public:
    Triangle(double side);
    void draw() const override;
    double area() const override;
    double perimeter() const override;
private:
    double side;
};

#endif // TRIANGLE_H