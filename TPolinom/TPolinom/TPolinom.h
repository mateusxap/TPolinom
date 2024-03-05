#pragma once
#include "TMonom.h"
class TPolinom
{
	TMonom* pFirst;
	void InsNoSort(double c, int deg);
public:
	TPolinom();
	void Ins(double c, int deg);
	TPolinom Add1(const TPolinom& a) const;
	TPolinom& Add2(TPolinom& a);
	void Show();
	void Input();
};

