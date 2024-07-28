#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

const int mxN = 2e5;

vector<int> adjL[mxN + 1];
int dist[mxN + 1];
int ans, node;

void dfs(int cur, int par, int diam)
{
    if (diam > ans)
    {
        ans = diam, node = cur;
    }
    for (int i : adjL[cur])
    {
        if (i != par)
        {
            dfs(i, cur, diam + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adjL[a].pb(b), adjL[b].pb(a);
    }
    dfs(b, -1, 0);
    dfs(node, -1, 0);
    cout << ans;
}