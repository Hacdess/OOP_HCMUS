#include "Player.h"

Player::Player()
{
    level = 1;
    gold = 100;
    energy = 100;
    buildingQuantity = 0;
}

Player::~Player()
{
    for (int i = 0; i < buildingQuantity; ++i)
        delete buildings[i];
    buildings.clear();
}