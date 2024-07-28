#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;
typedef array<ll, 2> all;

const int mxN = 1e5;

vector<all> adjL[mxN + 1];
ll dist[mxN + 1];

void dijk()
{
    priority_queue<all, vector<all>, greater<all>> pq;
    // cost, v
    pq.push({0, 1});
    dist[1] = 0;
    all cur;
    while (pq.size())
    {
        cur = pq.top();
        pq.pop();
        if (cur[0] > dist[cur[1]])
        {
            continue;
        }
        for (const all &a : adjL[cur[1]])
        {
            ll cost = cur[0] + a[0];
            if (cost < dist[a[1]])
            {
                dist[a[1]] = cost;
                pq.push({cost, a[1]});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v, c; i < m; i++)
    {
        cin >> u >> v >> c;
        // cost, v
        adjL[u].pb({c, v});
    }
    memset(dist, INF, sizeof(dist));
    dijk();
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
}