
#include "../headers/Triangle.h"
#include <iostream>

Triangle::Triangle(double side) : side(side) {}

void Triangle::draw() const {
    std::cout<<"Drawing a triangle with side "<<side<<std::endl;
    for (int i=1; i <= side; i++) {
        for (int j=0; j < i; j++) {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
}

double Triangle::area() const {
    return side*side / 2;
}

double Triangle::perimeter() const {
    return 3*side;
}