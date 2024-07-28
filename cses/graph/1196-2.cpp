#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;
typedef array<ll, 2> all;

const int mxN = 1e5, mxK = 10;

int n, m, k;
vector<all> adjL[mxN + 1];
vector<ll> dist[mxN + 1];

void dijk()
{
    priority_queue<all, vector<all>, greater<all>> pq;
    all cur;
    // cost, node
    pq.push({0, 1});
    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        if (dist[cur[1]].size() == k)
        {
            continue;
        }
        dist[cur[1]].pb(cur[0]);
        for (const all &a : adjL[cur[1]])
        {
            pq.push({cur[0] + a[0], a[1]});
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0, u, v, c; i < m; i++)
    {
        cin >> u >> v >> c;
        // cost, node2
        adjL[u].pb({c, v});
    }
    dijk();
    for (int i = 0; i < k; i++)
    {
        cout << dist[n][i] << " ";
    }
}