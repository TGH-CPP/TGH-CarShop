#pragma once
#include <string>
#include "Wheel.h"
#include "Engine.h"

using namespace std;
class Car
{
public:
	Car();
	~Car();
	string name;
	Wheel wheels;
	Engine engine;
};

