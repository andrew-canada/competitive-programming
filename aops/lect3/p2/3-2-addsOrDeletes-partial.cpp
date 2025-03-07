#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 2e5;

int adjL[mxN + 1];
bool vis[mxN + 1];

struct UFDS
{
    int par[mxN + 1];
    vector<int> sz = vector<int>(mxN + 1, 1);
    int findSet(int u)
    {
        return u == par[u] ? u : par[u] = findSet(par[u]);
    }
    bool isSameSet(int u, int v)
    {
        return findSet(u) == findSet(v);
    }
    void unionSet(int u, int v)
    {
        int pu = findSet(u), pv = findSet(v);
        if (isSameSet(pu, pv))
        {
            return;
        }
        if (sz[pu] >= sz[pv])
        {
            sz[pu] += sz[pv];
            par[pv] = pu;
        }
        else
        {
            sz[pv] += sz[pu];
            par[pu] = pv;
        }
    }
    void dfs(int root)
    {
        memset(vis, 0, sizeof(vis));
        stack<int> s;
        s.push(root);
        int u;
        while (!s.empty())
        {
            u = s.top();
            s.pop();
            vis[u] = true;
            par[u] = root;
            if (!vis[adjL[u]])
            {
                s.push(adjL[u]);
            }
        }
    }
    void del(int u, int v)
    {
        dfs(u), dfs(v);
    }
};

UFDS ufds;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, d, q, u, v;
    char c;
    cin >> n >> m >> d >> q;

    for (int i = 1; i <= n; i++)
    {
        ufds.par[i] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adjL[u] = v, adjL[v] = u;
        ufds.unionSet(u, v);
    }
    // C = YES/NO
    // M: D=0 --> add
    // M: D=1 --> delete
    for (int i = 1; i <= q; i++)
    {
        cin >> c >> u >> v;
        if (c == 'C')
        {
            cout << (ufds.isSameSet(u, v) ? "YES\n" : "NO\n");
        }
        else
        {
            if (d)
            {
                if (adjL[u] == v || adjL[v] == u)
                {
                    adjL[u] = 0, adjL[v] = 0;
                    ufds.del(u, v);
                }
            }
            else
            {
                ufds.unionSet(u, v);
            }
        }
    }
}