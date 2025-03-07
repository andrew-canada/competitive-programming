#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> t(mxN + 1), dp(mxN + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < n; i++)
    {
        while (t[idx1] + 1440 <= t[i])
        {
            idx1++;
        }
        while (t[idx2] + 90 <= t[i])
        {
            idx2++;
        }
        dp[i + 1] = min(min(dp[idx1] + 120, dp[idx2] + 50), dp[i] + 20);
        cout << dp[i + 1] - dp[i] << '\n';
    }
}
