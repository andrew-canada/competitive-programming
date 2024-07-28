#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 1e5, M = 1e9 + 7;

int n, m;
vector<int> adjL[mxN + 1];
int dp[mxN + 1];
bool vis[mxN + 1];

void dfs(int u)
{
    dp[u] = {u == n ? 1 : 0};
    vis[u] = true;
    for (int v : adjL[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
        dp[u] = (dp[u] + dp[v]) % M;
    }
}

int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adjL[u].pb(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    cout << dp[1];
}