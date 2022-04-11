#ifndef __TOY_ROBOT_TEST_H
#define __TOY_ROBOT_TEST_H

#include "Robot.h"

#include <memory>
#include <cassert>
#include <functional>
#include <vector>

namespace ToyRobot
{
	class ToyRobotTest
	{
	public:
		static ToyRobotTest& instance()
		{
			static ToyRobotTest _instance;
			return _instance;
		}

		void run();
	private:
		ToyRobotTest() = default;
		~ToyRobotTest() = default;

		std::unique_ptr<Robot> _robot;

		using TestCase = std::function<void()>;
		std::vector<TestCase> testCases;
		void addTestCase(const TestCase& testCase);
		
		void runAllTests() const;

		void TestPlaceCommand();
		void TestMoveCommand();
		void TestLeftCommand();
		void TestRightCommand();
		//void TestReportCommand();
	};
}

#endif // !__TOY_ROBOT_TEST_H