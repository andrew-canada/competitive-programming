#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e6, M = 1e9 + 7;

int dp[mxN + 1];

int main()
{
    int n;
    cin >> n;
    dp[0] = 1;

    for (int s = 1; s <= n; s++)
    {
        for (int k = 1; k <= 6 && k <= s; k++)
        {
            dp[s] = (dp[s] + dp[s - k]) % M;
        }
    }
    cout << dp[n];
}