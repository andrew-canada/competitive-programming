#include <bits/stdc++.h>
using namespace std;

const int mxN = 3e5;

int a[mxN + 1];
bitset<mxN + 1> known, cur;

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

        known.reset();
        cur.reset();
        for (int i = 0; i < k; i++)
        {
            int q;
            cin >> q;
            known.set(q);
        }
        for (int i = 0; i <= n; i++)
        {
            cur.set(i);
        }

        string ans;
        for (int i = 0; i < m; i++)
        {
            if ((cur ^ bitset<mxN + 1>(a[i]) & known) == known)
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