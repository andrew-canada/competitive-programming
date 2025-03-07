#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;

int arr[mxN + 1], ans[mxN + 1], freq[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int current_mode = arr[0];
        freq[current_mode] = 1;
        ans[0] = current_mode;

        for (int i = 1; i < n; i++)
        {
            if (freq[arr[i]] + 1 > freq[current_mode])
            {
                current_mode = arr[i];
            }
            freq[arr[i]]++;
            ans[i] = arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}