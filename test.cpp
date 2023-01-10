#include <iostream>
#include <sstream>

#include "gtest/gtest.h"
#include "toy_robot.h"

// Test that the ToyRobot can be placed on the table at a valid position.
TEST(ToyRobotTest, PlaceValidPosition) {
    ToyRobot robot;
    robot.place(0, 0, Direction::NORTH);
    EXPECT_EQ(robot.x_, 0);
    EXPECT_EQ(robot.y_, 0);
    EXPECT_EQ(robot.direction_, Direction::NORTH);
}

TEST(ToyRobotTest, BasicMove) {
    ToyRobot robot;
    robot.place(0, 0, Direction::NORTH);
    EXPECT_NO_THROW(robot.move());
}

// Test that the ToyRobot is not placed on the table at an invalid position.
TEST(ToyRobotTest, PlaceInvalidPosition) {
    ToyRobot robot;
    // I put this test for any case since the x_ and y_ will never be outside
    // these values since I take care of this inside the
    //  function place() in toy_robot.h
    robot.place(-1, 10, Direction::NORTH);

    EXPECT_TRUE(robot.x_ >= 0 && robot.x_ <= 4);
    EXPECT_TRUE(robot.y_ >= 0 && robot.y_ <= 4);
}

// Test that the ToyRobot can move one unit forward in the direction it is
// facing. While facing NORTH the move() will increment the y_ by 1.
// Respectively, while facing EAST the move() will increment the x_ by 1.
// While facing SOUTH the move() will decrement the y_ by 1.
// While facing WEST the move() will decrement the x_ by 1.
TEST(ToyRobotTest, Move) {
    ToyRobot robot;
    robot.place(0, 0, Direction::NORTH);
    robot.move();
    EXPECT_TRUE(robot.x_ == 0 && robot.y_ == 1);

    robot.place(1, 1, Direction::EAST);
    robot.move();
    EXPECT_TRUE(robot.x_ == 2 && robot.y_ == 1);

    robot.place(2, 2, Direction::SOUTH);
    robot.move();
    EXPECT_TRUE(robot.x_ == 2 && robot.y_ == 1);

    robot.place(3, 3, Direction::WEST);
    robot.move();
    EXPECT_TRUE(robot.x_ == 2 && robot.y_ == 3);
}

// Test that the ToyRobot can turn left
// e.g if the robot is facing NORTH, after turning left it will be facing WEST.
TEST(ToyRobotTest, TurnLeft) {
    ToyRobot robot;
    robot.place(0, 0, Direction::NORTH);
    robot.left();
    EXPECT_EQ(robot.direction_, Direction::WEST);
    EXPECT_TRUE(robot.x_ == 0 && robot.y_ == 0);

    robot.place(1, 1, Direction::EAST);
    robot.left();
    EXPECT_EQ(robot.direction_, Direction::NORTH);

    robot.place(2, 2, Direction::SOUTH);
    robot.left();
    EXPECT_EQ(robot.direction_, Direction::EAST);

    robot.place(3, 3, Direction::WEST);
    robot.left();
    EXPECT_EQ(robot.direction_, Direction::SOUTH);
}

// Test that the ToyRobot can turn right.
// e.g. if the robot is facing NORTH, after turning right it will be facing
// EAST.
TEST(ToyRobotTest, TurnRight) {
    ToyRobot robot;
    robot.place(0, 0, Direction::NORTH);
    robot.right();
    EXPECT_EQ(robot.direction_, Direction::EAST);

    robot.place(1, 1, Direction::EAST);
    robot.right();
    EXPECT_EQ(robot.direction_, Direction::SOUTH);

    robot.place(2, 2, Direction::SOUTH);
    robot.right();
    EXPECT_EQ(robot.direction_, Direction::WEST);

    robot.place(3, 3, Direction::WEST);
    // std::cout << robot.x_ << " " << robot.y_ << " " << std::endl;
    robot.right();

    EXPECT_EQ(robot.direction_, Direction::NORTH);

    robot.place(6, 6, Direction::WEST);
    // std::cout << robot.x_ << " " << robot.y_ << " " << std::endl;
    robot.right();

    EXPECT_EQ(robot.direction_, Direction::EAST);
}
