cmake_minimum_required(VERSION 3.5)
project(YourProjectName)

# Add C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add your source files
set(SOURCES 
    main.cpp
    MatrixMult.cpp
)

# Add your executable target
add_executable(${PROJECT_NAME} ${SOURCES})
