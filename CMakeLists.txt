cmake_minimum_required(VERSION 3.10)
project(Shapes)



add_executable(shape main.cpp Square.cpp Circle.cpp SquareFactory.h CircleFactory.h ShapeFactory.h Shape.h)