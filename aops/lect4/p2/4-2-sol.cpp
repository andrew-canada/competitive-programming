#include <bits/stdc++.h>
using namespace std;

vector<int> bestNonDecSublistSizes(string s)
{
    vector<int> dp(s.size(), 1);
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] <= s[i])
        {
            dp[i] = dp[i - 1] + 1;
        }
    }
    return dp;
}

vector<int> bestNonDecSubsequenceSizes(string s)
{
    int bests[26] = {};
    vector<int> dp(s.size(), 1);
    for (int i = 0; i < s.size(); i++)
    {
        char curr = s[i];
        for (char prev = 'A'; prev <= curr; prev++)
        {
            dp[i] = max(dp[i], bests[prev - 'A'] + 1);
        }
        bests[curr - 'A'] = dp[i];
    }
    return dp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    string s;
    cin >> t >> n >> s;

    auto solve = t ? bestNonDecSubsequenceSizes : bestNonDecSublistSizes;

    vector<int> dpForward = solve(s);
    reverse(s.begin(), s.end());
    vector<int> dpBackward = solve(s);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dpForward[i] + dpBackward[n - i - 1] - 1);
    }

    cout << ans << endl;
}