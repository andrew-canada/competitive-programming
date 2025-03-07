#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, val;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<vector<int>> diag(2 * n + 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> val;
                diag[n + i - j].push_back(val);
            }
        }
        int ans = 0;
        for (int i = 1; i <= 2 * n - 1; i++)
        {
            int cur = *min_element(diag[i].begin(), diag[i].end());
            ans += (cur < 0 ? -cur : 0);
        }
        cout << ans << '\n';
    }
}