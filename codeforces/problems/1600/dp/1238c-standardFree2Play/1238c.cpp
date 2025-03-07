#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, h, n;
    cin >> t;
    while (t--)
    {
        cin >> h >> n;
        vector<int> p(n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        int ans = 0;
        int lf = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && p[i - 1] > p[i] + 1)
            {
                if (lf > 0)
                {
                    ans += (i - lf) & 1;
                }
                else
                {
                    ans += 1 - ((i - lf) & 1);
                }
                lf = i;
            }
        }
        if (p[n - 1] > 1)
        {
            if (lf != 0)
            {
                ans += (n - lf) & 1;
            }
            else
            {
                ans += 1 - ((n - lf) & 1);
            }
        }
        cout << ans << '\n';
    }
}