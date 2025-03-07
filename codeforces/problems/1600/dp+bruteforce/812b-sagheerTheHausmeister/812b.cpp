#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 15, mxM = 100;

int n, m, highest;
char a[mxN + 5][mxM + 5];

int solve(int row, bool left)
{
    if (row == highest)
    {
        if (left == 0)
        {
            for (int j = m + 2; j >= 1; j--)
            {
                if (a[row][j] == '1')
                {
                    return j - 1;
                }
            }
        }
        for (int j = 1; j <= m + 2; j++)
        {
            if (a[row][j] == '1')
            {
                return (m + 2) - j;
            }
        }
    }

    int ans = INF;
    if (left == 0)
    {
        int pos = 0;
        for (int j = m + 2; j >= 1; j--)
        {
            if (a[row][j] == '1')
            {
                pos = j - 1;
                break;
            }
        }
        ans = (2 * pos) + 1 + solve(row - 1, 0);
        ans = min(ans, (m + 2) + solve(row - 1, 1));
    }
    else
    {
        int pos = m + 2;
        for (int j = 1; j <= m + 2; j++)
        {
            if (a[row][j] == '1')
            {
                pos = j;
                break;
            }
        }
        ans = 2 * ((m + 2) - pos) + 1 + solve(row - 1, 1);
        ans = min(ans, (m + 2) + solve(row - 1, 0));
    }
    return ans;
}
int main()
{
    cin >> n >> m;
    bool lights = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m + 2; j++)
        {
            cin >> a[i][j];
        }

        bool ok = true;
        for (int j = 1; j <= m + 2 && !lights; j++)
        {
            if (a[i][j] == '1')
            {
                ok = false;
                lights = true;
            }
        }
        if (ok && !lights)
        {
            highest = i + 1;
        }
    }

    if (!highest)
    {
        highest++;
    }
    if (highest > n)
    {
        cout << 0;
        return 0;
    }
    cout << solve(n, 0);
}