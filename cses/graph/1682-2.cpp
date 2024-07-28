#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 1e5;

bool vis[mxN + 1];
vector<int> ord, comp, adjL1[mxN + 1], adjL2[mxN + 1];

void dfs1(int u)
{
    vis[u] = true;
    for (int v : adjL1[u])
    {
        if (!vis[v])
        {
            dfs1(v);
        }
    }
    ord.pb(u);
}

void dfs2(int u)
{
    vis[u] = true;
    comp.pb(u);
    for (int v : adjL2[u])
    {
        if (!vis[v])
        {
            dfs2(v);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        adjL1[u].pb(v);
        adjL2[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs1(i);
        }
    }
    memset(vis, 0, sizeof(vis));
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        int j = ord[i];
        if (!vis[j])
        {
            dfs2(j);
            if (comp.size() == n)
            {
                cout << "YES\n";
                return 0;
            }
            ans.pb(j);
            comp.clear();
        }
    }
    cout << "NO\n";
    cout << ans[1] << " " << ans[0];
}

/*
3 3
1 2
2 3
3 1
*/