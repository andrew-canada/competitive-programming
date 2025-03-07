#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000
#define MAX_S 1000000000

using ll = long long;
using outEdge = struct
{
    int neigh, cost, width;
};

vector<outEdge> edges[MAX_N + 1] = {};

// Returns true if field n is reachable from field 1 by a cow of size s
int n_reachable_by_s(int n, int s)
{
    queue<int> q = {};
    bool visited[n + 1] = {};
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto [neigh, _, width] : edges[cur])
        {
            if (!visited[neigh] && width >= s)
            {
                if (neigh == n)
                {
                    return true;
                }
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
    return false;
}

int compute_largest(int n)
{
    int lo = 1, hi = MAX_S + 1;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        if (n_reachable_by_s(n, mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    return lo;
}

ll dijkstra(int n, int cowSize)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    bool visited[n + 1] = {};
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [cost, cur] = pq.top();
        pq.pop();
        if (visited[cur])
        {
            continue;
        }
        visited[cur] = true;
        if (cur == n)
        {
            return cost;
        }
        for (auto [neigh, neighCost, neighWidth] : edges[cur])
        {
            if (neighWidth >= cowSize)
            {
                pq.push({cost + neighCost, neigh});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b, l, s;
        cin >> a >> b >> l >> s;
        edges[a].push_back({b, l, s});
        edges[b].push_back({a, l, s});
    }

    // Binary search for largest possible cow
    int cowSize = compute_largest(n);

    // Dijkstra for shortest path for that particular cow
    ll cost = dijkstra(n, cowSize);

    cout << cowSize << " " << cost << endl;
    exit(0);
}