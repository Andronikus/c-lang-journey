FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    cppcheck \
    gdb \
    clang \
    gcc \
    g++ \
    git \
    iputils-ping \
    vim \
    curl \
    wget \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /usr/src/app

CMD ["/bin/bash"]