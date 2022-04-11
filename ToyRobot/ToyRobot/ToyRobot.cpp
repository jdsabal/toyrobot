#include "Robot.h"
#include "ToyRobotTest.h"

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>

using namespace ToyRobot;

void tokenize(const std::string& str, const char delim, std::vector<std::string>& out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}

void parseInputAndExecute(const std::string& input, Robot& robot)
{
	if (input == "q") return;

	std::istringstream inputStream(input);
	
	std::string command;
	inputStream >> command;
	if (command == "PLACE") {
		std::string parameter;
		inputStream >> parameter;
		std::vector<std::string> coordinate;
		coordinate.reserve(3);
		tokenize(parameter, ',', coordinate);
		try {
			robot.place(std::stoi(coordinate[0]), std::stoi(coordinate[1]), coordinate[2]);
		}
		catch (...) {
			std::cout << "Invalid coordinates" << '\n';
		}
	}
	else if (command == "MOVE") {
		robot.move();
	}
	else if(command == "LEFT") {
		robot.turnLeft();
	}
	else if (command == "RIGHT") {
		robot.turnRight();
	}
	else if (command == "REPORT") {
		robot.report();
	}
	else { 
		std::cout << "Invalid input" << '\n'; 
	}
}

void welcomeMessage()
{
	std::cout << "Toy Robot Application" << '\n';
	std::cout << "Please place the toy robot on the table" << '\n';
	std::cout << "After placing the robot on the table, you may enter a valid command to move the toy robot" << '\n';
}

int main(int argc, char* argv[])
{
	if (argc > 1) {
		if (std::strcmp(argv[1], "--test") == 0) {
			ToyRobotTest::instance().run();
		}
	}
	else {
		welcomeMessage();

		std::string input;
		Robot toyRobot;

		do {
			std::getline(std::cin, input);
			parseInputAndExecute(input, toyRobot);
		} while (input != "q");
	}

	return 0;
}
