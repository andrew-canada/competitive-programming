#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 5e2, mxM = 1e3, M = 1e9 + 7;

struct edge
{
    edge *back;
    int u, v, c, f;
    bool real;
    edge(int u1, int v1, int c1, bool real1)
    {
        u = u1, v = v1, c = c1, f = 0, real = real1;
    }
};

vector<edge *> adjL[mxN];
int lvl[mxN], nxt[mxN];
int n, m;
bool vis[mxN];

void add(int u, int v, int c)
{
    edge *e1 = new edge(u, v, c, true);
    edge *e2 = new edge(v, u, 0, false);
    e1->back = e2;
    e2->back = e1;
    adjL[u].push_back(e1);
    adjL[v].push_back(e2);
}

bool bfs()
{
    queue<int> q;
    q.push(0);
    memset(lvl, INF, sizeof(lvl));
    lvl[0] = 0;
    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        for (edge *e : adjL[cur])
        {
            if (lvl[e->v] == INF && e->c - e->f > 0)
            {
                q.push(e->v);
                lvl[e->v] = lvl[cur] + 1;
            }
        }
    }
    return lvl[n - 1] != INF;
}

int dfs(int cur, int f)
{
    if (cur == n - 1)
    {
        return f;
    }
    for (int num = adjL[cur].size(); nxt[cur] < num; nxt[cur]++)
    {
        edge *e = adjL[cur][nxt[cur]];
        if (e->c - e->f > 0 && lvl[e->v] == lvl[e->u] + 1)
        {
            int flow = dfs(e->v, min(f, e->c - e->f));
            if (flow > 0)
            {
                e->f += flow;
                e->back->f -= flow;
                return flow;
            }
        }
    }
    return 0;
}

int dinic()
{
    int mf = 0, f;
    while (bfs())
    {
        memset(nxt, 0, sizeof(nxt));
        while (f = dfs(0, INF))
        {
            mf += f;
        }
    }
    return mf;
}

void dfs1(int u = 0)
{
    vis[u] = true;
    for (edge *e : adjL[u])
    {
        if (e->c > e->f && !vis[e->v])
        {
            dfs1(e->v);
        }
    }
}

int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v, --u, --v;
        add(u, v, 1);
        add(v, u, 1);
    }
    // number of min cut edges is equal to max flow
    cout << dinic() << '\n';
    dfs1();
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
        {
            for (edge *e : adjL[i])
            {
                if (!vis[e->v] && e->real)
                {
                    cout << i + 1 << " " << e->v + 1 << '\n';
                }
            }
        }
    }
}

/*
6 7
1 2
1 3
1 4
2 5
3 5
4 5
5 6
*/