#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 1e5, mxM = 2e5, M = 1e9 + 7;

struct edge
{
    int u, v, c;
    bool operator<(const edge &e)
    {
        return c < e.c;
    }
};

edge el[mxM + 1];
vector<array<ll, 2>> adjL1[mxN + 1], adjL2[mxN + 1];
ll dist1[mxN + 1], dist2[mxN + 1];

int main()
{
    int n, m;
    cin >> n >> m;
    int u, v, c;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        el[i] = {u, v, c};
        adjL1[u].pb({c, v});
        adjL2[v].pb({c, u});
    }
    memset(dist1, INF, sizeof(dist1)), memset(dist2, INF, sizeof(dist2));
    // dijk(adjL1, dist1), dijk(adjL2, dist2);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (const array<ll, 2> &e : adjL1[i])
        {
            ans = max(ans, dist1[e[0]] + dist2[e[1]]);
        }
    }
    cout << ans;
}