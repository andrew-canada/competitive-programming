#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 500;

int n, m;
int lvl[mxN + 1], nxt[mxN + 1];

struct edge
{
    ll u, v, c, f;
    edge *rev;
    edge(ll u1, ll v1, ll c1)
    {
        u = u1, v = v1, c = c1, f = 0;
    }
};

vector<edge *> adjL[mxN + 1];

void add(int u, int v, int c)
{
    edge *e1 = new edge(u, v, c);
    edge *e2 = new edge(v, u, 0);
    e1->rev = e2, e2->rev = e1;
    adjL[u].pb(e1), adjL[v].pb(e2);
}

bool bfs()
{
    memset(lvl, INF, sizeof(lvl));
    lvl[1] = 0;
    queue<int> q;
    q.push(1);
    int cur;
    while (q.size())
    {
        cur = q.front();
        q.pop();
        for (const edge *e : adjL[cur])
        {
            if (lvl[e->v] == INF && e->c > e->f)
            {
                lvl[e->v] = lvl[cur] + 1;
                q.push(e->v);
            }
        }
    }
    return lvl[n] != INF;
}

ll dfs(int u, ll f)
{
    if (u == n)
    {
        return f;
    }
    while (nxt[u] < adjL[u].size())
    {
        edge *e = adjL[u][nxt[u]];
        if (lvl[e->v] == lvl[e->u] + 1 && e->c > e->f)
        {
            int flow = dfs(e->v, min(f, e->c - e->f));
            if (flow)
            {
                e->f += flow;
                e->rev->f -= flow;
                return flow;
            }
        }
        nxt[u]++;
    }
    return 0;
}

ll dinic()
{
    ll cur, ans = 0;
    while (bfs())
    {
        memset(nxt, 0, sizeof(nxt));
        while (cur = dfs(1, 1e12))
        {
            ans += cur;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 0, u, v, c; i < m; i++)
    {
        cin >> u >> v >> c;
        add(u, v, c);
    }
    cout << dinic();
}