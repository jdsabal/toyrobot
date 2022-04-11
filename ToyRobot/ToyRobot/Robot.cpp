#include "Robot.h"

#include "Table.h"

#include <string>
#include <iostream>

namespace ToyRobot
{
	Robot::Robot()
		: _placed(false)
		, _xPos(0)
		, _yPos(0)
		, _direction()
	{
	}

	void Robot::place(int x, int y, const std::string& dir)
	{
		if (Table::instance().insideTable(x, y) && _direction.set(dir)) {
			_xPos = x;
			_yPos = y;

			_placed = true;
		}
	}

	void Robot::move()
	{
		int x, y;
		if (_placed) {
			std::tie(x, y) = _direction.getStep(_direction.get());
			
			place(_xPos + x, _yPos + y, _direction.get());
		}
	}

	void Robot::turnLeft()
	{
		if (_placed) _direction.change("Left");
	}

	void Robot::turnRight()
	{
		if (_placed) _direction.change("Right");
	}

	void Robot::report() const
	{
		if (_placed) {
			std::cout << "Robot is in grid: (" 
				<< _xPos << ", " << _yPos 
				<< ") facing " << _direction.get() << '\n';
		}
		else {
			std::cout << "Robot is not on the table" << '\n';
		}
	}
}
