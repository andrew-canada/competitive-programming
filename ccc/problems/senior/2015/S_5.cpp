#include <bits/stdc++.h>

using namespace std;

const int mxN = 3e3, mxM = 105;

int p1[mxN + 1], p2[mxN + 1];
int dp[mxN + 1][mxM + 1][mxM + 1][2];
int n, m;

int maxS(int n1, int l, int r, bool canTake);

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p1[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &p2[i]);
    }
    sort(p2, p2 + m);
    printf("%d", maxS(0, 0, m - 1, true));
}

int maxS(int n1, int l, int r, bool canTake)
{
    int totS = 0;
    if (dp[n][l][r][canTake])
    {
        return dp[n][l][r][canTake];
    }
    if (n1 >= n && l > r)
    {
        return dp[n][l][r][canTake] = totS;
    }
    if (canTake)
    {
        if (p1[n1] > p2[r] && n1 < n - 1)
        {
            totS = max(maxS(n1 + 1, l, r, true), maxS(n1, l, r + 1, true));
        }
        else
        {
            totS = max(maxS(n1, l, r - 1, false), maxS(n1, l, r - 1, false));
        }
    }
    else
    {
        totS = maxS(n1 + 1, l, r, true);
    }
    return dp[n][l][r][canTake] = totS;
}

/*
5
10
12
6
14
7
3
1
8
2
*/