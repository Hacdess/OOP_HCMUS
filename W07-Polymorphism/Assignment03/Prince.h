#ifndef _PRINCE_H_
#define _PRINCE_H_

#include "Gate.h"
#include <iostream>
#include <vector>

using namespace std;

using namespace std;

class Prince
{
private:
    int money;
    int IQLevel;
    int strengthLevel;

public:
    Prince();

    void input();
    void output() const;
    bool canRescue(int &gateCount, vector <Gate*> gates);
};

#endif