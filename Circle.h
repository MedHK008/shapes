#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
    Circle(double radius);
    void draw() const override;
private:
    double radius;
};

#endif // CIRCLE_H
