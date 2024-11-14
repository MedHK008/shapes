#include "Circle.h"
#include <iostream>
#include <cmath>

using namespace std;

Circle::Circle(double radius) : radius(radius) {}

void Circle::draw() const {
    cout << "Drawing a circle with radius " << radius << endl;
    for (int i = 0; i <= 2 * radius; i++) {
        for (int j = 0; j <= 2 * radius; j++) {
            if (pow(i - radius, 2) + pow(j - radius, 2) <= pow(radius, 2)) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}
