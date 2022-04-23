FROM alpine:3.15.4

ENV TZ=UTC

RUN apk update && apk --no-cache --upgrade add tzdata \
    && ln -snf /usr/share/zoneinfo/$TZ /etc/localtime \
    && echo $TZ > /etc/timezone

# it would return an error about "bash" not being found
# turns out it's not installed in alpine by default
RUN apk --no-cache --upgrade add \
    bash \
    curl wget cmake make pkgconfig git gcc g++ \
    openssl libressl-dev jsoncpp-dev util-linux-dev zlib-dev c-ares-dev \
    sqlite-dev


ENV LANG=en_US.UTF-8 \
    LANGUAGE=en_US:en \
    LC_ALL=en_US.UTF-8 \
    CC=gcc \
    CXX=g++ \
    AR=gcc-ar \
    RANLIB=gcc-ranlib \
    IROOT=/install

ENV DROGON_ROOT="$IROOT/drogon"

ADD https://api.github.com/repos/an-tao/drogon/git/refs/heads/master $IROOT/version.json

RUN git clone https://github.com/an-tao/drogon $DROGON_ROOT

WORKDIR $DROGON_ROOT

RUN ./build.sh