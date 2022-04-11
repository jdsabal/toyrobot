#ifndef __DIRECTION_H
#define __DIRECTION_H

#include <string>
#include <unordered_map>
#include <tuple>

namespace ToyRobot
{
	class Direction
	{
	public:
		Direction() : _bearing(std::string()) {};
		~Direction() {};
		void change(const std::string& direction);
		std::string get() const;
		bool set(const std::string& dir);
		std::tuple<int, int> getStep(const std::string& bearing);
	private:
		std::string _bearing;

		using changeDirectionMap = std::unordered_map<std::string, std::string>;
		static const std::unordered_map<std::string, changeDirectionMap> directionMatrix;

		static const std::unordered_map<std::string, std::vector<int>> stepMatrix;
	};
}

#endif // !__DIRECTION_H
