#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

struct edge
{
    int a, b, c, f;
    edge *back;
    edge(int a1, int b1, int c1)
    {
        a = a1, b = b1, c = c1, f = 0;
    }
};

vector<edge *> adjL[18];
int lvl[18], nxt[18];

void addEdge(int a, int b, int c)
{
    edge *e1 = new edge(a, b, c);
    edge *e2 = new edge(b, a, 0);
    e1->back = e2, e2->back = e1;
    adjL[a].pb(e1), adjL[b].pb(e2);
}

bool bfs()
{
    queue<int> q;
    int cur;
    q.push(0);
    memset(lvl, INF, sizeof(lvl));
    lvl[0] = 0;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        for (edge *e : adjL[cur])
        {
            if (lvl[e->b] == INF && e->c > e->f)
            {
                lvl[e->b] = lvl[cur] + 1;
                q.push(e->b);
            }
        }
    }
    return lvl[17] != INF;
}

int dfs(int cur, int curF)
{
    if (cur == 17)
    {
        return curF;
    }
    for (int i = adjL[cur].size(); nxt[cur] < i; nxt[cur]++)
    {
        edge *curE = adjL[cur][nxt[cur]];
        if (curE->c > curE->f && lvl[curE->b] == lvl[curE->a] + 1)
        {
            int maxFlow = dfs(curE->b, min(curF, curE->c - curE->f));
            if (maxFlow > 0)
            {
                curE->f += maxFlow;
                curE->back->f -= maxFlow;
                return maxFlow;
            }
        }
    }
    return 0;
}

int dinic()
{
    int maxFlow = 0, curFlow;
    while (bfs())
    {
        memset(nxt, 0, sizeof(nxt));
        while (curFlow = dfs(0, INF))
        {
            maxFlow += curFlow;
        }
    }
    return maxFlow;
}

int main()
{
    int val;
    for (int i = 1; i <= 8; i++)
    {
        cin >> val;
        addEdge(0, i, val);
    }
    for (int i = 9; i <= 16; i++)
    {
        cin >> val;
        addEdge(i, 17, val);
        addEdge(1, i, INF);
        if (i % 2 == 0)
        {
            addEdge(2, i, INF);
        }
    }
    addEdge(3, 11, INF), addEdge(3, 12, INF), addEdge(3, 15, INF), addEdge(3, 16, INF), addEdge(4, 12, INF);
    addEdge(4, 16, INF), addEdge(5, 13, INF), addEdge(5, 14, INF), addEdge(5, 15, INF), addEdge(5, 16, INF);
    addEdge(6, 14, INF), addEdge(6, 16, INF), addEdge(7, 15, INF), addEdge(7, 16, INF), addEdge(8, 16, INF);
    cout << dinic();
}