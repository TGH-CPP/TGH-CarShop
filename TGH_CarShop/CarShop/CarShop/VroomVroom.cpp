#include "stdafx.h"
#include "VroomVroom.h"
#include "Vroomerino.h"
#include "Wheelios.h"


VroomVroom::VroomVroom()
{
	name = "VroomVroom";
	engine = Vroomerino();
	wheels = Wheelios();
}


VroomVroom::~VroomVroom()
{
}
