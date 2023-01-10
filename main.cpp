#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "toy_robot.h"

int main() {
    // Create a ToyRobot instance.
    ToyRobot robot;

    // Open the input file.
    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cerr << "Failed to open input file" << std::endl;
        return 1;
    }

    // Read and execute each command.
    std::string line;
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        int x, y;
        std::string coordinates;
        std::getline(iss, coordinates, ',');
        std::istringstream(coordinates) >> x;
        std::getline(iss, coordinates, ',');
        std::istringstream(coordinates) >> y;

        // Read the fourth word as a string.
        std::string direction_str;
        iss >> direction_str;

        if (command == "PLACE") {
            // robot.place(x, y, Direction::NORTH);
            //           std::cout << "x: " << x << ", y: " << y
            //                    << ", direction: " << direction_str <<
            //                    std::endl;
            if (direction_str == "NORTH") {
                robot.place(x, y, Direction::NORTH);
            } else if (direction_str == "EAST") {
                robot.place(x, y, Direction::EAST);
            } else if (direction_str == "SOUTH") {
                robot.place(x, y, Direction::SOUTH);
            } else if (direction_str == "WEST") {
                robot.place(x, y, Direction::WEST);
            }
        } else if (command == "MOVE") {
            robot.move();
        } else if (command == "LEFT") {
            robot.left();
        } else if (command == "RIGHT") {
            robot.right();
        } else if (command == "REPORT") {
            robot.report();
        }
    }

    return 0;
}
