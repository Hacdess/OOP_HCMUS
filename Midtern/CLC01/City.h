#ifndef _CITY_H_
#define _CITY_H_

#include "Building.h"

class City
{
private:
    int row;
    int col;
    Building** map;
public:
    City();
    City(int row, int col);

    int getRow();
    int getCol();

    ~City();


};


#endif