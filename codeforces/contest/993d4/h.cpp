#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2000;
int M[mxN + 1][mxN + 1];
ll pref[mxN + 1][mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> M[i][j];
            }
        }

        memset(pref, 0, sizeof(pref));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                pref[i][j] = M[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }

        while (q--)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            ll sum = 0;
            int idx = 1;
            for (int i = x1; i <= x2; i++)
            {
                for (int j = y1; j <= y2; j++)
                {
                    sum += M[i][j] * idx;
                    idx++;
                }
            }

            cout << sum << ' ';
        }
        cout << '\n';
    }
}