#include <iostream>
#include <stdlib.h>
#include "TPolinom.h"
using namespace std;



int main() {
    setlocale(0, "");
    TPolinom a;
    TPolinom b;
    TPolinom c;
    a.Input();
    b.Input();
    a.Show();
    b.Show();

    c = a.Add1(b);
    c.Show();

    a.Add2(b);
    a.Show();

    return 0;
}
//14 2 4 6 14 2 4 6 1 1 3 5 0 2 2 4 6 1 1 3 3 0
//14 2 4 6 14 2 4 6 1 1 3 5 0 2 2 4 6 1 1 3 3 7 2 2 2 0