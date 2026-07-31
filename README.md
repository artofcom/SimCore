![CI](https://github.com/artofcom/SimCore/actions/workflows/ci.yml/badge.svg)
![Release](https://img.shields.io/github/v/release/artofcom/SimCore)
![C++20](https://img.shields.io/badge/C%2B%2B-20-blue)
![License](https://img.shields.io/badge/license-MIT-green)

# SimCore

> A modern C++20 robotics simulation framework built from scratch.

SimCore is a personal learning project focused on building a modular robotics simulation framework while practicing production-quality C++ software engineering.

The project is developed incrementally to better understand how robotics simulators are architected internally, covering robot kinematics, world modeling, collision detection, navigation, and autonomous control.

Rather than relying on an existing simulator, every subsystem is implemented from the ground up.

---

# Features

## Engineering

- ✅ Modern C++20
- ✅ CMake Build System
- ✅ GoogleTest
- ✅ GitHub Actions CI/CD
- ✅ Docker
- ✅ Python Build Tool
- ✅ clang-format
- ✅ spdlog
- ✅ JSON Configuration
- ✅ Automatic Resource Pipeline
- ✅ GitHub Releases

## Robotics Simulation

- ✅ 2D World
- ✅ Pose2D
- ✅ Differential Drive Kinematics
- ✅ Robot
- ✅ Goal
- ✅ Obstacle
- ✅ Circle Collision Detection

---

# Tech Stack

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

# Architecture

```
Simulation
      │
      ▼
World
 ├── Robot
 ├── Goal
 └── Obstacle
```

Current simulation flow

```
Simulation
      │
      ▼
World::Update()
      │
      ▼
Robot::Update()
      │
      ▼
Pose2D
```

---

# Project Structure

```
SimCore
│
├── include/
│   └── simcore/
│       ├── Goal.h
│       ├── Obstacle.h
│       ├── Pose2D.h
│       ├── Robot.h
│       ├── Simulation.h
│       └── World.h
│
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

# Build

```bash
python3 build.py --build
```

---

# Run

```bash
./build/console_demo
```

---

# Testing

```bash
python3 build.py --test
```

---

# Formatting

Format source code

```bash
python3 build.py --format
```

Verify formatting

```bash
python3 build.py --check-format
```

---

# Docker

Build

```bash
docker build -t simcore .
```

Run

```bash
docker run --rm simcore
```

---

# Continuous Integration

Every push automatically performs:

- Formatting Check
- CMake Build
- Docker Build
- Unit Tests

---

# Development Workflow

```
Git Push
    │
    ▼
GitHub Actions
    │
 ┌──┴───────────────┐
 │                  │
Formatting      Build & Test
 │                  │
PASS          GoogleTest
```

---

# Robotics Roadmap

## Foundation

- [x] Pose2D
- [x] Robot
- [x] World
- [x] Differential Drive Kinematics
- [x] Goal
- [x] Obstacle
- [x] Collision Detection

## Navigation

- [ ] Goal Controller
- [ ] Occupancy Grid
- [ ] A* Path Planning
- [ ] Waypoint Following

## Robotics

- [ ] Sensor Framework
- [ ] LiDAR Simulation
- [ ] Differential Drive Controller
- [ ] ROS2 Bridge

## Advanced

- [ ] Multi Robot Simulation
- [ ] Fleet Manager
- [ ] Unity Visualization

---

# Long-term Goals

- Build a reusable robotics simulation framework.
- Learn robotics algorithms by implementing them from scratch.
- Practice production-quality C++ software engineering.
- Explore ROS2 integration.
- Develop a foundation for digital twin and autonomous robotics research.

---

# Status

🚧 This project is currently under active development.

The architecture and APIs are expected to evolve as new robotics concepts are implemented.


## Current Progress

✅ Milestone 1 - Pose2D

✅ Milestone 2 - Robot Kinematics

✅ Milestone 3 - World & Collision

✅ Milestone 4 - Goal Management

🚧 Milestone 5 - Goal Controller (In Progress)

⬜ Milestone 6 - Occupancy Grid

⬜ Milestone 7 - A* Path Planning

⬜ Milestone 8 - ROS2 Integration


# License

This project is intended for educational and personal learning purposes.