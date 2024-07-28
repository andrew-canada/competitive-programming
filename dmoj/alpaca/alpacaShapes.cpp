#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int s = 0, r = 0;
    cin >> s >> r;
    if (s * s > 3.14 * r * r)
    {
        cout << "SQUARE";
    }
    else
    {
        cout << "CIRCLE";
    }
}