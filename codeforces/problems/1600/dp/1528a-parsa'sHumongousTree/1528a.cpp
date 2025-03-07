#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

ll dp[2][mxN + 1];
int a[2][mxN + 1];
vector<int> adjL[mxN + 1];

void dfs(int v, int p)
{
    dp[0][v] = dp[1][v] = 0;
    for (int u : adjL[v])
    {
        if (u == p)
        {
            continue;
        }
        dfs(u, v);
        dp[0][v] += max(abs(a[0][v] - a[1][u]) + dp[1][u], dp[0][u] + abs(a[0][v] - a[0][u]));
        dp[1][v] += max(abs(a[1][v] - a[1][u]) + dp[1][u], dp[0][u] + abs(a[1][v] - a[0][u]));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, u, v;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[0][i] >> a[1][i];
        }
        for (int i = 0; i <= n; i++)
        {
            adjL[i].clear();
        }
        for (int i = 1; i < n; i++)
        {
            cin >> u >> v;
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }
        dfs(1, -1);
        cout << max(dp[0][1], dp[1][1]) << '\n';
    }
}