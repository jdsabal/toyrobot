#ifndef __ROBOT_H
#define __ROBOT_H

#include "Direction.h"

#include <string>

namespace ToyRobot
{
	class Robot
	{
	public:
		Robot();
		~Robot() {};

		void place(int x, int y, const std::string& dir);
		void move();
		void turnLeft();
		void turnRight();
		void report() const;

		Direction getDirection() { return _direction; }
		std::tuple<int, int> getPosition() { return std::make_tuple(_xPos, _yPos); }
		bool isPlaced() { return _placed; }
	private:
		bool _placed;
		int _xPos;
		int _yPos;
		Direction _direction;
	};
}

#endif // !__ROBOT_H