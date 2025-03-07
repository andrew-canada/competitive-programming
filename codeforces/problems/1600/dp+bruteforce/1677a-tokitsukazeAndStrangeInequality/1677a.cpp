#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 5e3;

ll p[mxN], f[mxN], pref[mxN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;
    while (t--)
    {
        ll ans = 0;
        memset(f, 0, sizeof(f));
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (p[i] > p[j])
                {
                    f[i]++;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (p[j] > p[i])
                {
                    f[j]--;
                }
            }
            pref[0] = 0;
            for (int j = 1; j <= i; j++)
            {
                pref[j] = pref[j - 1] + f[j];
            }
            for (int j = 1; j < i; j++)
            {
                if (p[j] < p[i])
                {
                    ans += pref[i - 1] - pref[j];
                }
            }
        }
        cout << ans << '\n';
    }
}
