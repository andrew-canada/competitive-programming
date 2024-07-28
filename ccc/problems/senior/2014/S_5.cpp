#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 2e3, mxE = 2001000;

struct edge
{
    int d, a, b;
    bool operator<(const edge &e)
    {
        return d < e.d;
    }
};

edge el[mxE + 1];
int node[mxN + 1][2];
int treat[mxN + 1];
int prevT[mxN + 1];
int dist[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> node[i][0] >> node[i][1];
    }
    int idx = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int xDist = (node[i][0] - node[j][0]) * (node[i][0] - node[j][0]);
            int yDist = (node[i][1] - node[j][1]) * (node[i][1] - node[j][1]);
            el[idx] = {xDist + yDist, i, j};
            idx++;
        }
    }
    sort(el, el + idx);
    for (int i = 0; i < idx; i++)
    {
        edge cur = el[i];
        if (cur.d > dist[cur.a])
        {
            dist[cur.a] = cur.d;
            prevT[cur.a] = treat[cur.a];
        }
        if (cur.d > dist[cur.b])
        {
            dist[cur.b] = cur.d;
            prevT[cur.b] = treat[cur.b];
        }
        if (cur.a == 0)
        {
            treat[cur.a] = max(treat[cur.a], prevT[cur.b] + 1);
        }
        else
        {
            treat[cur.a] = max(treat[cur.a], prevT[cur.b] + 1);
            treat[cur.b] = max(treat[cur.b], prevT[cur.a] + 1);
        }
    }
    cout << treat[0];
}