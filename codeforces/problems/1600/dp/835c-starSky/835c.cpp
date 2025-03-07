#include <bits/stdc++.h>
using namespace std;

const int mxC = 100, mxP = 10;

int cnt[mxP + 1][mxC + 1][mxC + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, c, x, y, s;
    cin >> n >> q >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> s;
        cnt[s][x][y]++;
    }

    for (int p = 0; p <= c; p++)
    {
        for (int i = 1; i <= mxC; i++)
        {
            for (int j = 1; j <= mxC; j++)
            {
                cnt[p][i][j] += cnt[p][i - 1][j] + cnt[p][i][j - 1] - cnt[p][i - 1][j - 1];
            }
        }
    }

    int t, x1, y1, x2, y2;
    while (q--)
    {
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        for (int p = 0; p <= c; p++)
        {
            int brightness = (p + t) % (c + 1);
            int amount = cnt[p][x2][y2] - cnt[p][x1 - 1][y2] - cnt[p][x2][y1 - 1] + cnt[p][x1 - 1][y1 - 1];
            ans += brightness * amount;
        }
        cout << ans << '\n';
    }
}