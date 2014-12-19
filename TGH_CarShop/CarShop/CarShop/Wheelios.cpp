#include "stdafx.h"
#include "Wheelios.h"
#include "Goodrich.h"
#include "BlingBling.h"


Wheelios::Wheelios()
{
	name = "Wheelios";
	tire = Goodrich();
	rim = BlingBling();
}


Wheelios::~Wheelios()
{
}
