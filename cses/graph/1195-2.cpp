#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;
typedef array<ll, 2> all;

const int mxN = 1e5;

vector<all> adjL1[mxN + 1], adjL2[mxN + 1];
ll dist1[mxN + 1], dist2[mxN + 1];

void dijk(vector<all> *adjL, ll *dist, int start)
{
    priority_queue<all, vector<all>, greater<all>> pq;
    all cur;
    dist[start] = 0;
    // cost, node
    pq.push({0, start});
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
        // cost, node 2
        adjL1[u].pb({c, v});
        adjL2[v].pb({c, u});
    }
    memset(dist1, INF, sizeof(dist1)), memset(dist2, INF, sizeof(dist2));
    dijk(adjL1, dist1, 1), dijk(adjL2, dist2, n);
    ll ans = 2e14;
    for (int i = 1; i <= n; i++)
    {
        for (const all &a : adjL1[i])
        {
            ans = min(ans, dist1[i] + dist2[a[1]] + a[0] / 2);
        }
    }
    cout << ans;
}