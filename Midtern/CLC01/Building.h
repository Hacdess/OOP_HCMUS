#ifndef _BUILDING_H_
#define _BUILDING_H_

#include <iostream>
#include <cstring>
using namespace std;

class Building
{
private:
    bool isAvailable; // Manage the building's state if it is available or not
    string name;
    int cost;
    int buildTime;
    int level;
    int resource;
    int produceTime;
    int produceTimeLeft;
    bool type; // 0 la cong trinh dan dung, 1 la cong trinh thuong mai    

public:
    Building();
    Building(string name,
            int cost, 
            int buildTime, 
            int level, 
            int resource, 
            int produceTime, 
            bool type);
    Building(const Building& other);
    ~Building();

    friend istream& operator>>(istream& is, Building& building);
    friend ostream& operator<<(ostream& os, const Building& building);

    // Manage the building's state if it is available or not
    void setAvailable(bool isAvailable);
    bool getAvailable();
};


#endif