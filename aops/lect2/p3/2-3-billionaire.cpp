#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

const int mxN = 2e3, mxS = 1e4;

int dist[mxN + 1], best[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("2-3.in", "r", stdin);
    int t, s, n, x, a, b, d;
    bool found;
    cin >> t;
    while (t--)
    {
        found = false;
        memset(dist, INF, sizeof(dist));
        dist[0] = 0;
        vector<array<int, 3>> el;

        cin >> s >> n >> x;
        for (int i = 0; i < s; i++)
        {
            cin >> a >> b >> d;
            --a, --b;
            el.pb({a, b, d});
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < s; j++)
            {
                int u = el[j][0], v = el[j][1], c = el[j][2];
                if (dist[u] + c <= 1e6)
                {
                    dist[v] = min(dist[v], dist[u] + c);
                }
            }
            if (i == n - 1)
            {
                for (int j = 0; j < n; j++)
                {
                    best[j] = dist[j];
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (dist[i] != best[i] || 1e6 - dist[i] >= x)
            {
                found = true;
                break;
            }
        }
        cout << (found ? "YES\n" : "NO\n");
    }
}