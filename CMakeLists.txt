# https://stackoverflow.com/questions/6921695/how-can-i-build-a-c-project-with-multiple-interdependent-subdirectories
cmake_minimum_required(VERSION 3.12)

set(SRC "quiz-game")
set(MAIN "${SRC}/${SRC}.cpp")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# set(CMAKE_CXX_FLAGS "add_more_flags_here")

# set project name
project(quiz)

file(GLOB_RECURSE quiz_SOURCES CONFIGURE_DEPENDS "${SRC}/*.cpp")
file(GLOB_RECURSE quiz_HEADERS CONFIGURE_DEPENDS "${SRC}/*.hpp")

set(quiz_INCLUDE_DIRS "")
foreach(_headerFile ${quiz_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list(APPEND quiz_INCLUDE_DIRS ${_dir})
endforeach()

list (REMOVE_DUPLICATES quiz_INCLUDE_DIRS)



# first value is name of executable
add_executable(
    quiz
    ${MAIN}
    "${SRC}/utility/utility.cpp"
)