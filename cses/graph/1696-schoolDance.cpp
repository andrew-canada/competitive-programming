#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 500, mxM = 1e3, M = 1e9 + 7;

int match[mxN];
vector<int> adjL[mxN];
bool vis[mxN];

bool dfs(int u)
{
    vis[u] = true;
    for (int v : adjL[u])
    {
        if (match[v] < 0 || !vis[match[v]] && dfs(match[v]))
        {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0, a, b; i < k; i++)
    {
        cin >> a >> b, --a, --b;
        adjL[a].pb(b);
    }
    int f = 0;
    memset(match, -1, 4 * m);
    memset(vis, 0, n);
    for (int i = 0; i < n; i++)
    {
        memset(vis, 0, n);
        f += dfs(i);
    }
    cout << f << '\n';
    for (int i = 0; i < m; i++)
    {
        if (~match[i])
        {
            cout << match[i] + 1 << " " << i + 1 << '\n';
        }
    }
}