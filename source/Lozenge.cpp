
#include "../headers/Lozenge.h"
#include <iostream>
#include <cmath>

Lozenge::Lozenge(double diagonal) : diagonal(diagonal) {}

void Lozenge::draw() const {
    std::cout<<"Drawing a lozenge with diagonal "<<diagonal<<std::endl;
    int n=diagonal / 2;
    for (int i=0; i <= n; i++) {
        for (int j=0; j < n - i; j++) {
            std::cout<<" ";
        }
        for (int j=0; j < 2*i + 1; j++) {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
    for (int i=n - 1; i >= 0; i--) {
        for (int j=0; j < n - i; j++) {
            std::cout<<" ";
        }
        for (int j=0; j < 2*i + 1; j++) {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
}

double Lozenge::area() const {
    return diagonal*diagonal / 2;
}

double Lozenge::perimeter() const {
    return 4*sqrt(2)*diagonal;
}