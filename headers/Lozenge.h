
#ifndef LOZENGE_H
#define LOZENGE_H

#include "Shape.h"

class Lozenge : public Shape {
public:
    Lozenge(double diagonal);
    void draw() const override;
    double area() const override;
    double perimeter() const override;
private:
    double diagonal;
};

#endif // LOZENGE_H