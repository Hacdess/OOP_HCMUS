#ifndef _PRINCE_H_
#define _PRINCE_H_

#include "Castle.h"
#include <iostream>

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
    bool canRescue(int &gateCount, Castle castle);
};

#endif