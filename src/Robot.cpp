#include "Robot.h"
#include <cmath>
#include <iostream>

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

    std::cout << "Robot moved " << distance << " units forward. New position: (" << x_ << ", " << y_
              << ")" << std::endl;
}

std::pair<double, double> Robot::getPosition() const
{
    return std::make_pair(x_, y_);
}

void Robot::printStatus() const
{
    std::cout << "Robot position: (" << x_ << ", " << y_ << ")" << std::endl;
}

void Robot::update(float dt)
{
    // Update robot position based on speed and angle
    x_ += speed_ * cos(angle_) * dt;
    y_ += speed_ * sin(angle_) * dt;

    std::cout << "Robot update (dt: " << dt << ")" << std::endl;
    std::cout << "New position: (" << x_ << ", " << y_ << ")" << std::endl;
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

    std::cout << "Robot turned by " << angle << " radians. New angle: " << angle_ << std::endl;
}

// Set the robot's angle directly (in radians)
void Robot::setAngle(double angle)
{
    angle_ = angle;

    std::cout << "Robot angle set to " << angle << " radians" << std::endl;
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
    std::cout << "Robot scaled by " << factor << ". New position: (" << x_ << ", " << y_ << ")"
              << std::endl;
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

    std::cout << "Robot rotated by " << angle << " radians around origin."
              << " New position: (" << x_ << ", " << y_ << ")" << std::endl;
}
