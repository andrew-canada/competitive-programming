#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 1e5;

struct edge
{
    ll u, v, c;
    bool isFlight;
    bool operator<(const edge &e)
    {
        return c < e.c;
    }
};

struct UFDS
{
    int par[mxN + 1];
    vector<int> sz = vector<int>(mxN + 1, 1);
    int findSet(int a)
    {
        return a == par[a] ? a : par[a] = findSet(par[a]);
    }
    bool isSameSet(int a, int b)
    {
        return findSet(a) == findSet(b);
    }
    void unionSet(int a, int b)
    {
        if (isSameSet(a, b))
        {
            return;
        }
        int p1 = findSet(a), p2 = findSet(b);
        if (sz[p1] > sz[p2])
        {
            par[p2] = p1;
            sz[p1] += sz[p2];
        }
        else
        {
            par[p1] = p2;
            sz[p2] += sz[p1];
        }
    }
};

UFDS flight, portal;
edge el[2 * mxN + 1];

int main()
{
    ll n, m, p, q;
    cin >> n >> m >> p >> q;
    ll tot = 0, cost = 0;
    for (int i = 0; i < p; i++)
    {
        cin >> el[i].u >> el[i].v >> el[i].c;
        el[i].isFlight = true;
        tot += n * el[i].c;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> el[p + i].u >> el[p + i].v >> el[p + i].c;
        tot += m * el[p + i].c;
    }
    for (int i = 1; i <= m; i++)
    {
        flight.par[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        portal.par[i] = i;
    }
    sort(el, el + p + q);
    int nf = m, np = n;
    for (const edge &e : el)
    {
        if (e.isFlight && !flight.isSameSet(e.u, e.v))
        {
            flight.unionSet(e.u, e.v);
            cost += np * e.c;
            nf--;
        }
        else if (!e.isFlight && !portal.isSameSet(e.u, e.v))
        {
            portal.unionSet(e.u, e.v);
            cost += nf * e.c;
            np--;
        }
    }
    cout << tot - cost;
}