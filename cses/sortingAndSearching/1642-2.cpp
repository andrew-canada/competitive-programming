#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e3;

int arr[mxN + 1];
map<int, array<int, 2>> mp;

int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mp.find(x - arr[i] - arr[j]) != mp.end())
            {
                array<int, 2> ar = mp[x - arr[i] - arr[j]];
                cout << i + 1 << " " << j + 1 << " " << ar[0] + 1 << " " << ar[1] + 1;
                return 0;
            }
        }
        for (int j = 0; j < i; j++)
        {
            mp[arr[i] + arr[j]] = {i, j};
        }
    }
    cout << "IMPOSSIBLE\n";
}