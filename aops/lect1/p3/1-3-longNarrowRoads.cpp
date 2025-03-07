#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 1e5, mxS = 1e9;

ll n, m, u, v, l, s;
vector<array<ll, 3>> adjL[mxN + 1];
ll dist[mxN + 1];
priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
array<ll, 2> cur;

ll dijk(ll cow)
{
    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        if (cur[0] > dist[cur[1]])
        {
            continue;
        }
        for (array<ll, 3> a : adjL[cur[1]])
        {
            if (cow > a[2])
            {
                continue;
            }
            ll d = cur[0] + a[1];
            if (d < dist[a[0]])
            {
                dist[a[0]] = d;
                pq.push({dist[a[0]], a[0]});
            }
        }
    }
    return (dist[n] == 4557430888798830399 ? 0 : dist[n]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> l >> s;
        adjL[u].pb({v, l, s});
        adjL[v].pb({u, l, s});
    }
    ll low = 0, high = mxS, mid, cow;
    ll cur, ans = 0;
    while (low <= high)
    {
        memset(dist, INF, sizeof(dist));
        mid = (low + high) / 2;
        cur = dijk(mid);
        if (cur)
        {
            low = mid + 1;
            ans = cur;
            cow = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << cow << " " << ans;
}