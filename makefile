CC = g++

FLAGS = -std=c++11 -g -Wall -pedantic

SOURCES = main.cpp test.cpp toy_robot.cpp
HEADERS = toy_robot.h
OBJECTS = $(SOURCES:.cpp=.o)

all: main.out test.out

main.out: main.o toy_robot.o
	$(CC) $(FLAGS) $^ -o $@

test.out: test.o toy_robot.o
	$(CC) $(FLAGS) $^ -lgtest -lgtest_main -pthread -o $@

memtest: test.out
	valgrind --leak-check=full ./$^

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) *.out

