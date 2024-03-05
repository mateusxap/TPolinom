#pragma once
#include <iostream>
class TMonom
{
	double coef;
	int deg;
	TMonom* pNext;
public:
	TMonom(double c, int d, TMonom* p);
	friend class TPolinom;
};

