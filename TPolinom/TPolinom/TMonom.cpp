#include "TMonom.h"
TMonom::TMonom(double c, int d, TMonom* p)
{
	coef = c;
	deg = d;
	pNext = p;
}

