FROM debian:bullseye
WORKDIR /app

RUN apt-get update && apt-get install -y \
    git \
    gcc \
    gdb \
    vim \
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/*
