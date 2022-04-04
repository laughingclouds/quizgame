# quiz-game

A Quiz Game written in C++ using File Handling and a Database | For subject CSR-107

> Note: Directory structure inspired (not completely) from [here](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1204r0.html).

## Project Members

- [Hemant Bhandari](https://github.com/laughingclouds)
- [Jagpreet Singh](https://github.com/JaGPR)
- [Prateek Sarna](https://github.com/PrateekSarna-24)
- [Shreya Singh](https://github.com/Shreya220)
- [Madhavi Gupta](https://github.com/MadhaviGupta18)

## TODO

Read this

- <https://www.freecodecamp.org/news/reusable-html-components-how-to-reuse-a-header-and-footer-on-a-website/>


## Quickstart

Paste this in your shell

```shell
pip install meson ninja
git clone https://github.com/laughingclouds/quiz-game.git
cd quiz-game
meson builddir
cd builddir
meson compile

```

Next, run the executable.

## Build

### meson

First, install meson and ninja using pip.

> minimum requirement to use meson: python 3.7

```shell
pip install meson ninja
```

create a build directory

```shell
meson builddir
```

cd into the build directory and compile

```shell
cd builddir
meson compile
```

An executable will be created (say, **quiz**). Run it (instructions below).

### cmake

I will be focussing primarily on meson. So try to use that if cmake doesn't work.

[This is a test run]
TODO: change later

First open cmd/terminal in the **build** directory; create one if it doesn't exist, and run the following command.

```shell
cmake ../
cmake --build .
```

> Note: Remember! Run this *only* while in the **build** directory.

### Run the test executable

An executable by the name of **quiz** should have appeared within **build**.
Run it.

Windows

```shell
start quiz
```

> If it doesn't work, then maybe try renaming ``quiz`` to ``quiz.exe``.

Linux

```shell
./quiz
```

## Conventions

When writing huge projects, it is important to maintain uniformity in naming of variables, directories (folders), functions, classes etc.

Hence, this README shall act as a guide to all of us, when we write the code.

### Main File

The main file for this project is ``quiz-game.cpp``.

This should have all the error handling and user interacting code. [Subject to change in the future]

### Directories

Directory names should have a "**-**"(minus sign) to separate words.

### Source Files

All ``.cpp`` and ``.hpp`` files too, should have "**-**" if they have multiple words.

Example: ``example-one.cpp``, ``example-two.cpp``, ``example-three.cpp``

### Variables and Functions

All variables, class instances, and functions should be named using *snake_case*.
Keep them descriptive, don't hesitate to use long variable names.

Example: **max_score**, **question_number**, **user_name**, **user_id**

### Including Header Files

Include user-defined header files only after including normal header files. And put a new line between them.

Example:

```c++
#include <iostream>

#include "quiz-game.hpp"

int main() {
    clear_screen();

    std::cout << "Hello World!" << std::endl;
}
```

#### More on header files

- Please place the line ``#pragma once`` at the start of every header (``.hpp``) file. This will make sure the file is included only once.

### The "using namespace std" debate

Cough, please try to not write the sweat old ``using namespace std;`` line after including the header files. More specifically, don't use namespaces **globally** (reasoning below).

- [iso cpp faq](https://isocpp.org/wiki/faq/coding-standards#using-namespace-std)
- [stackoverflow discussion](https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice)
