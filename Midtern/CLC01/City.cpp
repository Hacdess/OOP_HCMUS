#include "City.h"

City::City()
{
    row = col = 0;
    map = nullptr;
}

City::City(int row, int col)
{
    map = new Building*[row];
    for (int i = 0; i < row; ++i)
        map[i] = new Building[col];
}

int City::getRow()
{
    return row;
}

int City::getCol()
{
    return col;
}

City::~City()
{
    for (int i = 0; i < row; ++i)
        delete map[i];
    delete[] map;
}
