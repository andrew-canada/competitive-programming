#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int rep[MAX_N];
int mass[MAX_N];

// The two functions for a Union-Find data structure, using the arrays above
int find(int u)
{
    int ans = u;
    // find the correct answer
    while (ans != rep[ans])
    {
        ans = rep[ans];
    }
    // before we return, do 'path compression' to make future finds faster
    // (not needed to pass this problem, but a good optimization to know)
    while (u != ans)
    {
        int next = rep[u];
        rep[u] = ans;
        u = next;
    }
    return ans;
}
void merge(int u, int v)
{
    u = find(u);
    v = find(v);
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        rep[i] = i;
        mass[i] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (find(u) == find(v))
        {
            cout << u + 1 << " " << v + 1 << "\n";
        }
        else
        {
            merge(u, v);
        }
    }
}