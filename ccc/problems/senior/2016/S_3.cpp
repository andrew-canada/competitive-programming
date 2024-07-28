#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

bool pho[mxN + 1];
vector<int> adjL[mxN + 1];
int d;
int v0;

void update(int cur, int par)
{
    for (int v : adjL[cur])
    {
        if (v != par)
        {
            update(v, cur);
            if (pho[v])
            {
                pho[cur] = true;
            }
        }
    }
}

void dfs(int cur, int par, int curD)
{
    if (curD > d)
    {
        d = curD;
        v0 = cur;
    }
    for (int v : adjL[cur])
    {
        if (v != par && pho[v])
        {
            dfs(v, cur, curD + 1);
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &v);
        pho[v] = true;
    }
    int v1, v2;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &v1, &v2);
        adjL[v1].push_back(v2);
        adjL[v2].push_back(v1);
    }
    update(v, -1);
    dfs(v, -1, 0);
    dfs(v0, -1, 0);
    int numP = 0;
    for (int i = 0; i < n; i++)
    {
        if (pho[i])
        {
            numP++;
        }
    }
    printf("%d\n", 2 * (numP - 1) - d);
}