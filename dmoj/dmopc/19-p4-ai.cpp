#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

vector<int> adj[300005];
char color[300005];
int red[300005], blue[300005];

void dfs(int u, int p)
{
    if (adj[u].size() == 1)
    { // leaf node
        if (color[u] == 'R')
        {
            red[u] = 1;
        }
        else
        {
            blue[u] = 1;
        }
        return;
    }
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
        red[u] = (1LL * red[u] * (blue[v] + (color[u] == 'R' ? red[v] : 0))) % MOD;
        blue[u] = (1LL * blue[u] * (red[v] + (color[u] == 'B' ? blue[v] : 0))) % MOD;
    }
    if (color[u] == 'R')
    {
        int cnt_blue = 0;
        for (int v : adj[u])
        {
            if (v == p || color[v] == 'R')
                continue;
            cnt_blue++;
        }
        if (cnt_blue == 0)
        { // case 1
            red[u] = (red[u] + 1) % MOD;
        }
        else
        { // case 2
            red[u] = (red[u] + 1LL * red[u] * (1 << cnt_blue)) % MOD;
        }
    }
    else
    { // color[u] == 'B'
        int cnt_red = 0;
        for (int v : adj[u])
        {
            if (v == p || color[v] == 'B')
                continue;
            cnt_red++;
        }
        if (cnt_red == 0)
        { // case 3
            blue[u] = (blue[u] + 1) % MOD;
        }
        else
        { // case 4
            blue[u] = (blue[u] + 1LL * blue[u] * (1 << cnt_red)) % MOD;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> color[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    int ans = (red[1] + blue[1]) % MOD;
    cout << ans << endl;
    return 0;
}