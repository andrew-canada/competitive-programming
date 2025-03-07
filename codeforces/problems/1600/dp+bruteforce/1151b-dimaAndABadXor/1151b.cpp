#include <bits/stdc++.h>

using namespace std;

const int mxN = 5e3;

int a[mxN + 1][mxN + 1], ans[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        ans[i] = 1;
    }
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur ^= a[i][0];
    }

    if (cur)
    {
        cout << "TAK\n";
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if ((cur ^ a[i][0] ^ a[i][j]) != 0)
            {
                ans[i] = j + 1;
                cout << "TAK\n";
                for (int k = 0; k < n; ++k)
                {
                    cout << ans[k] << " ";
                }
                return 0;
            }
        }
    }

    cout << "NIE\n";
}