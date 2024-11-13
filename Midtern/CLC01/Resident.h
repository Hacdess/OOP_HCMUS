#ifndef _RESIDENT_H_
#define _RESIDENT_H_

#include <string>
using namespace std;

class Resident
{
private:
    string name;
    int age;
    int productivity;

public:
    Resident(/* args */);
    ~Resident();
};


#endif