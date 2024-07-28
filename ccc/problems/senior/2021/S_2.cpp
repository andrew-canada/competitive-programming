#include <bits/stdc++.h>

using namespace std;

const int mxN = 5e6;

bool rG[mxN + 1], cG[mxN + 1];

int main()
{
    int r, c, k;
    cin >> r >> c >> k;
    char rc;
    int n;
    for (int i = 0; i < k; i++)
    {
        cin >> rc >> n;
        if (rc == 'R')
        {
            rG[n] = !rG[n];
        }
        else
        {
            cG[n] = !cG[n];
        }
    }
    int gr = 0, gc = 0;
    for (int i = 1; i <= r; i++)
    {
        if (rG[i])
        {
            gr++;
        }
    }
    for (int i = 1; i <= c; i++)
    {
        if (cG[i])
        {
            gc++;
        }
    }
    cout << gr * c + gc * r - 2 * gr * gc;
}