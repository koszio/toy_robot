#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

enum class Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST,
};

class ToyRobot {
   public:
    bool placed_;
    int x_;
    int y_;
    Direction direction_;

    // Create a constructor with given fields
    ToyRobot() : placed_(false), x_(0), y_(0), direction_(Direction::NORTH) {}

    // Place the robot at the given position and facing the given direction.
    // If the position is invalid (i.e. falls off the table), the command is
    // ignored.
    void place(int x, int y, Direction direction);

    // Move the robot one unit forward in the direction it is currently facing.
    // If the move would cause the robot to fall off the table, the command is
    // ignored.
    void move();

    // Rotate the robot 90 degrees left.
    void left();

    // Rotate the robot 90 degrees right.
    void right();
    // Announce the X, Y, and F of the robot.
    void report();
};
