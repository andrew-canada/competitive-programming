#include <bits/stdc++.h>

using namespace std;

const int mxN = 200;

int a[mxN + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;
    while (t--)
    {
        bool ok = false;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] * 2 > a[i + 1] && a[i + 1] * 2 > a[i])
            {
                ok = true;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}