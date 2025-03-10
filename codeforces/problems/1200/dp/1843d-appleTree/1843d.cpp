#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

const int mxN = 2e5;

vector<int> adjL[mxN + 1];
ll freq[mxN + 1];

void dfs(int u, int par)
{
    if (adjL[u].size() == 1 && adjL[u][0] == par)
    {
        freq[u] = 1;
    }
    else
    {
        for (int v : adjL[u])
        {
            if (v != par)
            {
                dfs(v, u);
                freq[u] += freq[v];
            }
        }
    }
}

void solve()
{
    int n, q;
    cin >> n;
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i <= n; i++)
    {
        adjL[i].clear();
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adjL[u].pb(v);
        adjL[v].pb(u);
    }
    cin >> q;
    dfs(0, -1);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        cout << freq[x] * freq[y] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}