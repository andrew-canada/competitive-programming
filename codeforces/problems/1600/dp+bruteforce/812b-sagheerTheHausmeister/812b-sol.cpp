#include <bits/stdc++.h>
using namespace std;
#define en "\n";
int n, m;
char a[20][110];

int ami;

int life(int row, int color)
{
    if (row == ami)
    {
        if (color == 0)
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
            if (a[row][j] == '1')
                return (m + 2) - j;
    }

    int an = INT_MAX;
    if (color == 0)
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
        an = (2 * pos) + 1 + life(row - 1, 0);
        an = min(an, (m + 2) + life(row - 1, 1));
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
        an = (2 * ((m + 2) - pos)) + 1 + life(row - 1, 1);
        an = min(an, (m + 2) + life(row - 1, 0));
    }
    return an;
}
int main()
{

    cin >> n >> m;
    bool global = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m + 2; j++)
        {
            cin >> a[i][j];
        }

        bool ok = true;
        for (int j = 1; j <= m + 2 && !global; j++)
        {
            if (a[i][j] == '1')
            {
                ok = false;
                global = true;
            }
        }
        if (ok && !global)
        {
            ami = i + 1;
        }
    }

    if (!ami)
        ami++;
    if (ami > n)
    {
        cout << 0 << en;
        return 0;
    }

    int an = life(n, 0);
    cout << an << en;
}