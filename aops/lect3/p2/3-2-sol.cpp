#include <bits/stdc++.h>
using namespace std;

#define MAX_N 150000

int parents[MAX_N];
int sizes[MAX_N];
pair<int, int> INVALID = make_pair(MAX_N, MAX_N);

int find_parent(int v)
{
    while (parents[v] != v)
    {
        v = parents[v];
    }
    return v;
}

void add_edge(int a, int b)
{
    int pa = find_parent(a);
    int pb = find_parent(b);
    if (pa == pb)
    {
        return;
    }
    if (sizes[pa] > sizes[pb])
    {
        parents[pb] = pa;
        sizes[pa] += sizes[pb];
    }
    else
    {
        parents[pa] = pb;
        sizes[pb] += sizes[pa];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, d, q, a, b;
    cin >> n >> m >> d >> q;
    for (int i = 0; i < n; ++i)
    {
        parents[i] = i;
        sizes[i] = 1;
    }
    set<pair<int, int>> edges;
    // Load all the edges.
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        a--;
        b--;
        edges.insert(make_pair(a, b));
    }
    // Load all the queries.
    char t;
    int xi, yi;
    pair<int, int> queries[q];
    for (int i = 0; i < q; ++i)
    {
        cin >> t >> xi >> yi;
        xi--;
        yi--;
        if (t == 'C')
        {
            queries[i] = make_pair(-xi, -yi); // negative signs mean C
        }
        else
        {
            pair<int, int> edge = make_pair(xi, yi);
            if (d == 1)
            {
                // Only delete a given edge once!
                if (edges.find(edge) != edges.end())
                {
                    edges.erase(edge);
                    queries[i] = edge;
                }
                else
                {
                    // Tried to delete an edge that wasn't there. Ignore this query.
                    queries[i] = INVALID;
                }
            }
            else
            { // d = 0
                queries[i] = edge;
            }
        }
    }
    // Reverse the queries if we're doing deletions.
    if (d == 1)
    {
        reverse(queries, queries + q);
    }
    // Build the initial graph. The order doesn't matter for this phase.
    for (auto &edge : edges)
    {
        add_edge(edge.first, edge.second);
    }
    vector<string> answers;
    // Process the queries.
    for (auto query : queries)
    {
        if (query == INVALID)
        {
            continue;
        }
        xi = query.first;
        yi = query.second;
        if (yi < 0)
        { // NOTE: we need to check yi here, since xi could be 0
            answers.push_back((find_parent(-xi) == find_parent(-yi)) ? "YES" : "NO");
        }
        else
        {
            add_edge(xi, yi);
        }
    }
    // Unreverse the answers if we're doing deletions.
    if (d == 1)
    {
        reverse(answers.begin(), answers.end());
    }
    for (string s : answers)
    {
        cout << s << '\n';
    }
}