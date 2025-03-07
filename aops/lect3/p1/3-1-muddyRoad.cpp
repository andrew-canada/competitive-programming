#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 1e5;

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

vector<array<int, 4>> el;
UFDS ufds;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        --u, --v;
        el.pb({i, u, v, 0});
    }
    sort(el.begin(), el.end());
    for (int i = 0; i < n; i++)
    {
        ufds.par[i] = i;
    }
    int ne = 0;
    for (int i = 0; i < m; i++)
    {
        if (ne == n - 1)
        {
            break;
        }
        if (ufds.isSameSet(el[i][1], el[i][2]))
        {
            continue;
        }
        ufds.unionSet(el[i][1], el[i][2]);
        el[i][3] = 1;
        ne++;
    }
    for (int i = 0; i < m; i++)
    {
        if (!el[i][3])
        {
            cout << el[i][1] + 1 << " " << el[i][2] + 1 << '\n';
        }
    }
}