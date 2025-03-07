#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 400;

struct edge
{
    int to, weight;
};

void dfs(int u, int b, vector<bool> &vis, vector<vector<edge>> &adjL, vector<vector<int>> &allPath, vector<int> &curPath)
{
    if (u == b)
    {
        allPath.pb(curPath);
        return;
    }
    vis[u] = true;
    for (auto &edge : adjL[u])
    {
        if (!vis[edge.to])
        {
            curPath.pb(edge.weight);
            dfs(edge.to, b, vis, adjL, allPath, curPath);
            curPath.pop_back();
        }
    }
    vis[u] = false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, q, u, v, w, a, b, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> q;
        vector<vector<edge>> adjL(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            adjL[u].pb({v, w});
            adjL[v].pb({u, w});
        }
        while (q--)
        {
            cin >> a >> b >> k;
            vector<vector<int>> allPath;
            vector<bool> vis(n + 1, false);
            vector<int> curPath;
            dfs(a, b, vis, adjL, allPath, curPath);

            int ans = INF;
            for (auto &path : allPath)
            {
                if (path.size() >= k)
                {
                    sort(path.rbegin(), path.rend());
                    ans = min(ans, path[k - 1]);
                }
            }
            cout << ans << " ";
        }
        cout << '\n';
    }
}