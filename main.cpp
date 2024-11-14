#include <iostream>

#include "SquareFactory.h"
#include "CircleFactory.h"
#include "TriangleFactory.h"
#include "LozengeFactory.h"

#include "Shape.h"

using namespace std;


int main()
{

    ShapeFactory* squareFactory=new SquareFactory();
    ShapeFactory* circleFactory=new CircleFactory();
    ShapeFactory* triangleFactory=new TriangleFactory();
    ShapeFactory* lozengeFactory=new LozengeFactory();

    Shape* square=squareFactory->create(5);
    Shape* circle=circleFactory->create(5);
    Shape* triangle=triangleFactory->create(5);
    Shape* lozenge=lozengeFactory->create(5);

    square->draw();
    circle->draw();
    triangle->draw();
    lozenge->draw();

    cout<<"Square area: "<<square->area()<<endl;
    cout<<"Circle area: "<<circle->area()<<endl;
    cout<<"Triangle area: "<<triangle->area()<<endl;
    cout<<"Lozenge area: "<<lozenge->area()<<endl;

    cout<<"Square perimeter: "<<square->perimeter()<<endl;
    cout<<"Circle perimeter: "<<circle->perimeter()<<endl;
    cout<<"Triangle perimeter: "<<triangle->perimeter()<<endl;
    cout<<"Lozenge perimeter: "<<lozenge->perimeter()<<endl;

    delete square;
    delete circle;
    delete triangle;
    delete lozenge;

    delete squareFactory;
    delete circleFactory;
    delete triangleFactory;
    delete lozengeFactory;

    return 0;
}
