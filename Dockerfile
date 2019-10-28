# ikf3.com for ETNA
# Usage:
#
# build with: docker build . -t containers.ikf3.com/etna/tic-crw2 and run with: 

FROM debian:buster-slim
LABEL authors="Antonio Matteo Talamona <contact@ikf3.com>, Andy Anago <contact@anago.me>"

ENV DEBIAN_FRONTEND noninteractive

RUN mkdir -p /root/work/
WORKDIR /root/work/

COPY . /root/work/

RUN apt-get update -y && apt-get install -y vim git make gcc && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

ENTRYPOINT ["/bin/bash"]
