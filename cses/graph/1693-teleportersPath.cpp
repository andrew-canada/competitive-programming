#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 1e5, mxM = 2e5, M = 1e9 + 7;

int n, m, eu[mxM], ev[mxM], ind[mxN], out[mxN];
vector<int> adjL[mxN + 1], ans;
bool vis[mxM];

void dfs(int u = 0)
{
    while (adjL[u].size())
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
        ind[ev[i]]++;
        out[eu[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (ind[i] + 1 != out[i])
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
        else if (i == n - 1)
        {
            if (ind[i] != out[i] + 1)
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
        else if (ind[i] != out[i])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    dfs();
    if (ans.size() ^ m)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans)
    {
        cout << i + 1 << " ";
    }
    cout << n;
}