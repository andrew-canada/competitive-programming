#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 2e5;

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
vector<array<int, 2>> query;
set<array<int, 2>> el;
vector<string> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, d, q, u, v;
    char c;
    cin >> n >> m >> d >> q;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        --u, --v;
        el.insert({u, v});
    }
    for (int i = 0; i < n; i++)
    {
        ufds.par[i] = i;
    }
    // C = YES/NO
    // M: D=0 --> add
    // M: D=1 --> delete
    for (int i = 0; i < q; i++)
    {
        cin >> c >> u >> v;
        --u, --v;
        if (c == 'C')
        {
            query.pb({-u, -v});
        }
        else
        {
            array<int, 2> cur = {u, v};
            if (d)
            {

                if (el.find(cur) != el.end())
                {
                    el.erase(cur);
                    query.pb({cur});
                }
            }
            else
            {
                query.pb(cur);
            }
        }
    }
    if (d)
    {
        reverse(query.begin(), query.end());
    }
    for (auto &ed : el)
    {
        ufds.unionSet(ed[0], ed[1]);
    }
    for (auto &qu : query)
    {
        if (qu[1] < 0)
        {
            ans.pb(ufds.isSameSet(-qu[0], -qu[1]) ? "YES" : "NO");
        }
        else
        {
            ufds.unionSet(qu[0], qu[1]);
        }
    }
    if (d)
    {
        reverse(ans.begin(), ans.end());
    }
    for (string &st : ans)
    {
        cout << st << '\n';
    }
}