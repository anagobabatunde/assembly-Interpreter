# ikf3.com for ETNA
# Usage:
#
# build with: docker build . -t containers.ikf3.com/etna/tic-crw2 and run with: 

FROM debian:buster-slim
LABEL authors="Antonio Matteo Talamona <contact@ikf3.com>, Andy Anago <contact@anago.me>"

ENV DEBIAN_FRONTEND noninteractive
RUN mkdir -p /workdir/
WORKDIR /workdir/
RUN apt-get update -y && apt-get install -qq -o=Dpkg::Use-Pty=0 -y build-essential gdb && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*