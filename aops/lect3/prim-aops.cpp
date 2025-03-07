#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<set<int>> my_edges(n, set<int>());
    vector<pair<int, int>> all_edges;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        my_edges[a].insert(i);
        my_edges[b].insert(i);
        all_edges.push_back(make_pair(a, b));
    }
    priority_queue<pair<int, int>> pq;
    // arbitrarily start from vertex 0
    pq.push(make_pair(1, 0)); // the "1" is a made-up edge number, "-1"
    bool reached[n] = {};
    set<int> edges_used;
    while (pq.size() > 0)
    {
        pair<int, int> curr = pq.top();
        pq.pop();
        int curr_node = curr.second;
        if (reached[curr_node])
        {
            // edge that would form a cycle, ignore
            continue;
        }
        int curr_edge = -curr.first;
        reached[curr_node] = true;
        edges_used.insert(curr_edge);
        for (int my_edge : my_edges[curr_node])
        {
            int neigh_node = all_edges[my_edge].first;
            if (neigh_node == curr_node)
            {
                neigh_node = all_edges[my_edge].second;
            }
            // Don't add edges to nodes that are already in our tree.
            // (we could also skip this check since we must check when popping either
            // way, but this saves a little time and potentially a lot of space)
            if (!reached[neigh_node])
            {
                pq.push(make_pair(-my_edge, neigh_node));
            }
        }
    }
    // Now go through and see what edges were used.
    for (int i = 0; i < m; ++i)
    {
        if (edges_used.find(i) == edges_used.end())
        {
            cout << all_edges[i].first + 1 << " " << all_edges[i].second + 1 << '\n';
        }
    }
}