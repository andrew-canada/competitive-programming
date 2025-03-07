
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
const int mod = 998244353, N = 500005;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    for (int i = 0, u, v; i < n - 1; ++i)
    {
        cin >> u >> v, --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }
    vector<int> p(n);
    auto dfs = [&](auto self, int v, int pa) -> void
    {
        p[v] = pa;
        for (int u : adj[v])
            if (u != pa)
            {
                self(self, u, v);
            }
    };
    dfs(dfs, 0, -1);
    while (q--)
    {
        int v, t;
        cin >> v >> t, --v;
        int ans = 0;
        for (int i = v; i; i = p[i])
        {
            ans++;
        }
        v = p[v];
        vector<int> cur;
        while (v > 0)
        {
            cur.pb((int)adj[v].size());
            v = p[v];
            if (v == 0)
            {
                break;
            }
            v = p[v];
        }
        sort(all(cur));
        while (!cur.empty() && t)
        {
            cur.pop_back(), t--;
        }
        for (int i : cur)
        {
            ans += (i - 1) * 2;
        }
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}