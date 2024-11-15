## dynamic library
> **Warning**: this was done on linux, the lib file is .so, and installation directories are linux os's


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

## How to use this library on other project

### the current project code
the cmake files conatain the part : 

``` cmake
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
```
The first `install` command is used to install the target named `shape`. The `TARGETS` keyword indicates that this command is dealing with a target, which is typically an executable or a library, in our case a library. The `LIBRARY DESTINATION lib` line specifies that any shared libraries associated with the `shape` target should be installed in the `lib` directory. Similarly, `ARCHIVE DESTINATION lib` indicates that static libraries should also be placed in the `lib` directory, i included this line for explanatory reasons. The `RUNTIME DESTINATION bin` line specifies that executable files should be installed in the `bin` directory.

The second `install` command is used to install header files. The `DIRECTORY` keyword indicates that a directory is being installed. The `headers` directory is specified as the source, and the `DESTINATION include` line indicates that the header files should be installed in the `include` directory. The `FILES_MATCHING PATTERN "*.h"` part ensures that only files with the `.h` extension (header files) are included in this installation step.

The third `install` command installs a specific file,`shapeConfig.cmake`, which is a configuration file for the `shape` project. The `FILES` keyword is used to specify individual files to be installed. The `${CMAKE_CURRENT_SOURCE_DIR}/shapeConfig.cmake` part uses a CMake variable to specify the path to the file relative to the current source directory. The `DESTINATION lib/cmake/shape` line indicates that this file should be installed in the `lib/cmake/shape` directory.

### the new project you want to use this lib in

with this cmake Code : 

```cmake
cmake_minimum_required(VERSION 3.10)
project(testShapes)

set(CMAKE_PREFIX_PATH "/usr/local")


find_package(shape REQUIRED CONFIG)

include_directories(${shape_INCLUDE_DIRS})

add_executable(testShapes main.cpp)

target_link_libraries(testShapes ${shape_LIBRARIES})
```

The `set` command is used to define the `CMAKE_PREFIX_PATH` variable, which specifies the base directory for searching for packages. Here, it is set to `/usr/local`, the directory in which we installed the liberary component in the first library project, indicating that CMake should look in this directory for any required packages.

The `find_package` command is used to locate the `shape` package, which is required for this project. The `REQUIRED` keyword ensures that CMake will generate an error if the `shape` package is not found. The `CONFIG` keyword indicates that the package should be found using a configuration file,named `shapeConfig.cmake` The `include_directories` command adds the directories specified by the `shape_INCLUDE_DIRS` variable to the list of directories that the compiler will search for header files. This variable is set by the `shape` package configuration file.