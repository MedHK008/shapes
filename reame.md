## dynamic library
this is a dynamic library, can be static if we replace the `SHARED` with `STATIC` in `CMakeLists.txt` :

```sh

add_library(
    shape SHARED/STATIC
    source/Square.cpp source/Circle.cpp 
    source/Lozenge.cpp source/Triangle.cpp
    headers/Square.h headers/Circle.h
    headers/SquareFactory.h headers/CircleFactory.h
    headers/ShapeFactory.h headers/Shape.h
    headers/Lozenge.h headers/LozengeFactory.h
    headers/Triangle.h headers/TriangleFactory.h
)

```

### Static Libraries (`.a` files)
- **File Extension**: `.a` (archive)
- **Linking**: Static libraries are linked at compile time. This means that the code from the library is copied into the executable at the time the application is built.
- **Distribution**: The resulting executable is self-contained and does not require the static library to be present on the system where the executable runs.
- **Size**: The executable file size is larger because it includes the code from the static library.
- **Performance**: Can be slightly faster at runtime since no dynamic linking is required.
- **Updates**: To update the library, you need to recompile the application with the new version of the library.

### Dynamic Libraries (`.so` files)
- **File Extension**: `.so` (shared object)
- **Linking**: Dynamic libraries are linked at runtime. The executable contains references to the shared library, which is loaded into memory when the application starts.
- **Distribution**: The executable is smaller, but the shared library must be present on the system where the executable runs.
- **Size**: The executable file size is smaller because it does not include the code from the dynamic library.
- **Performance**: May have a slight overhead at runtime due to dynamic linking.
- **Updates**: You can update the library without recompiling the application, as long as the interface (API) remains compatible.

### Example in 

CMakeLists.txt


To create a `static` library:
```cmake

add_library(shape STATIC
    source/Square.cpp source/Circle.cpp 
    source/Lozenge.cpp source/Triangle.cpp
    headers/Square.h headers/Circle.h
    headers/SquareFactory.h headers/CircleFactory.h
    headers/ShapeFactory.h headers/Shape.h
    headers/Lozenge.h headers/LozengeFactory.h
    headers/Triangle.h headers/TriangleFactory.h
)
```

To create a `dynamic` library:
```cmake
add_library(shape SHARED
    source/Square.cpp source/Circle.cpp 
    source/Lozenge.cpp source/Triangle.cpp
    headers/Square.h headers/Circle.h
    headers/SquareFactory.h headers/CircleFactory.h
    headers/ShapeFactory.h headers/Shape.h
    headers/Lozenge.h headers/LozengeFactory.h
    headers/Triangle.h headers/TriangleFactory.h
)
```

there is a part of the `cmake file` commented, i used it to install the library on my system, so that i can use it in another program, without having the .cpp and .h in and .so file in the project directory, in the new project - the one without the source files- i tried with the same main, and a `cmakeLists` : 

```cmake
cmake_minimum_required(VERSION 3.10)
project(NewProject)

set(CMAKE_PREFIX_PATH "/usr/local")

find_package(shape REQUIRED)

include_directories(${Shape_INCLUDE_DIRS})

add_executable(new_project main.cpp)

target_link_libraries(new_project ${Shape_LIBRARIES})
```

still working on it.
