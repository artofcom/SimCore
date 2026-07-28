#include "Robot.h"
#include <cmath>
#include <spdlog/spdlog.h>

// M_PI definition (when M_PI is not defined)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Robot class implementation
Robot::Robot(double x, double y) : x_(x), y_(y), speed_(0.0), angle_(0.0) {}

void Robot::moveForward(double distance)
{
    // Move forward in the current direction (angle_)
    x_ += distance * cos(angle_);
    y_ += distance * sin(angle_);

    spdlog::info("Robot moved : {}, units forward. New position: ({}, {})", distance, x_, y_);
}

std::pair<double, double> Robot::getPosition() const
{
    return std::make_pair(x_, y_);
}

void Robot::printStatus() const
{
    spdlog::info("Robot position: ({}, {})", x_, y_);
}

void Robot::update(float dt)
{
    // Update robot position based on speed and angle
    x_ += speed_ * cos(angle_) * dt;
    y_ += speed_ * sin(angle_) * dt;

    spdlog::info("Robot update (dt: {})", dt);
    spdlog::info("New position: ({}, {})", x_, y_);
}

// Set methods implementation
void Robot::setSpeed(double speed)
{
    speed_ = speed;
}

// Turn the robot by a given angle (in radians)
void Robot::turn(double angle)
{
    angle_ += angle;

    spdlog::info("Robot turned by {} radians. New angle : {}", angle, angle_);
}

// Set the robot's angle directly (in radians)
void Robot::setAngle(double angle)
{
    angle_ = angle;
    spdlog::info("Robot angle set to {} radians", angle);
}

// Get the current angle
double Robot::getAngle() const
{
    return angle_;
}

// Scale function implementation
void Robot::scale(double factor)
{
    x_ *= factor;
    y_ *= factor;
    spdlog::info("Robot scaled by {}, New position({}, {})", factor, x_, y_);
}

// Rotate function implementation
void Robot::rotate(double angle)
{
    double cosA = cos(angle);
    double sinA = sin(angle);
    double newX = x_ * cosA - y_ * sinA;
    double newY = x_ * sinA + y_ * cosA;
    x_ = newX;
    y_ = newY;

    spdlog::info("Robot rotated by {} radians around origin., New position({}, {})", angle, x_, y_);
}
