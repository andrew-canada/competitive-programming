#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5, mxH = 100, range = 100 * mxH + 1;

bool dp[2][range];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int vals[n];
    int valsu = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> vals[i];
        valsu += vals[i];
    }
    for (int i = 0; i < range; ++i)
    {
        dp[0][i] = false;
    }
    dp[0][0] = true;
    int which = 0;
    for (int k = 0; k < n; ++k)
    {
        int v = vals[k];
        for (int i = 0; i < range; ++i)
        {
            dp[1 - which][i] = false;
        }
        for (int i = 0; i < range; ++i)
        {
            if (dp[which][i])
            {
                if (i + v <= range - 1)
                {
                    dp[1 - which][i + v] = true;
                }
                if (v >= i)
                {
                    dp[1 - which][v - i] = true;
                }
                else
                {
                    dp[1 - which][i - v] = true;
                }
            }
        }
        which = 1 - which;
        for (int i = 0; i <= mxH; ++i)
        {
            if (dp[which][i])
            {
                cout << i << '\n';
                break;
            }
        }
    }
}