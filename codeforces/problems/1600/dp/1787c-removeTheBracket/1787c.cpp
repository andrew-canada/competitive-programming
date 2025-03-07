#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 2e5;

ll f[mxN + 1][2], x[mxN + 1], y[mxN + 1];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, i, n, s, j;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        for (i = 1; i <= n; i++)
        {
            cin >> j;
            if (i == 1 || i == n)
            {
                x[i] = y[i] = j;
            }
            else if (j <= s)
            {
                x[i] = 0;
                y[i] = j;
            }
            else
            {
                x[i] = s;
                y[i] = j - s;
            }
        }

        f[1][0] = f[1][1] = 0;
        for (i = 2; i <= n; i++)
        {
            f[i][0] = min(f[i - 1][0] + y[i - 1] * x[i], f[i - 1][1] + x[i - 1] * x[i]);
            f[i][1] = min(f[i - 1][0] + y[i - 1] * y[i], f[i - 1][1] + x[i - 1] * y[i]);
        }
        cout << f[n][0] << '\n';
    }
}