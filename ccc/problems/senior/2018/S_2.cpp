#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define INF 0x3f3f3f3f

int grid[105][105];

int main()
{
    int n;
    scanf("%d", &n);
    REP(i, 0, n)
    {
        REP(j, 0, n)
        {
            scanf("%d", &grid[i][j]);
        }
    }
    int tl = grid[0][0], tr = grid[0][n - 1], bl = grid[n - 1][0], br = grid[n - 1][n - 1];
    if (tl <= tr && tl <= bl && tl <= br)
    {
        REP(i, 0, n)
        {
            REP(j, 0, n)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    else if (tr <= tl && tr <= bl && tr <= br)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            REP(i, 0, n)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    else if (bl <= tl && bl <= tr && bl <= br)
    {
        REP(j, 0, n)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
}