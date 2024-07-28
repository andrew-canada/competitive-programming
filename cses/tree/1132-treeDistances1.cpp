#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

const int mxN = 2e5;

vector<int> adjL[mxN];
int d[mxN], ans[mxN];

void dfs(int u = 0, int p = -1)
{
    for (int v : adjL[u])
    {
        if (v == p)
        {
            continue;
        }
        dfs(v, u);
        d[u] = max(d[u], d[v] + 1);
    }
}

void dfs2(int u = 0, int p = -1, int pd = 0)
{
    ans[u] = max(d[u], pd);
    vector<array<int, 2>> w{{pd, -1}};
    for (int v : adjL[u])
    {
        if (v == p)
        {
            continue;
        }
        w.pb({d[v] + 1, v});
    }
    w.pb({0, -1});
    sort(w.begin(), w.end(), greater<array<int, 2>>());
    for (int v : adjL[u])
    {
        if (v == p)
        {
            continue;
        }
        dfs2(v, u, w[0][1] == v ? w[1][0] + 1 : w[0][0] + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v, --u, --v;
        adjL[u].pb(v), adjL[v].pb(u);
    }
    dfs();
    dfs2();
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}