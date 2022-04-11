#include "Table.h"

namespace ToyRobot
{

    bool Table::insideTable(unsigned x, unsigned y)
    {
        return (x < X_MAX && y < Y_MAX);
    }

}
