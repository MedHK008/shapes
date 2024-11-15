cmake_minimum_required(VERSION 3.10)
project(Shapes)



include_directories(headers)

add_library(
    shape SHARED
    source/Square.cpp source/Circle.cpp 
    source/Lozenge.cpp source/Triangle.cpp
    headers/Square.h headers/Circle.h
    headers/SquareFactory.h headers/CircleFactory.h
    headers/ShapeFactory.h headers/Shape.h
    headers/Lozenge.h headers/LozengeFactory.h
    headers/Triangle.h headers/TriangleFactory.h
)

include_directories(${shape_INCLUDE_DIRS})

add_executable(Shapes main.cpp)

target_link_libraries(Shapes shape)

install(TARGETS shape
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)
install(DIRECTORY headers/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)

install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/shapeConfig.cmake"
    DESTINATION lib/cmake/shape)