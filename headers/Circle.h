
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
    Circle(double radius);
    void draw() const override;
    double area() const override;
    double perimeter() const override;
private:
    double radius;
};

#endif // CIRCLE_H