#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

const int mxN = 2e5;

vector<int> adjL[mxN + 1];
int dist[mxN + 1];
int ans;

void dfs(int cur = 1, int par = -1)
{
    for (int i : adjL[cur])
    {
        if (i != par)
        {
            dfs(i, cur);
            ans = max(ans, dist[cur] + dist[i] + 1);
            dist[cur] = max(dist[cur], dist[i] + 1);
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
    dfs();
    cout << ans;
}