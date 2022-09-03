FROM ubuntu:18.04

ARG v=3.21.3

RUN apt-get -y update && apt-get -y install --no-install-recommends \
      build-essential ca-certificates wget && \
    wget -q https://github.com/Kitware/CMake/releases/download/v${v}/cmake-${v}-linux-x86_64.sh && \
    chmod u+x cmake-${v}-linux-x86_64.sh && \
    ./cmake-${v}-linux-x86_64.sh --skip-license --prefix=/usr/local && \
    rm -f cmake-${v}-linux-x86_64.sh
