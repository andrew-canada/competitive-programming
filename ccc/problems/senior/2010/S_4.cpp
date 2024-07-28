#include <bits/stdc++.h>

using namespace std;

const int mxE = 1e3;

#define pb push_back

struct edge
{
    int a, b, c;
    bool operator<(const edge &e)
    {
        return c < e.c;
    }
};

struct UFDS
{
    int par[mxE + 1];
    vector<int> size = vector<int>(mxE + 1, 1);
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
        int p1 = findSet(a), p2 = findSet(b);
        if (isSameSet(p1, p2))
        {
            return;
        }
        if (size[p1] > size[p2])
        {
            size[p1] += size[p2];
            par[p2] = p1;
        }
        else
        {
            size[p2] += size[p1];
            par[p1] = p2;
        }
    }
};

int corner[10];
vector<edge> el;
vector<int> adjL[mxE + 1][mxE + 1];
UFDS ufds;

int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int numE;
        cin >> numE;
        for (int j = 0; j < numE; j++)
        {
            cin >> corner[j];
        }
        corner[numE] = corner[0];
        for (int j = 0; j < numE; j++)
        {
            int cost;
            cin >> cost;
            int c1 = min(corner[j], corner[j + 1]), c2 = max(corner[j], corner[j + 1]);
            if (adjL[c1][c2].size() == 0)
            {
                adjL[c1][c2].pb(cost);
            }
            adjL[c1][c2].pb(i);
        }
    }
    for (int i = 1; i <= mxE; i++)
    {
        for (int j = 1; j <= mxE; j++)
        {
            auto &cur = adjL[i][j];
            if (cur.size() == 2)
            {
                el.pb({cur[1], m, cur[0]});
            }
            else if (cur.size() == 3)
            {
                el.pb({cur[1], cur[2], cur[0]});
            }
        }
    }
    for (int i = 0; i <= mxE; i++)
    {
        ufds.par[i] = i;
    }
    sort(el.begin(), el.end());
    int cost1 = 0, cost2 = 0;
    int numEdge = 0;
    for (edge e : el)
    {
        if (e.b == m || ufds.isSameSet(e.a, e.b))
        {
            continue;
        }
        cost1 += e.c;
        numEdge++;
        ufds.unionSet(e.a, e.b);
        if (numEdge == m - 1)
        {
            break;
        }
    }

    for (int i = 0; i <= mxE; i++)
    {
        ufds.par[i] = i;
    }
    numEdge = 0;
    for (edge e : el)
    {
        if (ufds.isSameSet(e.a, e.b))
        {
            continue;
        }
        cost2 += e.c;
        numEdge++;
        ufds.unionSet(e.a, e.b);
        if (numEdge == m)
        {
            break;
        }
    }
    cout << min(cost1, cost2);
}