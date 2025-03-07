#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll lis[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> lis[i];
    }
    // States:
    // 1: active
    // 2: stopped
    ll dp1 = 0;
    ll dp2 = 0;
    ll new_dp1, new_dp2;
    for (int i = 0; i < n; ++i)
    {
        // don't change state right before this
        new_dp1 = dp1 + lis[i];
        new_dp2 = dp2;
        // do change state right before this
        new_dp1 = max(new_dp1, lis[i]);
        new_dp2 = max(new_dp2, dp1);
        dp1 = new_dp1;
        dp2 = new_dp2;
    }
    cout << max(dp1, dp2) << '\n';
}