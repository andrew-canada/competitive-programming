#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 1e5, mxM = 2e5, M = 1e9 + 7;

int n, m, eu[mxM + 1], ev[mxM + 1];
vector<int> adjL[mxN + 1], ans;
bool vis[mxM + 1];

void dfs(int u)
{
    while (!adjL[u].empty())
    {
        int e = adjL[u].back();
        adjL[u].pop_back();
        if (vis[e])
        {
            continue;
        }
        vis[e] = true;
        dfs(u ^ eu[e] ^ ev[e]);
        ans.pb(u);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> eu[i] >> ev[i], --eu[i], --ev[i];
        adjL[eu[i]].pb(i);
        adjL[ev[i]].pb(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (adjL[i].size() & 1)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    ans.pb(0);
    dfs(0);
    if (ans.size() ^ (m + 1))
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i : ans)
    {
        cout << i + 1 << " ";
    }
}