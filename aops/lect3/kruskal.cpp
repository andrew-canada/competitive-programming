#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 1e5, mxE = 1e5;

vector<array<int, 3>> el;

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
};

UFDS ufds;

int main()
{
    int n, e, u, v, c, cost = 0, ne = 0;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> c;
        --u, --v;
        el.pb({c, u, v});
    }
    sort(el.begin(), el.end());
    for (int i = 0; i < n; i++)
    {
        ufds.par[i] = i;
    }
    for (array<int, 3> &edge : el)
    {
        if (ufds.isSameSet(edge[1], edge[2]))
        {
            continue;
        }
        ufds.unionSet(edge[1], edge[2]);
        cost += edge[0];
    }
    cout << cost;
}

/*
4 5
1 2 1
1 3 2
2 3 5
1 4 4
3 4 3
*/