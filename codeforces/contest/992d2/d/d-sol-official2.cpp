#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(int v, vector<vector<int>> &g, vector<int> &h, int p)
{
    h[v] = h[p] + 1;
    for (int u : g[v])
    {
        if (u == p)
            continue;
        dfs(u, g, h, v);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> h(n);
        dfs(0, g, h, 0);
        vector<vector<int>> hs(n + 1);
        for (int i = 0; i < n; i++)
            hs[h[i]].push_back(i);
        int l = 2, r = 2 * n;
        int cur = 0;
        vector<int> ans(n);
        for (int i = 1; i <= n; i++)
        {
            if (cur)
            {
                for (int v : hs[i])
                {
                    ans[v] = r;
                    r -= 2;
                }
            }
            else
            {
                for (int v : hs[i])
                {
                    ans[v] = l;
                    l += 2;
                }
            }
            cur ^= 1;
        }
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            for (int v : g[i])
            {
                if (h[v] < h[i])
                    continue;
                if (abs(ans[v] - ans[i]) == 2)
                {
                    ans[v] = ans[i] - 1;
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}