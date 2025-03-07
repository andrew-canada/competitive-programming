#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 300005, P = 998244353;
ll qpow(ll a, ll b)
{
    ll res = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % P;
        a = a * a % P;
    }
    return res;
}
auto solve()
{
    // f[i]=1/d + (1-1/d)*(f[i]+2)
    // 1/d *f[i]=2-1/d
    // f[i] = 2*d-1
    int n, q;
    cin >> n >> q;
    vector<vector<int>> nxt(n);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        --u;
        --v;
        nxt[u].push_back(v);
        nxt[v].push_back(u);
    }
    vector<int> deep(n), fa(n);
    vector<vector<array<int, 2>>> ask(n);
    for (int i = 0, v, p; i < q; i++)
    {
        cin >> v >> p;
        ask[v - 1].push_back({p, i});
    }
    vector<int> ans(q);
    auto dfs = [&](auto &&dfs, int u, vector<int> &a, vector<int> &b) -> void
    {
        auto c = a;
        ranges::sort(c);
        ranges::reverse(c);
        // printf("!! %d %d\n",u,(int)ask[u].size());
        for (auto [p, id] : ask[u])
        {
            ll res = deep[u];
            // printf("$ %d %d %lld\n",u,deep[u],res);
            for (int i = p; i < (int)c.size(); i++)
                res += c[i] - 1;
            ans[id] = res;
        }
        for (auto v : nxt[u])
        {
            if (v == fa[u])
                continue;
            fa[v] = u;
            deep[v] = deep[u] + 1;
            a.push_back(2 * nxt[v].size() - 1);
            dfs(dfs, v, b, a);
            a.pop_back();
        }
    };
    vector<int> a, b;
    dfs(dfs, 0, a, b);
    for (auto v : ans)
        cout << v << '\n';
    // cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        // cout<<solve()<<'\n';
        // cout<<(solve()?"Yes":"No")<<'\n';
    }
    return 0;
}