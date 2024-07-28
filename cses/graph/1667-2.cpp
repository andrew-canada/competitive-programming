#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 1e5;

vector<int> adjL[mxN + 1];
bool vis[mxN + 1];
int par[mxN + 1];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjL[a].pb(b), adjL[b].pb(a);
    }

    queue<int> q;
    q.push(1);
    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        for (int i : adjL[cur])
        {
            if (!vis[i])
            {
                vis[i] = true;
                q.push(i);
                par[i] = cur;
            }
        }
    }

    if (vis[n])
    {
        vector<int> ans;
        int nd = n;
        ans.pb(nd);
        while (nd != 1)
        {
            ans.pb(par[nd]);
            nd = par[nd];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int i : ans)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}