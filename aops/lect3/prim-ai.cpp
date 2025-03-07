#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF INT_MAX

const int mxN = 1e5;

vector<pair<int, int>> adjL[mxN + 1];

class UnionFind
{
public:
    vector<int> parent, size;
    int maxSize;

    UnionFind(int n) : parent(n), size(n, 1), maxSize(1)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionSets(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV)
        {
            if (size[rootU] < size[rootV])
                swap(rootU, rootV);
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
            maxSize = max(maxSize, size[rootU]);
        }
    }
};

void prim(int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> inMST(n, false);
    vector<int> key(n, INF);
    int result = 0;
    int lastEdgeCost = 0;

    pq.push({0, 0}); // {weight, vertex}
    key[0] = 0;

    UnionFind uf(n);

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue;
        inMST[u] = true;
        result += key[u];
        lastEdgeCost = key[u];

        for (auto &[v, weight] : adjL[u])
        {
            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                pq.push({key[v], v});
                uf.unionSets(u, v);
                cout << "Largest connected component size after adding edge (" << u << ", " << v << "): " << uf.maxSize << endl;
                cout << "Cost of the most recently added edge: " << weight << endl;
            }
        }
    }

    cout << "Minimum Spanning Tree cost: " << result << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int n, m, u, v, w;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        --u, --v;
        adjL[u].pb({v, i + 1});
        adjL[v].pb({u, i + 1});
    }
    prim(n);
}