#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int M = 1e9 + 7, mxX = 1e6, mxN = 2e5;

int who[mxN + 1];
vector<int> adjL[mxN + 1], adjL2[mxN + 1], adjL3[mxN + 1], st, co;
bool vis[mxN + 1];
char ans[mxN + 1];
ll x[mxN + 1], y[mxN + 1], dp[mxN + 1];

void dfs1(int u)
{
    vis[u] = 1;
    for (int v : adjL[u])
    {
        if (!vis[v])
        {
            dfs1(v);
        }
    }
    st.pb(u);
}

void dfs2(int u, int rt)
{
    vis[u] = 0;
    who[u] = rt;
    for (int v : adjL2[u])
    {
        if (vis[v])
        {
            dfs2(v, rt);
        }
    }
    y[who[u]] += x[u];
    co.pb(u);
}

void dfs3(int u)
{
    vis[u] = 1;
    for (int v : adjL3[u])
    {
        if (!vis[v])
        {
            dfs3(v);
        }
        dp[u] = max(dp[u], dp[v]);
    }
    dp[u] += y[u];
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v, --u, --v;
        adjL[u].pb(v);
        adjL2[v].pb(u);
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs1(i);
        }
    }
    for (int i = n - 1; ~i; i--)
    {
        if (vis[st[i]])
        {
            dfs2(st[i], st[i]);
            co.clear();
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j : adjL[i])
        {
            if (who[i] != who[j])
            {
                adjL3[who[i]].pb(who[j]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (who[i] == i && !vis[i])
        {
            dfs3(i);
            ans = max(dp[i], ans);
        }
    }
    cout << ans;
}