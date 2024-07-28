#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 500;

ll dp[mxN + 1][mxN + 1];

int main()
{
    memset(dp, INF, sizeof(dp));
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0, u, v, c; i < m; i++)
    {
        cin >> u >> v >> c;
        dp[u][v] = min(dp[u][v], 1ll * c);
        dp[v][u] = min(dp[v][u], 1ll * c);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (int i = 0, u, v; i < q; i++)
    {
        cin >> u >> v;
        cout << (dp[u][v] >= 5e11 ? -1 : dp[u][v]) << '\n';
    }
}