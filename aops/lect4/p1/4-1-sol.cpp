#include <bits/stdc++.h>
using namespace std;

#define INVALID -1000000000000000000
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    ll vals[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> vals[i];
    }
    vector<ll> dp;
    dp.push_back(0);
    for (int i = 1; i <= k; ++i)
    {
        dp.push_back(INVALID);
    }
    for (int i = 0; i < n; ++i)
    {
        vector<ll> new_dp;
        for (int j = 0; j <= k; ++j)
        {
            new_dp.push_back(INVALID);
        }
        // j = number of switches performed thus far
        for (int j = 0; j <= k; ++j)
        {
            if (dp[j] == INVALID)
            {
                continue;
            }
            ll mult = (j % 2 == 0 ? 1 : -1);
            // Try switching... (if we can)
            if (j < k)
            {
                new_dp[j + 1] = max(new_dp[j + 1], dp[j] - mult * vals[i]);
            }
            // Try not switching
            new_dp[j] = max(new_dp[j], dp[j] + mult * vals[i]);
        }
        dp = new_dp;
    }
    ll best = *max_element(dp.begin(), dp.end());
    cout << best << '\n';
}