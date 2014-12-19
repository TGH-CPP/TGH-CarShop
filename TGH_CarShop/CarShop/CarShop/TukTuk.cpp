#include "stdafx.h"
#include "TukTuk.h"
#include "SwiftRage.h"
#include "Rollos.h"


TukTuk::TukTuk()
{
	name = "TukTuk";
	engine = SwiftRage();
	wheels = Rollos();
}


TukTuk::~TukTuk()
{
}
