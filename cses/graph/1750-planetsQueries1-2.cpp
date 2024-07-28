#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5, M = 1e9 + 7;

int tar[mxN + 1][30];

int main()
{
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> tar[i][0];
    }
    for (int i = 1; i < 30; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            tar[j][i] = tar[tar[j][i - 1]][i - 1];
        }
    }
    for (int i = 0, x, k; i < q; i++)
    {
        cin >> x >> k;
        for (int i = 0; i < 30; i++)
        {
            if ((k >> i) & 1)
            {
                x = tar[x][i];
            }
        }
        cout << x << '\n';
    }
}