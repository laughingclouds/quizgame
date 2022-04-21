FROM drogonframework/drogon

WORKDIR /src
COPY . .

ENV BUILD_DIR_NAME="build" \
    EXECUTABLE_NAME="quiz_game"

# We ignore $BUILD_DIR in .dockerignore
# Hence we're making one again
RUN mkdir ${BUILD_DIR_NAME}

WORKDIR ${BUILD_DIR_NAME}

RUN cmake ../ && cmake --build .
ENTRYPOINT [ "./quiz_game" ]

# LABEL Name=quiz-game