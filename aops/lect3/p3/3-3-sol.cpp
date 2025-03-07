#include <bits/stdc++.h>
using namespace std;

// w,v is a edge towards v with weight w
typedef pair<int, int> outEdge;

// The two functions for a Union-Find data structure
int find(int u, int rep[])
{
    int ans = u;
    // find the correct answer
    while (ans != rep[ans])
    {
        ans = rep[ans];
    }
    // before we return, do 'path compression' to make future finds faster
    while (u != ans)
    {
        int next = rep[u];
        rep[u] = ans;
        u = next;
    }
    return ans;
}
void merge(int u, int v, int rep[], int mass[])
{
    u = find(u, rep);
    v = find(v, rep);
    if (u == v)
    {
        return;
    }
    if (mass[u] < mass[v])
    {
        swap(u, v);
    }
    rep[v] = u;
    mass[u] += mass[v];
}

void kruskal(int n, int m, char y)
{
    int rep[n] = {};
    int mass[n] = {};
    for (int i = 0; i < n; i++)
    {
        rep[i] = i;
        mass[i] = 1;
    }
    int maxComp = 1;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (find(u, rep) == find(v, rep))
        {
            continue;
        }
        else
        {
            if (y == 'W')
            {
                cout << i + 1 << "\n";
            }
            merge(u, v, rep, mass);
            if (y == 'S')
            {
                maxComp = max(maxComp, mass[find(u, rep)]);
                cout << maxComp << "\n";
            }
        }
    }
}

void prim(int n, int m, char y)
{
    if (y == 'S')
    {
        for (int i = 2; i <= n; i++)
        {
            cout << i << endl;
        }
    }
    else if (y == 'W')
    {
        vector<outEdge> edges[n] = {};
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            edges[u].push_back({-i, v});
            edges[v].push_back({-i, u});
        }
        priority_queue<outEdge> pq(edges[0].begin(), edges[0].end());
        unordered_set<int> visited = {0};
        while (!pq.empty())
        {
            auto [negWeight, v] = pq.top();
            pq.pop();
            if (visited.find(v) != visited.end())
            {
                continue;
            }
            visited.insert(v);
            cout << -negWeight << endl;
            for (outEdge e2 : edges[v])
            {
                pq.push(e2);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    char x, y;
    cin >> n >> m >> x >> y;

    if (x == 'K')
    {
        kruskal(n, m, y);
    }
    else if (x == 'P')
    {
        prim(n, m, y);
    }
}