#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 20, mxX = 1e6, M = 1e9 + 7;

ll adjL[mxN][mxN], dp[1 << mxN][mxN];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v, --u, --v;
        ++adjL[u][v];
    }
    dp[1][0] = 1;
    for (int i = 2; i < (1 << n); i++)
    {
        if (((i >> (n - 1)) & 1) && (i != (1 << n) - 1))
        {
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1)
            {
                int i2 = i ^ (1 << j);
                for (int k = 0; k < n; k++)
                {
                    if (((i2 >> k) & 1) && adjL[k][j])
                    {
                        dp[i][j] += adjL[k][j] * dp[i2][k];
                    }
                }
                dp[i][j] %= M;
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1];
}