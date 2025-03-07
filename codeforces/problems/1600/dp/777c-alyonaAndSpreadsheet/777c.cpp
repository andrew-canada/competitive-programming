#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 1e5;

int a[mxN + 1], f[mxN + 1], mx[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, i, j, li, ri;
    cin >> n >> m;
    for (i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    cin >> k;

    for (j = 1; j <= m; j++)
    {
        f[j] = 1;
    }
    for (j = 1; j <= m; j++)
    {
        for (i = 2; i <= n; i++)
        {
            f[(i - 1) * m + j] = (a[(i - 1) * m + j] >= a[(i - 2) * m + j] ? f[(i - 2) * m + j] : i);
        }
    }
    for (i = 1; i <= n; i++)
    {
        mx[i] = INF;
        for (j = 1; j <= m; j++)
        {
            mx[i] = min(mx[i], f[(i - 1) * m + j]);
        }
    }
    for (i = 1; i <= k; i++)
    {
        cin >> li >> ri;
        if (mx[ri] <= li)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}
