#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution
{
public:
    int minimumIncrements(vector<int> &nums, vector<int> &target)
    {
        int n = target.size();
        vector<ll> lcmArr(1 << n);
        for (int mask = 1; mask < (1 << n); mask++)
        {
            ll val = 1;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    val = lcm(val, target[i]);
                }
            }
            lcmArr[mask] = val;
        }
        vector<ll> dp(1 << n, LLONG_MAX / 2);
        dp[0] = 0;
        for (int i : nums)
        {
            vector<ll> next = dp;
            for (int mask = 1; mask < (1 << n); mask++)
            {
                ll rem = i % lcmArr[mask];
                ll cost = (rem == 0 ? 0 : lcmArr[mask] - rem);
                for (int oldMask = 0; oldMask < (1 << n); oldMask++)
                {
                    int newMask = oldMask | mask;
                    next[newMask] = min(next[newMask], dp[oldMask] + cost);
                }
            }
            dp = next;
        }
        return (int)dp[(1 << n) - 1];
    }
};

Solution sol;

int main()
{
    vector<int> nums = {1};
    vector<int> target = {4};
    sol.minimumIncrements(nums, target);
}