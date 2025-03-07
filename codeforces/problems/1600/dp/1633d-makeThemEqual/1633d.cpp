#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 1e3, mxK = 1e6;

int d[mxN + 1], b[mxN + 1], c[mxN + 1], dp[mxK + 1];

int main()
{
    int t, n, k;
    cin >> t;

    memset(d, INF, sizeof(d));
    d[1] = 0;
    for (int i = 1; i <= mxN; i++)
    {
        for (int x = 1; x <= i; x++)
        {
            int j = i + i / x;
            if (j <= mxN)
            {
                d[j] = min(d[j], d[i] + 1);
            }
        }
    }

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += d[b[i]];
        }
        k = min(k, sum);
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            for (int j = k - d[b[i]]; j >= 0; j--)
            {
                dp[j + d[b[i]]] = max(dp[j + d[b[i]]], dp[j] + c[i]);
            }
        }
        cout << *max_element(dp, dp + k + 1) << '\n';
    }
}