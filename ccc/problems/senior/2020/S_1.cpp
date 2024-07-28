#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

array<int, 2> arr[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    sort(arr, arr + n);
    double ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans = max(ans, abs(1.0 * (arr[i + 1][1] - arr[i][1]) / (arr[i + 1][0] - arr[i][0])));
    }
    cout << ans;
}