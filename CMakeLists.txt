cmake_minimum_required(VERSION 3.0)


set(CMAKE_BUILD_TYPE Debug)
# the other flag will be appended
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(quiz-game)

# first value is name of executable
add_executable(
    quiz
    main.cpp
)