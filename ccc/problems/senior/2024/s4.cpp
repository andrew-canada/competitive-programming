#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef array<int, 3> ar;

const int mxN = 2e5;

vector<ar> el;
map<array<int, 2>, int> mp;
char col[mxN + 1];
char colNode[mxN + 1];

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
        if (colNode[u] == 'G' && colNode[v] == 'G')
        {
            col[mp[{u, v}]] = 'R';
            colNode[u] = 'R', colNode[v] = 'R';
        }
        else if (colNode[u] == 'R' && colNode[v] == 'G')
        {
            col[mp[{u, v}]] = 'B';
            colNode[v] = 'B';
        }
        else if (colNode[u] == 'B' && colNode[v] == 'G')
        {
            col[mp[{u, v}]] = 'R';
            colNode[v] = 'R';
        }
        else if (colNode[v] == 'R' && colNode[u] == 'G')
        {
            col[mp[{u, v}]] = 'B';
            colNode[u] = 'B';
        }
        else if (colNode[v] == 'B' && colNode[u] == 'G')
        {
            col[mp[{u, v}]] = 'R';
            colNode[u] = 'R';
        }
    }
};

UFDS ufds;

int main()
{
    memset(col, 'G', sizeof(col));
    memset(colNode, 'G', sizeof(colNode));
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v, c; i < m; i++)
    {
        cin >> u >> v;
        c = 1;
        el.pb({c, u, v});
        mp[{u, v}] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        ufds.par[i] = i;
    }
    int ne = 0, ans = 0;
    for (const ar &a : el)
    {
        if (ufds.isSameSet(a[1], a[2]))
        {
            continue;
        }
        ne++;
        ufds.unionSet(a[1], a[2]);
        if (ne == n - 1)
        {
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << col[i];
    }
}

/*
5 7
1 2
2 4
5 2
4 5
4 3
1 3
1 4
*/