#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int arr[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll ans = arr[0], curMax = arr[0];
    for (int i = 1; i < n; i++)
    {
        curMax = max(curMax + arr[i], (ll)arr[i]);
        ans = max(ans, curMax);
    }
    cout << ans;
}