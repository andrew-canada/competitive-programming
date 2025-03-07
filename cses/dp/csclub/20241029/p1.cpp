#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9 + 7, mxN = 1e6;

int n;
ll dp[mxN + 1];

int main()
{
    cin >> n;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= 6 && j <= i; j++)
        {
            dp[i] = (dp[i] + dp[i - j]) % M;
        }
    }
    cout << dp[n];
}