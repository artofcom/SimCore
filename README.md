![CI](https://github.com/artofcom/SimCore/actions/workflows/ci.yml/badge.svg)
![Release](https://img.shields.io/github/v/release/artofcom/SimCore)
![C++20](https://img.shields.io/badge/C%2B%2B-20-blue)
![License](https://img.shields.io/badge/license-MIT-green)

# SimCore

> A modern C++20 simulation framework demonstrating production-style engineering practices.

SimCore is a personal learning project focused on building a reusable C++ development workflow for simulation, robotics, and game engine projects.

Instead of only implementing simulation logic, this project emphasizes modern software engineering practices including CI/CD, Docker, testing, logging, formatting, and configuration management.

---

## Features

- ✅ Modern C++20
- ✅ CMake Build System
- ✅ GoogleTest Unit Testing
- ✅ GitHub Actions CI/CD
- ✅ Docker Build & Test
- ✅ Python Build Tool
- ✅ clang-format
- ✅ spdlog Logging
- ✅ JSON Configuration System
- ✅ Automatic Resource Pipeline
- ✅ GitHub Releases

---

## Tech Stack

| Category | Technology |
|-----------|------------|
| Language | C++20 |
| Build | CMake |
| Testing | GoogleTest |
| CI/CD | GitHub Actions |
| Container | Docker |
| Formatting | clang-format |
| Logging | spdlog |
| Configuration | nlohmann/json |
| Automation | Python |

---

## Project Structure

```text
SimCore
│
├── include/
├── src/
├── tests/
├── examples/
├── config/
├── .github/
│   └── workflows/
├── build.py
├── Dockerfile
└── CMakeLists.txt
```

---

## Build

```bash
cmake -S . -B build
cmake --build build
```

---

## Run

```bash
./build/console_demo
```

---

## Python Build Tool

Build

```bash
python build.py --build
```

Run Tests

```bash
python build.py --test
```

Format

```bash
python build.py --format
```

Format Check

```bash
python build.py --check-format
```

---

## Docker

Build

```bash
docker build -t simcore .
```

Run

```bash
docker run --rm simcore
```

---

## Continuous Integration

Every push automatically runs:

- Code formatting check
- Docker build
- Unit tests

---

## Engineering Workflow

```text
Git Push
    │
    ▼
GitHub Actions
    │
 ┌──┴────────────┐
 │               │
Quality      Docker
 │               │
Format      Build
 │               │
PASS        GoogleTest
```

---

## Roadmap

### Completed

- [x] Modern C++20
- [x] CMake
- [x] GoogleTest
- [x] GitHub Actions
- [x] Docker
- [x] Python Build Tool
- [x] clang-format
- [x] spdlog
- [x] JSON Configuration
- [x] Resource Pipeline

### Planned

- [ ] clang-tidy
- [ ] Code Coverage
- [ ] Benchmark
- [ ] ROS2 Integration
- [ ] Fleet Manager
- [ ] Unity Sample Project

---

## Purpose

This repository serves as a reusable engineering template for future C++ projects, including robotics, simulation, and game engine development.

The long-term goal is to establish a consistent development workflow that can be shared across native C++ libraries and Unity-based applications.