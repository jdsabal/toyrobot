#include "ToyRobotTest.h"

#include <iostream>

namespace ToyRobot
{
	using TestCase = std::function<void()>;
	void ToyRobotTest::run()
	{
		_robot = std::make_unique<Robot>();

		//add test cases here
		addTestCase(std::bind(&ToyRobotTest::TestPlaceCommand, this));
		addTestCase(std::bind(&ToyRobotTest::TestMoveCommand, this));
		addTestCase(std::bind(&ToyRobotTest::TestLeftCommand, this));
		addTestCase(std::bind(&ToyRobotTest::TestRightCommand, this));

		runAllTests();
	}
	void ToyRobotTest::addTestCase(const TestCase& testCase)
	{
		testCases.emplace_back(testCase);
	}

	void ToyRobotTest::runAllTests() const
	{
		for (auto test : testCases)
		{
			test();
		}
	}
	void ToyRobotTest::TestPlaceCommand()
	{

		std::cout << "\nRunning tests for PLACE command" << '\n';
		_robot.reset(new Robot);

		assert(_robot->isPlaced() == false);

		int i = 0;
		int x, y;

		// test invalid place
		std::cout << "PLACE 5,-1,WEST" << '\n';
		_robot->place(5, -1, "WEST");
		assert(_robot->isPlaced() == false);
		std::cout << "---passed" << '\n';
		++i;

		// test valid place
		std::cout << "PLACE 0,0,NORTH" << '\n';
		_robot->place(0, 0, "NORTH");
		assert(_robot->isPlaced() == true);
		std::tie(x, y) = _robot->getPosition();
		assert(x == 0);
		assert(y == 0);
		assert(_robot->getDirection().get() == "NORTH");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "PLACE 4,4,EAST" << '\n';
		_robot->place(4, 4, "EAST");
		assert(_robot->isPlaced() == true);
		std::tie(x, y) = _robot->getPosition();
		assert(x == 4);
		assert(y == 4);
		assert(_robot->getDirection().get() == "EAST");
		std::cout << "---passed" << '\n';
		++i;

		// test invalid y
		std::cout << "PLACE 0,-1,WEST" << '\n';
		_robot->place(0, -1, "WEST");
		assert(_robot->isPlaced() == true);
		std::tie(x, y) = _robot->getPosition();
		assert(x == 4);
		assert(y == 4);
		assert(_robot->getDirection().get() == "EAST");
		std::cout << "---passed" << '\n';
		++i;

		//test invalid x
		std::cout << "PLACE -3,0,WEST" << '\n';
		_robot->place(-3, 0, "WEST");
		assert(_robot->isPlaced() == true);
		std::tie(x, y) = _robot->getPosition();
		assert(x == 4);
		assert(y == 4);
		assert(_robot->getDirection().get() == "EAST");
		std::cout << "---passed" << '\n';
		++i;

		// test invalid y
		std::cout << "PLACE 5,6,WEST" << '\n';
		_robot->place(5, 6, "WEST");
		assert(_robot->isPlaced() == true);
		std::tie(x, y) = _robot->getPosition();
		assert(x == 4);
		assert(y == 4);
		assert(_robot->getDirection().get() == "EAST");
		std::cout << "---passed" << '\n';
		++i;

		//test invalid face
		std::cout << "PLACE 0,0,NW" << '\n';
		_robot->place(5, 6, "NW");
		assert(_robot->isPlaced() == true);
		std::tie(x, y) = _robot->getPosition();
		assert(x == 4);
		assert(y == 4);
		assert(_robot->getDirection().get() == "EAST");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << i << " tests passed.\n";
	}
	void ToyRobotTest::TestMoveCommand()
	{
		std::cout << "\nRunning tests for MOVE command" << '\n';
		_robot.reset(new Robot);

		assert(_robot->isPlaced() == false);

		int i = 0;
		int x, y;

		std::cout << "MOVE 1step from 0,0,NORTH" << '\n';
		_robot->place(0, 0, "NORTH");
		_robot->move();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 0);
		assert(y == 1);
		assert(_robot->getDirection().get() == "NORTH");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "MOVE 1step from 0,0,WEST" << '\n';
		_robot->place(0, 0, "WEST");
		_robot->move();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 0);
		assert(y == 0);
		assert(_robot->getDirection().get() == "WEST");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "MOVE 1step from 1,0,WEST" << '\n';
		_robot->place(1, 0, "WEST");
		_robot->move();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 0);
		assert(y == 0);
		assert(_robot->getDirection().get() == "WEST");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "MOVE 1step from 0,0,EAST" << '\n';
		_robot->place(0, 0, "EAST");
		_robot->move();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 1);
		assert(y == 0);
		assert(_robot->getDirection().get() == "EAST");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "MOVE 1step from 4,0,EAST" << '\n';
		_robot->place(4, 0, "EAST");
		_robot->move();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 4);
		assert(y == 0);
		assert(_robot->getDirection().get() == "EAST");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "MOVE 1step from 4,0,SOUTH" << '\n';
		_robot->place(4, 0, "SOUTH");
		_robot->move();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 4);
		assert(y == 0);
		assert(_robot->getDirection().get() == "SOUTH");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "MOVE 4steps from 0,0,NORTH" << '\n';
		_robot->place(0, 0, "NORTH");
		_robot->move();
		_robot->move();
		_robot->move();
		_robot->move();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 0);
		assert(y == 4);
		assert(_robot->getDirection().get() == "NORTH");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "MOVE 5steps from 0,0,NORTH" << '\n';
		_robot->place(0, 0, "NORTH");
		_robot->move();
		_robot->move();
		_robot->move();
		_robot->move();
		_robot->move();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 0);
		assert(y == 4);
		assert(_robot->getDirection().get() == "NORTH");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "MOVE 4steps from 0,0,EAST" << '\n';
		_robot->place(0, 0, "EAST");
		_robot->move();
		_robot->move();
		_robot->move();
		_robot->move();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 4);
		assert(y == 0);
		assert(_robot->getDirection().get() == "EAST");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "MOVE 5steps from 0,0,EAST" << '\n';
		_robot->place(0, 0, "EAST");
		_robot->move();
		_robot->move();
		_robot->move();
		_robot->move();
		_robot->move();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 4);
		assert(y == 0);
		assert(_robot->getDirection().get() == "EAST");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "MOVE 4steps from 4,0,WEST" << '\n';
		_robot->place(4, 0, "WEST");
		_robot->move();
		_robot->move();
		_robot->move();
		_robot->move();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 0);
		assert(y == 0);
		assert(_robot->getDirection().get() == "WEST");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "MOVE 5steps from 4,0,EAST" << '\n';
		_robot->place(0, 0, "WEST");
		_robot->move();
		_robot->move();
		_robot->move();
		_robot->move();
		_robot->move();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 0);
		assert(y == 0);
		assert(_robot->getDirection().get() == "WEST");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "MOVE 4steps from 4,4,SOUTH" << '\n';
		_robot->place(4, 4, "SOUTH");
		_robot->move();
		_robot->move();
		_robot->move();
		_robot->move();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 4);
		assert(y == 0);
		assert(_robot->getDirection().get() == "SOUTH");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "MOVE 5steps from 4,4,SOUTH" << '\n';
		_robot->place(4, 4, "SOUTH");
		_robot->move();
		_robot->move();
		_robot->move();
		_robot->move();
		_robot->move();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 4);
		assert(y == 0);
		assert(_robot->getDirection().get() == "SOUTH");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << i << " tests passed.\n";
	}
	void ToyRobotTest::TestLeftCommand()
	{
		std::cout << "\nRunning tests for LEFT command" << '\n';
		_robot.reset(new Robot);

		assert(_robot->isPlaced() == false);

		int i = 0;
		int x, y;

		std::cout << "LEFT x 1 from 0,0,NORTH" << '\n';
		_robot->place(0, 0, "NORTH");
		_robot->turnLeft();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 0);
		assert(y == 0);
		assert(_robot->getDirection().get() == "WEST");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "LEFT x 2 from 0,0,NORTH" << '\n';
		_robot->turnLeft();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 0);
		assert(y == 0);
		assert(_robot->getDirection().get() == "SOUTH");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "LEFT x 3 from 0,0,NORTH" << '\n';
		_robot->turnLeft();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 0);
		assert(y == 0);
		assert(_robot->getDirection().get() == "EAST");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "LEFT x 4 from 0,0,NORTH" << '\n';
		_robot->turnLeft();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 0);
		assert(y == 0);
		assert(_robot->getDirection().get() == "NORTH");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << i << " tests passed.\n";
	}
	void ToyRobotTest::TestRightCommand()
	{
		std::cout << "\nRunning tests for RIGHT command" << '\n';
		_robot.reset(new Robot);

		assert(_robot->isPlaced() == false);

		int i = 0;
		int x, y;

		std::cout << "RIGHT x 1 from 0,0,NORTH" << '\n';
		_robot->place(0, 0, "NORTH");
		_robot->turnRight();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 0);
		assert(y == 0);
		assert(_robot->getDirection().get() == "EAST");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "RIGHT x 2 from 0,0,NORTH" << '\n';
		_robot->turnRight();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 0);
		assert(y == 0);
		assert(_robot->getDirection().get() == "SOUTH");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "RIGHT x 3 from 0,0,NORTH" << '\n';
		_robot->turnRight();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 0);
		assert(y == 0);
		assert(_robot->getDirection().get() == "WEST");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << "RIGHT x 4 from 0,0,NORTH" << '\n';
		_robot->turnRight();
		std::tie(x, y) = _robot->getPosition();
		assert(x == 0);
		assert(y == 0);
		assert(_robot->getDirection().get() == "NORTH");
		std::cout << "---passed" << '\n';
		++i;

		std::cout << i << " tests passed.\n";
	}
}
