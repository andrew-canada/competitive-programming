#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

const int mxN = 2.5e3;
const ll INF = 1e18, NINF = -1e18;

struct edge
{
    ll u, v, c;
};

int n, m, nd;
edge el[2 * mxN + 1];
ll dist[mxN + 1];
int par[mxN + 1];

void bellmanFord()
{
    for (int i = 1; i <= n; i++)
    {
        nd = 0;
        for (edge &e : el)
        {
            if (dist[e.u] + e.c < dist[e.v])
            {
                dist[e.v] = dist[e.u] + e.c;
                par[e.v] = e.u;
                nd = e.v;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    ll u, v, c;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        el[i] = {u, v, c};
    }
    bellmanFord();
    if (nd)
    {
        cout << "YES\n";
        vector<int> ans;
        for (int i = 1; i < n; i++)
        {
            nd = par[nd];
        }
        ans.pb(nd);
        int nd2 = par[nd];
        while (nd2 ^ nd)
        {
            ans.pb(nd2);
            nd2 = par[nd2];
        }
        ans.pb(nd);
        reverse(ans.begin(), ans.end());
        for (int i : ans)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "NO";
    }
}