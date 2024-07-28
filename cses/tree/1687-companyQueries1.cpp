#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5, mxP = 18;

int par[mxN + 1][mxP + 1];

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        cin >> par[i][0];
    }
    for (int i = 1; i <= mxP; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }
    int x, k;
    while (q--)
    {
        cin >> x >> k;
        for (int i = 0; i <= mxP; i++)
        {
            if ((k >> i) & 1)
            {
                x = par[x][i];
            }
        }
        cout << (x ? x : -1) << '\n';
    }
}
