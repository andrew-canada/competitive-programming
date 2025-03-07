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
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }

        memset(known, 0, sizeof(known));
        int q;
        for (int i = 0; i < k; i++)
        {
            cin >> q;
            known[q] = true;
        }

        string ans;
        for (int i = 0; i < m; i++)
        {
            bool ok = true;
            for (int j = 1; j <= n; j++)
            {
                if (j != a[i] && !known[j])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
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