#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

array<int, 3> arr[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][1] >> arr[i][0] >> arr[i][2];
    }
    sort(arr, arr + n);

    ll ans = 0;
    set<array<ll, 2>> dp;
    dp.insert({0, 0});
    for (int i = 0; i < n; i++)
    {
        auto it = dp.lower_bound({arr[i][1]});
        --it;
        ans = max(ans, (*it)[1] + arr[i][2]);
        dp.insert({arr[i][0], ans});
    }
    cout << ans;
}