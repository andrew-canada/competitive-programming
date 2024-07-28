#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int arr[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int sl = arr[n / 2];
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(sl - arr[i]);
    }
    cout << ans;
}