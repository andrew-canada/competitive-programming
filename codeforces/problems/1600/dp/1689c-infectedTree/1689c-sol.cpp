#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g(300005);
int ch[300005], dp[300005];

void dfs(int p, int q)
{
    ch[p] = 1, dp[p] = 0;
    int s = 0;
    for (auto it : g[p])
        if (it != q)
        {
            dfs(it, p);
            s += dp[it];
            ch[p] += ch[it];
        }
    for (auto it : g[p])
        if (it != q)
        {
            dp[p] = max(dp[p], s - dp[it] + ch[it] - 1);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(1, 0);
        cout << dp[1] << "\n";
    }
}