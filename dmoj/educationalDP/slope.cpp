#include <iostream>

using namespace std;

double v[4] = {3.9, 3.99, 4.01, 4.1};

int main()
{
    double initY = -4 * 4 * 4 + 4 * 4 + 2;
    for (double d : v)
    {
        cout << (-4 * d * d + 4 * d + 2 - initY) / (d - 4) << '\n';
    }
}