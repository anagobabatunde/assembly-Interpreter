# ikf3.com for ETNA
# Usage:
#
# build with: docker build . -t containers.ikf3.com/etna/tic-crw2 and run with: 

FROM alpine:latest
LABEL authors="Antonio Matteo Talamona <contact@ikf3.com>, Andy Anago <contact@anago.me>"

RUN apk add --no-cache git make gcc gdb libc-dev && mkdir -p /workdir
WORKDIR /workdir/