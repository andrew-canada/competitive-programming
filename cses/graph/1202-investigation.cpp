#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 1e5, M = 1e9 + 7;

vector<array<ll, 2>> adjL[mxN + 1];
ll cost[mxN + 1], numRoute[mxN + 1], minEdge[mxN + 1], maxEdge[mxN + 1];

void dijk()
{
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    // cost, node
    pq.push({0, 1});
    cost[1] = 0, numRoute[1] = 1;
    array<ll, 2> cur;
    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        if (cur[0] > cost[cur[1]])
        {
            continue;
        }
        for (const array<ll, 2> &ar : adjL[cur[1]])
        {
            if (cur[0] + ar[0] == cost[ar[1]])
            {
                numRoute[ar[1]] = (numRoute[ar[1]] + numRoute[cur[1]]) % M;
                minEdge[ar[1]] = min(minEdge[ar[1]], minEdge[cur[1]] + 1);
                maxEdge[ar[1]] = max(maxEdge[ar[1]], maxEdge[cur[1]] + 1);
            }
            else if (cur[0] + ar[0] < cost[ar[1]])
            {
                cost[ar[1]] = cur[0] + ar[0];
                pq.push({cost[ar[1]], ar[1]});
                numRoute[ar[1]] = numRoute[cur[1]];
                minEdge[ar[1]] = minEdge[cur[1]] + 1;
                maxEdge[ar[1]] = maxEdge[cur[1]] + 1;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    ll u, v, c;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        adjL[u].pb({c, v});
    }
    memset(cost, INF, sizeof(cost));
    dijk();
    // min price, number of min price, min number for min price, max number for min price
    cout << cost[n] << " " << numRoute[n] << " " << minEdge[n] << " " << maxEdge[n];
}