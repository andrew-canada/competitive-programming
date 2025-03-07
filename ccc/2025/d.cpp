#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back

const ll INF = LLONG_MAX / 2;

struct edge
{
    ll u, v, t;
};

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<edge> el(m);
    vector<vector<ll>> adjN(n + 1);
    vector<vector<array<ll, 2>>> adjL(m);
    vector<ll> dist(m, INF);
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    for (ll i = 0; i < m; i++)
    {
        cin >> el[i].u >> el[i].v >> el[i].t;
        adjN[el[i].u].pb(i);
        adjN[el[i].v].pb(i);
    }
    for (ll cur = 1; cur <= n; cur++)
    {
        auto &curAdj = adjN[cur];
        if (curAdj.size() < 2)
        {
            continue;
        }
        sort(curAdj.begin(), curAdj.end(), [&](ll e1, ll e2)
             { return el[e1].t < el[e2].t; });
        for (ll j = 0; j < curAdj.size() - 1; j++)
        {
            ll e1 = curAdj[j], e2 = curAdj[j + 1];
            ll cost = llabs(el[e1].t - el[e2].t);
            adjL[e1].pb({e2, cost});
            adjL[e2].pb({e1, cost});
        }
    }
    for (ll curI : adjN[1])
    {
        dist[curI] = el[curI].t;
        pq.push({dist[curI], curI});
    }
    while (!pq.empty())
    {
        auto [cd, e] = pq.top();
        pq.pop();
        if (cd > dist[e])
        {
            continue;
        }
        for (auto &curE : adjL[e])
        {
            ll nxt = curE[0];
            ll w = curE[1];
            ll nd = cd + w;
            if (nd < dist[nxt])
            {
                dist[nxt] = nd;
                pq.push({nd, nxt});
            }
        }
    }
    ll ans = INF;
    for (ll curI : adjN[n])
    {
        ans = min(ans, dist[curI]);
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}