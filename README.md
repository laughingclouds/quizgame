# quiz-game

A Quiz Game written in C++ using File Handling and a Database | For subject CSR-107

## Project Members

- [Hemant Bhandari](https://github.com/laughingclouds)
- [Jagpreet Singh](https://github.com/JaGPR)
- [Prateek Sarna](https://github.com/PrateekSarna-24)
- [Shreya Singh](https://github.com/Shreya220)
- [Madhavi Gupta](https://github.com/MadhaviGupta18)

## Quiz-Game Survey

On conducting a survey among the students of Chandigarh University, we got the following responses.

A total of 42 responses were collected. The respondents belonged to the following age groups:
![Pie chart displaying the different age groups](https://user-images.githubusercontent.com/57110219/163675852-86f3ed99-fb20-4964-b6d5-e5d63f1e9fea.png)

These respondents voted on the following categories to be included in the game:
![Bar graph displaying the responses for the categories](https://user-images.githubusercontent.com/57110219/163675753-f00c19c1-8e5f-4022-b14f-299414d14d51.png)

### Top six categories

Below is the list of the six categories that received the most votes; in descending order of votes received:

1. Entertainment
2. Science
3. Sports
4. General knowledge
5. TV Shows
6. Anime

We have decided to include these six into the game. This means, every player will get the chance to start a game with any of these six categories.

## TODO

1. Read this: <https://www.freecodecamp.org/news/reusable-html-components-how-to-reuse-a-header-and-footer-on-a-website/>
2. This too: <https://stackoverflow.com/questions/14551194/how-are-parameters-sent-in-an-http-post-request>

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
cmake .. && cmake --build .
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
