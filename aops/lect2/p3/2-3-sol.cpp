#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2000
#define HUUGE 100000000
#define START_AMOUNT 1000000

int bestimates[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, s, n, x, a, b, d;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        // the pair has: ordered edge, cost
        vector<pair<pair<int, int>, int>> edges;
        cin >> s >> n >> x;
        for (int j = 0; j < s; ++j)
        {
            cin >> a >> b >> d;
            a--;
            b--;
            // each stall is a directed edge
            edges.push_back(make_pair(make_pair(a, b), d));
        }
        // We let 0 represent our starting amount, i.e., a final estimate of 0
        // would mean we just break even.
        bestimates[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            bestimates[i] = HUUGE;
        }
        // We could experiment with edge order here, or randomly shuffle the
        // edges.
        int prv[n]; // used in cycle checking
        for (int k = 0; k <= n; ++k)
        { // extra round for cycle detection
            for (int j = 0; j < s; ++j)
            {
                a = edges[j].first.first;
                b = edges[j].first.second;
                d = edges[j].second;
                // Make sure we can actually afford the cost of the edge...
                if (bestimates[a] + d <= START_AMOUNT)
                {
                    bestimates[b] = min(bestimates[b], bestimates[a] + d);
                }
            }
            if (k == n - 1)
            {
                for (int l = 0; l < n; ++l)
                {
                    prv[l] = bestimates[l];
                }
            }
        }
        bool ok = false;
        for (int i = 1; i < n; ++i)
        {
            if (bestimates[i] != prv[i])
            { // there is a reachable negative cycle
                ok = true;
                break;
            }
            else if (START_AMOUNT - bestimates[i] >= x)
            {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}