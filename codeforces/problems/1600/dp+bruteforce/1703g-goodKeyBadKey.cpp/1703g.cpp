#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f

typedef long long ll;

const int mxN = 1e5;

ll c[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        ll ans = 0, sum = 0;
        for (int i = -1; i < n; i++)
        {
            ll cur = sum;
            for (int j = i + 1; j < min(n, i + 32); j++)
            {
                int val = c[j];
                val >>= (j - i);
                cur += val;
            }
            ans = max(ans, cur);
            if (i + 1 != n)
            {
                sum += c[i + 1] - k;
            }
        }
        cout << ans << '\n';
    }
}