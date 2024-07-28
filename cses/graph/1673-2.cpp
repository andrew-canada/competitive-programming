#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;
typedef array<int, 3> ar;

const int mxN = 2500;
const ll INF = 5e12;

int n, m;
vector<ar> el;
ll dist[mxN + 1];

void bellmanFord()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (const ar &a : el)
        {
            if (dist[a[1]] == INF)
            {
                continue;
            }
            dist[a[2]] = min(dist[a[2]], dist[a[1]] + a[0]);
            dist[a[2]] = max(dist[a[2]], -INF);
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (const ar &a : el)
        {
            if (dist[a[1]] == INF)
            {
                continue;
            }
            dist[a[2]] = max(dist[a[2]], -INF);
            if (dist[a[2]] > dist[a[1]] + a[0])
            {
                dist[a[2]] = -INF;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    bool cycle = false;
    for (int i = 0, u, v, c; i < m; i++)
    {
        cin >> u >> v >> c, c *= -1;
        el.pb({c, u, v});
        if (c < 0)
        {
            cycle = true;
        }
    }
    fill(dist, dist + n + 1, INF);
    dist[1] = 0;
    bellmanFord();
    if (dist[n] == -INF || (cycle && n == 1))
    {
        cout << -1;
    }
    else
    {
        cout << -dist[n];
    }
}