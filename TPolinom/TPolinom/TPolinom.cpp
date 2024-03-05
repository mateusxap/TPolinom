#include "TPolinom.h"
TPolinom::TPolinom()
{
	pFirst = new TMonom(0, -1, nullptr);
	pFirst->pNext = pFirst;
}



void TPolinom::Show()
{
	TMonom* next = pFirst->pNext;
	if (pFirst == next)
	{
		std::cout << "0\n";
	}
	else
	{
		double c;
		int degX, degY, degZ;
		while (next != pFirst)
		{
			c = next->coef;
			degX = (next->deg / 100);
			degY = (next->deg / 10) % 10;
			degZ = (next->deg % 10);
			std::cout << c << "*x^" << degX << "*y^" << degY << "*z^" << degZ;
			if (next->pNext != pFirst)
			{
				if (((next->pNext)->coef) > 0)
				{
					std::cout << "+";
				}
			}
			next = next->pNext;
		}
	}
	std::cout << "\n";
}

void TPolinom::InsNoSort(double c, int d)
{
	TMonom* cur, *newM;
	cur = pFirst->pNext;
	while (cur->pNext != pFirst)
	{
		cur = cur->pNext;
	}
	newM = new TMonom(c, d, pFirst);
	cur->pNext = newM;

}

void TPolinom::Ins(double c, int d)
{
	TMonom* prev, * cur;
	prev = pFirst;
	cur = prev->pNext;
	while (d < cur->deg)
	{
		prev = cur;
		cur = cur->pNext;
	}
	if (cur->deg < d)
	{
		prev->pNext = new TMonom(c, d, cur);
	}
	else
	{
		cur->coef += c;
		if(cur->coef==0)
		{
			prev->pNext = cur->pNext;
			delete cur; //работает ли delete?
		}
	}
}

void TPolinom::Input()
{
	double c;
	while (true)
	{
		std::cout << "¬ведите коэфцент монома ('0' - конец ввода): ";
		std::cin >> c;
		std::cout << "\n";
		if (c == 0)
		{
			break;
		}
		int degX, degY, degZ;
		std::cout << "¬ведите степень x: ";
		std::cin >> degX;
		std::cout << "\n";
		std::cout << "¬ведите степень y: ";
		std::cin >> degY;
		std::cout << "\n";
		std::cout << "¬ведите степень z: ";
		std::cin >> degZ;
		std::cout << "\n";
		int degRes = degX * 100 + degY * 10 + degZ;
		Ins(c, degRes);
	}
}

TPolinom TPolinom::Add1(const TPolinom& a) const 
{
	TPolinom res;
	TMonom* prev1, * prev2, * cur1, * cur2;
	prev1 = pFirst;
	cur1 = prev1->pNext;
	prev2 = a.pFirst;
	cur2 = prev2->pNext;
	while ((cur2 != a.pFirst) || (cur1 != this->pFirst))
	{
		if (cur1->deg > cur2->deg)
		{
			res.InsNoSort(cur1->coef, cur1->deg);	
			prev1 = cur1;
			cur1 = prev1->pNext;
		}
		else if (cur1->deg < cur2->deg)
		{
			res.InsNoSort(cur2->coef, cur2->deg);
			prev2 = cur2;
			cur2 = prev2->pNext;
		}
		else
		{

			if (cur1->coef != 0)
			{
				res.InsNoSort(cur1->coef + cur2->coef, cur1->deg);
			}
			prev1 = cur1;
			cur1 = prev1->pNext;
			prev2 = cur2;
			cur2 = prev2->pNext;

		}
		


	}
	return (res);
}

TPolinom& TPolinom::Add2(TPolinom & a)
{
	TMonom* prev1, * prev2, * cur1, * cur2;
	prev1 = pFirst;
	cur1 = prev1->pNext;
	prev2 = a.pFirst;
	cur2 = prev2->pNext;
	while (cur2 != a.pFirst)
	{
		if (cur1->deg > cur2->deg)
		{
			prev1 = cur1;
			cur1 = prev1->pNext;
		}
		else if (cur1->deg < cur2->deg)
		{
			prev1->pNext = cur2;
			prev2->pNext = cur2->pNext;
			cur2->pNext = cur1;
			cur2 = prev2->pNext;

			prev1 = prev1->pNext;
			//prev1 = cur2;
			//cur2 = prev1->pNext;
			//prev1->pNext = cur1->pNext;//перев€зка 
			//cur1->pNext = prev1; //		 в P1	

			//prev2->pNext = cur2; // перев€зка в P2
			////cur1 = prev1->pNext; //передвижение
		}
		else
		{
			cur1->coef += cur2->coef;

			//prev1 = cur1;
			//cur1 = prev1->pNext;//передвижение в P1 ???

			if (cur1->coef == 0)
			{
				prev1->pNext = cur1->pNext;
				delete cur1;
				cur1 = prev1->pNext;
				//delete prev1; //удалит ли это весь моном?
				//prev1 = cur1;
				//cur1 = prev1->pNext;
			}
			else
			{
				prev1 = cur1;
				cur1 = prev1->pNext;//передвижение в P1 ???
			}
			prev2 = cur2;
			cur2 = prev2->pNext;
			//все разные уход€т наверх, одинаковые остаютс€ внизу
		
		}
		//if (prev1->coef == 0)
		//{
		//	delete prev1; //удалит ли это весь моном?
		//	prev1 = cur1;
		//	cur1 = prev1->pNext;
		//}
		//else
		//{
		//	prev2 = cur2;//перемещ в P2
		//	cur2 = prev2->pNext;
		//}


	}
	a.Show();
	return (*this);
}