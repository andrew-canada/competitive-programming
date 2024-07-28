#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e6;

vector<int> adjL[mxN + 1];
bool vis[mxN + 1];

bool bfs(int a, int b)
{
    queue<int> q;
    q.push(a);
    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur == b)
        {
            return true;
        }
        for (int i : adjL[cur])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int x, y;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        adjL[x].push_back(y);
    }
    int p, q;
    scanf("%d%d", &p, &q);
    if (bfs(p, q))
    {
        printf("yes\n");
    }
    else if (bfs(q, p))
    {
        printf("no\n");
    }
    else
    {
        printf("unknown\n");
    }
}