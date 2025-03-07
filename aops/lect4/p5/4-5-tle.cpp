#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;
const int mxH = 100;

int h[mxN + 1];
bitset<mxN * mxH / 2 + 1> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    dp[0] = 1;
    int tot = 0;

    for (int i = 0; i < n; i++)
    {
        tot += h[i];
        dp |= dp << h[i];

        int ans = tot;
        for (int j = 0; j <= tot / 2; j++)
        {
            if (dp[j])
            {
                ans = min(ans, abs(tot - 2 * j));
            }
        }

        cout << ans << '\n';
    }

    return 0;
}