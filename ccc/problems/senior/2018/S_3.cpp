#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define INF 0x3f3f3f3f
#define pb push_back

struct step
{
    int r, c, s;
};

char grid[105][105];
int numStep[105][105];
bool vis[105][105];
int n, m;
int xDir[4] = {-1, 1, 0, 0};
int yDir[4] = {0, 0, -1, 1};
vector<pii> cam;

bool inRange(int r, int c);
bool isSafe(int r, int c);

int main()
{
    int r0, c0;
    scanf("%d%d", &n, &m);
    REP(i, 0, n)
    {
        REP(j, 0, m)
        {
            scanf(" %c", &grid[i][j]);
            if (grid[i][j] == 'C')
            {
                cam.pb({i, j});
            }
            else if (grid[i][j] == 'S')
            {
                r0 = i, c0 = j;
            }
            else if (grid[i][j] == '.')
            {
                numStep[i][j] = -1;
            }
        }
    }
    int curR, curC;
    for (pii pos : cam)
    {
        REP(i, 0, 4)
        {
            curR = pos.first, curC = pos.second;
            while (inRange(curR, curC))
            {
                curR += xDir[i], curC += yDir[i];
                if (grid[curR][curC] == 'W')
                {
                    break;
                }
                else if (grid[curR][curC] == '.' || grid[curR][curC] == 'S')
                {
                    grid[curR][curC] = 'C';
                }
            }
        }
    }
    queue<step> q;
    if (grid[r0][c0] != 'C')
    {
        q.push({r0, c0, 0});
    }
    step cur;
    int r1, c1;
    bool safe;
    bool validPos;
    vis[r0][c0] = true;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (grid[cur.r][cur.c] == '.')
        {
            numStep[cur.r][cur.c] = cur.s;
        }
        REP(i, 0, 4)
        {
            r1 = cur.r + xDir[i], c1 = cur.c + yDir[i];
            if (!isSafe(r1, c1))
            {
                continue;
            }
            safe = true;
            validPos = true;
            vis[r1][c1] = true;
            while (safe)
            {
                safe = false;
                if (grid[r1][c1] == 'U')
                {
                    safe = true;
                    r1--;
                }
                if (grid[r1][c1] == 'D')
                {
                    safe = true;
                    r1++;
                }
                if (grid[r1][c1] == 'L')
                {
                    safe = true;
                    c1--;
                }
                if (grid[r1][c1] == 'R')
                {
                    safe = true;
                    c1++;
                }
                if (safe && !isSafe(r1, c1))
                {
                    validPos = false;
                    break;
                }
                vis[r1][c1] = true;
                if (grid[r1][c1] == '.')
                {
                    break;
                }
            }
            if (validPos)
            {
                q.push({r1, c1, cur.s + 1});
            }
        }
    }
    REP(i, 0, n)
    {
        REP(j, 0, m)
        {
            if (numStep[i][j])
            {
                printf("%d\n", numStep[i][j]);
            }
        }
    }
}

bool inRange(int r, int c)
{
    return r >= 0 && r < n && c >= 0 && c < m;
}

bool isSafe(int r, int c)
{
    return inRange(r, c) && !vis[r][c] && grid[r][c] != 'C' && grid[r][c] != 'W';
}