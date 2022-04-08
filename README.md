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

### Install the Drogon framework

Linux: <https://drogon.docsforge.com/master/installation/>
Windows: <https://drogon.docsforge.com/master/installation/#use-vcpkg>

### Compile and run

```shell
git clone https://github.com/laughingclouds/quiz-game.git
cd quiz-game
mkdir build
cd build
cmake .. && make
```

Next, run the executable.

```shell
./quiz-game
```

## Build and Run

### cmake

Because the drogon cli (drogon_ctl) sets everything up, working
with cmake becomes easier.

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

Linux

```shell
./quiz
```