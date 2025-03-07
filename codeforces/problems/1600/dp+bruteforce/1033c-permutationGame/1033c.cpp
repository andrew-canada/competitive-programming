#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

int arr[mxN + 1], pos[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    string ans(n + 1, '.');
    for (int x = n; x >= 1; x--)
    {
        int i = pos[x];
        int j = i;
        ans[i] = 'B';
        while (true)
        {
            j -= x;
            if (j <= 0)
            {
                break;
            }
            if (ans[j] == 'B')
            {
                ans[i] = 'A';
                break;
            }
        }
        j = i;
        while (true)
        {
            j += x;
            if (j > n)
            {
                break;
            }
            if (ans[j] == 'B')
            {
                ans[i] = 'A';
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i];
    }
}