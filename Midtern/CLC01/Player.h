#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "City.h"
#include <vector>

class Player
{
private:
    int level;
    int gold;
    int energy;

    int buildingQuantity;
    vector<Building*> buildings;

public:
    Player();
    ~Player();
};


#endif