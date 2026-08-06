FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    git \
    cmake \
    g++ \
    make \
    libspdlog-dev

WORKDIR /app

COPY . .

RUN cmake -S . -B build
RUN cmake --build build

WORKDIR /app/build

CMD ["ctest", "--output-on-failure"]