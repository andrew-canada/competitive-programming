#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 2e5;

int anc[mxN][19], d[mxN], ans[mxN], c[mxN];
vector<int> adjL[mxN];

void dfs(int u = 0, int p = -1)
{
    anc[u][0] = p;
    for (int i = 1; i < 19; i++)
    {
        anc[u][i] = ~anc[u][i - 1] ? anc[anc[u][i - 1]][i - 1] : -1;
    }
    for (int v : adjL[u])
    {
        if (v == p)
        {
            continue;
        }
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v)
{
    if (d[u] < d[v])
    {
        swap(u, v);
    }
    for (int i = 18; ~i; i--)
    {
        if (d[u] - (1 << i) >= d[v])
        {
            u = anc[u][i];
        }
    }
    if (u == v)
    {
        return u;
    }
    for (int i = 18; ~i; i--)
    {
        if (anc[u][i] ^ anc[v][i])
        {
            u = anc[u][i], v = anc[v][i];
        }
    }
    return anc[u][0];
}

void dfs2(int u = 0, int p = -1)
{
    for (int v : adjL[u])
    {
        if (v ^ p)
        {
            dfs2(v, u);
            c[u] += c[v];
        }
    }
    ans[u] = c[u];
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1, a, b; i < n; i++)
    {
        cin >> a >> b, --a, --b;
        adjL[a].pb(b);
        adjL[b].pb(a);
    }
    dfs();
    int a, b;
    while (q--)
    {
        cin >> a >> b, --a, --b;
        ++c[a], ++c[b];
        int d = lca(a, b);
        --c[d];
        if (d)
        {
            --c[anc[d][0]];
        }
    }
    dfs2();
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}