#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 2e5;

vector<int> adjL[mxN + 1];
int depth[mxN + 1], sz[mxN + 1], det[mxN + 1];

int dfs(int u, int p)
{
    depth[u] = depth[p] + 1;
    sz[u] = 1;
    for (int v : adjL[u])
    {
        if (v == p)
        {
            continue;
        }
        sz[u] += dfs(v, u);
    }
    det[u] = sz[u] - depth[u];
    return sz[u];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll ans = 0;
    int n, k, u, v;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
    dfs(1, -1);
    nth_element(det + 1, det + n - k, det + n + 1, greater<int>());
    for (int i = 1; i <= n - k; ++i)
    {
        ans += det[i];
    }
    cout << ans;
}