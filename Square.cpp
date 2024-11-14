#include "Square.h"
#include <iostream>

Square::Square(double side) : side(side) {}

void Square::draw() const {
    std::cout << "Drawing a square with side " << side << std::endl;
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }    
}



