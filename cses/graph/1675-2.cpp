#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;
typedef array<int, 3> ar;

const int mxN = 1e5, mxE = 2e5;

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
        // watch out for accidentally writing single equal
        if (pu == pv)
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
vector<ar> el;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v, c; i < m; i++)
    {
        cin >> u >> v >> c;
        el.pb({c, u, v});
    }
    sort(el.begin(), el.end());
    // don't forget to initialize parent
    for (int i = 1; i <= n; i++)
    {
        ufds.par[i] = i;
    }
    int ne = 0;
    ll ans = 0;
    for (const ar &a : el)
    {
        // order of code here is important
        if (ufds.isSameSet(a[1], a[2]))
        {
            continue;
        }
        ne++;
        ans += a[0];
        ufds.unionSet(a[1], a[2]);
        if (ne == n - 1)
        {
            cout << ans;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}