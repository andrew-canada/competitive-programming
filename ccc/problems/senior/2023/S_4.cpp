#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;
typedef array<ll, 2> all;

const int mxN = 2e3;

struct edge
{
    int a, b, l, c;
    bool operator<(const edge &e)
    {
        return l == e.l ? c < e.c : l < e.l;
    }
};

ll ans;
edge el[mxN + 1];
vector<all> adjL[mxN + 1];
ll len[mxN + 1];

ll dijk(int a, int b)
{
    priority_queue<all, vector<all>, greater<all>> pq;
    memset(len, INF, sizeof(len));
    pq.push({a, 0});
    all cur;
    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        if (cur[1] > len[cur[0]])
        {
            continue;
        }
        for (all e : adjL[cur[0]])
        {
            ll nl = cur[1] + e[1];
            if (nl < len[e[0]])
            {
                len[e[0]] = nl;
                pq.push({e[0], nl});
            }
        }
    }
    return len[b];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> el[i].a >> el[i].b >> el[i].l >> el[i].c;
    }
    sort(el, el + m);
    for (edge e : el)
    {
        if (e.l < dijk(e.a, e.b))
        {
            adjL[e.a].pb({e.b, e.l}), adjL[e.b].pb({e.a, e.l});
            ans += e.c;
        }
    }
    cout << ans;
}

/*
in:
5 7
1 2 15 1
2 4 9 9
5 2 5 6
4 5 4 4
4 3 3 7
1 3 2 7
1 4 2 1

out:
25
*/