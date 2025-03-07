#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e2, mxS = 1e5;

int coins[mxN + 1];
bool dp[mxS + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = mxS; j >= coins[i]; j--)
        {
            dp[j] |= dp[j - coins[i]];
        }
    }

    vector<int> ans;
    for (int i = 1; i <= mxS; i++)
    {
        if (dp[i])
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (int i : ans)
    {
        cout << i << " ";
    }
}