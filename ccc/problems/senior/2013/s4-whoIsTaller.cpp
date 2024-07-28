#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define inf 1000005

int n, m;
int c1, c2;
vector<int> adjL[inf];
int vis[inf];

bool bfs(int c1, int c2);

int main()
{
    scanf("%d%d", &n, &m);
    int p1, p2;
    REP(i, 1, m)
    {
        scanf("%d%d", &p1, &p2);
        adjL[p1].push_back(p2);
    }
    scanf("%d%d", &c1, &c2);
    if (bfs(c1, c2))
    {
        printf("yes");
    }
    else if (bfs(c2, c1))
    {
        printf("no");
    }
    else
    {
        printf("unknown");
    }
}

bool bfs(int c1, int c2)
{
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(c1);
    vis[c1] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int c : adjL[cur])
        {
            if (c == c2)
            {
                return true;
            }
            if (!vis[c])
            {
                vis[c] = true;
                q.push(c);
            }
        }
    }
    return false;
}