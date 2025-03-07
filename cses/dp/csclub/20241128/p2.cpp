// https://cses.fi/problemset/task/1745

#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e3, mxS = 1e5;

int arr[mxN + 1], dp[mxS + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int s = mxS; s >= arr[i]; s--)
        {
            dp[s] |= dp[s - arr[i]];
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
