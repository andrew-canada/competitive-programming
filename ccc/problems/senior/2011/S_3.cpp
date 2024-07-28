#include <bits/stdc++.h>

using namespace std;

bool isCrystal(int m, int x, int y)
{
    int x1 = x / pow(5, m - 1), y1 = y / pow(5, m - 1);
    if (x1 == 0 || x1 == 4)
    {
        return false;
    }
    if (x1 > 0 && x1 < 4 && y1 == 0 || x1 == 2 && y1 == 1)
    {
        return true;
    }
    if ((x1 == 1 || x1 == 3) && y1 == 1 || x1 == 2 && y1 == 2)
    {
        return isCrystal(m - 1, x % (int)pow(5, m - 1), y % (int)pow(5, m - 1));
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    int m, x, y;
    for (int i = 0; i < t; i++)
    {
        cin >> m >> x >> y;
        isCrystal(m, x, y) ? printf("crystal\n") : printf("empty\n");
    }
}