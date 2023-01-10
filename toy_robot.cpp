#include "toy_robot.h"

void ToyRobot::place(int x, int y, Direction direction) {
    if (x >= 0 && x < 5 && y >= 0 && y < 5) {
        placed_ = true;
        x_ = x;
        y_ = y;
        direction_ = direction;
    }
}
// Move the robot one unit forward in the direction it is currently facing.
// If the move would cause the robot to fall off the table, the command is
// ignored.
void ToyRobot::move() {
    if (!placed_) {
        return;
    }
    int new_x = x_;
    int new_y = y_;
    switch (direction_) {
        case Direction::NORTH:
            new_y++;
            break;
        case Direction::EAST:
            new_x++;
            break;
        case Direction::SOUTH:
            new_y--;
            break;
        case Direction::WEST:
            new_x--;
            break;
    }
    if (new_x >= 0 && new_x < 5 && new_y >= 0 && new_y < 5) {
        x_ = new_x;
        y_ = new_y;
    }
}

// Rotate the robot 90 degrees left.
void ToyRobot::left() {
    if (!placed_) {
        return;
    }
    switch (direction_) {
        case Direction::NORTH:
            direction_ = Direction::WEST;
            break;
        case Direction::EAST:
            direction_ = Direction::NORTH;
            break;
        case Direction::SOUTH:
            direction_ = Direction::EAST;
            break;
        case Direction::WEST:
            direction_ = Direction::SOUTH;
            break;
    }
}

// Rotate the robot 90 degrees right.
void ToyRobot::right() {
    if (!placed_) {
        return;
    }
    switch (direction_) {
        case Direction::NORTH:
            direction_ = Direction::EAST;
            break;
        case Direction::EAST:
            direction_ = Direction::SOUTH;
            break;
        case Direction::SOUTH:
            direction_ = Direction::WEST;
            break;
        case Direction::WEST:
            direction_ = Direction::NORTH;
            break;
    }
}

// Announce the X, Y, and F of the robot.
void ToyRobot::report() {
    if (!placed_) {
        std::cout << "The robot is not on the table" << std::endl;
    } else {
        std::cout << "X: " << x_ << ", Y: " << y_ << ", F: ";
        switch (direction_) {
            case Direction::NORTH:
                std::cout << "NORTH" << std::endl;
                break;
            case Direction::EAST:
                std::cout << "EAST" << std::endl;
                break;
            case Direction::SOUTH:
                std::cout << "SOUTH" << std::endl;
                break;
            case Direction::WEST:
                std::cout << "WEST" << std::endl;
                break;
        }
    }
}
