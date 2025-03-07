#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

#define pb push_back

int ans[2 * mxN + 1];

void dfs(int cur, int par, vector<vector<int>> &adjL, int &val)
{
    for (int next : adjL[cur])
    {
        if (next == par)
        {
            continue;
        }
        ans[next] = val + 1;
        while (ans[next] != ans[cur] + 1 && (ans[cur] % 2 != ans[next] % 2 || ans[next] - ans[cur] == 2))
        {
            ans[next]++;
        }
        val = ans[next];
        dfs(next, cur, adjL, val);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, u, v;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<vector<int>> adjL(n);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> u >> v;
            --u, --v;
            adjL[u].pb(v), adjL[v].pb(u);
        }
        ans[0] = 1;
        int val = 1;
        dfs(0, -1, adjL, val);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}