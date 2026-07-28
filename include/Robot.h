#ifndef ROBOT_H
#define ROBOT_H

#include <utility>

class Robot
{
  private:
    double x_;     // x coordinate
    double y_;     // y coordinate
    double speed_; // movement speed
    double angle_; // movement angle in radians
  public:
    // Constructor
    Robot(double x = 0.0, double y = 0.0);

    // Movement methods
    void moveForward(double distance);
    void turn(double angle);     // Turn the robot by given angle (in radians)
    void setAngle(double angle); // Set the robot's angle directly (in radians)
    // Status query methods
    std::pair<double, double> getPosition() const;
    double getAngle() const; // Get the current angle
    // Status output
    void printStatus() const;

    // Update function (called by Simulation)
    void update(float dt);

    // Set speed
    void setSpeed(double speed);

    // Scale method
    void scale(double factor);

    // Rotate method (position around origin)
    void rotate(double angle);
};

#endif // ROBOT_H
