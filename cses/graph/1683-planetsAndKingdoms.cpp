#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 1e5, mxM = 2e5, M = 1e9 + 7;

vector<int> adjL[mxN + 1], invAdjL[mxN + 1], ord, comp;
bool vis[mxN + 1];
int num[mxN + 1];

void dfs1(int u)
{
    vis[u] = true;
    for (int v : adjL[u])
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
    for (int v : invAdjL[u])
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
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adjL[u].pb(v);
        invAdjL[v].pb(u);
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
    int nc = 0;
    for (int j = n - 1; j >= 0; j--)
    {
        int i = ord[j];
        if (!vis[i])
        {
            dfs2(i);
            ++nc;
            for (int k : comp)
            {
                num[k] = nc;
            }
            comp.clear();
        }
    }
    cout << nc << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << num[i] << " ";
    }
}