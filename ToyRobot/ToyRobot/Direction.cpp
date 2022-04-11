#include "Direction.h"

#include <iostream>
namespace ToyRobot
{
    using changeDirectionMap = std::unordered_map<std::string, std::string>;
    const std::unordered_map<std::string, changeDirectionMap> Direction::directionMatrix{
        { "NORTH", { {"Left", "WEST" }, {"Right", "EAST" } } },
        { "SOUTH", { {"Left", "EAST" }, {"Right", "WEST" } } },
        { "EAST",  { {"Left", "NORTH"}, {"Right", "SOUTH"} } },
        { "WEST",  { {"Left", "SOUTH"}, {"Right", "NORTH"} } }
    };

    const std::unordered_map<std::string, std::vector<int>> Direction::stepMatrix{
        { "NORTH", { 0,  1 } },
        { "SOUTH", { 0, -1 } },
        { "EAST",  { 1,  0 } },
        { "WEST",  { -1, 0 } }
    };

    void Direction::change(const std::string& face)
    {
        try {
            _bearing = directionMatrix.at(_bearing).at(face);
        }
        catch (...) { std::cout << "Invalid face: " << face << '\n'; }
    }

    std::string Direction::get() const
    {
        return _bearing;
    }

    bool Direction::set(const std::string& dir)
    {
        if (directionMatrix.find(dir) == directionMatrix.end()) {
            std::cout << "Invalid face: " << dir << '\n';
            return false;
        }
        _bearing = dir;
        return true;
    }
    std::tuple<int, int> Direction::getStep(const std::string& bearing)
    {
        int x = 0, y = 0;
        try {
            auto steps = stepMatrix.at(bearing);
            {
                x = steps[0];
                y = steps[1];
            }
        }
        catch (...) { std::cout << "Invalid bearing: " << bearing << '\n'; }
        return std::make_tuple(x, y);
    }
}
