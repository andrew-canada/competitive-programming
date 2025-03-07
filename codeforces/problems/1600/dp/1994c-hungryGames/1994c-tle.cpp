#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 2e5;

int a[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ll ans = 0;
        for (int l = 0; l < n; l++)
        {
            ll g = 0;
            for (int r = l; r < n; r++)
            {
                g += a[r];
                if (g > x)
                {
                    g = 0;
                }
                if (g != 0)
                {
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }
}