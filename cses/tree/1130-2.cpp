#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

const int mxN = 2e5;

vector<int> adjL[mxN + 1];
bool vis[mxN + 1];
int ans;

void dfs(int cur, int par)
{
    for (int i : adjL[cur])
    {
        if (i != par)
        {
            dfs(i, cur);
            if (!vis[i] && !vis[cur])
            {
                ans++;
                vis[i] = true, vis[cur] = true;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjL[a].pb(b), adjL[b].pb(a);
    }
    dfs(1, -1);
    cout << ans;
}