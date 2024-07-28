#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 1e5;

vector<int> adjL[mxN + 1];
bool vis[mxN + 1];
int par[mxN + 1];

void dfs(int cur, int p = -1)
{
    par[cur] = p;
    vis[cur] = true;
    for (int i : adjL[cur])
    {
        if (i == p)
        {
            continue;
        }
        if (vis[i])
        {
            vector<int> ans;
            ans.pb(i);
            while (cur ^ i)
            {
                ans.pb(cur);
                cur = par[cur];
            }
            ans.pb(i);
            cout << ans.size() << '\n';
            for (int j : ans)
            {
                cout << j << " ";
            }
            exit(0);
        }
        else
        {
            dfs(i, cur);
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
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    cout << "IMPOSSIBLE\n";
}