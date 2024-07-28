#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
// #define LOCAL

typedef pair<int, int> pii;

int n, l;
int field[1505][1505];
pii cur;
bool vis[1505][1505];

queue<pii> path;

int main()
{
#ifdef LOCAL
    freopen("13p3.in", "r", stdin);
#endif
    scanf("%d %d", &n, &l);
    REP(i, 1, n)
    {
        REP(j, 1, n)
        {
            scanf("%d", &field[i][j]);
        }
    }
    path.push(make_pair(1, 1));
    while (!path.empty())
    {
        cur = path.front();
        path.pop();
        int r = cur.first;
        int c = cur.second;
        if (!vis[r][c])
        {
            vis[r][c] = true;
            if (r == n && c == n)
            {
                puts("yes");
                return 0;
            }
            if (c - 1 > 0)
            {
                if (!vis[r][c - 1] && abs(field[r][c] - field[r][c - 1]) <= l)
                {
                    path.push(make_pair(r, c - 1));
                }
            }
            if (c + 1 <= n)
            {
                if (!vis[r][c + 1] && abs(field[r][c] - field[r][c + 1]) <= l)
                {
                    path.push(make_pair(r, c + 1));
                }
            }
            if (r - 1 > 0)
            {
                if (!vis[r - 1][c] && abs(field[r][c] - field[r - 1][c]) <= l)
                {
                    path.push(make_pair(r - 1, c));
                }
            }
            if (r + 1 <= n)
            {
                if (!vis[r + 1][c] && abs(field[r][c] - field[r + 1][c]) <= l)
                {
                    path.push(make_pair(r + 1, c));
                }
            }
        }
    }
    puts("no");
}