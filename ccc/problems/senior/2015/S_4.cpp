#include <bits/stdc++.h>

using namespace std;

const int mxP = 2e3;

struct edge
{
    int b, t, h;
};

struct comp
{
    bool operator()(const edge &e1, const edge &e2)
    {
        return e1.t > e2.t;
    }
};

vector<edge> adjL[mxP + 1];
priority_queue<edge, vector<edge>, comp> pq;
int hull[mxP + 1];

int main()
{
    int k, n, m;
    scanf("%d%d%d", &k, &n, &m);
    int a, b, t, h;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d%d", &a, &b, &t, &h);
        adjL[a].push_back({b, t, h});
        adjL[b].push_back({a, t, h});
    }
    scanf("%d%d", &a, &b);
    pq.push({a, 0, k});
    edge cur;
    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        if (cur.h <= hull[cur.b])
        {
            continue;
        }
        hull[cur.b] = cur.h;
        if (cur.b == b)
        {
            printf("%d", cur.t);
            return 0;
        }
        for (edge e : adjL[cur.b])
        {
            if (cur.h > e.h)
            {
                pq.push({e.b, cur.t + e.t, cur.h - e.h});
            }
        }
    }
    printf("-1");
}

/*
10 4 7
1 2 4 4
1 3 7 2
3 1 8 1
3 2 2 2
4 2 1 6
3 4 1 1
1 4 6 12
1 4
*/