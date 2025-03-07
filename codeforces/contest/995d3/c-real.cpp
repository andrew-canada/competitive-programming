#include <bits/stdc++.h>

using namespace std;

const int mxN = 3e5;

int a[mxN + 1];
bool known[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        memset(known, 0, sizeof(known));
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        int q;
        for (int i = 0; i < k; i++)
        {
            cin >> q;
            known[q] = true;
        }

        string ans;
        for (int i = 0; i < m; i++)
        {
            if (n - k >= 2)
            {
                ans += '0';
            }
            else if (n == k)
            {
                ans += '1';
            }
            else if (!known[a[i]])
            {
                ans += '1';
            }
            else
            {
                ans += '0';
            }
        }
        cout << ans << '\n';
    }
}