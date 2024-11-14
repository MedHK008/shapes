#ifndef SHAPE_H
#define SHAPE_H




class Shape {
public:
    virtual ~Shape()=default;
    virtual void draw() const=0;
    virtual double area() const=0;
    virtual double perimeter() const=0;
};

#endif // SHAPE_H
