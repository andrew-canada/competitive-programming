#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 2e5, mxX = 1e6, M = 1e9 + 7;

int t[mxN], d[mxN], rt[mxN], rp[mxN], cr[mxN], dt, ds[mxN], de[mxN], cs[mxN];
vector<int> adjL[mxN], cyc;
bool vis[mxN];

void dfs(int u)
{
    ds[u] = dt++;
    for (int v : adjL[u])
    {
        if (rt[v] ^ v)
        {
            d[v] = d[u] + 1;
            rt[v] = rt[u];
            cr[v] = cr[u];
            dfs(v);
        }
    }
    de[u] = dt;
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i], --t[i];
        adjL[t[i]].pb(i);
    }
    memset(rt, -1, 4 * n);
    for (int i = 0; i < n; i++)
    {
        if (~rt[i])
        {
            continue;
        }
        int u = i;
        while (!vis[u])
        {
            vis[u] = true;
            u = t[u];
        }
        while (!cyc.size() || u ^ cyc[0])
        {
            rp[u] = cyc.size();
            cyc.pb(u);
            rt[u] = u;
            cr[u] = i;
            u = t[u];
        }
        for (int ci : cyc)
        {
            dt = 0, dfs(ci), cs[ci] = cyc.size();
        }
        cyc.clear();
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b, --a, --b;
        int ans = -1;
        if (cr[a] == cr[b])
        {
            if (rt[b] == b)
            {
                ans = d[a];
                a = rt[a];
                ans += (rp[b] - rp[a] + cs[a]) % cs[a];
            }
            else
            {
                if (rt[a] == rt[b] && ds[b] <= ds[a] && ds[a] < de[b])
                {
                    ans = d[a] - d[b];
                }
            }
        }
        cout << ans << '\n';
    }
}