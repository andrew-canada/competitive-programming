#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

int r1[mxN + 1], r2[mxN + 1];

int main()
{
    int c;
    cin >> c;
    int nw = 0;
    for (int i = 0; i < c; i++)
    {
        cin >> r1[i];
        if (r1[i])
        {
            nw++;
        }
    }
    for (int i = 0; i < c; i++)
    {
        cin >> r2[i];
        if (r2[i])
        {
            nw++;
        }
    }
    nw *= 3;
    for (int i = 0; i < c; i++)
    {
        if (r1[i])
        {
            if (i + 1 < c && r1[i + 1])
            {
                nw--;
            }
            if (i - 1 >= 0 && r1[i - 1])
            {
                nw--;
            }
            if (i % 2 == 0 && r2[i])
            {
                nw--;
            }
        }
    }
    for (int i = 0; i < c; i++)
    {
        if (r2[i])
        {
            if (i + 1 < c && r2[i + 1])
            {
                nw--;
            }
            if (i - 1 >= 0 && r2[i - 1])
            {
                nw--;
            }
            if (i % 2 == 0 && r1[i])
            {
                nw--;
            }
        }
    }
    cout << nw;
}