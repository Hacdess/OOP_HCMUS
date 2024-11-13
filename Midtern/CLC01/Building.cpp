#include "Building.h"

Building::Building()
{
    isAvailable = false;
    name = "";
    type = 0;
    cost = 1;
    level = 1;
    produceTimeLeft = buildTime = produceTime = 60;
    resource = 0;
}

Building::Building(string name, int cost, int buildTime, int level, int resource, int produceTime, bool type)
{
    this->name = name;
    this->cost = cost;
    this->buildTime = buildTime;
    this->level = level;
    this->resource = resource;
    this->produceTimeLeft = this->produceTime = produceTime;
    type = type;
}

Building::Building(const Building &other)
{
    this->name = other.name;
    this->cost = other.cost;
    this->buildTime = other.buildTime;
    this->level = other.level;
    this->resource = other.resource;
    this->produceTime = other.produceTime;
    this->produceTimeLeft = other.produceTimeLeft;
    type = other.type;
}

// Khong co loai du lieu de deallocate
Building::~Building()
{
}

void Building::setAvailable(bool isAvailable)
{
    this->isAvailable = isAvailable;
}

bool Building::getAvailable()
{
    return isAvailable;
}

istream &operator>>(istream &is, Building &building)
{
    cout << "Input building's name: ";
    is.ignore();
    getline(is, building.name);

    cout << "Input building's building cost: ";
    is >> building.cost;

    cout << "Input building's building time: ";
    is >> building.buildTime;

    cout << "Input building's level: ";
    is >> building.level;

    cout << "Input building's resource: ";
    is >> building.resource;

    cout << "Input building's producing time: ";
    is >> building.produceTime;

    cout << "Input building's producing time left: ";
    is >> building.produceTimeLeft;

    cout << "Input building's type (0 - cong trinh dan dung, 1 - cong trinh thuong mai): ";
    is >> building.type;

    return is;
}

ostream &operator<<(ostream &os, const Building &building)
{
    os << "Input building's name: " << building.name << endl;

    os << "Input building's building cost: " << building.cost << endl;

    os << "Input building's building time: " << building.buildTime << endl;

    os << "Input building's level: " << building.level << endl;

    os << "Input building's resource: " << building.resource << endl;

    os << "Input building's producing time: " << building.produceTime << endl;

    os << "Input building's producing time left: " << building.produceTimeLeft << endl;

    os << "Input building's type: " << (building.type ? "cong trinh thuong mai" : "cong trinh dan dung") << endl;

    return os;
}
