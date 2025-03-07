#include <bits/stdc++.h>
using namespace std;

#define InF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> s;
        vector<vector<ll>> a(n, vector<ll>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        int x = 0, y = 0;
        for (char c : s)
        {
            if (c == 'D')
            {
                ll tot = 0;
                for (int i = 0; i < m; i++)
                {
                    tot += a[x][i];
                }
                a[x][y] = -tot;
                x++;
            }
            else
            {
                ll tot = 0;
                for (int i = 0; i < n; i++)
                {
                    tot += a[i][y];
                }
                a[x][y] = -tot;
                y++;
            }
        }
        ll tot = 0;
        for (int i = 0; i < m; i++)
        {
            tot += a[n - 1][i];
        }
        a[n - 1][m - 1] = -tot;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
    }
}