#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

int a[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k, l, r;
    cin >> t;
    while (t--)
    {
        bool ok = true;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        l = r = a[0];
        for (int i = 1; i < n; i++)
        {
            l = max(a[i], l - k + 1);
            r = min(r + k - 1, a[i] + k - 1);
            if (l > r)
            {
                ok = false;
                break;
            }
        }
        if (l != a[n - 1])
        {
            ok = false;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}