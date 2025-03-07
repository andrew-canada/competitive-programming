#include <bits/stdc++.h>

using namespace std;

const int mxN = 100;

int arr[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool win;
        for (int i = 0; i < n; i++)
        {
            win = true;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                // cout << "in: " << abs(arr[i] - arr[j]) << '\n';
                if (abs(arr[i] - arr[j]) % k == 0)
                {
                    // cout << "found\n";
                    win = false;
                    break;
                }
            }
            if (win)
            {
                cout << "YES\n"
                     << i + 1 << '\n';
                break;
            }
        }
        if (!win)
        {
            cout << "NO\n";
        }
    }
}