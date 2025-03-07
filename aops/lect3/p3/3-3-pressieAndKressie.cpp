#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

const int mxN = 1e5;

int maxComp;

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
            maxComp = max(maxComp, sz[pu]);
        }
        else
        {
            sz[pv] += sz[pu];
            par[pu] = pv;
            maxComp = max(maxComp, sz[pv]);
        }
    }
};

UFDS ufds;
vector<array<int, 3>> el;
vector<array<int, 2>> adjL[mxN + 1];
bool vis[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v;
    char x, y;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        --u, --v;
        // no need to sort later
        el.pb({i + 1, u, v});
        adjL[u].pb({i + 1, v});
        adjL[v].pb({i + 1, u});
    }
    if (x == 'P')
    {
        if (y == 'W')
        {
            priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq(adjL[0].begin(), adjL[0].end());
            vis[0] = true;
            while (!pq.empty())
            {
                array<int, 2> cur = pq.top();
                pq.pop();
                if (vis[cur[1]])
                {
                    continue;
                }
                vis[cur[1]] = true;
                cout << cur[0] << '\n';
                for (array<int, 2> &ed : adjL[cur[1]])
                {
                    pq.push(ed);
                }
            }
        }
        else
        {
            for (int i = 2; i <= n; i++)
            {
                cout << i << '\n';
            }
        }
    }
    else
    {
        int ne = 0;
        for (int i = 0; i < n; i++)
        {
            ufds.par[i] = i;
        }
        for (auto &ed : el)
        {
            if (ne == n - 1)
            {
                break;
            }
            if (ufds.isSameSet(ed[1], ed[2]))
            {
                continue;
            }
            ufds.unionSet(ed[1], ed[2]);
            ne++;
            if (y == 'W')
            {
                cout << ed[0] << '\n';
            }
            else
            {
                cout << maxComp << '\n';
            }
        }
    }
}