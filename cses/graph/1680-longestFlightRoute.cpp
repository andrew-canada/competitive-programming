#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 1e5;

int n, m;
vector<int> adjL[mxN + 1];
int par[mxN + 1], dp[mxN + 1];
bool vis[mxN + 1];

void dfs(int u)
{
    dp[u] = (u == n ? 1 : -1e9);
    vis[u] = true;
    for (int v : adjL[u])
    {
        if (!vis[v])
        {
            par[v] = u;
            dfs(v);
        }
        if (dp[v] + 1 > dp[u])
        {
            dp[u] = dp[v] + 1;
            par[u] = v;
        }
    }
}

int main()
{
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adjL[a].pb(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    if (dp[1] < 0)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        vector<int> ans = {1};
        int u = 1;
        while (u ^ n)
        {
            u = par[u];
            ans.pb(u);
        }
        cout << ans.size() << '\n';
        for (int i : ans)
        {
            cout << i << " ";
        }
    }
}