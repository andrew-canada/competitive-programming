#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 1e5;

vector<int> adjL[mxN + 1];
int vis[mxN + 1];

void dfs(int a)
{
    vis[a] = true;
    for (int b : adjL[a])
    {
        if (!vis[b])
        {
            dfs(b);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adjL[a].pb(b), adjL[b].pb(a);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            ans.pb(i);
        }
    }
    cout << ans.size() - 1 << '\n';
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << " " << ans[i + 1] << "\n";
    }
}