#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

const int mxN = 1e5;
const int mxM = 2e5;

struct edge
{
    int a, b, c, n;
    bool operator<(edge &e)
    {
        return c == e.c ? n < e.n : c < e.c;
    }
};

struct UFDS
{
    int par[mxN + 1];
    vector<int> size = vector<int>(mxN, 1);
    int findSet(int n)
    {
        return n == par[n] ? n : par[n] = findSet(par[n]);
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
        if (size[p1] >= size[p2])
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

edge el[mxM + 1];
UFDS ufds;

int main()
{
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    REP(i, 0, m)
    {
        scanf("%d%d%d", &el[i].a, &el[i].b, &el[i].c);
        el[i].n = i;
    }
    REP(i, 0, n)
    {
        ufds.par[i] = i;
    }
    sort(el, el + m);
    int numEdge = 0;
    int numDay = 0;
    int maxCost;
    REP(i, 0, m)
    {
        if (numEdge == n - 1)
        {
            break;
        }
        edge cur = el[i];
        if (ufds.isSameSet(cur.a, cur.b))
        {
            continue;
        }
        numEdge++;
        ufds.unionSet(cur.a, cur.b);
        if (cur.n >= n - 1)
        {
            numDay++;
        }
        maxCost = cur.c;
    }

    REP(i, 0, n)
    {
        ufds.par[i] = i;
    }
    REP(i, 0, m)
    {
        edge cur = el[i];
        if (ufds.isSameSet(cur.a, cur.b))
        {
            continue;
        }
        if (cur.c < maxCost || (cur.c == maxCost && cur.n < n - 1))
        {
            ufds.unionSet(cur.a, cur.b);
        }
        else if (cur.n < n - 1 && cur.c <= d)
        {
            numDay--;
            break;
        }
    }
    printf("%d\n", numDay);
}