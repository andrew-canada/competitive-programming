#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e6;

int arr[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] == arr[(i + n / 2) % n])
        {
            ans += 2;
        }
    }
    cout << ans;
}