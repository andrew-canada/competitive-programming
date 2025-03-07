#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1e5;

int c[mxN + 1], a[mxN + 1], b[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        ll ans = 0;
        ll prevLen = 0;
        for (int i = 1; i < n; i++)
        {
            ll curLen = c[i] + 1ll + abs(a[i] - b[i]);
            if (a[i] != b[i])
            {
                curLen = max(curLen, c[i] + prevLen + 1 - abs(a[i] - b[i]));
            }
            ans = max(ans, curLen);
            prevLen = curLen;
        }
        cout << ans << '\n';
    }
}