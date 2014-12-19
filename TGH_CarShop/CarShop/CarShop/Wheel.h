#pragma once
#include <string>
#include "Tire.h"
#include "Rim.h"

using namespace std;
class Wheel
{
public:
	Wheel();
	~Wheel();
	string name;
	Tire tire;
	Rim rim;
};

