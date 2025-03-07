#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

vector<int> contig()
{
    vector<int> dp(n, 1);
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] <= s[i])
        {
            dp[i] = dp[i - 1] + 1;
        }
    }
    return dp;
}

vector<int> nonContig()
{
    int best[26] = {};
    vector<int> dp(n, 1);
    for (int i = 0; i < s.size(); i++)
    {
        char cur = s[i];
        for (char prev = 'A'; prev <= cur; prev++)
        {
            dp[i] = max(dp[i], best[prev - 'A'] + 1);
        }
        best[cur - 'A'] = dp[i];
    }
    return dp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t >> n >> s;

    auto solve = t ? nonContig : contig;

    vector<int> pref = solve();
    reverse(s.begin(), s.end());
    vector<int> suf = solve();

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, pref[i] + suf[n - i - 1] - 1);
    }

    cout << ans << endl;
}