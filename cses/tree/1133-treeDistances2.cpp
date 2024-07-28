#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

const int mxN = 2e5;

vector<int> adjL[mxN];
int n, d[mxN];
ll ans[mxN], s[mxN];

void dfs(int u = 0, int p = -1)
{
    s[u] = 1;
    for (int v : adjL[u])
    {
        if (v == p)
        {
            continue;
        }
        d[v] = d[u] + 1;
        dfs(v, u);
        s[u] += s[v];
    }
}

void dfs2(int u, ll pd, int p = -1)
{
    ans[u] = pd;
    for (int v : adjL[u])
    {
        if (v == p)
        {
            continue;
        }
        dfs2(v, pd - s[v] + (n - s[v]), u);
    }
}

int main()
{
    cin >> n;
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v, --u, --v;
        adjL[u].pb(v), adjL[v].pb(u);
    }
    dfs();
    ll sd = 0;
    for (int i = 0; i < n; i++)
    {
        sd += d[i];
    }
    dfs2(0, sd);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}