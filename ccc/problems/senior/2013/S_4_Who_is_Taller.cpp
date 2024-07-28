#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n, m;
int x, y;
int p, q;

vector<int> adjL[100005];
bool vis[100005];

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
        for (int h : adjL[cur])
        {
            if (!vis[h])
            {
                q.push(h);
                vis[h] = true;
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    REP(i, 0, m)
    {
        scanf("%d%d", &x, &y);
        adjL[x].push_back(y);
    }
    scanf("%d%d", &p, &q);
    if (bfs(p, q))
    {
        printf("yes");
    }
    else
    {
        if (bfs(q, p))
        {
            printf("no");
        }
        else
        {
            printf("unknown");
        }
    }
}