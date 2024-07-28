#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;
typedef array<int, 2> ar;

const int mxN = 1e5, mxE = 2e5;

struct UFDS
{
    int par[mxN + 1];
    vector<int> sz = vector<int>(mxN + 1, 1);
    int nc, mc = 0;
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
        if (pu == pv)
        {
            return;
        }
        if (sz[pu] >= sz[pv])
        {
            sz[pu] += sz[pv];
            par[pv] = pu;
            mc = max(mc, sz[pu]);
        }
        else
        {
            sz[pv] += sz[pu];
            par[pu] = pv;
            mc = max(mc, sz[pv]);
        }
        nc--;
    }
};

vector<ar> el;
UFDS ufds;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        el.pb({u, v});
    }
    for (int i = 1; i <= n; i++)
    {
        ufds.par[i] = i;
    }
    ufds.nc = n, ufds.mc = 0;
    for (const ar &a : el)
    {
        if (!ufds.isSameSet(a[0], a[1]))
        {
            ufds.unionSet(a[0], a[1]);
        }
        cout << ufds.nc << " " << ufds.mc << '\n';
    }
}