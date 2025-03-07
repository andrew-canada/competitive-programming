#include <bits/stdc++.h>

using namespace std;

const int mxN = 3e5;

vector<int> adjL[mxN + 1];
int ch[mxN + 1], dp[mxN + 1];

void dfs(int u, int par)
{
    ch[u] = 1, dp[u] = 0;
    int s = 0;
    for (int v : adjL[u])
        if (v != par)
        {
            dfs(v, u);
            s += dp[v];
            ch[u] += ch[v];
        }
    for (int v : adjL[u])
    {
        if (v != par)
        {
            dp[u] = max(dp[u], s - dp[v] + ch[v] - 1);
        }
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
            adjL[i].clear();
        }
        for (int i = 1; i < n; i++)
        {
            cin >> u >> v;
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }
        dfs(1, -1);
        cout << dp[1] << "\n";
    }
}