FROM ubuntu:24.04

RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake

WORKDIR /app

COPY . .

RUN cmake -S . -B build
RUN cmake --build build

WORKDIR /app/build

CMD ["ctest", "--output-on-failure"]