#ifndef _CASTLE_H_
#define _CASTLE_H_

#include "Gate.h"
#include <vector>

class Castle
{
private:
    vector <Gate*> gates;

public:
    ~Castle();

    void input();
    vector <Gate*> getGates();
};

#endif