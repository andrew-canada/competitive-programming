#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

int a[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k, z;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> z;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        for (int l = 0; l <= z; l++)
        {
            int cur = 0, maxPair = 0;
            int r = k - 2 * l;
            if (r < 0)
            {
                continue;
            }
            for (int i = 0; i <= r; i++)
            {
                cur += a[i];
                if (i < n - 1)
                {
                    maxPair = max(maxPair, a[i] + a[i + 1]);
                }
            }
            ans = max(ans, cur + l * maxPair);
        }
        cout << ans << '\n';
    }
}